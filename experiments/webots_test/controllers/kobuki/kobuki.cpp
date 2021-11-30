// Copyright 1996-2021 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * Description:  This controller gives to its robot the following behavior:
 *               According to the messages it receives, the robot change its
 *               behavior.
 */

/* #include <webots/Camera.hpp> */
/* #include <webots/DistanceSensor.hpp> */
/* #include <webots/Motor.hpp> */
/* #include <webots/Receiver.hpp> */
/* #include <webots/Robot.hpp> */
/* #include <webots/utils/AnsiCodes.hpp> */
/* #include <webots/Lidar.hpp> */
/* #include <webots/Gyro.hpp> */
/* #include <webots/TouchSensor.hpp> */

#include "devices.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <cmath>

using namespace std;
using namespace webots;

static const double MAX_SPEED = 7.0;
static const double BATTERY_THRESHOLD = 20.0;
static const double speedMultiplier = 0.7;
static const double rotationSpeedMutliplier = 0.4;
static const double TOLERANCE_THRESHOLD = 0.10;
static const double ANGLE_THRESHOLD = M_PI / 18.0;

typedef struct Location {
    float x;
    float y;
    Location(float _x = 0, float _y = 0) { x = _x; y = _y; }
    friend bool operator == (const Location& l1, const Location& l2) {
        return fabs(l1.x - l2.x) < TOLERANCE_THRESHOLD && 
            fabs(l1.y - l2.y) < TOLERANCE_THRESHOLD;
    }
    friend bool operator != (const Location& l1, const Location& l2) {
        return !(l1 == l2);
    }
    friend ostream& operator << (ostream& out, const Location& l) {
        return out << "(" << l.x << ", " << l.y << ")";
    }
} Location;

class Kobuki {
public:
  Kobuki(int timestep = 32);
  void run();



private:
  /* enum Mode { STOP, MOVE_FORWARD, AVOID_OBSTACLES, TURN }; */
  enum Mode { ROBOT, MOTION_PLANNER, MOTION_PRIMITIVES, BATTERY };

  static double boundSpeed(double speed);

  void moveForward();
  bool rotateTowardNextLocation();
  bool isLowBattery();
  

  int timeStep;
  Mode mode;
  Location batteryChargeStation;
  Location currentLocation;
  Location goalLocation;
  Location nextLocation;
  float orientation;
  int numGoalLocation;
  int currentGoalIndex;
  /* Receiver *receiver; */
  /* Camera *camera; */
  /* DistanceSensor *distanceSensors[2]; */
  /* Gyro * gyro; */
  /* Motor * motors[2]; */
  /* Lidar * lidars[3]; */
  /* TouchSensor * bumpSensors[3]; */
  Devices devices;
};

Kobuki::Kobuki(int timestep)
    : batteryChargeStation(Location(0, 0))
    , currentLocation(Location(0, 0))
    , orientation(0.0)
    , numGoalLocation(4)
    , currentGoalIndex(0)
{
  timeStep = timestep;
  mode = ROBOT;
  devices.init(timeStep);
  /* camera = getCamera("camera"); */
  /* camera->enable(4 * timeStep); */
  /* receiver = getReceiver("receiver"); */
  /* receiver->enable(timeStep); */
  /* gyro = getGyro("gyro"); */
  /* gyro->enable(timeStep); */
  
  /* motors[0] = getMotor("wheel_left_joint"); */
  /* motors[1] = getMotor("wheel_right_joint"); */
  /* motors[0]->setPosition(std::numeric_limits<double>::infinity()); */
  /* motors[1]->setPosition(std::numeric_limits<double>::infinity()); */
  /* motors[0]->setVelocity(0.0); */
  /* motors[1]->setVelocity(0.0); */
  
  /* lidars[0] = getLidar("cliff_sensor_left"); */
  /* lidars[1] = getLidar("cliff_sensor_right"); */
  /* lidars[2] = getLidar("cliff_sensor_front"); */
  
  /* for (int i = 0; i < 3; ++i) */
  /*   lidars[i]->enable(timeStep); */
    
  /* bumpSensors[0] = getTouchSensor("bump_sensor_left"); */
  /* bumpSensors[1] = getTouchSensor("bump_sensor_right"); */
  /* bumpSensors[2] = getTouchSensor("bump_sensor_front"); */
  
  /* for (int i = 0; i < 3; ++i) */
  /*   bumpSensors[i]->enable(timeStep); */

  /* string distanceSensorNames("ds0"); */
  /* for (int i = 0; i < 2; i++) { */
  /*   distanceSensors[i] = getDistanceSensor(distanceSensorNames); */
  /*   distanceSensors[i]->enable(timeStep); */
  /*   distanceSensorNames[2]++;  // for getting "ds1","ds2",... */
  /* } */
}

