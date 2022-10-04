#include "l1-domain/model/pair/ConcretePairObserver.h"
#include <iostream>

CDA_NS_BEGIN

Status ConcretePairObserver::design()
{
    std::cout << "PairObserver Designing..." << std::endl;

    return Result::SUCCESS;
}
Status ConcretePairObserver::test()
{
    std::cout << "PairObserver Testing..." << std::endl;

    return Result::SUCCESS;
}

CDA_NS_END
