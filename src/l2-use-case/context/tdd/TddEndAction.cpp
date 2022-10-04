#include "l2-use-case/context/tdd/TddEndAction.h"
#include <trans-dsl/action/TransactionInfo.h>
#include "l1-domain/interface/tdd/TddMsg.h"
#include <iostream>

CDA_NS_BEGIN

auto TddEndAction::exec(TransactionInfo const&) -> TSL_NS::Status
{
    return WAIT_ON(EV_REFACTOR_COMPLETED_IND, MSG_HANDLER(RefactorCompletedInd) {
        std::cout << "Received EV_REFACTOR_COMPLETED_IND " << std::endl;
        std::cout << "End A TDD Cycle" << std::endl;

        return Result::SUCCESS;
    });
}

CDA_NS_END
