#ifndef INCL_CDA_INCLUDE_L1_DOMAIN_BEHAVIOR_DRIVING_SENDDRIVINGSTARTIND_H_
#define INCL_CDA_INCLUDE_L1_DOMAIN_BEHAVIOR_DRIVING_SENDDRIVINGSTARTIND_H_

#include "l4-infra/cda.h"
#include "l4-infra/cub/dci/fractal.h"
#include "l4-infra/cub/base/Status.h"

CDA_NS_BEGIN

DEF_B(SendDrivingStartInd)
{
    Status execute();
};

CDA_NS_END

#endif
