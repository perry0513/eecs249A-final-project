/**                                                                           !
 * @file src/demos/simple_loop.cpp
 *
 * @brief Example program with a simple control loop.
 *
 * Controls the kobuki around a dead-reckoned square with sides of
 * length 0.25m.
 *
 * License: BSD
 *   https://raw.githubusercontent.com/kobuki-base/kobuki_core/license/LICENSE
 **/

/*****************************************************************************
 * Includes
 ****************************************************************************/

#include "helper.hpp"

#include <string>

#include <csignal>
#include <ecl/geometry.hpp>
#include <ecl/time.hpp>
#include <ecl/sigslots.hpp>
#include <ecl/linear_algebra.hpp>
#include <ecl/command_line.hpp>
#include "kobuki_core/kobuki.hpp"
#include "kobuki_core/event_manager.hpp"

#include <cmath>

double x_position = 0.0;
double y_position = 0.0;
double z_position = 0.0;

double orientation = 0.0;

double x_start = 0.0;
double y_start = 0.0;
double z_start = 0.0;

double charger_x = 0.0;
double charger_y = 0.0;
double charger_z = 0.0;

float batteryLevel = 100.0;
float batteryStep = 0.1;


/*****************************************************************************
** Classes
*****************************************************************************/

class KobukiManager {
public:
  KobukiManager(
      const std::string & device,
      const double &length,
      const bool &disable_smoothing
  ) :
    dx(0.0), dth(0.0),
    length(length),
    is_bumper_released_left(true),
    is_bumper_released_right(true),
    is_button_pressed_b0(false),
    is_button_pressed_and_released_b0(false),
    slot_stream_data(&KobukiManager::processStreamData, *this),
    slot_bumper_event(&KobukiManager::processBumperEvent, *this),
    slot_button_event(&KobukiManager::processButtonEvent, *this)
    slot_cliff_event(&KobukiManager::processCliffEvent, *this),
    is_bumper_released_left(true), is_bumper_released_right(true),
    is_cliff_left(false), is_cliff_center(false), is_cliff_right(false),
  {
    kobuki::Parameters parameters;
    parameters.sigslots_namespace = "/kobuki";
    parameters.device_port = device;
    parameters.enable_acceleration_limiter = !disable_smoothing;

    kobuki.init(parameters);
    kobuki.enable();
    slot_stream_data.connect("/kobuki/stream_data");
    slot_bumper_event.connect("/kobuki/bumper_event");
    slot_button_event.connect("/kobuki/button_event");
    slot_cliff_event.connect("/kobuki/cliff_event");
  }

  ~KobukiManager() {
    kobuki.setBaseControl(0,0); // linear_velocity, angular_velocity in (m/s), (rad/s)
    kobuki.disable();
  }

  void processStreamData() {
    ecl::linear_algebra::Vector3d pose_update;
    ecl::linear_algebra::Vector3d pose_update_rates;
    kobuki.updateOdometry(pose_update, pose_update_rates);
    ecl::concatenate_poses(pose, pose_update);
    dx += pose_update[0];   // x
    dth += pose_update[2];  // heading
    pose[2] += pose_update[2];
    pose[0] += pose_update[0] * cos(pose[2]);
    pose[1] += pose_update[0] * sin(pose[2]);
    x_position = pose[0];
    z_position = pose[1];
    orientation = pose[2];
    while (orientation > 2*M_PI) {
      orientation -= 2*M_PI;
    }
    while (orientation < 0) {
      orientation += 2*M_PI;
    }
  }

  const ecl::linear_algebra::Vector3d& getPose() {
    return pose;
  }

  void processBumperEvent(const kobuki::BumperEvent &event) {
    if (event.state == kobuki::BumperEvent::Released ) {
      is_bumper_released_left = true;
      is_bumper_released_right = true;
    } else if (event.state == kobuki::BumperEvent::Pressed) {
      if (event.bumper == kobuki::BumperEvent::Left) {
        is_bumper_released_left = false;
      } else {
        is_bumper_released_right = false;
      }
    }
  }

