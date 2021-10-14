#include <Arduino.h>
#include "WireNoFreeze.h"
#include "prizm.h"


#define SERIAL_DEBUGGING 115200

#include "drivetrain.h"

#include "barrier.h"
#include "intake.h"
#include "ledstrip.h"


void setup() {
#ifdef SERIAL_DEBUGGING
    Serial.begin(SERIAL_DEBUGGING);
#endif
    //initialization phase 1
    Prizm::prizmBegin();
    //initalization phase 2
    barrier.init();
    drivetrain.init();
    intake.init();
    led_strip.init();

    Prizm::setRedLED(HIGH);                    // Turn on when we're reset
    while (Prizm::readStartButton() == 0) {
        Prizm::setGreenLED(millis() % 200 < 100 ? HIGH : LOW);
    }        // wait for the program start (green_value) button pressed
    Prizm::setGreenLED(LOW);
    Prizm::setRedLED(LOW);
}


void loop() {
    barrier.update();
    drivetrain.update();
    intake.update();
    led_strip.update();
}