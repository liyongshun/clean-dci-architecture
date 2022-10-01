#include "l1-domain/behavior/tdd/ImproveCodeQuality.h"
#include "l1-domain/interface/pair/PairInf.h"
#include "l1-domain/interface/pair/PairDriver.h"

CDA_NS_BEGIN

Status ImproveCodeQuality::execute()
{
    I(PairInf).I(PairDriver).refactor();

    return CUB_SUCCESS;
}

CDA_NS_END
