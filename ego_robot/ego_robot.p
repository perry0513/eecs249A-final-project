fun Init(): int;
fun CheckIfReached(x: float, z:float, speed:float): bool;
fun RotateTowardsLocation(x: float, z:float, speed:float): bool;
fun MoveForward(positionalSpeed: float, rotationalSpeed: float): int;
fun MoveBackward(speed: float): int;
fun RotateLeft(speed: float): int;
fun RotateRight(speed: float): int;
fun Stay(): int;
fun IsInTrajectory(x0: float, z0: float, x1:float, z1:float, trajectoryDeviationThreshold: float): bool;
fun RandomController(forwardSpeed: float, rotationSpeed: float): int;
fun GetRobotPosition(): seq[float];
fun GetChargerPosition(): seq[float];
fun GetIsBumperReleasedLeft(): bool;
fun GetIsBumperReleasedCenter(): bool;
fun GetIsBumperReleasedRight(): bool;
fun GetIsCliffLeft(): bool;
fun GetIsCliffRight(): bool;
fun GetIsCliffCenter(): bool;
fun GetBatteryLevel(): float;
fun GetIsButtonPressedAndReleasedB0(): bool;
fun StepPID(x: float, z:float): int;
fun GetOMPLMotionPlanAC(currentLocationX: float, currentLocationZ: float, goalLocationX: float, goalLocationZ: float): seq[(float, float)];
fun GetOMPLMotionPlanSC(currentLocationX: float, currentLocationZ: float, goalLocationX: float, goalLocationZ: float): seq[(float, float)];
fun RegisterAvoidLocation(): int;
fun SetLed(led_num: int, led_color: int): int;

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
            motionPlanner = new MotionPlanner();
            motionPrimitives = new MotionPrimitives(this, motionPlanner, currentLocation, 0.1, 300.0);
            battery = new Battery(motionPrimitives, motionPlanner, chargerLocation, 50.0, 100.0);
            goals += (sizeof(goals), (1.0, 1.0));
            goals += (sizeof(goals), (-1.0, 1.0));
            goals += (sizeof(goals), (-1.0, -1.0));
            goals += (sizeof(goals), (1.0, -1.0));
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
        if (false) {
            return "AC";
        }
        return "SC";
    }

    fun AC() {
        var motionPlan: seq[locationType];
        var index: int;
        motionPlan = GetOMPLMotionPlanAC(currentLocation.0, currentLocation.1, goalLocation.0, goalLocation.1);
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
        var motionPlan: seq[locationType];
        var index: int;
        motionPlan = GetOMPLMotionPlanSC(currentLocation.0, currentLocation.1, goalLocation.0, goalLocation.1);
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
    var bumpCountPerGoalLocation: int;
    var bumpCountThreshold: int;
    var isPreviouslyBumpedLeft: bool;
    var isPreviouslyBumpedRight: bool;
    var isPreviouslyBumpedCenter: bool;
    var motionPlanner: machine;
    var isAvoidLocationSent: bool;
    var backwardCount: int;

    fun DM(): string {
        var temp: bool;
        var isBumperReleasedLeft: bool;
        var isBumperReleasedCenter: bool;
        var isBumperReleasedRight: bool;
        var isCliffLeft: bool;
        var isCliffRight: bool;
        var isCliffCenter: bool;
        isBumperReleasedLeft = GetIsBumperReleasedLeft();
        isBumperReleasedCenter = GetIsBumperReleasedCenter();
        isBumperReleasedRight = GetIsBumperReleasedRight();
        isCliffLeft = GetIsCliffLeft();
        isCliffRight = GetIsCliffRight();
        isCliffCenter = GetIsCliffCenter();
        isAvoidLocationSent = false;
        SetLed(0, 0); /* set led0 to black */
        SetLed(1, 0); /* set led1 to black */
        if ((!isBumperReleasedLeft || !isBumperReleasedCenter || !isBumperReleasedRight)) {
            SetLed(1, 3); /* set led1 to orange */
            backwardCount = 0;
            return "ObstacleAvoidanceController";
        }
        if (isCliffLeft) {
            SetLed(1, 1); /* set led1 to red */
            return "LeftCliffAvoidanceController";
        }
        if (isCliffRight) {
            SetLed(1, 1); /* set led1 to red */
            return "RightCliffAvoidanceController";
        }
        if (isCliffCenter) {
            SetLed(1, 1); /* set led1 to red */
            return "CenterCliffAvoidanceController";
        }
        temp = IsInTrajectory(currentLocation.0, currentLocation.1, currentMotion.0, currentMotion.1, trajectoryDeviationThreshold);
        if (temp) {
            SetLed(0, 2); /* set led0 to green */
            return "AdvancedMotionController";
        }
        SetLed(0, 1); /* set led0 to red */
        return "SafeMotionController";
    }

    fun ObstacleAvoidanceController() {
        var isBumperReleasedLeft: bool;
        var isBumperReleasedCenter: bool;
        var isBumperReleasedRight: bool;
        var forwardSpeed: float;
        var rotationSpeed: float;
        forwardSpeed = 0.2;
        rotationSpeed = 0.8;
        isBumperReleasedLeft = GetIsBumperReleasedLeft();
        isBumperReleasedCenter = GetIsBumperReleasedCenter();
        isBumperReleasedRight = GetIsBumperReleasedRight();
        if (!isAvoidLocationSent) {
            isAvoidLocationSent = true;
            RegisterAvoidLocation();
        }
        if (!isBumperReleasedLeft || backwardCount < 20) {
            MoveBackward(forwardSpeed);
            isPreviouslyBumpedLeft = true;
            isPreviouslyBumpedCenter = false;
            isPreviouslyBumpedRight = false;
            rotateCount = 0;
            if (isBumperReleasedLeft) {
                backwardCount = backwardCount + 1;
            }
        } else if (!isBumperReleasedCenter || backwardCount < 50) {
            MoveBackward(forwardSpeed);
            isPreviouslyBumpedLeft = false;
            isPreviouslyBumpedCenter = true;
            isPreviouslyBumpedRight = false;
            rotateCount = 0;
            if (isBumperReleasedCenter) {
                backwardCount = backwardCount + 1;
            }
        } else if (!isBumperReleasedRight || backwardCount < 50) {
            MoveBackward(forwardSpeed);
            isPreviouslyBumpedLeft = false;
            isPreviouslyBumpedCenter = false;
            isPreviouslyBumpedRight = true;
            rotateCount = 0;
            if (isBumperReleasedRight) {
                backwardCount = backwardCount + 1;
            }
        } else if (isPreviouslyBumpedLeft && rotateCount < 100) {
            RotateRight(rotationSpeed);
            rotateCount = rotateCount + 1;
        } else if (isPreviouslyBumpedCenter && rotateCount < 100) {
            RotateLeft(rotationSpeed);
            rotateCount = rotateCount + 1;
        } else if (isPreviouslyBumpedRight && rotateCount < 100) {
            RotateLeft(rotationSpeed);
            rotateCount = rotateCount + 1;
        } else if (isPreviouslyBumpedLeft) {
            MoveForward(forwardSpeed, 0.4);
        } else if (isPreviouslyBumpedCenter) {
            MoveForward(forwardSpeed, -0.4);
        } else if (isPreviouslyBumpedRight) {
            MoveForward(forwardSpeed, -0.4);
        }
    }

    fun LeftCliffAvoidanceController() {
        var isCliffLeft: bool;
        var forwardSpeed: float;
        var rotationSpeed: float;
        forwardSpeed = 0.2;
        rotationSpeed = 0.8;
        isCliffLeft = GetIsCliffLeft();
        if (!isCliffLeft) {
            if (rotateCount >= 10) {
                MoveForward(forwardSpeed, 0.0);
            } else {
                RotateRight(rotationSpeed);
                rotateCount = rotateCount + 1;
            }
        } else {
            MoveBackward(forwardSpeed);
            rotateCount = 0;
        }
    }

    fun RightCliffAvoidanceController() {
        var isCliffLeft: bool;
        var forwardSpeed: float;
        var rotationSpeed: float;
        forwardSpeed = 0.2;
        rotationSpeed = 0.8;
        isCliffLeft = GetIsCliffRight();
        if (!isCliffLeft) {
            if (rotateCount >= 10) {
                MoveForward(forwardSpeed, 0.0);
            } else {
                RotateLeft(rotationSpeed);
                rotateCount = rotateCount + 1;
            }
        } else {
            MoveBackward(forwardSpeed);
            rotateCount = 0;
        }
    }
    
    fun CenterCliffAvoidanceController() {
        var isCliffLeft: bool;
        var forwardSpeed: float;
        var rotationSpeed: float;
        forwardSpeed = 0.2;
        rotationSpeed = 0.8;
        isCliffLeft = GetIsCliffCenter();
        if (!isCliffLeft) {
            if (rotateCount >= 10) {
                MoveForward(forwardSpeed, 0.0);
            } else {
                /* RotateRight(rotationSpeed); */
                RotateLeft(rotationSpeed);
                rotateCount = rotateCount + 1;
            }
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
                MoveForward(forwardSpeed, 0.0);
            }
            if (CheckIfReached(currentMotion.0, currentMotion.1, forwardSpeed)) {
                currentLocation = currentMotion;
                currentHighPriorityMotionsIndex = currentHighPriorityMotionsIndex + 1;
                bumpCountPerGoalLocation = 0;
                isPreviouslyBumpedLeft = false;
                isPreviouslyBumpedCenter = false;
                isPreviouslyBumpedRight = false;
                send robot, eCurrentLocation, currentLocation;
            }
            safeMotionControllerCount = safeMotionControllerCount + 1;
        } else if (!isBatteryLow && currentMotionIndex < sizeof(motions)) {
            currentMotion = motions[currentMotionIndex];
            if (!RotateTowardsLocation(currentMotion.0, currentMotion.1, rotationSpeed)) {
                MoveForward(forwardSpeed, 0.0);
            }
            if (CheckIfReached(currentMotion.0, currentMotion.1, forwardSpeed)) {
                currentLocation = currentMotion;
                currentMotionIndex = currentMotionIndex + 1;
                bumpCountPerGoalLocation = 0;
                isPreviouslyBumpedLeft = false;
                isPreviouslyBumpedCenter = false;
                isPreviouslyBumpedRight = false;
                send robot, eCurrentLocation, currentLocation;
            }
            safeMotionControllerCount = safeMotionControllerCount + 1;
        } else {
            Stay();
        }
    }

    fun AdvancedMotionController() {
        var speedMultiplier: float;
        speedMultiplier = 2.0;
        if (currentHighPriorityMotionsIndex < sizeof(highPriorityMotions)) {
            currentMotion = highPriorityMotions[currentHighPriorityMotionsIndex];
            StepPID(currentMotion.0, currentMotion.1);
            if (CheckIfReached(currentMotion.0, currentMotion.1, speedMultiplier)) {
                currentLocation = currentMotion;
                currentHighPriorityMotionsIndex = currentHighPriorityMotionsIndex + 1;
                bumpCountPerGoalLocation = 0;
                isPreviouslyBumpedLeft = false;
                isPreviouslyBumpedCenter = false;
                isPreviouslyBumpedRight = false;
                send robot, eCurrentLocation, currentLocation;
            }
            advancedMotionControllerCount = advancedMotionControllerCount + 1;
        } else if (!isBatteryLow && currentMotionIndex < sizeof(motions)) {
            currentMotion = motions[currentMotionIndex];
            StepPID(currentMotion.0, currentMotion.1);
            if (CheckIfReached(currentMotion.0, currentMotion.1, speedMultiplier)) {
                currentLocation = currentMotion;
                currentMotionIndex = currentMotionIndex + 1;
                bumpCountPerGoalLocation = 0;
                isPreviouslyBumpedLeft = false;
                isPreviouslyBumpedCenter = false;
                isPreviouslyBumpedRight = false;
                send robot, eCurrentLocation, currentLocation;
            }
            advancedMotionControllerCount = advancedMotionControllerCount + 1;
        } else {
            Stay();
        }
    }

    start state Init {
        entry (payload: (machine, machine, locationType, float, float)) {
            currentMotionIndex = 0;
            currentHighPriorityMotionsIndex = 0;
            robot = payload.0;
            motionPlanner = payload.1;
            currentLocation = payload.2;
            trajectoryDeviationThreshold = payload.3;
            advancedMotionControllerCount = 0;
            safeMotionControllerCount = 0;
            rotateCount = 0;
            isBatteryLow = false;
            bumpCountPerGoalLocation = 0;
            bumpCountThreshold = 2;
            isPreviouslyBumpedLeft = false;
            isPreviouslyBumpedCenter = false;
            isPreviouslyBumpedRight = false;
            isAvoidLocationSent = false;
            goto Run;
        }
    }

    state Run {
        rtamodule {
            controller SafeMotionController period 20 ms;
            controller AdvancedMotionController period 10 ms;
            controller ObstacleAvoidanceController period 20 ms;
            controller LeftCliffAvoidanceController period 20 ms;
            controller RightCliffAvoidanceController period 20 ms;
            controller CenterCliffAvoidanceController period 20 ms;
            decisionmodule DM @ {SafeMotionController: 1,
                                 AdvancedMotionController: 1,
                                 ObstacleAvoidanceController: 400,
                                 LeftCliffAvoidanceController: 100,
                                 RightCliffAvoidanceController: 100,
                                 CenterCliffAvoidanceController: 100};
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
            controller SafeMotionController period 20 ms;
            controller AdvancedMotionController period 10 ms;
            controller ObstacleAvoidanceController period 20 ms;
            controller LeftCliffAvoidanceController period 20 ms;
            controller RightCliffAvoidanceController period 20 ms;
            controller CenterCliffAvoidanceController period 20 ms;
            decisionmodule DM @ {SafeMotionController: 1,
                                 AdvancedMotionController: 1,
                                 ObstacleAvoidanceController: 400,
                                 LeftCliffAvoidanceController: 100,
                                 RightCliffAvoidanceController: 100,
                                 CenterCliffAvoidanceController: 100};
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

