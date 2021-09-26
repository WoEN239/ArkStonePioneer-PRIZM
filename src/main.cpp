#include <Arduino.h>
#include "WireNoFreeze.h"
#include "SPI.h" //Does not compile without this magic line...
#include "Adafruit_TCS34725.h"
#include "Adafruit_BNO055.h"
#include "Prizm.h"



    Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

    Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

    Prizm prizm;

    DCExpansion drivetrainMotorExpansion1 = DCExpansion(1);
    DCExpansion drivetrainMotorExpansion2 = DCExpansion(2);
    DCExpansion intakeMotorExpansion2 = DCExpansion(3);
    DCExpansion ledStripMotorExpansion = prizm.integratedDC;

void setup() {
    prizm.prizmBegin();
}

void loop() {
}