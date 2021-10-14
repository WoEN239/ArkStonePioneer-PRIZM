//
// Created by oaleksander on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_BARRIER_H
#define PUCKCOLLECT2021_BARRIER_H


#include "SPI.h"
#include "Adafruit_TCS34725.h"
#include "prizm.h"
#include "robotmodule.h"
#include "gyro.h"

#define BARRIER_COLOR_INTEGRATIONTIME TCS34725_INTEGRATIONTIME_154MS
#define BARRIER_COLOR_SAMPLEDELAY ((256 - BARRIER_COLOR_INTEGRATIONTIME) * 12 / 5)
#define BARRIER_COLOR_NCALIBRATIONSAMPLES 3
#define BARRIER_COLOR_DETECTION_TIMER_MS 333
#define BARRIER_COLOR_TOLERANCE 50.0

#define BARRIER_ACTIVATION_ANGULAR_RANGE 90.0

#define BARRIER_SERVO_OPEN 120
#define BARRIER_SERVO_CLOSE 60
#define BARRIER_SERVO_PORT 1




class Barrier : public RobotModule{

private:

    void callibrateColor(uint8_t n_samples);

    Adafruit_TCS34725 tcs = Adafruit_TCS34725(BARRIER_COLOR_INTEGRATIONTIME, TCS34725_GAIN_1X);

    ServoExpansion servoExpansion = prizm.integrated_servo;

    typeof(millis()) t_lastread = 0;

    uint16_t red_team = .0;
    uint16_t green_team = .0;
    uint16_t blue_team = .0;

    typeof(millis()) t_start_at_home;


public:

    uint16_t red_value = 0;
    uint16_t green_value = 0;
    uint16_t blue_value = 0;

    bool is_at_home = false;

    void getColor(uint16_t *r, uint16_t *g, uint16_t *b);

    void init() override;

    void update() override;

    bool detectTeamColor();
};

extern Barrier barrier;


#endif //PUCKCOLLECT2021_BARRIER_H
