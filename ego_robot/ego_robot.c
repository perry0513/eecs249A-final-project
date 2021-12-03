#include "ego_robot.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE P_GEND_TYPE_f = { PRT_KIND_FLOAT, { NULL } };
static PRT_TYPE* P_TUP_T_1[] = { &P_GEND_TYPE_f, &P_GEND_TYPE_f };
static PRT_TUPTYPE P_TUP_1 = { 2U, P_TUP_T_1 };
static PRT_TYPE P_GEND_TYPE_T2ff = { PRT_KIND_TUPLE, { .tuple = &P_TUP_1 } };
static PRT_TYPE P_GEND_TYPE_b = { PRT_KIND_BOOL, { NULL } };
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_m, &P_GEND_TYPE_T2ff, &P_GEND_TYPE_T2ff, &P_GEND_TYPE_b };
static PRT_TUPTYPE P_TUP = { 4U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T4mT2ffT2ffb = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE* P_TUP_T_2[] = { &P_GEND_TYPE_m, &P_GEND_TYPE_T2ff, &P_GEND_TYPE_f, &P_GEND_TYPE_f };
static PRT_TUPTYPE P_TUP_2 = { 4U, P_TUP_T_2 };
static PRT_TYPE P_GEND_TYPE_T4mT2ffff = { PRT_KIND_TUPLE, { .tuple = &P_TUP_2 } };
static PRT_TYPE* P_TUP_T_3[] = { &P_GEND_TYPE_m, &P_GEND_TYPE_m, &P_GEND_TYPE_T2ff, &P_GEND_TYPE_f, &P_GEND_TYPE_f };
static PRT_TUPTYPE P_TUP_3 = { 5U, P_TUP_T_3 };
static PRT_TYPE P_GEND_TYPE_T5mmT2ffff = { PRT_KIND_TUPLE, { .tuple = &P_TUP_3 } };
static PRT_SEQTYPE P_SEQTYPE = { &P_GEND_TYPE_T2ff };
static PRT_TYPE P_GEND_TYPE_ST2ff = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_SEQTYPE P_SEQTYPE_1 = { &P_GEND_TYPE_f };
static PRT_TYPE P_GEND_TYPE_Sf = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_1 } };
static PRT_TYPE P_GEND_TYPE_r = { PRT_KIND_STRING, { NULL } };

// Function implementation prototypes:
PRT_VALUE* P_Init_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_CheckIfReached_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_RotateTowardsLocation_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_MoveForward_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_MoveBackward_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_RotateLeft_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_RotateRight_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Stay_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_IsInTrajectory_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_RandomController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetRobotPosition_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetChargerPosition_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetIsBumperReleasedLeft_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetIsBumperReleasedRight_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetIsCliffLeft_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetIsCliffRight_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetIsCliffCenter_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetBatteryLevel_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetIsButtonPressedAndReleasedB0_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_DM_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_DM;

PRT_VALUE* P_AC_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_AC;

PRT_VALUE* P_SC_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_SC;

PRT_VALUE* P_handler_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_handler;

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_3;

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_2;

PRT_VALUE* P_DM_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_DM_1;

PRT_VALUE* P_AC_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_AC_1;

PRT_VALUE* P_SC_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_SC_1;

PRT_VALUE* P_handler_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_handler_1;

PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_4;

PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_6;

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_5;

PRT_VALUE* P_DM_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_DM_2;

PRT_VALUE* P_LeftObstacleAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_LeftObstacleAvoidanceController;

PRT_VALUE* P_RightObstacleAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_RightObstacleAvoidanceController;

PRT_VALUE* P_LeftCliffAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_LeftCliffAvoidanceController;

PRT_VALUE* P_RightCliffAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_RightCliffAvoidanceController;

PRT_VALUE* P_CenterCliffAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_CenterCliffAvoidanceController;

PRT_VALUE* P_SafeMotionController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_SafeMotionController;

PRT_VALUE* P_AdvancedMotionController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_AdvancedMotionController;

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_7;

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_9;

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_11;

PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_12;

PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_10;

PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_8;

PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_14;

PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_16;

PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_15;

PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_13;

PRT_VALUE* P_DM_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_DM_3;

PRT_VALUE* P_Idle_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Idle;

PRT_VALUE* P_HandleLowBattery_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_HandleLowBattery;

PRT_VALUE* P_NotifyRecovery_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_NotifyRecovery;

PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_17;

PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_19;

PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_20;

PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_21;

PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_18;


PRT_EVENTDECL P_EVENT_eMotionRequest = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eMotionRequest",
    4294967295U,
    &P_GEND_TYPE_T4mT2ffT2ffb,
    0U
};

PRT_EVENTDECL P_EVENT_eMotionRequestX = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eMotionRequestX",
    4294967295U,
    &P_GEND_TYPE_T4mT2ffT2ffb,
    10U
};

PRT_EVENTDECL P_EVENT_eMotion = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eMotion",
    4294967295U,
    &P_GEND_TYPE_T2ff,
    0U
};

PRT_EVENTDECL P_EVENT_eMotionX = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eMotionX",
    4294967295U,
    &P_GEND_TYPE_T2ff,
    10U
};

PRT_EVENTDECL P_EVENT_eBatteryLow = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eBatteryLow",
    4294967295U,
    &P_GEND_TYPE_m,
    10U
};

PRT_EVENTDECL P_EVENT_eBatteryRecovered = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eBatteryRecovered",
    4294967295U,
    &P_GEND_TYPE_m,
    10U
};

PRT_EVENTDECL P_EVENT_eCurrentLocation = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eCurrentLocation",
    4294967295U,
    &P_GEND_TYPE_T2ff,
    10U
};

PRT_EVENTDECL P_EVENT_eCurrentGoal = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "eCurrentGoal",
    4294967295U,
    &P_GEND_TYPE_T2ff,
    10U
};

PRT_FUNDECL P_FUNCTION_Init =
{
    "Init",
    &P_Init_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_CheckIfReached =
{
    "CheckIfReached",
    &P_CheckIfReached_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_RotateTowardsLocation =
{
    "RotateTowardsLocation",
    &P_RotateTowardsLocation_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_MoveForward =
{
    "MoveForward",
    &P_MoveForward_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_MoveBackward =
{
    "MoveBackward",
    &P_MoveBackward_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_RotateLeft =
{
    "RotateLeft",
    &P_RotateLeft_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_RotateRight =
{
    "RotateRight",
    &P_RotateRight_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_Stay =
{
    "Stay",
    &P_Stay_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_IsInTrajectory =
{
    "IsInTrajectory",
    &P_IsInTrajectory_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_RandomController =
{
    "RandomController",
    &P_RandomController_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetRobotPosition =
{
    "GetRobotPosition",
    &P_GetRobotPosition_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetChargerPosition =
{
    "GetChargerPosition",
    &P_GetChargerPosition_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetIsBumperReleasedLeft =
{
    "GetIsBumperReleasedLeft",
    &P_GetIsBumperReleasedLeft_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetIsBumperReleasedRight =
{
    "GetIsBumperReleasedRight",
    &P_GetIsBumperReleasedRight_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetIsCliffLeft =
{
    "GetIsCliffLeft",
    &P_GetIsCliffLeft_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetIsCliffRight =
{
    "GetIsCliffRight",
    &P_GetIsCliffRight_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetIsCliffCenter =
{
    "GetIsCliffCenter",
    &P_GetIsCliffCenter_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetBatteryLevel =
{
    "GetBatteryLevel",
    &P_GetBatteryLevel_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_GetIsButtonPressedAndReleasedB0 =
{
    "GetIsButtonPressedAndReleasedB0",
    &P_GetIsButtonPressedAndReleasedB0_IMPL,
    NULL,
    PRT_FALSE
};


PRT_EVENTDECL* P_EgoRobot_RECV_INNER[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EgoRobot_RECV =
{
    9U,
    P_EgoRobot_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_EgoRobot =
{
    0U,
    "EgoRobot",
    &P_GEND_TYPE_n,
    &P_EVENTSET_EgoRobot_RECV
};

PRT_EVENTDECL* P_MotionPlanner_RECV_INNER[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MotionPlanner_RECV =
{
    9U,
    P_MotionPlanner_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_MotionPlanner =
{
    1U,
    "MotionPlanner",
    &P_GEND_TYPE_n,
    &P_EVENTSET_MotionPlanner_RECV
};

PRT_EVENTDECL* P_MotionPrimitives_RECV_INNER[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MotionPrimitives_RECV =
{
    9U,
    P_MotionPrimitives_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_MotionPrimitives =
{
    2U,
    "MotionPrimitives",
    &P_GEND_TYPE_T4mT2ffff,
    &P_EVENTSET_MotionPrimitives_RECV
};

PRT_EVENTDECL* P_Battery_RECV_INNER[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Battery_RECV =
{
    9U,
    P_Battery_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Battery =
{
    3U,
    "Battery",
    &P_GEND_TYPE_T5mmT2ffff,
    &P_EVENTSET_Battery_RECV
};

PRT_VARDECL P_EgoRobot_VARS[] = {
    { "motionPlanner", &P_GEND_TYPE_m },
    { "motionPrimitives", &P_GEND_TYPE_m },
    { "battery", &P_GEND_TYPE_m },
    { "currentLocation", &P_GEND_TYPE_T2ff },
    { "goals", &P_GEND_TYPE_ST2ff },
    { "currentGoalIndex", &P_GEND_TYPE_i },
    { "temp", &P_GEND_TYPE_Sf },
    { "chargerLocation", &P_GEND_TYPE_T2ff },
    { "", &P_GEND_TYPE_b },
    { "", &P_GEND_TYPE_r },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS =
{
    0U,
    P_Init_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS =
{
    0U,
    P_Init_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS =
{
    0U,
    P_Init_DOS_INNER,
    NULL
};

#define P_STATE_EgoRobot_Init \
{ \
    "EgoRobot.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS, \
    &P_EVENTSET_Init_TRANS, \
    &P_EVENTSET_Init_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon, \
    &_P_NO_OP, \
    &_P_NO_OP, \
    0, \
}

PRT_EVENTDECL* P_WaitB0Press_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitB0Press_DEFERS =
{
    0U,
    P_WaitB0Press_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitB0Press_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitB0Press_TRANS =
{
    0U,
    P_WaitB0Press_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_WaitB0Press_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_WaitB0Press_DOS =
{
    0U,
    P_WaitB0Press_DOS_INNER,
    NULL
};

#define P_STATE_EgoRobot_WaitB0Press \
{ \
    "EgoRobot.WaitB0Press", \
    0U, \
    0U, \
    &P_EVENTSET_WaitB0Press_DEFERS, \
    &P_EVENTSET_WaitB0Press_TRANS, \
    &P_EVENTSET_WaitB0Press_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_1, \
    &_P_NO_OP, \
    &_P_NO_OP, \
    0, \
}

PRT_EVENTDECL* P_Run_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Run_DEFERS =
{
    0U,
    P_Run_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Run_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Run_TRANS =
{
    0U,
    P_Run_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Run_DOS_INNER[] = { &P_EVENT_eCurrentLocation };
PRT_EVENTSETDECL P_EVENTSET_Run_DOS =
{
    1U,
    P_Run_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS[] =
{
    { 2, &P_EVENT_eCurrentLocation, &P_FUNCTION_Anon_3 }
};

#define P_STATE_EgoRobot_Run \
{ \
    "EgoRobot.Run", \
    0U, \
    1U, \
    &P_EVENTSET_Run_DEFERS, \
    &P_EVENTSET_Run_TRANS, \
    &P_EVENTSET_Run_DOS, \
    NULL, \
    P_DOS, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
    &_P_NO_OP, \
    0, \
}

PRT_STATEDECL P_EgoRobot_STATES[] = { P_STATE_EgoRobot_Init, P_STATE_EgoRobot_WaitB0Press, P_STATE_EgoRobot_Run };

PRT_VALUE* P_DM_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_r);
    PRT_VALUE* PTMP_tmp0 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtSeqGet(p_this->varValues[4], p_this->varValues[5]);
    
    PRT_VALUE** P_LVALUE_1 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_1);
    *P_LVALUE_1 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[3], PTMP_tmp0));
    
    if (PrtPrimGetBool(PTMP_tmp1))
    {
        PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp2);
        PrtFreeValue(*P_LVALUE_2);
        *P_LVALUE_2 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[5]) + PrtPrimGetInt((&P_LIT_INT32)));
        
        PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp3);
        PrtFreeValue(*P_LVALUE_3);
        *P_LVALUE_3 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[4]));
        
        PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp4);
        PrtFreeValue(*P_LVALUE_4);
        *P_LVALUE_4 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp2) < PrtPrimGetInt(PTMP_tmp3));
        
        if (PrtPrimGetBool(PTMP_tmp4))
        {
            PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp5);
            PrtFreeValue(*P_LVALUE_5);
            *P_LVALUE_5 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[5]) + PrtPrimGetInt((&P_LIT_INT32)));
            
            {
                PRT_VALUE** P_LVALUE_6 = &(p_this->varValues[5]);
                PrtFreeValue(*P_LVALUE_6);
                *P_LVALUE_6 = PTMP_tmp5;
                PTMP_tmp5 = NULL;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_7 = &(p_this->varValues[5]);
            PrtFreeValue(*P_LVALUE_7);
            *P_LVALUE_7 = PrtCloneValue((&P_LIT_INT32_1));
            
        }
        
        
        PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp6);
        PrtFreeValue(*P_LVALUE_8);
        *P_LVALUE_8 = PrtMkStringValue(PrtFormatString("SC", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp6);
        goto p_return;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
    ;
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(PTMP_tmp7);
    goto p_return;
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_DM =
{
    "DM",
    &P_DM_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_AC_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_1: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_AC =
{
    "AC",
    &P_AC_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_SC_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp1_1);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue((&P_EVENT_eMotionRequest.value));
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp2_1);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp3_1);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp4_1);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtSeqGet(p_this->varValues[4], p_this->varValues[5]);
    
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp5_1);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtCloneValue((&P_LIT_BOOLEAN));
    
    PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_16);
    *P_LVALUE_16 = (PrtMkTuple(&P_GEND_TYPE_T4mT2ffT2ffb, &(PTMP_tmp2_1), &(PTMP_tmp3_1), &(PTMP_tmp4_1), &(PTMP_tmp5_1)));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_1), PTMP_tmp1_1, 1, &(PTMP_tmp6_1));
    *(&(PTMP_tmp1_1)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_SC =
{
    "SC",
    &P_SC_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_handler_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_17 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_17);
    *P_LVALUE_17 = PrtCloneValue(*P_VAR_payload);
    
p_return_3: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_handler =
{
    "handler",
    &P_handler_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_2 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    PRT_VALUE* PTMP_tmp17 = NULL;
    PRT_VALUE* PTMP_tmp18 = NULL;
    PRT_VALUE* PTMP_tmp19 = NULL;
    PRT_VALUE* PTMP_tmp20 = NULL;
    PRT_VALUE* PTMP_tmp21 = NULL;
    PRT_VALUE* PTMP_tmp22 = NULL;
    PRT_VALUE* PTMP_tmp23 = NULL;
    PRT_VALUE* PTMP_tmp24 = NULL;
    PRT_VALUE* PTMP_tmp25 = NULL;
    PRT_VALUE* PTMP_tmp26 = NULL;
    PRT_VALUE* PTMP_tmp27 = NULL;
    PRT_VALUE* PTMP_tmp28 = NULL;
    PRT_VALUE* PTMP_tmp29 = NULL;
    PRT_VALUE* PTMP_tmp30 = NULL;
    PRT_VALUE* PTMP_tmp31 = NULL;
    PRT_VALUE* PTMP_tmp32 = NULL;
    PRT_VALUE* PTMP_tmp33 = NULL;
    PRT_VALUE* PTMP_tmp34 = NULL;
    PRT_VALUE* PTMP_tmp35 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_DOUBLE = { PRT_VALUE_KIND_FLOAT, { .ft = 0.1 } };
    PRT_VALUE P_LIT_DOUBLE_1 = { PRT_VALUE_KIND_FLOAT, { .ft = 300 } };
    PRT_VALUE P_LIT_DOUBLE_2 = { PRT_VALUE_KIND_FLOAT, { .ft = 50 } };
    PRT_VALUE P_LIT_DOUBLE_3 = { PRT_VALUE_KIND_FLOAT, { .ft = 100 } };
    PRT_VALUE P_LIT_DOUBLE_4 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.25 } };
    PRT_VALUE P_LIT_BOOLEAN_1 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PrtFreeValue(P_Init_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_18);
    *P_LVALUE_18 = ((_P_GEN_funval = P_GetRobotPosition_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_19 = &(p_this->varValues[6]);
        PrtFreeValue(*P_LVALUE_19);
        *P_LVALUE_19 = PTMP_tmp0_2;
        PTMP_tmp0_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp1_2);
    PrtFreeValue(*P_LVALUE_20);
    *P_LVALUE_20 = PrtSeqGet(p_this->varValues[6], (&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp2_2);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtSeqGet(p_this->varValues[6], (&P_LIT_INT32_3));
    
    PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp3_2);
    PrtFreeValue(*P_LVALUE_22);
    *P_LVALUE_22 = (PrtMkTuple(&P_GEND_TYPE_T2ff, &(PTMP_tmp1_2), &(PTMP_tmp2_2)));
    
    {
        PRT_VALUE** P_LVALUE_23 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_23);
        *P_LVALUE_23 = PTMP_tmp3_2;
        PTMP_tmp3_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp4_2);
    PrtFreeValue(*P_LVALUE_24);
    *P_LVALUE_24 = ((_P_GEN_funval = P_GetChargerPosition_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_25 = &(p_this->varValues[6]);
        PrtFreeValue(*P_LVALUE_25);
        *P_LVALUE_25 = PTMP_tmp4_2;
        PTMP_tmp4_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_26 = &(PTMP_tmp5_2);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtSeqGet(p_this->varValues[6], (&P_LIT_INT32_2));
    
    PRT_VALUE** P_LVALUE_27 = &(PTMP_tmp6_2);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = PrtSeqGet(p_this->varValues[6], (&P_LIT_INT32_3));
    
    PRT_VALUE** P_LVALUE_28 = &(PTMP_tmp7_1);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = (PrtMkTuple(&P_GEND_TYPE_T2ff, &(PTMP_tmp5_2), &(PTMP_tmp6_2)));
    
    {
        PRT_VALUE** P_LVALUE_29 = &(p_this->varValues[7]);
        PrtFreeValue(*P_LVALUE_29);
        *P_LVALUE_29 = PTMP_tmp7_1;
        PTMP_tmp7_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_30 = &(PTMP_tmp8);
    PrtFreeValue(*P_LVALUE_30);
    *P_LVALUE_30 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp9);
    PrtFreeValue(*P_LVALUE_31);
    *P_LVALUE_31 = PrtCloneValue(p_this->varValues[3]);
    
    PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_32);
    *P_LVALUE_32 = PrtCloneValue((&P_LIT_DOUBLE));
    
    PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp11);
    PrtFreeValue(*P_LVALUE_33);
    *P_LVALUE_33 = PrtCloneValue((&P_LIT_DOUBLE_1));
    
    PRT_VALUE** P_LVALUE_34 = &(PTMP_tmp12);
    PrtFreeValue(*P_LVALUE_34);
    *P_LVALUE_34 = PrtCloneValue(PrtMkInterface(context, 2, 4, &(PTMP_tmp8), &(PTMP_tmp9), &(PTMP_tmp10), &(PTMP_tmp11))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_35 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_35);
        *P_LVALUE_35 = PTMP_tmp12;
        PTMP_tmp12 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp13);
    PrtFreeValue(*P_LVALUE_36);
    *P_LVALUE_36 = PrtCloneValue(PrtMkInterface(context, 1, 0)->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_37 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_37);
        *P_LVALUE_37 = PTMP_tmp13;
        PTMP_tmp13 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp14);
    PrtFreeValue(*P_LVALUE_38);
    *P_LVALUE_38 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_39 = &(PTMP_tmp15);
    PrtFreeValue(*P_LVALUE_39);
    *P_LVALUE_39 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp16);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = PrtCloneValue(p_this->varValues[7]);
    
    PRT_VALUE** P_LVALUE_41 = &(PTMP_tmp17);
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = PrtCloneValue((&P_LIT_DOUBLE_2));
    
    PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp18);
    PrtFreeValue(*P_LVALUE_42);
    *P_LVALUE_42 = PrtCloneValue((&P_LIT_DOUBLE_3));
    
    PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp19);
    PrtFreeValue(*P_LVALUE_43);
    *P_LVALUE_43 = PrtCloneValue(PrtMkInterface(context, 3, 5, &(PTMP_tmp14), &(PTMP_tmp15), &(PTMP_tmp16), &(PTMP_tmp17), &(PTMP_tmp18))->id);
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    {
        PRT_VALUE** P_LVALUE_44 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_44);
        *P_LVALUE_44 = PTMP_tmp19;
        PTMP_tmp19 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp20);
    PrtFreeValue(*P_LVALUE_45);
    *P_LVALUE_45 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[4]));
    
    PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp21);
    PrtFreeValue(*P_LVALUE_46);
    *P_LVALUE_46 = PrtCloneValue((&P_LIT_DOUBLE_4));
    
    PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp22);
    PrtFreeValue(*P_LVALUE_47);
    *P_LVALUE_47 = PrtCloneValue((&P_LIT_DOUBLE_4));
    
    PRT_VALUE** P_LVALUE_48 = &(PTMP_tmp23);
    PrtFreeValue(*P_LVALUE_48);
    *P_LVALUE_48 = (PrtMkTuple(&P_GEND_TYPE_T2ff, &(PTMP_tmp21), &(PTMP_tmp22)));
    
    PrtSeqInsertEx(p_this->varValues[4], PTMP_tmp20, PTMP_tmp23, PRT_FALSE);
    *(&(PTMP_tmp23)) = NULL;
    
    PRT_VALUE** P_LVALUE_49 = &(PTMP_tmp24);
    PrtFreeValue(*P_LVALUE_49);
    *P_LVALUE_49 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[4]));
    
    PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp25);
    PrtFreeValue(*P_LVALUE_50);
    *P_LVALUE_50 = PrtMkFloatValue(-PrtPrimGetFloat((&P_LIT_DOUBLE_4)));
    
    PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp26);
    PrtFreeValue(*P_LVALUE_51);
    *P_LVALUE_51 = PrtCloneValue((&P_LIT_DOUBLE_4));
    
    PRT_VALUE** P_LVALUE_52 = &(PTMP_tmp27);
    PrtFreeValue(*P_LVALUE_52);
    *P_LVALUE_52 = (PrtMkTuple(&P_GEND_TYPE_T2ff, &(PTMP_tmp25), &(PTMP_tmp26)));
    
    PrtSeqInsertEx(p_this->varValues[4], PTMP_tmp24, PTMP_tmp27, PRT_FALSE);
    *(&(PTMP_tmp27)) = NULL;
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp28);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[4]));
    
    PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp29);
    PrtFreeValue(*P_LVALUE_54);
    *P_LVALUE_54 = PrtMkFloatValue(-PrtPrimGetFloat((&P_LIT_DOUBLE_4)));
    
    PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp30);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtMkFloatValue(-PrtPrimGetFloat((&P_LIT_DOUBLE_4)));
    
    PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp31);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = (PrtMkTuple(&P_GEND_TYPE_T2ff, &(PTMP_tmp29), &(PTMP_tmp30)));
    
    PrtSeqInsertEx(p_this->varValues[4], PTMP_tmp28, PTMP_tmp31, PRT_FALSE);
    *(&(PTMP_tmp31)) = NULL;
    
    PRT_VALUE** P_LVALUE_57 = &(PTMP_tmp32);
    PrtFreeValue(*P_LVALUE_57);
    *P_LVALUE_57 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[4]));
    
    PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp33);
    PrtFreeValue(*P_LVALUE_58);
    *P_LVALUE_58 = PrtCloneValue((&P_LIT_DOUBLE_4));
    
    PRT_VALUE** P_LVALUE_59 = &(PTMP_tmp34);
    PrtFreeValue(*P_LVALUE_59);
    *P_LVALUE_59 = PrtMkFloatValue(-PrtPrimGetFloat((&P_LIT_DOUBLE_4)));
    
    PRT_VALUE** P_LVALUE_60 = &(PTMP_tmp35);
    PrtFreeValue(*P_LVALUE_60);
    *P_LVALUE_60 = (PrtMkTuple(&P_GEND_TYPE_T2ff, &(PTMP_tmp33), &(PTMP_tmp34)));
    
    PrtSeqInsertEx(p_this->varValues[4], PTMP_tmp32, PTMP_tmp35, PRT_FALSE);
    *(&(PTMP_tmp35)) = NULL;
    
    PRT_VALUE** P_LVALUE_61 = &(p_this->varValues[5]);
    PrtFreeValue(*P_LVALUE_61);
    *P_LVALUE_61 = PrtCloneValue((&P_LIT_INT32_2));
    
    PrtGoto(p_this, 1U, 0);
    
    PRT_VALUE** P_LVALUE_62 = &(p_this->varValues[8]);
    PrtFreeValue(*P_LVALUE_62);
    *P_LVALUE_62 = PrtCloneValue((&P_LIT_BOOLEAN_1));
    
    PRT_VALUE** P_LVALUE_63 = &(p_this->varValues[11]);
    PrtFreeValue(*P_LVALUE_63);
    *P_LVALUE_63 = PrtCloneValue((&P_LIT_INT32_2));
    
p_return_4: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_2); PTMP_tmp6_2 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    PrtFreeValue(PTMP_tmp17); PTMP_tmp17 = NULL;
    PrtFreeValue(PTMP_tmp18); PTMP_tmp18 = NULL;
    PrtFreeValue(PTMP_tmp19); PTMP_tmp19 = NULL;
    PrtFreeValue(PTMP_tmp20); PTMP_tmp20 = NULL;
    PrtFreeValue(PTMP_tmp21); PTMP_tmp21 = NULL;
    PrtFreeValue(PTMP_tmp22); PTMP_tmp22 = NULL;
    PrtFreeValue(PTMP_tmp23); PTMP_tmp23 = NULL;
    PrtFreeValue(PTMP_tmp24); PTMP_tmp24 = NULL;
    PrtFreeValue(PTMP_tmp25); PTMP_tmp25 = NULL;
    PrtFreeValue(PTMP_tmp26); PTMP_tmp26 = NULL;
    PrtFreeValue(PTMP_tmp27); PTMP_tmp27 = NULL;
    PrtFreeValue(PTMP_tmp28); PTMP_tmp28 = NULL;
    PrtFreeValue(PTMP_tmp29); PTMP_tmp29 = NULL;
    PrtFreeValue(PTMP_tmp30); PTMP_tmp30 = NULL;
    PrtFreeValue(PTMP_tmp31); PTMP_tmp31 = NULL;
    PrtFreeValue(PTMP_tmp32); PTMP_tmp32 = NULL;
    PrtFreeValue(PTMP_tmp33); PTMP_tmp33 = NULL;
    PrtFreeValue(PTMP_tmp34); PTMP_tmp34 = NULL;
    PrtFreeValue(PTMP_tmp35); PTMP_tmp35 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_isButtonB0PressedAndReleased = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_3 = NULL;
    PRT_VALUE* PTMP_tmp5_3 = NULL;
    PRT_VALUE* PTMP_tmp6_3 = NULL;
    PRT_VALUE* PTMP_tmp7_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_2 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_64 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_64);
    *P_LVALUE_64 = ((_P_GEN_funval = P_GetIsButtonPressedAndReleasedB0_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_5;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_5;
    }
    
    {
        PRT_VALUE** P_LVALUE_65 = &(P_VAR_isButtonB0PressedAndReleased);
        PrtFreeValue(*P_LVALUE_65);
        *P_LVALUE_65 = PTMP_tmp0_3;
        PTMP_tmp0_3 = NULL;
    }
    
    if (PrtPrimGetBool(P_VAR_isButtonB0PressedAndReleased))
    {
        PRT_VALUE** P_LVALUE_66 = &(PTMP_tmp1_3);
        PrtFreeValue(*P_LVALUE_66);
        *P_LVALUE_66 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_67 = &(PTMP_tmp2_3);
        PrtFreeValue(*P_LVALUE_67);
        *P_LVALUE_67 = PrtCloneValue((&P_EVENT_eMotionRequest.value));
        
        PRT_VALUE** P_LVALUE_68 = &(PTMP_tmp3_3);
        PrtFreeValue(*P_LVALUE_68);
        *P_LVALUE_68 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_69 = &(PTMP_tmp4_3);
        PrtFreeValue(*P_LVALUE_69);
        *P_LVALUE_69 = PrtCloneValue(p_this->varValues[3]);
        
        PRT_VALUE** P_LVALUE_70 = &(PTMP_tmp5_3);
        PrtFreeValue(*P_LVALUE_70);
        *P_LVALUE_70 = PrtSeqGet(p_this->varValues[4], p_this->varValues[5]);
        
        PRT_VALUE** P_LVALUE_71 = &(PTMP_tmp6_3);
        PrtFreeValue(*P_LVALUE_71);
        *P_LVALUE_71 = PrtCloneValue((&P_LIT_BOOLEAN_2));
        
        PRT_VALUE** P_LVALUE_72 = &(PTMP_tmp7_2);
        PrtFreeValue(*P_LVALUE_72);
        *P_LVALUE_72 = (PrtMkTuple(&P_GEND_TYPE_T4mT2ffT2ffb, &(PTMP_tmp3_3), &(PTMP_tmp4_3), &(PTMP_tmp5_3), &(PTMP_tmp6_3)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_3), PTMP_tmp2_3, 1, &(PTMP_tmp7_2));
        *(&(PTMP_tmp2_3)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_5;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_5;
        }
        
        PrtGoto(p_this, 2U, 0);
        
    }
    
    else
    {
        PrtGoto(p_this, 1U, 0);
        
    }
    
    
    PRT_VALUE** P_LVALUE_73 = &(p_this->varValues[8]);
    PrtFreeValue(*P_LVALUE_73);
    *P_LVALUE_73 = PrtCloneValue((&P_LIT_BOOLEAN_2));
    
    PRT_VALUE** P_LVALUE_74 = &(p_this->varValues[11]);
    PrtFreeValue(*P_LVALUE_74);
    *P_LVALUE_74 = PrtCloneValue((&P_LIT_INT32_4));
    
p_return_5: ;
    PrtFreeValue(P_VAR_isButtonB0PressedAndReleased); P_VAR_isButtonB0PressedAndReleased = NULL;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_3); PTMP_tmp4_3 = NULL;
    PrtFreeValue(PTMP_tmp5_3); PTMP_tmp5_3 = NULL;
    PrtFreeValue(PTMP_tmp6_3); PTMP_tmp6_3 = NULL;
    PrtFreeValue(PTMP_tmp7_2); PTMP_tmp7_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    PRT_VALUE* PTMP_tmp3_4 = NULL;
    PRT_VALUE* PTMP_tmp4_4 = NULL;
    PRT_VALUE* PTMP_tmp5_4 = NULL;
    PRT_VALUE* PTMP_tmp6_4 = NULL;
    PRT_VALUE* PTMP_tmp7_3 = NULL;
    PRT_VALUE* PTMP_tmp8_1 = NULL;
    PRT_VALUE* PTMP_tmp9_1 = NULL;
    PRT_VALUE* PTMP_tmp10_1 = NULL;
    PRT_VALUE* PTMP_tmp11_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_3 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_75 = &(PTMP_tmp0_4);
    PrtFreeValue(*P_LVALUE_75);
    *P_LVALUE_75 = PrtCloneValue(*P_VAR_payload_1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_4);
    PrtFreeValue(P_handler_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_4);
    PTMP_tmp0_4 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_6;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_6;
    }
    
    PRT_VALUE** P_LVALUE_76 = &(PTMP_tmp1_4);
    PrtFreeValue(*P_LVALUE_76);
    *P_LVALUE_76 = PrtMkBoolValue(!PrtPrimGetBool(p_this->varValues[8]));
    
    if (PrtPrimGetBool(PTMP_tmp1_4))
    {
        PRT_VALUE** P_LVALUE_77 = &(p_this->varValues[8]);
        PrtFreeValue(*P_LVALUE_77);
        *P_LVALUE_77 = PrtCloneValue((&P_LIT_BOOLEAN_3));
        
        PRT_VALUE** P_LVALUE_78 = &(PTMP_tmp2_4);
        PrtFreeValue(*P_LVALUE_78);
        *P_LVALUE_78 = ((_P_GEN_funval = P_DM_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_6;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_6;
        }
        
        {
            PRT_VALUE** P_LVALUE_79 = &(p_this->varValues[9]);
            PrtFreeValue(*P_LVALUE_79);
            *P_LVALUE_79 = PTMP_tmp2_4;
            PTMP_tmp2_4 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_80 = &(PTMP_tmp3_4);
        PrtFreeValue(*P_LVALUE_80);
        *P_LVALUE_80 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
        ;
        
        PRT_VALUE** P_LVALUE_81 = &(PTMP_tmp4_4);
        PrtFreeValue(*P_LVALUE_81);
        *P_LVALUE_81 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp3_4));
        
        if (PrtPrimGetBool(PTMP_tmp4_4))
        {
            PrtFreeValue(P_AC_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_6;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_6;
            }
            
            PRT_VALUE** P_LVALUE_82 = &(p_this->varValues[10]);
            PrtFreeValue(*P_LVALUE_82);
            *P_LVALUE_82 = PrtCloneValue((&P_LIT_INT32_5));
            
        }
        
        else
        {
            PrtFreeValue(P_SC_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_6;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_6;
            }
            
            PRT_VALUE** P_LVALUE_83 = &(p_this->varValues[10]);
            PrtFreeValue(*P_LVALUE_83);
            *P_LVALUE_83 = PrtCloneValue((&P_LIT_INT32_5));
            
        }
        
        
        PRT_VALUE** P_LVALUE_84 = &(p_this->varValues[11]);
        PrtFreeValue(*P_LVALUE_84);
        *P_LVALUE_84 = PrtCloneValue((&P_LIT_INT32_5));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_85 = &(PTMP_tmp5_4);
        PrtFreeValue(*P_LVALUE_85);
        *P_LVALUE_85 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[10], p_this->varValues[11]));
        
        if (PrtPrimGetBool(PTMP_tmp5_4))
        {
            PRT_VALUE** P_LVALUE_86 = &(PTMP_tmp6_4);
            PrtFreeValue(*P_LVALUE_86);
            *P_LVALUE_86 = ((_P_GEN_funval = P_DM_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_6;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_6;
            }
            
            {
                PRT_VALUE** P_LVALUE_87 = &(p_this->varValues[9]);
                PrtFreeValue(*P_LVALUE_87);
                *P_LVALUE_87 = PTMP_tmp6_4;
                PTMP_tmp6_4 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_88 = &(PTMP_tmp7_3);
            PrtFreeValue(*P_LVALUE_88);
            *P_LVALUE_88 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_89 = &(PTMP_tmp8_1);
            PrtFreeValue(*P_LVALUE_89);
            *P_LVALUE_89 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp7_3));
            
            if (PrtPrimGetBool(PTMP_tmp8_1))
            {
                PrtFreeValue(P_AC_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_6;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_6;
                }
                
                PRT_VALUE** P_LVALUE_90 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_90);
                *P_LVALUE_90 = PrtCloneValue((&P_LIT_INT32_5));
                
            }
            
            else
            {
                PrtFreeValue(P_SC_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_6;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_6;
                }
                
                PRT_VALUE** P_LVALUE_91 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_91);
                *P_LVALUE_91 = PrtCloneValue((&P_LIT_INT32_5));
                
            }
            
            
            PRT_VALUE** P_LVALUE_92 = &(p_this->varValues[11]);
            PrtFreeValue(*P_LVALUE_92);
            *P_LVALUE_92 = PrtCloneValue((&P_LIT_INT32_5));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_93 = &(PTMP_tmp9_1);
            PrtFreeValue(*P_LVALUE_93);
            *P_LVALUE_93 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_94 = &(PTMP_tmp10_1);
            PrtFreeValue(*P_LVALUE_94);
            *P_LVALUE_94 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp9_1));
            
            if (PrtPrimGetBool(PTMP_tmp10_1))
            {
                PrtFreeValue(P_AC_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_6;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_6;
                }
                
                PRT_VALUE** P_LVALUE_95 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_95);
                *P_LVALUE_95 = PrtCloneValue((&P_LIT_INT32_5));
                
            }
            
            else
            {
                PrtFreeValue(P_SC_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_6;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_6;
                }
                
                PRT_VALUE** P_LVALUE_96 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_96);
                *P_LVALUE_96 = PrtCloneValue((&P_LIT_INT32_5));
                
            }
            
            
            PRT_VALUE** P_LVALUE_97 = &(PTMP_tmp11_1);
            PrtFreeValue(*P_LVALUE_97);
            *P_LVALUE_97 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[11]) + PrtPrimGetInt((&P_LIT_INT32_5)));
            
            {
                PRT_VALUE** P_LVALUE_98 = &(p_this->varValues[11]);
                PrtFreeValue(*P_LVALUE_98);
                *P_LVALUE_98 = PTMP_tmp11_1;
                PTMP_tmp11_1 = NULL;
            }
            
        }
        
        
    }
    
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    PrtFreeValue(PTMP_tmp3_4); PTMP_tmp3_4 = NULL;
    PrtFreeValue(PTMP_tmp4_4); PTMP_tmp4_4 = NULL;
    PrtFreeValue(PTMP_tmp5_4); PTMP_tmp5_4 = NULL;
    PrtFreeValue(PTMP_tmp6_4); PTMP_tmp6_4 = NULL;
    PrtFreeValue(PTMP_tmp7_3); PTMP_tmp7_3 = NULL;
    PrtFreeValue(PTMP_tmp8_1); PTMP_tmp8_1 = NULL;
    PrtFreeValue(PTMP_tmp9_1); PTMP_tmp9_1 = NULL;
    PrtFreeValue(PTMP_tmp10_1); PTMP_tmp10_1 = NULL;
    PrtFreeValue(PTMP_tmp11_1); PTMP_tmp11_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_2,
    &P_GEND_TYPE_T2ff,
    PRT_TRUE
};


PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_4 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_99 = &(p_this->varValues[8]);
    PrtFreeValue(*P_LVALUE_99);
    *P_LVALUE_99 = PrtCloneValue((&P_LIT_BOOLEAN_4));
    
    PRT_VALUE** P_LVALUE_100 = &(p_this->varValues[11]);
    PrtFreeValue(*P_LVALUE_100);
    *P_LVALUE_100 = PrtCloneValue((&P_LIT_INT32_6));
    
p_return_7: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_3,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL* P_EgoRobot_METHODS[] = { &P_FUNCTION_DM, &P_FUNCTION_AC, &P_FUNCTION_SC, &P_FUNCTION_handler, &P_FUNCTION_Anon, &P_FUNCTION_Anon_1, &P_FUNCTION_Anon_3, &P_FUNCTION_Anon_2 };

PRT_EVENTDECL* P_EgoRobot_RECV_INNER_1[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EgoRobot_RECV_1 =
{
    9U,
    P_EgoRobot_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_EgoRobot_SEND_INNER[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_EgoRobot_SEND =
{
    9U,
    P_EgoRobot_SEND_INNER,
    NULL
};

PRT_UINT32 P_EgoRobot_CREATES_ARR[] = { 3, 1, 2 };
PRT_INTERFACESETDECL P_EgoRobot_CREATES = { 3, P_EgoRobot_CREATES_ARR };
PRT_MACHINEDECL P_MACHINE_EgoRobot = 
{
    0U,
    "EgoRobot",
    &P_EVENTSET_EgoRobot_RECV_1,
    &P_EVENTSET_EgoRobot_SEND,
    &P_EgoRobot_CREATES,
    12U,
    3U,
    8U,
    4294967295U,
    0U,
    0U,
    P_EgoRobot_VARS,
    P_EgoRobot_STATES,
    P_EgoRobot_METHODS
};

PRT_VARDECL P_MotionPlanner_VARS[] = {
    { "destination", &P_GEND_TYPE_m },
    { "step", &P_GEND_TYPE_f },
    { "destinationOfRequest", &P_GEND_TYPE_m },
    { "currentLocation", &P_GEND_TYPE_T2ff },
    { "goalLocation", &P_GEND_TYPE_T2ff },
    { "isHighPriorityMotionRequest", &P_GEND_TYPE_b },
    { "", &P_GEND_TYPE_b },
    { "", &P_GEND_TYPE_r },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_1 =
{
    0U,
    P_Init_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_1 =
{
    0U,
    P_Init_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_1 =
{
    0U,
    P_Init_DOS_INNER_1,
    NULL
};

#define P_STATE_MotionPlanner_Init \
{ \
    "MotionPlanner.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_1, \
    &P_EVENTSET_Init_TRANS_1, \
    &P_EVENTSET_Init_DOS_1, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
    &_P_NO_OP, \
    0, \
}

PRT_EVENTDECL* P_Run_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Run_DEFERS_1 =
{
    0U,
    P_Run_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Run_TRANS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Run_TRANS_1 =
{
    0U,
    P_Run_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Run_DOS_INNER_1[] = { &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX };
PRT_EVENTSETDECL P_EVENTSET_Run_DOS_1 =
{
    2U,
    P_Run_DOS_INNER_1,
    NULL
};

PRT_DODECL P_DOS_1[] =
{
    { 1, &P_EVENT_eMotionRequest, &P_FUNCTION_Anon_6 },
    { 1, &P_EVENT_eMotionRequestX, &P_FUNCTION_Anon_6 }
};

#define P_STATE_MotionPlanner_Run \
{ \
    "MotionPlanner.Run", \
    0U, \
    2U, \
    &P_EVENTSET_Run_DEFERS_1, \
    &P_EVENTSET_Run_TRANS_1, \
    &P_EVENTSET_Run_DOS_1, \
    NULL, \
    P_DOS_1, \
    &P_FUNCTION_Anon_5, \
    &_P_NO_OP, \
    &_P_NO_OP, \
    0, \
}

PRT_STATEDECL P_MotionPlanner_STATES[] = { P_STATE_MotionPlanner_Init, P_STATE_MotionPlanner_Run };

PRT_VALUE* P_DM_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_r);
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_5 = NULL;
    PRT_VALUE* PTMP_tmp2_5 = NULL;
    PRT_VALUE* PTMP_tmp3_5 = NULL;
    PRT_VALUE* PTMP_tmp4_5 = NULL;
    PRT_VALUE* PTMP_tmp5_5 = NULL;
    PRT_VALUE* PTMP_tmp6_5 = NULL;
    PRT_VALUE* PTMP_tmp7_4 = NULL;
    PRT_VALUE* PTMP_tmp8_2 = NULL;
    PRT_VALUE* PTMP_tmp9_2 = NULL;
    PRT_VALUE* PTMP_tmp10_2 = NULL;
    PRT_VALUE* PTMP_tmp11_2 = NULL;
    PRT_VALUE* PTMP_tmp12_1 = NULL;
    PRT_VALUE* PTMP_tmp13_1 = NULL;
    PRT_VALUE* PTMP_tmp14_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_101 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_101);
    *P_LVALUE_101 = PrtTupleGet(p_this->varValues[3], 0);
    
    PRT_VALUE** P_LVALUE_102 = &(PTMP_tmp1_5);
    PrtFreeValue(*P_LVALUE_102);
    *P_LVALUE_102 = PrtMkFloatValue(-PrtPrimGetFloat(p_this->varValues[1]));
    
    PRT_VALUE** P_LVALUE_103 = &(PTMP_tmp2_5);
    PrtFreeValue(*P_LVALUE_103);
    *P_LVALUE_103 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp0_5) >= PrtPrimGetFloat(PTMP_tmp1_5));
    
    PRT_VALUE** P_LVALUE_104 = &(PTMP_tmp5_5);
    PrtFreeValue(*P_LVALUE_104);
    *P_LVALUE_104 = PrtCloneValue(PTMP_tmp2_5);
    
    if (PrtPrimGetBool(PTMP_tmp5_5))
    {
        PRT_VALUE** P_LVALUE_105 = &(PTMP_tmp3_5);
        PrtFreeValue(*P_LVALUE_105);
        *P_LVALUE_105 = PrtTupleGet(p_this->varValues[3], 0);
        
        PRT_VALUE** P_LVALUE_106 = &(PTMP_tmp4_5);
        PrtFreeValue(*P_LVALUE_106);
        *P_LVALUE_106 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp3_5) <= PrtPrimGetFloat(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_107 = &(PTMP_tmp5_5);
        PrtFreeValue(*P_LVALUE_107);
        *P_LVALUE_107 = PrtCloneValue(PTMP_tmp4_5);
        
    }
    
    
    PRT_VALUE** P_LVALUE_108 = &(PTMP_tmp9_2);
    PrtFreeValue(*P_LVALUE_108);
    *P_LVALUE_108 = PrtCloneValue(PTMP_tmp5_5);
    
    if (PrtPrimGetBool(PTMP_tmp9_2))
    {
        PRT_VALUE** P_LVALUE_109 = &(PTMP_tmp6_5);
        PrtFreeValue(*P_LVALUE_109);
        *P_LVALUE_109 = PrtTupleGet(p_this->varValues[3], 1);
        
        PRT_VALUE** P_LVALUE_110 = &(PTMP_tmp7_4);
        PrtFreeValue(*P_LVALUE_110);
        *P_LVALUE_110 = PrtMkFloatValue(-PrtPrimGetFloat(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_111 = &(PTMP_tmp8_2);
        PrtFreeValue(*P_LVALUE_111);
        *P_LVALUE_111 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp6_5) >= PrtPrimGetFloat(PTMP_tmp7_4));
        
        PRT_VALUE** P_LVALUE_112 = &(PTMP_tmp9_2);
        PrtFreeValue(*P_LVALUE_112);
        *P_LVALUE_112 = PrtCloneValue(PTMP_tmp8_2);
        
    }
    
    
    PRT_VALUE** P_LVALUE_113 = &(PTMP_tmp12_1);
    PrtFreeValue(*P_LVALUE_113);
    *P_LVALUE_113 = PrtCloneValue(PTMP_tmp9_2);
    
    if (PrtPrimGetBool(PTMP_tmp12_1))
    {
        PRT_VALUE** P_LVALUE_114 = &(PTMP_tmp10_2);
        PrtFreeValue(*P_LVALUE_114);
        *P_LVALUE_114 = PrtTupleGet(p_this->varValues[3], 1);
        
        PRT_VALUE** P_LVALUE_115 = &(PTMP_tmp11_2);
        PrtFreeValue(*P_LVALUE_115);
        *P_LVALUE_115 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp10_2) <= PrtPrimGetFloat(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_116 = &(PTMP_tmp12_1);
        PrtFreeValue(*P_LVALUE_116);
        *P_LVALUE_116 = PrtCloneValue(PTMP_tmp11_2);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp12_1))
    {
        PRT_VALUE** P_LVALUE_117 = &(PTMP_tmp13_1);
        PrtFreeValue(*P_LVALUE_117);
        *P_LVALUE_117 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp13_1);
        goto p_return_8;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_118 = &(PTMP_tmp14_1);
    PrtFreeValue(*P_LVALUE_118);
    *P_LVALUE_118 = PrtMkStringValue(PrtFormatString("SC", 0, 0));
    ;
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(PTMP_tmp14_1);
    goto p_return_8;
    
p_return_8: ;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_5); PTMP_tmp1_5 = NULL;
    PrtFreeValue(PTMP_tmp2_5); PTMP_tmp2_5 = NULL;
    PrtFreeValue(PTMP_tmp3_5); PTMP_tmp3_5 = NULL;
    PrtFreeValue(PTMP_tmp4_5); PTMP_tmp4_5 = NULL;
    PrtFreeValue(PTMP_tmp5_5); PTMP_tmp5_5 = NULL;
    PrtFreeValue(PTMP_tmp6_5); PTMP_tmp6_5 = NULL;
    PrtFreeValue(PTMP_tmp7_4); PTMP_tmp7_4 = NULL;
    PrtFreeValue(PTMP_tmp8_2); PTMP_tmp8_2 = NULL;
    PrtFreeValue(PTMP_tmp9_2); PTMP_tmp9_2 = NULL;
    PrtFreeValue(PTMP_tmp10_2); PTMP_tmp10_2 = NULL;
    PrtFreeValue(PTMP_tmp11_2); PTMP_tmp11_2 = NULL;
    PrtFreeValue(PTMP_tmp12_1); PTMP_tmp12_1 = NULL;
    PrtFreeValue(PTMP_tmp13_1); PTMP_tmp13_1 = NULL;
    PrtFreeValue(PTMP_tmp14_1); PTMP_tmp14_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_DM_1 =
{
    "DM",
    &P_DM_IMPL_1,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_AC_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_motionPlan = PrtMkDefaultValue(&P_GEND_TYPE_ST2ff);
    PRT_VALUE* P_VAR_index = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    PRT_VALUE* PTMP_tmp1_6 = NULL;
    PRT_VALUE* PTMP_tmp2_6 = NULL;
    PRT_VALUE* PTMP_tmp3_6 = NULL;
    PRT_VALUE* PTMP_tmp4_6 = NULL;
    PRT_VALUE* PTMP_tmp5_6 = NULL;
    PRT_VALUE* PTMP_tmp6_6 = NULL;
    PRT_VALUE* PTMP_tmp7_5 = NULL;
    PRT_VALUE* PTMP_tmp8_3 = NULL;
    PRT_VALUE* PTMP_tmp9_3 = NULL;
    PRT_VALUE* PTMP_tmp10_3 = NULL;
    PRT_VALUE* PTMP_tmp11_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_7 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_8 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_5 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_119 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_119);
    *P_LVALUE_119 = PrtMkIntValue(PrtSeqSizeOf(P_VAR_motionPlan));
    
    PRT_VALUE** P_LVALUE_120 = &(PTMP_tmp1_6);
    PrtFreeValue(*P_LVALUE_120);
    *P_LVALUE_120 = PrtCloneValue(p_this->varValues[4]);
    
    PrtSeqInsertEx(P_VAR_motionPlan, PTMP_tmp0_6, PTMP_tmp1_6, PRT_FALSE);
    *(&(PTMP_tmp1_6)) = NULL;
    
    PRT_VALUE** P_LVALUE_121 = &(P_VAR_index);
    PrtFreeValue(*P_LVALUE_121);
    *P_LVALUE_121 = PrtCloneValue((&P_LIT_INT32_7));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_5)))
    {
        PRT_VALUE** P_LVALUE_122 = &(PTMP_tmp2_6);
        PrtFreeValue(*P_LVALUE_122);
        *P_LVALUE_122 = PrtMkIntValue(PrtSeqSizeOf(P_VAR_motionPlan));
        
        PRT_VALUE** P_LVALUE_123 = &(PTMP_tmp3_6);
        PrtFreeValue(*P_LVALUE_123);
        *P_LVALUE_123 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_index) < PrtPrimGetInt(PTMP_tmp2_6));
        
        PRT_VALUE** P_LVALUE_124 = &(PTMP_tmp4_6);
        PrtFreeValue(*P_LVALUE_124);
        *P_LVALUE_124 = PrtCloneValue(PTMP_tmp3_6);
        
        if (PrtPrimGetBool(PTMP_tmp4_6))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        if (PrtPrimGetBool(p_this->varValues[5]))
        {
            PRT_VALUE** P_LVALUE_125 = &(PTMP_tmp5_6);
            PrtFreeValue(*P_LVALUE_125);
            *P_LVALUE_125 = PrtCloneValue(p_this->varValues[2]);
            
            PRT_VALUE** P_LVALUE_126 = &(PTMP_tmp6_6);
            PrtFreeValue(*P_LVALUE_126);
            *P_LVALUE_126 = PrtCloneValue((&P_EVENT_eMotionX.value));
            
            PRT_VALUE** P_LVALUE_127 = &(PTMP_tmp7_5);
            PrtFreeValue(*P_LVALUE_127);
            *P_LVALUE_127 = PrtSeqGet(P_VAR_motionPlan, P_VAR_index);
            
            PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp5_6), PTMP_tmp6_6, 1, &(PTMP_tmp7_5));
            *(&(PTMP_tmp6_6)) = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_9;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_9;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_128 = &(PTMP_tmp8_3);
            PrtFreeValue(*P_LVALUE_128);
            *P_LVALUE_128 = PrtCloneValue(p_this->varValues[2]);
            
            PRT_VALUE** P_LVALUE_129 = &(PTMP_tmp9_3);
            PrtFreeValue(*P_LVALUE_129);
            *P_LVALUE_129 = PrtCloneValue((&P_EVENT_eMotion.value));
            
            PRT_VALUE** P_LVALUE_130 = &(PTMP_tmp10_3);
            PrtFreeValue(*P_LVALUE_130);
            *P_LVALUE_130 = PrtSeqGet(P_VAR_motionPlan, P_VAR_index);
            
            PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp8_3), PTMP_tmp9_3, 1, &(PTMP_tmp10_3));
            *(&(PTMP_tmp9_3)) = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_9;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_9;
            }
            
        }
        
        
        PRT_VALUE** P_LVALUE_131 = &(PTMP_tmp11_3);
        PrtFreeValue(*P_LVALUE_131);
        *P_LVALUE_131 = PrtMkIntValue(PrtPrimGetInt(P_VAR_index) + PrtPrimGetInt((&P_LIT_INT32_8)));
        
        {
            PRT_VALUE** P_LVALUE_132 = &(P_VAR_index);
            PrtFreeValue(*P_LVALUE_132);
            *P_LVALUE_132 = PTMP_tmp11_3;
            PTMP_tmp11_3 = NULL;
        }
        
    }
    
    
p_return_9: ;
    PrtFreeValue(P_VAR_motionPlan); P_VAR_motionPlan = NULL;
    PrtFreeValue(P_VAR_index); P_VAR_index = NULL;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    PrtFreeValue(PTMP_tmp1_6); PTMP_tmp1_6 = NULL;
    PrtFreeValue(PTMP_tmp2_6); PTMP_tmp2_6 = NULL;
    PrtFreeValue(PTMP_tmp3_6); PTMP_tmp3_6 = NULL;
    PrtFreeValue(PTMP_tmp4_6); PTMP_tmp4_6 = NULL;
    PrtFreeValue(PTMP_tmp5_6); PTMP_tmp5_6 = NULL;
    PrtFreeValue(PTMP_tmp6_6); PTMP_tmp6_6 = NULL;
    PrtFreeValue(PTMP_tmp7_5); PTMP_tmp7_5 = NULL;
    PrtFreeValue(PTMP_tmp8_3); PTMP_tmp8_3 = NULL;
    PrtFreeValue(PTMP_tmp9_3); PTMP_tmp9_3 = NULL;
    PrtFreeValue(PTMP_tmp10_3); PTMP_tmp10_3 = NULL;
    PrtFreeValue(PTMP_tmp11_3); PTMP_tmp11_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_AC_1 =
{
    "AC",
    &P_AC_IMPL_1,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_SC_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_waypoint = PrtMkDefaultValue(&P_GEND_TYPE_T2ff);
    PRT_VALUE* P_VAR_motionPlan_1 = PrtMkDefaultValue(&P_GEND_TYPE_ST2ff);
    PRT_VALUE* P_VAR_index_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_7 = NULL;
    PRT_VALUE* PTMP_tmp1_7 = NULL;
    PRT_VALUE* PTMP_tmp2_7 = NULL;
    PRT_VALUE* PTMP_tmp3_7 = NULL;
    PRT_VALUE* PTMP_tmp4_7 = NULL;
    PRT_VALUE* PTMP_tmp5_7 = NULL;
    PRT_VALUE* PTMP_tmp6_7 = NULL;
    PRT_VALUE* PTMP_tmp7_6 = NULL;
    PRT_VALUE* PTMP_tmp8_4 = NULL;
    PRT_VALUE* PTMP_tmp9_4 = NULL;
    PRT_VALUE* PTMP_tmp10_4 = NULL;
    PRT_VALUE* PTMP_tmp11_4 = NULL;
    PRT_VALUE* PTMP_tmp12_2 = NULL;
    PRT_VALUE* PTMP_tmp13_2 = NULL;
    PRT_VALUE* PTMP_tmp14_2 = NULL;
    PRT_VALUE* PTMP_tmp15_1 = NULL;
    PRT_VALUE* PTMP_tmp16_1 = NULL;
    PRT_VALUE* PTMP_tmp17_1 = NULL;
    PRT_VALUE* PTMP_tmp18_1 = NULL;
    PRT_VALUE* PTMP_tmp19_1 = NULL;
    PRT_VALUE* PTMP_tmp20_1 = NULL;
    PRT_VALUE* PTMP_tmp21_1 = NULL;
    PRT_VALUE* PTMP_tmp22_1 = NULL;
    PRT_VALUE* PTMP_tmp23_1 = NULL;
    PRT_VALUE* PTMP_tmp24_1 = NULL;
    PRT_VALUE* PTMP_tmp25_1 = NULL;
    PRT_VALUE* PTMP_tmp26_1 = NULL;
    PRT_VALUE* PTMP_tmp27_1 = NULL;
    PRT_VALUE* PTMP_tmp28_1 = NULL;
    PRT_VALUE* PTMP_tmp29_1 = NULL;
    PRT_VALUE* PTMP_tmp30_1 = NULL;
    PRT_VALUE* PTMP_tmp31_1 = NULL;
    PRT_VALUE* PTMP_tmp32_1 = NULL;
    PRT_VALUE* PTMP_tmp33_1 = NULL;
    PRT_VALUE* PTMP_tmp34_1 = NULL;
    PRT_VALUE* PTMP_tmp35_1 = NULL;
    PRT_VALUE* PTMP_tmp36 = NULL;
    PRT_VALUE* PTMP_tmp37 = NULL;
    PRT_VALUE* PTMP_tmp38 = NULL;
    PRT_VALUE* PTMP_tmp39 = NULL;
    PRT_VALUE* PTMP_tmp40 = NULL;
    PRT_VALUE* PTMP_tmp41 = NULL;
    PRT_VALUE* PTMP_tmp42 = NULL;
    PRT_VALUE* PTMP_tmp43 = NULL;
    PRT_VALUE* PTMP_tmp44 = NULL;
    PRT_VALUE* PTMP_tmp45 = NULL;
    PRT_VALUE* PTMP_tmp46 = NULL;
    PRT_VALUE* PTMP_tmp47 = NULL;
    PRT_VALUE* PTMP_tmp48 = NULL;
    PRT_VALUE* PTMP_tmp49 = NULL;
    PRT_VALUE* PTMP_tmp50 = NULL;
    PRT_VALUE* PTMP_tmp51 = NULL;
    PRT_VALUE* PTMP_tmp52 = NULL;
    PRT_VALUE* PTMP_tmp53 = NULL;
    PRT_VALUE* PTMP_tmp54 = NULL;
    PRT_VALUE* PTMP_tmp55 = NULL;
    PRT_VALUE* PTMP_tmp56 = NULL;
    PRT_VALUE* PTMP_tmp57 = NULL;
    PRT_VALUE* PTMP_tmp58 = NULL;
    PRT_VALUE* PTMP_tmp59 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_9 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_10 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_6 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_133 = &(P_VAR_waypoint);
    PrtFreeValue(*P_LVALUE_133);
    *P_LVALUE_133 = PrtCloneValue(p_this->varValues[3]);
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_6)))
    {
        PRT_VALUE** P_LVALUE_134 = &(PTMP_tmp0_7);
        PrtFreeValue(*P_LVALUE_134);
        *P_LVALUE_134 = PrtTupleGet(P_VAR_waypoint, 0);
        
        PRT_VALUE** P_LVALUE_135 = &(PTMP_tmp1_7);
        PrtFreeValue(*P_LVALUE_135);
        *P_LVALUE_135 = PrtTupleGet(p_this->varValues[4], 0);
        
        PRT_VALUE** P_LVALUE_136 = &(PTMP_tmp2_7);
        PrtFreeValue(*P_LVALUE_136);
        *P_LVALUE_136 = PrtMkBoolValue(!PrtIsEqualValue(PTMP_tmp0_7, PTMP_tmp1_7));
        
        PRT_VALUE** P_LVALUE_137 = &(PTMP_tmp6_7);
        PrtFreeValue(*P_LVALUE_137);
        *P_LVALUE_137 = PrtCloneValue(PTMP_tmp2_7);
        
        if (PrtPrimGetBool(PTMP_tmp6_7))
        {
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_138 = &(PTMP_tmp3_7);
            PrtFreeValue(*P_LVALUE_138);
            *P_LVALUE_138 = PrtTupleGet(P_VAR_waypoint, 1);
            
            PRT_VALUE** P_LVALUE_139 = &(PTMP_tmp4_7);
            PrtFreeValue(*P_LVALUE_139);
            *P_LVALUE_139 = PrtTupleGet(p_this->varValues[4], 1);
            
            PRT_VALUE** P_LVALUE_140 = &(PTMP_tmp5_7);
            PrtFreeValue(*P_LVALUE_140);
            *P_LVALUE_140 = PrtMkBoolValue(!PrtIsEqualValue(PTMP_tmp3_7, PTMP_tmp4_7));
            
            PRT_VALUE** P_LVALUE_141 = &(PTMP_tmp6_7);
            PrtFreeValue(*P_LVALUE_141);
            *P_LVALUE_141 = PrtCloneValue(PTMP_tmp5_7);
            
        }
        
        
        PRT_VALUE** P_LVALUE_142 = &(PTMP_tmp7_6);
        PrtFreeValue(*P_LVALUE_142);
        *P_LVALUE_142 = PrtCloneValue(PTMP_tmp6_7);
        
        if (PrtPrimGetBool(PTMP_tmp7_6))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_143 = &(PTMP_tmp8_4);
        PrtFreeValue(*P_LVALUE_143);
        *P_LVALUE_143 = PrtTupleGet(P_VAR_waypoint, 0);
        
        PRT_VALUE** P_LVALUE_144 = &(PTMP_tmp9_4);
        PrtFreeValue(*P_LVALUE_144);
        *P_LVALUE_144 = PrtTupleGet(p_this->varValues[4], 0);
        
        PRT_VALUE** P_LVALUE_145 = &(PTMP_tmp10_4);
        PrtFreeValue(*P_LVALUE_145);
        *P_LVALUE_145 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp8_4) > PrtPrimGetFloat(PTMP_tmp9_4));
        
        if (PrtPrimGetBool(PTMP_tmp10_4))
        {
            PRT_VALUE** P_LVALUE_146 = &(PTMP_tmp11_4);
            PrtFreeValue(*P_LVALUE_146);
            *P_LVALUE_146 = PrtTupleGet(P_VAR_waypoint, 0);
            
            PRT_VALUE** P_LVALUE_147 = &(PTMP_tmp12_2);
            PrtFreeValue(*P_LVALUE_147);
            *P_LVALUE_147 = PrtMkFloatValue(PrtPrimGetFloat(PTMP_tmp11_4) - PrtPrimGetFloat(p_this->varValues[1]));
            
            {
                PRT_VALUE** P_LVALUE_148 = &(*(PrtTupleGetLValue(P_VAR_waypoint, 0)));
                PrtFreeValue(*P_LVALUE_148);
                *P_LVALUE_148 = PTMP_tmp12_2;
                PTMP_tmp12_2 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_149 = &(PTMP_tmp13_2);
            PrtFreeValue(*P_LVALUE_149);
            *P_LVALUE_149 = PrtTupleGet(P_VAR_waypoint, 0);
            
            PRT_VALUE** P_LVALUE_150 = &(PTMP_tmp14_2);
            PrtFreeValue(*P_LVALUE_150);
            *P_LVALUE_150 = PrtTupleGet(p_this->varValues[4], 0);
            
            PRT_VALUE** P_LVALUE_151 = &(PTMP_tmp15_1);
            PrtFreeValue(*P_LVALUE_151);
            *P_LVALUE_151 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp13_2) < PrtPrimGetFloat(PTMP_tmp14_2));
            
            if (PrtPrimGetBool(PTMP_tmp15_1))
            {
                PRT_VALUE** P_LVALUE_152 = &(PTMP_tmp16_1);
                PrtFreeValue(*P_LVALUE_152);
                *P_LVALUE_152 = PrtTupleGet(p_this->varValues[4], 0);
                
                PRT_VALUE** P_LVALUE_153 = &(PTMP_tmp17_1);
                PrtFreeValue(*P_LVALUE_153);
                *P_LVALUE_153 = PrtCloneValue(PTMP_tmp16_1);
                
                {
                    PRT_VALUE** P_LVALUE_154 = &(*(PrtTupleGetLValue(P_VAR_waypoint, 0)));
                    PrtFreeValue(*P_LVALUE_154);
                    *P_LVALUE_154 = PTMP_tmp17_1;
                    PTMP_tmp17_1 = NULL;
                }
                
            }
            
            else
            {
            }
            
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_155 = &(PTMP_tmp18_1);
            PrtFreeValue(*P_LVALUE_155);
            *P_LVALUE_155 = PrtTupleGet(P_VAR_waypoint, 0);
            
            PRT_VALUE** P_LVALUE_156 = &(PTMP_tmp19_1);
            PrtFreeValue(*P_LVALUE_156);
            *P_LVALUE_156 = PrtTupleGet(p_this->varValues[4], 0);
            
            PRT_VALUE** P_LVALUE_157 = &(PTMP_tmp20_1);
            PrtFreeValue(*P_LVALUE_157);
            *P_LVALUE_157 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp18_1) < PrtPrimGetFloat(PTMP_tmp19_1));
            
            if (PrtPrimGetBool(PTMP_tmp20_1))
            {
                PRT_VALUE** P_LVALUE_158 = &(PTMP_tmp21_1);
                PrtFreeValue(*P_LVALUE_158);
                *P_LVALUE_158 = PrtTupleGet(P_VAR_waypoint, 0);
                
                PRT_VALUE** P_LVALUE_159 = &(PTMP_tmp22_1);
                PrtFreeValue(*P_LVALUE_159);
                *P_LVALUE_159 = PrtMkFloatValue(PrtPrimGetFloat(PTMP_tmp21_1) + PrtPrimGetFloat(p_this->varValues[1]));
                
                {
                    PRT_VALUE** P_LVALUE_160 = &(*(PrtTupleGetLValue(P_VAR_waypoint, 0)));
                    PrtFreeValue(*P_LVALUE_160);
                    *P_LVALUE_160 = PTMP_tmp22_1;
                    PTMP_tmp22_1 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_161 = &(PTMP_tmp23_1);
                PrtFreeValue(*P_LVALUE_161);
                *P_LVALUE_161 = PrtTupleGet(P_VAR_waypoint, 0);
                
                PRT_VALUE** P_LVALUE_162 = &(PTMP_tmp24_1);
                PrtFreeValue(*P_LVALUE_162);
                *P_LVALUE_162 = PrtTupleGet(p_this->varValues[4], 0);
                
                PRT_VALUE** P_LVALUE_163 = &(PTMP_tmp25_1);
                PrtFreeValue(*P_LVALUE_163);
                *P_LVALUE_163 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp23_1) > PrtPrimGetFloat(PTMP_tmp24_1));
                
                if (PrtPrimGetBool(PTMP_tmp25_1))
                {
                    PRT_VALUE** P_LVALUE_164 = &(PTMP_tmp26_1);
                    PrtFreeValue(*P_LVALUE_164);
                    *P_LVALUE_164 = PrtTupleGet(p_this->varValues[4], 0);
                    
                    PRT_VALUE** P_LVALUE_165 = &(PTMP_tmp27_1);
                    PrtFreeValue(*P_LVALUE_165);
                    *P_LVALUE_165 = PrtCloneValue(PTMP_tmp26_1);
                    
                    {
                        PRT_VALUE** P_LVALUE_166 = &(*(PrtTupleGetLValue(P_VAR_waypoint, 0)));
                        PrtFreeValue(*P_LVALUE_166);
                        *P_LVALUE_166 = PTMP_tmp27_1;
                        PTMP_tmp27_1 = NULL;
                    }
                    
                }
                
                else
                {
                }
                
                
            }
            
            else
            {
            }
            
            
        }
        
        
        PRT_VALUE** P_LVALUE_167 = &(PTMP_tmp28_1);
        PrtFreeValue(*P_LVALUE_167);
        *P_LVALUE_167 = PrtTupleGet(P_VAR_waypoint, 1);
        
        PRT_VALUE** P_LVALUE_168 = &(PTMP_tmp29_1);
        PrtFreeValue(*P_LVALUE_168);
        *P_LVALUE_168 = PrtTupleGet(p_this->varValues[4], 1);
        
        PRT_VALUE** P_LVALUE_169 = &(PTMP_tmp30_1);
        PrtFreeValue(*P_LVALUE_169);
        *P_LVALUE_169 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp28_1) > PrtPrimGetFloat(PTMP_tmp29_1));
        
        if (PrtPrimGetBool(PTMP_tmp30_1))
        {
            PRT_VALUE** P_LVALUE_170 = &(PTMP_tmp31_1);
            PrtFreeValue(*P_LVALUE_170);
            *P_LVALUE_170 = PrtTupleGet(P_VAR_waypoint, 1);
            
            PRT_VALUE** P_LVALUE_171 = &(PTMP_tmp32_1);
            PrtFreeValue(*P_LVALUE_171);
            *P_LVALUE_171 = PrtMkFloatValue(PrtPrimGetFloat(PTMP_tmp31_1) - PrtPrimGetFloat(p_this->varValues[1]));
            
            {
                PRT_VALUE** P_LVALUE_172 = &(*(PrtTupleGetLValue(P_VAR_waypoint, 1)));
                PrtFreeValue(*P_LVALUE_172);
                *P_LVALUE_172 = PTMP_tmp32_1;
                PTMP_tmp32_1 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_173 = &(PTMP_tmp33_1);
            PrtFreeValue(*P_LVALUE_173);
            *P_LVALUE_173 = PrtTupleGet(P_VAR_waypoint, 1);
            
            PRT_VALUE** P_LVALUE_174 = &(PTMP_tmp34_1);
            PrtFreeValue(*P_LVALUE_174);
            *P_LVALUE_174 = PrtTupleGet(p_this->varValues[4], 1);
            
            PRT_VALUE** P_LVALUE_175 = &(PTMP_tmp35_1);
            PrtFreeValue(*P_LVALUE_175);
            *P_LVALUE_175 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp33_1) < PrtPrimGetFloat(PTMP_tmp34_1));
            
            if (PrtPrimGetBool(PTMP_tmp35_1))
            {
                PRT_VALUE** P_LVALUE_176 = &(PTMP_tmp36);
                PrtFreeValue(*P_LVALUE_176);
                *P_LVALUE_176 = PrtTupleGet(p_this->varValues[4], 1);
                
                PRT_VALUE** P_LVALUE_177 = &(PTMP_tmp37);
                PrtFreeValue(*P_LVALUE_177);
                *P_LVALUE_177 = PrtCloneValue(PTMP_tmp36);
                
                {
                    PRT_VALUE** P_LVALUE_178 = &(*(PrtTupleGetLValue(P_VAR_waypoint, 1)));
                    PrtFreeValue(*P_LVALUE_178);
                    *P_LVALUE_178 = PTMP_tmp37;
                    PTMP_tmp37 = NULL;
                }
                
            }
            
            else
            {
            }
            
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_179 = &(PTMP_tmp38);
            PrtFreeValue(*P_LVALUE_179);
            *P_LVALUE_179 = PrtTupleGet(P_VAR_waypoint, 1);
            
            PRT_VALUE** P_LVALUE_180 = &(PTMP_tmp39);
            PrtFreeValue(*P_LVALUE_180);
            *P_LVALUE_180 = PrtTupleGet(p_this->varValues[4], 1);
            
            PRT_VALUE** P_LVALUE_181 = &(PTMP_tmp40);
            PrtFreeValue(*P_LVALUE_181);
            *P_LVALUE_181 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp38) < PrtPrimGetFloat(PTMP_tmp39));
            
            if (PrtPrimGetBool(PTMP_tmp40))
            {
                PRT_VALUE** P_LVALUE_182 = &(PTMP_tmp41);
                PrtFreeValue(*P_LVALUE_182);
                *P_LVALUE_182 = PrtTupleGet(P_VAR_waypoint, 1);
                
                PRT_VALUE** P_LVALUE_183 = &(PTMP_tmp42);
                PrtFreeValue(*P_LVALUE_183);
                *P_LVALUE_183 = PrtMkFloatValue(PrtPrimGetFloat(PTMP_tmp41) + PrtPrimGetFloat(p_this->varValues[1]));
                
                {
                    PRT_VALUE** P_LVALUE_184 = &(*(PrtTupleGetLValue(P_VAR_waypoint, 1)));
                    PrtFreeValue(*P_LVALUE_184);
                    *P_LVALUE_184 = PTMP_tmp42;
                    PTMP_tmp42 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_185 = &(PTMP_tmp43);
                PrtFreeValue(*P_LVALUE_185);
                *P_LVALUE_185 = PrtTupleGet(P_VAR_waypoint, 1);
                
                PRT_VALUE** P_LVALUE_186 = &(PTMP_tmp44);
                PrtFreeValue(*P_LVALUE_186);
                *P_LVALUE_186 = PrtTupleGet(p_this->varValues[4], 1);
                
                PRT_VALUE** P_LVALUE_187 = &(PTMP_tmp45);
                PrtFreeValue(*P_LVALUE_187);
                *P_LVALUE_187 = PrtMkBoolValue(PrtPrimGetFloat(PTMP_tmp43) > PrtPrimGetFloat(PTMP_tmp44));
                
                if (PrtPrimGetBool(PTMP_tmp45))
                {
                    PRT_VALUE** P_LVALUE_188 = &(PTMP_tmp46);
                    PrtFreeValue(*P_LVALUE_188);
                    *P_LVALUE_188 = PrtTupleGet(p_this->varValues[4], 1);
                    
                    PRT_VALUE** P_LVALUE_189 = &(PTMP_tmp47);
                    PrtFreeValue(*P_LVALUE_189);
                    *P_LVALUE_189 = PrtCloneValue(PTMP_tmp46);
                    
                    {
                        PRT_VALUE** P_LVALUE_190 = &(*(PrtTupleGetLValue(P_VAR_waypoint, 1)));
                        PrtFreeValue(*P_LVALUE_190);
                        *P_LVALUE_190 = PTMP_tmp47;
                        PTMP_tmp47 = NULL;
                    }
                    
                }
                
                else
                {
                }
                
                
            }
            
            else
            {
            }
            
            
        }
        
        
        PRT_VALUE** P_LVALUE_191 = &(PTMP_tmp48);
        PrtFreeValue(*P_LVALUE_191);
        *P_LVALUE_191 = PrtMkIntValue(PrtSeqSizeOf(P_VAR_motionPlan_1));
        
        PRT_VALUE** P_LVALUE_192 = &(PTMP_tmp49);
        PrtFreeValue(*P_LVALUE_192);
        *P_LVALUE_192 = PrtCloneValue(P_VAR_waypoint);
        
        PrtSeqInsertEx(P_VAR_motionPlan_1, PTMP_tmp48, PTMP_tmp49, PRT_FALSE);
        *(&(PTMP_tmp49)) = NULL;
        
    }
    
    
    PRT_VALUE** P_LVALUE_193 = &(P_VAR_index_1);
    PrtFreeValue(*P_LVALUE_193);
    *P_LVALUE_193 = PrtCloneValue((&P_LIT_INT32_9));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_6)))
    {
        PRT_VALUE** P_LVALUE_194 = &(PTMP_tmp50);
        PrtFreeValue(*P_LVALUE_194);
        *P_LVALUE_194 = PrtMkIntValue(PrtSeqSizeOf(P_VAR_motionPlan_1));
        
        PRT_VALUE** P_LVALUE_195 = &(PTMP_tmp51);
        PrtFreeValue(*P_LVALUE_195);
        *P_LVALUE_195 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_index_1) < PrtPrimGetInt(PTMP_tmp50));
        
        PRT_VALUE** P_LVALUE_196 = &(PTMP_tmp52);
        PrtFreeValue(*P_LVALUE_196);
        *P_LVALUE_196 = PrtCloneValue(PTMP_tmp51);
        
        if (PrtPrimGetBool(PTMP_tmp52))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        if (PrtPrimGetBool(p_this->varValues[5]))
        {
            PRT_VALUE** P_LVALUE_197 = &(PTMP_tmp53);
            PrtFreeValue(*P_LVALUE_197);
            *P_LVALUE_197 = PrtCloneValue(p_this->varValues[2]);
            
            PRT_VALUE** P_LVALUE_198 = &(PTMP_tmp54);
            PrtFreeValue(*P_LVALUE_198);
            *P_LVALUE_198 = PrtCloneValue((&P_EVENT_eMotionX.value));
            
            PRT_VALUE** P_LVALUE_199 = &(PTMP_tmp55);
            PrtFreeValue(*P_LVALUE_199);
            *P_LVALUE_199 = PrtSeqGet(P_VAR_motionPlan_1, P_VAR_index_1);
            
            PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp53), PTMP_tmp54, 1, &(PTMP_tmp55));
            *(&(PTMP_tmp54)) = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_10;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_10;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_200 = &(PTMP_tmp56);
            PrtFreeValue(*P_LVALUE_200);
            *P_LVALUE_200 = PrtCloneValue(p_this->varValues[2]);
            
            PRT_VALUE** P_LVALUE_201 = &(PTMP_tmp57);
            PrtFreeValue(*P_LVALUE_201);
            *P_LVALUE_201 = PrtCloneValue((&P_EVENT_eMotion.value));
            
            PRT_VALUE** P_LVALUE_202 = &(PTMP_tmp58);
            PrtFreeValue(*P_LVALUE_202);
            *P_LVALUE_202 = PrtSeqGet(P_VAR_motionPlan_1, P_VAR_index_1);
            
            PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp56), PTMP_tmp57, 1, &(PTMP_tmp58));
            *(&(PTMP_tmp57)) = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_10;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_10;
            }
            
        }
        
        
        PRT_VALUE** P_LVALUE_203 = &(PTMP_tmp59);
        PrtFreeValue(*P_LVALUE_203);
        *P_LVALUE_203 = PrtMkIntValue(PrtPrimGetInt(P_VAR_index_1) + PrtPrimGetInt((&P_LIT_INT32_10)));
        
        {
            PRT_VALUE** P_LVALUE_204 = &(P_VAR_index_1);
            PrtFreeValue(*P_LVALUE_204);
            *P_LVALUE_204 = PTMP_tmp59;
            PTMP_tmp59 = NULL;
        }
        
    }
    
    
