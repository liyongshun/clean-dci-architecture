#include "l2-use-case/context/drving/NavigateAction.h"
#include "l4-infra/event/concept/Event.h"
#include "l4-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/driving/DrivingMsg.h"
#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/behavior/driving/DrivingNavigation.h"
#include "l1-domain/behavior/driving/SendReachTheGoalInd.h"
#include <iostream>

CDA_NS_BEGIN

Status NavigateAction::exec(const TransactionInfo&)
{
   WAIT_ON(EV_DRIVING_START_IND, handleDrivingStartInd);

   return CUB_CONTINUE;
}

ACTION_SIMPLE_EVENT_HANDLER_DEF(NavigateAction, handleDrivingStartInd, DrivingStartInd)
{
    std::cout << "Received EV_DRIVING_START_IND " << std::endl;
    TRANS_TO_ROLE(DrivingInf).B(DrivingNavigation).execute();
    TRANS_TO_ROLE(DrivingInf).B(SendReachTheGoalInd).execute();

    return CUB_SUCCESS;
}

CDA_NS_END
