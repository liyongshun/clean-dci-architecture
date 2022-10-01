#ifndef INCL_CDA_INCLUDE_TDDENDACTION_H_
#define INCL_CDA_INCLUDE_TDDENDACTION_H_

#include "l4-infra/cda.h"
#include "l4-infra/trans-dsl/action/SimpleAsyncActionHelper.h"

USING_TSL_NS

CDA_NS_BEGIN

struct RefactorCompletedInd;

DEF_SIMPLE_ASYNC_ACTION(TddEndAction)
{
    OVERRIDE(Status exec(const TransactionInfo&));

    ACTION_SIMPLE_EVENT_HANDLER_DECL(handleRefactorCompletedInd, RefactorCompletedInd);
};

CDA_NS_END

#endif
