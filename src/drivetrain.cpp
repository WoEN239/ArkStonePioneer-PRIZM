//
// Created by muram on 26.09.2021.
//

#include "drivetrain.h"

Drivetrain drivetrain;

void Drivetrain::init() {

    bno.begin(Adafruit_BNO055::OPERATION_MODE_NDOF);
    bno.setExtCrystalUse(false);
    drivetrainMotorExpansion1.resetEncoders();
    drivetrainMotorExpansion2.resetEncoders();

}

void Drivetrain::update() {

    current_angle = angle_transform(bno.getVector(Adafruit_BNO055::VECTOR_EULER).x());
}

double angle_transform(double alpha){
    if(alpha>180.0)
    do alpha -= 360.0; while(alpha>180.0);
    else if(alpha<-180.0)
    do alpha += 360.0; while(alpha<-180.0);
    return alpha;
}

