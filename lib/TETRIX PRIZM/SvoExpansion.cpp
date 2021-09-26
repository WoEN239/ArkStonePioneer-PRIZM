//
// Created by User on 26.09.2021.
//

#include "SvoExpansion.h"

void SvoExpansion::setServoSpeed(int channel, int servospeed) {
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

    sendTwoInts(address, channel, servospeed);
}

void SvoExpansion::setServoSpeeds(int servospeed1, int servospeed2, int servospeed3, int servospeed4, int servospeed5, int servospeed6) {
    sendSevenInts(address, SVOEXPANSION_SETSERVOSPEEDS, servospeed1, servospeed2, servospeed3, servospeed4, servospeed5, servospeed6);
}

void SvoExpansion::setServoPosition(int channel, int servoposition) {
    bool xmit = false;
    switch (channel) {
        case 1:
            channel = SVOEXPANSION_SETSERVOPOSITION1;
            xmit = servoposition != lastPosition_1;
            lastPosition_6 = servoposition;
            break;
        case 2:
            channel = SVOEXPANSION_SETSERVOPOSITION2;
            xmit = servoposition != lastPosition_2;
            lastPosition_6 = servoposition;
            break;
        case 3:
            channel = SVOEXPANSION_SETSERVOPOSITION3;
            xmit = servoposition != lastPosition_3;
            lastPosition_6 = servoposition;
            break;
        case 4:
            channel = SVOEXPANSION_SETSERVOPOSITION4;
            xmit = servoposition != lastPosition_4;
            lastPosition_6 = servoposition;
            break;
        case 5:
            channel = SVOEXPANSION_SETSERVOPOSITION5;
            xmit = servoposition != lastPosition_5;
            lastPosition_6 = servoposition;
            break;
        case 6:
            channel = SVOEXPANSION_SETSERVOPOSITION6;
            xmit = servoposition != lastPosition_6;
            lastPosition_6 = servoposition;
            break;
        default:
            break;
    }

    if (xmit)
        sendTwoInts(address, channel, servoposition);

}

void SvoExpansion::setServoPositions(int servoposition1, int servoposition2, int servoposition3, int servoposition4, int servoposition5,
                                     int servoposition6) {

    if (lastPosition_1 != servoposition1 && lastPosition_2 != servoposition2 && lastPosition_3 != servoposition3 &&
        lastPosition_4 != servoposition4 && lastPosition_5 != servoposition5 && lastPosition_6 != servoposition6) {
        sendSevenInts(address, SVOEXPANSION_SETSERVOPOSITIONS, servoposition1, servoposition2, servoposition3, servoposition4,
                      servoposition5,
                      servoposition6);
        lastPosition_1 = servoposition1;
        lastPosition_2 = servoposition2;
        lastPosition_3 = servoposition3;
        lastPosition_4 = servoposition4;
        lastPosition_5 = servoposition5;
        lastPosition_6 = servoposition6;
    }
}

void SvoExpansion::setCRServoState(int channel, int servospeed) {
    if (channel == 1) { channel = SVOEXPANSION_SETCRSERVOSTATE1; }   // CRservo 1
    if (channel == 2) { channel = SVOEXPANSION_SETCRSERVOSTATE2; }   // CRservo 2

    sendTwoInts(address, channel, servospeed);
}

int SvoExpansion::readServoPosition(int channel) {
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

    sendOneInt(address, channel);
    Wire.requestFrom(address, 1);
    int readServoPosition = Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return readServoPosition;
}

