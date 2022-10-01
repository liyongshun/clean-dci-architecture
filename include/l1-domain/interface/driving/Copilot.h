#ifndef INCL_CDA_INCLUDE_COPILOT_H_
#define INCL_CDA_INCLUDE_COPILOT_H_

#include "l4-infra/cda.h"
#include "l4-infra/cub/dci/fractal.h"
#include "l4-infra/cub/base/Status.h"

CDA_NS_BEGIN

DEF_I(Copilot)
{
    virtual Status routePlan() = 0;
    virtual Status navigate() = 0;
};

CDA_NS_END

#endif
