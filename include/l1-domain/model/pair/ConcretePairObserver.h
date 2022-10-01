#ifndef INCL_CDA_INCLUDE_CONCRETETDDOBSERVER_H_
#define INCL_CDA_INCLUDE_CONCRETETDDOBSERVER_H_

#include "l1-domain/interface/pair/PairObserver.h"

CDA_NS_BEGIN

struct ConcretePairObserver : PairObserver
{
    virtual Status design() override;
    virtual Status test() override;
};

CDA_NS_END

#endif
