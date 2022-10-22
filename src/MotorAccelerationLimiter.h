//
// Created by DmitriiDenisov on 20.10.2022.
//

#ifndef ARKSTONEPIONEER_PRIZM_MOTORACCELERATIONLIMITER_H
#define ARKSTONEPIONEER_PRIZM_MOTORACCELERATIONLIMITER_H
#include "MathExtend.h"
#include <Arduino.h>
struct paramsMotorAccelerationLimiter {
    double maxAcceleration;
};

double setPowerMotorAccelerationLimiter(double requestedPower, struct paramsMotorAccelerationLimiter* paramsMotorAccelerationLimiter, double timeNow);
#endif //ARKSTONEPIONEER_PRIZM_MOTORACCELERATIONLIMITER_H
