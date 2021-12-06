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

#include <ompl/base/SpaceInformation.h>
#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/geometric/planners/rrt/RRTConnect.h>
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/geometric/PathGeometric.h>
#include <ompl/config.h>



using namespace std;
using namespace webots;
  
namespace ob = ompl::base;
namespace og = ompl::geometric;


static const double MAX_SPEED = 7.0;
static const double BATTERY_THRESHOLD = 20.0;
static const double speedMultiplier = 0.7;
static const double rotationSpeedMutliplier = 0.4;
static const double TOLERANCE_THRESHOLD = 0.10;
static const double ANGLE_THRESHOLD = M_PI / 18.0;
/* static const double ANGLE_FRAME_OFFSET = -M_PI; */

// PID gains
static const double K_ap = 0.0;
static const double K_av = 0.0;
static const double K_ai = 0.0;
static const double K_tp = -10.0;
static const double K_tv = .1;
static const double K_ti = -.05;
static const double BASE_SPEED = 5.0;

// OMPL constants
static const double GRIDLOW = -1.5;
static const double GRIDHIGH = 1.5;

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

bool isStateValid(const ob::State *state) {
    //  cast the abstract state type to the type we expect
    const auto *se2state = state->as<ob::SE2StateSpace::StateType>();
    
    // extract the first component of the state and cast it to what we expect
    const auto *pos = se2state->as<ob::RealVectorStateSpace::StateType>(0);

    // extract the second component of the state and cast it to what we expect
    /* const auto *rot = se2state->as<ob::SO2StateSpace::StateType>(1); */

    // check validity of state defined by pos & rot
    float x = pos->values[0];
    float y = pos->values[1];

    if (sqrt(pow(x-1,2) + pow(y-0,2)) < .5) {
      return false;
    }
    if (sqrt(pow(x+1,2) + pow(y-0,2)) < .5) {
      return false;
    }
    return true;
}


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
  bool reached(Location current, Location goal);
  Location getNextWaypoint();
  void plan();
  void stepPID();
  void updateLocalization();

  shared_ptr<ob::SE2StateSpace> space;
  og::SimpleSetup ss;
  og::PathGeometric waypoints;
  int currWaypointIndex;

  // PID controller
  float prev_position_difference;
  float prev_angle_difference;
  float position_integral;
  float angle_integral;
  float velocity;
  float angl_velocity;
  
  // sensor readings
  GyroMeasurement_t odomPosition;
  GyroMeasurement_t odomOrientation;

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
    // construct the state space we are planning in
    , space(std::make_shared<ob::SE2StateSpace>())
    // define a simple setup class
    , ss(space)
    , waypoints(ss.getSpaceInformation())
{
  timeStep = timestep;
  mode = ROBOT;
  devices.init(timeStep);

  // construct the state space we are planning in
  /* space(std::make_shared<ob::SE2StateSpace>()) */

  // set the bounds for the R^2 part of SE(2)
  ob::RealVectorBounds bounds(2);
  bounds.setLow(GRIDLOW);
  bounds.setHigh(GRIDHIGH);

  space->setBounds(bounds);

  // define a simple setup class
  /* ss(space); */

  // set state validity checking for this space
  ss.setStateValidityChecker([](const ob::State *state) { return isStateValid(state); });

  /* waypoints(ss.getSpaceInformation()); */
  
}

float normalizeAngle(float a1) {
    if (a1 > M_PI) {
      return a1 - 2*M_PI;
    } else if (a1 < -M_PI) {
      return a1 + 2*M_PI;
    } else {
      return a1;
    }
}

float angleDiff(float a1, float a2) {
    return normalizeAngle(normalizeAngle(a1) - normalizeAngle(a2));
}

double Kobuki::boundSpeed(double speed) {
  return std::min(MAX_SPEED, std::max(-MAX_SPEED, speed));
}

