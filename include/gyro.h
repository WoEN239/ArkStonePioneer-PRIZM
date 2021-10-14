//
// Created by User on 11.10.2021.
//

#ifndef PUCKCOLLECT2021_GYRO_H
#define PUCKCOLLECT2021_GYRO_H

//#define GYRO_CCW_ANGLE

#include "robotmodule.h"
#include "Adafruit_BNO055.h"

class Gyro : public RobotModule {

private:
    Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

public:
    float current_angle = .0f;
    void init() override;
    void update() override;

};

extern Gyro gyro;

float angle_transform(float);

#endif //PUCKCOLLECT2021_GYRO_H