p_return_10: ;
    PrtFreeValue(P_VAR_waypoint); P_VAR_waypoint = NULL;
    PrtFreeValue(P_VAR_motionPlan_1); P_VAR_motionPlan_1 = NULL;
    PrtFreeValue(P_VAR_index_1); P_VAR_index_1 = NULL;
    PrtFreeValue(PTMP_tmp0_7); PTMP_tmp0_7 = NULL;
    PrtFreeValue(PTMP_tmp1_7); PTMP_tmp1_7 = NULL;
    PrtFreeValue(PTMP_tmp2_7); PTMP_tmp2_7 = NULL;
    PrtFreeValue(PTMP_tmp3_7); PTMP_tmp3_7 = NULL;
    PrtFreeValue(PTMP_tmp4_7); PTMP_tmp4_7 = NULL;
    PrtFreeValue(PTMP_tmp5_7); PTMP_tmp5_7 = NULL;
    PrtFreeValue(PTMP_tmp6_7); PTMP_tmp6_7 = NULL;
    PrtFreeValue(PTMP_tmp7_6); PTMP_tmp7_6 = NULL;
    PrtFreeValue(PTMP_tmp8_4); PTMP_tmp8_4 = NULL;
    PrtFreeValue(PTMP_tmp9_4); PTMP_tmp9_4 = NULL;
    PrtFreeValue(PTMP_tmp10_4); PTMP_tmp10_4 = NULL;
    PrtFreeValue(PTMP_tmp11_4); PTMP_tmp11_4 = NULL;
    PrtFreeValue(PTMP_tmp12_2); PTMP_tmp12_2 = NULL;
    PrtFreeValue(PTMP_tmp13_2); PTMP_tmp13_2 = NULL;
    PrtFreeValue(PTMP_tmp14_2); PTMP_tmp14_2 = NULL;
    PrtFreeValue(PTMP_tmp15_1); PTMP_tmp15_1 = NULL;
    PrtFreeValue(PTMP_tmp16_1); PTMP_tmp16_1 = NULL;
    PrtFreeValue(PTMP_tmp17_1); PTMP_tmp17_1 = NULL;
    PrtFreeValue(PTMP_tmp18_1); PTMP_tmp18_1 = NULL;
    PrtFreeValue(PTMP_tmp19_1); PTMP_tmp19_1 = NULL;
    PrtFreeValue(PTMP_tmp20_1); PTMP_tmp20_1 = NULL;
    PrtFreeValue(PTMP_tmp21_1); PTMP_tmp21_1 = NULL;
    PrtFreeValue(PTMP_tmp22_1); PTMP_tmp22_1 = NULL;
    PrtFreeValue(PTMP_tmp23_1); PTMP_tmp23_1 = NULL;
    PrtFreeValue(PTMP_tmp24_1); PTMP_tmp24_1 = NULL;
    PrtFreeValue(PTMP_tmp25_1); PTMP_tmp25_1 = NULL;
    PrtFreeValue(PTMP_tmp26_1); PTMP_tmp26_1 = NULL;
    PrtFreeValue(PTMP_tmp27_1); PTMP_tmp27_1 = NULL;
    PrtFreeValue(PTMP_tmp28_1); PTMP_tmp28_1 = NULL;
    PrtFreeValue(PTMP_tmp29_1); PTMP_tmp29_1 = NULL;
    PrtFreeValue(PTMP_tmp30_1); PTMP_tmp30_1 = NULL;
    PrtFreeValue(PTMP_tmp31_1); PTMP_tmp31_1 = NULL;
    PrtFreeValue(PTMP_tmp32_1); PTMP_tmp32_1 = NULL;
    PrtFreeValue(PTMP_tmp33_1); PTMP_tmp33_1 = NULL;
    PrtFreeValue(PTMP_tmp34_1); PTMP_tmp34_1 = NULL;
    PrtFreeValue(PTMP_tmp35_1); PTMP_tmp35_1 = NULL;
    PrtFreeValue(PTMP_tmp36); PTMP_tmp36 = NULL;
    PrtFreeValue(PTMP_tmp37); PTMP_tmp37 = NULL;
    PrtFreeValue(PTMP_tmp38); PTMP_tmp38 = NULL;
    PrtFreeValue(PTMP_tmp39); PTMP_tmp39 = NULL;
    PrtFreeValue(PTMP_tmp40); PTMP_tmp40 = NULL;
    PrtFreeValue(PTMP_tmp41); PTMP_tmp41 = NULL;
    PrtFreeValue(PTMP_tmp42); PTMP_tmp42 = NULL;
    PrtFreeValue(PTMP_tmp43); PTMP_tmp43 = NULL;
    PrtFreeValue(PTMP_tmp44); PTMP_tmp44 = NULL;
    PrtFreeValue(PTMP_tmp45); PTMP_tmp45 = NULL;
    PrtFreeValue(PTMP_tmp46); PTMP_tmp46 = NULL;
    PrtFreeValue(PTMP_tmp47); PTMP_tmp47 = NULL;
    PrtFreeValue(PTMP_tmp48); PTMP_tmp48 = NULL;
    PrtFreeValue(PTMP_tmp49); PTMP_tmp49 = NULL;
    PrtFreeValue(PTMP_tmp50); PTMP_tmp50 = NULL;
    PrtFreeValue(PTMP_tmp51); PTMP_tmp51 = NULL;
    PrtFreeValue(PTMP_tmp52); PTMP_tmp52 = NULL;
    PrtFreeValue(PTMP_tmp53); PTMP_tmp53 = NULL;
    PrtFreeValue(PTMP_tmp54); PTMP_tmp54 = NULL;
    PrtFreeValue(PTMP_tmp55); PTMP_tmp55 = NULL;
    PrtFreeValue(PTMP_tmp56); PTMP_tmp56 = NULL;
    PrtFreeValue(PTMP_tmp57); PTMP_tmp57 = NULL;
    PrtFreeValue(PTMP_tmp58); PTMP_tmp58 = NULL;
    PrtFreeValue(PTMP_tmp59); PTMP_tmp59 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_SC_1 =
{
    "SC",
    &P_SC_IMPL_1,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_handler_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_8 = NULL;
    PRT_VALUE* PTMP_tmp1_8 = NULL;
    PRT_VALUE* PTMP_tmp2_8 = NULL;
    PRT_VALUE* PTMP_tmp3_8 = NULL;
    PRT_VALUE* PTMP_tmp4_8 = NULL;
    PRT_VALUE* PTMP_tmp5_8 = NULL;
    PRT_VALUE* PTMP_tmp6_8 = NULL;
    PRT_VALUE* PTMP_tmp7_7 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_205 = &(PTMP_tmp0_8);
    PrtFreeValue(*P_LVALUE_205);
    *P_LVALUE_205 = PrtTupleGet(*P_VAR_payload_2, 0);
    
    PRT_VALUE** P_LVALUE_206 = &(PTMP_tmp1_8);
    PrtFreeValue(*P_LVALUE_206);
    *P_LVALUE_206 = PrtCloneValue(PTMP_tmp0_8);
    
    {
        PRT_VALUE** P_LVALUE_207 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_207);
        *P_LVALUE_207 = PTMP_tmp1_8;
        PTMP_tmp1_8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_208 = &(PTMP_tmp2_8);
    PrtFreeValue(*P_LVALUE_208);
    *P_LVALUE_208 = PrtTupleGet(*P_VAR_payload_2, 1);
    
    PRT_VALUE** P_LVALUE_209 = &(PTMP_tmp3_8);
    PrtFreeValue(*P_LVALUE_209);
    *P_LVALUE_209 = PrtCloneValue(PTMP_tmp2_8);
    
    {
        PRT_VALUE** P_LVALUE_210 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_210);
        *P_LVALUE_210 = PTMP_tmp3_8;
        PTMP_tmp3_8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_211 = &(PTMP_tmp4_8);
    PrtFreeValue(*P_LVALUE_211);
    *P_LVALUE_211 = PrtTupleGet(*P_VAR_payload_2, 2);
    
    PRT_VALUE** P_LVALUE_212 = &(PTMP_tmp5_8);
    PrtFreeValue(*P_LVALUE_212);
    *P_LVALUE_212 = PrtCloneValue(PTMP_tmp4_8);
    
    {
        PRT_VALUE** P_LVALUE_213 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_213);
        *P_LVALUE_213 = PTMP_tmp5_8;
        PTMP_tmp5_8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_214 = &(PTMP_tmp6_8);
    PrtFreeValue(*P_LVALUE_214);
    *P_LVALUE_214 = PrtTupleGet(*P_VAR_payload_2, 3);
    
    PRT_VALUE** P_LVALUE_215 = &(PTMP_tmp7_7);
    PrtFreeValue(*P_LVALUE_215);
    *P_LVALUE_215 = PrtCloneValue(PTMP_tmp6_8);
    
    {
        PRT_VALUE** P_LVALUE_216 = &(p_this->varValues[5]);
        PrtFreeValue(*P_LVALUE_216);
        *P_LVALUE_216 = PTMP_tmp7_7;
        PTMP_tmp7_7 = NULL;
    }
    
p_return_11: ;
    PrtFreeValue(PTMP_tmp0_8); PTMP_tmp0_8 = NULL;
    PrtFreeValue(PTMP_tmp1_8); PTMP_tmp1_8 = NULL;
    PrtFreeValue(PTMP_tmp2_8); PTMP_tmp2_8 = NULL;
    PrtFreeValue(PTMP_tmp3_8); PTMP_tmp3_8 = NULL;
    PrtFreeValue(PTMP_tmp4_8); PTMP_tmp4_8 = NULL;
    PrtFreeValue(PTMP_tmp5_8); PTMP_tmp5_8 = NULL;
    PrtFreeValue(PTMP_tmp6_8); PTMP_tmp6_8 = NULL;
    PrtFreeValue(PTMP_tmp7_7); PTMP_tmp7_7 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_handler_1 =
{
    "handler",
    &P_handler_IMPL_1,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_11 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_DOUBLE_5 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.25 } };
    PRT_VALUE P_LIT_BOOLEAN_7 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_217 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_217);
    *P_LVALUE_217 = PrtCloneValue((&P_LIT_DOUBLE_5));
    
    PrtGoto(p_this, 1U, 0);
    
    PRT_VALUE** P_LVALUE_218 = &(p_this->varValues[6]);
    PrtFreeValue(*P_LVALUE_218);
    *P_LVALUE_218 = PrtCloneValue((&P_LIT_BOOLEAN_7));
    
    PRT_VALUE** P_LVALUE_219 = &(p_this->varValues[9]);
    PrtFreeValue(*P_LVALUE_219);
    *P_LVALUE_219 = PrtCloneValue((&P_LIT_INT32_11));
    
p_return_12: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_9 = NULL;
    PRT_VALUE* PTMP_tmp1_9 = NULL;
    PRT_VALUE* PTMP_tmp2_9 = NULL;
    PRT_VALUE* PTMP_tmp3_9 = NULL;
    PRT_VALUE* PTMP_tmp4_9 = NULL;
    PRT_VALUE* PTMP_tmp5_9 = NULL;
    PRT_VALUE* PTMP_tmp6_9 = NULL;
    PRT_VALUE* PTMP_tmp7_8 = NULL;
    PRT_VALUE* PTMP_tmp8_5 = NULL;
    PRT_VALUE* PTMP_tmp9_5 = NULL;
    PRT_VALUE* PTMP_tmp10_5 = NULL;
    PRT_VALUE* PTMP_tmp11_5 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_12 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_8 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_220 = &(PTMP_tmp0_9);
    PrtFreeValue(*P_LVALUE_220);
    *P_LVALUE_220 = PrtCloneValue(*P_VAR_payload_3);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_9);
    PrtFreeValue(P_handler_IMPL_1(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_9);
    PTMP_tmp0_9 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_13;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_13;
    }
    
    PRT_VALUE** P_LVALUE_221 = &(PTMP_tmp1_9);
    PrtFreeValue(*P_LVALUE_221);
    *P_LVALUE_221 = PrtMkBoolValue(!PrtPrimGetBool(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_9))
    {
        PRT_VALUE** P_LVALUE_222 = &(p_this->varValues[6]);
        PrtFreeValue(*P_LVALUE_222);
        *P_LVALUE_222 = PrtCloneValue((&P_LIT_BOOLEAN_8));
        
        PRT_VALUE** P_LVALUE_223 = &(PTMP_tmp2_9);
        PrtFreeValue(*P_LVALUE_223);
        *P_LVALUE_223 = ((_P_GEN_funval = P_DM_IMPL_1(context, _P_GEN_funargs)), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_13;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_13;
        }
        
        {
            PRT_VALUE** P_LVALUE_224 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_224);
            *P_LVALUE_224 = PTMP_tmp2_9;
            PTMP_tmp2_9 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_225 = &(PTMP_tmp3_9);
        PrtFreeValue(*P_LVALUE_225);
        *P_LVALUE_225 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
        ;
        
        PRT_VALUE** P_LVALUE_226 = &(PTMP_tmp4_9);
        PrtFreeValue(*P_LVALUE_226);
        *P_LVALUE_226 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[7], PTMP_tmp3_9));
        
        if (PrtPrimGetBool(PTMP_tmp4_9))
        {
            PrtFreeValue(P_AC_IMPL_1(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_13;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_13;
            }
            
            PRT_VALUE** P_LVALUE_227 = &(p_this->varValues[8]);
            PrtFreeValue(*P_LVALUE_227);
            *P_LVALUE_227 = PrtCloneValue((&P_LIT_INT32_12));
            
        }
        
        else
        {
            PrtFreeValue(P_SC_IMPL_1(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_13;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_13;
            }
            
            PRT_VALUE** P_LVALUE_228 = &(p_this->varValues[8]);
            PrtFreeValue(*P_LVALUE_228);
            *P_LVALUE_228 = PrtCloneValue((&P_LIT_INT32_12));
            
        }
        
        
        PRT_VALUE** P_LVALUE_229 = &(p_this->varValues[9]);
        PrtFreeValue(*P_LVALUE_229);
        *P_LVALUE_229 = PrtCloneValue((&P_LIT_INT32_12));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_230 = &(PTMP_tmp5_9);
        PrtFreeValue(*P_LVALUE_230);
        *P_LVALUE_230 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[8], p_this->varValues[9]));
        
        if (PrtPrimGetBool(PTMP_tmp5_9))
        {
            PRT_VALUE** P_LVALUE_231 = &(PTMP_tmp6_9);
            PrtFreeValue(*P_LVALUE_231);
            *P_LVALUE_231 = ((_P_GEN_funval = P_DM_IMPL_1(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_13;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_13;
            }
            
            {
                PRT_VALUE** P_LVALUE_232 = &(p_this->varValues[7]);
                PrtFreeValue(*P_LVALUE_232);
                *P_LVALUE_232 = PTMP_tmp6_9;
                PTMP_tmp6_9 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_233 = &(PTMP_tmp7_8);
            PrtFreeValue(*P_LVALUE_233);
            *P_LVALUE_233 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_234 = &(PTMP_tmp8_5);
            PrtFreeValue(*P_LVALUE_234);
            *P_LVALUE_234 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[7], PTMP_tmp7_8));
            
            if (PrtPrimGetBool(PTMP_tmp8_5))
            {
                PrtFreeValue(P_AC_IMPL_1(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_13;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_13;
                }
                
                PRT_VALUE** P_LVALUE_235 = &(p_this->varValues[8]);
                PrtFreeValue(*P_LVALUE_235);
                *P_LVALUE_235 = PrtCloneValue((&P_LIT_INT32_12));
                
            }
            
            else
            {
                PrtFreeValue(P_SC_IMPL_1(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_13;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_13;
                }
                
                PRT_VALUE** P_LVALUE_236 = &(p_this->varValues[8]);
                PrtFreeValue(*P_LVALUE_236);
                *P_LVALUE_236 = PrtCloneValue((&P_LIT_INT32_12));
                
            }
            
            
            PRT_VALUE** P_LVALUE_237 = &(p_this->varValues[9]);
            PrtFreeValue(*P_LVALUE_237);
            *P_LVALUE_237 = PrtCloneValue((&P_LIT_INT32_12));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_238 = &(PTMP_tmp9_5);
            PrtFreeValue(*P_LVALUE_238);
            *P_LVALUE_238 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_239 = &(PTMP_tmp10_5);
            PrtFreeValue(*P_LVALUE_239);
            *P_LVALUE_239 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[7], PTMP_tmp9_5));
            
            if (PrtPrimGetBool(PTMP_tmp10_5))
            {
                PrtFreeValue(P_AC_IMPL_1(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_13;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_13;
                }
                
                PRT_VALUE** P_LVALUE_240 = &(p_this->varValues[8]);
                PrtFreeValue(*P_LVALUE_240);
                *P_LVALUE_240 = PrtCloneValue((&P_LIT_INT32_12));
                
            }
            
            else
            {
                PrtFreeValue(P_SC_IMPL_1(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_13;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_13;
                }
                
                PRT_VALUE** P_LVALUE_241 = &(p_this->varValues[8]);
                PrtFreeValue(*P_LVALUE_241);
                *P_LVALUE_241 = PrtCloneValue((&P_LIT_INT32_12));
                
            }
            
            
            PRT_VALUE** P_LVALUE_242 = &(PTMP_tmp11_5);
            PrtFreeValue(*P_LVALUE_242);
            *P_LVALUE_242 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[9]) + PrtPrimGetInt((&P_LIT_INT32_12)));
            
            {
                PRT_VALUE** P_LVALUE_243 = &(p_this->varValues[9]);
                PrtFreeValue(*P_LVALUE_243);
                *P_LVALUE_243 = PTMP_tmp11_5;
                PTMP_tmp11_5 = NULL;
            }
            
        }
        
        
    }
    
    
p_return_13: ;
    PrtFreeValue(PTMP_tmp0_9); PTMP_tmp0_9 = NULL;
    PrtFreeValue(PTMP_tmp1_9); PTMP_tmp1_9 = NULL;
    PrtFreeValue(PTMP_tmp2_9); PTMP_tmp2_9 = NULL;
    PrtFreeValue(PTMP_tmp3_9); PTMP_tmp3_9 = NULL;
    PrtFreeValue(PTMP_tmp4_9); PTMP_tmp4_9 = NULL;
    PrtFreeValue(PTMP_tmp5_9); PTMP_tmp5_9 = NULL;
    PrtFreeValue(PTMP_tmp6_9); PTMP_tmp6_9 = NULL;
    PrtFreeValue(PTMP_tmp7_8); PTMP_tmp7_8 = NULL;
    PrtFreeValue(PTMP_tmp8_5); PTMP_tmp8_5 = NULL;
    PrtFreeValue(PTMP_tmp9_5); PTMP_tmp9_5 = NULL;
    PrtFreeValue(PTMP_tmp10_5); PTMP_tmp10_5 = NULL;
    PrtFreeValue(PTMP_tmp11_5); PTMP_tmp11_5 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_5,
    &P_GEND_TYPE_T4mT2ffT2ffb,
    PRT_TRUE
};


PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_13 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_9 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_244 = &(p_this->varValues[6]);
    PrtFreeValue(*P_LVALUE_244);
    *P_LVALUE_244 = PrtCloneValue((&P_LIT_BOOLEAN_9));
    
    PRT_VALUE** P_LVALUE_245 = &(p_this->varValues[9]);
    PrtFreeValue(*P_LVALUE_245);
    *P_LVALUE_245 = PrtCloneValue((&P_LIT_INT32_13));
    
p_return_14: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_6,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL* P_MotionPlanner_METHODS[] = { &P_FUNCTION_DM_1, &P_FUNCTION_AC_1, &P_FUNCTION_SC_1, &P_FUNCTION_handler_1, &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_6, &P_FUNCTION_Anon_5 };

