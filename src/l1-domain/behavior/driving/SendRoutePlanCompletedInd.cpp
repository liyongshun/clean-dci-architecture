#include "l1-domain/behavior/driving/SendRoutePlanCompletedInd.h"
#include <iostream>

CDA_NS_BEGIN

Status SendRoutePlanCompletedInd::execute()
{
    std::cout << "Send EV_ROUTE_PLAN_COMPLETED_IND" << std::endl;

    return Result::SUCCESS;
}

CDA_NS_END
