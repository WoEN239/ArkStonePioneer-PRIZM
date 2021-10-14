//
// Created by User on 26.09.2021.
//

#ifndef DCEXPANSION_H
#define DCEXPANSION_H

#include "tetrix_expansion.h"
#include "prizm_utils.h"

#define DCEXPANSION_SETPOWER1 (0x40)
#define DCEXPANSION_SETPOWER2 (0x41)
#define DCEXPANSION_SETPOWERS (0x42)
#define DCEXPANSION_SETSPEED1 (0x43)
#define DCEXPANSION_SETSPEED2 (0x44)
#define DCEXPANSION_SETSPEEDS (0x45)
#define DCEXPANSION_SETTARGET1 (0x46)
#define DCEXPANSION_SETTARGET2 (0x47)
#define DCEXPANSION_SETTARGETS (0x48)
#define DCEXPANSION_SETINVERT1 (0x51)
#define DCEXPANSION_SETINVERT2 (0x52)
#define DCEXPANSION_READBUSY1 (0x4F)
#define DCEXPANSION_READBUSY2 (0x50)
#define DCEXPANSION_READCURRENT1 (0x54)
#define DCEXPANSION_READCURRENT2 (0x55)
#define DCEXPANSION_READENCODER1 (0x49)
#define DCEXPANSION_READENCODER2 (0x4A)
#define DCEXPANSION_RESETENCODER1 (0x4C)
#define DCEXPANSION_RESETENCODER2 (0x4D)
#define DCEXPANSION_RESETENCODERS (0x4E)
#define DCEXPANSION_SETSPEEDPID (0X56)
#define DCEXPANSION_SETTARGETPID (0x57)
#define DCEXPANSION_BRAKEMOTOR (0x7D)

class DCExpansion : public TetrixExpansion {

    using TetrixExpansion::TetrixExpansion;

private:

    uint8_t last_power_1 = 0;
    uint8_t last_power_2 = 0;

public:

    bool brake_on_zero_1 = false;
    bool brake_on_zero_2 = false;

    bool invert_encoder_1 = false;
    bool invert_encoder_2 = false;

    void setMotorPower(uint8_t channel, int16_t power);

    void setMotorPowers(int16_t power1, int16_t power2);

    void setMotorSpeed(uint8_t channel, int16_t Mspeed);

    void setMotorSpeeds(int16_t Mspeed1, int16_t Mspeed2);

    void setMotorTarget(uint8_t channel, int16_t Mspeed, int32_t Mtarget);

    void setMotorTargets(int16_t Mspeed1, int32_t Mtarget1, int16_t Mspeed2, int32_t Mtarget2);

    void setMotorInvert(uint8_t channel, uint8_t invertMotor);

    void setMotorInvert(uint8_t channel, uint8_t invertMotor, bool invertEncoder);

    void setMotorBraking(uint8_t channel, bool brakeOnZero);

    int16_t readMotorBusy(uint8_t channel);

    int16_t readMotorCurrent(uint8_t channel);

    int32_t readEncoderCount(uint8_t channel);

    void resetEncoder(uint8_t channel);

    void resetEncoders();

    void setMotorSpeedPID(uint8_t P, uint8_t I, uint8_t D);

    void setMotorTargetPID(uint8_t P, uint8_t I, uint8_t D);


private:

};


#endif //DCEXPANSION_H
