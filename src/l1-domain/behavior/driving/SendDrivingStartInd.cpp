#include "l1-domain/behavior/driving/SendDrivingStartInd.h"
#include <iostream>

CDA_NS_BEGIN

Status SendDrivingStartInd::execute()
{
    std::cout << "Send EV_DRIVING_START_IND" << std::endl;

    return CUB_SUCCESS;
}

CDA_NS_END