  void processButtonEvent(const kobuki::ButtonEvent &event) {
    if (event.button == kobuki::ButtonEvent::Button0) {
      if (event.state == kobuki::ButtonEvent::Pressed) {
        is_button_pressed_b0 = true;
      } else if (event.state == kobuki::ButtonEvent::Released) {
        if (is_button_pressed_b0) {
          batteryLevel = 100.0;
          is_button_pressed_and_released_b0 = true;
        }
        is_button_pressed_b0 = false;
      }
    }
  }

  void processCliffEvent(const kobuki::CliffEvent &event) {
    if (event.state == kobuki::CliffEvent.Cliff) {
      switch (event.sensor) {
        case kobuki::CliffEvent.Left  : is_cliff_left   = true; break;
        case kobuki::CliffEvent.Center: is_cliff_center = true; break;
        case kobuki::CliffEvent.Right : is_cliff_right  = true; break;
      }
    } else if (event.state == kobuki::CliffEvent.Floor) {
      switch (event.sensor) {
        case kobuki::CliffEvent.Left  : is_cliff_left   = false; break;
        case kobuki::CliffEvent.Center: is_cliff_center = false; break;
        case kobuki::CliffEvent.Right : is_cliff_right  = false; break;
      }
    }
  }

  void moveForward(float speed) {
    if (speed < 0) {
      kobuki.setBaseControl(0.0, 0.0);
    } else if (speed > 1.0) {
      kobuki.setBaseControl(1.0, 0.0);
    } else {
      kobuki.setBaseControl(speed, 0.0);
    }
    batteryLevel -= batteryStep;
  }

  void moveBackward(float speed) {
    if (speed < 0) {
      kobuki.setBaseControl(0.0, 0.0);
    } else if (speed > 1.0) {
      kobuki.setBaseControl(-1.0, 0.0);
    } else {
      kobuki.setBaseControl(-speed, 0.0);
    }
    batteryLevel -= batteryStep;
  }

  void turnLeft(float speed) {
    if (speed < 0) {
      kobuki.setBaseControl(0.0, 0.0);
    } else if (speed > 1.0) {
      kobuki.setBaseControl(0.0, 1.0);
    } else {
      kobuki.setBaseControl(0.0, speed);
    }
    batteryLevel -= batteryStep;
  }

  void turnRight(float speed) {
    if (speed < 0) {
      kobuki.setBaseControl(0.0, 0.0);
    } else if (speed > 1.0) {
      kobuki.setBaseControl(0.0, -1.0);
    } else {
      kobuki.setBaseControl(0.0, -speed);
    }
    batteryLevel -= batteryStep;
  }

  void stop() {
    kobuki.setBaseControl(0.0, 0.0);
  }

  bool get_is_bumper_released_left() {
    return is_bumper_released_left;
  }

  bool get_is_bumper_released_right() {
    return is_bumper_released_right;
  }

  bool get_is_cliff_left() {
    return is_cliff_left;
  }

  bool get_is_cliff_center() {
    return is_cliff_center;
  }

  bool get_is_cliff_right() {
    return is_cliff_right;
  }
  
private:
  double dx, dth;
  const double length;
  ecl::linear_algebra::Vector3d pose;  // x, y, heading
  kobuki::Kobuki kobuki;
  ecl::Slot<> slot_stream_data;
  ecl::Slot<const kobuki::BumperEvent&> slot_bumper_event;
  ecl::Slot<const kobuki::ButtonEvent&> slot_button_event;
  ecl::Slot<const kobuki::CliffEvent&> slot_cliff_event;
  bool is_bumper_released_left;
  bool is_bumper_released_right;
  bool is_button_pressed_b0;
  bool is_button_pressed_and_released_b0;
  bool is_cliff_left;
  bool is_cliff_center;
  bool is_cliff_right;
};

/*****************************************************************************
** Signal Handler
*****************************************************************************/



bool shutdown_req = false;
void signalHandler(int /* signum */) {
  shutdown_req = true;
}

