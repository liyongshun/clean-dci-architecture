#ifndef INCL_CDA_INCLUDE_TDDINF_H_
#define INCL_CDA_INCLUDE_TDDINF_H_

#include "l4-infra/cda.h"
#include "cub/dci/fractal.h"
#include "trans-dsl/tsl_status.h"

CDA_NS_BEGIN

struct WriteAFailingTest;
struct MakeOnlyEnoughCodeToPassTest;
struct ImproveCodeQuality;
struct SendTestCompletedInd;
struct SendRefactorCompletedInd;

DEF_I(TddInf)
{
    HAS_B(WriteAFailingTest);
    HAS_B(MakeOnlyEnoughCodeToPassTest);
    HAS_B(ImproveCodeQuality);

    HAS_B(SendTestCompletedInd);
    HAS_B(SendRefactorCompletedInd);
};

CDA_NS_END

#endif
