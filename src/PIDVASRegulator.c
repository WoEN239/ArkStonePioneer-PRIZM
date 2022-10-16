//
// Created by DmitriiDenisov on 16.10.2022.
//
//extern "C" {
#include "PIDVASRegulator.h"
double timeOld = 0.0;
double velocityErrorOld = 0.0;
double I = 0.0;
double velocityTargetOld = 0.0;
double updateRegulator(struct paramsRegulatorPIDVAS *paramsRegulatorPIDVAS, double pos, double target, double voltage,
                       double timeNow) {
    double timeDelta = timeNow - timeOld;
    timeOld = timeNow;
    double power = 0.0;
    if (target != 0.0 || paramsRegulatorPIDVAS -> activeBraking) {
        double voltageDelta = paramsRegulatorPIDVAS -> kV_referenceVoltage / voltage;
        double velocityError = target - pos;
        double P = velocityError * paramsRegulatorPIDVAS->kP;
        double D = (velocityError - velocityErrorOld) * paramsRegulatorPIDVAS->kD / timeDelta;
        I += (paramsRegulatorPIDVAS->kI * velocityError) * timeDelta;
        if (abs(n) > paramsRegulatorPIDVAS->maxI) I = sign(I) * paramsRegulatorPIDVAS->maxI;
        double V = paramsRegulatorPIDVAS->kV * target * voltageDelta;
        double A = paramsRegulatorPIDVAS->kA * (target - velocityTargetOld) / timeDelta * voltageDelta;
        double S = paramsRegulatorPIDVAS->kS * sign(target) * voltageDelta;
        power = (P + I + D + V + A + S) / 32367.0;
        velocityErrorOld = velocityError;
        velocityTargetOld = target;
        if (!paramsRegulatorPIDVAS->activeBraking && sign(target) != sign(power)) power = 0.0;
    } else {
        power = 0.0;
        I = 0.0;
        velocityTargetOld = 0.0;
        velocityErrorOld = 0.0;
    }
    return power;
}
//}