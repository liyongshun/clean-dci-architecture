#include "l2-use-case/context/tdd/TddTestAction.h"
#include "l1-domain/interface/Instance.h"
#include <trans-dsl/action/TransactionInfo.h>
#include "l1-domain/interface/tdd/TddInf.h"
#include "l1-domain/behavior/tdd/WriteAFailingTest.h"
#include "l1-domain/behavior/tdd/SendTestCompletedInd.h"
#include <iostream>

CDA_NS_BEGIN

auto TddTestAction::operator()(TransactionInfo const& trans) -> Status
{
    TRANS_TO_ROLE(TddInf).B(WriteAFailingTest).execute();
    TRANS_TO_ROLE(TddInf).B(SendTestCompletedInd).execute();

    return Result::SUCCESS;
}

CDA_NS_END
