#include "l2-use-case/context/drving/RoutePlanAction.h"
#include "l4-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/behavior/driving/PlanTravelRoute.h"
#include "l1-domain/behavior/driving/SendRoutePlanCompletedInd.h"
#include <iostream>

CDA_NS_BEGIN

Status RoutePlanAction::exec(const TransactionInfo& trans)
{
    std::cout << "Start Route Plan..." << std::endl;
    TRANS_TO_ROLE(DrivingInf).B(PlanTravelRoute).execute();
    TRANS_TO_ROLE(DrivingInf).B(SendRoutePlanCompletedInd).execute();

    return CUB_SUCCESS;
}

CDA_NS_END
