#include "l2-use-case/context/tdd/TddCodingAction.h"
#include "l4-infra/event/concept/Event.h"
#include "l4-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/tdd/TddInf.h"
#include "l1-domain/behavior/tdd/MakeOnlyEnoughCodeToPassTest.h"
#include "l1-domain/interface/tdd/TddMsg.h"
#include <iostream>

CDA_NS_BEGIN

Status TddCodingAction::exec(const TransactionInfo&)
{
   WAIT_ON(EV_TEST_COMPLETED_IND, handleTestCompletedInd);

   return CUB_CONTINUE;
}

ACTION_SIMPLE_EVENT_HANDLER_DEF(TddCodingAction, handleTestCompletedInd, TestCompletedInd)
{
    std::cout << "Received EV_TEST_COMPLETED_IND " << std::endl;

    TRANS_TO_ROLE(TddInf).B(MakeOnlyEnoughCodeToPassTest).execute();

    return CUB_SUCCESS;
}

CDA_NS_END
