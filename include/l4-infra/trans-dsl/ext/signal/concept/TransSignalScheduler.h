#ifndef HA466B077_02E9_4409_95A5_4599FE9B2B9A
#define HA466B077_02E9_4409_95A5_4599FE9B2B9A

#include <l4-infra/cub/dci/InterfaceDef.h>
#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/trans-dsl/ext/signal/concept/TransSignalId.h>
#include <l4-infra/trans-dsl/tsl.h>

TSL_NS_BEGIN

UNKNOWN_INTERFACE(TransSignalScheduler, 0x09061329)
{
    ABSTRACT(cub::Status broadcast(const TransSignalId));
};

TSL_NS_END

#endif /* HA466B077_02E9_4409_95A5_4599FE9B2B9A */
