//
// Created by muram on 26.09.2021.
//

#include "barrier.h"

Barrier barrier;

void Barrier::getColor(float *r, float *g, float *b) {

    if (millis()-t_lastread<((256 - BARRIER_COLOR_INTEGRATIONTIME) * 12 / 5 + 1))
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

    *r = (float)r_raw / c_raw * 255.0;
    *g = (float)g_raw / c_raw * 255.0;
    *b = (float)b_raw / c_raw * 255.0;
}

void Barrier::init() {
    tcs.begin();
}

void Barrier::update() {
    getColor(&r,&g,&b);
}
