#include "gtest/gtest.h"
#include "l4-infra/event/concept/Event.h"
#include "l4-infra/event/impl/ConsecutiveEventInfo.h"
#include "l2-use-case/interactions/GoHome.h"
#include "l1-domain/interface/driving/DrivingMsg.h"

USING_EV_NS

CDA_NS_BEGIN

namespace
{
    __transaction( __apply(GoHomeTrans)) goHomeTransaction;
}

struct GoHomeTransTest : testing::Test
{
    void SetUp() override
    {
        ASSERT_TRUE(CUB_CONTINUE == goHomeTransaction.start());
    }
};

TEST_F(GoHomeTransTest, should_test_go_home_transtions)
{
    RoutePlanCompletedInd routePlanCmp;
    DrivingStartInd drivingStartInd;
    ReachTheGoalInd reachTheGoalInd;

    ASSERT_TRUE(CUB_CONTINUE == goHomeTransaction.handleEvent(ConsecutiveEventInfo(EV_ROUTE_PLAN_COMPLETED_IND, routePlanCmp)));
    ASSERT_TRUE(CUB_CONTINUE == goHomeTransaction.handleEvent(ConsecutiveEventInfo(EV_DRIVING_START_IND, drivingStartInd)));
    ASSERT_TRUE(CUB_SUCCESS == goHomeTransaction.handleEvent(ConsecutiveEventInfo(EV_REACH_THE_GOAL_IND, reachTheGoalInd)));
}

CDA_NS_END

