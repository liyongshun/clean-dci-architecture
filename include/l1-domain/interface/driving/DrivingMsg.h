#ifndef INCL_CDA_INCLUDE_L1_DOMAIN_INTERFACE_DRIVING_DRIVINGMSG_H_
#define INCL_CDA_INCLUDE_L1_DOMAIN_INTERFACE_DRIVING_DRIVINGMSG_H_

#include "l4-infra/cda.h"
#include "event/concept/EventId.h"

using ev::EventId;

CDA_NS_BEGIN

struct RoutePlanCompletedInd
{
    int msg;
};

struct DrivingStartInd
{
    int msg;
};

struct ReachTheGoalInd
{
    int msg;
};

const EventId EV_ROUTE_PLAN_COMPLETED_IND = 201;
const EventId EV_DRIVING_START_IND = 202;
const EventId EV_REACH_THE_GOAL_IND = 203;

CDA_NS_END

#endif
