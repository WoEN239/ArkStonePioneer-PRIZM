#include <Arduino.h>
#include "WireNoFreeze.h"
#include "Prizm_Controller.h"

#define SERIAL_OUTPUT 115200

/*
#include "NewPing.h"
*/

void setup() {

#ifdef SERIAL_OUTPUT
    Serial.begin(SERIAL_OUTPUT);
#endif

    Prizm::prizmBegin(false);

    Prizm::setRedLED(HIGH);
    while (Prizm::readStartButton() == 0) {
        Prizm::setGreenLED(millis() % 200 < 100 ? HIGH : LOW);
    }        // wait for the program start (green_value) button pressed
    prizm.setGreenLED(LOW);

}

void loop() {
    Serial.print('1');
    delay(1000);

    Serial.print('2');
    delay(1000);

    Serial.print('3');
    delay(1000);

    Serial.print('4');
    delay(1000);

    Serial.print('5');
    delay(1000);
}