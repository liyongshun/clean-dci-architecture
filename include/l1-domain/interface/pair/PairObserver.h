#ifndef INCL_INCLUDE_TDDOBSERVER_H_
#define INCL_INCLUDE_TDDOBSERVER_H_

#include "l4-infra/cda.h"
#include "l4-infra/cub/dci/fractal.h"
#include "l4-infra/cub/base/Status.h"

CDA_NS_BEGIN

DEF_I(PairObserver)
{
    virtual Status design() = 0;
    virtual Status test() = 0;
};

CDA_NS_END

#endif
