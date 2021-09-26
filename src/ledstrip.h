//
// Created by User on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_LEDSTRIP_H
#define PUCKCOLLECT2021_LEDSTRIP_H


#include "prizm.h"
#include "robotmodule.h"

class LedStrip : public RobotModule {
private:
    DCExpansion ledStripMotorExpansion = prizm.integrated_DC;

public:
    void init() override;

    void update() override;

};

extern LedStrip led_strip;


#endif //PUCKCOLLECT2021_LEDSTRIP_H
