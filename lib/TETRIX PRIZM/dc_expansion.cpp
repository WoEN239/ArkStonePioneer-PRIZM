//
// Created by User on 26.09.2021.
//

#include "dc_expansion.h"


void DCExpansion::setMotorPower(int channel, int power) {
    power = power < -100 ? -100 : power > 100 ? 100 : power;
    if (channel == 1) {
        power = power == 0 && brake_on_zero_1 ? 125 : power;
        if (power != last_power_1) {
            sendTwoInts(address, DCEXPANSION_SETPOWER1, power);
            last_power_1 = power;
        }
    }   // DC channel 1
    if (channel == 2) {
        power = power == 0 && brake_on_zero_2 ? 125 : power;
        if (power != last_power_2) {
            sendTwoInts(address, DCEXPANSION_SETPOWER2, power);
            last_power_2 = power;
        }
    }   // DC channel 2

}

void DCExpansion::setMotorPowers(int power1, int power2) {
    power1 = power1 < -100 ? -100 : power1 > 100 ? 100 : power1 == 0 && brake_on_zero_1 ? 125 : power1;
    power2 = power2 < -100 ? -100 : power2 > 100 ? 100 : power2 == 0 && brake_on_zero_2 ? 125 : power2;
    if (power1 != last_power_1 || power2 != last_power_2) {
        sendThreeInts(address, DCEXPANSION_SETPOWERS, power1, power2);
        last_power_1 = power1;
        last_power_2 = power2;
    }
}

void DCExpansion::setMotorSpeed(int channel, long Mspeed) {
    if (channel == 1) { channel = DCEXPANSION_SETSPEED1; }   // DC channel 1
    if (channel == 2) { channel = DCEXPANSION_SETSPEED2; }
    sendIntAndShortLong(address, channel, Mspeed);
}

void DCExpansion::setMotorSpeeds(long Mspeed1, long Mspeed2) {
    sendIntAndTwoShortLongs(address, DCEXPANSION_SETSPEEDS, Mspeed1, Mspeed2);
}

void DCExpansion::setMotorTarget(int channel, long Mspeed, long Mtarget) {
    if (channel == 1) { channel = DCEXPANSION_SETTARGET1; }   // DC channel 1
    if (channel == 2) { channel = DCEXPANSION_SETTARGET2; }
    sendIntAndShortLongAndLong(address, channel, Mspeed, Mtarget);
}

void DCExpansion::setMotorTargets(long Mspeed1, long Mtarget1, long Mspeed2, long Mtarget2) {
    sendIntAndTwoShortLongsAndTwoLongs(address, DCEXPANSION_SETTARGETS, Mspeed1, Mtarget1, Mspeed2, Mtarget2);
}

void DCExpansion::setMotorInvert(int channel, int invertMotor, bool invertEncoder) {
    if (channel == 1) {
        channel = DCEXPANSION_SETINVERT1;
        invert_encoder_1 = invertEncoder;
    }   // DC channel 1
    if (channel == 2) {
        channel = DCEXPANSION_SETINVERT2;
        invert_encoder_2 = invertEncoder;
    }
    sendTwoInts(address, channel, invertMotor);
}

int DCExpansion::readMotorBusy(int channel) {
    if (channel == 1) { channel = DCEXPANSION_READBUSY1; }   // DC channel 1
    if (channel == 2) { channel = DCEXPANSION_READBUSY2; }
    sendOneInt(address, channel);
    Wire.requestFrom(address, 1);
    int byte1 = Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return byte1;
}

int DCExpansion::readMotorCurrent(int channel) {
    if (channel == 1) { channel = DCEXPANSION_READCURRENT1; }   // DC channel 1
    if (channel == 2) { channel = DCEXPANSION_READCURRENT2; }
    sendOneInt(address, channel);
    Wire.requestFrom(address, 2);
    byte byte1 = Wire.read();
    int MotorCurrent = byte1 * 256 + Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return MotorCurrent;
}

long DCExpansion::readEncoderCount(int channel) {
    int sign = 0;
    if (channel == 1) {
        channel = DCEXPANSION_READENCODER1;
        sign = invert_encoder_1 ? -1 : 1;
    }
    if (channel == 2) {
        channel = DCEXPANSION_READENCODER2;
        sign = invert_encoder_2 ? -1 : 1;
    }
    sendOneInt(address, channel);

    Wire.requestFrom(address, 4);
    byte byte1 = Wire.read();
    byte byte2 = Wire.read();
    byte byte3 = Wire.read();
    long eCount = (((((byte1 * 256) + byte2) * 256) + byte3) * 256) + Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return sign * eCount;
}

void DCExpansion::resetEncoder(int channel) {
    if (channel == 1) { channel = DCEXPANSION_RESETENCODER1; }
    if (channel == 2) { channel = DCEXPANSION_RESETENCODER2; }
    sendOneInt(address, channel);
}

void DCExpansion::resetEncoders() {
    sendOneInt(address, DCEXPANSION_RESETENCODERS);
}

void DCExpansion::setMotorSpeedPID(int P, int I, int D) {
    sendFourInts(address, DCEXPANSION_SETSPEEDPID, P, I, D);
}

void DCExpansion::setMotorTargetPID(int P, int I, int D) {
    sendFourInts(address, DCEXPANSION_SETTARGETPID, P, I, D);
}