PRT_EVENTDECL* P_MotionPlanner_RECV_INNER_1[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MotionPlanner_RECV_1 =
{
    9U,
    P_MotionPlanner_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_MotionPlanner_SEND_INNER[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MotionPlanner_SEND =
{
    9U,
    P_MotionPlanner_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_MotionPlanner = 
{
    1U,
    "MotionPlanner",
    &P_EVENTSET_MotionPlanner_RECV_1,
    &P_EVENTSET_MotionPlanner_SEND,
    NULL,
    10U,
    2U,
    7U,
    4294967295U,
    0U,
    0U,
    P_MotionPlanner_VARS,
    P_MotionPlanner_STATES,
    P_MotionPlanner_METHODS
};

PRT_VARDECL P_MotionPrimitives_VARS[] = {
    { "motions", &P_GEND_TYPE_ST2ff },
    { "currentMotionIndex", &P_GEND_TYPE_i },
    { "highPriorityMotions", &P_GEND_TYPE_ST2ff },
    { "currentHighPriorityMotionsIndex", &P_GEND_TYPE_i },
    { "trajectoryDeviationThreshold", &P_GEND_TYPE_f },
    { "trajectoryDeviation", &P_GEND_TYPE_f },
    { "currentLocation", &P_GEND_TYPE_T2ff },
    { "currentMotion", &P_GEND_TYPE_T2ff },
    { "lastGoal", &P_GEND_TYPE_T2ff },
    { "advancedMotionControllerCount", &P_GEND_TYPE_i },
    { "safeMotionControllerCount", &P_GEND_TYPE_i },
    { "robot", &P_GEND_TYPE_m },
    { "rotateCount", &P_GEND_TYPE_i },
    { "isBatteryLow", &P_GEND_TYPE_b },
    { "", &P_GEND_TYPE_b },
    { "", &P_GEND_TYPE_r },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_2 =
{
    0U,
    P_Init_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_2 =
{
    0U,
    P_Init_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_2 =
{
    0U,
    P_Init_DOS_INNER_2,
    NULL
};

#define P_STATE_MotionPrimitives_Init \
{ \
    "MotionPrimitives.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_2, \
    &P_EVENTSET_Init_TRANS_2, \
    &P_EVENTSET_Init_DOS_2, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_7, \
    &_P_NO_OP, \
    &_P_NO_OP, \
    0, \
}

PRT_EVENTDECL* P_Run_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Run_DEFERS_2 =
{
    0U,
    P_Run_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Run_TRANS_INNER_2[] = { &P_EVENT_eBatteryLow };
PRT_EVENTSETDECL P_EVENTSET_Run_TRANS_2 =
{
    1U,
    P_Run_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Run_DOS_INNER_2[] = { &P_EVENT_eMotion, &P_EVENT_eMotionX };
PRT_EVENTSETDECL P_EVENTSET_Run_DOS_2 =
{
    2U,
    P_Run_DOS_INNER_2,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 1, &P_EVENT_eBatteryLow, 2, &P_FUNCTION_Anon_10 }
};

PRT_DODECL P_DOS_2[] =
{
    { 1, &P_EVENT_eMotion, &P_FUNCTION_Anon_11 },
    { 1, &P_EVENT_eMotionX, &P_FUNCTION_Anon_12 }
};

#define P_STATE_MotionPrimitives_Run \
{ \
    "MotionPrimitives.Run", \
    1U, \
    2U, \
    &P_EVENTSET_Run_DEFERS_2, \
    &P_EVENTSET_Run_TRANS_2, \
    &P_EVENTSET_Run_DOS_2, \
    P_TRANS, \
    P_DOS_2, \
    &P_FUNCTION_Anon_8, \
    &_P_NO_OP, \
    &P_FUNCTION_Anon_9, \
    0, \
}

PRT_EVENTDECL* P_LowBatteryRun_DEFERS_INNER[] = { &P_EVENT_eMotion };
PRT_EVENTSETDECL P_EVENTSET_LowBatteryRun_DEFERS =
{
    1U,
    P_LowBatteryRun_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_LowBatteryRun_TRANS_INNER[] = { &P_EVENT_eBatteryRecovered };
PRT_EVENTSETDECL P_EVENTSET_LowBatteryRun_TRANS =
{
    1U,
    P_LowBatteryRun_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_LowBatteryRun_DOS_INNER[] = { &P_EVENT_eMotionX };
PRT_EVENTSETDECL P_EVENTSET_LowBatteryRun_DOS =
{
    1U,
    P_LowBatteryRun_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 2, &P_EVENT_eBatteryRecovered, 1, &P_FUNCTION_Anon_15 }
};

PRT_DODECL P_DOS_3[] =
{
    { 2, &P_EVENT_eMotionX, &P_FUNCTION_Anon_16 }
};

#define P_STATE_MotionPrimitives_LowBatteryRun \
{ \
    "MotionPrimitives.LowBatteryRun", \
    1U, \
    1U, \
    &P_EVENTSET_LowBatteryRun_DEFERS, \
    &P_EVENTSET_LowBatteryRun_TRANS, \
    &P_EVENTSET_LowBatteryRun_DOS, \
    P_TRANS_1, \
    P_DOS_3, \
    &P_FUNCTION_Anon_13, \
    &_P_NO_OP, \
    &P_FUNCTION_Anon_14, \
    0, \
}

PRT_STATEDECL P_MotionPrimitives_STATES[] = { P_STATE_MotionPrimitives_Init, P_STATE_MotionPrimitives_Run, P_STATE_MotionPrimitives_LowBatteryRun };

PRT_VALUE* P_DM_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_r);
    PRT_VALUE* P_VAR_temp = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_isBumperReleasedLeft = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_isBumperReleasedRight = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_isCliffLeft = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_isCliffRight = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_isCliffCenter = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* PTMP_tmp0_10 = NULL;
    PRT_VALUE* PTMP_tmp1_10 = NULL;
    PRT_VALUE* PTMP_tmp2_10 = NULL;
    PRT_VALUE* PTMP_tmp3_10 = NULL;
    PRT_VALUE* PTMP_tmp4_10 = NULL;
    PRT_VALUE* PTMP_tmp5_10 = NULL;
    PRT_VALUE* PTMP_tmp6_10 = NULL;
    PRT_VALUE* PTMP_tmp7_9 = NULL;
    PRT_VALUE* PTMP_tmp8_6 = NULL;
    PRT_VALUE* PTMP_tmp9_6 = NULL;
    PRT_VALUE* PTMP_tmp10_6 = NULL;
    PRT_VALUE* PTMP_tmp11_6 = NULL;
    PRT_VALUE* PTMP_tmp12_3 = NULL;
    PRT_VALUE* PTMP_tmp13_3 = NULL;
    PRT_VALUE* PTMP_tmp14_3 = NULL;
    PRT_VALUE* PTMP_tmp15_2 = NULL;
    PRT_VALUE* PTMP_tmp16_2 = NULL;
    PRT_VALUE* PTMP_tmp17_2 = NULL;
    PRT_VALUE* PTMP_tmp18_2 = NULL;
    PRT_VALUE* PTMP_tmp19_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_246 = &(PTMP_tmp0_10);
    PrtFreeValue(*P_LVALUE_246);
    *P_LVALUE_246 = ((_P_GEN_funval = P_GetIsBumperReleasedLeft_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    
    {
        PRT_VALUE** P_LVALUE_247 = &(P_VAR_isBumperReleasedLeft);
        PrtFreeValue(*P_LVALUE_247);
        *P_LVALUE_247 = PTMP_tmp0_10;
        PTMP_tmp0_10 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_248 = &(PTMP_tmp1_10);
    PrtFreeValue(*P_LVALUE_248);
    *P_LVALUE_248 = ((_P_GEN_funval = P_GetIsBumperReleasedRight_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    
    {
        PRT_VALUE** P_LVALUE_249 = &(P_VAR_isBumperReleasedRight);
        PrtFreeValue(*P_LVALUE_249);
        *P_LVALUE_249 = PTMP_tmp1_10;
        PTMP_tmp1_10 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_250 = &(PTMP_tmp2_10);
    PrtFreeValue(*P_LVALUE_250);
    *P_LVALUE_250 = ((_P_GEN_funval = P_GetIsCliffLeft_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    
    {
        PRT_VALUE** P_LVALUE_251 = &(P_VAR_isCliffLeft);
        PrtFreeValue(*P_LVALUE_251);
        *P_LVALUE_251 = PTMP_tmp2_10;
        PTMP_tmp2_10 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_252 = &(PTMP_tmp3_10);
    PrtFreeValue(*P_LVALUE_252);
    *P_LVALUE_252 = ((_P_GEN_funval = P_GetIsCliffRight_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    
    {
        PRT_VALUE** P_LVALUE_253 = &(P_VAR_isCliffRight);
        PrtFreeValue(*P_LVALUE_253);
        *P_LVALUE_253 = PTMP_tmp3_10;
        PTMP_tmp3_10 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_254 = &(PTMP_tmp4_10);
    PrtFreeValue(*P_LVALUE_254);
    *P_LVALUE_254 = ((_P_GEN_funval = P_GetIsCliffCenter_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    
    {
        PRT_VALUE** P_LVALUE_255 = &(P_VAR_isCliffCenter);
        PrtFreeValue(*P_LVALUE_255);
        *P_LVALUE_255 = PTMP_tmp4_10;
        PTMP_tmp4_10 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_256 = &(PTMP_tmp5_10);
    PrtFreeValue(*P_LVALUE_256);
    *P_LVALUE_256 = PrtMkBoolValue(!PrtPrimGetBool(P_VAR_isBumperReleasedLeft));
    
    if (PrtPrimGetBool(PTMP_tmp5_10))
    {
        PRT_VALUE** P_LVALUE_257 = &(PTMP_tmp6_10);
        PrtFreeValue(*P_LVALUE_257);
        *P_LVALUE_257 = PrtMkStringValue(PrtFormatString("LeftObstacleAvoidanceController", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp6_10);
        goto p_return_15;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_258 = &(PTMP_tmp7_9);
    PrtFreeValue(*P_LVALUE_258);
    *P_LVALUE_258 = PrtMkBoolValue(!PrtPrimGetBool(P_VAR_isBumperReleasedRight));
    
    if (PrtPrimGetBool(PTMP_tmp7_9))
    {
        PRT_VALUE** P_LVALUE_259 = &(PTMP_tmp8_6);
        PrtFreeValue(*P_LVALUE_259);
        *P_LVALUE_259 = PrtMkStringValue(PrtFormatString("RightObstacleAvoidanceController", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp8_6);
        goto p_return_15;
        
    }
    
    else
    {
    }
    
    
    if (PrtPrimGetBool(P_VAR_isCliffLeft))
    {
        PRT_VALUE** P_LVALUE_260 = &(PTMP_tmp9_6);
        PrtFreeValue(*P_LVALUE_260);
        *P_LVALUE_260 = PrtMkStringValue(PrtFormatString("LeftCliffAvoidanceController", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp9_6);
        goto p_return_15;
        
    }
    
    else
    {
    }
    
    
    if (PrtPrimGetBool(P_VAR_isCliffRight))
    {
        PRT_VALUE** P_LVALUE_261 = &(PTMP_tmp10_6);
        PrtFreeValue(*P_LVALUE_261);
        *P_LVALUE_261 = PrtMkStringValue(PrtFormatString("RightCliffAvoidanceController", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp10_6);
        goto p_return_15;
        
    }
    
    else
    {
    }
    
    
    if (PrtPrimGetBool(P_VAR_isCliffCenter))
    {
        PRT_VALUE** P_LVALUE_262 = &(PTMP_tmp11_6);
        PrtFreeValue(*P_LVALUE_262);
        *P_LVALUE_262 = PrtMkStringValue(PrtFormatString("CenterCliffAvoidanceController", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp11_6);
        goto p_return_15;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_263 = &(PTMP_tmp12_3);
    PrtFreeValue(*P_LVALUE_263);
    *P_LVALUE_263 = PrtTupleGet(p_this->varValues[6], 0);
    
    PRT_VALUE** P_LVALUE_264 = &(PTMP_tmp13_3);
    PrtFreeValue(*P_LVALUE_264);
    *P_LVALUE_264 = PrtTupleGet(p_this->varValues[6], 1);
    
    PRT_VALUE** P_LVALUE_265 = &(PTMP_tmp14_3);
    PrtFreeValue(*P_LVALUE_265);
    *P_LVALUE_265 = PrtTupleGet(p_this->varValues[7], 0);
    
    PRT_VALUE** P_LVALUE_266 = &(PTMP_tmp15_2);
    PrtFreeValue(*P_LVALUE_266);
    *P_LVALUE_266 = PrtTupleGet(p_this->varValues[7], 1);
    
    PRT_VALUE** P_LVALUE_267 = &(PTMP_tmp16_2);
    PrtFreeValue(*P_LVALUE_267);
    *P_LVALUE_267 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_268 = &(PTMP_tmp17_2);
    PrtFreeValue(*P_LVALUE_268);
    *P_LVALUE_268 = ((_P_GEN_funargs[0] = &(PTMP_tmp12_3)), (_P_GEN_funargs[1] = &(PTMP_tmp13_3)), (_P_GEN_funargs[2] = &(PTMP_tmp14_3)), (_P_GEN_funargs[3] = &(PTMP_tmp15_2)), (_P_GEN_funargs[4] = &(PTMP_tmp16_2)), (_P_GEN_funval = P_IsInTrajectory_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp12_3), PTMP_tmp12_3 = NULL), (PrtFreeValue(PTMP_tmp13_3), PTMP_tmp13_3 = NULL), (PrtFreeValue(PTMP_tmp14_3), PTMP_tmp14_3 = NULL), (PrtFreeValue(PTMP_tmp15_2), PTMP_tmp15_2 = NULL), (PrtFreeValue(PTMP_tmp16_2), PTMP_tmp16_2 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_15;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_15;
    }
    
    {
        PRT_VALUE** P_LVALUE_269 = &(P_VAR_temp);
        PrtFreeValue(*P_LVALUE_269);
        *P_LVALUE_269 = PTMP_tmp17_2;
        PTMP_tmp17_2 = NULL;
    }
    
    if (PrtPrimGetBool(P_VAR_temp))
    {
        PRT_VALUE** P_LVALUE_270 = &(PTMP_tmp18_2);
        PrtFreeValue(*P_LVALUE_270);
        *P_LVALUE_270 = PrtMkStringValue(PrtFormatString("AdvancedMotionController", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp18_2);
        goto p_return_15;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_271 = &(PTMP_tmp19_2);
    PrtFreeValue(*P_LVALUE_271);
    *P_LVALUE_271 = PrtMkStringValue(PrtFormatString("SafeMotionController", 0, 0));
    ;
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(PTMP_tmp19_2);
    goto p_return_15;
    
p_return_15: ;
    PrtFreeValue(P_VAR_temp); P_VAR_temp = NULL;
    PrtFreeValue(P_VAR_isBumperReleasedLeft); P_VAR_isBumperReleasedLeft = NULL;
    PrtFreeValue(P_VAR_isBumperReleasedRight); P_VAR_isBumperReleasedRight = NULL;
    PrtFreeValue(P_VAR_isCliffLeft); P_VAR_isCliffLeft = NULL;
    PrtFreeValue(P_VAR_isCliffRight); P_VAR_isCliffRight = NULL;
    PrtFreeValue(P_VAR_isCliffCenter); P_VAR_isCliffCenter = NULL;
    PrtFreeValue(PTMP_tmp0_10); PTMP_tmp0_10 = NULL;
    PrtFreeValue(PTMP_tmp1_10); PTMP_tmp1_10 = NULL;
    PrtFreeValue(PTMP_tmp2_10); PTMP_tmp2_10 = NULL;
    PrtFreeValue(PTMP_tmp3_10); PTMP_tmp3_10 = NULL;
    PrtFreeValue(PTMP_tmp4_10); PTMP_tmp4_10 = NULL;
    PrtFreeValue(PTMP_tmp5_10); PTMP_tmp5_10 = NULL;
    PrtFreeValue(PTMP_tmp6_10); PTMP_tmp6_10 = NULL;
    PrtFreeValue(PTMP_tmp7_9); PTMP_tmp7_9 = NULL;
    PrtFreeValue(PTMP_tmp8_6); PTMP_tmp8_6 = NULL;
    PrtFreeValue(PTMP_tmp9_6); PTMP_tmp9_6 = NULL;
    PrtFreeValue(PTMP_tmp10_6); PTMP_tmp10_6 = NULL;
    PrtFreeValue(PTMP_tmp11_6); PTMP_tmp11_6 = NULL;
    PrtFreeValue(PTMP_tmp12_3); PTMP_tmp12_3 = NULL;
    PrtFreeValue(PTMP_tmp13_3); PTMP_tmp13_3 = NULL;
    PrtFreeValue(PTMP_tmp14_3); PTMP_tmp14_3 = NULL;
    PrtFreeValue(PTMP_tmp15_2); PTMP_tmp15_2 = NULL;
    PrtFreeValue(PTMP_tmp16_2); PTMP_tmp16_2 = NULL;
    PrtFreeValue(PTMP_tmp17_2); PTMP_tmp17_2 = NULL;
    PrtFreeValue(PTMP_tmp18_2); PTMP_tmp18_2 = NULL;
    PrtFreeValue(PTMP_tmp19_2); PTMP_tmp19_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_DM_2 =
{
    "DM",
    &P_DM_IMPL_2,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_LeftObstacleAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_isBumperReleasedLeft_1 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_forwardSpeed = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* P_VAR_rotationSpeed = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* PTMP_tmp0_11 = NULL;
    PRT_VALUE* PTMP_tmp1_11 = NULL;
    PRT_VALUE* PTMP_tmp2_11 = NULL;
    PRT_VALUE* PTMP_tmp3_11 = NULL;
    PRT_VALUE* PTMP_tmp4_11 = NULL;
    PRT_VALUE* PTMP_tmp5_11 = NULL;
    PRT_VALUE* PTMP_tmp6_11 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_14 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_15 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_16 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_DOUBLE_6 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.2 } };
    PRT_VALUE P_LIT_DOUBLE_7 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.8 } };
    PRT_VALUE** P_LVALUE_272 = &(P_VAR_forwardSpeed);
    PrtFreeValue(*P_LVALUE_272);
    *P_LVALUE_272 = PrtCloneValue((&P_LIT_DOUBLE_6));
    
    PRT_VALUE** P_LVALUE_273 = &(P_VAR_rotationSpeed);
    PrtFreeValue(*P_LVALUE_273);
    *P_LVALUE_273 = PrtCloneValue((&P_LIT_DOUBLE_7));
    
    PRT_VALUE** P_LVALUE_274 = &(PTMP_tmp0_11);
    PrtFreeValue(*P_LVALUE_274);
    *P_LVALUE_274 = ((_P_GEN_funval = P_GetIsBumperReleasedLeft_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_16;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_16;
    }
    
    {
        PRT_VALUE** P_LVALUE_275 = &(P_VAR_isBumperReleasedLeft_1);
        PrtFreeValue(*P_LVALUE_275);
        *P_LVALUE_275 = PTMP_tmp0_11;
        PTMP_tmp0_11 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_276 = &(PTMP_tmp2_11);
    PrtFreeValue(*P_LVALUE_276);
    *P_LVALUE_276 = PrtCloneValue(P_VAR_isBumperReleasedLeft_1);
    
    if (PrtPrimGetBool(PTMP_tmp2_11))
    {
        PRT_VALUE** P_LVALUE_277 = &(PTMP_tmp1_11);
        PrtFreeValue(*P_LVALUE_277);
        *P_LVALUE_277 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[12]) >= PrtPrimGetInt((&P_LIT_INT32_14)));
        
        PRT_VALUE** P_LVALUE_278 = &(PTMP_tmp2_11);
        PrtFreeValue(*P_LVALUE_278);
        *P_LVALUE_278 = PrtCloneValue(PTMP_tmp1_11);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp2_11))
    {
        PRT_VALUE** P_LVALUE_279 = &(PTMP_tmp3_11);
        PrtFreeValue(*P_LVALUE_279);
        *P_LVALUE_279 = PrtCloneValue(P_VAR_forwardSpeed);
        
        _P_GEN_funargs[0] = &(PTMP_tmp3_11);
        PrtFreeValue(P_MoveForward_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp3_11);
        PTMP_tmp3_11 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_16;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_16;
        }
        
    }
    
    else
    {
        if (PrtPrimGetBool(P_VAR_isBumperReleasedLeft_1))
        {
            PRT_VALUE** P_LVALUE_280 = &(PTMP_tmp4_11);
            PrtFreeValue(*P_LVALUE_280);
            *P_LVALUE_280 = PrtCloneValue(P_VAR_rotationSpeed);
            
            _P_GEN_funargs[0] = &(PTMP_tmp4_11);
            PrtFreeValue(P_RotateRight_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp4_11);
            PTMP_tmp4_11 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_16;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_16;
            }
            
            PRT_VALUE** P_LVALUE_281 = &(PTMP_tmp5_11);
            PrtFreeValue(*P_LVALUE_281);
            *P_LVALUE_281 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[12]) + PrtPrimGetInt((&P_LIT_INT32_15)));
            
            {
                PRT_VALUE** P_LVALUE_282 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_282);
                *P_LVALUE_282 = PTMP_tmp5_11;
                PTMP_tmp5_11 = NULL;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_283 = &(PTMP_tmp6_11);
            PrtFreeValue(*P_LVALUE_283);
            *P_LVALUE_283 = PrtCloneValue(P_VAR_forwardSpeed);
            
            _P_GEN_funargs[0] = &(PTMP_tmp6_11);
            PrtFreeValue(P_MoveBackward_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp6_11);
            PTMP_tmp6_11 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_16;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_16;
            }
            
            PRT_VALUE** P_LVALUE_284 = &(p_this->varValues[12]);
            PrtFreeValue(*P_LVALUE_284);
            *P_LVALUE_284 = PrtCloneValue((&P_LIT_INT32_16));
            
        }
        
        
    }
    
    
p_return_16: ;
    PrtFreeValue(P_VAR_isBumperReleasedLeft_1); P_VAR_isBumperReleasedLeft_1 = NULL;
    PrtFreeValue(P_VAR_forwardSpeed); P_VAR_forwardSpeed = NULL;
    PrtFreeValue(P_VAR_rotationSpeed); P_VAR_rotationSpeed = NULL;
    PrtFreeValue(PTMP_tmp0_11); PTMP_tmp0_11 = NULL;
    PrtFreeValue(PTMP_tmp1_11); PTMP_tmp1_11 = NULL;
    PrtFreeValue(PTMP_tmp2_11); PTMP_tmp2_11 = NULL;
    PrtFreeValue(PTMP_tmp3_11); PTMP_tmp3_11 = NULL;
    PrtFreeValue(PTMP_tmp4_11); PTMP_tmp4_11 = NULL;
    PrtFreeValue(PTMP_tmp5_11); PTMP_tmp5_11 = NULL;
    PrtFreeValue(PTMP_tmp6_11); PTMP_tmp6_11 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_LeftObstacleAvoidanceController =
{
    "LeftObstacleAvoidanceController",
    &P_LeftObstacleAvoidanceController_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_RightObstacleAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_isBumperReleasedRight_1 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_forwardSpeed_1 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* P_VAR_rotationSpeed_1 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* PTMP_tmp0_12 = NULL;
    PRT_VALUE* PTMP_tmp1_12 = NULL;
    PRT_VALUE* PTMP_tmp2_12 = NULL;
    PRT_VALUE* PTMP_tmp3_12 = NULL;
    PRT_VALUE* PTMP_tmp4_12 = NULL;
    PRT_VALUE* PTMP_tmp5_12 = NULL;
    PRT_VALUE* PTMP_tmp6_12 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_17 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_18 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_19 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_DOUBLE_8 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.2 } };
    PRT_VALUE P_LIT_DOUBLE_9 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.8 } };
    PRT_VALUE** P_LVALUE_285 = &(P_VAR_forwardSpeed_1);
    PrtFreeValue(*P_LVALUE_285);
    *P_LVALUE_285 = PrtCloneValue((&P_LIT_DOUBLE_8));
    
    PRT_VALUE** P_LVALUE_286 = &(P_VAR_rotationSpeed_1);
    PrtFreeValue(*P_LVALUE_286);
    *P_LVALUE_286 = PrtCloneValue((&P_LIT_DOUBLE_9));
    
    PRT_VALUE** P_LVALUE_287 = &(PTMP_tmp0_12);
    PrtFreeValue(*P_LVALUE_287);
    *P_LVALUE_287 = ((_P_GEN_funval = P_GetIsBumperReleasedRight_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_17;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_17;
    }
    
    {
        PRT_VALUE** P_LVALUE_288 = &(P_VAR_isBumperReleasedRight_1);
        PrtFreeValue(*P_LVALUE_288);
        *P_LVALUE_288 = PTMP_tmp0_12;
        PTMP_tmp0_12 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_289 = &(PTMP_tmp2_12);
    PrtFreeValue(*P_LVALUE_289);
    *P_LVALUE_289 = PrtCloneValue(P_VAR_isBumperReleasedRight_1);
    
    if (PrtPrimGetBool(PTMP_tmp2_12))
    {
        PRT_VALUE** P_LVALUE_290 = &(PTMP_tmp1_12);
        PrtFreeValue(*P_LVALUE_290);
        *P_LVALUE_290 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[12]) >= PrtPrimGetInt((&P_LIT_INT32_17)));
        
        PRT_VALUE** P_LVALUE_291 = &(PTMP_tmp2_12);
        PrtFreeValue(*P_LVALUE_291);
        *P_LVALUE_291 = PrtCloneValue(PTMP_tmp1_12);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp2_12))
    {
        PRT_VALUE** P_LVALUE_292 = &(PTMP_tmp3_12);
        PrtFreeValue(*P_LVALUE_292);
        *P_LVALUE_292 = PrtCloneValue(P_VAR_forwardSpeed_1);
        
        _P_GEN_funargs[0] = &(PTMP_tmp3_12);
        PrtFreeValue(P_MoveForward_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp3_12);
        PTMP_tmp3_12 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_17;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_17;
        }
        
    }
    
    else
    {
        if (PrtPrimGetBool(P_VAR_isBumperReleasedRight_1))
        {
            PRT_VALUE** P_LVALUE_293 = &(PTMP_tmp4_12);
            PrtFreeValue(*P_LVALUE_293);
            *P_LVALUE_293 = PrtCloneValue(P_VAR_rotationSpeed_1);
            
            _P_GEN_funargs[0] = &(PTMP_tmp4_12);
            PrtFreeValue(P_RotateLeft_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp4_12);
            PTMP_tmp4_12 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_17;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_17;
            }
            
            PRT_VALUE** P_LVALUE_294 = &(PTMP_tmp5_12);
            PrtFreeValue(*P_LVALUE_294);
            *P_LVALUE_294 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[12]) + PrtPrimGetInt((&P_LIT_INT32_18)));
            
            {
                PRT_VALUE** P_LVALUE_295 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_295);
                *P_LVALUE_295 = PTMP_tmp5_12;
                PTMP_tmp5_12 = NULL;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_296 = &(PTMP_tmp6_12);
            PrtFreeValue(*P_LVALUE_296);
            *P_LVALUE_296 = PrtCloneValue(P_VAR_forwardSpeed_1);
            
            _P_GEN_funargs[0] = &(PTMP_tmp6_12);
            PrtFreeValue(P_MoveBackward_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp6_12);
            PTMP_tmp6_12 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_17;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_17;
            }
            
            PRT_VALUE** P_LVALUE_297 = &(p_this->varValues[12]);
            PrtFreeValue(*P_LVALUE_297);
            *P_LVALUE_297 = PrtCloneValue((&P_LIT_INT32_19));
            
        }
        
        
    }
    
    
p_return_17: ;
    PrtFreeValue(P_VAR_isBumperReleasedRight_1); P_VAR_isBumperReleasedRight_1 = NULL;
    PrtFreeValue(P_VAR_forwardSpeed_1); P_VAR_forwardSpeed_1 = NULL;
    PrtFreeValue(P_VAR_rotationSpeed_1); P_VAR_rotationSpeed_1 = NULL;
    PrtFreeValue(PTMP_tmp0_12); PTMP_tmp0_12 = NULL;
    PrtFreeValue(PTMP_tmp1_12); PTMP_tmp1_12 = NULL;
    PrtFreeValue(PTMP_tmp2_12); PTMP_tmp2_12 = NULL;
    PrtFreeValue(PTMP_tmp3_12); PTMP_tmp3_12 = NULL;
    PrtFreeValue(PTMP_tmp4_12); PTMP_tmp4_12 = NULL;
    PrtFreeValue(PTMP_tmp5_12); PTMP_tmp5_12 = NULL;
    PrtFreeValue(PTMP_tmp6_12); PTMP_tmp6_12 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_RightObstacleAvoidanceController =
{
    "RightObstacleAvoidanceController",
    &P_RightObstacleAvoidanceController_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_LeftCliffAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_isCliffLeft_1 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_forwardSpeed_2 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* P_VAR_rotationSpeed_2 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* PTMP_tmp0_13 = NULL;
    PRT_VALUE* PTMP_tmp1_13 = NULL;
    PRT_VALUE* PTMP_tmp2_13 = NULL;
    PRT_VALUE* PTMP_tmp3_13 = NULL;
    PRT_VALUE* PTMP_tmp4_13 = NULL;
    PRT_VALUE* PTMP_tmp5_13 = NULL;
    PRT_VALUE* PTMP_tmp6_13 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_20 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_21 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_22 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_DOUBLE_10 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.2 } };
    PRT_VALUE P_LIT_DOUBLE_11 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.8 } };
    PRT_VALUE** P_LVALUE_298 = &(P_VAR_forwardSpeed_2);
    PrtFreeValue(*P_LVALUE_298);
    *P_LVALUE_298 = PrtCloneValue((&P_LIT_DOUBLE_10));
    
    PRT_VALUE** P_LVALUE_299 = &(P_VAR_rotationSpeed_2);
    PrtFreeValue(*P_LVALUE_299);
    *P_LVALUE_299 = PrtCloneValue((&P_LIT_DOUBLE_11));
    
    PRT_VALUE** P_LVALUE_300 = &(PTMP_tmp0_13);
    PrtFreeValue(*P_LVALUE_300);
    *P_LVALUE_300 = ((_P_GEN_funval = P_GetIsCliffLeft_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_18;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_18;
    }
    
    {
        PRT_VALUE** P_LVALUE_301 = &(P_VAR_isCliffLeft_1);
        PrtFreeValue(*P_LVALUE_301);
        *P_LVALUE_301 = PTMP_tmp0_13;
        PTMP_tmp0_13 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_302 = &(PTMP_tmp1_13);
    PrtFreeValue(*P_LVALUE_302);
    *P_LVALUE_302 = PrtMkBoolValue(!PrtPrimGetBool(P_VAR_isCliffLeft_1));
    
    if (PrtPrimGetBool(PTMP_tmp1_13))
    {
        PRT_VALUE** P_LVALUE_303 = &(PTMP_tmp2_13);
        PrtFreeValue(*P_LVALUE_303);
        *P_LVALUE_303 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[12]) >= PrtPrimGetInt((&P_LIT_INT32_20)));
        
        if (PrtPrimGetBool(PTMP_tmp2_13))
        {
            PRT_VALUE** P_LVALUE_304 = &(PTMP_tmp3_13);
            PrtFreeValue(*P_LVALUE_304);
            *P_LVALUE_304 = PrtCloneValue(P_VAR_forwardSpeed_2);
            
            _P_GEN_funargs[0] = &(PTMP_tmp3_13);
            PrtFreeValue(P_MoveForward_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp3_13);
            PTMP_tmp3_13 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_18;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_18;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_305 = &(PTMP_tmp4_13);
            PrtFreeValue(*P_LVALUE_305);
            *P_LVALUE_305 = PrtCloneValue(P_VAR_rotationSpeed_2);
            
            _P_GEN_funargs[0] = &(PTMP_tmp4_13);
            PrtFreeValue(P_RotateRight_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp4_13);
            PTMP_tmp4_13 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_18;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_18;
            }
            
            PRT_VALUE** P_LVALUE_306 = &(PTMP_tmp5_13);
            PrtFreeValue(*P_LVALUE_306);
            *P_LVALUE_306 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[12]) + PrtPrimGetInt((&P_LIT_INT32_21)));
            
            {
                PRT_VALUE** P_LVALUE_307 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_307);
                *P_LVALUE_307 = PTMP_tmp5_13;
                PTMP_tmp5_13 = NULL;
            }
            
        }
        
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_308 = &(PTMP_tmp6_13);
        PrtFreeValue(*P_LVALUE_308);
        *P_LVALUE_308 = PrtCloneValue(P_VAR_forwardSpeed_2);
        
        _P_GEN_funargs[0] = &(PTMP_tmp6_13);
        PrtFreeValue(P_MoveBackward_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp6_13);
        PTMP_tmp6_13 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_18;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_18;
        }
        
        PRT_VALUE** P_LVALUE_309 = &(p_this->varValues[12]);
        PrtFreeValue(*P_LVALUE_309);
        *P_LVALUE_309 = PrtCloneValue((&P_LIT_INT32_22));
        
    }
    
    
p_return_18: ;
    PrtFreeValue(P_VAR_isCliffLeft_1); P_VAR_isCliffLeft_1 = NULL;
    PrtFreeValue(P_VAR_forwardSpeed_2); P_VAR_forwardSpeed_2 = NULL;
    PrtFreeValue(P_VAR_rotationSpeed_2); P_VAR_rotationSpeed_2 = NULL;
    PrtFreeValue(PTMP_tmp0_13); PTMP_tmp0_13 = NULL;
    PrtFreeValue(PTMP_tmp1_13); PTMP_tmp1_13 = NULL;
    PrtFreeValue(PTMP_tmp2_13); PTMP_tmp2_13 = NULL;
    PrtFreeValue(PTMP_tmp3_13); PTMP_tmp3_13 = NULL;
    PrtFreeValue(PTMP_tmp4_13); PTMP_tmp4_13 = NULL;
    PrtFreeValue(PTMP_tmp5_13); PTMP_tmp5_13 = NULL;
    PrtFreeValue(PTMP_tmp6_13); PTMP_tmp6_13 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_LeftCliffAvoidanceController =
{
    "LeftCliffAvoidanceController",
    &P_LeftCliffAvoidanceController_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_RightCliffAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_isCliffLeft_2 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_forwardSpeed_3 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* P_VAR_rotationSpeed_3 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* PTMP_tmp0_14 = NULL;
    PRT_VALUE* PTMP_tmp1_14 = NULL;
    PRT_VALUE* PTMP_tmp2_14 = NULL;
    PRT_VALUE* PTMP_tmp3_14 = NULL;
    PRT_VALUE* PTMP_tmp4_14 = NULL;
    PRT_VALUE* PTMP_tmp5_14 = NULL;
    PRT_VALUE* PTMP_tmp6_14 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_23 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_24 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_25 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_DOUBLE_12 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.2 } };
    PRT_VALUE P_LIT_DOUBLE_13 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.8 } };
    PRT_VALUE** P_LVALUE_310 = &(P_VAR_forwardSpeed_3);
    PrtFreeValue(*P_LVALUE_310);
    *P_LVALUE_310 = PrtCloneValue((&P_LIT_DOUBLE_12));
    
    PRT_VALUE** P_LVALUE_311 = &(P_VAR_rotationSpeed_3);
    PrtFreeValue(*P_LVALUE_311);
    *P_LVALUE_311 = PrtCloneValue((&P_LIT_DOUBLE_13));
    
    PRT_VALUE** P_LVALUE_312 = &(PTMP_tmp0_14);
    PrtFreeValue(*P_LVALUE_312);
    *P_LVALUE_312 = ((_P_GEN_funval = P_GetIsCliffRight_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_19;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_19;
    }
    
    {
        PRT_VALUE** P_LVALUE_313 = &(P_VAR_isCliffLeft_2);
        PrtFreeValue(*P_LVALUE_313);
        *P_LVALUE_313 = PTMP_tmp0_14;
        PTMP_tmp0_14 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_314 = &(PTMP_tmp1_14);
    PrtFreeValue(*P_LVALUE_314);
    *P_LVALUE_314 = PrtMkBoolValue(!PrtPrimGetBool(P_VAR_isCliffLeft_2));
    
    if (PrtPrimGetBool(PTMP_tmp1_14))
    {
        PRT_VALUE** P_LVALUE_315 = &(PTMP_tmp2_14);
        PrtFreeValue(*P_LVALUE_315);
        *P_LVALUE_315 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[12]) >= PrtPrimGetInt((&P_LIT_INT32_23)));
        
        if (PrtPrimGetBool(PTMP_tmp2_14))
        {
            PRT_VALUE** P_LVALUE_316 = &(PTMP_tmp3_14);
            PrtFreeValue(*P_LVALUE_316);
            *P_LVALUE_316 = PrtCloneValue(P_VAR_forwardSpeed_3);
            
            _P_GEN_funargs[0] = &(PTMP_tmp3_14);
            PrtFreeValue(P_MoveForward_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp3_14);
            PTMP_tmp3_14 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_19;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_19;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_317 = &(PTMP_tmp4_14);
            PrtFreeValue(*P_LVALUE_317);
            *P_LVALUE_317 = PrtCloneValue(P_VAR_rotationSpeed_3);
            
            _P_GEN_funargs[0] = &(PTMP_tmp4_14);
            PrtFreeValue(P_RotateLeft_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp4_14);
            PTMP_tmp4_14 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_19;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_19;
            }
            
            PRT_VALUE** P_LVALUE_318 = &(PTMP_tmp5_14);
            PrtFreeValue(*P_LVALUE_318);
            *P_LVALUE_318 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[12]) + PrtPrimGetInt((&P_LIT_INT32_24)));
            
            {
                PRT_VALUE** P_LVALUE_319 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_319);
                *P_LVALUE_319 = PTMP_tmp5_14;
                PTMP_tmp5_14 = NULL;
            }
            
        }
        
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_320 = &(PTMP_tmp6_14);
        PrtFreeValue(*P_LVALUE_320);
        *P_LVALUE_320 = PrtCloneValue(P_VAR_forwardSpeed_3);
        
        _P_GEN_funargs[0] = &(PTMP_tmp6_14);
        PrtFreeValue(P_MoveBackward_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp6_14);
        PTMP_tmp6_14 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_19;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_19;
        }
        
        PRT_VALUE** P_LVALUE_321 = &(p_this->varValues[12]);
        PrtFreeValue(*P_LVALUE_321);
        *P_LVALUE_321 = PrtCloneValue((&P_LIT_INT32_25));
        
    }
    
    
p_return_19: ;
    PrtFreeValue(P_VAR_isCliffLeft_2); P_VAR_isCliffLeft_2 = NULL;
    PrtFreeValue(P_VAR_forwardSpeed_3); P_VAR_forwardSpeed_3 = NULL;
    PrtFreeValue(P_VAR_rotationSpeed_3); P_VAR_rotationSpeed_3 = NULL;
    PrtFreeValue(PTMP_tmp0_14); PTMP_tmp0_14 = NULL;
    PrtFreeValue(PTMP_tmp1_14); PTMP_tmp1_14 = NULL;
    PrtFreeValue(PTMP_tmp2_14); PTMP_tmp2_14 = NULL;
    PrtFreeValue(PTMP_tmp3_14); PTMP_tmp3_14 = NULL;
    PrtFreeValue(PTMP_tmp4_14); PTMP_tmp4_14 = NULL;
    PrtFreeValue(PTMP_tmp5_14); PTMP_tmp5_14 = NULL;
    PrtFreeValue(PTMP_tmp6_14); PTMP_tmp6_14 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_RightCliffAvoidanceController =
{
    "RightCliffAvoidanceController",
    &P_RightCliffAvoidanceController_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_CenterCliffAvoidanceController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_isCliffLeft_3 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_forwardSpeed_4 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* P_VAR_rotationSpeed_4 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* PTMP_tmp0_15 = NULL;
    PRT_VALUE* PTMP_tmp1_15 = NULL;
    PRT_VALUE* PTMP_tmp2_15 = NULL;
    PRT_VALUE* PTMP_tmp3_15 = NULL;
    PRT_VALUE* PTMP_tmp4_15 = NULL;
    PRT_VALUE* PTMP_tmp5_15 = NULL;
    PRT_VALUE* PTMP_tmp6_15 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_26 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_27 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_28 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_DOUBLE_14 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.2 } };
    PRT_VALUE P_LIT_DOUBLE_15 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.8 } };
    PRT_VALUE** P_LVALUE_322 = &(P_VAR_forwardSpeed_4);
    PrtFreeValue(*P_LVALUE_322);
    *P_LVALUE_322 = PrtCloneValue((&P_LIT_DOUBLE_14));
    
    PRT_VALUE** P_LVALUE_323 = &(P_VAR_rotationSpeed_4);
    PrtFreeValue(*P_LVALUE_323);
    *P_LVALUE_323 = PrtCloneValue((&P_LIT_DOUBLE_15));
    
    PRT_VALUE** P_LVALUE_324 = &(PTMP_tmp0_15);
    PrtFreeValue(*P_LVALUE_324);
    *P_LVALUE_324 = ((_P_GEN_funval = P_GetIsCliffCenter_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_20;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_20;
    }
    
    {
        PRT_VALUE** P_LVALUE_325 = &(P_VAR_isCliffLeft_3);
        PrtFreeValue(*P_LVALUE_325);
        *P_LVALUE_325 = PTMP_tmp0_15;
        PTMP_tmp0_15 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_326 = &(PTMP_tmp1_15);
    PrtFreeValue(*P_LVALUE_326);
    *P_LVALUE_326 = PrtMkBoolValue(!PrtPrimGetBool(P_VAR_isCliffLeft_3));
    
    if (PrtPrimGetBool(PTMP_tmp1_15))
    {
        PRT_VALUE** P_LVALUE_327 = &(PTMP_tmp2_15);
        PrtFreeValue(*P_LVALUE_327);
        *P_LVALUE_327 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[12]) >= PrtPrimGetInt((&P_LIT_INT32_26)));
        
        if (PrtPrimGetBool(PTMP_tmp2_15))
        {
            PRT_VALUE** P_LVALUE_328 = &(PTMP_tmp3_15);
            PrtFreeValue(*P_LVALUE_328);
            *P_LVALUE_328 = PrtCloneValue(P_VAR_forwardSpeed_4);
            
            _P_GEN_funargs[0] = &(PTMP_tmp3_15);
            PrtFreeValue(P_MoveForward_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp3_15);
            PTMP_tmp3_15 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_20;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_20;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_329 = &(PTMP_tmp4_15);
            PrtFreeValue(*P_LVALUE_329);
            *P_LVALUE_329 = PrtCloneValue(P_VAR_rotationSpeed_4);
            
            _P_GEN_funargs[0] = &(PTMP_tmp4_15);
            PrtFreeValue(P_RotateLeft_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp4_15);
            PTMP_tmp4_15 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_20;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_20;
            }
            
            PRT_VALUE** P_LVALUE_330 = &(PTMP_tmp5_15);
            PrtFreeValue(*P_LVALUE_330);
            *P_LVALUE_330 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[12]) + PrtPrimGetInt((&P_LIT_INT32_27)));
            
            {
                PRT_VALUE** P_LVALUE_331 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_331);
                *P_LVALUE_331 = PTMP_tmp5_15;
                PTMP_tmp5_15 = NULL;
            }
            
        }
        
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_332 = &(PTMP_tmp6_15);
        PrtFreeValue(*P_LVALUE_332);
        *P_LVALUE_332 = PrtCloneValue(P_VAR_forwardSpeed_4);
        
        _P_GEN_funargs[0] = &(PTMP_tmp6_15);
        PrtFreeValue(P_MoveBackward_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp6_15);
        PTMP_tmp6_15 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_20;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_20;
        }
        
        PRT_VALUE** P_LVALUE_333 = &(p_this->varValues[12]);
        PrtFreeValue(*P_LVALUE_333);
        *P_LVALUE_333 = PrtCloneValue((&P_LIT_INT32_28));
        
    }
    
    
