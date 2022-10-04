#include "l1-domain/model/driving/ConcreteCarDriver.h"
#include <iostream>

CDA_NS_BEGIN

Status ConcreteCarDriver::drive()
{
    std::cout << "CarDriver Driving..." << std::endl;

    return Result::SUCCESS;
}
Status ConcreteCarDriver::park()
{
    std::cout << "CarDriver Parking..." << std::endl;

    return Result::SUCCESS;
}

CDA_NS_END
