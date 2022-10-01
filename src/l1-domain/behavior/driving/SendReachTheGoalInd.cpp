#include "l1-domain/behavior/driving/SendReachTheGoalInd.h"
#include <iostream>

CDA_NS_BEGIN

Status SendReachTheGoalInd::execute()
{
    std::cout << "Send EV_REACH_THE_GOAL_IND" << std::endl;

    return CUB_SUCCESS;
}

CDA_NS_END