double Kobuki::boundSpeed(double speed) {
  return std::min(MAX_SPEED, std::max(-MAX_SPEED, speed));
}

bool Kobuki::rotateTowardNextLocation() {
    float x_diff = nextLocation.x - currentLocation.x;
    float y_diff = nextLocation.y - currentLocation.y;
    float angle2Goal = atan2(y_diff, x_diff) - M_PI;
    angle2Goal = angle2Goal < 0? angle2Goal + 2 * M_PI: angle2Goal;
    float angle_difference = angle2Goal - orientation;

    if (fabs(angle_difference) > ANGLE_THRESHOLD) {
        if (angle_difference > 0) { // counterclockwise
            devices.setMotor(-rotationSpeedMutliplier * MAX_SPEED, rotationSpeedMutliplier * MAX_SPEED);
            orientation += rotationSpeedMutliplier / 2.0 * MAX_SPEED * timeStep / 1000.0;
        }
        else { // clockwise
            devices.setMotor(rotationSpeedMutliplier * MAX_SPEED, -rotationSpeedMutliplier * MAX_SPEED);
            orientation -= rotationSpeedMutliplier / 2.0 * MAX_SPEED * timeStep / 1000.0;
        }
        devices.step(timeStep);
        if (orientation < 0) orientation += 2 * M_PI;
        if (orientation >= 2 * M_PI) orientation -= 2 * M_PI;
        return true;
    }
    return false;
}

void Kobuki::moveForward() {
    devices.setMotor(speedMultiplier * MAX_SPEED, speedMultiplier * MAX_SPEED);
    cout << speedMultiplier * MAX_SPEED * timeStep / 1000.0 * cos(orientation)<< '\n';
    devices.step(timeStep);
    currentLocation.x += speedMultiplier * MAX_SPEED * timeStep / 1000.0 * cos(orientation);
    currentLocation.y += speedMultiplier * MAX_SPEED * timeStep / 1000.0 * sin(orientation);
}

bool Kobuki::isLowBattery() {
    return devices.getBatteryLevel() < BATTERY_THRESHOLD;
}

