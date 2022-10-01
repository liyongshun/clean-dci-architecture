#include "l2-use-case/context/tdd/TddEndAction.h"
#include "l4-infra/event/concept/Event.h"
#include "l4-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l1-domain/interface/tdd/TddMsg.h"
#include <iostream>

CDA_NS_BEGIN

Status TddEndAction::exec(const TransactionInfo&)
{
   WAIT_ON(EV_REFACTOR_COMPLETED_IND, handleRefactorCompletedInd);

   return CUB_CONTINUE;
}

ACTION_SIMPLE_EVENT_HANDLER_DEF(TddEndAction, handleRefactorCompletedInd, RefactorCompletedInd)
{
    std::cout << "Received EV_REFACTOR_COMPLETED_IND " << std::endl;
    std::cout << "End A TDD Cycle" << std::endl;

    return CUB_SUCCESS;
}

CDA_NS_END
