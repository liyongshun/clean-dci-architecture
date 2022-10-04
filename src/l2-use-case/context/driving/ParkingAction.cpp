#include "l2-use-case/context/drving/ParkingAction.h"
#include "trans-dsl/action/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/driving/DrivingMsg.h"
#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/behavior/driving/ParkingTheCar.h"
#include <iostream>

CDA_NS_BEGIN

auto ParkingAction::exec(TransactionInfo const&) -> TSL_NS::Status
{
    return WAIT_ON(EV_REACH_THE_GOAL_IND, MSG_HANDLER(ReachTheGoalInd) {
        std::cout << "Received EV_REACH_THE_GOAL_IND " << std::endl;
        TRANS_TO_ROLE(DrivingInf).B(ParkingTheCar).execute();

        return Result::SUCCESS;
    });
}

CDA_NS_END
