#ifndef INCL_CDA_INCLUDE_SENDCODINGCOMPLETEDIND_H_
#define INCL_CDA_INCLUDE_SENDCODINGCOMPLETEDIND_H_

#include "l4-infra/cda.h"
#include "l4-infra/cub/dci/fractal.h"
#include "l4-infra/cub/base/Status.h"

CDA_NS_BEGIN

DEF_B(SendRefactorCompletedInd)
{
    Status execute();
};

CDA_NS_END

#endif