p_return_20: ;
    PrtFreeValue(P_VAR_isCliffLeft_3); P_VAR_isCliffLeft_3 = NULL;
    PrtFreeValue(P_VAR_forwardSpeed_4); P_VAR_forwardSpeed_4 = NULL;
    PrtFreeValue(P_VAR_rotationSpeed_4); P_VAR_rotationSpeed_4 = NULL;
    PrtFreeValue(PTMP_tmp0_15); PTMP_tmp0_15 = NULL;
    PrtFreeValue(PTMP_tmp1_15); PTMP_tmp1_15 = NULL;
    PrtFreeValue(PTMP_tmp2_15); PTMP_tmp2_15 = NULL;
    PrtFreeValue(PTMP_tmp3_15); PTMP_tmp3_15 = NULL;
    PrtFreeValue(PTMP_tmp4_15); PTMP_tmp4_15 = NULL;
    PrtFreeValue(PTMP_tmp5_15); PTMP_tmp5_15 = NULL;
    PrtFreeValue(PTMP_tmp6_15); PTMP_tmp6_15 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_CenterCliffAvoidanceController =
{
    "CenterCliffAvoidanceController",
    &P_CenterCliffAvoidanceController_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_SafeMotionController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_forwardSpeed_5 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* P_VAR_rotationSpeed_5 = PrtMkDefaultValue(&P_GEND_TYPE_f);
    PRT_VALUE* PTMP_tmp0_16 = NULL;
    PRT_VALUE* PTMP_tmp1_16 = NULL;
    PRT_VALUE* PTMP_tmp2_16 = NULL;
    PRT_VALUE* PTMP_tmp3_16 = NULL;
    PRT_VALUE* PTMP_tmp4_16 = NULL;
    PRT_VALUE* PTMP_tmp5_16 = NULL;
    PRT_VALUE* PTMP_tmp6_16 = NULL;
    PRT_VALUE* PTMP_tmp7_10 = NULL;
    PRT_VALUE* PTMP_tmp8_7 = NULL;
    PRT_VALUE* PTMP_tmp9_7 = NULL;
    PRT_VALUE* PTMP_tmp10_7 = NULL;
    PRT_VALUE* PTMP_tmp11_7 = NULL;
    PRT_VALUE* PTMP_tmp12_4 = NULL;
    PRT_VALUE* PTMP_tmp13_4 = NULL;
    PRT_VALUE* PTMP_tmp14_4 = NULL;
    PRT_VALUE* PTMP_tmp15_3 = NULL;
    PRT_VALUE* PTMP_tmp16_3 = NULL;
    PRT_VALUE* PTMP_tmp17_3 = NULL;
    PRT_VALUE* PTMP_tmp18_3 = NULL;
    PRT_VALUE* PTMP_tmp19_3 = NULL;
    PRT_VALUE* PTMP_tmp20_2 = NULL;
    PRT_VALUE* PTMP_tmp21_2 = NULL;
    PRT_VALUE* PTMP_tmp22_2 = NULL;
    PRT_VALUE* PTMP_tmp23_2 = NULL;
    PRT_VALUE* PTMP_tmp24_2 = NULL;
    PRT_VALUE* PTMP_tmp25_2 = NULL;
    PRT_VALUE* PTMP_tmp26_2 = NULL;
    PRT_VALUE* PTMP_tmp27_2 = NULL;
    PRT_VALUE* PTMP_tmp28_2 = NULL;
    PRT_VALUE* PTMP_tmp29_2 = NULL;
    PRT_VALUE* PTMP_tmp30_2 = NULL;
    PRT_VALUE* PTMP_tmp31_2 = NULL;
    PRT_VALUE* PTMP_tmp32_2 = NULL;
    PRT_VALUE* PTMP_tmp33_2 = NULL;
    PRT_VALUE* PTMP_tmp34_2 = NULL;
    PRT_VALUE* PTMP_tmp35_2 = NULL;
    PRT_VALUE* PTMP_tmp36_1 = NULL;
    PRT_VALUE* PTMP_tmp37_1 = NULL;
    PRT_VALUE* PTMP_tmp38_1 = NULL;
    PRT_VALUE* PTMP_tmp39_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_29 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_DOUBLE_16 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.2 } };
    PRT_VALUE P_LIT_DOUBLE_17 = { PRT_VALUE_KIND_FLOAT, { .ft = 0.8 } };
    PRT_VALUE** P_LVALUE_334 = &(P_VAR_forwardSpeed_5);
    PrtFreeValue(*P_LVALUE_334);
    *P_LVALUE_334 = PrtCloneValue((&P_LIT_DOUBLE_16));
    
    PRT_VALUE** P_LVALUE_335 = &(P_VAR_rotationSpeed_5);
    PrtFreeValue(*P_LVALUE_335);
    *P_LVALUE_335 = PrtCloneValue((&P_LIT_DOUBLE_17));
    
    PRT_VALUE** P_LVALUE_336 = &(PTMP_tmp0_16);
    PrtFreeValue(*P_LVALUE_336);
    *P_LVALUE_336 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
    
    PRT_VALUE** P_LVALUE_337 = &(PTMP_tmp1_16);
    PrtFreeValue(*P_LVALUE_337);
    *P_LVALUE_337 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[3]) < PrtPrimGetInt(PTMP_tmp0_16));
    
    if (PrtPrimGetBool(PTMP_tmp1_16))
    {
        PRT_VALUE** P_LVALUE_338 = &(PTMP_tmp2_16);
        PrtFreeValue(*P_LVALUE_338);
        *P_LVALUE_338 = PrtSeqGet(p_this->varValues[2], p_this->varValues[3]);
        
        PRT_VALUE** P_LVALUE_339 = &(PTMP_tmp3_16);
        PrtFreeValue(*P_LVALUE_339);
        *P_LVALUE_339 = PrtCloneValue(PTMP_tmp2_16);
        
        {
            PRT_VALUE** P_LVALUE_340 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_340);
            *P_LVALUE_340 = PTMP_tmp3_16;
            PTMP_tmp3_16 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_341 = &(PTMP_tmp4_16);
        PrtFreeValue(*P_LVALUE_341);
        *P_LVALUE_341 = PrtTupleGet(p_this->varValues[7], 0);
        
        PRT_VALUE** P_LVALUE_342 = &(PTMP_tmp5_16);
        PrtFreeValue(*P_LVALUE_342);
        *P_LVALUE_342 = PrtTupleGet(p_this->varValues[7], 1);
        
        PRT_VALUE** P_LVALUE_343 = &(PTMP_tmp6_16);
        PrtFreeValue(*P_LVALUE_343);
        *P_LVALUE_343 = PrtCloneValue(P_VAR_rotationSpeed_5);
        
        PRT_VALUE** P_LVALUE_344 = &(PTMP_tmp7_10);
        PrtFreeValue(*P_LVALUE_344);
        *P_LVALUE_344 = ((_P_GEN_funargs[0] = &(PTMP_tmp4_16)), (_P_GEN_funargs[1] = &(PTMP_tmp5_16)), (_P_GEN_funargs[2] = &(PTMP_tmp6_16)), (_P_GEN_funval = P_RotateTowardsLocation_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp4_16), PTMP_tmp4_16 = NULL), (PrtFreeValue(PTMP_tmp5_16), PTMP_tmp5_16 = NULL), (PrtFreeValue(PTMP_tmp6_16), PTMP_tmp6_16 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_21;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_21;
        }
        
        PRT_VALUE** P_LVALUE_345 = &(PTMP_tmp8_7);
        PrtFreeValue(*P_LVALUE_345);
        *P_LVALUE_345 = PrtMkBoolValue(!PrtPrimGetBool(PTMP_tmp7_10));
        
        if (PrtPrimGetBool(PTMP_tmp8_7))
        {
            PRT_VALUE** P_LVALUE_346 = &(PTMP_tmp9_7);
            PrtFreeValue(*P_LVALUE_346);
            *P_LVALUE_346 = PrtCloneValue(P_VAR_forwardSpeed_5);
            
            _P_GEN_funargs[0] = &(PTMP_tmp9_7);
            PrtFreeValue(P_MoveForward_IMPL(context, _P_GEN_funargs));
            PrtFreeValue(PTMP_tmp9_7);
            PTMP_tmp9_7 = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_21;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_21;
            }
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_347 = &(PTMP_tmp10_7);
        PrtFreeValue(*P_LVALUE_347);
        *P_LVALUE_347 = PrtTupleGet(p_this->varValues[7], 0);
        
        PRT_VALUE** P_LVALUE_348 = &(PTMP_tmp11_7);
        PrtFreeValue(*P_LVALUE_348);
        *P_LVALUE_348 = PrtTupleGet(p_this->varValues[7], 1);
        
        PRT_VALUE** P_LVALUE_349 = &(PTMP_tmp12_4);
        PrtFreeValue(*P_LVALUE_349);
        *P_LVALUE_349 = PrtCloneValue(P_VAR_forwardSpeed_5);
        
        PRT_VALUE** P_LVALUE_350 = &(PTMP_tmp13_4);
        PrtFreeValue(*P_LVALUE_350);
        *P_LVALUE_350 = ((_P_GEN_funargs[0] = &(PTMP_tmp10_7)), (_P_GEN_funargs[1] = &(PTMP_tmp11_7)), (_P_GEN_funargs[2] = &(PTMP_tmp12_4)), (_P_GEN_funval = P_CheckIfReached_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp10_7), PTMP_tmp10_7 = NULL), (PrtFreeValue(PTMP_tmp11_7), PTMP_tmp11_7 = NULL), (PrtFreeValue(PTMP_tmp12_4), PTMP_tmp12_4 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_21;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_21;
        }
        
        if (PrtPrimGetBool(PTMP_tmp13_4))
        {
            PRT_VALUE** P_LVALUE_351 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_351);
            *P_LVALUE_351 = PrtCloneValue(p_this->varValues[7]);
            
            PRT_VALUE** P_LVALUE_352 = &(PTMP_tmp14_4);
            PrtFreeValue(*P_LVALUE_352);
            *P_LVALUE_352 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[3]) + PrtPrimGetInt((&P_LIT_INT32_29)));
            
            {
                PRT_VALUE** P_LVALUE_353 = &(p_this->varValues[3]);
                PrtFreeValue(*P_LVALUE_353);
                *P_LVALUE_353 = PTMP_tmp14_4;
                PTMP_tmp14_4 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_354 = &(PTMP_tmp15_3);
            PrtFreeValue(*P_LVALUE_354);
            *P_LVALUE_354 = PrtCloneValue(p_this->varValues[11]);
            
            PRT_VALUE** P_LVALUE_355 = &(PTMP_tmp16_3);
            PrtFreeValue(*P_LVALUE_355);
            *P_LVALUE_355 = PrtCloneValue((&P_EVENT_eCurrentLocation.value));
            
            PRT_VALUE** P_LVALUE_356 = &(PTMP_tmp17_3);
            PrtFreeValue(*P_LVALUE_356);
            *P_LVALUE_356 = PrtCloneValue(p_this->varValues[6]);
            
            PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp15_3), PTMP_tmp16_3, 1, &(PTMP_tmp17_3));
            *(&(PTMP_tmp16_3)) = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_21;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_21;
            }
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_357 = &(PTMP_tmp18_3);
        PrtFreeValue(*P_LVALUE_357);
        *P_LVALUE_357 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[10]) + PrtPrimGetInt((&P_LIT_INT32_29)));
        
        {
            PRT_VALUE** P_LVALUE_358 = &(p_this->varValues[10]);
            PrtFreeValue(*P_LVALUE_358);
            *P_LVALUE_358 = PTMP_tmp18_3;
            PTMP_tmp18_3 = NULL;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_359 = &(PTMP_tmp19_3);
        PrtFreeValue(*P_LVALUE_359);
        *P_LVALUE_359 = PrtMkBoolValue(!PrtPrimGetBool(p_this->varValues[13]));
        
        PRT_VALUE** P_LVALUE_360 = &(PTMP_tmp22_2);
        PrtFreeValue(*P_LVALUE_360);
        *P_LVALUE_360 = PrtCloneValue(PTMP_tmp19_3);
        
        if (PrtPrimGetBool(PTMP_tmp22_2))
        {
            PRT_VALUE** P_LVALUE_361 = &(PTMP_tmp20_2);
            PrtFreeValue(*P_LVALUE_361);
            *P_LVALUE_361 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[0]));
            
            PRT_VALUE** P_LVALUE_362 = &(PTMP_tmp21_2);
            PrtFreeValue(*P_LVALUE_362);
            *P_LVALUE_362 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[1]) < PrtPrimGetInt(PTMP_tmp20_2));
            
            PRT_VALUE** P_LVALUE_363 = &(PTMP_tmp22_2);
            PrtFreeValue(*P_LVALUE_363);
            *P_LVALUE_363 = PrtCloneValue(PTMP_tmp21_2);
            
        }
        
        
        if (PrtPrimGetBool(PTMP_tmp22_2))
        {
            PRT_VALUE** P_LVALUE_364 = &(PTMP_tmp23_2);
            PrtFreeValue(*P_LVALUE_364);
            *P_LVALUE_364 = PrtSeqGet(p_this->varValues[0], p_this->varValues[1]);
            
            PRT_VALUE** P_LVALUE_365 = &(PTMP_tmp24_2);
            PrtFreeValue(*P_LVALUE_365);
            *P_LVALUE_365 = PrtCloneValue(PTMP_tmp23_2);
            
            {
                PRT_VALUE** P_LVALUE_366 = &(p_this->varValues[7]);
                PrtFreeValue(*P_LVALUE_366);
                *P_LVALUE_366 = PTMP_tmp24_2;
                PTMP_tmp24_2 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_367 = &(PTMP_tmp25_2);
            PrtFreeValue(*P_LVALUE_367);
            *P_LVALUE_367 = PrtTupleGet(p_this->varValues[7], 0);
            
            PRT_VALUE** P_LVALUE_368 = &(PTMP_tmp26_2);
            PrtFreeValue(*P_LVALUE_368);
            *P_LVALUE_368 = PrtTupleGet(p_this->varValues[7], 1);
            
            PRT_VALUE** P_LVALUE_369 = &(PTMP_tmp27_2);
            PrtFreeValue(*P_LVALUE_369);
            *P_LVALUE_369 = PrtCloneValue(P_VAR_rotationSpeed_5);
            
            PRT_VALUE** P_LVALUE_370 = &(PTMP_tmp28_2);
            PrtFreeValue(*P_LVALUE_370);
            *P_LVALUE_370 = ((_P_GEN_funargs[0] = &(PTMP_tmp25_2)), (_P_GEN_funargs[1] = &(PTMP_tmp26_2)), (_P_GEN_funargs[2] = &(PTMP_tmp27_2)), (_P_GEN_funval = P_RotateTowardsLocation_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp25_2), PTMP_tmp25_2 = NULL), (PrtFreeValue(PTMP_tmp26_2), PTMP_tmp26_2 = NULL), (PrtFreeValue(PTMP_tmp27_2), PTMP_tmp27_2 = NULL), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_21;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_21;
            }
            
            PRT_VALUE** P_LVALUE_371 = &(PTMP_tmp29_2);
            PrtFreeValue(*P_LVALUE_371);
            *P_LVALUE_371 = PrtMkBoolValue(!PrtPrimGetBool(PTMP_tmp28_2));
            
            if (PrtPrimGetBool(PTMP_tmp29_2))
            {
                PRT_VALUE** P_LVALUE_372 = &(PTMP_tmp30_2);
                PrtFreeValue(*P_LVALUE_372);
                *P_LVALUE_372 = PrtCloneValue(P_VAR_forwardSpeed_5);
                
                _P_GEN_funargs[0] = &(PTMP_tmp30_2);
                PrtFreeValue(P_MoveForward_IMPL(context, _P_GEN_funargs));
                PrtFreeValue(PTMP_tmp30_2);
                PTMP_tmp30_2 = NULL;
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_21;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_21;
                }
                
            }
            
            else
            {
            }
            
            
            PRT_VALUE** P_LVALUE_373 = &(PTMP_tmp31_2);
            PrtFreeValue(*P_LVALUE_373);
            *P_LVALUE_373 = PrtTupleGet(p_this->varValues[7], 0);
            
            PRT_VALUE** P_LVALUE_374 = &(PTMP_tmp32_2);
            PrtFreeValue(*P_LVALUE_374);
            *P_LVALUE_374 = PrtTupleGet(p_this->varValues[7], 1);
            
            PRT_VALUE** P_LVALUE_375 = &(PTMP_tmp33_2);
            PrtFreeValue(*P_LVALUE_375);
            *P_LVALUE_375 = PrtCloneValue(P_VAR_forwardSpeed_5);
            
            PRT_VALUE** P_LVALUE_376 = &(PTMP_tmp34_2);
            PrtFreeValue(*P_LVALUE_376);
            *P_LVALUE_376 = ((_P_GEN_funargs[0] = &(PTMP_tmp31_2)), (_P_GEN_funargs[1] = &(PTMP_tmp32_2)), (_P_GEN_funargs[2] = &(PTMP_tmp33_2)), (_P_GEN_funval = P_CheckIfReached_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp31_2), PTMP_tmp31_2 = NULL), (PrtFreeValue(PTMP_tmp32_2), PTMP_tmp32_2 = NULL), (PrtFreeValue(PTMP_tmp33_2), PTMP_tmp33_2 = NULL), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_21;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_21;
            }
            
            if (PrtPrimGetBool(PTMP_tmp34_2))
            {
                PRT_VALUE** P_LVALUE_377 = &(p_this->varValues[6]);
                PrtFreeValue(*P_LVALUE_377);
                *P_LVALUE_377 = PrtCloneValue(p_this->varValues[7]);
                
                PRT_VALUE** P_LVALUE_378 = &(PTMP_tmp35_2);
                PrtFreeValue(*P_LVALUE_378);
                *P_LVALUE_378 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[1]) + PrtPrimGetInt((&P_LIT_INT32_29)));
                
                {
                    PRT_VALUE** P_LVALUE_379 = &(p_this->varValues[1]);
                    PrtFreeValue(*P_LVALUE_379);
                    *P_LVALUE_379 = PTMP_tmp35_2;
                    PTMP_tmp35_2 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_380 = &(PTMP_tmp36_1);
                PrtFreeValue(*P_LVALUE_380);
                *P_LVALUE_380 = PrtCloneValue(p_this->varValues[11]);
                
                PRT_VALUE** P_LVALUE_381 = &(PTMP_tmp37_1);
                PrtFreeValue(*P_LVALUE_381);
                *P_LVALUE_381 = PrtCloneValue((&P_EVENT_eCurrentLocation.value));
                
                PRT_VALUE** P_LVALUE_382 = &(PTMP_tmp38_1);
                PrtFreeValue(*P_LVALUE_382);
                *P_LVALUE_382 = PrtCloneValue(p_this->varValues[6]);
                
                PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp36_1), PTMP_tmp37_1, 1, &(PTMP_tmp38_1));
                *(&(PTMP_tmp37_1)) = NULL;
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_21;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_21;
                }
                
            }
            
            else
            {
            }
            
            
            PRT_VALUE** P_LVALUE_383 = &(PTMP_tmp39_1);
            PrtFreeValue(*P_LVALUE_383);
            *P_LVALUE_383 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[10]) + PrtPrimGetInt((&P_LIT_INT32_29)));
            
            {
                PRT_VALUE** P_LVALUE_384 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_384);
                *P_LVALUE_384 = PTMP_tmp39_1;
                PTMP_tmp39_1 = NULL;
            }
            
        }
        
        else
        {
            PrtFreeValue(P_Stay_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_21;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_21;
            }
            
        }
        
        
    }
    
    
p_return_21: ;
    PrtFreeValue(P_VAR_forwardSpeed_5); P_VAR_forwardSpeed_5 = NULL;
    PrtFreeValue(P_VAR_rotationSpeed_5); P_VAR_rotationSpeed_5 = NULL;
    PrtFreeValue(PTMP_tmp0_16); PTMP_tmp0_16 = NULL;
    PrtFreeValue(PTMP_tmp1_16); PTMP_tmp1_16 = NULL;
    PrtFreeValue(PTMP_tmp2_16); PTMP_tmp2_16 = NULL;
    PrtFreeValue(PTMP_tmp3_16); PTMP_tmp3_16 = NULL;
    PrtFreeValue(PTMP_tmp4_16); PTMP_tmp4_16 = NULL;
    PrtFreeValue(PTMP_tmp5_16); PTMP_tmp5_16 = NULL;
    PrtFreeValue(PTMP_tmp6_16); PTMP_tmp6_16 = NULL;
    PrtFreeValue(PTMP_tmp7_10); PTMP_tmp7_10 = NULL;
    PrtFreeValue(PTMP_tmp8_7); PTMP_tmp8_7 = NULL;
    PrtFreeValue(PTMP_tmp9_7); PTMP_tmp9_7 = NULL;
    PrtFreeValue(PTMP_tmp10_7); PTMP_tmp10_7 = NULL;
    PrtFreeValue(PTMP_tmp11_7); PTMP_tmp11_7 = NULL;
    PrtFreeValue(PTMP_tmp12_4); PTMP_tmp12_4 = NULL;
    PrtFreeValue(PTMP_tmp13_4); PTMP_tmp13_4 = NULL;
    PrtFreeValue(PTMP_tmp14_4); PTMP_tmp14_4 = NULL;
    PrtFreeValue(PTMP_tmp15_3); PTMP_tmp15_3 = NULL;
    PrtFreeValue(PTMP_tmp16_3); PTMP_tmp16_3 = NULL;
    PrtFreeValue(PTMP_tmp17_3); PTMP_tmp17_3 = NULL;
    PrtFreeValue(PTMP_tmp18_3); PTMP_tmp18_3 = NULL;
    PrtFreeValue(PTMP_tmp19_3); PTMP_tmp19_3 = NULL;
    PrtFreeValue(PTMP_tmp20_2); PTMP_tmp20_2 = NULL;
    PrtFreeValue(PTMP_tmp21_2); PTMP_tmp21_2 = NULL;
    PrtFreeValue(PTMP_tmp22_2); PTMP_tmp22_2 = NULL;
    PrtFreeValue(PTMP_tmp23_2); PTMP_tmp23_2 = NULL;
    PrtFreeValue(PTMP_tmp24_2); PTMP_tmp24_2 = NULL;
    PrtFreeValue(PTMP_tmp25_2); PTMP_tmp25_2 = NULL;
    PrtFreeValue(PTMP_tmp26_2); PTMP_tmp26_2 = NULL;
    PrtFreeValue(PTMP_tmp27_2); PTMP_tmp27_2 = NULL;
    PrtFreeValue(PTMP_tmp28_2); PTMP_tmp28_2 = NULL;
    PrtFreeValue(PTMP_tmp29_2); PTMP_tmp29_2 = NULL;
    PrtFreeValue(PTMP_tmp30_2); PTMP_tmp30_2 = NULL;
    PrtFreeValue(PTMP_tmp31_2); PTMP_tmp31_2 = NULL;
    PrtFreeValue(PTMP_tmp32_2); PTMP_tmp32_2 = NULL;
    PrtFreeValue(PTMP_tmp33_2); PTMP_tmp33_2 = NULL;
    PrtFreeValue(PTMP_tmp34_2); PTMP_tmp34_2 = NULL;
    PrtFreeValue(PTMP_tmp35_2); PTMP_tmp35_2 = NULL;
    PrtFreeValue(PTMP_tmp36_1); PTMP_tmp36_1 = NULL;
    PrtFreeValue(PTMP_tmp37_1); PTMP_tmp37_1 = NULL;
    PrtFreeValue(PTMP_tmp38_1); PTMP_tmp38_1 = NULL;
    PrtFreeValue(PTMP_tmp39_1); PTMP_tmp39_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_SafeMotionController =
{
    "SafeMotionController",
    &P_SafeMotionController_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_AdvancedMotionController_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtFreeValue(P_SafeMotionController_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_22;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_22;
    }
    
p_return_22: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_AdvancedMotionController =
{
    "AdvancedMotionController",
    &P_AdvancedMotionController_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_4 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_17 = NULL;
    PRT_VALUE* PTMP_tmp1_17 = NULL;
    PRT_VALUE* PTMP_tmp2_17 = NULL;
    PRT_VALUE* PTMP_tmp3_17 = NULL;
    PRT_VALUE* PTMP_tmp4_17 = NULL;
    PRT_VALUE* PTMP_tmp5_17 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_30 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_10 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_385 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_385);
    *P_LVALUE_385 = PrtCloneValue((&P_LIT_INT32_30));
    
    PRT_VALUE** P_LVALUE_386 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_386);
    *P_LVALUE_386 = PrtCloneValue((&P_LIT_INT32_30));
    
    PRT_VALUE** P_LVALUE_387 = &(PTMP_tmp0_17);
    PrtFreeValue(*P_LVALUE_387);
    *P_LVALUE_387 = PrtTupleGet(*P_VAR_payload_4, 0);
    
    PRT_VALUE** P_LVALUE_388 = &(PTMP_tmp1_17);
    PrtFreeValue(*P_LVALUE_388);
    *P_LVALUE_388 = PrtCloneValue(PTMP_tmp0_17);
    
    {
        PRT_VALUE** P_LVALUE_389 = &(p_this->varValues[11]);
        PrtFreeValue(*P_LVALUE_389);
        *P_LVALUE_389 = PTMP_tmp1_17;
        PTMP_tmp1_17 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_390 = &(PTMP_tmp2_17);
    PrtFreeValue(*P_LVALUE_390);
    *P_LVALUE_390 = PrtTupleGet(*P_VAR_payload_4, 1);
    
    PRT_VALUE** P_LVALUE_391 = &(PTMP_tmp3_17);
    PrtFreeValue(*P_LVALUE_391);
    *P_LVALUE_391 = PrtCloneValue(PTMP_tmp2_17);
    
    {
        PRT_VALUE** P_LVALUE_392 = &(p_this->varValues[6]);
        PrtFreeValue(*P_LVALUE_392);
        *P_LVALUE_392 = PTMP_tmp3_17;
        PTMP_tmp3_17 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_393 = &(PTMP_tmp4_17);
    PrtFreeValue(*P_LVALUE_393);
    *P_LVALUE_393 = PrtTupleGet(*P_VAR_payload_4, 2);
    
    PRT_VALUE** P_LVALUE_394 = &(PTMP_tmp5_17);
    PrtFreeValue(*P_LVALUE_394);
    *P_LVALUE_394 = PrtCloneValue(PTMP_tmp4_17);
    
    {
        PRT_VALUE** P_LVALUE_395 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_395);
        *P_LVALUE_395 = PTMP_tmp5_17;
        PTMP_tmp5_17 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_396 = &(p_this->varValues[9]);
    PrtFreeValue(*P_LVALUE_396);
    *P_LVALUE_396 = PrtCloneValue((&P_LIT_INT32_30));
    
    PRT_VALUE** P_LVALUE_397 = &(p_this->varValues[10]);
    PrtFreeValue(*P_LVALUE_397);
    *P_LVALUE_397 = PrtCloneValue((&P_LIT_INT32_30));
    
    PRT_VALUE** P_LVALUE_398 = &(p_this->varValues[12]);
    PrtFreeValue(*P_LVALUE_398);
    *P_LVALUE_398 = PrtCloneValue((&P_LIT_INT32_30));
    
    PRT_VALUE** P_LVALUE_399 = &(p_this->varValues[13]);
    PrtFreeValue(*P_LVALUE_399);
    *P_LVALUE_399 = PrtCloneValue((&P_LIT_BOOLEAN_10));
    
    PrtGoto(p_this, 1U, 0);
    
    PRT_VALUE** P_LVALUE_400 = &(p_this->varValues[14]);
    PrtFreeValue(*P_LVALUE_400);
    *P_LVALUE_400 = PrtCloneValue((&P_LIT_BOOLEAN_10));
    
    PRT_VALUE** P_LVALUE_401 = &(p_this->varValues[17]);
    PrtFreeValue(*P_LVALUE_401);
    *P_LVALUE_401 = PrtCloneValue((&P_LIT_INT32_30));
    
p_return_23: ;
    PrtFreeValue(PTMP_tmp0_17); PTMP_tmp0_17 = NULL;
    PrtFreeValue(PTMP_tmp1_17); PTMP_tmp1_17 = NULL;
    PrtFreeValue(PTMP_tmp2_17); PTMP_tmp2_17 = NULL;
    PrtFreeValue(PTMP_tmp3_17); PTMP_tmp3_17 = NULL;
    PrtFreeValue(PTMP_tmp4_17); PTMP_tmp4_17 = NULL;
    PrtFreeValue(PTMP_tmp5_17); PTMP_tmp5_17 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_T4mT2ffff,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_18 = NULL;
    PRT_VALUE* PTMP_tmp1_18 = NULL;
    PRT_VALUE* PTMP_tmp2_18 = NULL;
    PRT_VALUE* PTMP_tmp3_18 = NULL;
    PRT_VALUE* PTMP_tmp4_18 = NULL;
    PRT_VALUE* PTMP_tmp5_18 = NULL;
    PRT_VALUE* PTMP_tmp6_17 = NULL;
    PRT_VALUE* PTMP_tmp7_11 = NULL;
    PRT_VALUE* PTMP_tmp8_8 = NULL;
    PRT_VALUE* PTMP_tmp9_8 = NULL;
    PRT_VALUE* PTMP_tmp10_8 = NULL;
    PRT_VALUE* PTMP_tmp11_8 = NULL;
    PRT_VALUE* PTMP_tmp12_5 = NULL;
    PRT_VALUE* PTMP_tmp13_5 = NULL;
    PRT_VALUE* PTMP_tmp14_5 = NULL;
    PRT_VALUE* PTMP_tmp15_4 = NULL;
    PRT_VALUE* PTMP_tmp16_4 = NULL;
    PRT_VALUE* PTMP_tmp17_4 = NULL;
    PRT_VALUE* PTMP_tmp18_4 = NULL;
    PRT_VALUE* PTMP_tmp19_4 = NULL;
    PRT_VALUE* PTMP_tmp20_3 = NULL;
    PRT_VALUE* PTMP_tmp21_3 = NULL;
    PRT_VALUE* PTMP_tmp22_3 = NULL;
    PRT_VALUE* PTMP_tmp23_3 = NULL;
    PRT_VALUE* PTMP_tmp24_3 = NULL;
    PRT_VALUE* PTMP_tmp25_3 = NULL;
    PRT_VALUE* PTMP_tmp26_3 = NULL;
    PRT_VALUE* PTMP_tmp27_3 = NULL;
    PRT_VALUE* PTMP_tmp28_3 = NULL;
    PRT_VALUE* PTMP_tmp29_3 = NULL;
    PRT_VALUE* PTMP_tmp30_3 = NULL;
    PRT_VALUE* PTMP_tmp31_3 = NULL;
    PRT_VALUE* PTMP_tmp32_3 = NULL;
    PRT_VALUE* PTMP_tmp33_3 = NULL;
    PRT_VALUE* PTMP_tmp34_3 = NULL;
    PRT_VALUE* PTMP_tmp35_3 = NULL;
    PRT_VALUE* PTMP_tmp36_2 = NULL;
    PRT_VALUE* PTMP_tmp37_2 = NULL;
    PRT_VALUE* PTMP_tmp38_2 = NULL;
    PRT_VALUE* PTMP_tmp39_2 = NULL;
    PRT_VALUE* PTMP_tmp40_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_31 = { PRT_VALUE_KIND_INT, { .nt = 20 } };
    PRT_VALUE P_LIT_INT32_32 = { PRT_VALUE_KIND_INT, { .nt = 200 } };
    PRT_VALUE P_LIT_INT32_33 = { PRT_VALUE_KIND_INT, { .nt = 6 } };
    PRT_VALUE P_LIT_INT32_34 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_35 = { PRT_VALUE_KIND_INT, { .nt = 50 } };
    PRT_VALUE P_LIT_BOOLEAN_11 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_402 = &(PTMP_tmp0_18);
    PrtFreeValue(*P_LVALUE_402);
    *P_LVALUE_402 = PrtMkBoolValue(!PrtPrimGetBool(p_this->varValues[14]));
    
    if (PrtPrimGetBool(PTMP_tmp0_18))
    {
        PRT_VALUE** P_LVALUE_403 = &(p_this->varValues[14]);
        PrtFreeValue(*P_LVALUE_403);
        *P_LVALUE_403 = PrtCloneValue((&P_LIT_BOOLEAN_11));
        
        PRT_VALUE** P_LVALUE_404 = &(PTMP_tmp1_18);
        PrtFreeValue(*P_LVALUE_404);
        *P_LVALUE_404 = ((_P_GEN_funval = P_DM_IMPL_2(context, _P_GEN_funargs)), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_24;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_24;
        }
        
        {
            PRT_VALUE** P_LVALUE_405 = &(p_this->varValues[15]);
            PrtFreeValue(*P_LVALUE_405);
            *P_LVALUE_405 = PTMP_tmp1_18;
            PTMP_tmp1_18 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_406 = &(PTMP_tmp2_18);
        PrtFreeValue(*P_LVALUE_406);
        *P_LVALUE_406 = PrtMkStringValue(PrtFormatString("CenterCliffAvoidanceController", 0, 0));
        ;
        
        PRT_VALUE** P_LVALUE_407 = &(PTMP_tmp3_18);
        PrtFreeValue(*P_LVALUE_407);
        *P_LVALUE_407 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp2_18));
        
        if (PrtPrimGetBool(PTMP_tmp3_18))
        {
            PrtFreeValue(P_CenterCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_24;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_24;
            }
            
            PRT_VALUE** P_LVALUE_408 = &(p_this->varValues[16]);
            PrtFreeValue(*P_LVALUE_408);
            *P_LVALUE_408 = PrtCloneValue((&P_LIT_INT32_31));
            
            PRT_VALUE** P_LVALUE_409 = &(p_this->varValues[18]);
            PrtFreeValue(*P_LVALUE_409);
            *P_LVALUE_409 = PrtCloneValue((&P_LIT_INT32_32));
            
            PRT_VALUE** P_LVALUE_410 = &(p_this->varValues[19]);
            PrtFreeValue(*P_LVALUE_410);
            *P_LVALUE_410 = PrtCloneValue((&P_LIT_INT32_33));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_411 = &(PTMP_tmp4_18);
            PrtFreeValue(*P_LVALUE_411);
            *P_LVALUE_411 = PrtMkStringValue(PrtFormatString("RightCliffAvoidanceController", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_412 = &(PTMP_tmp5_18);
            PrtFreeValue(*P_LVALUE_412);
            *P_LVALUE_412 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp4_18));
            
            if (PrtPrimGetBool(PTMP_tmp5_18))
            {
                PrtFreeValue(P_RightCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_24;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_24;
                }
                
                PRT_VALUE** P_LVALUE_413 = &(p_this->varValues[16]);
                PrtFreeValue(*P_LVALUE_413);
                *P_LVALUE_413 = PrtCloneValue((&P_LIT_INT32_31));
                
                PRT_VALUE** P_LVALUE_414 = &(p_this->varValues[18]);
                PrtFreeValue(*P_LVALUE_414);
                *P_LVALUE_414 = PrtCloneValue((&P_LIT_INT32_32));
                
                PRT_VALUE** P_LVALUE_415 = &(p_this->varValues[19]);
                PrtFreeValue(*P_LVALUE_415);
                *P_LVALUE_415 = PrtCloneValue((&P_LIT_INT32_33));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_416 = &(PTMP_tmp6_17);
                PrtFreeValue(*P_LVALUE_416);
                *P_LVALUE_416 = PrtMkStringValue(PrtFormatString("LeftCliffAvoidanceController", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_417 = &(PTMP_tmp7_11);
                PrtFreeValue(*P_LVALUE_417);
                *P_LVALUE_417 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp6_17));
                
                if (PrtPrimGetBool(PTMP_tmp7_11))
                {
                    PrtFreeValue(P_LeftCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_24;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_24;
                    }
                    
                    PRT_VALUE** P_LVALUE_418 = &(p_this->varValues[16]);
                    PrtFreeValue(*P_LVALUE_418);
                    *P_LVALUE_418 = PrtCloneValue((&P_LIT_INT32_31));
                    
                    PRT_VALUE** P_LVALUE_419 = &(p_this->varValues[18]);
                    PrtFreeValue(*P_LVALUE_419);
                    *P_LVALUE_419 = PrtCloneValue((&P_LIT_INT32_32));
                    
                    PRT_VALUE** P_LVALUE_420 = &(p_this->varValues[19]);
                    PrtFreeValue(*P_LVALUE_420);
                    *P_LVALUE_420 = PrtCloneValue((&P_LIT_INT32_33));
                    
                }
                
                else
                {
                    PRT_VALUE** P_LVALUE_421 = &(PTMP_tmp8_8);
                    PrtFreeValue(*P_LVALUE_421);
                    *P_LVALUE_421 = PrtMkStringValue(PrtFormatString("RightObstacleAvoidanceController", 0, 0));
                    ;
                    
                    PRT_VALUE** P_LVALUE_422 = &(PTMP_tmp9_8);
                    PrtFreeValue(*P_LVALUE_422);
                    *P_LVALUE_422 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp8_8));
                    
                    if (PrtPrimGetBool(PTMP_tmp9_8))
                    {
                        PrtFreeValue(P_RightObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                            goto p_return_24;
                        }
                        if (p_this->isHalted == PRT_TRUE) {
                            PrtFreeValue(_P_GEN_retval);
                            _P_GEN_retval = NULL;
                            goto p_return_24;
                        }
                        
                        PRT_VALUE** P_LVALUE_423 = &(p_this->varValues[16]);
                        PrtFreeValue(*P_LVALUE_423);
                        *P_LVALUE_423 = PrtCloneValue((&P_LIT_INT32_31));
                        
                        PRT_VALUE** P_LVALUE_424 = &(p_this->varValues[18]);
                        PrtFreeValue(*P_LVALUE_424);
                        *P_LVALUE_424 = PrtCloneValue((&P_LIT_INT32_32));
                        
                        PRT_VALUE** P_LVALUE_425 = &(p_this->varValues[19]);
                        PrtFreeValue(*P_LVALUE_425);
                        *P_LVALUE_425 = PrtCloneValue((&P_LIT_INT32_33));
                        
                    }
                    
                    else
                    {
                        PRT_VALUE** P_LVALUE_426 = &(PTMP_tmp10_8);
                        PrtFreeValue(*P_LVALUE_426);
                        *P_LVALUE_426 = PrtMkStringValue(PrtFormatString("LeftObstacleAvoidanceController", 0, 0));
                        ;
                        
                        PRT_VALUE** P_LVALUE_427 = &(PTMP_tmp11_8);
                        PrtFreeValue(*P_LVALUE_427);
                        *P_LVALUE_427 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp10_8));
                        
                        if (PrtPrimGetBool(PTMP_tmp11_8))
                        {
                            PrtFreeValue(P_LeftObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                goto p_return_24;
                            }
                            if (p_this->isHalted == PRT_TRUE) {
                                PrtFreeValue(_P_GEN_retval);
                                _P_GEN_retval = NULL;
                                goto p_return_24;
                            }
                            
                            PRT_VALUE** P_LVALUE_428 = &(p_this->varValues[16]);
                            PrtFreeValue(*P_LVALUE_428);
                            *P_LVALUE_428 = PrtCloneValue((&P_LIT_INT32_31));
                            
                            PRT_VALUE** P_LVALUE_429 = &(p_this->varValues[18]);
                            PrtFreeValue(*P_LVALUE_429);
                            *P_LVALUE_429 = PrtCloneValue((&P_LIT_INT32_32));
                            
                            PRT_VALUE** P_LVALUE_430 = &(p_this->varValues[19]);
                            PrtFreeValue(*P_LVALUE_430);
                            *P_LVALUE_430 = PrtCloneValue((&P_LIT_INT32_33));
                            
                        }
                        
                        else
                        {
                            PRT_VALUE** P_LVALUE_431 = &(PTMP_tmp12_5);
                            PrtFreeValue(*P_LVALUE_431);
                            *P_LVALUE_431 = PrtMkStringValue(PrtFormatString("SafeMotionController", 0, 0));
                            ;
                            
                            PRT_VALUE** P_LVALUE_432 = &(PTMP_tmp13_5);
                            PrtFreeValue(*P_LVALUE_432);
                            *P_LVALUE_432 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp12_5));
                            
                            if (PrtPrimGetBool(PTMP_tmp13_5))
                            {
                                PrtFreeValue(P_SafeMotionController_IMPL(context, _P_GEN_funargs));
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_24;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_24;
                                }
                                
                                PRT_VALUE** P_LVALUE_433 = &(p_this->varValues[16]);
                                PrtFreeValue(*P_LVALUE_433);
                                *P_LVALUE_433 = PrtCloneValue((&P_LIT_INT32_34));
                                
                                PRT_VALUE** P_LVALUE_434 = &(p_this->varValues[18]);
                                PrtFreeValue(*P_LVALUE_434);
                                *P_LVALUE_434 = PrtCloneValue((&P_LIT_INT32_35));
                                
                                PRT_VALUE** P_LVALUE_435 = &(p_this->varValues[19]);
                                PrtFreeValue(*P_LVALUE_435);
                                *P_LVALUE_435 = PrtCloneValue((&P_LIT_INT32_33));
                                
                            }
                            
                            else
                            {
                                PrtFreeValue(P_AdvancedMotionController_IMPL(context, _P_GEN_funargs));
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_24;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_24;
                                }
                                
                                PRT_VALUE** P_LVALUE_436 = &(p_this->varValues[16]);
                                PrtFreeValue(*P_LVALUE_436);
                                *P_LVALUE_436 = PrtCloneValue((&P_LIT_INT32_34));
                                
                                PRT_VALUE** P_LVALUE_437 = &(p_this->varValues[18]);
                                PrtFreeValue(*P_LVALUE_437);
                                *P_LVALUE_437 = PrtCloneValue((&P_LIT_INT32_35));
                                
                                PRT_VALUE** P_LVALUE_438 = &(p_this->varValues[19]);
                                PrtFreeValue(*P_LVALUE_438);
                                *P_LVALUE_438 = PrtCloneValue((&P_LIT_INT32_33));
                                
                            }
                            
                            
                        }
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            
        }
        
        
        PRT_VALUE** P_LVALUE_439 = &(p_this->varValues[17]);
        PrtFreeValue(*P_LVALUE_439);
        *P_LVALUE_439 = PrtCloneValue((&P_LIT_INT32_34));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_440 = &(PTMP_tmp14_5);
        PrtFreeValue(*P_LVALUE_440);
        *P_LVALUE_440 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[16], p_this->varValues[17]));
        
        if (PrtPrimGetBool(PTMP_tmp14_5))
        {
            PRT_VALUE** P_LVALUE_441 = &(PTMP_tmp15_4);
            PrtFreeValue(*P_LVALUE_441);
            *P_LVALUE_441 = ((_P_GEN_funval = P_DM_IMPL_2(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_24;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_24;
            }
            
            {
                PRT_VALUE** P_LVALUE_442 = &(p_this->varValues[15]);
                PrtFreeValue(*P_LVALUE_442);
                *P_LVALUE_442 = PTMP_tmp15_4;
                PTMP_tmp15_4 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_443 = &(PTMP_tmp16_4);
            PrtFreeValue(*P_LVALUE_443);
            *P_LVALUE_443 = PrtMkStringValue(PrtFormatString("CenterCliffAvoidanceController", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_444 = &(PTMP_tmp17_4);
            PrtFreeValue(*P_LVALUE_444);
            *P_LVALUE_444 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp16_4));
            
            if (PrtPrimGetBool(PTMP_tmp17_4))
            {
                PrtFreeValue(P_CenterCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_24;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_24;
                }
                
                PRT_VALUE** P_LVALUE_445 = &(p_this->varValues[16]);
                PrtFreeValue(*P_LVALUE_445);
                *P_LVALUE_445 = PrtCloneValue((&P_LIT_INT32_31));
                
                PRT_VALUE** P_LVALUE_446 = &(p_this->varValues[18]);
                PrtFreeValue(*P_LVALUE_446);
                *P_LVALUE_446 = PrtCloneValue((&P_LIT_INT32_32));
                
                PRT_VALUE** P_LVALUE_447 = &(p_this->varValues[19]);
                PrtFreeValue(*P_LVALUE_447);
                *P_LVALUE_447 = PrtCloneValue((&P_LIT_INT32_33));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_448 = &(PTMP_tmp18_4);
                PrtFreeValue(*P_LVALUE_448);
                *P_LVALUE_448 = PrtMkStringValue(PrtFormatString("RightCliffAvoidanceController", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_449 = &(PTMP_tmp19_4);
                PrtFreeValue(*P_LVALUE_449);
                *P_LVALUE_449 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp18_4));
                
                if (PrtPrimGetBool(PTMP_tmp19_4))
                {
                    PrtFreeValue(P_RightCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_24;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_24;
                    }
                    
                    PRT_VALUE** P_LVALUE_450 = &(p_this->varValues[16]);
                    PrtFreeValue(*P_LVALUE_450);
                    *P_LVALUE_450 = PrtCloneValue((&P_LIT_INT32_31));
                    
                    PRT_VALUE** P_LVALUE_451 = &(p_this->varValues[18]);
                    PrtFreeValue(*P_LVALUE_451);
                    *P_LVALUE_451 = PrtCloneValue((&P_LIT_INT32_32));
                    
                    PRT_VALUE** P_LVALUE_452 = &(p_this->varValues[19]);
                    PrtFreeValue(*P_LVALUE_452);
                    *P_LVALUE_452 = PrtCloneValue((&P_LIT_INT32_33));
                    
                }
                
                else
                {
                    PRT_VALUE** P_LVALUE_453 = &(PTMP_tmp20_3);
                    PrtFreeValue(*P_LVALUE_453);
                    *P_LVALUE_453 = PrtMkStringValue(PrtFormatString("LeftCliffAvoidanceController", 0, 0));
                    ;
                    
                    PRT_VALUE** P_LVALUE_454 = &(PTMP_tmp21_3);
                    PrtFreeValue(*P_LVALUE_454);
                    *P_LVALUE_454 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp20_3));
                    
                    if (PrtPrimGetBool(PTMP_tmp21_3))
                    {
                        PrtFreeValue(P_LeftCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                            goto p_return_24;
                        }
                        if (p_this->isHalted == PRT_TRUE) {
                            PrtFreeValue(_P_GEN_retval);
                            _P_GEN_retval = NULL;
                            goto p_return_24;
                        }
                        
                        PRT_VALUE** P_LVALUE_455 = &(p_this->varValues[16]);
                        PrtFreeValue(*P_LVALUE_455);
                        *P_LVALUE_455 = PrtCloneValue((&P_LIT_INT32_31));
                        
                        PRT_VALUE** P_LVALUE_456 = &(p_this->varValues[18]);
                        PrtFreeValue(*P_LVALUE_456);
                        *P_LVALUE_456 = PrtCloneValue((&P_LIT_INT32_32));
                        
                        PRT_VALUE** P_LVALUE_457 = &(p_this->varValues[19]);
                        PrtFreeValue(*P_LVALUE_457);
                        *P_LVALUE_457 = PrtCloneValue((&P_LIT_INT32_33));
                        
                    }
                    
                    else
                    {
                        PRT_VALUE** P_LVALUE_458 = &(PTMP_tmp22_3);
                        PrtFreeValue(*P_LVALUE_458);
                        *P_LVALUE_458 = PrtMkStringValue(PrtFormatString("RightObstacleAvoidanceController", 0, 0));
                        ;
                        
                        PRT_VALUE** P_LVALUE_459 = &(PTMP_tmp23_3);
                        PrtFreeValue(*P_LVALUE_459);
                        *P_LVALUE_459 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp22_3));
                        
                        if (PrtPrimGetBool(PTMP_tmp23_3))
                        {
                            PrtFreeValue(P_RightObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                goto p_return_24;
                            }
                            if (p_this->isHalted == PRT_TRUE) {
                                PrtFreeValue(_P_GEN_retval);
                                _P_GEN_retval = NULL;
                                goto p_return_24;
                            }
                            
                            PRT_VALUE** P_LVALUE_460 = &(p_this->varValues[16]);
                            PrtFreeValue(*P_LVALUE_460);
                            *P_LVALUE_460 = PrtCloneValue((&P_LIT_INT32_31));
                            
                            PRT_VALUE** P_LVALUE_461 = &(p_this->varValues[18]);
                            PrtFreeValue(*P_LVALUE_461);
                            *P_LVALUE_461 = PrtCloneValue((&P_LIT_INT32_32));
                            
                            PRT_VALUE** P_LVALUE_462 = &(p_this->varValues[19]);
                            PrtFreeValue(*P_LVALUE_462);
                            *P_LVALUE_462 = PrtCloneValue((&P_LIT_INT32_33));
                            
                        }
                        
                        else
                        {
                            PRT_VALUE** P_LVALUE_463 = &(PTMP_tmp24_3);
                            PrtFreeValue(*P_LVALUE_463);
                            *P_LVALUE_463 = PrtMkStringValue(PrtFormatString("LeftObstacleAvoidanceController", 0, 0));
                            ;
                            
                            PRT_VALUE** P_LVALUE_464 = &(PTMP_tmp25_3);
                            PrtFreeValue(*P_LVALUE_464);
                            *P_LVALUE_464 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp24_3));
                            
                            if (PrtPrimGetBool(PTMP_tmp25_3))
                            {
                                PrtFreeValue(P_LeftObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_24;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_24;
                                }
                                
                                PRT_VALUE** P_LVALUE_465 = &(p_this->varValues[16]);
                                PrtFreeValue(*P_LVALUE_465);
                                *P_LVALUE_465 = PrtCloneValue((&P_LIT_INT32_31));
                                
                                PRT_VALUE** P_LVALUE_466 = &(p_this->varValues[18]);
                                PrtFreeValue(*P_LVALUE_466);
                                *P_LVALUE_466 = PrtCloneValue((&P_LIT_INT32_32));
                                
                                PRT_VALUE** P_LVALUE_467 = &(p_this->varValues[19]);
                                PrtFreeValue(*P_LVALUE_467);
                                *P_LVALUE_467 = PrtCloneValue((&P_LIT_INT32_33));
                                
                            }
                            
                            else
                            {
                                PRT_VALUE** P_LVALUE_468 = &(PTMP_tmp26_3);
                                PrtFreeValue(*P_LVALUE_468);
                                *P_LVALUE_468 = PrtMkStringValue(PrtFormatString("SafeMotionController", 0, 0));
                                ;
                                
                                PRT_VALUE** P_LVALUE_469 = &(PTMP_tmp27_3);
                                PrtFreeValue(*P_LVALUE_469);
                                *P_LVALUE_469 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp26_3));
                                
                                if (PrtPrimGetBool(PTMP_tmp27_3))
                                {
                                    PrtFreeValue(P_SafeMotionController_IMPL(context, _P_GEN_funargs));
                                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                        goto p_return_24;
                                    }
                                    if (p_this->isHalted == PRT_TRUE) {
                                        PrtFreeValue(_P_GEN_retval);
                                        _P_GEN_retval = NULL;
                                        goto p_return_24;
                                    }
                                    
                                    PRT_VALUE** P_LVALUE_470 = &(p_this->varValues[16]);
                                    PrtFreeValue(*P_LVALUE_470);
                                    *P_LVALUE_470 = PrtCloneValue((&P_LIT_INT32_34));
                                    
                                    PRT_VALUE** P_LVALUE_471 = &(p_this->varValues[18]);
                                    PrtFreeValue(*P_LVALUE_471);
                                    *P_LVALUE_471 = PrtCloneValue((&P_LIT_INT32_35));
                                    
                                    PRT_VALUE** P_LVALUE_472 = &(p_this->varValues[19]);
                                    PrtFreeValue(*P_LVALUE_472);
                                    *P_LVALUE_472 = PrtCloneValue((&P_LIT_INT32_33));
                                    
                                }
                                
                                else
                                {
                                    PrtFreeValue(P_AdvancedMotionController_IMPL(context, _P_GEN_funargs));
                                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                        goto p_return_24;
                                    }
                                    if (p_this->isHalted == PRT_TRUE) {
                                        PrtFreeValue(_P_GEN_retval);
                                        _P_GEN_retval = NULL;
                                        goto p_return_24;
                                    }
                                    
                                    PRT_VALUE** P_LVALUE_473 = &(p_this->varValues[16]);
                                    PrtFreeValue(*P_LVALUE_473);
                                    *P_LVALUE_473 = PrtCloneValue((&P_LIT_INT32_34));
                                    
                                    PRT_VALUE** P_LVALUE_474 = &(p_this->varValues[18]);
                                    PrtFreeValue(*P_LVALUE_474);
                                    *P_LVALUE_474 = PrtCloneValue((&P_LIT_INT32_35));
                                    
                                    PRT_VALUE** P_LVALUE_475 = &(p_this->varValues[19]);
                                    PrtFreeValue(*P_LVALUE_475);
                                    *P_LVALUE_475 = PrtCloneValue((&P_LIT_INT32_33));
                                    
                                }
                                
                                
                            }
                            
                            
                        }
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_476 = &(p_this->varValues[17]);
            PrtFreeValue(*P_LVALUE_476);
            *P_LVALUE_476 = PrtCloneValue((&P_LIT_INT32_34));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_477 = &(PTMP_tmp28_3);
            PrtFreeValue(*P_LVALUE_477);
            *P_LVALUE_477 = PrtMkStringValue(PrtFormatString("CenterCliffAvoidanceController", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_478 = &(PTMP_tmp29_3);
            PrtFreeValue(*P_LVALUE_478);
            *P_LVALUE_478 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp28_3));
            
            if (PrtPrimGetBool(PTMP_tmp29_3))
            {
                PrtFreeValue(P_CenterCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_24;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_24;
                }
                
                PRT_VALUE** P_LVALUE_479 = &(p_this->varValues[16]);
                PrtFreeValue(*P_LVALUE_479);
                *P_LVALUE_479 = PrtCloneValue((&P_LIT_INT32_31));
                
                PRT_VALUE** P_LVALUE_480 = &(p_this->varValues[18]);
                PrtFreeValue(*P_LVALUE_480);
                *P_LVALUE_480 = PrtCloneValue((&P_LIT_INT32_32));
                
                PRT_VALUE** P_LVALUE_481 = &(p_this->varValues[19]);
                PrtFreeValue(*P_LVALUE_481);
                *P_LVALUE_481 = PrtCloneValue((&P_LIT_INT32_33));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_482 = &(PTMP_tmp30_3);
                PrtFreeValue(*P_LVALUE_482);
                *P_LVALUE_482 = PrtMkStringValue(PrtFormatString("RightCliffAvoidanceController", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_483 = &(PTMP_tmp31_3);
                PrtFreeValue(*P_LVALUE_483);
                *P_LVALUE_483 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp30_3));
                
                if (PrtPrimGetBool(PTMP_tmp31_3))
                {
                    PrtFreeValue(P_RightCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_24;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_24;
                    }
                    
                    PRT_VALUE** P_LVALUE_484 = &(p_this->varValues[16]);
                    PrtFreeValue(*P_LVALUE_484);
                    *P_LVALUE_484 = PrtCloneValue((&P_LIT_INT32_31));
                    
                    PRT_VALUE** P_LVALUE_485 = &(p_this->varValues[18]);
                    PrtFreeValue(*P_LVALUE_485);
                    *P_LVALUE_485 = PrtCloneValue((&P_LIT_INT32_32));
                    
                    PRT_VALUE** P_LVALUE_486 = &(p_this->varValues[19]);
                    PrtFreeValue(*P_LVALUE_486);
                    *P_LVALUE_486 = PrtCloneValue((&P_LIT_INT32_33));
                    
                }
                
                else
                {
                    PRT_VALUE** P_LVALUE_487 = &(PTMP_tmp32_3);
                    PrtFreeValue(*P_LVALUE_487);
                    *P_LVALUE_487 = PrtMkStringValue(PrtFormatString("LeftCliffAvoidanceController", 0, 0));
                    ;
                    
                    PRT_VALUE** P_LVALUE_488 = &(PTMP_tmp33_3);
                    PrtFreeValue(*P_LVALUE_488);
                    *P_LVALUE_488 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp32_3));
                    
                    if (PrtPrimGetBool(PTMP_tmp33_3))
                    {
                        PrtFreeValue(P_LeftCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                            goto p_return_24;
                        }
                        if (p_this->isHalted == PRT_TRUE) {
                            PrtFreeValue(_P_GEN_retval);
                            _P_GEN_retval = NULL;
                            goto p_return_24;
                        }
                        
                        PRT_VALUE** P_LVALUE_489 = &(p_this->varValues[16]);
                        PrtFreeValue(*P_LVALUE_489);
                        *P_LVALUE_489 = PrtCloneValue((&P_LIT_INT32_31));
                        
                        PRT_VALUE** P_LVALUE_490 = &(p_this->varValues[18]);
                        PrtFreeValue(*P_LVALUE_490);
                        *P_LVALUE_490 = PrtCloneValue((&P_LIT_INT32_32));
                        
                        PRT_VALUE** P_LVALUE_491 = &(p_this->varValues[19]);
                        PrtFreeValue(*P_LVALUE_491);
                        *P_LVALUE_491 = PrtCloneValue((&P_LIT_INT32_33));
                        
                    }
                    
                    else
                    {
                        PRT_VALUE** P_LVALUE_492 = &(PTMP_tmp34_3);
                        PrtFreeValue(*P_LVALUE_492);
                        *P_LVALUE_492 = PrtMkStringValue(PrtFormatString("RightObstacleAvoidanceController", 0, 0));
                        ;
                        
                        PRT_VALUE** P_LVALUE_493 = &(PTMP_tmp35_3);
                        PrtFreeValue(*P_LVALUE_493);
                        *P_LVALUE_493 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp34_3));
                        
                        if (PrtPrimGetBool(PTMP_tmp35_3))
                        {
                            PrtFreeValue(P_RightObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                goto p_return_24;
                            }
                            if (p_this->isHalted == PRT_TRUE) {
                                PrtFreeValue(_P_GEN_retval);
                                _P_GEN_retval = NULL;
                                goto p_return_24;
                            }
                            
                            PRT_VALUE** P_LVALUE_494 = &(p_this->varValues[16]);
                            PrtFreeValue(*P_LVALUE_494);
                            *P_LVALUE_494 = PrtCloneValue((&P_LIT_INT32_31));
                            
                            PRT_VALUE** P_LVALUE_495 = &(p_this->varValues[18]);
                            PrtFreeValue(*P_LVALUE_495);
                            *P_LVALUE_495 = PrtCloneValue((&P_LIT_INT32_32));
                            
                            PRT_VALUE** P_LVALUE_496 = &(p_this->varValues[19]);
                            PrtFreeValue(*P_LVALUE_496);
                            *P_LVALUE_496 = PrtCloneValue((&P_LIT_INT32_33));
                            
                        }
                        
                        else
                        {
                            PRT_VALUE** P_LVALUE_497 = &(PTMP_tmp36_2);
                            PrtFreeValue(*P_LVALUE_497);
                            *P_LVALUE_497 = PrtMkStringValue(PrtFormatString("LeftObstacleAvoidanceController", 0, 0));
                            ;
                            
                            PRT_VALUE** P_LVALUE_498 = &(PTMP_tmp37_2);
                            PrtFreeValue(*P_LVALUE_498);
                            *P_LVALUE_498 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp36_2));
                            
                            if (PrtPrimGetBool(PTMP_tmp37_2))
                            {
                                PrtFreeValue(P_LeftObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_24;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_24;
                                }
                                
                                PRT_VALUE** P_LVALUE_499 = &(p_this->varValues[16]);
                                PrtFreeValue(*P_LVALUE_499);
                                *P_LVALUE_499 = PrtCloneValue((&P_LIT_INT32_31));
                                
                                PRT_VALUE** P_LVALUE_500 = &(p_this->varValues[18]);
                                PrtFreeValue(*P_LVALUE_500);
                                *P_LVALUE_500 = PrtCloneValue((&P_LIT_INT32_32));
                                
                                PRT_VALUE** P_LVALUE_501 = &(p_this->varValues[19]);
                                PrtFreeValue(*P_LVALUE_501);
                                *P_LVALUE_501 = PrtCloneValue((&P_LIT_INT32_33));
                                
                            }
                            
                            else
                            {
                                PRT_VALUE** P_LVALUE_502 = &(PTMP_tmp38_2);
                                PrtFreeValue(*P_LVALUE_502);
                                *P_LVALUE_502 = PrtMkStringValue(PrtFormatString("SafeMotionController", 0, 0));
                                ;
                                
                                PRT_VALUE** P_LVALUE_503 = &(PTMP_tmp39_2);
                                PrtFreeValue(*P_LVALUE_503);
                                *P_LVALUE_503 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp38_2));
                                
                                if (PrtPrimGetBool(PTMP_tmp39_2))
                                {
                                    PrtFreeValue(P_SafeMotionController_IMPL(context, _P_GEN_funargs));
                                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                        goto p_return_24;
                                    }
                                    if (p_this->isHalted == PRT_TRUE) {
                                        PrtFreeValue(_P_GEN_retval);
                                        _P_GEN_retval = NULL;
                                        goto p_return_24;
                                    }
                                    
                                    PRT_VALUE** P_LVALUE_504 = &(p_this->varValues[16]);
                                    PrtFreeValue(*P_LVALUE_504);
                                    *P_LVALUE_504 = PrtCloneValue((&P_LIT_INT32_34));
                                    
                                    PRT_VALUE** P_LVALUE_505 = &(p_this->varValues[18]);
                                    PrtFreeValue(*P_LVALUE_505);
                                    *P_LVALUE_505 = PrtCloneValue((&P_LIT_INT32_35));
                                    
                                    PRT_VALUE** P_LVALUE_506 = &(p_this->varValues[19]);
                                    PrtFreeValue(*P_LVALUE_506);
                                    *P_LVALUE_506 = PrtCloneValue((&P_LIT_INT32_33));
                                    
                                }
                                
                                else
                                {
                                    PrtFreeValue(P_AdvancedMotionController_IMPL(context, _P_GEN_funargs));
                                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                        goto p_return_24;
                                    }
                                    if (p_this->isHalted == PRT_TRUE) {
                                        PrtFreeValue(_P_GEN_retval);
                                        _P_GEN_retval = NULL;
                                        goto p_return_24;
                                    }
                                    
                                    PRT_VALUE** P_LVALUE_507 = &(p_this->varValues[16]);
                                    PrtFreeValue(*P_LVALUE_507);
                                    *P_LVALUE_507 = PrtCloneValue((&P_LIT_INT32_34));
                                    
                                    PRT_VALUE** P_LVALUE_508 = &(p_this->varValues[18]);
                                    PrtFreeValue(*P_LVALUE_508);
                                    *P_LVALUE_508 = PrtCloneValue((&P_LIT_INT32_35));
                                    
                                    PRT_VALUE** P_LVALUE_509 = &(p_this->varValues[19]);
                                    PrtFreeValue(*P_LVALUE_509);
                                    *P_LVALUE_509 = PrtCloneValue((&P_LIT_INT32_33));
                                    
                                }
                                
                                
                            }
                            
                            
                        }
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_510 = &(PTMP_tmp40_1);
            PrtFreeValue(*P_LVALUE_510);
            *P_LVALUE_510 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[17]) + PrtPrimGetInt((&P_LIT_INT32_34)));
            
            {
                PRT_VALUE** P_LVALUE_511 = &(p_this->varValues[17]);
                PrtFreeValue(*P_LVALUE_511);
                *P_LVALUE_511 = PTMP_tmp40_1;
                PTMP_tmp40_1 = NULL;
            }
            
        }
        
        
    }
    
    
