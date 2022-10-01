#include "l1-domain/behavior/tdd/MakeOnlyEnoughCodeToPassTest.h"
#include "l1-domain/interface/pair/PairInf.h"
#include "l1-domain/interface/pair/PairDriver.h"

CDA_NS_BEGIN

Status MakeOnlyEnoughCodeToPassTest::execute()
{
    I(PairInf).I(PairDriver).coding();

    return CUB_SUCCESS;
}

CDA_NS_END
