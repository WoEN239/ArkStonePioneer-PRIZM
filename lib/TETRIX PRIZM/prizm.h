/* 	Header file for TETRIX PRIZM robotics controller Arduino Library
   	Written by: Paul W. Uttley
	01/03/2018
	Version 3.0
	=============== Added support for DC and Servo Motor Expansion Controllers =============================
	Default address for DC box is 1. Default for Servo box is 2.
	Additional boxes can be added in a daisy chain, and if so the addresses will need to be set different
	Valid address range for PRIZM to support is address 1 - 4.
	=============== Version 3 - fixed minor servo jitter related to PRIZM version 1 firmware ===============
	A workaround to fix is to change each servo channel position update to always update all servo channels with one I2C transaction.
*/

#include <Arduino.h>


#ifndef PRIZM_H
#define PRIZM_H

//#include <avr/wdt.h>
//#include <inttypes.h>
//#include <stdio.h>
//#include <string.h>
//#include "PRIZM.h"

//#include "utility/WSWire.h" // Not the standard Arduino library, but a variant that is supposed to perform better and not lock up

#include "tetrix_expansion.h"
#include "dc_expansion.h"
#include "servo_expansion.h"

class Prizm {


public:
    DCExpansion integrated_DC;
    ServoExpansion integrated_servo;

    Prizm() : integrated_DC(5), integrated_servo(6) {}

    int readLineSensor(int pin);
    int readSonicSensorCM(int pin);
    int readBatteryVoltage(void);
    void prizmBegin(void);
    void prizmEnd(void);
    void setGreenLED(int state);
    void setRedLED(int state);
    int readStartButton(void);

private:
};

extern Prizm prizm;

#endif







