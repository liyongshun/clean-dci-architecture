#include "l1-domain/model/driving/ConcreteCopilot.h"
#include <iostream>

CDA_NS_BEGIN

Status ConcreteCopilot::routePlan()
{
    std::cout << "Copilot Route Planning..." << std::endl;

    return Result::SUCCESS;
}
Status ConcreteCopilot::navigate()
{
    std::cout << "Copilot Navigating..." << std::endl;

    return Result::SUCCESS;
}

CDA_NS_END
