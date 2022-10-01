#include "l1-domain/behavior/driving/DrivingNavigation.h"
#include "l1-domain/interface/driving/Copilot.h"

CDA_NS_BEGIN

Status DrivingNavigation::execute()
{
    I(Copilot).navigate();

    return CUB_SUCCESS;
}

CDA_NS_END
