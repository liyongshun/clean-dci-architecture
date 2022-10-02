#ifndef H472AAFAE_FDA0_4FFB_BB90_E9B772F1DBB1
#define H472AAFAE_FDA0_4FFB_BB90_E9B772F1DBB1

#include <l4-infra/event/concept/EventId.h>
#include <l4-infra/trans-dsl/tsl.h>

TSL_NS_BEGIN

const ev::EventId EV_GLOBAL_TRANS_SIGNAL = 0xFFFC;

struct TransSignalMsg
{
    TransSignalMsg(const TransSignalId& signal)
        : signal(signal)
    {}

    TransSignalId signal;
};

TSL_NS_END

#endif /* H472AAFAE_FDA0_4FFB_BB90_E9B772F1DBB1 */
