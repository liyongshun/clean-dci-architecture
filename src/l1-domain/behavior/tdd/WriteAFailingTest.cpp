#include "l1-domain/behavior/tdd/WriteAFailingTest.h"
#include "l1-domain/interface/pair/PairObserver.h"
#include "l1-domain/interface/pair/PairInf.h"

CDA_NS_BEGIN

Status WriteAFailingTest::execute()
{
    I(PairInf).I(PairObserver).design();
    I(PairInf).I(PairObserver).test();

    return Result::SUCCESS;
}

CDA_NS_END
