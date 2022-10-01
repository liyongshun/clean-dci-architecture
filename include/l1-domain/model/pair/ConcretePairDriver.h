#ifndef INCL_CDA_INCLUDE_CONCRETETDDDRIVER_H_
#define INCL_CDA_INCLUDE_CONCRETETDDDRIVER_H_

#include "l1-domain/interface/pair/PairDriver.h"

CDA_NS_BEGIN

struct ConcretePairDriver : PairDriver
{
    virtual Status coding() override;
    virtual Status refactor() override;
};

CDA_NS_END

#endif
