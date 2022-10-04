#include "gtest/gtest.h"
#include "event/concept/Event.h"
#include "event/impl/ConsecutiveEventInfo.h"
#include "l2-use-case/interactions/Development.h"
#include "l1-domain/interface/tdd/TddMsg.h"

USING_TSL_NS
USING_EV_NS

CDA_NS_BEGIN

namespace
{
    TddTrans tddTransaction;
}

struct TddTransTest : testing::Test
{
    void SetUp() override
    {
        ASSERT_TRUE(CONTINUE == tddTransaction.start());
    }
};

TEST_F(TddTransTest, should_test_tdd_transtions)
{
    TestCompletedInd testCompletedInd;
    RefactorCompletedInd refactorCompletedInd;

    ASSERT_TRUE(CONTINUE == tddTransaction.handleEvent(ConsecutiveEventInfo(EV_TEST_COMPLETED_IND, testCompletedInd)));
    ASSERT_TRUE(SUCCESS == tddTransaction.handleEvent(ConsecutiveEventInfo(EV_REFACTOR_COMPLETED_IND, refactorCompletedInd)));
}

CDA_NS_END