ecl::ValueArg<std::string> device_port("p", "port", "Path to device file of serial port to open", false, "/dev/kobuki", "string");
ecl::ValueArg<double> length("l", "length", "traverse square with sides of this size in length (m)", false, 0.25, "double");
ecl::SwitchArg disable_smoothing("d", "disable_smoothing", "Disable the acceleration limiter (smoothens velocity)", false);

KobukiManager kobuki_manager(device_port.getValue(), length.getValue(), disable_smoothing.getValue());

PRT_VALUE* P_Init_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  ecl::CmdLine cmd_line("Uses a simple control loop to move Kobuki around a dead-reckoned square with sides of length 1.0m", ' ', "0.2");
  cmd_line.add(device_port);
  cmd_line.add(length);
  cmd_line.add(disable_smoothing);
  signal(SIGINT, signalHandler);
  return PrtMkIntValue((PRT_UINT32)1);
}

PRT_VALUE* P_MoveForward_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  float speed = PrtPrimGetFloat(*argRefs[0]);
  kobuki_manager.moveForward(speed);
  return PrtMkIntValue((PRT_UINT32)1);
}

PRT_VALUE* P_MoveBackward_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  float speed = PrtPrimGetFloat(*argRefs[0]);
  kobuki_manager.moveBackward(speed);
  return PrtMkIntValue((PRT_UINT32)1);
}

PRT_VALUE* P_RotateLeft_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  float speed = PrtPrimGetFloat(*argRefs[0]);
  kobuki_manager.turnLeft(speed);
  return PrtMkIntValue((PRT_UINT32)1);
}

PRT_VALUE* P_RotateRight_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  float speed = PrtPrimGetFloat(*argRefs[0]);
  kobuki_manager.turnRight(speed);
  return PrtMkIntValue((PRT_UINT32)1);
}

PRT_VALUE* P_GetIsBumperReleasedLeft_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  bool returnValue = kobuki_manager.get_is_bumper_released_left();
  return PrtMkBoolValue((PRT_BOOLEAN)returnValue);
}

PRT_VALUE* P_GetIsBumperReleasedRight_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  bool returnValue = kobuki_manager.get_is_bumper_released_right();
  return PrtMkBoolValue((PRT_BOOLEAN)returnValue);
}

PRT_VALUE* P_GetIsButtonPressedAndReleasedB0_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  bool returnValue = kobuki_manager.get_is_button_pressed_and_released_b0();

PRT_VALUE* P_GetIsCliffLeft_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  bool returnValue = kobuki_manager.get_is_cliff_left();
  return PrtMkBoolValue((PRT_BOOLEAN)returnValue);
}

PRT_VALUE* P_GetIsCliffCenter_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  bool returnValue = kobuki_manager.get_is_cliff_center();
  return PrtMkBoolValue((PRT_BOOLEAN)returnValue);
}

PRT_VALUE* P_GetIsCliffRight_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  bool returnValue = kobuki_manager.get_is_cliff_right();
  return PrtMkBoolValue((PRT_BOOLEAN)returnValue);
}

PRT_VALUE* P_GetRobotPosition_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  PRT_VALUE* value = (PRT_VALUE*)PrtMalloc(sizeof(PRT_VALUE));
  PRT_TYPE* seqType = PrtMkSeqType(PrtMkPrimitiveType(PRT_KIND_FLOAT));
  value = PrtMkDefaultValue(seqType);
  PrtSeqInsert(value, PrtMkIntValue(0), PrtMkFloatValue(x_position));
  PrtSeqInsert(value, PrtMkIntValue(1), PrtMkFloatValue(z_position));
  return value;
}

PRT_VALUE* P_GetChargerPosition_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  PRT_VALUE* value = (PRT_VALUE*)PrtMalloc(sizeof(PRT_VALUE));
  PRT_TYPE* seqType = PrtMkSeqType(PrtMkPrimitiveType(PRT_KIND_FLOAT));
  value = PrtMkDefaultValue(seqType);
  PrtSeqInsert(value, PrtMkIntValue(0), PrtMkFloatValue(charger_x));
  PrtSeqInsert(value, PrtMkIntValue(1), PrtMkFloatValue(charger_z));
  return value;
}

