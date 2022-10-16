//
// Created by DmitriiDenisov on 16.10.2022.
//
//extern "C" {
    #ifndef ARKSTONEPIONEER_PRIZM_PIDVASREGULATOR_H
    #define ARKSTONEPIONEER_PRIZM_PIDVASREGULATOR_H
#include <MathExtend.h>
    struct paramsRegulatorPIDVAS {
        double kP;
        double kI;
        double kD;
        double kV;
        double kA;
        double kS;
        double maxI;
        double kV_referenceVoltage;
        bool activeBraking;
    };

    double updateRegulator(struct paramsRegulatorPIDVAS *paramsRegulatorPIDVAS, double pos, double target, double voltage, double timeNow);
    #endif //ARKSTONEPIONEER_PRIZM_PIDVASREGULATOR_H
//}