#include "l1-domain/model/pair/ConcretePairDriver.h"
#include <iostream>

CDA_NS_BEGIN

Status ConcretePairDriver::coding()
{
    std::cout << "PairDriver Coding..." << std::endl;

    return Result::SUCCESS;
}
Status ConcretePairDriver::refactor()
{
    std::cout << "PairDriver Refactoring..." << std::endl;

    return Result::SUCCESS;
}

CDA_NS_END