p_return_24: ;
    PrtFreeValue(PTMP_tmp0_18); PTMP_tmp0_18 = NULL;
    PrtFreeValue(PTMP_tmp1_18); PTMP_tmp1_18 = NULL;
    PrtFreeValue(PTMP_tmp2_18); PTMP_tmp2_18 = NULL;
    PrtFreeValue(PTMP_tmp3_18); PTMP_tmp3_18 = NULL;
    PrtFreeValue(PTMP_tmp4_18); PTMP_tmp4_18 = NULL;
    PrtFreeValue(PTMP_tmp5_18); PTMP_tmp5_18 = NULL;
    PrtFreeValue(PTMP_tmp6_17); PTMP_tmp6_17 = NULL;
    PrtFreeValue(PTMP_tmp7_11); PTMP_tmp7_11 = NULL;
    PrtFreeValue(PTMP_tmp8_8); PTMP_tmp8_8 = NULL;
    PrtFreeValue(PTMP_tmp9_8); PTMP_tmp9_8 = NULL;
    PrtFreeValue(PTMP_tmp10_8); PTMP_tmp10_8 = NULL;
    PrtFreeValue(PTMP_tmp11_8); PTMP_tmp11_8 = NULL;
    PrtFreeValue(PTMP_tmp12_5); PTMP_tmp12_5 = NULL;
    PrtFreeValue(PTMP_tmp13_5); PTMP_tmp13_5 = NULL;
    PrtFreeValue(PTMP_tmp14_5); PTMP_tmp14_5 = NULL;
    PrtFreeValue(PTMP_tmp15_4); PTMP_tmp15_4 = NULL;
    PrtFreeValue(PTMP_tmp16_4); PTMP_tmp16_4 = NULL;
    PrtFreeValue(PTMP_tmp17_4); PTMP_tmp17_4 = NULL;
    PrtFreeValue(PTMP_tmp18_4); PTMP_tmp18_4 = NULL;
    PrtFreeValue(PTMP_tmp19_4); PTMP_tmp19_4 = NULL;
    PrtFreeValue(PTMP_tmp20_3); PTMP_tmp20_3 = NULL;
    PrtFreeValue(PTMP_tmp21_3); PTMP_tmp21_3 = NULL;
    PrtFreeValue(PTMP_tmp22_3); PTMP_tmp22_3 = NULL;
    PrtFreeValue(PTMP_tmp23_3); PTMP_tmp23_3 = NULL;
    PrtFreeValue(PTMP_tmp24_3); PTMP_tmp24_3 = NULL;
    PrtFreeValue(PTMP_tmp25_3); PTMP_tmp25_3 = NULL;
    PrtFreeValue(PTMP_tmp26_3); PTMP_tmp26_3 = NULL;
    PrtFreeValue(PTMP_tmp27_3); PTMP_tmp27_3 = NULL;
    PrtFreeValue(PTMP_tmp28_3); PTMP_tmp28_3 = NULL;
    PrtFreeValue(PTMP_tmp29_3); PTMP_tmp29_3 = NULL;
    PrtFreeValue(PTMP_tmp30_3); PTMP_tmp30_3 = NULL;
    PrtFreeValue(PTMP_tmp31_3); PTMP_tmp31_3 = NULL;
    PrtFreeValue(PTMP_tmp32_3); PTMP_tmp32_3 = NULL;
    PrtFreeValue(PTMP_tmp33_3); PTMP_tmp33_3 = NULL;
    PrtFreeValue(PTMP_tmp34_3); PTMP_tmp34_3 = NULL;
    PrtFreeValue(PTMP_tmp35_3); PTMP_tmp35_3 = NULL;
    PrtFreeValue(PTMP_tmp36_2); PTMP_tmp36_2 = NULL;
    PrtFreeValue(PTMP_tmp37_2); PTMP_tmp37_2 = NULL;
    PrtFreeValue(PTMP_tmp38_2); PTMP_tmp38_2 = NULL;
    PrtFreeValue(PTMP_tmp39_2); PTMP_tmp39_2 = NULL;
    PrtFreeValue(PTMP_tmp40_1); PTMP_tmp40_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_9 =
{
    NULL,
    &P_Anon_IMPL_8,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_5 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_19 = NULL;
    PRT_VALUE* PTMP_tmp1_19 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_512 = &(PTMP_tmp0_19);
    PrtFreeValue(*P_LVALUE_512);
    *P_LVALUE_512 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[0]));
    
    PRT_VALUE** P_LVALUE_513 = &(PTMP_tmp1_19);
    PrtFreeValue(*P_LVALUE_513);
    *P_LVALUE_513 = PrtCloneValue(*P_VAR_payload_5);
    
    PrtSeqInsertEx(p_this->varValues[0], PTMP_tmp0_19, PTMP_tmp1_19, PRT_FALSE);
    *(&(PTMP_tmp1_19)) = NULL;
    
p_return_25: ;
    PrtFreeValue(PTMP_tmp0_19); PTMP_tmp0_19 = NULL;
    PrtFreeValue(PTMP_tmp1_19); PTMP_tmp1_19 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_11 =
{
    NULL,
    &P_Anon_IMPL_9,
    &P_GEND_TYPE_T2ff,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_6 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_20 = NULL;
    PRT_VALUE* PTMP_tmp1_20 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_514 = &(PTMP_tmp0_20);
    PrtFreeValue(*P_LVALUE_514);
    *P_LVALUE_514 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
    
    PRT_VALUE** P_LVALUE_515 = &(PTMP_tmp1_20);
    PrtFreeValue(*P_LVALUE_515);
    *P_LVALUE_515 = PrtCloneValue(*P_VAR_payload_6);
    
    PrtSeqInsertEx(p_this->varValues[2], PTMP_tmp0_20, PTMP_tmp1_20, PRT_FALSE);
    *(&(PTMP_tmp1_20)) = NULL;
    
p_return_26: ;
    PrtFreeValue(PTMP_tmp0_20); PTMP_tmp0_20 = NULL;
    PrtFreeValue(PTMP_tmp1_20); PTMP_tmp1_20 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_12 =
{
    NULL,
    &P_Anon_IMPL_10,
    &P_GEND_TYPE_T2ff,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_7 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_21 = NULL;
    PRT_VALUE* PTMP_tmp1_21 = NULL;
    PRT_VALUE* PTMP_tmp2_19 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_12 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_516 = &(PTMP_tmp0_21);
    PrtFreeValue(*P_LVALUE_516);
    *P_LVALUE_516 = PrtCloneValue(*P_VAR_payload_7);
    
    PRT_VALUE** P_LVALUE_517 = &(PTMP_tmp1_21);
    PrtFreeValue(*P_LVALUE_517);
    *P_LVALUE_517 = PrtCloneValue((&P_EVENT_eCurrentLocation.value));
    
    PRT_VALUE** P_LVALUE_518 = &(PTMP_tmp2_19);
    PrtFreeValue(*P_LVALUE_518);
    *P_LVALUE_518 = PrtCloneValue(p_this->varValues[6]);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_21), PTMP_tmp1_21, 1, &(PTMP_tmp2_19));
    *(&(PTMP_tmp1_21)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_27;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_27;
    }
    
    PRT_VALUE** P_LVALUE_519 = &(p_this->varValues[8]);
    PrtFreeValue(*P_LVALUE_519);
    *P_LVALUE_519 = PrtCloneValue(p_this->varValues[7]);
    
    PRT_VALUE** P_LVALUE_520 = &(p_this->varValues[13]);
    PrtFreeValue(*P_LVALUE_520);
    *P_LVALUE_520 = PrtCloneValue((&P_LIT_BOOLEAN_12));
    
