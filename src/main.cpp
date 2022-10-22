#include <Arduino.h>
#include "WireNoFreeze.h"
#include "Prizm_Controller.h"
#include "BNO055_support.h"

struct bno055_t gyro;
struct bno055_euler angleData;

PrizmDCExpansion driveExpansion(1);
#define LEFT_MOTOR_PORT_NUMBER 1
#define RIGHT_MOTOR_PORT_NUMBER 2

void setDrivePowers(int8_t forward, int8_t rotation) {
    driveExpansion.setPowers(forward + rotation, forward - rotation);
}

void rotate(double target) {
    double err;
    do {
        bno055_read_euler_hrp(&angleData);
        err = target - angleData.h / 16.00;
        while (abs(err) > 180.0) err -= 360.0;
        while (abs(err) < -180.0) err += 360.0;
        setDrivePowers(0, err * 0.8);
    }   while (abs(err) > 1.0);
    setDrivePowers(0, 0);
}

void setup() {
    pinMode(3, INPUT_PULLUP);
    PrizmController::begin(DO_NOT_WAIT_FOR_START_BUTTON);
    driveExpansion.setZeroPowerBehavior(LEFT_MOTOR_PORT_NUMBER, BRAKE);
    driveExpansion.setZeroPowerBehavior(RIGHT_MOTOR_PORT_NUMBER, BRAKE);
    driveExpansion.setDirection(LEFT_MOTOR_PORT_NUMBER, FORWARD);
    driveExpansion.setDirection(RIGHT_MOTOR_PORT_NUMBER, REVERSE);
    setDrivePowers(0,0);

    Prizm.MotorController.setPowers(0,100);
    while (digitalRead(3));

    BNO_Init(&gyro);
    bno055_set_operation_mode(OPERATION_MODE_NDOF);

    Serial.begin(115200);
    rotate(90.0);
    Prizm.MotorController.setPowers(0,-100);
}

void loop() {
}