#include "l2-use-case/context/tdd/TddRefactorAction.h"
#include <trans-dsl/action/TransactionInfo.h>
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/tdd/TddInf.h"
#include "l1-domain/behavior/tdd/ImproveCodeQuality.h"
#include "l1-domain/behavior/tdd/SendRefactorCompletedInd.h"

CDA_NS_BEGIN

auto TddRefactorAction::operator()(TransactionInfo const& trans) -> Status
{
    TRANS_TO_ROLE(TddInf).B(ImproveCodeQuality).execute();
    TRANS_TO_ROLE(TddInf).B(SendRefactorCompletedInd).execute();

    return Result::SUCCESS;
}

CDA_NS_END
