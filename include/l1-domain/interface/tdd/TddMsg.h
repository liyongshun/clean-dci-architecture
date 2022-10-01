#ifndef INCL_CDA_INCLUDE_L1_DOMAIN_INTERFACE_TDDMSG_H_
#define INCL_CDA_INCLUDE_L1_DOMAIN_INTERFACE_TDDMSG_H_

#include "l4-infra/cda.h"
#include "l4-infra/event/concept/EventId.h"

using ev::EventId;

CDA_NS_BEGIN

struct TestCompletedInd
{
    int msg;
};

struct RefactorCompletedInd
{
    int msg;
};

const EventId EV_TEST_COMPLETED_IND = 101;
const EventId EV_REFACTOR_COMPLETED_IND = 102;

CDA_NS_END

#endif
