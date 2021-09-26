//
// Created by User on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_LEDSTRIP_H
#define PUCKCOLLECT2021_LEDSTRIP_H


#include "robotmodule.h"

class LedStrip : public RobotModule {
public:
    void init() override;

    void update() override;

};


#endif //PUCKCOLLECT2021_LEDSTRIP_H
