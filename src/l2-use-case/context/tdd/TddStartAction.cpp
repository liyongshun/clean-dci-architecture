#include "l2-use-case/context/tdd/TddStartAction.h"
#include <iostream>

CDA_NS_BEGIN

Status TddStartAction::exec(const TransactionInfo&)
{
    std::cout << "Start A TDD Cycle..." << std::endl;

    return CUB_SUCCESS;
}

CDA_NS_END
