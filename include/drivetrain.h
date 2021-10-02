//
// Created by muram on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_DRIVETRAIN_H
#define PUCKCOLLECT2021_DRIVETRAIN_H


#include "Adafruit_BNO055.h"
#include "dc_expansion.h"
#include "robotmodule.h"

class Drivetrain : public RobotModule{

private:


    DCExpansion drivetrainMotorExpansion1 = DCExpansion(1);
    DCExpansion drivetrainMotorExpansion2 = DCExpansion(2);
public:
    Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

    double current_angle = .0f;

    void init() override;

    void update() override;

};

extern Drivetrain drivetrain;


double angle_transform(double);


#endif //PUCKCOLLECT2021_DRIVETRAIN_H
