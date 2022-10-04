#ifndef INCL_CDA_INCLUDE_PAIRINF_H_
#define INCL_CDA_INCLUDE_PAIRINF_H_

#include "l4-infra/cda.h"
#include "cub/dci/fractal.h"
#include "trans-dsl/tsl_status.h"

CDA_NS_BEGIN

struct PairDriver;
struct PairObserver;

DEF_I(PairInf)
{
    HAS_I(PairDriver);
    HAS_I(PairObserver);
};

CDA_NS_END

#endif
