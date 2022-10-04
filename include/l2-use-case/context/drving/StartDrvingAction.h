#ifndef INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_STARTDRVINGACTION_H_
#define INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_STARTDRVINGACTION_H_

#include "l4-infra/cda.h"
#include "trans-dsl/action/SimpleAsyncAction.h"

FWD_DECL_TSL(TransactionInfo);
USING_TSL_NS

CDA_NS_BEGIN

DEF_SIMPLE_ASYNC_ACTION(StartDrvingAction)
{
    auto exec(TransactionInfo const&) -> TSL_NS::Status;
};

CDA_NS_END

#endif
