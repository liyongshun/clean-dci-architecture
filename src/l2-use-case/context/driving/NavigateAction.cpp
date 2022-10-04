#include "l2-use-case/context/drving/NavigateAction.h"
#include "trans-dsl/action/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/driving/DrivingMsg.h"
#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/behavior/driving/DrivingNavigation.h"
#include "l1-domain/behavior/driving/SendReachTheGoalInd.h"
#include <iostream>

CDA_NS_BEGIN

auto NavigateAction::exec(TransactionInfo const&) -> TSL_NS::Status
{
    return WAIT_ON(EV_DRIVING_START_IND, MSG_HANDLER(DrivingStartInd) {
        std::cout << "Received EV_DRIVING_START_IND " << std::endl;
        TRANS_TO_ROLE(DrivingInf).B(DrivingNavigation).execute();
        TRANS_TO_ROLE(DrivingInf).B(SendReachTheGoalInd).execute();

        return Result::SUCCESS;
    });
}

CDA_NS_END
