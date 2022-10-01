#ifndef INCL_CDA_INCLUDE_DRIVING_H_
#define INCL_CDA_INCLUDE_DRIVING_H_

#include "l1-domain/interface/driving/DrivingInf.h"
#include "l1-domain/model/driving/ConcreteCarDriver.h"
#include "l1-domain/model/driving/ConcreteCopilot.h"
#include "l1-domain/behavior/driving/DrivingNavigation.h"
#include "l1-domain/behavior/driving/ParkingTheCar.h"
#include "l1-domain/behavior/driving/PlanTravelRoute.h"
#include "l1-domain/behavior/driving/StartDriving.h"
#include "l1-domain/behavior/driving/SendDrivingStartInd.h"
#include "l1-domain/behavior/driving/SendReachTheGoalInd.h"
#include "l1-domain/behavior/driving/SendRoutePlanCompletedInd.h"

CDA_NS_BEGIN

struct Driving : DrivingInf
               , private ConcreteCarDriver
               , private ConcreteCopilot
               , private PlanTravelRoute
               , private SendRoutePlanCompletedInd
               , private StartDriving
               , private SendDrivingStartInd
               , private DrivingNavigation
               , private SendReachTheGoalInd
               , private ParkingTheCar
{
    IMPL_B(PlanTravelRoute);
    IMPL_B(SendRoutePlanCompletedInd);
    IMPL_B(StartDriving);
    IMPL_B(SendDrivingStartInd);
    IMPL_B(DrivingNavigation);
    IMPL_B(SendReachTheGoalInd);
    IMPL_B(ParkingTheCar);

private:
    IMPL_I(CarDriver);
    IMPL_I(Copilot);
};

CDA_NS_END


#endif
