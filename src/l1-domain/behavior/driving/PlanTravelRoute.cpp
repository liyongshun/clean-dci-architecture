#include "l1-domain/behavior/driving/PlanTravelRoute.h"
#include "l1-domain/interface/driving/Copilot.h"

CDA_NS_BEGIN

Status PlanTravelRoute::execute()
{
    I(Copilot).routePlan();

    return Result::SUCCESS;
}

CDA_NS_END