p_return_27: ;
    PrtFreeValue(PTMP_tmp0_21); PTMP_tmp0_21 = NULL;
    PrtFreeValue(PTMP_tmp1_21); PTMP_tmp1_21 = NULL;
    PrtFreeValue(PTMP_tmp2_19); PTMP_tmp2_19 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_10 =
{
    NULL,
    &P_Anon_IMPL_11,
    &P_GEND_TYPE_m,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_36 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_13 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_521 = &(p_this->varValues[14]);
    PrtFreeValue(*P_LVALUE_521);
    *P_LVALUE_521 = PrtCloneValue((&P_LIT_BOOLEAN_13));
    
    PRT_VALUE** P_LVALUE_522 = &(p_this->varValues[17]);
    PrtFreeValue(*P_LVALUE_522);
    *P_LVALUE_522 = PrtCloneValue((&P_LIT_INT32_36));
    
p_return_28: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_12,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_22 = NULL;
    PRT_VALUE* PTMP_tmp1_22 = NULL;
    PRT_VALUE* PTMP_tmp2_20 = NULL;
    PRT_VALUE* PTMP_tmp3_19 = NULL;
    PRT_VALUE* PTMP_tmp4_19 = NULL;
    PRT_VALUE* PTMP_tmp5_19 = NULL;
    PRT_VALUE* PTMP_tmp6_18 = NULL;
    PRT_VALUE* PTMP_tmp7_12 = NULL;
    PRT_VALUE* PTMP_tmp8_9 = NULL;
    PRT_VALUE* PTMP_tmp9_9 = NULL;
    PRT_VALUE* PTMP_tmp10_9 = NULL;
    PRT_VALUE* PTMP_tmp11_9 = NULL;
    PRT_VALUE* PTMP_tmp12_6 = NULL;
    PRT_VALUE* PTMP_tmp13_6 = NULL;
    PRT_VALUE* PTMP_tmp14_6 = NULL;
    PRT_VALUE* PTMP_tmp15_5 = NULL;
    PRT_VALUE* PTMP_tmp16_5 = NULL;
    PRT_VALUE* PTMP_tmp17_5 = NULL;
    PRT_VALUE* PTMP_tmp18_5 = NULL;
    PRT_VALUE* PTMP_tmp19_5 = NULL;
    PRT_VALUE* PTMP_tmp20_4 = NULL;
    PRT_VALUE* PTMP_tmp21_4 = NULL;
    PRT_VALUE* PTMP_tmp22_4 = NULL;
    PRT_VALUE* PTMP_tmp23_4 = NULL;
    PRT_VALUE* PTMP_tmp24_4 = NULL;
    PRT_VALUE* PTMP_tmp25_4 = NULL;
    PRT_VALUE* PTMP_tmp26_4 = NULL;
    PRT_VALUE* PTMP_tmp27_4 = NULL;
    PRT_VALUE* PTMP_tmp28_4 = NULL;
    PRT_VALUE* PTMP_tmp29_4 = NULL;
    PRT_VALUE* PTMP_tmp30_4 = NULL;
    PRT_VALUE* PTMP_tmp31_4 = NULL;
    PRT_VALUE* PTMP_tmp32_4 = NULL;
    PRT_VALUE* PTMP_tmp33_4 = NULL;
    PRT_VALUE* PTMP_tmp34_4 = NULL;
    PRT_VALUE* PTMP_tmp35_4 = NULL;
    PRT_VALUE* PTMP_tmp36_3 = NULL;
    PRT_VALUE* PTMP_tmp37_3 = NULL;
    PRT_VALUE* PTMP_tmp38_3 = NULL;
    PRT_VALUE* PTMP_tmp39_3 = NULL;
    PRT_VALUE* PTMP_tmp40_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_37 = { PRT_VALUE_KIND_INT, { .nt = 20 } };
    PRT_VALUE P_LIT_INT32_38 = { PRT_VALUE_KIND_INT, { .nt = 200 } };
    PRT_VALUE P_LIT_INT32_39 = { PRT_VALUE_KIND_INT, { .nt = 6 } };
    PRT_VALUE P_LIT_INT32_40 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_41 = { PRT_VALUE_KIND_INT, { .nt = 50 } };
    PRT_VALUE P_LIT_BOOLEAN_14 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_523 = &(PTMP_tmp0_22);
    PrtFreeValue(*P_LVALUE_523);
    *P_LVALUE_523 = PrtMkBoolValue(!PrtPrimGetBool(p_this->varValues[14]));
    
    if (PrtPrimGetBool(PTMP_tmp0_22))
    {
        PRT_VALUE** P_LVALUE_524 = &(p_this->varValues[14]);
        PrtFreeValue(*P_LVALUE_524);
        *P_LVALUE_524 = PrtCloneValue((&P_LIT_BOOLEAN_14));
        
        PRT_VALUE** P_LVALUE_525 = &(PTMP_tmp1_22);
        PrtFreeValue(*P_LVALUE_525);
        *P_LVALUE_525 = ((_P_GEN_funval = P_DM_IMPL_2(context, _P_GEN_funargs)), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_29;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_29;
        }
        
        {
            PRT_VALUE** P_LVALUE_526 = &(p_this->varValues[15]);
            PrtFreeValue(*P_LVALUE_526);
            *P_LVALUE_526 = PTMP_tmp1_22;
            PTMP_tmp1_22 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_527 = &(PTMP_tmp2_20);
        PrtFreeValue(*P_LVALUE_527);
        *P_LVALUE_527 = PrtMkStringValue(PrtFormatString("CenterCliffAvoidanceController", 0, 0));
        ;
        
        PRT_VALUE** P_LVALUE_528 = &(PTMP_tmp3_19);
        PrtFreeValue(*P_LVALUE_528);
        *P_LVALUE_528 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp2_20));
        
        if (PrtPrimGetBool(PTMP_tmp3_19))
        {
            PrtFreeValue(P_CenterCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_29;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_29;
            }
            
            PRT_VALUE** P_LVALUE_529 = &(p_this->varValues[16]);
            PrtFreeValue(*P_LVALUE_529);
            *P_LVALUE_529 = PrtCloneValue((&P_LIT_INT32_37));
            
            PRT_VALUE** P_LVALUE_530 = &(p_this->varValues[18]);
            PrtFreeValue(*P_LVALUE_530);
            *P_LVALUE_530 = PrtCloneValue((&P_LIT_INT32_38));
            
            PRT_VALUE** P_LVALUE_531 = &(p_this->varValues[19]);
            PrtFreeValue(*P_LVALUE_531);
            *P_LVALUE_531 = PrtCloneValue((&P_LIT_INT32_39));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_532 = &(PTMP_tmp4_19);
            PrtFreeValue(*P_LVALUE_532);
            *P_LVALUE_532 = PrtMkStringValue(PrtFormatString("RightCliffAvoidanceController", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_533 = &(PTMP_tmp5_19);
            PrtFreeValue(*P_LVALUE_533);
            *P_LVALUE_533 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp4_19));
            
            if (PrtPrimGetBool(PTMP_tmp5_19))
            {
                PrtFreeValue(P_RightCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_29;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_29;
                }
                
                PRT_VALUE** P_LVALUE_534 = &(p_this->varValues[16]);
                PrtFreeValue(*P_LVALUE_534);
                *P_LVALUE_534 = PrtCloneValue((&P_LIT_INT32_37));
                
                PRT_VALUE** P_LVALUE_535 = &(p_this->varValues[18]);
                PrtFreeValue(*P_LVALUE_535);
                *P_LVALUE_535 = PrtCloneValue((&P_LIT_INT32_38));
                
                PRT_VALUE** P_LVALUE_536 = &(p_this->varValues[19]);
                PrtFreeValue(*P_LVALUE_536);
                *P_LVALUE_536 = PrtCloneValue((&P_LIT_INT32_39));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_537 = &(PTMP_tmp6_18);
                PrtFreeValue(*P_LVALUE_537);
                *P_LVALUE_537 = PrtMkStringValue(PrtFormatString("LeftCliffAvoidanceController", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_538 = &(PTMP_tmp7_12);
                PrtFreeValue(*P_LVALUE_538);
                *P_LVALUE_538 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp6_18));
                
                if (PrtPrimGetBool(PTMP_tmp7_12))
                {
                    PrtFreeValue(P_LeftCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_29;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_29;
                    }
                    
                    PRT_VALUE** P_LVALUE_539 = &(p_this->varValues[16]);
                    PrtFreeValue(*P_LVALUE_539);
                    *P_LVALUE_539 = PrtCloneValue((&P_LIT_INT32_37));
                    
                    PRT_VALUE** P_LVALUE_540 = &(p_this->varValues[18]);
                    PrtFreeValue(*P_LVALUE_540);
                    *P_LVALUE_540 = PrtCloneValue((&P_LIT_INT32_38));
                    
                    PRT_VALUE** P_LVALUE_541 = &(p_this->varValues[19]);
                    PrtFreeValue(*P_LVALUE_541);
                    *P_LVALUE_541 = PrtCloneValue((&P_LIT_INT32_39));
                    
                }
                
                else
                {
                    PRT_VALUE** P_LVALUE_542 = &(PTMP_tmp8_9);
                    PrtFreeValue(*P_LVALUE_542);
                    *P_LVALUE_542 = PrtMkStringValue(PrtFormatString("RightObstacleAvoidanceController", 0, 0));
                    ;
                    
                    PRT_VALUE** P_LVALUE_543 = &(PTMP_tmp9_9);
                    PrtFreeValue(*P_LVALUE_543);
                    *P_LVALUE_543 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp8_9));
                    
                    if (PrtPrimGetBool(PTMP_tmp9_9))
                    {
                        PrtFreeValue(P_RightObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                            goto p_return_29;
                        }
                        if (p_this->isHalted == PRT_TRUE) {
                            PrtFreeValue(_P_GEN_retval);
                            _P_GEN_retval = NULL;
                            goto p_return_29;
                        }
                        
                        PRT_VALUE** P_LVALUE_544 = &(p_this->varValues[16]);
                        PrtFreeValue(*P_LVALUE_544);
                        *P_LVALUE_544 = PrtCloneValue((&P_LIT_INT32_37));
                        
                        PRT_VALUE** P_LVALUE_545 = &(p_this->varValues[18]);
                        PrtFreeValue(*P_LVALUE_545);
                        *P_LVALUE_545 = PrtCloneValue((&P_LIT_INT32_38));
                        
                        PRT_VALUE** P_LVALUE_546 = &(p_this->varValues[19]);
                        PrtFreeValue(*P_LVALUE_546);
                        *P_LVALUE_546 = PrtCloneValue((&P_LIT_INT32_39));
                        
                    }
                    
                    else
                    {
                        PRT_VALUE** P_LVALUE_547 = &(PTMP_tmp10_9);
                        PrtFreeValue(*P_LVALUE_547);
                        *P_LVALUE_547 = PrtMkStringValue(PrtFormatString("LeftObstacleAvoidanceController", 0, 0));
                        ;
                        
                        PRT_VALUE** P_LVALUE_548 = &(PTMP_tmp11_9);
                        PrtFreeValue(*P_LVALUE_548);
                        *P_LVALUE_548 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp10_9));
                        
                        if (PrtPrimGetBool(PTMP_tmp11_9))
                        {
                            PrtFreeValue(P_LeftObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                goto p_return_29;
                            }
                            if (p_this->isHalted == PRT_TRUE) {
                                PrtFreeValue(_P_GEN_retval);
                                _P_GEN_retval = NULL;
                                goto p_return_29;
                            }
                            
                            PRT_VALUE** P_LVALUE_549 = &(p_this->varValues[16]);
                            PrtFreeValue(*P_LVALUE_549);
                            *P_LVALUE_549 = PrtCloneValue((&P_LIT_INT32_37));
                            
                            PRT_VALUE** P_LVALUE_550 = &(p_this->varValues[18]);
                            PrtFreeValue(*P_LVALUE_550);
                            *P_LVALUE_550 = PrtCloneValue((&P_LIT_INT32_38));
                            
                            PRT_VALUE** P_LVALUE_551 = &(p_this->varValues[19]);
                            PrtFreeValue(*P_LVALUE_551);
                            *P_LVALUE_551 = PrtCloneValue((&P_LIT_INT32_39));
                            
                        }
                        
                        else
                        {
                            PRT_VALUE** P_LVALUE_552 = &(PTMP_tmp12_6);
                            PrtFreeValue(*P_LVALUE_552);
                            *P_LVALUE_552 = PrtMkStringValue(PrtFormatString("SafeMotionController", 0, 0));
                            ;
                            
                            PRT_VALUE** P_LVALUE_553 = &(PTMP_tmp13_6);
                            PrtFreeValue(*P_LVALUE_553);
                            *P_LVALUE_553 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp12_6));
                            
                            if (PrtPrimGetBool(PTMP_tmp13_6))
                            {
                                PrtFreeValue(P_SafeMotionController_IMPL(context, _P_GEN_funargs));
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_29;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_29;
                                }
                                
                                PRT_VALUE** P_LVALUE_554 = &(p_this->varValues[16]);
                                PrtFreeValue(*P_LVALUE_554);
                                *P_LVALUE_554 = PrtCloneValue((&P_LIT_INT32_40));
                                
                                PRT_VALUE** P_LVALUE_555 = &(p_this->varValues[18]);
                                PrtFreeValue(*P_LVALUE_555);
                                *P_LVALUE_555 = PrtCloneValue((&P_LIT_INT32_41));
                                
                                PRT_VALUE** P_LVALUE_556 = &(p_this->varValues[19]);
                                PrtFreeValue(*P_LVALUE_556);
                                *P_LVALUE_556 = PrtCloneValue((&P_LIT_INT32_39));
                                
                            }
                            
                            else
                            {
                                PrtFreeValue(P_AdvancedMotionController_IMPL(context, _P_GEN_funargs));
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_29;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_29;
                                }
                                
                                PRT_VALUE** P_LVALUE_557 = &(p_this->varValues[16]);
                                PrtFreeValue(*P_LVALUE_557);
                                *P_LVALUE_557 = PrtCloneValue((&P_LIT_INT32_40));
                                
                                PRT_VALUE** P_LVALUE_558 = &(p_this->varValues[18]);
                                PrtFreeValue(*P_LVALUE_558);
                                *P_LVALUE_558 = PrtCloneValue((&P_LIT_INT32_41));
                                
                                PRT_VALUE** P_LVALUE_559 = &(p_this->varValues[19]);
                                PrtFreeValue(*P_LVALUE_559);
                                *P_LVALUE_559 = PrtCloneValue((&P_LIT_INT32_39));
                                
                            }
                            
                            
                        }
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            
        }
        
        
        PRT_VALUE** P_LVALUE_560 = &(p_this->varValues[17]);
        PrtFreeValue(*P_LVALUE_560);
        *P_LVALUE_560 = PrtCloneValue((&P_LIT_INT32_40));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_561 = &(PTMP_tmp14_6);
        PrtFreeValue(*P_LVALUE_561);
        *P_LVALUE_561 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[16], p_this->varValues[17]));
        
        if (PrtPrimGetBool(PTMP_tmp14_6))
        {
            PRT_VALUE** P_LVALUE_562 = &(PTMP_tmp15_5);
            PrtFreeValue(*P_LVALUE_562);
            *P_LVALUE_562 = ((_P_GEN_funval = P_DM_IMPL_2(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_29;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_29;
            }
            
            {
                PRT_VALUE** P_LVALUE_563 = &(p_this->varValues[15]);
                PrtFreeValue(*P_LVALUE_563);
                *P_LVALUE_563 = PTMP_tmp15_5;
                PTMP_tmp15_5 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_564 = &(PTMP_tmp16_5);
            PrtFreeValue(*P_LVALUE_564);
            *P_LVALUE_564 = PrtMkStringValue(PrtFormatString("CenterCliffAvoidanceController", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_565 = &(PTMP_tmp17_5);
            PrtFreeValue(*P_LVALUE_565);
            *P_LVALUE_565 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp16_5));
            
            if (PrtPrimGetBool(PTMP_tmp17_5))
            {
                PrtFreeValue(P_CenterCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_29;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_29;
                }
                
                PRT_VALUE** P_LVALUE_566 = &(p_this->varValues[16]);
                PrtFreeValue(*P_LVALUE_566);
                *P_LVALUE_566 = PrtCloneValue((&P_LIT_INT32_37));
                
                PRT_VALUE** P_LVALUE_567 = &(p_this->varValues[18]);
                PrtFreeValue(*P_LVALUE_567);
                *P_LVALUE_567 = PrtCloneValue((&P_LIT_INT32_38));
                
                PRT_VALUE** P_LVALUE_568 = &(p_this->varValues[19]);
                PrtFreeValue(*P_LVALUE_568);
                *P_LVALUE_568 = PrtCloneValue((&P_LIT_INT32_39));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_569 = &(PTMP_tmp18_5);
                PrtFreeValue(*P_LVALUE_569);
                *P_LVALUE_569 = PrtMkStringValue(PrtFormatString("RightCliffAvoidanceController", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_570 = &(PTMP_tmp19_5);
                PrtFreeValue(*P_LVALUE_570);
                *P_LVALUE_570 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp18_5));
                
                if (PrtPrimGetBool(PTMP_tmp19_5))
                {
                    PrtFreeValue(P_RightCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_29;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_29;
                    }
                    
                    PRT_VALUE** P_LVALUE_571 = &(p_this->varValues[16]);
                    PrtFreeValue(*P_LVALUE_571);
                    *P_LVALUE_571 = PrtCloneValue((&P_LIT_INT32_37));
                    
                    PRT_VALUE** P_LVALUE_572 = &(p_this->varValues[18]);
                    PrtFreeValue(*P_LVALUE_572);
                    *P_LVALUE_572 = PrtCloneValue((&P_LIT_INT32_38));
                    
                    PRT_VALUE** P_LVALUE_573 = &(p_this->varValues[19]);
                    PrtFreeValue(*P_LVALUE_573);
                    *P_LVALUE_573 = PrtCloneValue((&P_LIT_INT32_39));
                    
                }
                
                else
                {
                    PRT_VALUE** P_LVALUE_574 = &(PTMP_tmp20_4);
                    PrtFreeValue(*P_LVALUE_574);
                    *P_LVALUE_574 = PrtMkStringValue(PrtFormatString("LeftCliffAvoidanceController", 0, 0));
                    ;
                    
                    PRT_VALUE** P_LVALUE_575 = &(PTMP_tmp21_4);
                    PrtFreeValue(*P_LVALUE_575);
                    *P_LVALUE_575 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp20_4));
                    
                    if (PrtPrimGetBool(PTMP_tmp21_4))
                    {
                        PrtFreeValue(P_LeftCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                            goto p_return_29;
                        }
                        if (p_this->isHalted == PRT_TRUE) {
                            PrtFreeValue(_P_GEN_retval);
                            _P_GEN_retval = NULL;
                            goto p_return_29;
                        }
                        
                        PRT_VALUE** P_LVALUE_576 = &(p_this->varValues[16]);
                        PrtFreeValue(*P_LVALUE_576);
                        *P_LVALUE_576 = PrtCloneValue((&P_LIT_INT32_37));
                        
                        PRT_VALUE** P_LVALUE_577 = &(p_this->varValues[18]);
                        PrtFreeValue(*P_LVALUE_577);
                        *P_LVALUE_577 = PrtCloneValue((&P_LIT_INT32_38));
                        
                        PRT_VALUE** P_LVALUE_578 = &(p_this->varValues[19]);
                        PrtFreeValue(*P_LVALUE_578);
                        *P_LVALUE_578 = PrtCloneValue((&P_LIT_INT32_39));
                        
                    }
                    
                    else
                    {
                        PRT_VALUE** P_LVALUE_579 = &(PTMP_tmp22_4);
                        PrtFreeValue(*P_LVALUE_579);
                        *P_LVALUE_579 = PrtMkStringValue(PrtFormatString("RightObstacleAvoidanceController", 0, 0));
                        ;
                        
                        PRT_VALUE** P_LVALUE_580 = &(PTMP_tmp23_4);
                        PrtFreeValue(*P_LVALUE_580);
                        *P_LVALUE_580 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp22_4));
                        
                        if (PrtPrimGetBool(PTMP_tmp23_4))
                        {
                            PrtFreeValue(P_RightObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                goto p_return_29;
                            }
                            if (p_this->isHalted == PRT_TRUE) {
                                PrtFreeValue(_P_GEN_retval);
                                _P_GEN_retval = NULL;
                                goto p_return_29;
                            }
                            
                            PRT_VALUE** P_LVALUE_581 = &(p_this->varValues[16]);
                            PrtFreeValue(*P_LVALUE_581);
                            *P_LVALUE_581 = PrtCloneValue((&P_LIT_INT32_37));
                            
                            PRT_VALUE** P_LVALUE_582 = &(p_this->varValues[18]);
                            PrtFreeValue(*P_LVALUE_582);
                            *P_LVALUE_582 = PrtCloneValue((&P_LIT_INT32_38));
                            
                            PRT_VALUE** P_LVALUE_583 = &(p_this->varValues[19]);
                            PrtFreeValue(*P_LVALUE_583);
                            *P_LVALUE_583 = PrtCloneValue((&P_LIT_INT32_39));
                            
                        }
                        
                        else
                        {
                            PRT_VALUE** P_LVALUE_584 = &(PTMP_tmp24_4);
                            PrtFreeValue(*P_LVALUE_584);
                            *P_LVALUE_584 = PrtMkStringValue(PrtFormatString("LeftObstacleAvoidanceController", 0, 0));
                            ;
                            
                            PRT_VALUE** P_LVALUE_585 = &(PTMP_tmp25_4);
                            PrtFreeValue(*P_LVALUE_585);
                            *P_LVALUE_585 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp24_4));
                            
                            if (PrtPrimGetBool(PTMP_tmp25_4))
                            {
                                PrtFreeValue(P_LeftObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_29;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_29;
                                }
                                
                                PRT_VALUE** P_LVALUE_586 = &(p_this->varValues[16]);
                                PrtFreeValue(*P_LVALUE_586);
                                *P_LVALUE_586 = PrtCloneValue((&P_LIT_INT32_37));
                                
                                PRT_VALUE** P_LVALUE_587 = &(p_this->varValues[18]);
                                PrtFreeValue(*P_LVALUE_587);
                                *P_LVALUE_587 = PrtCloneValue((&P_LIT_INT32_38));
                                
                                PRT_VALUE** P_LVALUE_588 = &(p_this->varValues[19]);
                                PrtFreeValue(*P_LVALUE_588);
                                *P_LVALUE_588 = PrtCloneValue((&P_LIT_INT32_39));
                                
                            }
                            
                            else
                            {
                                PRT_VALUE** P_LVALUE_589 = &(PTMP_tmp26_4);
                                PrtFreeValue(*P_LVALUE_589);
                                *P_LVALUE_589 = PrtMkStringValue(PrtFormatString("SafeMotionController", 0, 0));
                                ;
                                
                                PRT_VALUE** P_LVALUE_590 = &(PTMP_tmp27_4);
                                PrtFreeValue(*P_LVALUE_590);
                                *P_LVALUE_590 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp26_4));
                                
                                if (PrtPrimGetBool(PTMP_tmp27_4))
                                {
                                    PrtFreeValue(P_SafeMotionController_IMPL(context, _P_GEN_funargs));
                                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                        goto p_return_29;
                                    }
                                    if (p_this->isHalted == PRT_TRUE) {
                                        PrtFreeValue(_P_GEN_retval);
                                        _P_GEN_retval = NULL;
                                        goto p_return_29;
                                    }
                                    
                                    PRT_VALUE** P_LVALUE_591 = &(p_this->varValues[16]);
                                    PrtFreeValue(*P_LVALUE_591);
                                    *P_LVALUE_591 = PrtCloneValue((&P_LIT_INT32_40));
                                    
                                    PRT_VALUE** P_LVALUE_592 = &(p_this->varValues[18]);
                                    PrtFreeValue(*P_LVALUE_592);
                                    *P_LVALUE_592 = PrtCloneValue((&P_LIT_INT32_41));
                                    
                                    PRT_VALUE** P_LVALUE_593 = &(p_this->varValues[19]);
                                    PrtFreeValue(*P_LVALUE_593);
                                    *P_LVALUE_593 = PrtCloneValue((&P_LIT_INT32_39));
                                    
                                }
                                
                                else
                                {
                                    PrtFreeValue(P_AdvancedMotionController_IMPL(context, _P_GEN_funargs));
                                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                        goto p_return_29;
                                    }
                                    if (p_this->isHalted == PRT_TRUE) {
                                        PrtFreeValue(_P_GEN_retval);
                                        _P_GEN_retval = NULL;
                                        goto p_return_29;
                                    }
                                    
                                    PRT_VALUE** P_LVALUE_594 = &(p_this->varValues[16]);
                                    PrtFreeValue(*P_LVALUE_594);
                                    *P_LVALUE_594 = PrtCloneValue((&P_LIT_INT32_40));
                                    
                                    PRT_VALUE** P_LVALUE_595 = &(p_this->varValues[18]);
                                    PrtFreeValue(*P_LVALUE_595);
                                    *P_LVALUE_595 = PrtCloneValue((&P_LIT_INT32_41));
                                    
                                    PRT_VALUE** P_LVALUE_596 = &(p_this->varValues[19]);
                                    PrtFreeValue(*P_LVALUE_596);
                                    *P_LVALUE_596 = PrtCloneValue((&P_LIT_INT32_39));
                                    
                                }
                                
                                
                            }
                            
                            
                        }
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_597 = &(p_this->varValues[17]);
            PrtFreeValue(*P_LVALUE_597);
            *P_LVALUE_597 = PrtCloneValue((&P_LIT_INT32_40));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_598 = &(PTMP_tmp28_4);
            PrtFreeValue(*P_LVALUE_598);
            *P_LVALUE_598 = PrtMkStringValue(PrtFormatString("CenterCliffAvoidanceController", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_599 = &(PTMP_tmp29_4);
            PrtFreeValue(*P_LVALUE_599);
            *P_LVALUE_599 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp28_4));
            
            if (PrtPrimGetBool(PTMP_tmp29_4))
            {
                PrtFreeValue(P_CenterCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_29;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_29;
                }
                
                PRT_VALUE** P_LVALUE_600 = &(p_this->varValues[16]);
                PrtFreeValue(*P_LVALUE_600);
                *P_LVALUE_600 = PrtCloneValue((&P_LIT_INT32_37));
                
                PRT_VALUE** P_LVALUE_601 = &(p_this->varValues[18]);
                PrtFreeValue(*P_LVALUE_601);
                *P_LVALUE_601 = PrtCloneValue((&P_LIT_INT32_38));
                
                PRT_VALUE** P_LVALUE_602 = &(p_this->varValues[19]);
                PrtFreeValue(*P_LVALUE_602);
                *P_LVALUE_602 = PrtCloneValue((&P_LIT_INT32_39));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_603 = &(PTMP_tmp30_4);
                PrtFreeValue(*P_LVALUE_603);
                *P_LVALUE_603 = PrtMkStringValue(PrtFormatString("RightCliffAvoidanceController", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_604 = &(PTMP_tmp31_4);
                PrtFreeValue(*P_LVALUE_604);
                *P_LVALUE_604 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp30_4));
                
                if (PrtPrimGetBool(PTMP_tmp31_4))
                {
                    PrtFreeValue(P_RightCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_29;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_29;
                    }
                    
                    PRT_VALUE** P_LVALUE_605 = &(p_this->varValues[16]);
                    PrtFreeValue(*P_LVALUE_605);
                    *P_LVALUE_605 = PrtCloneValue((&P_LIT_INT32_37));
                    
                    PRT_VALUE** P_LVALUE_606 = &(p_this->varValues[18]);
                    PrtFreeValue(*P_LVALUE_606);
                    *P_LVALUE_606 = PrtCloneValue((&P_LIT_INT32_38));
                    
                    PRT_VALUE** P_LVALUE_607 = &(p_this->varValues[19]);
                    PrtFreeValue(*P_LVALUE_607);
                    *P_LVALUE_607 = PrtCloneValue((&P_LIT_INT32_39));
                    
                }
                
                else
                {
                    PRT_VALUE** P_LVALUE_608 = &(PTMP_tmp32_4);
                    PrtFreeValue(*P_LVALUE_608);
                    *P_LVALUE_608 = PrtMkStringValue(PrtFormatString("LeftCliffAvoidanceController", 0, 0));
                    ;
                    
                    PRT_VALUE** P_LVALUE_609 = &(PTMP_tmp33_4);
                    PrtFreeValue(*P_LVALUE_609);
                    *P_LVALUE_609 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp32_4));
                    
                    if (PrtPrimGetBool(PTMP_tmp33_4))
                    {
                        PrtFreeValue(P_LeftCliffAvoidanceController_IMPL(context, _P_GEN_funargs));
                        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                            goto p_return_29;
                        }
                        if (p_this->isHalted == PRT_TRUE) {
                            PrtFreeValue(_P_GEN_retval);
                            _P_GEN_retval = NULL;
                            goto p_return_29;
                        }
                        
                        PRT_VALUE** P_LVALUE_610 = &(p_this->varValues[16]);
                        PrtFreeValue(*P_LVALUE_610);
                        *P_LVALUE_610 = PrtCloneValue((&P_LIT_INT32_37));
                        
                        PRT_VALUE** P_LVALUE_611 = &(p_this->varValues[18]);
                        PrtFreeValue(*P_LVALUE_611);
                        *P_LVALUE_611 = PrtCloneValue((&P_LIT_INT32_38));
                        
                        PRT_VALUE** P_LVALUE_612 = &(p_this->varValues[19]);
                        PrtFreeValue(*P_LVALUE_612);
                        *P_LVALUE_612 = PrtCloneValue((&P_LIT_INT32_39));
                        
                    }
                    
                    else
                    {
                        PRT_VALUE** P_LVALUE_613 = &(PTMP_tmp34_4);
                        PrtFreeValue(*P_LVALUE_613);
                        *P_LVALUE_613 = PrtMkStringValue(PrtFormatString("RightObstacleAvoidanceController", 0, 0));
                        ;
                        
                        PRT_VALUE** P_LVALUE_614 = &(PTMP_tmp35_4);
                        PrtFreeValue(*P_LVALUE_614);
                        *P_LVALUE_614 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp34_4));
                        
                        if (PrtPrimGetBool(PTMP_tmp35_4))
                        {
                            PrtFreeValue(P_RightObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                goto p_return_29;
                            }
                            if (p_this->isHalted == PRT_TRUE) {
                                PrtFreeValue(_P_GEN_retval);
                                _P_GEN_retval = NULL;
                                goto p_return_29;
                            }
                            
                            PRT_VALUE** P_LVALUE_615 = &(p_this->varValues[16]);
                            PrtFreeValue(*P_LVALUE_615);
                            *P_LVALUE_615 = PrtCloneValue((&P_LIT_INT32_37));
                            
                            PRT_VALUE** P_LVALUE_616 = &(p_this->varValues[18]);
                            PrtFreeValue(*P_LVALUE_616);
                            *P_LVALUE_616 = PrtCloneValue((&P_LIT_INT32_38));
                            
                            PRT_VALUE** P_LVALUE_617 = &(p_this->varValues[19]);
                            PrtFreeValue(*P_LVALUE_617);
                            *P_LVALUE_617 = PrtCloneValue((&P_LIT_INT32_39));
                            
                        }
                        
                        else
                        {
                            PRT_VALUE** P_LVALUE_618 = &(PTMP_tmp36_3);
                            PrtFreeValue(*P_LVALUE_618);
                            *P_LVALUE_618 = PrtMkStringValue(PrtFormatString("LeftObstacleAvoidanceController", 0, 0));
                            ;
                            
                            PRT_VALUE** P_LVALUE_619 = &(PTMP_tmp37_3);
                            PrtFreeValue(*P_LVALUE_619);
                            *P_LVALUE_619 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp36_3));
                            
                            if (PrtPrimGetBool(PTMP_tmp37_3))
                            {
                                PrtFreeValue(P_LeftObstacleAvoidanceController_IMPL(context, _P_GEN_funargs));
                                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                    goto p_return_29;
                                }
                                if (p_this->isHalted == PRT_TRUE) {
                                    PrtFreeValue(_P_GEN_retval);
                                    _P_GEN_retval = NULL;
                                    goto p_return_29;
                                }
                                
                                PRT_VALUE** P_LVALUE_620 = &(p_this->varValues[16]);
                                PrtFreeValue(*P_LVALUE_620);
                                *P_LVALUE_620 = PrtCloneValue((&P_LIT_INT32_37));
                                
                                PRT_VALUE** P_LVALUE_621 = &(p_this->varValues[18]);
                                PrtFreeValue(*P_LVALUE_621);
                                *P_LVALUE_621 = PrtCloneValue((&P_LIT_INT32_38));
                                
                                PRT_VALUE** P_LVALUE_622 = &(p_this->varValues[19]);
                                PrtFreeValue(*P_LVALUE_622);
                                *P_LVALUE_622 = PrtCloneValue((&P_LIT_INT32_39));
                                
                            }
                            
                            else
                            {
                                PRT_VALUE** P_LVALUE_623 = &(PTMP_tmp38_3);
                                PrtFreeValue(*P_LVALUE_623);
                                *P_LVALUE_623 = PrtMkStringValue(PrtFormatString("SafeMotionController", 0, 0));
                                ;
                                
                                PRT_VALUE** P_LVALUE_624 = &(PTMP_tmp39_3);
                                PrtFreeValue(*P_LVALUE_624);
                                *P_LVALUE_624 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[15], PTMP_tmp38_3));
                                
                                if (PrtPrimGetBool(PTMP_tmp39_3))
                                {
                                    PrtFreeValue(P_SafeMotionController_IMPL(context, _P_GEN_funargs));
                                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                        goto p_return_29;
                                    }
                                    if (p_this->isHalted == PRT_TRUE) {
                                        PrtFreeValue(_P_GEN_retval);
                                        _P_GEN_retval = NULL;
                                        goto p_return_29;
                                    }
                                    
                                    PRT_VALUE** P_LVALUE_625 = &(p_this->varValues[16]);
                                    PrtFreeValue(*P_LVALUE_625);
                                    *P_LVALUE_625 = PrtCloneValue((&P_LIT_INT32_40));
                                    
                                    PRT_VALUE** P_LVALUE_626 = &(p_this->varValues[18]);
                                    PrtFreeValue(*P_LVALUE_626);
                                    *P_LVALUE_626 = PrtCloneValue((&P_LIT_INT32_41));
                                    
                                    PRT_VALUE** P_LVALUE_627 = &(p_this->varValues[19]);
                                    PrtFreeValue(*P_LVALUE_627);
                                    *P_LVALUE_627 = PrtCloneValue((&P_LIT_INT32_39));
                                    
                                }
                                
                                else
                                {
                                    PrtFreeValue(P_AdvancedMotionController_IMPL(context, _P_GEN_funargs));
                                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                                        goto p_return_29;
                                    }
                                    if (p_this->isHalted == PRT_TRUE) {
                                        PrtFreeValue(_P_GEN_retval);
                                        _P_GEN_retval = NULL;
                                        goto p_return_29;
                                    }
                                    
                                    PRT_VALUE** P_LVALUE_628 = &(p_this->varValues[16]);
                                    PrtFreeValue(*P_LVALUE_628);
                                    *P_LVALUE_628 = PrtCloneValue((&P_LIT_INT32_40));
                                    
                                    PRT_VALUE** P_LVALUE_629 = &(p_this->varValues[18]);
                                    PrtFreeValue(*P_LVALUE_629);
                                    *P_LVALUE_629 = PrtCloneValue((&P_LIT_INT32_41));
                                    
                                    PRT_VALUE** P_LVALUE_630 = &(p_this->varValues[19]);
                                    PrtFreeValue(*P_LVALUE_630);
                                    *P_LVALUE_630 = PrtCloneValue((&P_LIT_INT32_39));
                                    
                                }
                                
                                
                            }
                            
                            
                        }
                        
                        
                    }
                    
                    
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_631 = &(PTMP_tmp40_2);
            PrtFreeValue(*P_LVALUE_631);
            *P_LVALUE_631 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[17]) + PrtPrimGetInt((&P_LIT_INT32_40)));
            
            {
                PRT_VALUE** P_LVALUE_632 = &(p_this->varValues[17]);
                PrtFreeValue(*P_LVALUE_632);
                *P_LVALUE_632 = PTMP_tmp40_2;
                PTMP_tmp40_2 = NULL;
            }
            
        }
        
        
    }
    
    
p_return_29: ;
    PrtFreeValue(PTMP_tmp0_22); PTMP_tmp0_22 = NULL;
    PrtFreeValue(PTMP_tmp1_22); PTMP_tmp1_22 = NULL;
    PrtFreeValue(PTMP_tmp2_20); PTMP_tmp2_20 = NULL;
    PrtFreeValue(PTMP_tmp3_19); PTMP_tmp3_19 = NULL;
    PrtFreeValue(PTMP_tmp4_19); PTMP_tmp4_19 = NULL;
    PrtFreeValue(PTMP_tmp5_19); PTMP_tmp5_19 = NULL;
    PrtFreeValue(PTMP_tmp6_18); PTMP_tmp6_18 = NULL;
    PrtFreeValue(PTMP_tmp7_12); PTMP_tmp7_12 = NULL;
    PrtFreeValue(PTMP_tmp8_9); PTMP_tmp8_9 = NULL;
    PrtFreeValue(PTMP_tmp9_9); PTMP_tmp9_9 = NULL;
    PrtFreeValue(PTMP_tmp10_9); PTMP_tmp10_9 = NULL;
    PrtFreeValue(PTMP_tmp11_9); PTMP_tmp11_9 = NULL;
    PrtFreeValue(PTMP_tmp12_6); PTMP_tmp12_6 = NULL;
    PrtFreeValue(PTMP_tmp13_6); PTMP_tmp13_6 = NULL;
    PrtFreeValue(PTMP_tmp14_6); PTMP_tmp14_6 = NULL;
    PrtFreeValue(PTMP_tmp15_5); PTMP_tmp15_5 = NULL;
    PrtFreeValue(PTMP_tmp16_5); PTMP_tmp16_5 = NULL;
    PrtFreeValue(PTMP_tmp17_5); PTMP_tmp17_5 = NULL;
    PrtFreeValue(PTMP_tmp18_5); PTMP_tmp18_5 = NULL;
    PrtFreeValue(PTMP_tmp19_5); PTMP_tmp19_5 = NULL;
    PrtFreeValue(PTMP_tmp20_4); PTMP_tmp20_4 = NULL;
    PrtFreeValue(PTMP_tmp21_4); PTMP_tmp21_4 = NULL;
    PrtFreeValue(PTMP_tmp22_4); PTMP_tmp22_4 = NULL;
    PrtFreeValue(PTMP_tmp23_4); PTMP_tmp23_4 = NULL;
    PrtFreeValue(PTMP_tmp24_4); PTMP_tmp24_4 = NULL;
    PrtFreeValue(PTMP_tmp25_4); PTMP_tmp25_4 = NULL;
    PrtFreeValue(PTMP_tmp26_4); PTMP_tmp26_4 = NULL;
    PrtFreeValue(PTMP_tmp27_4); PTMP_tmp27_4 = NULL;
    PrtFreeValue(PTMP_tmp28_4); PTMP_tmp28_4 = NULL;
    PrtFreeValue(PTMP_tmp29_4); PTMP_tmp29_4 = NULL;
    PrtFreeValue(PTMP_tmp30_4); PTMP_tmp30_4 = NULL;
    PrtFreeValue(PTMP_tmp31_4); PTMP_tmp31_4 = NULL;
    PrtFreeValue(PTMP_tmp32_4); PTMP_tmp32_4 = NULL;
    PrtFreeValue(PTMP_tmp33_4); PTMP_tmp33_4 = NULL;
    PrtFreeValue(PTMP_tmp34_4); PTMP_tmp34_4 = NULL;
    PrtFreeValue(PTMP_tmp35_4); PTMP_tmp35_4 = NULL;
    PrtFreeValue(PTMP_tmp36_3); PTMP_tmp36_3 = NULL;
    PrtFreeValue(PTMP_tmp37_3); PTMP_tmp37_3 = NULL;
    PrtFreeValue(PTMP_tmp38_3); PTMP_tmp38_3 = NULL;
    PrtFreeValue(PTMP_tmp39_3); PTMP_tmp39_3 = NULL;
    PrtFreeValue(PTMP_tmp40_2); PTMP_tmp40_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_14 =
{
    NULL,
    &P_Anon_IMPL_13,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_8 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_23 = NULL;
    PRT_VALUE* PTMP_tmp1_23 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_633 = &(PTMP_tmp0_23);
    PrtFreeValue(*P_LVALUE_633);
    *P_LVALUE_633 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
    
    PRT_VALUE** P_LVALUE_634 = &(PTMP_tmp1_23);
    PrtFreeValue(*P_LVALUE_634);
    *P_LVALUE_634 = PrtCloneValue(*P_VAR_payload_8);
    
    PrtSeqInsertEx(p_this->varValues[2], PTMP_tmp0_23, PTMP_tmp1_23, PRT_FALSE);
    *(&(PTMP_tmp1_23)) = NULL;
    
p_return_30: ;
    PrtFreeValue(PTMP_tmp0_23); PTMP_tmp0_23 = NULL;
    PrtFreeValue(PTMP_tmp1_23); PTMP_tmp1_23 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_16 =
{
    NULL,
    &P_Anon_IMPL_14,
    &P_GEND_TYPE_T2ff,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_9 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_24 = NULL;
    PRT_VALUE* PTMP_tmp1_24 = NULL;
    PRT_VALUE* PTMP_tmp2_21 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_15 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_635 = &(PTMP_tmp0_24);
    PrtFreeValue(*P_LVALUE_635);
    *P_LVALUE_635 = PrtCloneValue(*P_VAR_payload_9);
    
    PRT_VALUE** P_LVALUE_636 = &(PTMP_tmp1_24);
    PrtFreeValue(*P_LVALUE_636);
    *P_LVALUE_636 = PrtCloneValue((&P_EVENT_eCurrentGoal.value));
    
    PRT_VALUE** P_LVALUE_637 = &(PTMP_tmp2_21);
    PrtFreeValue(*P_LVALUE_637);
    *P_LVALUE_637 = PrtCloneValue(p_this->varValues[8]);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_24), PTMP_tmp1_24, 1, &(PTMP_tmp2_21));
    *(&(PTMP_tmp1_24)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_31;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_31;
    }
    
    PRT_VALUE** P_LVALUE_638 = &(p_this->varValues[13]);
    PrtFreeValue(*P_LVALUE_638);
    *P_LVALUE_638 = PrtCloneValue((&P_LIT_BOOLEAN_15));
    
