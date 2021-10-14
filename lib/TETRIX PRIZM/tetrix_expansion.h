//
// Created by User on 26.09.2021.
//

#ifndef TETRIXEXPANSION_H
#define TETRIXEXPANSION_H

#include <Arduino.h>
#include <Wire.h>

#define TETRIXEXPANSION_WDTSTOP (0x23)
#define TETRIXEXPANSION_ENABLE (0x25)
#define TETRIXEXPANSION_RESET (0x27)
#define TETRIXEXPANSION_SETID (0x24)
#define TETRIXEXPANSION_READFW (0x26)
#define DCEXPANSION_READVOLTAGE (0x53)


class TetrixExpansion {

protected:
    uint8_t address;
public:

    explicit TetrixExpansion(uint8_t address = 0);

    void WDT_STOP() const;
    void controllerEnable() const;
    void controllerReset() const;
    void setID(uint8_t newID);
    uint8_t readID();
    int16_t readFirmware() const;
    int16_t readBatteryVoltage() const;

};


#endif //TETRIXEXPANSION_H
