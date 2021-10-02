/*  TETRIX PRIZM robotics controller cpp File for PRIZM Arduino Library
   	Written by: Paul W. Uttley
	01/03/2018
	Version 3.0
	=============== Added support for DC and Servo Motor EXPANSIONansion Controllers
	Default address for DC box is 1. Default for Servo box is 2.
	Additional boxes can be added in a daisy chain, and if so the addresses will need to be set different
	Valid address range for PRIZM to support is address 1 - 4.
	=============== Version 3 - fixed minor servo jitter related to PRIZM version 1 firmware ===============
	A workaround to fix is to change each servo channel position update to always update all servo channels with one I2C transaction.

*/

#include <Arduino.h>
#include <avr/wdt.h>
#include <Wire.h>
#include "prizm.h"

//#include "utility/WSWire.h"

Prizm prizm;

void Prizm::prizmBegin() {  //======= Send a SW reset to all EXPANSIONansion port I2C
    Wire.begin();

    for (int i = 1; i <= 6; i++)
        TetrixExpansion(i).controllerReset();
    delay(400);                        // Give EXPANSION controllers time to reset
    // SW reset on Expansion and DC + Servo chips at addresses 5 and 6 (7 is not used)
    for (int i = 1; i <= 6; i++)
        TetrixExpansion(i).controllerReset();

    unsigned long t_start = millis(); // Battery chere indication
    for (int i = 0; i < (readBatteryVoltage() - 1050) / 100; i++) {
        setRedLED(HIGH);
        setGreenLED(HIGH);
        delay(100);
        setRedLED(LOW);
        setGreenLED(LOW);
        delay(100);
    }
    setRedLED(LOW);
    setGreenLED(LOW);
    delay(500 - (millis() - t_start)>0?500 - (millis() - t_start):0); // 1 second delay between time GO button is pushed and program starts gives time for resets

    for (int i = 1; i <= 6; i++)
        TetrixExpansion(i).controllerEnable();

    setGreenLED(HIGH);                    // Turn on when we're reset
    while (readStartButton() == 0) {
        setRedLED(millis() % 3000 < 25 ? HIGH : LOW);
    }        // wait for the program start (green_value) button pressed
    setRedLED(HIGH);
    t_start = millis();
    while (millis() - t_start < 333 && readStartButton()) {}
    delay(20);
    while (readStartButton())
    setGreenLED(LOW);                    // turn green_value off


}

void Prizm::prizmEnd() {  //======= Send a SW reset to all I2C devices(resets everything) This is done mainly to stop all motors

    for (int i = 1; i <= 6; i++)
        TetrixExpansion(i).controllerReset();

    wdt_enable(WDTO_15MS);  // set the wdt to timeout after 15ms automatically resets
    for (;;) {
    }

}

int Prizm::readBatteryVoltage() {

    int Bvoltage = analogRead(0) * 2;
    return Bvoltage;
}

int Prizm::readLineSensor(int pin) {     // Can sense black or white (follow the edge of a black line on a white surface)
    int BWstate; // black or white
    pinMode(pin, INPUT);
    if (HIGH == digitalRead(pin)) { BWstate = 1; } else { BWstate = 0; }
    return BWstate;
}

int Prizm::readSonicSensorCM(int pin) {   // Returns distance of object from sensor in Centimeters

    delayMicroseconds(1000);  // added in version 2 to help with reading accuracy, can't read sonic sensors very fast
    int duration;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(2);
    digitalWrite(pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT);
    duration = pulseIn(pin, HIGH);
    return duration / 29 / 2; // convert time of echo to centimeters distance

}

void Prizm::setGreenLED(int state) {
    pinMode(7, OUTPUT); //===== GREEN LED is on pin 7
    if (state == 1) { digitalWrite(7, HIGH); }
    if (state == 0) { digitalWrite(7, LOW); }
}

void Prizm::setRedLED(int state) {
    pinMode(6, OUTPUT); //===== RED LED is on pin 6
    if (state == 1) { digitalWrite(6, HIGH); }
    if (state == 0) { digitalWrite(6, LOW); }
}

int Prizm::readStartButton() {       //============== function returns; unpressed button == 0; pressed button == 1
    pinMode(8, INPUT);    // Button is on pin 8; unpressed = high, pressed = low
    int StartBtn = digitalRead(8);
    StartBtn = !StartBtn; // toggle variable to make sense;
    return StartBtn;
}


//=========THE END ===========================================================================================================================================================


