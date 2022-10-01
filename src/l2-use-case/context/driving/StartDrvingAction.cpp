#include "l2-use-case/context/drving/StartDrvingAction.h"
#include "l4-infra/event/concept/Event.h"
#include "l4-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/driving/DrivingMsg.h"
#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/behavior/driving/StartDriving.h"
#include "l1-domain/behavior/driving/SendDrivingStartInd.h"
#include <iostream>

using cub::StartDrvingAction;

CDA_NS_BEGIN

Status StartDrvingAction::exec(const TransactionInfo&)
{
   WAIT_ON(EV_ROUTE_PLAN_COMPLETED_IND, handleRoutePlanCompletedInd);

   return CUB_CONTINUE;
}

ACTION_SIMPLE_EVENT_HANDLER_DEF(StartDrvingAction, handleRoutePlanCompletedInd, RoutePlanCompletedInd)
{
    std::cout << "Received EV_ROUTE_PLAN_COMPLETED_IND " << std::endl;
    TRANS_TO_ROLE(DrivingInf).B(StartDriving).execute();
    TRANS_TO_ROLE(DrivingInf).B(SendDrivingStartInd).execute();

    return CUB_SUCCESS;
}

CDA_NS_END
