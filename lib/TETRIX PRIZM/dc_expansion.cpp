//
// Created by User on 26.09.2021.
//

#include "dc_expansion.h"


void DCExpansion::setMotorPower(int16_t channel, int16_t power) {
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

void DCExpansion::setMotorPowers(int16_t power1, int16_t power2) {
    power1 = power1 < -100 ? -100 : power1 > 100 ? 100 : power1 == 0 && brake_on_zero_1 ? 125 : power1;
    power2 = power2 < -100 ? -100 : power2 > 100 ? 100 : power2 == 0 && brake_on_zero_2 ? 125 : power2;
    if (power1 != last_power_1 || power2 != last_power_2) {
        sendThreeInts(address, DCEXPANSION_SETPOWERS, power1, power2);
        last_power_1 = power1;
        last_power_2 = power2;
    }
}

void DCExpansion::setMotorSpeed(int16_t channel, int32_t Mspeed) {
    if (channel == 1) { channel = DCEXPANSION_SETSPEED1; }   // DC channel 1
    if (channel == 2) { channel = DCEXPANSION_SETSPEED2; }
    sendIntAndShortLong(address, channel, Mspeed);
}

void DCExpansion::setMotorSpeeds(int32_t Mspeed1, int32_t Mspeed2) {
    sendIntAndTwoShortLongs(address, DCEXPANSION_SETSPEEDS, Mspeed1, Mspeed2);
}

void DCExpansion::setMotorTarget(int16_t channel, int32_t Mspeed, int32_t Mtarget) {
    if (channel == 1) { channel = DCEXPANSION_SETTARGET1; }   // DC channel 1
    if (channel == 2) { channel = DCEXPANSION_SETTARGET2; }
    sendIntAndShortLongAndLong(address, channel, Mspeed, Mtarget);
}

void DCExpansion::setMotorTargets(int32_t Mspeed1, int32_t Mtarget1, int32_t Mspeed2, int32_t Mtarget2) {
    sendIntAndTwoShortLongsAndTwoLongs(address, DCEXPANSION_SETTARGETS, Mspeed1, Mtarget1, Mspeed2, Mtarget2);
}

void DCExpansion::setMotorInvert(int16_t channel, int16_t invertMotor, bool invertEncoder) {
    if (channel == 1) {
        channel = DCEXPANSION_SETINVERT1;
        invert_encoder_1 = invertEncoder;
    }   // DC channel 1
    else if (channel == 2) {
        channel = DCEXPANSION_SETINVERT2;
        invert_encoder_2 = invertEncoder;
    }
    sendTwoInts(address, channel, invertMotor);
}

void DCExpansion::setMotorBraking(int16_t channel, bool brakeOnZero) {
    if(channel == 1)
        brake_on_zero_1 = brakeOnZero;
    else if(channel == 2)
        brake_on_zero_2 = brakeOnZero;
}

int16_t DCExpansion::readMotorBusy(int16_t channel) {
    if (channel == 1) { channel = DCEXPANSION_READBUSY1; }   // DC channel 1
    if (channel == 2) { channel = DCEXPANSION_READBUSY2; }
    sendOneInt(address, channel);
    Wire.requestFrom(address, (uint8_t)1);
    int16_t byte1 = Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return byte1;
}

int16_t DCExpansion::readMotorCurrent(int16_t channel) {
    if (channel == 1) { channel = DCEXPANSION_READCURRENT1; }   // DC channel 1
    if (channel == 2) { channel = DCEXPANSION_READCURRENT2; }
    sendOneInt(address, channel);
    Wire.requestFrom(address, (uint8_t)2);
    byte byte1 = Wire.read();
    int16_t MotorCurrent = byte1 * 256 + Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return MotorCurrent;
}

int32_t DCExpansion::readEncoderCount(int16_t channel) {
    int8_t sign = 0;
    if (channel == 1) {
        channel = DCEXPANSION_READENCODER1;
        sign = invert_encoder_1 ? -1 : 1;
    }
    if (channel == 2) {
        channel = DCEXPANSION_READENCODER2;
        sign = invert_encoder_2 ? -1 : 1;
    }
    sendOneInt(address, channel);

    Wire.requestFrom(address, (uint8_t)4);
    byte byte1 = Wire.read();
    byte byte2 = Wire.read();
    byte byte3 = Wire.read();
    int32_t eCount = (((((byte1 * 256) + byte2) * 256) + byte3) * 256) + Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return sign * eCount;
}

void DCExpansion::resetEncoder(int16_t channel) {
    if (channel == 1) { channel = DCEXPANSION_RESETENCODER1; }
    if (channel == 2) { channel = DCEXPANSION_RESETENCODER2; }
    sendOneInt(address, channel);
}

void DCExpansion::resetEncoders() {
    sendOneInt(address, DCEXPANSION_RESETENCODERS);
}

void DCExpansion::setMotorSpeedPID(int16_t P, int16_t I, int16_t D) {
    sendFourInts(address, DCEXPANSION_SETSPEEDPID, P, I, D);
}

void DCExpansion::setMotorTargetPID(int16_t P, int16_t I, int16_t D) {
    sendFourInts(address, DCEXPANSION_SETTARGETPID, P, I, D);
}

void DCExpansion::setMotorInvert(int16_t channel, int16_t invertMotor) {
    setMotorInvert(channel,invertMotor,invertMotor);
}

