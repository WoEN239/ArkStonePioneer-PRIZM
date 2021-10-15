//
// Created by oaleksander on 26.09.2021.
//

#include "barrier.h"

Barrier barrier;

void Barrier::getColor(uint16_t *r, uint16_t *g, uint16_t *b) {

    if (millis() - t_lastread < BARRIER_COLOR_SAMPLEDELAY)
        return;

    uint16_t c_raw = tcs.read16(TCS34725_CDATAL);
    if (c_raw == 0) {
        *r = *g = *b = 0;
        return;
    }
    uint16_t r_raw = tcs.read16(TCS34725_RDATAL);
    uint16_t g_raw = tcs.read16(TCS34725_GDATAL);
    uint16_t b_raw = tcs.read16(TCS34725_BDATAL);

    t_lastread = millis();

    c_raw = 255;

    *r = (r_raw * 255) / c_raw;
    *g = (g_raw * 255) / c_raw;
    *b = (b_raw * 255) / c_raw;
}

void Barrier::init() {
    tcs.begin();
    servoExpansion.setServoPosition(BARRIER_SERVO_PORT, BARRIER_SERVO_OPEN);
    callibrateColor(BARRIER_COLOR_NCALIBRATIONSAMPLES);
    servoExpansion.setServoPosition(BARRIER_SERVO_PORT, BARRIER_SERVO_CLOSE);
}

bool raw_color_bool_last = false;

void Barrier::update() {
    getColor(&red_value, &green_value, &blue_value);
    bool raw_color_bool = detectTeamColor();
    if (!raw_color_bool_last && raw_color_bool)
        t_start_at_home = millis();
    raw_color_bool_last = raw_color_bool;
    is_at_home = raw_color_bool && ((millis() - t_start_at_home) > BARRIER_COLOR_DETECTION_TIMER_MS);
    servoExpansion.setServoPosition(BARRIER_SERVO_PORT,
                                    is_at_home && abs(angle_transform(gyro.current_angle - 45.0)) < BARRIER_ACTIVATION_ANGULAR_RANGE
                                    ? BARRIER_SERVO_OPEN : BARRIER_SERVO_CLOSE);

#ifdef SERIAL_DEBUGGING
    Serial.println(F(" - = Barrier = -"));
    Serial.print(F("r:")); Serial.print(barrier.red_value);
    Serial.print(F(" g:")); Serial.print(barrier.green_value);
    Serial.print(F(" b:")); Serial.print(barrier.blue_value);
    Serial.print(F(" athome:")); Serial.println(barrier.is_at_home);
#endif
}

void Barrier::callibrateColor(uint8_t n_samples) {
    uint16_t red_sample, green_sample, blue_sample;
    red_sample = green_sample = blue_sample = .0;
    red_team = green_team = blue_team = .0;
    for (uint8_t i = 0; i < n_samples; i++) {
        delay(BARRIER_COLOR_SAMPLEDELAY);
        getColor(&red_sample, &green_sample, &blue_sample);
        red_team += red_sample;
        green_team += green_sample;
        blue_team += blue_sample;
    }

    red_team /= n_samples;
    green_team /= n_samples;
    blue_team /= n_samples;


}

bool Barrier::detectTeamColor() {
    int32_t delta_red = red_value - red_team;
    int32_t delta_green = green_value - green_team;
    int32_t delta_blue = blue_value - blue_team;

    return (sqrtf((float) (delta_red * delta_red + delta_green * delta_green + delta_blue * delta_blue)) <= BARRIER_COLOR_TOLERANCE);
}