void Kobuki::run() {
  // main loop
  Location goalLocations[] = {Location(10,10), Location(10,-10), Location(-10,-10), Location(-10,10)};
  float xStep, yStep, stepSize = 0.8;

  while (devices.step(timeStep) != -1) {
    switch (mode) {
        case ROBOT: 
        {
            cout << "ROBOT\n";
            if (isLowBattery()) {
                goalLocation = batteryChargeStation;
            } else if (currentLocation == goalLocation) {
                if (goalLocation != batteryChargeStation) {
                    currentGoalIndex = (currentGoalIndex + 1) % numGoalLocation;
                    goalLocation = goalLocations[currentGoalIndex];
                }
            } else {

            }
            mode = MOTION_PLANNER;
            devices.setMotor(0,0);
        } break;
        case MOTION_PLANNER:
        {
            cout << "MOTION_PLANNER\n";
            cout << currentLocation << " " << nextLocation << "\n";
            if (currentLocation.x - goalLocation.x > TOLERANCE_THRESHOLD) {
                xStep = -1;
            } else if (goalLocation.x - currentLocation.x > TOLERANCE_THRESHOLD) {
                xStep = 1;
            } else {
                xStep = 0;
            }
            if (currentLocation.y - goalLocation.y > TOLERANCE_THRESHOLD) {
                yStep = -1;
            } else if (goalLocation.y - currentLocation.x > TOLERANCE_THRESHOLD) {
                yStep = 1;
            } else {
                yStep = 0;
            }
            nextLocation.x = currentLocation.x + xStep * stepSize;
            nextLocation.y = currentLocation.y + yStep * stepSize;
            mode = MOTION_PRIMITIVES;
            devices.setMotor(0,0);
        } break;
        case MOTION_PRIMITIVES: 
        {
            cout << "MOTION_PRIMITIVES\n";
            if (!rotateTowardNextLocation()) {
                // move forward
                moveForward();
            }
            if (currentLocation == goalLocation) { // reach destination
                mode = (goalLocation == batteryChargeStation)? BATTERY: ROBOT;
            } else {
                mode = MOTION_PLANNER;
            }
        } break;
        case BATTERY: 
        {
            cout << "BATTERY\n";
            devices.chargeBattery();
            /* devices.setMotor(0, 0); */
            mode = ROBOT;
        } break;
    }
    // Read sensors, particularly the order of the supervisor
    /* if (receiver->getQueueLength() > 0) { */
    /*   string message((const char *)receiver->getData()); */
    /*   receiver->nextPacket(); */

    /*   cout << "I should " << AnsiCodes::RED_FOREGROUND << message << AnsiCodes::RESET << "!" << endl; */

    /*   if (message.compare("avoid obstacles") == 0) */
    /*     mode = AVOID_OBSTACLES; */
    /*   else if (message.compare("move forward") == 0) */
    /*     mode = MOVE_FORWARD; */
    /*   else if (message.compare("stop") == 0) */
    /*     mode = STOP; */
    /*   else if (message.compare("turn") == 0) */
    /*     mode = TURN; */
    /* } */
    /* mode = MOVE_FORWARD; */
    /* double delta = distanceSensors[0]->getValue() - distanceSensors[1]->getValue(); */
    /* double delta = .1; */
    /* double speeds[2] = {0.0, 0.0}; */

    /* // send actuators commands according to the mode */
    /* switch (mode) { */
    /*   case AVOID_OBSTACLES: */
    /*     speeds[0] = boundSpeed(maxSpeed / 2.0 + 0.1 * delta); */
    /*     speeds[1] = boundSpeed(maxSpeed / 2.0 - 0.1 * delta); */
    /*     break; */
    /*   case MOVE_FORWARD: */
    /*     speeds[0] = maxSpeed; */
    /*     speeds[1] = maxSpeed; */
    /*     break; */
    /*   case TURN: */
    /*     speeds[0] = maxSpeed / 2.0; */
    /*     speeds[1] = -maxSpeed / 2.0; */
    /*     break; */
    /*   default: */
    /*     break; */
    /* } */
    /* motors[0]->setVelocity(speeds[0]); */
    /* motors[1]->setVelocity(speeds[1]); */
    /* devices.setMotor(speeds[0], speeds[1]); */
    
    /* GyroMeasurement_t gm; */
    /* devices.readGyro(gm); */
    /* cout << gm << '\n'; */

    /* std::cout << "x: " << gm.x << ", y: " << gm.y */ 
    /*           << ", z: " << gm.z << '\n'; // angular velocity */
    /* const double * gyroVals = gyro->getValues(); */
    /* std::cout << "x: " << gyroVals[0] << ", y: " << gyroVals[1] */ 
    /*           << ", z: " << gyroVals[2] << '\n'; // angular velocity */
    // std::cout << lidars[0]->isPointCloudEnabled() << '\n';
    // std::cout << lidars[0]->getNumberOfPoints() << '\n';
    // const LidarPoint * lidarPoints = lidars[2]->getPointCloud();
    // int numPoints = lidars[0]->getNumberOfPoints();
    
    /* LidarMeasurement_t lm; */
    /* devices.readLidarImage(lm); */
    /* for (int i = 0; i < devices.getLidarHorizontalResolution(); ++i) */
    /*   cout << lm.left[i] << ' '; */
    /* cout << '\n'; */
    
    /* const float * rangeImage = lidars[0]->getRangeImage(); */
    /* int resolution = lidars[0]->getHorizontalResolution(); */
    /* for (int i = 0; i < resolution; ++i) */
    /*   cout << rangeImage[i] << ' '; */
    /* cout << '\n'; */

    /* BumpMeasurement_t bm; */
    /* devices.readBump(bm); */
    /* cout << bm << '\n'; */

    /* std::cout << "left: " << bm.left << ", right: " << bm.right */
    /*           << ", front: " << bm.front << '\n'; */
    /* std::cout <<    "left: " << bool(bumpSensors[0]->getValue()) */
    /*           << ", right: " << bool(bumpSensors[1]->getValue()) */
    /*           << ", front: " << bool(bumpSensors[2]->getValue()) << '\n'; */
  }
}

int main() {
  Kobuki *controller = new Kobuki();
  controller->run();
  delete controller;
  return 0;
}
