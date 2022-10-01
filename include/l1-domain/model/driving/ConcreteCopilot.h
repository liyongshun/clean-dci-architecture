#ifndef INCL_CDA_INCLUDE_CONCRETECOPILOT_CPP_
#define INCL_CDA_INCLUDE_CONCRETECOPILOT_CPP_

#include "l1-domain/interface/driving/Copilot.h"

CDA_NS_BEGIN

struct ConcreteCopilot : Copilot
{
    virtual Status routePlan() override;
    virtual Status navigate() override;
};

CDA_NS_END

#endif
