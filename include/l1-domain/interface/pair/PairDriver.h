#ifndef INCL_INCLUDE_TDD_DRIVER_H_
#define INCL_INCLUDE_TDD_DRIVER_H_

#include "l4-infra/cda.h"
#include "cub/dci/fractal.h"
#include "trans-dsl/tsl_status.h"

CDA_NS_BEGIN

DEF_I(PairDriver)
{
    virtual Status coding() = 0;
    virtual Status refactor() = 0;
};

CDA_NS_END

#endif
