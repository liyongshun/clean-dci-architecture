#include "l2-use-case/context/drving/RoutePlanAction.h"
#include "trans-dsl/action/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/behavior/driving/PlanTravelRoute.h"
#include "l1-domain/behavior/driving/SendRoutePlanCompletedInd.h"
#include <iostream>

CDA_NS_BEGIN

auto RoutePlanAction::operator()(TransactionInfo const& trans) -> Status
{
    std::cout << "Start Route Plan..." << std::endl;
    TRANS_TO_ROLE(DrivingInf).B(PlanTravelRoute).execute();
    TRANS_TO_ROLE(DrivingInf).B(SendRoutePlanCompletedInd).execute();

    return Result::SUCCESS;
}

CDA_NS_END