bool Kobuki::rotateTowardNextLocation() {
    float x_diff = nextLocation.x - currentLocation.x;
    float y_diff = nextLocation.y - currentLocation.y;
    float angle2Goal = atan2(y_diff, x_diff);
    angle2Goal = angle2Goal < 0? angle2Goal + 2 * M_PI: angle2Goal;
    float angle_difference = angle2Goal - orientation;
    cout << angle_difference;

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

void Kobuki::updateLocalization() {
    devices.getPose(odomPosition);
    devices.getOrientation(odomOrientation);
    currentLocation.x = odomPosition.x;
    currentLocation.y = odomPosition.z;
    orientation = odomOrientation.z;
    /* orientation = orientation > M_PI ? orientation - 2 * M_PI : orientation; */
    /* orientation = orientation < -M_PI ? orientation + 2 * M_PI : orientation; */
}

void Kobuki::stepPID() {
    // One PID controller for deviation from the line between two points (to control torque)
    // Another PID controller for distance to the next goal (to control acceleration)
    
    float x_diff = nextLocation.x - currentLocation.x;
    float y_diff = nextLocation.y - currentLocation.y;
    float target_orientation = -atan2(y_diff, x_diff);
    cout << "Current orientation:" << orientation << endl;
    cout << "Target orientation:" << target_orientation << endl;
    target_orientation = normalizeAngle(target_orientation);

    /* target_orientation = target_orientation < 0? target_orientation + 2 * M_PI: target_orientation; */

    float position_difference = sqrt(pow(x_diff,2) + pow(y_diff,2));
    float angle_difference = angleDiff(target_orientation, orientation);

    cout << "Position Diff = " << position_difference << endl;
    cout << "Angle Diff = " << angle_difference << endl;

    float position_velocity = position_difference - prev_position_difference;
    float angle_velocity = angle_difference - prev_angle_difference;

    position_integral += position_difference;
    angle_integral += angle_difference;

    float pos_out = BASE_SPEED + K_ap * position_difference + K_av * position_velocity + K_ai * position_integral;
    float angl_out = K_tp * angle_difference + K_tv * angle_velocity + K_ti * angle_integral;

    cout << "Speed = " << velocity << endl;
    cout << "Rotational speed = " << angl_velocity << endl;

    /* velocity += accel / 1000.0; */
    /* angl_velocity += angl_accel / 1000.0; */

    /* cout << "Velocity = " << velocity << endl; */
    /* cout << "Anglular Velocity = " << angl_velocity << endl; */
    float SPEED_SCALE = 1.0;
    /* devices.setMotor((velocity + angl_velocity) * SPEED_SCALE, (velocity - angl_velocity) * SPEED_SCALE); */
    devices.setMotor((pos_out + angl_out) * SPEED_SCALE, (pos_out - angl_out) * SPEED_SCALE);

    prev_position_difference = position_difference;
    prev_angle_difference = angle_difference;

    devices.step(timeStep);
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

void Kobuki::plan() {
    // set start state
    ob::ScopedState<> start(space);
    start->as<ob::SE2StateSpace::StateType>()->setX(currentLocation.x);
    start->as<ob::SE2StateSpace::StateType>()->setY(currentLocation.y);
  
    // set goal state
    ob::ScopedState<> goal(space);
    goal->as<ob::SE2StateSpace::StateType>()->setX(goalLocation.x);
    goal->as<ob::SE2StateSpace::StateType>()->setY(goalLocation.y);
  
    // set the start and goal states
    ss.setStartAndGoalStates(start, goal);
    std::cout << "Planning towards: " << goalLocation << std::endl;

    // this call is optional, but we put it in to get more output information
    /* ss.setup(); */
    /* ss.print(); */
  
    // attempt to solve the problem within one second of planning time
    ob::PlannerStatus solved = ss.solve(1.0);

    if (solved)
    {
        std::cout << "Found solution:" << std::endl;
        // print the path to screen
        ss.simplifySolution();
        ss.getSolutionPath().print(std::cout);
        waypoints = ss.getSolutionPath();
        currWaypointIndex = 1;
    }
    else
        std::cout << "No solution found" << std::endl;

    ss.clear();
 }

bool Kobuki::reached(Location l1, Location l2) {
    return l1 == l2;
}

Location Kobuki::getNextWaypoint() {
    // just return the next waypoint for now
    auto loc = Location(waypoints.getState(currWaypointIndex)->as<ob::SE2StateSpace::StateType>()->getX(), waypoints.getState(currWaypointIndex)->as<ob::SE2StateSpace::StateType>()->getY());
    currWaypointIndex += 1;
    return loc;
}

void Kobuki::run() {
  // main loop
  Location goalLocations[] = {Location(1,1), Location(1,-1), Location(-1,-1), Location(-1,1)};
  goalLocation = goalLocations[0];
  plan();

  while (devices.step(timeStep) != -1) {
    // update sensor localization
    updateLocalization();
    switch (mode) {
        case ROBOT: 
        {
            cout << "ROBOT\n";
            if (isLowBattery()) {
                cout << "GOING TO RECHARGE" << endl;
                goalLocation = batteryChargeStation;
                plan();
            } else if (currentLocation == goalLocation) {
                if (goalLocation != batteryChargeStation) {
                    currentGoalIndex = (currentGoalIndex + 1) % numGoalLocation;
                    goalLocation = goalLocations[currentGoalIndex];
                    plan();
                }
            } else {

            }
            mode = MOTION_PLANNER;
            devices.setMotor(0,0);
        } break;
        case MOTION_PLANNER:
        {
            cout << "MOTION_PLANNER\n";
            cout << currentLocation << " --> " << nextLocation << "\n";
            if (reached(currentLocation, nextLocation)) {
              // replan
              cout << "Reached next waypoint!" << "\n";
              cout << nextLocation << endl << goalLocation << endl;
              if (nextLocation == goalLocation) {
                mode = ROBOT;
              }
              else {
                cout << "Getting next waypoint";
                nextLocation = getNextWaypoint();
              }
            }

            mode = MOTION_PRIMITIVES;
            devices.setMotor(0,0);
        } break;
        case MOTION_PRIMITIVES: 
        {
            cout << "MOTION_PRIMITIVES\n";
            /* if (!rotateTowardNextLocation()) { */
            /*     // move forward */
            /*     cout << "MOVING FORWARD\n"; */
            /*     moveForward(); */
            /* } */
            /* else { */
            /*     cout << "ROTATING\n"; */
            /* } */
            stepPID();
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
    
  }
}

int main() {
  Kobuki *controller = new Kobuki();
  controller->run();
  delete controller;
  return 0;
}
