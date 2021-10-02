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

    int last_position_1 = 90;        // these hold the current 'last' positions of each servo channel
    int last_position_2 = 90;
    int last_position_3 = 90;
    int last_position_4 = 90;
    int last_position_5 = 90;
    int last_position_6 = 90;

public:

    void setServoSpeed(int channel, int servospeed);

    void setServoSpeeds(int servospeed1, int servospeed2, int servospeed3, int servospeed4, int servospeed5, int servospeed6);

    void setServoPosition(int channel, int servoposition);

    void setServoPositions(int servoposition1, int servoposition2, int servoposition3, int servoposition4, int servoposition5, int servoposition6);

    void setCRServoState(int channel, int servospeed);

    int readServoPosition(int channel);
};


#endif //SVOEXPANSION_H