p_return_31: ;
    PrtFreeValue(PTMP_tmp0_24); PTMP_tmp0_24 = NULL;
    PrtFreeValue(PTMP_tmp1_24); PTMP_tmp1_24 = NULL;
    PrtFreeValue(PTMP_tmp2_21); PTMP_tmp2_21 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_15 =
{
    NULL,
    &P_Anon_IMPL_15,
    &P_GEND_TYPE_m,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_42 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_16 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_639 = &(p_this->varValues[14]);
    PrtFreeValue(*P_LVALUE_639);
    *P_LVALUE_639 = PrtCloneValue((&P_LIT_BOOLEAN_16));
    
    PRT_VALUE** P_LVALUE_640 = &(p_this->varValues[17]);
    PrtFreeValue(*P_LVALUE_640);
    *P_LVALUE_640 = PrtCloneValue((&P_LIT_INT32_42));
    
p_return_32: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_13 =
{
    NULL,
    &P_Anon_IMPL_16,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL* P_MotionPrimitives_METHODS[] = { &P_FUNCTION_DM_2, &P_FUNCTION_LeftObstacleAvoidanceController, &P_FUNCTION_RightObstacleAvoidanceController, &P_FUNCTION_LeftCliffAvoidanceController, &P_FUNCTION_RightCliffAvoidanceController, &P_FUNCTION_CenterCliffAvoidanceController, &P_FUNCTION_SafeMotionController, &P_FUNCTION_AdvancedMotionController, &P_FUNCTION_Anon_7, &P_FUNCTION_Anon_9, &P_FUNCTION_Anon_11, &P_FUNCTION_Anon_12, &P_FUNCTION_Anon_10, &P_FUNCTION_Anon_8, &P_FUNCTION_Anon_14, &P_FUNCTION_Anon_16, &P_FUNCTION_Anon_15, &P_FUNCTION_Anon_13 };

PRT_EVENTDECL* P_MotionPrimitives_RECV_INNER_1[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MotionPrimitives_RECV_1 =
{
    9U,
    P_MotionPrimitives_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_MotionPrimitives_SEND_INNER[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_MotionPrimitives_SEND =
{
    9U,
    P_MotionPrimitives_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_MotionPrimitives = 
{
    2U,
    "MotionPrimitives",
    &P_EVENTSET_MotionPrimitives_RECV_1,
    &P_EVENTSET_MotionPrimitives_SEND,
    NULL,
    20U,
    3U,
    18U,
    4294967295U,
    0U,
    0U,
    P_MotionPrimitives_VARS,
    P_MotionPrimitives_STATES,
    P_MotionPrimitives_METHODS
};

PRT_VARDECL P_Battery_VARS[] = {
    { "destination", &P_GEND_TYPE_m },
    { "motionPlanner", &P_GEND_TYPE_m },
    { "chargerLocation", &P_GEND_TYPE_T2ff },
    { "previousBatteryLevel", &P_GEND_TYPE_f },
    { "currentBatteryLevel", &P_GEND_TYPE_f },
    { "batteryLevelLowerBound", &P_GEND_TYPE_f },
    { "batteryLevelUpperBound", &P_GEND_TYPE_f },
    { "isBatteryLow", &P_GEND_TYPE_b },
    { "", &P_GEND_TYPE_b },
    { "", &P_GEND_TYPE_r },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_3 =
{
    0U,
    P_Init_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_3 =
{
    0U,
    P_Init_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_3 =
{
    0U,
    P_Init_DOS_INNER_3,
    NULL
};

#define P_STATE_Battery_Init \
{ \
    "Battery.Init", \
    0U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_3, \
    &P_EVENTSET_Init_TRANS_3, \
    &P_EVENTSET_Init_DOS_3, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_17, \
    &_P_NO_OP, \
    &_P_NO_OP, \
    0, \
}

PRT_EVENTDECL* P_Run_DEFERS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Run_DEFERS_3 =
{
    0U,
    P_Run_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Run_TRANS_INNER_3[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Run_TRANS_3 =
{
    0U,
    P_Run_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Run_DOS_INNER_3[] = { &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation };
PRT_EVENTSETDECL P_EVENTSET_Run_DOS_3 =
{
    2U,
    P_Run_DOS_INNER_3,
    NULL
};

PRT_DODECL P_DOS_4[] =
{
    { 1, &P_EVENT_eCurrentLocation, &P_FUNCTION_Anon_20 },
    { 1, &P_EVENT_eCurrentGoal, &P_FUNCTION_Anon_21 }
};

#define P_STATE_Battery_Run \
{ \
    "Battery.Run", \
    0U, \
    2U, \
    &P_EVENTSET_Run_DEFERS_3, \
    &P_EVENTSET_Run_TRANS_3, \
    &P_EVENTSET_Run_DOS_3, \
    NULL, \
    P_DOS_4, \
    &P_FUNCTION_Anon_18, \
    &_P_NO_OP, \
    &P_FUNCTION_Anon_19, \
    0, \
}

PRT_STATEDECL P_Battery_STATES[] = { P_STATE_Battery_Init, P_STATE_Battery_Run };

PRT_VALUE* P_DM_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_r);
    PRT_VALUE* P_VAR_isButtonB0PressedAndReleased_1 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* PTMP_tmp0_25 = NULL;
    PRT_VALUE* PTMP_tmp1_25 = NULL;
    PRT_VALUE* PTMP_tmp2_22 = NULL;
    PRT_VALUE* PTMP_tmp3_20 = NULL;
    PRT_VALUE* PTMP_tmp4_20 = NULL;
    PRT_VALUE* PTMP_tmp5_20 = NULL;
    PRT_VALUE* PTMP_tmp6_19 = NULL;
    PRT_VALUE* PTMP_tmp7_13 = NULL;
    PRT_VALUE* PTMP_tmp8_10 = NULL;
    PRT_VALUE* PTMP_tmp9_10 = NULL;
    PRT_VALUE* PTMP_tmp10_10 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_641 = &(PTMP_tmp0_25);
    PrtFreeValue(*P_LVALUE_641);
    *P_LVALUE_641 = ((_P_GEN_funval = P_GetIsButtonPressedAndReleasedB0_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_33;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_33;
    }
    
    {
        PRT_VALUE** P_LVALUE_642 = &(P_VAR_isButtonB0PressedAndReleased_1);
        PrtFreeValue(*P_LVALUE_642);
        *P_LVALUE_642 = PTMP_tmp0_25;
        PTMP_tmp0_25 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_643 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_643);
    *P_LVALUE_643 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_644 = &(PTMP_tmp1_25);
    PrtFreeValue(*P_LVALUE_644);
    *P_LVALUE_644 = ((_P_GEN_funval = P_GetBatteryLevel_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_33;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_33;
    }
    
    {
        PRT_VALUE** P_LVALUE_645 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_645);
        *P_LVALUE_645 = PTMP_tmp1_25;
        PTMP_tmp1_25 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_646 = &(PTMP_tmp2_22);
    PrtFreeValue(*P_LVALUE_646);
    *P_LVALUE_646 = PrtMkBoolValue(!PrtPrimGetBool(p_this->varValues[7]));
    
    PRT_VALUE** P_LVALUE_647 = &(PTMP_tmp4_20);
    PrtFreeValue(*P_LVALUE_647);
    *P_LVALUE_647 = PrtCloneValue(PTMP_tmp2_22);
    
    if (PrtPrimGetBool(PTMP_tmp4_20))
    {
        PRT_VALUE** P_LVALUE_648 = &(PTMP_tmp3_20);
        PrtFreeValue(*P_LVALUE_648);
        *P_LVALUE_648 = PrtMkBoolValue(PrtPrimGetFloat(p_this->varValues[4]) < PrtPrimGetFloat(p_this->varValues[5]));
        
        PRT_VALUE** P_LVALUE_649 = &(PTMP_tmp4_20);
        PrtFreeValue(*P_LVALUE_649);
        *P_LVALUE_649 = PrtCloneValue(PTMP_tmp3_20);
        
    }
    
    
    PRT_VALUE** P_LVALUE_650 = &(PTMP_tmp6_19);
    PrtFreeValue(*P_LVALUE_650);
    *P_LVALUE_650 = PrtCloneValue(PTMP_tmp4_20);
    
    if (PrtPrimGetBool(PTMP_tmp6_19))
    {
        PRT_VALUE** P_LVALUE_651 = &(PTMP_tmp5_20);
        PrtFreeValue(*P_LVALUE_651);
        *P_LVALUE_651 = PrtMkBoolValue(PrtPrimGetFloat(p_this->varValues[3]) >= PrtPrimGetFloat(p_this->varValues[5]));
        
        PRT_VALUE** P_LVALUE_652 = &(PTMP_tmp6_19);
        PrtFreeValue(*P_LVALUE_652);
        *P_LVALUE_652 = PrtCloneValue(PTMP_tmp5_20);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp6_19))
    {
        PRT_VALUE** P_LVALUE_653 = &(PTMP_tmp7_13);
        PrtFreeValue(*P_LVALUE_653);
        *P_LVALUE_653 = PrtMkStringValue(PrtFormatString("HandleLowBattery", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp7_13);
        goto p_return_33;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_654 = &(PTMP_tmp8_10);
    PrtFreeValue(*P_LVALUE_654);
    *P_LVALUE_654 = PrtCloneValue(p_this->varValues[7]);
    
    if (PrtPrimGetBool(PTMP_tmp8_10))
    {
        PRT_VALUE** P_LVALUE_655 = &(PTMP_tmp8_10);
        PrtFreeValue(*P_LVALUE_655);
        *P_LVALUE_655 = PrtCloneValue(P_VAR_isButtonB0PressedAndReleased_1);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp8_10))
    {
        PRT_VALUE** P_LVALUE_656 = &(PTMP_tmp9_10);
        PrtFreeValue(*P_LVALUE_656);
        *P_LVALUE_656 = PrtMkStringValue(PrtFormatString("NotifyRecovery", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp9_10);
        goto p_return_33;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_657 = &(PTMP_tmp10_10);
    PrtFreeValue(*P_LVALUE_657);
    *P_LVALUE_657 = PrtMkStringValue(PrtFormatString("Idle", 0, 0));
    ;
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(PTMP_tmp10_10);
    goto p_return_33;
    
p_return_33: ;
    PrtFreeValue(P_VAR_isButtonB0PressedAndReleased_1); P_VAR_isButtonB0PressedAndReleased_1 = NULL;
    PrtFreeValue(PTMP_tmp0_25); PTMP_tmp0_25 = NULL;
    PrtFreeValue(PTMP_tmp1_25); PTMP_tmp1_25 = NULL;
    PrtFreeValue(PTMP_tmp2_22); PTMP_tmp2_22 = NULL;
    PrtFreeValue(PTMP_tmp3_20); PTMP_tmp3_20 = NULL;
    PrtFreeValue(PTMP_tmp4_20); PTMP_tmp4_20 = NULL;
    PrtFreeValue(PTMP_tmp5_20); PTMP_tmp5_20 = NULL;
    PrtFreeValue(PTMP_tmp6_19); PTMP_tmp6_19 = NULL;
    PrtFreeValue(PTMP_tmp7_13); PTMP_tmp7_13 = NULL;
    PrtFreeValue(PTMP_tmp8_10); PTMP_tmp8_10 = NULL;
    PrtFreeValue(PTMP_tmp9_10); PTMP_tmp9_10 = NULL;
    PrtFreeValue(PTMP_tmp10_10); PTMP_tmp10_10 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_DM_3 =
{
    "DM",
    &P_DM_IMPL_3,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Idle_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_34: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Idle =
{
    "Idle",
    &P_Idle_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_HandleLowBattery_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_26 = NULL;
    PRT_VALUE* PTMP_tmp1_26 = NULL;
    PRT_VALUE* PTMP_tmp2_23 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_17 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_658 = &(p_this->varValues[7]);
    PrtFreeValue(*P_LVALUE_658);
    *P_LVALUE_658 = PrtCloneValue((&P_LIT_BOOLEAN_17));
    
    PRT_VALUE** P_LVALUE_659 = &(PTMP_tmp0_26);
    PrtFreeValue(*P_LVALUE_659);
    *P_LVALUE_659 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_660 = &(PTMP_tmp1_26);
    PrtFreeValue(*P_LVALUE_660);
    *P_LVALUE_660 = PrtCloneValue((&P_EVENT_eBatteryLow.value));
    
    PRT_VALUE** P_LVALUE_661 = &(PTMP_tmp2_23);
    PrtFreeValue(*P_LVALUE_661);
    *P_LVALUE_661 = PrtCloneValue((p_this->id));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_26), PTMP_tmp1_26, 1, &(PTMP_tmp2_23));
    *(&(PTMP_tmp1_26)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_35;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_35;
    }
    
p_return_35: ;
    PrtFreeValue(PTMP_tmp0_26); PTMP_tmp0_26 = NULL;
    PrtFreeValue(PTMP_tmp1_26); PTMP_tmp1_26 = NULL;
    PrtFreeValue(PTMP_tmp2_23); PTMP_tmp2_23 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_HandleLowBattery =
{
    "HandleLowBattery",
    &P_HandleLowBattery_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_NotifyRecovery_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_27 = NULL;
    PRT_VALUE* PTMP_tmp1_27 = NULL;
    PRT_VALUE* PTMP_tmp2_24 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_18 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_662 = &(p_this->varValues[7]);
    PrtFreeValue(*P_LVALUE_662);
    *P_LVALUE_662 = PrtCloneValue((&P_LIT_BOOLEAN_18));
    
    PRT_VALUE** P_LVALUE_663 = &(PTMP_tmp0_27);
    PrtFreeValue(*P_LVALUE_663);
    *P_LVALUE_663 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_664 = &(PTMP_tmp1_27);
    PrtFreeValue(*P_LVALUE_664);
    *P_LVALUE_664 = PrtCloneValue((&P_EVENT_eBatteryRecovered.value));
    
    PRT_VALUE** P_LVALUE_665 = &(PTMP_tmp2_24);
    PrtFreeValue(*P_LVALUE_665);
    *P_LVALUE_665 = PrtCloneValue((p_this->id));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_27), PTMP_tmp1_27, 1, &(PTMP_tmp2_24));
    *(&(PTMP_tmp1_27)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_36;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_36;
    }
    
p_return_36: ;
    PrtFreeValue(PTMP_tmp0_27); PTMP_tmp0_27 = NULL;
    PrtFreeValue(PTMP_tmp1_27); PTMP_tmp1_27 = NULL;
    PrtFreeValue(PTMP_tmp2_24); PTMP_tmp2_24 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_NotifyRecovery =
{
    "NotifyRecovery",
    &P_NotifyRecovery_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_10 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_28 = NULL;
    PRT_VALUE* PTMP_tmp1_28 = NULL;
    PRT_VALUE* PTMP_tmp2_25 = NULL;
    PRT_VALUE* PTMP_tmp3_21 = NULL;
    PRT_VALUE* PTMP_tmp4_21 = NULL;
    PRT_VALUE* PTMP_tmp5_21 = NULL;
    PRT_VALUE* PTMP_tmp6_20 = NULL;
    PRT_VALUE* PTMP_tmp7_14 = NULL;
    PRT_VALUE* PTMP_tmp8_11 = NULL;
    PRT_VALUE* PTMP_tmp9_11 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_43 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_DOUBLE_18 = { PRT_VALUE_KIND_FLOAT, { .ft = 100 } };
    PRT_VALUE P_LIT_BOOLEAN_19 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_666 = &(PTMP_tmp0_28);
    PrtFreeValue(*P_LVALUE_666);
    *P_LVALUE_666 = PrtTupleGet(*P_VAR_payload_10, 0);
    
    PRT_VALUE** P_LVALUE_667 = &(PTMP_tmp1_28);
    PrtFreeValue(*P_LVALUE_667);
    *P_LVALUE_667 = PrtCloneValue(PTMP_tmp0_28);
    
    {
        PRT_VALUE** P_LVALUE_668 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_668);
        *P_LVALUE_668 = PTMP_tmp1_28;
        PTMP_tmp1_28 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_669 = &(PTMP_tmp2_25);
    PrtFreeValue(*P_LVALUE_669);
    *P_LVALUE_669 = PrtTupleGet(*P_VAR_payload_10, 1);
    
    PRT_VALUE** P_LVALUE_670 = &(PTMP_tmp3_21);
    PrtFreeValue(*P_LVALUE_670);
    *P_LVALUE_670 = PrtCloneValue(PTMP_tmp2_25);
    
    {
        PRT_VALUE** P_LVALUE_671 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_671);
        *P_LVALUE_671 = PTMP_tmp3_21;
        PTMP_tmp3_21 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_672 = &(PTMP_tmp4_21);
    PrtFreeValue(*P_LVALUE_672);
    *P_LVALUE_672 = PrtTupleGet(*P_VAR_payload_10, 2);
    
    PRT_VALUE** P_LVALUE_673 = &(PTMP_tmp5_21);
    PrtFreeValue(*P_LVALUE_673);
    *P_LVALUE_673 = PrtCloneValue(PTMP_tmp4_21);
    
    {
        PRT_VALUE** P_LVALUE_674 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_674);
        *P_LVALUE_674 = PTMP_tmp5_21;
        PTMP_tmp5_21 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_675 = &(PTMP_tmp6_20);
    PrtFreeValue(*P_LVALUE_675);
    *P_LVALUE_675 = PrtTupleGet(*P_VAR_payload_10, 3);
    
    PRT_VALUE** P_LVALUE_676 = &(PTMP_tmp7_14);
    PrtFreeValue(*P_LVALUE_676);
    *P_LVALUE_676 = PrtCloneValue(PTMP_tmp6_20);
    
    {
        PRT_VALUE** P_LVALUE_677 = &(p_this->varValues[5]);
        PrtFreeValue(*P_LVALUE_677);
        *P_LVALUE_677 = PTMP_tmp7_14;
        PTMP_tmp7_14 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_678 = &(PTMP_tmp8_11);
    PrtFreeValue(*P_LVALUE_678);
    *P_LVALUE_678 = PrtTupleGet(*P_VAR_payload_10, 4);
    
    PRT_VALUE** P_LVALUE_679 = &(PTMP_tmp9_11);
    PrtFreeValue(*P_LVALUE_679);
    *P_LVALUE_679 = PrtCloneValue(PTMP_tmp8_11);
    
    {
        PRT_VALUE** P_LVALUE_680 = &(p_this->varValues[6]);
        PrtFreeValue(*P_LVALUE_680);
        *P_LVALUE_680 = PTMP_tmp9_11;
        PTMP_tmp9_11 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_681 = &(p_this->varValues[7]);
    PrtFreeValue(*P_LVALUE_681);
    *P_LVALUE_681 = PrtCloneValue((&P_LIT_BOOLEAN_19));
    
    PRT_VALUE** P_LVALUE_682 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_682);
    *P_LVALUE_682 = PrtCloneValue((&P_LIT_DOUBLE_18));
    
    PrtGoto(p_this, 1U, 0);
    
    PRT_VALUE** P_LVALUE_683 = &(p_this->varValues[8]);
    PrtFreeValue(*P_LVALUE_683);
    *P_LVALUE_683 = PrtCloneValue((&P_LIT_BOOLEAN_19));
    
    PRT_VALUE** P_LVALUE_684 = &(p_this->varValues[11]);
    PrtFreeValue(*P_LVALUE_684);
    *P_LVALUE_684 = PrtCloneValue((&P_LIT_INT32_43));
    
p_return_37: ;
    PrtFreeValue(PTMP_tmp0_28); PTMP_tmp0_28 = NULL;
    PrtFreeValue(PTMP_tmp1_28); PTMP_tmp1_28 = NULL;
    PrtFreeValue(PTMP_tmp2_25); PTMP_tmp2_25 = NULL;
    PrtFreeValue(PTMP_tmp3_21); PTMP_tmp3_21 = NULL;
    PrtFreeValue(PTMP_tmp4_21); PTMP_tmp4_21 = NULL;
    PrtFreeValue(PTMP_tmp5_21); PTMP_tmp5_21 = NULL;
    PrtFreeValue(PTMP_tmp6_20); PTMP_tmp6_20 = NULL;
    PrtFreeValue(PTMP_tmp7_14); PTMP_tmp7_14 = NULL;
    PrtFreeValue(PTMP_tmp8_11); PTMP_tmp8_11 = NULL;
    PrtFreeValue(PTMP_tmp9_11); PTMP_tmp9_11 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_17 =
{
    NULL,
    &P_Anon_IMPL_17,
    &P_GEND_TYPE_T5mmT2ffff,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_29 = NULL;
    PRT_VALUE* PTMP_tmp1_29 = NULL;
    PRT_VALUE* PTMP_tmp2_26 = NULL;
    PRT_VALUE* PTMP_tmp3_22 = NULL;
    PRT_VALUE* PTMP_tmp4_22 = NULL;
    PRT_VALUE* PTMP_tmp5_22 = NULL;
    PRT_VALUE* PTMP_tmp6_21 = NULL;
    PRT_VALUE* PTMP_tmp7_15 = NULL;
    PRT_VALUE* PTMP_tmp8_12 = NULL;
    PRT_VALUE* PTMP_tmp9_12 = NULL;
    PRT_VALUE* PTMP_tmp10_11 = NULL;
    PRT_VALUE* PTMP_tmp11_10 = NULL;
    PRT_VALUE* PTMP_tmp12_7 = NULL;
    PRT_VALUE* PTMP_tmp13_7 = NULL;
    PRT_VALUE* PTMP_tmp14_7 = NULL;
    PRT_VALUE* PTMP_tmp15_6 = NULL;
    PRT_VALUE* PTMP_tmp16_6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_44 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_45 = { PRT_VALUE_KIND_INT, { .nt = 9 } };
    PRT_VALUE P_LIT_BOOLEAN_20 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_685 = &(PTMP_tmp0_29);
    PrtFreeValue(*P_LVALUE_685);
    *P_LVALUE_685 = PrtMkBoolValue(!PrtPrimGetBool(p_this->varValues[8]));
    
    if (PrtPrimGetBool(PTMP_tmp0_29))
    {
        PRT_VALUE** P_LVALUE_686 = &(p_this->varValues[8]);
        PrtFreeValue(*P_LVALUE_686);
        *P_LVALUE_686 = PrtCloneValue((&P_LIT_BOOLEAN_20));
        
        PRT_VALUE** P_LVALUE_687 = &(PTMP_tmp1_29);
        PrtFreeValue(*P_LVALUE_687);
        *P_LVALUE_687 = ((_P_GEN_funval = P_DM_IMPL_3(context, _P_GEN_funargs)), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_38;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_38;
        }
        
        {
            PRT_VALUE** P_LVALUE_688 = &(p_this->varValues[9]);
            PrtFreeValue(*P_LVALUE_688);
            *P_LVALUE_688 = PTMP_tmp1_29;
            PTMP_tmp1_29 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_689 = &(PTMP_tmp2_26);
        PrtFreeValue(*P_LVALUE_689);
        *P_LVALUE_689 = PrtMkStringValue(PrtFormatString("NotifyRecovery", 0, 0));
        ;
        
        PRT_VALUE** P_LVALUE_690 = &(PTMP_tmp3_22);
        PrtFreeValue(*P_LVALUE_690);
        *P_LVALUE_690 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp2_26));
        
        if (PrtPrimGetBool(PTMP_tmp3_22))
        {
            PrtFreeValue(P_NotifyRecovery_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_38;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_38;
            }
            
            PRT_VALUE** P_LVALUE_691 = &(p_this->varValues[10]);
            PrtFreeValue(*P_LVALUE_691);
            *P_LVALUE_691 = PrtCloneValue((&P_LIT_INT32_44));
            
            PRT_VALUE** P_LVALUE_692 = &(p_this->varValues[12]);
            PrtFreeValue(*P_LVALUE_692);
            *P_LVALUE_692 = PrtCloneValue((&P_LIT_INT32_44));
            
            PRT_VALUE** P_LVALUE_693 = &(p_this->varValues[13]);
            PrtFreeValue(*P_LVALUE_693);
            *P_LVALUE_693 = PrtCloneValue((&P_LIT_INT32_45));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_694 = &(PTMP_tmp4_22);
            PrtFreeValue(*P_LVALUE_694);
            *P_LVALUE_694 = PrtMkStringValue(PrtFormatString("Idle", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_695 = &(PTMP_tmp5_22);
            PrtFreeValue(*P_LVALUE_695);
            *P_LVALUE_695 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp4_22));
            
            if (PrtPrimGetBool(PTMP_tmp5_22))
            {
                PrtFreeValue(P_Idle_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_38;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_38;
                }
                
                PRT_VALUE** P_LVALUE_696 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_696);
                *P_LVALUE_696 = PrtCloneValue((&P_LIT_INT32_44));
                
                PRT_VALUE** P_LVALUE_697 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_697);
                *P_LVALUE_697 = PrtCloneValue((&P_LIT_INT32_44));
                
                PRT_VALUE** P_LVALUE_698 = &(p_this->varValues[13]);
                PrtFreeValue(*P_LVALUE_698);
                *P_LVALUE_698 = PrtCloneValue((&P_LIT_INT32_45));
                
            }
            
            else
            {
                PrtFreeValue(P_HandleLowBattery_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_38;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_38;
                }
                
                PRT_VALUE** P_LVALUE_699 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_699);
                *P_LVALUE_699 = PrtCloneValue((&P_LIT_INT32_44));
                
                PRT_VALUE** P_LVALUE_700 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_700);
                *P_LVALUE_700 = PrtCloneValue((&P_LIT_INT32_44));
                
                PRT_VALUE** P_LVALUE_701 = &(p_this->varValues[13]);
                PrtFreeValue(*P_LVALUE_701);
                *P_LVALUE_701 = PrtCloneValue((&P_LIT_INT32_45));
                
            }
            
            
        }
        
        
        PRT_VALUE** P_LVALUE_702 = &(p_this->varValues[11]);
        PrtFreeValue(*P_LVALUE_702);
        *P_LVALUE_702 = PrtCloneValue((&P_LIT_INT32_44));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_703 = &(PTMP_tmp6_21);
        PrtFreeValue(*P_LVALUE_703);
        *P_LVALUE_703 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[10], p_this->varValues[11]));
        
        if (PrtPrimGetBool(PTMP_tmp6_21))
        {
            PRT_VALUE** P_LVALUE_704 = &(PTMP_tmp7_15);
            PrtFreeValue(*P_LVALUE_704);
            *P_LVALUE_704 = ((_P_GEN_funval = P_DM_IMPL_3(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_38;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_38;
            }
            
            {
                PRT_VALUE** P_LVALUE_705 = &(p_this->varValues[9]);
                PrtFreeValue(*P_LVALUE_705);
                *P_LVALUE_705 = PTMP_tmp7_15;
                PTMP_tmp7_15 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_706 = &(PTMP_tmp8_12);
            PrtFreeValue(*P_LVALUE_706);
            *P_LVALUE_706 = PrtMkStringValue(PrtFormatString("NotifyRecovery", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_707 = &(PTMP_tmp9_12);
            PrtFreeValue(*P_LVALUE_707);
            *P_LVALUE_707 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp8_12));
            
            if (PrtPrimGetBool(PTMP_tmp9_12))
            {
                PrtFreeValue(P_NotifyRecovery_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_38;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_38;
                }
                
                PRT_VALUE** P_LVALUE_708 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_708);
                *P_LVALUE_708 = PrtCloneValue((&P_LIT_INT32_44));
                
                PRT_VALUE** P_LVALUE_709 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_709);
                *P_LVALUE_709 = PrtCloneValue((&P_LIT_INT32_44));
                
                PRT_VALUE** P_LVALUE_710 = &(p_this->varValues[13]);
                PrtFreeValue(*P_LVALUE_710);
                *P_LVALUE_710 = PrtCloneValue((&P_LIT_INT32_45));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_711 = &(PTMP_tmp10_11);
                PrtFreeValue(*P_LVALUE_711);
                *P_LVALUE_711 = PrtMkStringValue(PrtFormatString("Idle", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_712 = &(PTMP_tmp11_10);
                PrtFreeValue(*P_LVALUE_712);
                *P_LVALUE_712 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp10_11));
                
                if (PrtPrimGetBool(PTMP_tmp11_10))
                {
                    PrtFreeValue(P_Idle_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_38;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_38;
                    }
                    
                    PRT_VALUE** P_LVALUE_713 = &(p_this->varValues[10]);
                    PrtFreeValue(*P_LVALUE_713);
                    *P_LVALUE_713 = PrtCloneValue((&P_LIT_INT32_44));
                    
                    PRT_VALUE** P_LVALUE_714 = &(p_this->varValues[12]);
                    PrtFreeValue(*P_LVALUE_714);
                    *P_LVALUE_714 = PrtCloneValue((&P_LIT_INT32_44));
                    
                    PRT_VALUE** P_LVALUE_715 = &(p_this->varValues[13]);
                    PrtFreeValue(*P_LVALUE_715);
                    *P_LVALUE_715 = PrtCloneValue((&P_LIT_INT32_45));
                    
                }
                
                else
                {
                    PrtFreeValue(P_HandleLowBattery_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_38;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_38;
                    }
                    
                    PRT_VALUE** P_LVALUE_716 = &(p_this->varValues[10]);
                    PrtFreeValue(*P_LVALUE_716);
                    *P_LVALUE_716 = PrtCloneValue((&P_LIT_INT32_44));
                    
                    PRT_VALUE** P_LVALUE_717 = &(p_this->varValues[12]);
                    PrtFreeValue(*P_LVALUE_717);
                    *P_LVALUE_717 = PrtCloneValue((&P_LIT_INT32_44));
                    
                    PRT_VALUE** P_LVALUE_718 = &(p_this->varValues[13]);
                    PrtFreeValue(*P_LVALUE_718);
                    *P_LVALUE_718 = PrtCloneValue((&P_LIT_INT32_45));
                    
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_719 = &(p_this->varValues[11]);
            PrtFreeValue(*P_LVALUE_719);
            *P_LVALUE_719 = PrtCloneValue((&P_LIT_INT32_44));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_720 = &(PTMP_tmp12_7);
            PrtFreeValue(*P_LVALUE_720);
            *P_LVALUE_720 = PrtMkStringValue(PrtFormatString("NotifyRecovery", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_721 = &(PTMP_tmp13_7);
            PrtFreeValue(*P_LVALUE_721);
            *P_LVALUE_721 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp12_7));
            
            if (PrtPrimGetBool(PTMP_tmp13_7))
            {
                PrtFreeValue(P_NotifyRecovery_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_38;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_38;
                }
                
                PRT_VALUE** P_LVALUE_722 = &(p_this->varValues[10]);
                PrtFreeValue(*P_LVALUE_722);
                *P_LVALUE_722 = PrtCloneValue((&P_LIT_INT32_44));
                
                PRT_VALUE** P_LVALUE_723 = &(p_this->varValues[12]);
                PrtFreeValue(*P_LVALUE_723);
                *P_LVALUE_723 = PrtCloneValue((&P_LIT_INT32_44));
                
                PRT_VALUE** P_LVALUE_724 = &(p_this->varValues[13]);
                PrtFreeValue(*P_LVALUE_724);
                *P_LVALUE_724 = PrtCloneValue((&P_LIT_INT32_45));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_725 = &(PTMP_tmp14_7);
                PrtFreeValue(*P_LVALUE_725);
                *P_LVALUE_725 = PrtMkStringValue(PrtFormatString("Idle", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_726 = &(PTMP_tmp15_6);
                PrtFreeValue(*P_LVALUE_726);
                *P_LVALUE_726 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[9], PTMP_tmp14_7));
                
                if (PrtPrimGetBool(PTMP_tmp15_6))
                {
                    PrtFreeValue(P_Idle_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_38;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_38;
                    }
                    
                    PRT_VALUE** P_LVALUE_727 = &(p_this->varValues[10]);
                    PrtFreeValue(*P_LVALUE_727);
                    *P_LVALUE_727 = PrtCloneValue((&P_LIT_INT32_44));
                    
                    PRT_VALUE** P_LVALUE_728 = &(p_this->varValues[12]);
                    PrtFreeValue(*P_LVALUE_728);
                    *P_LVALUE_728 = PrtCloneValue((&P_LIT_INT32_44));
                    
                    PRT_VALUE** P_LVALUE_729 = &(p_this->varValues[13]);
                    PrtFreeValue(*P_LVALUE_729);
                    *P_LVALUE_729 = PrtCloneValue((&P_LIT_INT32_45));
                    
                }
                
                else
                {
                    PrtFreeValue(P_HandleLowBattery_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_38;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_38;
                    }
                    
                    PRT_VALUE** P_LVALUE_730 = &(p_this->varValues[10]);
                    PrtFreeValue(*P_LVALUE_730);
                    *P_LVALUE_730 = PrtCloneValue((&P_LIT_INT32_44));
                    
                    PRT_VALUE** P_LVALUE_731 = &(p_this->varValues[12]);
                    PrtFreeValue(*P_LVALUE_731);
                    *P_LVALUE_731 = PrtCloneValue((&P_LIT_INT32_44));
                    
                    PRT_VALUE** P_LVALUE_732 = &(p_this->varValues[13]);
                    PrtFreeValue(*P_LVALUE_732);
                    *P_LVALUE_732 = PrtCloneValue((&P_LIT_INT32_45));
                    
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_733 = &(PTMP_tmp16_6);
            PrtFreeValue(*P_LVALUE_733);
            *P_LVALUE_733 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[11]) + PrtPrimGetInt((&P_LIT_INT32_44)));
            
            {
                PRT_VALUE** P_LVALUE_734 = &(p_this->varValues[11]);
                PrtFreeValue(*P_LVALUE_734);
                *P_LVALUE_734 = PTMP_tmp16_6;
                PTMP_tmp16_6 = NULL;
            }
            
        }
        
        
    }
    
    
p_return_38: ;
    PrtFreeValue(PTMP_tmp0_29); PTMP_tmp0_29 = NULL;
    PrtFreeValue(PTMP_tmp1_29); PTMP_tmp1_29 = NULL;
    PrtFreeValue(PTMP_tmp2_26); PTMP_tmp2_26 = NULL;
    PrtFreeValue(PTMP_tmp3_22); PTMP_tmp3_22 = NULL;
    PrtFreeValue(PTMP_tmp4_22); PTMP_tmp4_22 = NULL;
    PrtFreeValue(PTMP_tmp5_22); PTMP_tmp5_22 = NULL;
    PrtFreeValue(PTMP_tmp6_21); PTMP_tmp6_21 = NULL;
    PrtFreeValue(PTMP_tmp7_15); PTMP_tmp7_15 = NULL;
    PrtFreeValue(PTMP_tmp8_12); PTMP_tmp8_12 = NULL;
    PrtFreeValue(PTMP_tmp9_12); PTMP_tmp9_12 = NULL;
    PrtFreeValue(PTMP_tmp10_11); PTMP_tmp10_11 = NULL;
    PrtFreeValue(PTMP_tmp11_10); PTMP_tmp11_10 = NULL;
    PrtFreeValue(PTMP_tmp12_7); PTMP_tmp12_7 = NULL;
    PrtFreeValue(PTMP_tmp13_7); PTMP_tmp13_7 = NULL;
    PrtFreeValue(PTMP_tmp14_7); PTMP_tmp14_7 = NULL;
    PrtFreeValue(PTMP_tmp15_6); PTMP_tmp15_6 = NULL;
    PrtFreeValue(PTMP_tmp16_6); PTMP_tmp16_6 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_19 =
{
    NULL,
    &P_Anon_IMPL_18,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_11 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_30 = NULL;
    PRT_VALUE* PTMP_tmp1_30 = NULL;
    PRT_VALUE* PTMP_tmp2_27 = NULL;
    PRT_VALUE* PTMP_tmp3_23 = NULL;
    PRT_VALUE* PTMP_tmp4_23 = NULL;
    PRT_VALUE* PTMP_tmp5_23 = NULL;
    PRT_VALUE* PTMP_tmp6_22 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_21 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_735 = &(PTMP_tmp0_30);
    PrtFreeValue(*P_LVALUE_735);
    *P_LVALUE_735 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_736 = &(PTMP_tmp1_30);
    PrtFreeValue(*P_LVALUE_736);
    *P_LVALUE_736 = PrtCloneValue((&P_EVENT_eMotionRequestX.value));
    
    PRT_VALUE** P_LVALUE_737 = &(PTMP_tmp2_27);
    PrtFreeValue(*P_LVALUE_737);
    *P_LVALUE_737 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_738 = &(PTMP_tmp3_23);
    PrtFreeValue(*P_LVALUE_738);
    *P_LVALUE_738 = PrtCloneValue(*P_VAR_payload_11);
    
    PRT_VALUE** P_LVALUE_739 = &(PTMP_tmp4_23);
    PrtFreeValue(*P_LVALUE_739);
    *P_LVALUE_739 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_740 = &(PTMP_tmp5_23);
    PrtFreeValue(*P_LVALUE_740);
    *P_LVALUE_740 = PrtCloneValue((&P_LIT_BOOLEAN_21));
    
    PRT_VALUE** P_LVALUE_741 = &(PTMP_tmp6_22);
    PrtFreeValue(*P_LVALUE_741);
    *P_LVALUE_741 = (PrtMkTuple(&P_GEND_TYPE_T4mT2ffT2ffb, &(PTMP_tmp2_27), &(PTMP_tmp3_23), &(PTMP_tmp4_23), &(PTMP_tmp5_23)));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_30), PTMP_tmp1_30, 1, &(PTMP_tmp6_22));
    *(&(PTMP_tmp1_30)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_39;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_39;
    }
    
p_return_39: ;
    PrtFreeValue(PTMP_tmp0_30); PTMP_tmp0_30 = NULL;
    PrtFreeValue(PTMP_tmp1_30); PTMP_tmp1_30 = NULL;
    PrtFreeValue(PTMP_tmp2_27); PTMP_tmp2_27 = NULL;
    PrtFreeValue(PTMP_tmp3_23); PTMP_tmp3_23 = NULL;
    PrtFreeValue(PTMP_tmp4_23); PTMP_tmp4_23 = NULL;
    PrtFreeValue(PTMP_tmp5_23); PTMP_tmp5_23 = NULL;
    PrtFreeValue(PTMP_tmp6_22); PTMP_tmp6_22 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_20 =
{
    NULL,
    &P_Anon_IMPL_19,
    &P_GEND_TYPE_T2ff,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_12 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_31 = NULL;
    PRT_VALUE* PTMP_tmp1_31 = NULL;
    PRT_VALUE* PTMP_tmp2_28 = NULL;
    PRT_VALUE* PTMP_tmp3_24 = NULL;
    PRT_VALUE* PTMP_tmp4_24 = NULL;
    PRT_VALUE* PTMP_tmp5_24 = NULL;
    PRT_VALUE* PTMP_tmp6_23 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_22 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_742 = &(PTMP_tmp0_31);
    PrtFreeValue(*P_LVALUE_742);
    *P_LVALUE_742 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_743 = &(PTMP_tmp1_31);
    PrtFreeValue(*P_LVALUE_743);
    *P_LVALUE_743 = PrtCloneValue((&P_EVENT_eMotionRequestX.value));
    
    PRT_VALUE** P_LVALUE_744 = &(PTMP_tmp2_28);
    PrtFreeValue(*P_LVALUE_744);
    *P_LVALUE_744 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_745 = &(PTMP_tmp3_24);
    PrtFreeValue(*P_LVALUE_745);
    *P_LVALUE_745 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_746 = &(PTMP_tmp4_24);
    PrtFreeValue(*P_LVALUE_746);
    *P_LVALUE_746 = PrtCloneValue(*P_VAR_payload_12);
    
    PRT_VALUE** P_LVALUE_747 = &(PTMP_tmp5_24);
    PrtFreeValue(*P_LVALUE_747);
    *P_LVALUE_747 = PrtCloneValue((&P_LIT_BOOLEAN_22));
    
    PRT_VALUE** P_LVALUE_748 = &(PTMP_tmp6_23);
    PrtFreeValue(*P_LVALUE_748);
    *P_LVALUE_748 = (PrtMkTuple(&P_GEND_TYPE_T4mT2ffT2ffb, &(PTMP_tmp2_28), &(PTMP_tmp3_24), &(PTMP_tmp4_24), &(PTMP_tmp5_24)));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_31), PTMP_tmp1_31, 1, &(PTMP_tmp6_23));
    *(&(PTMP_tmp1_31)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_40;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_40;
    }
    
p_return_40: ;
    PrtFreeValue(PTMP_tmp0_31); PTMP_tmp0_31 = NULL;
    PrtFreeValue(PTMP_tmp1_31); PTMP_tmp1_31 = NULL;
    PrtFreeValue(PTMP_tmp2_28); PTMP_tmp2_28 = NULL;
    PrtFreeValue(PTMP_tmp3_24); PTMP_tmp3_24 = NULL;
    PrtFreeValue(PTMP_tmp4_24); PTMP_tmp4_24 = NULL;
    PrtFreeValue(PTMP_tmp5_24); PTMP_tmp5_24 = NULL;
    PrtFreeValue(PTMP_tmp6_23); PTMP_tmp6_23 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_21 =
{
    NULL,
    &P_Anon_IMPL_20,
    &P_GEND_TYPE_T2ff,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_46 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_23 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_749 = &(p_this->varValues[8]);
    PrtFreeValue(*P_LVALUE_749);
    *P_LVALUE_749 = PrtCloneValue((&P_LIT_BOOLEAN_23));
    
    PRT_VALUE** P_LVALUE_750 = &(p_this->varValues[11]);
    PrtFreeValue(*P_LVALUE_750);
    *P_LVALUE_750 = PrtCloneValue((&P_LIT_INT32_46));
    
p_return_41: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_18 =
{
    NULL,
    &P_Anon_IMPL_21,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL* P_Battery_METHODS[] = { &P_FUNCTION_DM_3, &P_FUNCTION_Idle, &P_FUNCTION_HandleLowBattery, &P_FUNCTION_NotifyRecovery, &P_FUNCTION_Anon_17, &P_FUNCTION_Anon_19, &P_FUNCTION_Anon_20, &P_FUNCTION_Anon_21, &P_FUNCTION_Anon_18 };

PRT_EVENTDECL* P_Battery_RECV_INNER_1[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Battery_RECV_1 =
{
    9U,
    P_Battery_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Battery_SEND_INNER[] = { &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentGoal, &P_EVENT_eCurrentLocation, &P_EVENT_eMotion, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotionX, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Battery_SEND =
{
    9U,
    P_Battery_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_Battery = 
{
    3U,
    "Battery",
    &P_EVENTSET_Battery_RECV_1,
    &P_EVENTSET_Battery_SEND,
    NULL,
    14U,
    2U,
    9U,
    4294967295U,
    0U,
    0U,
    P_Battery_VARS,
    P_Battery_STATES,
    P_Battery_METHODS
};

PRT_TYPE* P_TYPEDEF_locationType = &P_GEND_TYPE_T2ff;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_eMotionRequest, &P_EVENT_eMotionRequestX, &P_EVENT_eMotion, &P_EVENT_eMotionX, &P_EVENT_eBatteryLow, &P_EVENT_eBatteryRecovered, &P_EVENT_eCurrentLocation, &P_EVENT_eCurrentGoal };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_EgoRobot, &P_MACHINE_MotionPlanner, &P_MACHINE_MotionPrimitives, &P_MACHINE_Battery };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_EgoRobot, &P_I_MotionPlanner, &P_I_MotionPrimitives, &P_I_Battery };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { NULL };
int P_DefaultImpl_LME_0[] = { -1,1,2,3 };
int P_DefaultImpl_LME_1[] = { -1,-1,-1,-1 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1,-1 };
int P_DefaultImpl_LME_3[] = { -1,-1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2, P_DefaultImpl_LME_3 };
int P_DefaultImpl_DEFMAP[] = { 0,1,2,3 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    10U,
    4U,
    4U,
    0U,
    0U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};
