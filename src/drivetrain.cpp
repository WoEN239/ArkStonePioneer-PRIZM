//
// Created by oaleksander on 26.09.2021.
//

#include <gyro.h>

#include "drivetrain.h"

Drivetrain drivetrain;

void Drivetrain::init() {
    drivetrainMotorExpansion1.resetEncoders();
    drivetrainMotorExpansion2.resetEncoders();

    DRIVETRAIN_L1_CONTROLLER.setMotorInvert(DRIVETRAIN_L1_PORT, DRIVETRAIN_L1_INVERT);
    DRIVETRAIN_L2_CONTROLLER.setMotorInvert(DRIVETRAIN_L2_PORT, DRIVETRAIN_L2_INVERT);
    DRIVETRAIN_R1_CONTROLLER.setMotorInvert(DRIVETRAIN_R1_PORT, DRIVETRAIN_R1_INVERT);
    DRIVETRAIN_R2_CONTROLLER.setMotorInvert(DRIVETRAIN_R2_PORT, DRIVETRAIN_R2_INVERT);

    DRIVETRAIN_L1_CONTROLLER.setMotorBraking(DRIVETRAIN_L1_PORT, DRIVETRAIN_L1_BRAKE);
    DRIVETRAIN_L2_CONTROLLER.setMotorBraking(DRIVETRAIN_L2_PORT, DRIVETRAIN_L2_BRAKE);
    DRIVETRAIN_R1_CONTROLLER.setMotorBraking(DRIVETRAIN_R1_PORT, DRIVETRAIN_R1_BRAKE);
    DRIVETRAIN_R2_CONTROLLER.setMotorBraking(DRIVETRAIN_R2_PORT, DRIVETRAIN_R2_BRAKE);
}

void Drivetrain::update() {

}

void Drivetrain::powerMove(int16_t throttle, int16_t steering) {
    auto l_power = (int16_t)(throttle + steering);
    auto r_power = (int16_t)(throttle - steering);

    #if (DRIVETRAIN_L1_CONTROLLER == DRIVETRAIN_L2_CONTROLLER) && (DRIVETRAIN_L1_CONTROLLER == DRIVETRAIN_L2_CONTROLLER)
    DRIVETRAIN_L1_CONTROLLER.setMotorPowers(l_power,l_power);
    DRIVETRAIN_R1_CONTROLLER.setMotorPowers(r_power,r_power);
    #else
    drivetrainMotorExpansion1.setMotorPowers(l_power,r_power);
    drivetrainMotorExpansion2.setMotorPowers(l_power,r_power);
    #endif

}
