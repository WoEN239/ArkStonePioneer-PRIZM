#include <Arduino.h>
#include "WireNoFreeze.h"
#include "SPI.h" //Does not compile without this magic line...
#include "Adafruit_TCS34725.h"
#include "Adafruit_BNO055.h"
#include "PRIZM.h"



class Barrier {
    Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);
public:
    void init();
    void update();
} barrier;

class Drivetrain {
    Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

public:
    void init();
    void update();
} drivetrain;

void Barrier::init() {
    tcs.begin();
}

void Barrier::update() {

}

void Drivetrain::init() {
    prizm.PrizmBegin();
    //bno.begin();
}

void Drivetrain::update() {

}

void setup() {
    //barrier.init();
    drivetrain.init();
}

void loop() {
    prizm.setMotorPowers(125,0);
    expansion.setMotorPowers(2,125,0);
}