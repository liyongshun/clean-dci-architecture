#ifndef INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_ROUTEPLANACTION_H_
#define INCL_CDA_INCLUDE_L2_USE_CASE_CONTEXT_DRVING_ROUTEPLANACTION_H_

#include "l4-infra/cda.h"
#include <trans-dsl/tsl_status.h>

FWD_DECL_TSL(TransactionInfo);
USING_TSL_NS

CDA_NS_BEGIN

struct RoutePlanAction
{
   auto operator()(TransactionInfo const&) -> Status;
};

CDA_NS_END

#endif
