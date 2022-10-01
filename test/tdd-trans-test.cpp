#include "gtest/gtest.h"
#include "l4-infra/event/concept/Event.h"
#include "l4-infra/event/impl/ConsecutiveEventInfo.h"
#include "l2-use-case/interactions/Development.h"
#include "l1-domain/interface/tdd/TddMsg.h"

USING_EV_NS

CDA_NS_BEGIN

namespace
{
    __transaction( __apply(TddTrans)) tddTransaction;
}

struct TddTransTest : testing::Test
{
    void SetUp() override
    {
        ASSERT_TRUE(CUB_CONTINUE == tddTransaction.start());
    }
};

TEST_F(TddTransTest, should_test_tdd_transtions)
{
    TestCompletedInd testCompletedInd;
    RefactorCompletedInd refactorCompletedInd;

    ASSERT_TRUE(CUB_CONTINUE == tddTransaction.handleEvent(ConsecutiveEventInfo(EV_TEST_COMPLETED_IND, testCompletedInd)));
    ASSERT_TRUE(CUB_SUCCESS == tddTransaction.handleEvent(ConsecutiveEventInfo(EV_REFACTOR_COMPLETED_IND, refactorCompletedInd)));
}

CDA_NS_END

