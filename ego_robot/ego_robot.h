#pragma once
#ifndef P_EGO_ROBOT_H_
#define P_EGO_ROBOT_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_eMotionRequest;
    extern PRT_EVENTDECL P_EVENT_eMotionRequestX;
    extern PRT_EVENTDECL P_EVENT_eMotion;
    extern PRT_EVENTDECL P_EVENT_eMotionX;
    extern PRT_EVENTDECL P_EVENT_eBatteryLow;
    extern PRT_EVENTDECL P_EVENT_eBatteryRecovered;
    extern PRT_EVENTDECL P_EVENT_eCurrentLocation;
    extern PRT_EVENTDECL P_EVENT_eCurrentGoal;
    extern PRT_INTERFACEDECL P_I_EgoRobot;
    extern PRT_INTERFACEDECL P_I_MotionPlanner;
    extern PRT_INTERFACEDECL P_I_MotionPrimitives;
    extern PRT_INTERFACEDECL P_I_Battery;
    extern PRT_MACHINEDECL P_MACHINE_EgoRobot;
    extern PRT_MACHINEDECL P_MACHINE_MotionPlanner;
    extern PRT_MACHINEDECL P_MACHINE_MotionPrimitives;
    extern PRT_MACHINEDECL P_MACHINE_Battery;
    extern PRT_TYPE* P_TYPEDEF_locationType;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_EGO_ROBOT_H_
