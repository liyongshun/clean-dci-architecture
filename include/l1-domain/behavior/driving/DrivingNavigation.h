#ifndef INCL_CDA_INCLUDE_L1_DOMAIN_BEHAVIOR_DRIVING_DRIVINGNAVIGATION_H_
#define INCL_CDA_INCLUDE_L1_DOMAIN_BEHAVIOR_DRIVING_DRIVINGNAVIGATION_H_

#include "l4-infra/cda.h"
#include "l4-infra/cub/dci/fractal.h"
#include "l4-infra/cub/base/Status.h"

CDA_NS_BEGIN

struct Copilot;

DEF_B(DrivingNavigation)
{
    Status execute();

private:
    USE_I(Copilot);
};

CDA_NS_END

#endif
