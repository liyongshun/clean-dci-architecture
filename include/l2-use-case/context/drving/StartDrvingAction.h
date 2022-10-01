#ifndef INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_STARTDRVINGACTION_H_
#define INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_STARTDRVINGACTION_H_

#include "l4-infra/cda.h"
#include "l4-infra/trans-dsl/action/SimpleAsyncActionHelper.h"

USING_TSL_NS

CDA_NS_BEGIN

struct RoutePlanCompletedInd;

DEF_SIMPLE_ASYNC_ACTION(StartDrvingAction)
{
    OVERRIDE(Status exec(const TransactionInfo&));

    ACTION_SIMPLE_EVENT_HANDLER_DECL(handleRoutePlanCompletedInd, RoutePlanCompletedInd);
};

CDA_NS_END

#endif
