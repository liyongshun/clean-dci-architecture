#include "l1-domain/model/pair/ConcretePairDriver.h"
#include <iostream>

CDA_NS_BEGIN

Status ConcretePairDriver::coding()
{
    std::cout << "PairDriver Coding..." << std::endl;

    return CUB_SUCCESS;
}
Status ConcretePairDriver::refactor()
{
    std::cout << "PairDriver Refactoring..." << std::endl;

    return CUB_SUCCESS;
}

CDA_NS_END
