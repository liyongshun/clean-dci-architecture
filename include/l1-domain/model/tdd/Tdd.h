#ifndef INCL_CDA_INCLUDE_TDD_H_
#define INCL_CDA_INCLUDE_TDD_H_

#include "l1-domain/interface/tdd/TddInf.h"
#include "l1-domain/interface/pair/PairInf.h"
#include "l1-domain/behavior/tdd/WriteAFailingTest.h"
#include "l1-domain/behavior/tdd/MakeOnlyEnoughCodeToPassTest.h"
#include "l1-domain/behavior/tdd/ImproveCodeQuality.h"
#include "l1-domain/model/pair/PairProgramming.h"
#include "l1-domain/behavior/tdd/SendTestCompletedInd.h"
#include "l1-domain/behavior/tdd/SendRefactorCompletedInd.h"

CDA_NS_BEGIN

struct Tdd : TddInf
           , private WriteAFailingTest
           , private MakeOnlyEnoughCodeToPassTest
           , private ImproveCodeQuality
           , private SendTestCompletedInd
           , private SendRefactorCompletedInd
           , private PairProgramming
{
    IMPL_B(WriteAFailingTest);
    IMPL_B(MakeOnlyEnoughCodeToPassTest);
    IMPL_B(ImproveCodeQuality);

    IMPL_B(SendTestCompletedInd);
    IMPL_B(SendRefactorCompletedInd);

private:
    IMPL_I(PairInf);
};

CDA_NS_END

#endif
