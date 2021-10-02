//
// Created by muram on 26.09.2021.
//

#include "barrier.h"

Barrier barrier;

void Barrier::getColor(float *r, float *g, float *b) {

    if (millis() - t_lastread < ((256 - BARRIER_COLOR_INTEGRATIONTIME) * 12 / 5))
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

    *r = ((float) r_raw / c_raw) * 255.0f;
    *g = ((float) g_raw / c_raw) * 255.0f;
    *b = ((float) b_raw / c_raw) * 255.0f;
}

void Barrier::init() {
    tcs.begin();
    servoExpansion.setServoPosition(BARRIER_SERVO_PORT, BARRIER_SERVO_OPEN);
    callibrateColor();
    servoExpansion.setServoPosition(BARRIER_SERVO_PORT, BARRIER_SERVO_CLOSE);
}

static bool raw_color_bool_last = false;

void Barrier::update() {
    getColor(&red_value, &green_value, &blue_value);
    bool raw_color_bool = detectTeamColor();
    if (!raw_color_bool_last && raw_color_bool)
        t_start_at_home = millis();
    raw_color_bool_last = raw_color_bool;
    is_at_home = raw_color_bool && ((millis() - t_start_at_home) > 333);
    servoExpansion.setServoPosition(BARRIER_SERVO_PORT,
                                    is_at_home && abs(angle_transform(drivetrain.current_angle-45.0)) < 90.0 ? BARRIER_SERVO_OPEN : BARRIER_SERVO_CLOSE);
}

void Barrier::callibrateColor(int n_samples) {
    auto *red_sample = (float *) (malloc(sizeof(float) * n_samples));
    auto *green_sample = (float *) malloc(sizeof(float) * n_samples);;
    auto *blue_sample = (float *) malloc(sizeof(float) * n_samples);
    for (int i = 0; i < 3; i++) {
        delay(((256 - BARRIER_COLOR_INTEGRATIONTIME) * 12 / 5));
        getColor(&red_sample[i], &green_sample[i], &blue_sample[i]);
        red_team += red_sample[i];
        green_team += green_sample[i];
        blue_team += blue_sample[i];
    }
    red_team /= n_samples;
    green_team /= n_samples;
    blue_team /= n_samples;

    free(red_sample);
    free(green_sample);
    free(blue_sample);

}

bool Barrier::detectTeamColor() {
    float delta_red = red_value - red_team;
    float delta_green = green_value - green_team;
    float delta_blue = blue_value - blue_team;

    return (sqrtf(delta_red * delta_red + delta_green * delta_green + delta_blue * delta_blue) <= BARRIER_COLOR_TOLERANCE);
}

