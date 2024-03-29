//
// Created by DmitriiDenisov on 20.10.2022.
//

#include "MotorAccelerationLimiter.h"

double currentPower = 0.0;
double timeOld_ = 0.0;
double setPowerMotorAccelerationLimiter(double requestedPower, struct paramsMotorAccelerationLimiter* paramsMotorAccelerationLimiter, double timeNow) {
    double power = 0.0;
    if (requestedPower != 0.0 ) {
        double somePower = abs(currentPower - requestedPower);
        double somePower2 = abs((timeNow - timeOld_) * paramsMotorAccelerationLimiter->maxAcceleration);
        power = min(somePower,somePower2);
        power *= sign(requestedPower - currentPower);
    }
    timeOld_ = timeNow;
    return power;
}
