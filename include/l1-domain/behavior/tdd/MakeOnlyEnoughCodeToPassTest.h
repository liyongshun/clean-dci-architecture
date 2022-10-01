#ifndef INCL_CDA_INCLUDE_MAKEONLYENOUGHCODETOPASSTEST_H_
#define INCL_CDA_INCLUDE_MAKEONLYENOUGHCODETOPASSTEST_H_

#include "l4-infra/cda.h"
#include "l4-infra/cub/dci/fractal.h"
#include "l4-infra/cub/base/Status.h"

CDA_NS_BEGIN

struct PairInf;

DEF_B(MakeOnlyEnoughCodeToPassTest)
{
    Status execute();

private:
    USE_I(PairInf);
};

CDA_NS_END

#endif