PRT_VALUE* P_CheckIfReached_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  float x = PrtPrimGetFloat(*argRefs[0]);
  float z = PrtPrimGetFloat(*argRefs[1]);
  float speedMultiplier = PrtPrimGetFloat(*argRefs[2]);
  bool returnValue = (fabs(x - x_position) + fabs(z - z_position)) < speedMultiplier * 0.05;
  if (returnValue) {
    x_start = x_position;
    y_start = y_position;
    z_start = z_position;
  }
  return PrtMkBoolValue((PRT_BOOLEAN)returnValue);
}

PRT_VALUE* P_RotateTowardsLocation_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  float x = PrtPrimGetFloat(*argRefs[0]);
  float z = PrtPrimGetFloat(*argRefs[1]);
  float speed = PrtPrimGetFloat(*argRefs[2]);
  double angle2Goal = atan2((z_position - z), (x_position - x)) - M_PI;
  angle2Goal = angle2Goal < 0 ? angle2Goal + 2*M_PI : angle2Goal;
  double angleDifference = angle2Goal - orientation;
  while (angleDifference > M_PI) {
    angleDifference -= 2*M_PI;
  }
  while (angleDifference < -M_PI) {
    angleDifference += 2*M_PI;
  }
  bool direction = angleDifference > 0;
  //std::cout << angle2Goal << " " << orientation << " " << angleDifference << std::endl;
  if (fabs(angleDifference) > 0.2 * speed) {
    if (direction) {
      kobuki_manager.turnLeft(speed);
    } else {
      kobuki_manager.turnRight(speed);
    }
    return PrtMkBoolValue((PRT_BOOLEAN)true);//Rotated
  }
  return PrtMkBoolValue((PRT_BOOLEAN)false);//No need to rotate
}

PRT_VALUE* P_Stay_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  kobuki_manager.stop();
  return PrtMkIntValue((PRT_UINT32)1);
}

PRT_VALUE* P_GetBatteryLevel_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  return PrtMkFloatValue((PRT_FLOAT)batteryLevel);
}

PRT_VALUE* P_IsInTrajectory_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  float x_0 = PrtPrimGetFloat(*argRefs[0]);
  float z_0 = PrtPrimGetFloat(*argRefs[1]);
  float x_1 = PrtPrimGetFloat(*argRefs[2]);
  float z_1 = PrtPrimGetFloat(*argRefs[3]);
  float trajectoryDeviationThreshold = PrtPrimGetFloat(*argRefs[4]);
  double angle2Goal = atan2((z_position - z_1), (x_position - x_1)) - M_PI;
  angle2Goal = angle2Goal < 0 ? angle2Goal + 2*M_PI : angle2Goal;
  double theta = angle2Goal - orientation;
  while (theta > M_PI) {
    theta -= 2*M_PI;
  }
  while (theta < -M_PI) {
    theta += 2*M_PI;
  }
  theta = fabs(theta);
  if (theta > M_PI/2) {
    return PrtMkBoolValue((PRT_BOOLEAN)false);
  }
  float trajectoryDeviationDistance = sqrt(pow(x_position - x_0, 2) + pow(z_position - z_0, 2));
  float trajectoryDeviation = fabs(trajectoryDeviationDistance * sin(theta));
  if (trajectoryDeviation >= trajectoryDeviationThreshold) {
    return PrtMkBoolValue((PRT_BOOLEAN)false);
  }
  return PrtMkBoolValue((PRT_BOOLEAN)true);
}

PRT_VALUE* P_RandomController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs) {
  float forwardSpeed = PrtPrimGetFloat(*argRefs[0]);
  float rotationSpeed = PrtPrimGetFloat(*argRefs[1]);
  double random_selector = (double)rand() / (double)RAND_MAX;
  if (random_selector < 0.2) {
    kobuki_manager.turnLeft(rotationSpeed);
  } else {
    kobuki_manager.moveForward(forwardSpeed);
  }
  return PrtMkIntValue((PRT_UINT32)1);
}

