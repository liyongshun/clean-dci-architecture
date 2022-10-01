#include "l1-domain/behavior/driving/StartDriving.h"
#include "l1-domain/interface/driving/CarDriver.h"

CDA_NS_BEGIN

Status StartDriving::execute()
{
    I(CarDriver).drive();

    return CUB_SUCCESS;
}

CDA_NS_END
