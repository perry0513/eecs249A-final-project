fun Init(): int;
fun CheckIfReached(x: float, z:float, speed:float): bool;
fun RotateTowardsLocation(x: float, z:float, speed:float): bool;
fun MoveForward(speed: float): int;
fun MoveBackward(speed: float): int;
fun RotateLeft(speed: float): int;
fun RotateRight(speed: float): int;
fun Stay(): int;
fun IsInTrajectory(x0: float, z0: float, x1:float, z1:float, trajectoryDeviationThreshold: float): bool;
fun RandomController(forwardSpeed: float, rotationSpeed: float): int;
fun GetRobotPosition(): seq[float];
fun GetChargerPosition(): seq[float];
fun GetIsBumperReleasedLeft(): bool;
fun GetIsBumperReleasedRight(): bool;
fun GetBatteryLevel(): float;
fun GetIsButtonPressedAndReleasedB0(): bool;

type locationType = (float, float);

event eMotionRequest: (machine, locationType, locationType, bool);
event eMotionRequestX priority 10: (machine, locationType, locationType, bool);
event eMotion: locationType;
event eMotionX priority 10: locationType;
event eBatteryLow priority 10: machine;
event eBatteryRecovered priority 10: machine;
event eCurrentLocation priority 10: locationType;
event eCurrentGoal priority 10: locationType;

machine EgoRobot {
    var motionPlanner: machine;
    var motionPrimitives: machine;
    var battery: machine;
    var currentLocation: locationType;
    var goals: seq[locationType];
    var currentGoalIndex: int;
    var temp: seq[float];
    var chargerLocation: locationType;

    fun DM(): string {
        if (currentLocation == goals[currentGoalIndex]) {
            if (currentGoalIndex + 1 < sizeof(goals)) {
                currentGoalIndex = currentGoalIndex + 1;
            } else {
                currentGoalIndex = 0;
            }
            return "SC";
        }
        return "AC";
    }

    fun AC() {
        ;
    }

    fun SC() {
        send motionPlanner, eMotionRequest, (motionPrimitives, currentLocation, goals[currentGoalIndex], false);
    }

    fun handler(payload: locationType) {
        currentLocation = payload;
    }

    start state Init {
        entry {
            Init();
            temp = GetRobotPosition();
            currentLocation = (temp[0], temp[1]);
            temp = GetChargerPosition();
            chargerLocation = (temp[0], temp[1]);
            motionPrimitives = new MotionPrimitives(this, currentLocation, 0.1, 300.0);
            motionPlanner = new MotionPlanner();
            battery = new Battery(motionPrimitives, motionPlanner, chargerLocation, 50.0, 100.0);
            goals += (sizeof(goals), (0.25, 0.25));
            goals += (sizeof(goals), (-0.25, 0.25));
            goals += (sizeof(goals), (-0.25, -0.25));
            goals += (sizeof(goals), (0.25, -0.25));
            currentGoalIndex = 0;
            goto WaitB0Press;
        }
    }

    state WaitB0Press {
        entry {
            var isButtonB0PressedAndReleased: bool;
            isButtonB0PressedAndReleased = GetIsButtonPressedAndReleasedB0();
            if (isButtonB0PressedAndReleased) {
                send motionPlanner, eMotionRequest, (motionPrimitives, currentLocation, goals[currentGoalIndex], false);
                goto Run;
            } else {
                goto WaitB0Press;
            }
        }
    }

    state Run {
        rtamodule {
            controller AC;
            controller SC;
            decisionmodule DM @ {AC: 1, SC: 1};
            on eCurrentLocation with handler;
        }
    }
}

