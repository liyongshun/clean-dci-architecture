#include "l1-domain/behavior/tdd/SendTestCompletedInd.h"
#include <iostream>

CDA_NS_BEGIN

Status SendTestCompletedInd::execute()
{
    std::cout << "Send EV_TEST_COMPLETED_IND" << std::endl;

    return Result::SUCCESS;
}

CDA_NS_END
