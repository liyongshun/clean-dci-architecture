#include "l2-use-case/context/drving/StartDrvingAction.h"
#include "trans-dsl/action/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/driving/DrivingMsg.h"
#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/behavior/driving/StartDriving.h"
#include "l1-domain/behavior/driving/SendDrivingStartInd.h"
#include <iostream>

CDA_NS_BEGIN

auto StartDrvingAction::exec(TransactionInfo const&) -> TSL_NS::Status
{
    return WAIT_ON(EV_ROUTE_PLAN_COMPLETED_IND, MSG_HANDLER(RoutePlanCompletedInd) {
        std::cout << "Received EV_ROUTE_PLAN_COMPLETED_IND " << std::endl;
        TRANS_TO_ROLE(DrivingInf).B(StartDriving).execute();
        TRANS_TO_ROLE(DrivingInf).B(SendDrivingStartInd).execute();

        return Result::SUCCESS;
    });
}

CDA_NS_END
