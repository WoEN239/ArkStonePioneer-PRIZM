#include <Arduino.h>
#include "WireNoFreeze.h"
#include "SPI.h" //Does not compile without this magic line...
#include "Adafruit_TCS34725.h"
#include "Adafruit_BNO055.h"
#include "PRIZM.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

void setup() {
  // put your setup code here, to run once:
  prizm.PrizmBegin();
  bno.begin();
  tcs.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}