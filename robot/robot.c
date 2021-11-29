#include "robot.h"

// Type universe for program:
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_TYPE P_GEND_TYPE_b = { PRT_KIND_BOOL, { NULL } };
static PRT_TYPE P_GEND_TYPE_r = { PRT_KIND_STRING, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };

// Function implementation prototypes:
PRT_VALUE* P_Init_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_MoveForward_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_MoveBackward_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_Stop_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_TurnRight_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_TurnLeft_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetIsBumperReleasedLeft_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_GetIsBumperReleasedRight_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);

PRT_VALUE* P_DM_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_DM;

PRT_VALUE* P_AC_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_AC;

PRT_VALUE* P_SC1_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_SC1;

PRT_VALUE* P_SC2_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_SC2;

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_2;

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;


PRT_FUNDECL P_FUNCTION_Init =
{
    "Init",
    &P_Init_IMPL,
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


PRT_FUNDECL P_FUNCTION_Stop =
{
    "Stop",
    &P_Stop_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_TurnRight =
{
    "TurnRight",
    &P_TurnRight_IMPL,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL P_FUNCTION_TurnLeft =
{
    "TurnLeft",
    &P_TurnLeft_IMPL,
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


PRT_EVENTDECL* P_Robot_RECV_INNER[] = { &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Robot_RECV =
{
    1U,
    P_Robot_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Robot =
{
    0U,
    "Robot",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Robot_RECV
};

PRT_VARDECL P_Robot_VARS[] = {
    { "", &P_GEND_TYPE_b },
    { "", &P_GEND_TYPE_r },
    { "", &P_GEND_TYPE_i },
    { "", &P_GEND_TYPE_i },
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

#define P_STATE_Robot_Init \
{ \
    "Robot.Init", \
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

PRT_EVENTDECL* P_Run_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Run_DOS =
{
    0U,
    P_Run_DOS_INNER,
    NULL
};

#define P_STATE_Robot_Run \
{ \
    "Robot.Run", \
    0U, \
    0U, \
    &P_EVENTSET_Run_DEFERS, \
    &P_EVENTSET_Run_TRANS, \
    &P_EVENTSET_Run_DOS, \
    NULL, \
    NULL, \
    &P_FUNCTION_Anon_1, \
    &_P_NO_OP, \
    &P_FUNCTION_Anon_2, \
    0, \
}

PRT_STATEDECL P_Robot_STATES[] = { P_STATE_Robot_Init, P_STATE_Robot_Run };

PRT_VALUE* P_DM_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_r);
    PRT_VALUE* P_VAR_isBumperReleasedLeft = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* P_VAR_isBumperReleasedRight = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* PTMP_tmp0 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = ((_P_GEN_funval = P_GetIsBumperReleasedLeft_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_1 = &(P_VAR_isBumperReleasedLeft);
        PrtFreeValue(*P_LVALUE_1);
        *P_LVALUE_1 = PTMP_tmp0;
        PTMP_tmp0 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_2 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = ((_P_GEN_funval = P_GetIsBumperReleasedRight_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return;
    }
    
    {
        PRT_VALUE** P_LVALUE_3 = &(P_VAR_isBumperReleasedRight);
        PrtFreeValue(*P_LVALUE_3);
        *P_LVALUE_3 = PTMP_tmp1;
        PTMP_tmp1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_4 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtMkBoolValue(!PrtPrimGetBool(P_VAR_isBumperReleasedLeft));
    
    if (PrtPrimGetBool(PTMP_tmp2))
    {
        PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp3);
        PrtFreeValue(*P_LVALUE_5);
        *P_LVALUE_5 = PrtMkStringValue(PrtFormatString("SC1", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp3);
        goto p_return;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = PrtMkBoolValue(!PrtPrimGetBool(P_VAR_isBumperReleasedRight));
    
    if (PrtPrimGetBool(PTMP_tmp4))
    {
        PRT_VALUE** P_LVALUE_7 = &(PTMP_tmp5);
        PrtFreeValue(*P_LVALUE_7);
        *P_LVALUE_7 = PrtMkStringValue(PrtFormatString("SC2", 0, 0));
        ;
        
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = PrtCloneValue(PTMP_tmp5);
        goto p_return;
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
    ;
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(PTMP_tmp6);
    goto p_return;
    
p_return: ;
    PrtFreeValue(P_VAR_isBumperReleasedLeft); P_VAR_isBumperReleasedLeft = NULL;
    PrtFreeValue(P_VAR_isBumperReleasedRight); P_VAR_isBumperReleasedRight = NULL;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
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
    PrtFreeValue(P_MoveForward_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
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


PRT_VALUE* P_SC1_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_isBumperReleasedLeft_1 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_9 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_9);
    *P_LVALUE_9 = ((_P_GEN_funval = P_GetIsBumperReleasedLeft_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_2;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_2;
    }
    
    {
        PRT_VALUE** P_LVALUE_10 = &(P_VAR_isBumperReleasedLeft_1);
        PrtFreeValue(*P_LVALUE_10);
        *P_LVALUE_10 = PTMP_tmp0_1;
        PTMP_tmp0_1 = NULL;
    }
    
    if (PrtPrimGetBool(P_VAR_isBumperReleasedLeft_1))
    {
        PrtFreeValue(P_TurnRight_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_2;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_2;
        }
        
    }
    
    else
    {
        PrtFreeValue(P_MoveBackward_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_2;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_2;
        }
        
    }
    
    
p_return_2: ;
    PrtFreeValue(P_VAR_isBumperReleasedLeft_1); P_VAR_isBumperReleasedLeft_1 = NULL;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_SC1 =
{
    "SC1",
    &P_SC1_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_SC2_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_isBumperReleasedRight_1 = PrtMkDefaultValue(&P_GEND_TYPE_b);
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = ((_P_GEN_funval = P_GetIsBumperReleasedRight_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    {
        PRT_VALUE** P_LVALUE_12 = &(P_VAR_isBumperReleasedRight_1);
        PrtFreeValue(*P_LVALUE_12);
        *P_LVALUE_12 = PTMP_tmp0_2;
        PTMP_tmp0_2 = NULL;
    }
    
    if (PrtPrimGetBool(P_VAR_isBumperReleasedRight_1))
    {
        PrtFreeValue(P_TurnLeft_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_3;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_3;
        }
        
    }
    
    else
    {
        PrtFreeValue(P_MoveBackward_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_3;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_3;
        }
        
    }
    
    
p_return_3: ;
    PrtFreeValue(P_VAR_isBumperReleasedRight_1); P_VAR_isBumperReleasedRight_1 = NULL;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_SC2 =
{
    "SC2",
    &P_SC2_IMPL,
    NULL,
    PRT_FALSE
};


PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PrtFreeValue(P_Init_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
    PrtGoto(p_this, 1U, 0);
    
    PRT_VALUE** P_LVALUE_13 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue((&P_LIT_BOOLEAN));
    
    PRT_VALUE** P_LVALUE_14 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = PrtCloneValue((&P_LIT_INT32));
    
p_return_4: ;
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
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 10 } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 200 } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 6 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_1 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_15 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtMkBoolValue(!PrtPrimGetBool(p_this->varValues[0]));
    
    if (PrtPrimGetBool(PTMP_tmp0_3))
    {
        PRT_VALUE** P_LVALUE_16 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_16);
        *P_LVALUE_16 = PrtCloneValue((&P_LIT_BOOLEAN_1));
        
        PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp1_1);
        PrtFreeValue(*P_LVALUE_17);
        *P_LVALUE_17 = ((_P_GEN_funval = P_DM_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_5;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_5;
        }
        
        {
            PRT_VALUE** P_LVALUE_18 = &(p_this->varValues[1]);
            PrtFreeValue(*P_LVALUE_18);
            *P_LVALUE_18 = PTMP_tmp1_1;
            PTMP_tmp1_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp2_1);
        PrtFreeValue(*P_LVALUE_19);
        *P_LVALUE_19 = PrtMkStringValue(PrtFormatString("SC2", 0, 0));
        ;
        
        PRT_VALUE** P_LVALUE_20 = &(PTMP_tmp3_1);
        PrtFreeValue(*P_LVALUE_20);
        *P_LVALUE_20 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], PTMP_tmp2_1));
        
        if (PrtPrimGetBool(PTMP_tmp3_1))
        {
            PrtFreeValue(P_SC2_IMPL(context, _P_GEN_funargs));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_5;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_5;
            }
            
            PRT_VALUE** P_LVALUE_21 = &(p_this->varValues[2]);
            PrtFreeValue(*P_LVALUE_21);
            *P_LVALUE_21 = PrtCloneValue((&P_LIT_INT32_1));
            
            PRT_VALUE** P_LVALUE_22 = &(p_this->varValues[4]);
            PrtFreeValue(*P_LVALUE_22);
            *P_LVALUE_22 = PrtCloneValue((&P_LIT_INT32_2));
            
            PRT_VALUE** P_LVALUE_23 = &(p_this->varValues[5]);
            PrtFreeValue(*P_LVALUE_23);
            *P_LVALUE_23 = PrtCloneValue((&P_LIT_INT32_3));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp4_1);
            PrtFreeValue(*P_LVALUE_24);
            *P_LVALUE_24 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp5_1);
            PrtFreeValue(*P_LVALUE_25);
            *P_LVALUE_25 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], PTMP_tmp4_1));
            
            if (PrtPrimGetBool(PTMP_tmp5_1))
            {
                PrtFreeValue(P_AC_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_5;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_5;
                }
                
                PRT_VALUE** P_LVALUE_26 = &(p_this->varValues[2]);
                PrtFreeValue(*P_LVALUE_26);
                *P_LVALUE_26 = PrtCloneValue((&P_LIT_INT32_4));
                
                PRT_VALUE** P_LVALUE_27 = &(p_this->varValues[4]);
                PrtFreeValue(*P_LVALUE_27);
                *P_LVALUE_27 = PrtCloneValue((&P_LIT_INT32_2));
                
                PRT_VALUE** P_LVALUE_28 = &(p_this->varValues[5]);
                PrtFreeValue(*P_LVALUE_28);
                *P_LVALUE_28 = PrtCloneValue((&P_LIT_INT32_3));
                
            }
            
            else
            {
                PrtFreeValue(P_SC1_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_5;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_5;
                }
                
                PRT_VALUE** P_LVALUE_29 = &(p_this->varValues[2]);
                PrtFreeValue(*P_LVALUE_29);
                *P_LVALUE_29 = PrtCloneValue((&P_LIT_INT32_1));
                
                PRT_VALUE** P_LVALUE_30 = &(p_this->varValues[4]);
                PrtFreeValue(*P_LVALUE_30);
                *P_LVALUE_30 = PrtCloneValue((&P_LIT_INT32_2));
                
                PRT_VALUE** P_LVALUE_31 = &(p_this->varValues[5]);
                PrtFreeValue(*P_LVALUE_31);
                *P_LVALUE_31 = PrtCloneValue((&P_LIT_INT32_3));
                
            }
            
            
        }
        
        
        PRT_VALUE** P_LVALUE_32 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PrtCloneValue((&P_LIT_INT32_4));
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp6_1);
        PrtFreeValue(*P_LVALUE_33);
        *P_LVALUE_33 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[2], p_this->varValues[3]));
        
        if (PrtPrimGetBool(PTMP_tmp6_1))
        {
            PRT_VALUE** P_LVALUE_34 = &(PTMP_tmp7);
            PrtFreeValue(*P_LVALUE_34);
            *P_LVALUE_34 = ((_P_GEN_funval = P_DM_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_5;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_5;
            }
            
            {
                PRT_VALUE** P_LVALUE_35 = &(p_this->varValues[1]);
                PrtFreeValue(*P_LVALUE_35);
                *P_LVALUE_35 = PTMP_tmp7;
                PTMP_tmp7 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp8);
            PrtFreeValue(*P_LVALUE_36);
            *P_LVALUE_36 = PrtMkStringValue(PrtFormatString("SC2", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_37 = &(PTMP_tmp9);
            PrtFreeValue(*P_LVALUE_37);
            *P_LVALUE_37 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], PTMP_tmp8));
            
            if (PrtPrimGetBool(PTMP_tmp9))
            {
                PrtFreeValue(P_SC2_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_5;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_5;
                }
                
                PRT_VALUE** P_LVALUE_38 = &(p_this->varValues[2]);
                PrtFreeValue(*P_LVALUE_38);
                *P_LVALUE_38 = PrtCloneValue((&P_LIT_INT32_1));
                
                PRT_VALUE** P_LVALUE_39 = &(p_this->varValues[4]);
                PrtFreeValue(*P_LVALUE_39);
                *P_LVALUE_39 = PrtCloneValue((&P_LIT_INT32_2));
                
                PRT_VALUE** P_LVALUE_40 = &(p_this->varValues[5]);
                PrtFreeValue(*P_LVALUE_40);
                *P_LVALUE_40 = PrtCloneValue((&P_LIT_INT32_3));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_41 = &(PTMP_tmp10);
                PrtFreeValue(*P_LVALUE_41);
                *P_LVALUE_41 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp11);
                PrtFreeValue(*P_LVALUE_42);
                *P_LVALUE_42 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], PTMP_tmp10));
                
                if (PrtPrimGetBool(PTMP_tmp11))
                {
                    PrtFreeValue(P_AC_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_5;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_5;
                    }
                    
                    PRT_VALUE** P_LVALUE_43 = &(p_this->varValues[2]);
                    PrtFreeValue(*P_LVALUE_43);
                    *P_LVALUE_43 = PrtCloneValue((&P_LIT_INT32_4));
                    
                    PRT_VALUE** P_LVALUE_44 = &(p_this->varValues[4]);
                    PrtFreeValue(*P_LVALUE_44);
                    *P_LVALUE_44 = PrtCloneValue((&P_LIT_INT32_2));
                    
                    PRT_VALUE** P_LVALUE_45 = &(p_this->varValues[5]);
                    PrtFreeValue(*P_LVALUE_45);
                    *P_LVALUE_45 = PrtCloneValue((&P_LIT_INT32_3));
                    
                }
                
                else
                {
                    PrtFreeValue(P_SC1_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_5;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_5;
                    }
                    
                    PRT_VALUE** P_LVALUE_46 = &(p_this->varValues[2]);
                    PrtFreeValue(*P_LVALUE_46);
                    *P_LVALUE_46 = PrtCloneValue((&P_LIT_INT32_1));
                    
                    PRT_VALUE** P_LVALUE_47 = &(p_this->varValues[4]);
                    PrtFreeValue(*P_LVALUE_47);
                    *P_LVALUE_47 = PrtCloneValue((&P_LIT_INT32_2));
                    
                    PRT_VALUE** P_LVALUE_48 = &(p_this->varValues[5]);
                    PrtFreeValue(*P_LVALUE_48);
                    *P_LVALUE_48 = PrtCloneValue((&P_LIT_INT32_3));
                    
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_49 = &(p_this->varValues[3]);
            PrtFreeValue(*P_LVALUE_49);
            *P_LVALUE_49 = PrtCloneValue((&P_LIT_INT32_4));
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp12);
            PrtFreeValue(*P_LVALUE_50);
            *P_LVALUE_50 = PrtMkStringValue(PrtFormatString("SC2", 0, 0));
            ;
            
            PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp13);
            PrtFreeValue(*P_LVALUE_51);
            *P_LVALUE_51 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], PTMP_tmp12));
            
            if (PrtPrimGetBool(PTMP_tmp13))
            {
                PrtFreeValue(P_SC2_IMPL(context, _P_GEN_funargs));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_5;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_5;
                }
                
                PRT_VALUE** P_LVALUE_52 = &(p_this->varValues[2]);
                PrtFreeValue(*P_LVALUE_52);
                *P_LVALUE_52 = PrtCloneValue((&P_LIT_INT32_1));
                
                PRT_VALUE** P_LVALUE_53 = &(p_this->varValues[4]);
                PrtFreeValue(*P_LVALUE_53);
                *P_LVALUE_53 = PrtCloneValue((&P_LIT_INT32_2));
                
                PRT_VALUE** P_LVALUE_54 = &(p_this->varValues[5]);
                PrtFreeValue(*P_LVALUE_54);
                *P_LVALUE_54 = PrtCloneValue((&P_LIT_INT32_3));
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp14);
                PrtFreeValue(*P_LVALUE_55);
                *P_LVALUE_55 = PrtMkStringValue(PrtFormatString("AC", 0, 0));
                ;
                
                PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp15);
                PrtFreeValue(*P_LVALUE_56);
                *P_LVALUE_56 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[1], PTMP_tmp14));
                
                if (PrtPrimGetBool(PTMP_tmp15))
                {
                    PrtFreeValue(P_AC_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_5;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_5;
                    }
                    
                    PRT_VALUE** P_LVALUE_57 = &(p_this->varValues[2]);
                    PrtFreeValue(*P_LVALUE_57);
                    *P_LVALUE_57 = PrtCloneValue((&P_LIT_INT32_4));
                    
                    PRT_VALUE** P_LVALUE_58 = &(p_this->varValues[4]);
                    PrtFreeValue(*P_LVALUE_58);
                    *P_LVALUE_58 = PrtCloneValue((&P_LIT_INT32_2));
                    
                    PRT_VALUE** P_LVALUE_59 = &(p_this->varValues[5]);
                    PrtFreeValue(*P_LVALUE_59);
                    *P_LVALUE_59 = PrtCloneValue((&P_LIT_INT32_3));
                    
                }
                
                else
                {
                    PrtFreeValue(P_SC1_IMPL(context, _P_GEN_funargs));
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_5;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_5;
                    }
                    
                    PRT_VALUE** P_LVALUE_60 = &(p_this->varValues[2]);
                    PrtFreeValue(*P_LVALUE_60);
                    *P_LVALUE_60 = PrtCloneValue((&P_LIT_INT32_1));
                    
                    PRT_VALUE** P_LVALUE_61 = &(p_this->varValues[4]);
                    PrtFreeValue(*P_LVALUE_61);
                    *P_LVALUE_61 = PrtCloneValue((&P_LIT_INT32_2));
                    
                    PRT_VALUE** P_LVALUE_62 = &(p_this->varValues[5]);
                    PrtFreeValue(*P_LVALUE_62);
                    *P_LVALUE_62 = PrtCloneValue((&P_LIT_INT32_3));
                    
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_63 = &(PTMP_tmp16);
            PrtFreeValue(*P_LVALUE_63);
            *P_LVALUE_63 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[3]) + PrtPrimGetInt((&P_LIT_INT32_4)));
            
            {
                PRT_VALUE** P_LVALUE_64 = &(p_this->varValues[3]);
                PrtFreeValue(*P_LVALUE_64);
                *P_LVALUE_64 = PTMP_tmp16;
                PTMP_tmp16 = NULL;
            }
            
        }
        
        
    }
    
    
