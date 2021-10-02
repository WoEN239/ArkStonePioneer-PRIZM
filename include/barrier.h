//
// Created by muram on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_BARRIER_H
#define PUCKCOLLECT2021_BARRIER_H


#include "SPI.h"
#include "Adafruit_TCS34725.h"
#include "prizm.h"
#include "robotmodule.h"
#include "drivetrain.h"

#define BARRIER_COLOR_INTEGRATIONTIME TCS34725_INTEGRATIONTIME_154MS
#define BARRIER_COLOR_TOLERANCE 50

#define BARRIER_SERVO_OPEN 120
#define BARRIER_SERVO_CLOSE 60
#define BARRIER_SERVO_PORT 1



class Barrier : public RobotModule{

private:

    void callibrateColor(int n_samples = 3);

    Adafruit_TCS34725 tcs = Adafruit_TCS34725(BARRIER_COLOR_INTEGRATIONTIME, TCS34725_GAIN_1X);

    ServoExpansion servoExpansion = prizm.integrated_servo;

    typeof(millis()) t_lastread = 0;

    float red_team = 0;
    float green_team = 0;
    float blue_team = 0;

    typeof(millis()) t_start_at_home;


public:

    float red_value = 0;
    float green_value = 0;
    float blue_value = 0;

    bool is_at_home = false;

    void getColor(float *r, float *g, float *b);

    void init() override;

    void update() override;

    bool detectTeamColor();
};

extern Barrier barrier;


#endif //PUCKCOLLECT2021_BARRIER_H
