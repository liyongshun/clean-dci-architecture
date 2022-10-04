#include "gtest/gtest.h"
#include "event/concept/Event.h"
#include "event/impl/ConsecutiveEventInfo.h"
#include "l2-use-case/interactions/GoHome.h"
#include "l1-domain/interface/driving/DrivingMsg.h"
#include "trans-dsl/tsl_status.h"

USING_TSL_NS
USING_EV_NS

CDA_NS_BEGIN

namespace
{
    GoHomeTrans goHomeTransaction;
}

struct GoHomeTransTest : testing::Test
{
    void SetUp() override
    {
        ASSERT_TRUE(CONTINUE == goHomeTransaction.start());
    }
};

TEST_F(GoHomeTransTest, should_test_go_home_transtions)
{
    RoutePlanCompletedInd routePlanCmp;
    DrivingStartInd drivingStartInd;
    ReachTheGoalInd reachTheGoalInd;

    ASSERT_TRUE(CONTINUE == goHomeTransaction.handleEvent(ConsecutiveEventInfo(EV_ROUTE_PLAN_COMPLETED_IND, routePlanCmp)));
    ASSERT_TRUE(CONTINUE == goHomeTransaction.handleEvent(ConsecutiveEventInfo(EV_DRIVING_START_IND, drivingStartInd)));
    ASSERT_TRUE(SUCCESS == goHomeTransaction.handleEvent(ConsecutiveEventInfo(EV_REACH_THE_GOAL_IND, reachTheGoalInd)));
}

CDA_NS_END
