#include "l2-use-case/context/drving/ParkingAction.h"
#include "l4-infra/event/concept/Event.h"
#include "l4-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/driving/DrivingMsg.h"
#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/behavior/driving/ParkingTheCar.h"
#include <iostream>

CDA_NS_BEGIN

Status ParkingAction::exec(const TransactionInfo&)
{
   WAIT_ON(EV_REACH_THE_GOAL_IND, handleReachTheGoalInd);

   return CUB_CONTINUE;
}

ACTION_SIMPLE_EVENT_HANDLER_DEF(ParkingAction, handleReachTheGoalInd, ReachTheGoalInd)
{
    std::cout << "Received EV_REACH_THE_GOAL_IND " << std::endl;
    TRANS_TO_ROLE(DrivingInf).B(ParkingTheCar).execute();

    return CUB_SUCCESS;
}

CDA_NS_END