p_return_5: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
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
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_2 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE** P_LVALUE_65 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_65);
    *P_LVALUE_65 = PrtCloneValue((&P_LIT_BOOLEAN_2));
    
    PRT_VALUE** P_LVALUE_66 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_66);
    *P_LVALUE_66 = PrtCloneValue((&P_LIT_INT32_5));
    
p_return_6: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_2,
    NULL,
    PRT_FALSE
};


PRT_FUNDECL* P_Robot_METHODS[] = { &P_FUNCTION_DM, &P_FUNCTION_AC, &P_FUNCTION_SC1, &P_FUNCTION_SC2, &P_FUNCTION_Anon, &P_FUNCTION_Anon_2, &P_FUNCTION_Anon_1 };

PRT_EVENTDECL* P_Robot_RECV_INNER_1[] = { &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Robot_RECV_1 =
{
    1U,
    P_Robot_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Robot_SEND_INNER[] = { &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Robot_SEND =
{
    1U,
    P_Robot_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_Robot = 
{
    0U,
    "Robot",
    &P_EVENTSET_Robot_RECV_1,
    &P_EVENTSET_Robot_SEND,
    NULL,
    6U,
    2U,
    7U,
    4294967295U,
    0U,
    0U,
    P_Robot_VARS,
    P_Robot_STATES,
    P_Robot_METHODS
};

PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Robot };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Robot };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { NULL };
int P_DefaultImpl_LME_0[] = { -1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0 };
int P_DefaultImpl_DEFMAP[] = { 0 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    2U,
    1U,
    1U,
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
