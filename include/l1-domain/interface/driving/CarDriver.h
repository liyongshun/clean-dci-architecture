#ifndef INCL_INCLUDE_CARDRIVER_H_
#define INCL_INCLUDE_CARDRIVER_H_

#include "l4-infra/cda.h"
#include "l4-infra/cub/dci/fractal.h"
#include "l4-infra/cub/base/Status.h"

CDA_NS_BEGIN

DEF_I(CarDriver)
{
    virtual Status drive() = 0;
    virtual Status park() = 0;
};

CDA_NS_END

#endif
