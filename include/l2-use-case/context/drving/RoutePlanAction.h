#ifndef INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_ROUTEPLANACTION_H_
#define INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_ROUTEPLANACTION_H_

#include "l4-infra/cda.h"
#include "l4-infra/trans-dsl/action/SyncAction.h"

USING_TSL_NS

CDA_NS_BEGIN

struct RoutePlanAction : SyncAction
{
    OVERRIDE(Status exec(const TransactionInfo&));
};

CDA_NS_END

#endif
