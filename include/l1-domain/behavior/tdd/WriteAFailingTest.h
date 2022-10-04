#ifndef INCL_CDA_INCLUDE_WRITEAFAILINGTEST_H_
#define INCL_CDA_INCLUDE_WRITEAFAILINGTEST_H_

#include "l4-infra/cda.h"
#include "cub/dci/fractal.h"
#include "trans-dsl/tsl_status.h"

CDA_NS_BEGIN

struct PairInf;

DEF_B(WriteAFailingTest)
{
    Status execute();

private:
    USE_I(PairInf);
};

CDA_NS_END

#endif
