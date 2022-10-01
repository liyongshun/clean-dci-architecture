#ifndef INCL_CDA_INCLUDE_INSTANCE_H_
#define INCL_CDA_INCLUDE_INSTANCE_H_

#include "l4-infra/cda.h"
#include "l4-infra/cub/dci/fractal.h"
#include "l4-infra/trans-dsl/sched/concept/InstanceId.h"

using tsl::InstanceId;

CDA_NS_BEGIN

struct TddInf;
struct DrivingInf;

const InstanceId Jobs = 1;
const InstanceId Gates = 2;

DEF_I(Instance)
{
    static Instance& getInstance(const InstanceId& iid);

    HAS_I(TddInf);
    HAS_I(DrivingInf);
};

CDA_NS_END

#define TRANS_TO_ROLE(role) \
    Instance::getInstance(trans.getInstanceId()).get##role()

#endif
