//
// Created by User on 26.09.2021.
//

#ifndef SVOEXPANSION_H
#define SVOEXPANSION_H

#include "tetrix_expansion.h"
#include "prizm_utils.h"

#define SVOEXPANSION_SETSERVOSPEED1 (0x28)
#define SVOEXPANSION_SETSERVOSPEED2 (0x29)
#define SVOEXPANSION_SETSERVOSPEED3 (0x2A)
#define SVOEXPANSION_SETSERVOSPEED4 (0x2B)
#define SVOEXPANSION_SETSERVOSPEED5 (0x2C)
#define SVOEXPANSION_SETSERVOSPEED6 (0x2D)
#define SVOEXPANSION_SETSERVOSPEEDS (0x2E)
#define SVOEXPANSION_SETSERVOPOSITION1 (0x2F)
#define SVOEXPANSION_SETSERVOPOSITION2 (0x30)
#define SVOEXPANSION_SETSERVOPOSITION3 (0x31)
#define SVOEXPANSION_SETSERVOPOSITION4 (0x32)
#define SVOEXPANSION_SETSERVOPOSITION5 (0x33)
#define SVOEXPANSION_SETSERVOPOSITION6 (0x34)
#define SVOEXPANSION_SETSERVOPOSITIONS (0x35)
#define SVOEXPANSION_SETCRSERVOSTATE1 (0x36)
#define SVOEXPANSION_SETCRSERVOSTATE2 (0x37)
#define SVOEXPANSION_READSERVOPOSITION1 (0x2F)
#define SVOEXPANSION_READSERVOPOSITION2 (0x30)
#define SVOEXPANSION_READSERVOPOSITION3 (0x31)
#define SVOEXPANSION_READSERVOPOSITION4 (0x32)
#define SVOEXPANSION_READSERVOPOSITION5 (0x33)
#define SVOEXPANSION_READSERVOPOSITION6 (0x34)


class ServoExpansion : public TetrixExpansion {

    using TetrixExpansion::TetrixExpansion;

private:

    int16_t last_position_1 = 90;        // these hold the current 'last' positions of each servo channel
    int16_t last_position_2 = 90;
    int16_t last_position_3 = 90;
    int16_t last_position_4 = 90;
    int16_t last_position_5 = 90;
    int16_t last_position_6 = 90;

public:

    void setServoSpeed(int16_t channel, int16_t servospeed);

    void setServoSpeeds(int16_t servospeed1, int16_t servospeed2, int16_t servospeed3, int16_t servospeed4, int16_t servospeed5, int16_t servospeed6);

    void setServoPosition(int16_t channel, int16_t servoposition);

    void setServoPositions(int16_t servoposition1, int16_t servoposition2, int16_t servoposition3, int16_t servoposition4, int16_t servoposition5, int16_t servoposition6);

    void setCRServoState(int16_t channel, int16_t servospeed);

    int16_t readServoPosition(int16_t channel);
};


#endif //SVOEXPANSION_H
