#ifndef INCL_CDA_INCLUDE_L1_DOMAIN_BEHAVIOR_DRIVING_STARTDRIVING_H_
#define INCL_CDA_INCLUDE_L1_DOMAIN_BEHAVIOR_DRIVING_STARTDRIVING_H_

#include "l4-infra/cda.h"
#include "cub/dci/fractal.h"
#include "trans-dsl/tsl_status.h"

CDA_NS_BEGIN

struct CarDriver;

DEF_B(StartDriving)
{
    Status execute();

private:
    USE_I(CarDriver);
};

CDA_NS_END

#endif
