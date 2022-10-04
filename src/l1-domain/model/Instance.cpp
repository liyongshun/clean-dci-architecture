#include "l1-domain/interface/Instance.h"
#include "l1-domain/model/tdd/Tdd.h"
#include "l1-domain/model/driving/Driving.h"

CDA_NS_BEGIN

struct InstanceImpl : Instance
                    , private Tdd
                    , private Driving
{
    IMPL_I(TddInf);
    IMPL_I(DrivingInf);
};

namespace
{
    const int MAX_INST_NUM = 5;
    InstanceImpl inst[MAX_INST_NUM];
}

Instance& Instance::getInstance(const InstanceId& iid)
{
    if (iid >= MAX_INST_NUM) return inst[0];
    return inst[iid];
}

CDA_NS_END

