#ifndef INCL_CDA_INCLUDE_SENDTESTCOMPLETEDIND_H_
#define INCL_CDA_INCLUDE_SENDTESTCOMPLETEDIND_H_

#include "l4-infra/cda.h"
#include "cub/dci/fractal.h"
#include "trans-dsl/tsl_status.h"

CDA_NS_BEGIN

DEF_B(SendTestCompletedInd)
{
    Status execute();
};

CDA_NS_END

#endif
