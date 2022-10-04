#ifndef INCL_CDA_INCLUDE_L1_DOMAIN_INTERFACE_DRIVINGINF_H_
#define INCL_CDA_INCLUDE_L1_DOMAIN_INTERFACE_DRIVINGINF_H_

#include "l4-infra/cda.h"
#include "cub/dci/fractal.h"

CDA_NS_BEGIN

struct PlanTravelRoute;
struct SendRoutePlanCompletedInd;
struct StartDriving;
struct SendDrivingStartInd;
struct DrivingNavigation;
struct SendReachTheGoalInd;
struct ParkingTheCar;

DEF_I(DrivingInf)
{
    HAS_B(PlanTravelRoute);
    HAS_B(SendRoutePlanCompletedInd);
    HAS_B(StartDriving);
    HAS_B(SendDrivingStartInd);
    HAS_B(DrivingNavigation);
    HAS_B(SendReachTheGoalInd);
    HAS_B(ParkingTheCar);
};

CDA_NS_END

#endif
