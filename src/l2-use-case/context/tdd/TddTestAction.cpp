#include "l2-use-case/context/tdd/TddTestAction.h"
#include "l1-domain/interface/Instance.h"
#include "l4-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l1-domain/interface/tdd/TddInf.h"
#include "l1-domain/behavior/tdd/WriteAFailingTest.h"
#include "l1-domain/behavior/tdd/SendTestCompletedInd.h"
#include <iostream>

CDA_NS_BEGIN

Status TddTestAction::exec(const TransactionInfo& trans)
{
    TRANS_TO_ROLE(TddInf).B(WriteAFailingTest).execute();
    TRANS_TO_ROLE(TddInf).B(SendTestCompletedInd).execute();

    return CUB_SUCCESS;
}

CDA_NS_END
