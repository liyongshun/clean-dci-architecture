#ifndef INCL_CDA_INCLUDE_PAIRPROGRAMMING_H_
#define INCL_CDA_INCLUDE_PAIRPROGRAMMING_H_

#include "l1-domain/interface/pair/PairInf.h"
#include "l1-domain/model/pair/ConcretePairDriver.h"
#include "l1-domain/model/pair/ConcretePairObserver.h"

CDA_NS_BEGIN

struct PairProgramming : PairInf
                       , private ConcretePairDriver
                       , private ConcretePairObserver
{

//private:
    IMPL_I(PairDriver);
    IMPL_I(PairObserver);
};

CDA_NS_END

#endif
