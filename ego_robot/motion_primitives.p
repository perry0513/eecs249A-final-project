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