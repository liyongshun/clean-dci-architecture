#ifndef INCL_CDA_INCLUDE_L2_USE_CASE_INTERACTIONS_GOHOME_H_
#define INCL_CDA_INCLUDE_L2_USE_CASE_INTERACTIONS_GOHOME_H_

#include "l4-infra/trans-dsl/TransactionDSL.h"
#include "l2-use-case/context/drving/RoutePlanAction.h"
#include "l2-use-case/context/drving/StartDrvingAction.h"
#include "l2-use-case/context/drving/NavigateAction.h"
#include "l2-use-case/context/drving/ParkingAction.h"

CDA_NS_BEGIN

__def(GoHomeTrans) __as
( __sequential( __call(RoutePlanAction)
              , __asyn(StartDrvingAction)
              , __asyn(NavigateAction)
              , __asyn(ParkingAction)
              )
);

CDA_NS_END

#endif