machine MotionPlanner {
    var destination: machine;
    var step: float;
    var destinationOfRequest: machine;
    var currentLocation: locationType;
    var goalLocation: locationType;
    var isHighPriorityMotionRequest: bool;

    fun DM(): string {
        if (currentLocation.0 >= -step &&
            currentLocation.0 <= step &&
            currentLocation.1 >= -step &&
            currentLocation.1 <= step) {
            return "AC";
        }
        return "SC";
    }

    fun AC() {
        var motionPlan: seq[locationType];
        var index: int;
        motionPlan += (sizeof(motionPlan), goalLocation);
        index = 0;
        while (index < sizeof(motionPlan)) {
            if (isHighPriorityMotionRequest) {
                send destinationOfRequest, eMotionX, motionPlan[index];
            } else {
                send destinationOfRequest, eMotion, motionPlan[index];
            }
            index = index + 1;
        }
    }

    fun SC() {
        var waypoint: locationType;
        var motionPlan: seq[locationType];
        var index: int;
        waypoint = currentLocation;
        while (waypoint.0 != goalLocation.0 ||
               waypoint.1 != goalLocation.1) {
            if (waypoint.0 > goalLocation.0) {
                waypoint.0 = waypoint.0 - step;
                if (waypoint.0 < goalLocation.0) {
                    waypoint.0 = goalLocation.0;
                }
            } else if (waypoint.0 < goalLocation.0) {
                waypoint.0 = waypoint.0 + step;
                if (waypoint.0 > goalLocation.0) {
                    waypoint.0 = goalLocation.0;
                }
            }
            if (waypoint.1 > goalLocation.1) {
                waypoint.1 = waypoint.1 - step;
                if (waypoint.1 < goalLocation.1) {
                    waypoint.1 = goalLocation.1;
                }
            } else if (waypoint.1 < goalLocation.1) {
                waypoint.1 = waypoint.1 + step;
                if (waypoint.1 > goalLocation.1) {
                    waypoint.1 = goalLocation.1;
                }
            }
            motionPlan += (sizeof(motionPlan), waypoint);
        }
        index = 0;
        while (index < sizeof(motionPlan)) {
            if (isHighPriorityMotionRequest) {
                send destinationOfRequest, eMotionX, motionPlan[index];
            } else {
                send destinationOfRequest, eMotion, motionPlan[index];
            }
            index = index + 1;
        }
    }

    fun handler(payload: (machine, locationType, locationType, bool)) {
        destinationOfRequest = payload.0;
        currentLocation = payload.1;
        goalLocation = payload.2;
        isHighPriorityMotionRequest = payload.3;
    }

    start state Init {
        entry {
            step = 0.25;
            goto Run;
        }
    }

    state Run {
        rtamodule {
            controller AC;
            controller SC;
            decisionmodule DM @ {AC: 1, SC: 1};
            on eMotionRequest, eMotionRequestX with handler;
        }
    }
}

