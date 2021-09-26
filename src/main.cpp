#include <Arduino.h>
#include "WireNoFreeze.h"
#include "prizm.h"


#include "drivetrain.h"

#include "barrier.h"
#include "intake.h"
#include "ledstrip.h"


void setup() {
    //initialization phase 1
    prizm.prizmBegin();
    //initalization phase 2
    barrier.init();
    drivetrain.init();
    intake.init();
    led_strip.init();

    prizm.setRedLED(HIGH);                    // Turn on when we're reset
    while (prizm.readStartButton() == 0) {
        prizm.setGreenLED(millis() % 333 < 166 ? HIGH : LOW);
    }        // wait for the program start (green) button pressed
    prizm.setGreenLED(LOW);
    prizm.setRedLED(LOW);
}

void loop() {
    barrier.update();
    drivetrain.update();
    intake.update();
    led_strip.update();
}