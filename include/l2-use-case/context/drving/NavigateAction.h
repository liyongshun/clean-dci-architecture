#ifndef INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_NAVIGATEACTION_H_
#define INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_NAVIGATEACTION_H_

#include "l4-infra/cda.h"
#include "l4-infra/trans-dsl/action/SimpleAsyncActionHelper.h"

USING_TSL_NS

CDA_NS_BEGIN

struct DrivingStartInd;

DEF_SIMPLE_ASYNC_ACTION(NavigateAction)
{
    OVERRIDE(Status exec(const TransactionInfo&));

    ACTION_SIMPLE_EVENT_HANDLER_DECL(handleDrivingStartInd, DrivingStartInd);
};

CDA_NS_END

#endif
