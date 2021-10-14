//
// Created by oaleksander on 26.09.2021.
//

#ifndef PUCKCOLLECT2021_INTAKE_H
#define PUCKCOLLECT2021_INTAKE_H


#include "dc_expansion.h"
#include "robotmodule.h"

class Intake : public RobotModule{
private:
    DCExpansion intakeMotorExpansion = DCExpansion(3);

public:
    void init() override;

    void update() override;
};

extern Intake intake;


#endif //PUCKCOLLECT2021_INTAKE_H
