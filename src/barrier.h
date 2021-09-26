//
// Created by muram on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_BARRIER_H
#define PUCKCOLLECT2021_BARRIER_H


#include "SPI.h"
#include "Adafruit_TCS34725.h"
#include "prizm.h"
#include "robotmodule.h"

class Barrier : public RobotModule{

private:
    Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_1X);

    ServoExpansion servoExpansion = prizm.integrated_servo;

public:
    void init() override;

    void update() override;
};

extern Barrier barrier;


#endif //PUCKCOLLECT2021_BARRIER_H
