//
// Created by User on 11.10.2021.
//

#include "gyro.h"

Gyro gyro;

void Gyro::init() {
    bno.begin(Adafruit_BNO055::OPERATION_MODE_NDOF);
    bno.setExtCrystalUse(false);
}

void Gyro::update() {
#ifdef GYRO_CCW_ANGLE
    current_angle = -angle_transform(bno.getVector(Adafruit_BNO055::VECTOR_EULER).x());
#else
    current_angle = angle_transform(bno.getVector(Adafruit_BNO055::VECTOR_EULER).x());
#endif // GYRO_CCW_ANGLE
#ifdef SERIAL_DEBUGGING
    Serial.println(" - = Gyro = -")
    Serial.print("degs:"); Serial.print(current_angle);
    Serial.print(" iscalibrated:"); Serial.println(bno.isFullyCalibrated());
#endif
}

float angle_transform(float alpha) {
    if (alpha > 180.0)
        do alpha -= 360.0; while (alpha > 180.0);
    else if (alpha < -180.0)
        do alpha += 360.0; while (alpha < -180.0);
    return alpha;
}
