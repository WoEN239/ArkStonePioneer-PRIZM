//
// Created by User on 26.09.2021.
//

#include "servo_expansion.h"

void ServoExpansion::setServoSpeed(uint8_t  channel, uint8_t  servospeed) {
    switch (channel) {
        case 1:
            channel = SVOEXPANSION_SETSERVOSPEED1;
            break;
        case 2:
            channel = SVOEXPANSION_SETSERVOSPEED2;
            break;
        case 3:
            channel = SVOEXPANSION_SETSERVOSPEED3;
            break;
        case 4:
            channel = SVOEXPANSION_SETSERVOSPEED4;
            break;
        case 5:
            channel = SVOEXPANSION_SETSERVOSPEED5;
            break;
        case 6:
            channel = SVOEXPANSION_SETSERVOSPEED6;
            break;
        default:
            break;
    }

    send2x8(address, channel, servospeed);
}

void ServoExpansion::setServoSpeeds(uint8_t  servospeed1, uint8_t  servospeed2, uint8_t  servospeed3, uint8_t  servospeed4, uint8_t  servospeed5, uint8_t  servospeed6) {
    send7x8(address, SVOEXPANSION_SETSERVOSPEEDS, servospeed1, servospeed2, servospeed3, servospeed4, servospeed5, servospeed6);
}

void ServoExpansion::setServoPosition(uint8_t  channel, uint8_t  servoposition) {
    bool xmit = false;
    switch (channel) {
        case 1:
            channel = SVOEXPANSION_SETSERVOPOSITION1;
            xmit = servoposition != last_position_1;
            last_position_6 = servoposition;
            break;
        case 2:
            channel = SVOEXPANSION_SETSERVOPOSITION2;
            xmit = servoposition != last_position_2;
            last_position_6 = servoposition;
            break;
        case 3:
            channel = SVOEXPANSION_SETSERVOPOSITION3;
            xmit = servoposition != last_position_3;
            last_position_6 = servoposition;
            break;
        case 4:
            channel = SVOEXPANSION_SETSERVOPOSITION4;
            xmit = servoposition != last_position_4;
            last_position_6 = servoposition;
            break;
        case 5:
            channel = SVOEXPANSION_SETSERVOPOSITION5;
            xmit = servoposition != last_position_5;
            last_position_6 = servoposition;
            break;
        case 6:
            channel = SVOEXPANSION_SETSERVOPOSITION6;
            xmit = servoposition != last_position_6;
            last_position_6 = servoposition;
            break;
        default:
            break;
    }

    if (xmit)
        send2x8(address, channel, servoposition);

}

void ServoExpansion::setServoPositions(uint8_t  servoposition1, uint8_t  servoposition2, uint8_t  servoposition3, uint8_t  servoposition4, uint8_t  servoposition5,
                                     uint8_t  servoposition6) {

    if (last_position_1 != servoposition1 || last_position_2 != servoposition2 || last_position_3 != servoposition3 ||
        last_position_4 != servoposition4 || last_position_5 != servoposition5 || last_position_6 != servoposition6) {
        send7x8(address, SVOEXPANSION_SETSERVOPOSITIONS, servoposition1, servoposition2, servoposition3, servoposition4,
                servoposition5,
                servoposition6);
        last_position_1 = servoposition1;
        last_position_2 = servoposition2;
        last_position_3 = servoposition3;
        last_position_4 = servoposition4;
        last_position_5 = servoposition5;
        last_position_6 = servoposition6;
    }
}

void ServoExpansion::setCRServoState(uint8_t  channel, uint8_t  servospeed) {
    if (channel == 1) { channel = SVOEXPANSION_SETCRSERVOSTATE1; }   // CRservo 1
    if (channel == 2) { channel = SVOEXPANSION_SETCRSERVOSTATE2; }   // CRservo 2

    send2x8(address, channel, servospeed);
}

int16_t ServoExpansion::readServoPosition(uint8_t channel) {
    switch (channel) {
        case 1:
            channel = SVOEXPANSION_READSERVOPOSITION1;
            break;
        case 2:
            channel = SVOEXPANSION_READSERVOPOSITION2;
            break;
        case 3:
            channel = SVOEXPANSION_READSERVOPOSITION3;
            break;
        case 4:
            channel = SVOEXPANSION_READSERVOPOSITION4;
            break;
        case 5:
            channel = SVOEXPANSION_READSERVOPOSITION5;
            break;
        case 6:
            channel = SVOEXPANSION_READSERVOPOSITION6;
            break;
        default:
            break;
    }

    send8(address, channel);
    Wire.requestFrom(address, (uint8_t)1);
    int16_t readServoPosition = Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return readServoPosition;
}

