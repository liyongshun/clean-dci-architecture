#include "l2-use-case/context/tdd/TddRefactorAction.h"
#include "l4-infra/event/concept/Event.h"
#include "l4-infra/trans-dsl/sched/concept/TransactionInfo.h"
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/tdd/TddInf.h"
#include "l1-domain/behavior/tdd/ImproveCodeQuality.h"
#include "l1-domain/behavior/tdd/SendRefactorCompletedInd.h"
#include <iostream>

CDA_NS_BEGIN

Status TddRefactorAction::exec(const TransactionInfo& trans)
{
    TRANS_TO_ROLE(TddInf).B(ImproveCodeQuality).execute();
    TRANS_TO_ROLE(TddInf).B(SendRefactorCompletedInd).execute();

    return CUB_SUCCESS;
}

CDA_NS_END
