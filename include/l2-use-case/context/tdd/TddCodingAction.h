#ifndef INCL_CDA_INCLUDE_TDDCODINGACTION_H_
#define INCL_CDA_INCLUDE_TDDCODINGACTION_H_

#include "l4-infra/cda.h"
#include "l4-infra/trans-dsl/action/SimpleAsyncActionHelper.h"

USING_TSL_NS

CDA_NS_BEGIN

struct TestCompletedInd;

DEF_SIMPLE_ASYNC_ACTION(TddCodingAction)
{
    OVERRIDE(Status exec(const TransactionInfo&));

    ACTION_SIMPLE_EVENT_HANDLER_DECL(handleTestCompletedInd, TestCompletedInd);
};

CDA_NS_END

#endif
