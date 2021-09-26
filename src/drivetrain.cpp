//
// Created by muram on 26.09.2021.
//

#include "drivetrain.h"

Drivetrain drivetrain;

void Drivetrain::init() {

    bno.begin();
    bno.setExtCrystalUse(true);
    drivetrainMotorExpansion1.resetEncoders();
    drivetrainMotorExpansion2.resetEncoders();

}

void Drivetrain::update() {

}
