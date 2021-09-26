//
// Created by muram on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_BARRIER_H
#define PUCKCOLLECT2021_BARRIER_H


#include "SPI.h"
#include "Adafruit_TCS34725.h"
#include "prizm.h"
#include "robotmodule.h"

#define BARRIER_COLOR_INTEGRATIONTIME TCS34725_INTEGRATIONTIME_154MS

#define SERVO_OPEN 0
#define SERVO_CLOSE 0
#define SERVO_PORT 1

class Barrier : public RobotModule{

private:

    Adafruit_TCS34725 tcs = Adafruit_TCS34725(BARRIER_COLOR_INTEGRATIONTIME, TCS34725_GAIN_4X);

    ServoExpansion servoExpansion = prizm.integrated_servo;

    typeof(millis()) t_lastread = 0;

    float r = 0;
    float g = 0;
    float b = 0;

public:

    void getColor(float *r, float *g, float *b);

    void init() override;

    void update() override;

};

extern Barrier barrier;


#endif //PUCKCOLLECT2021_BARRIER_H