machine MotionPrimitives {
    var motions: seq[locationType];
    var currentMotionIndex: int;
    var highPriorityMotions: seq[locationType];
    var currentHighPriorityMotionsIndex: int;
    var trajectoryDeviationThreshold: float;
    var trajectoryDeviation: float;
    var currentLocation: locationType;
    var currentMotion: locationType;
    var lastGoal: locationType;
    var advancedMotionControllerCount: int;
    var safeMotionControllerCount: int;
    var robot: machine;
    var rotateCount: int;
    var isBatteryLow: bool;

    fun DM(): string {
        var temp: bool;
        var isBumperReleasedLeft: bool;
        var isBumperReleasedRight: bool;
        isBumperReleasedLeft = GetIsBumperReleasedLeft();
        isBumperReleasedRight = GetIsBumperReleasedRight();
        if (!isBumperReleasedLeft) {
            return "LeftObstacleAvoidanceController";//Trun Right
        }
        if (!isBumperReleasedRight) {
            return "RightObstacleAvoidanceController";//Trun Left
        }
        temp = IsInTrajectory(currentLocation.0, currentLocation.1, currentMotion.0, currentMotion.1, trajectoryDeviationThreshold);
        if (temp) {
            return "AdvancedMotionController";
        }
        return "SafeMotionController";
    }

    fun LeftObstacleAvoidanceController() {
        var isBumperReleasedLeft: bool;
        var forwardSpeed: float;
        var rotationSpeed: float;
        forwardSpeed = 0.2;
        rotationSpeed = 0.8;
        isBumperReleasedLeft = GetIsBumperReleasedLeft();
        if (isBumperReleasedLeft && rotateCount >= 10) {
            MoveForward(forwardSpeed);
        } else if (isBumperReleasedLeft) {
            RotateRight(rotationSpeed);
            rotateCount = rotateCount + 1;
        } else {
            MoveBackward(forwardSpeed);
            rotateCount = 0;
        }
    }

    fun RightObstacleAvoidanceController() {
        var isBumperReleasedRight: bool;
        var forwardSpeed: float;
        var rotationSpeed: float;
        forwardSpeed = 0.2;
        rotationSpeed = 0.8;
        isBumperReleasedRight = GetIsBumperReleasedRight();
        if (isBumperReleasedRight && rotateCount >= 10) {
            MoveForward(forwardSpeed);
        } else if (isBumperReleasedRight) {
            RotateLeft(rotationSpeed);
            rotateCount = rotateCount + 1;
        } else {
            MoveBackward(forwardSpeed);
            rotateCount = 0;
        }
    }

    fun SafeMotionController() {
        var forwardSpeed: float;
        var rotationSpeed: float;
        forwardSpeed = 0.2;
        rotationSpeed = 0.8;
        if (currentHighPriorityMotionsIndex < sizeof(highPriorityMotions)) {
            currentMotion = highPriorityMotions[currentHighPriorityMotionsIndex];
            if (!RotateTowardsLocation(currentMotion.0, currentMotion.1, rotationSpeed)) {
                MoveForward(forwardSpeed);
            }
            if (CheckIfReached(currentMotion.0, currentMotion.1, forwardSpeed)) {
                currentLocation = currentMotion;
                currentHighPriorityMotionsIndex = currentHighPriorityMotionsIndex + 1;
                send robot, eCurrentLocation, currentLocation;
            }
            safeMotionControllerCount = safeMotionControllerCount + 1;
        } else if (!isBatteryLow && currentMotionIndex < sizeof(motions)) {
            currentMotion = motions[currentMotionIndex];
            if (!RotateTowardsLocation(currentMotion.0, currentMotion.1, rotationSpeed)) {
                MoveForward(forwardSpeed);
            }
            if (CheckIfReached(currentMotion.0, currentMotion.1, forwardSpeed)) {
                currentLocation = currentMotion;
                currentMotionIndex = currentMotionIndex + 1;
                send robot, eCurrentLocation, currentLocation;
            }
            safeMotionControllerCount = safeMotionControllerCount + 1;
        } else {
            Stay();
        }
    }

    fun AdvancedMotionController() {
        SafeMotionController();
        /*var forwardSpeed: float;
        var rotationSpeed: float;
        forwardSpeed = 0.22;
        rotationSpeed = 1.0;
        if (currentHighPriorityMotionsIndex < sizeof(highPriorityMotions)) {
            currentMotion = highPriorityMotions[currentHighPriorityMotionsIndex];
            RandomController(forwardSpeed, rotationSpeed);
            if (CheckIfReached(currentMotion.0, currentMotion.1, forwardSpeed)) {
                currentLocation = currentMotion;
                currentHighPriorityMotionsIndex = currentHighPriorityMotionsIndex + 1;
                send robot, eCurrentLocation, currentLocation;
            }
            advancedMotionControllerCount = advancedMotionControllerCount + 1;
        } else if (!isBatteryLow && currentMotionIndex < sizeof(motions)) {
            currentMotion = motions[currentMotionIndex];
            RandomController(forwardSpeed, rotationSpeed);
            if (CheckIfReached(currentMotion.0, currentMotion.1, forwardSpeed)) {
                currentLocation = currentMotion;
                currentMotionIndex = currentMotionIndex + 1;
                send robot, eCurrentLocation, currentLocation;
            }
            advancedMotionControllerCount = advancedMotionControllerCount + 1;
        } else {
            Stay();
        }*/
    }

    start state Init {
        entry (payload: (machine, locationType, float, float)) {
            currentMotionIndex = 0;
            currentHighPriorityMotionsIndex = 0;
            robot = payload.0;
            currentLocation = payload.1;
            trajectoryDeviationThreshold = payload.2;
            advancedMotionControllerCount = 0;
            safeMotionControllerCount = 0;
            rotateCount = 0;
            isBatteryLow = false;
            goto Run;
        }
    }

    state Run {
        rtamodule {
            controller SafeMotionController period 50 ms;
            controller AdvancedMotionController period 50 ms;
            controller LeftObstacleAvoidanceController period 200 ms;
            controller RightObstacleAvoidanceController period 200 ms;
            decisionmodule DM @ {SafeMotionController: 1, AdvancedMotionController: 1, LeftObstacleAvoidanceController: 20, RightObstacleAvoidanceController: 20};
        }
        on eMotion do (payload: locationType) {
            motions += (sizeof(motions), payload);
        }
        on eMotionX do (payload: locationType) {
            highPriorityMotions += (sizeof(highPriorityMotions), payload);
        }
        on eBatteryLow goto LowBatteryRun with (payload: machine) {
            send payload, eCurrentLocation, currentLocation;
            lastGoal = currentMotion;
            isBatteryLow = true;
        }
    }

    state LowBatteryRun {
        defer eMotion;
        rtamodule {
            controller SafeMotionController period 50 ms;
            controller AdvancedMotionController period 50 ms;
            controller LeftObstacleAvoidanceController period 200 ms;
            controller RightObstacleAvoidanceController period 200 ms;
            decisionmodule DM @ {SafeMotionController: 1, AdvancedMotionController: 1, LeftObstacleAvoidanceController: 20, RightObstacleAvoidanceController: 20};
        }
        on eMotionX do (payload: locationType) {
            highPriorityMotions += (sizeof(highPriorityMotions), payload);
        }
        on eBatteryRecovered goto Run with (payload: machine) {
            send payload, eCurrentGoal, lastGoal;
            isBatteryLow = false;
        }
    }
}


