#include "l1-domain/behavior/driving/ParkingTheCar.h"
#include "l1-domain/interface/driving/CarDriver.h"

CDA_NS_BEGIN

Status ParkingTheCar::execute()
{
    I(CarDriver).park();

    return Result::SUCCESS;
}

CDA_NS_END
