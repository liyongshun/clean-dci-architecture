#include "l1-domain/behavior/tdd/SendRefactorCompletedInd.h"
#include <iostream>

CDA_NS_BEGIN

Status SendRefactorCompletedInd::execute()
{
    std::cout << "Send EV_REFACTOR_COMPLETED_IND" << std::endl;

    return CUB_SUCCESS;
}

CDA_NS_END
