//
// Created by oaleksander on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_DRIVETRAIN_H
#define PUCKCOLLECT2021_DRIVETRAIN_H


#include "dc_expansion.h"
#include "robotmodule.h"

#define DRIVETRAIN_CONTROLLER1_ID 1
#define DRIVETRAIN_CONTROLLER2_ID 2

#define DRIVETRAIN_L1_CONTROLLER drivetrainMotorExpansion1
#define DRIVETRAIN_L2_CONTROLLER drivetrainMotorExpansion1
#define DRIVETRAIN_R1_CONTROLLER drivetrainMotorExpansion2
#define DRIVETRAIN_R2_CONTROLLER drivetrainMotorExpansion2

#define DRIVETRAIN_L1_PORT 1
#define DRIVETRAIN_L2_PORT 2
#define DRIVETRAIN_R1_PORT 1
#define DRIVETRAIN_R2_PORT 2

#define DRIVETRAIN_L1_BRAKE true
#define DRIVETRAIN_L2_BRAKE false
#define DRIVETRAIN_R1_BRAKE true
#define DRIVETRAIN_R2_BRAKE false

#warning Be VERY careful about paired motor directions
#define DRIVETRAIN_L1_INVERT true
#define DRIVETRAIN_L2_INVERT true
#define DRIVETRAIN_R1_INVERT false
#define DRIVETRAIN_R2_INVERT false

class Drivetrain : public RobotModule {

private:
    DCExpansion drivetrainMotorExpansion1 = DCExpansion(DRIVETRAIN_CONTROLLER1_ID);
    DCExpansion drivetrainMotorExpansion2 = DCExpansion(DRIVETRAIN_CONTROLLER2_ID);

public:
    void init() override;

    void update() override;

    void powerMove(int16_t throttle, int16_t steering);

};

extern Drivetrain drivetrain;

#endif //PUCKCOLLECT2021_DRIVETRAIN_H
