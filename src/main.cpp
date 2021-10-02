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
    prizm.prizmBegin();
    //initalization phase 2
    barrier.init();
    drivetrain.init();
    intake.init();
    led_strip.init();

    prizm.setRedLED(HIGH);                    // Turn on when we're reset
    while (prizm.readStartButton() == 0) {
        prizm.setGreenLED(millis() % 200 < 100 ? HIGH : LOW);
    }        // wait for the program start (green_value) button pressed
    prizm.setGreenLED(LOW);
    prizm.setRedLED(LOW);
}

void loop() {
#ifdef SERIAL_DEBUGGING
    Serial.print("r "); Serial.print(barrier.red_value);
    Serial.print(" g "); Serial.print(barrier.green_value);
    Serial.print(" b "); Serial.print(barrier.blue_value);
    Serial.print(" "); Serial.print(drivetrain.current_angle); Serial.println(barrier.is_at_home);
#endif
    barrier.update();
    drivetrain.update();
    intake.update();
    led_strip.update();
}