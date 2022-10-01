#ifndef INCL_CDA_INCLUDE_BASE_CONCRETECARDRIVER_H_
#define INCL_CDA_INCLUDE_BASE_CONCRETECARDRIVER_H_

#include "l1-domain/interface/driving/CarDriver.h"

CDA_NS_BEGIN

struct ConcreteCarDriver : CarDriver
{
    virtual Status drive() override;
    virtual Status park() override;
};

CDA_NS_END

#endif
