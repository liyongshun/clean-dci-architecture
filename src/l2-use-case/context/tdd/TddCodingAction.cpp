#include "l2-use-case/context/tdd/TddCodingAction.h"
#include <trans-dsl/action/TransactionInfo.h>
#include "l1-domain/interface/Instance.h"
#include "l1-domain/interface/tdd/TddInf.h"
#include "l1-domain/behavior/tdd/MakeOnlyEnoughCodeToPassTest.h"
#include "l1-domain/interface/tdd/TddMsg.h"
#include <iostream>

CDA_NS_BEGIN

auto TddCodingAction::exec(TransactionInfo const&) -> TSL_NS::Status
{
    return WAIT_ON(EV_TEST_COMPLETED_IND, MSG_HANDLER(TestCompletedInd) {
        std::cout << "Received EV_TEST_COMPLETED_IND " << std::endl;
        TRANS_TO_ROLE(TddInf).B(MakeOnlyEnoughCodeToPassTest).execute();

        return Result::SUCCESS;
    });
}

CDA_NS_END
