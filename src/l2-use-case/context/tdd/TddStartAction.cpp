#include "l2-use-case/context/tdd/TddStartAction.h"
#include <trans-dsl/action/TransactionInfo.h>
#include <iostream>

CDA_NS_BEGIN

auto TddStartAction::operator()(TransactionInfo const&) -> Status
{
    std::cout << "Start A TDD Cycle..." << std::endl;

    return Result::SUCCESS;
}

CDA_NS_END