machine Battery {
    var destination: machine;
    var motionPlanner: machine;
    var chargerLocation: locationType;
    var previousBatteryLevel: float;
    var currentBatteryLevel: float;
    var batteryLevelLowerBound: float;
    var batteryLevelUpperBound: float;
    var isBatteryLow: bool;

    fun DM(): string {
        var isButtonB0PressedAndReleased: bool;
        isButtonB0PressedAndReleased = GetIsButtonPressedAndReleasedB0();
        previousBatteryLevel = currentBatteryLevel;
        currentBatteryLevel = GetBatteryLevel();
        if (!isBatteryLow && currentBatteryLevel < batteryLevelLowerBound && previousBatteryLevel >= batteryLevelLowerBound) {
            return "HandleLowBattery";
        }
        if (isBatteryLow && isButtonB0PressedAndReleased) {
            return "NotifyRecovery";
        }
        return "Idle";
    }

    fun Idle() {
        ;
    }

    fun HandleLowBattery() {
        isBatteryLow = true;
        send destination, eBatteryLow, this;
    }

    fun NotifyRecovery() {
        isBatteryLow = false;
        send destination, eBatteryRecovered, this;
    }

    start state Init {
        entry (payload: (machine, machine, locationType, float, float)) {
            destination = payload.0;
            motionPlanner = payload.1;
            chargerLocation = payload.2;
            batteryLevelLowerBound= payload.3;
            batteryLevelUpperBound= payload.4;
            isBatteryLow = false;
            previousBatteryLevel = 100.0;
            goto Run;
        }
    }

    state Run {
        rtamodule {
            controller Idle period 1 s;
            controller HandleLowBattery period 1 s;
            controller NotifyRecovery period 1 s;
            decisionmodule DM @ {Idle: 1, HandleLowBattery: 1, NotifyRecovery: 1};
        }
        on eCurrentLocation do (payload: locationType) {
            send motionPlanner, eMotionRequestX, (destination, payload, chargerLocation, true);
        }
        on eCurrentGoal do (payload: locationType) {
            send motionPlanner, eMotionRequestX, (destination, chargerLocation, payload, true);
        }
    }
}

