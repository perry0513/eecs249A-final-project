package mop;

import p.runtime.values.*;
import db.*;

public aspect getConsistencyAspect {
    // Implement your code here.
    pointcut getConsistency_getReq(String key, int rId) : (execution(* Database.getReq(String, int)) && args(key, rId));
    after (String key, int rId) : getConsistency_getReq(key, rId) {
        getConsistencyRuntimeMonitor.getConsistency_eGetReqEvent(
            new NamedTuple(
                new String[]{"key", "rId"},
                new IValue<?>[]{new StringValue(key), new IntValue(rId)}
            )
        );
    }

    pointcut getConsistency_getRes(boolean res, Record r, int rId) : (execution(* Database.getRes(boolean, Record, int)) && args(res, r, rId));
    after (boolean res, Record r, int rId) : getConsistency_getRes(res, r, rId) {
        getConsistencyRuntimeMonitor.getConsistency_eGetRespEvent(
            new NamedTuple(
                new String[]{"res", "record", "rId"},
                new IValue<?>[]{
                    new BoolValue(res),
                    new NamedTuple(
                        new String[]{"key", "val", "sqr"},
                        new IValue<?>[]{new StringValue(r.key), new IntValue(r.val), new IntValue(r.sqr)}
                    ),
                    new IntValue(rId)
                }
            )
        );
    }

    pointcut getConsistency_putReq(Record r, int rId) : (execution(* Database.putReq(Record, int)) && args(r, rId));
    after (Record r, int rId) : getConsistency_putReq(r, rId) {
        getConsistencyRuntimeMonitor.getConsistency_ePutReqEvent(
            new NamedTuple(
                new String[]{"record", "rId"},
                new IValue<?>[]{
                    new NamedTuple(
                        new String[]{"key", "val", "sqr"},
                        new IValue<?>[]{new StringValue(r.key), new IntValue(r.val), new IntValue(r.sqr)}
                    ),
                    new IntValue(rId)
                }
            )
        );
    }

    pointcut getConsistency_putRes(boolean res, Record r, int rId) : (execution(* Database.putRes(boolean, Record, int)) && args(res, r, rId));
    after (boolean res, Record r, int rId) : getConsistency_putRes(res, r, rId) {
        getConsistencyRuntimeMonitor.getConsistency_ePutRespEvent(
            new NamedTuple(
                new String[]{"res", "record", "rId"},
                new IValue<?>[]{
                    new BoolValue(res),
                    new NamedTuple(
                        new String[]{"key", "val", "sqr"},
                        new IValue<?>[]{new StringValue(r.key), new IntValue(r.val), new IntValue(r.sqr)}
                    ),
                    new IntValue(rId)
                }
            )
        );
    }
}

