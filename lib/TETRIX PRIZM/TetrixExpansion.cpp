//
// Created by User on 26.09.2021.
//

#include "TetrixExpansion.h"
#include "PrizmUtils.h"

TetrixExpansion::TetrixExpansion(int address) {
    this->address = address;
}

void TetrixExpansion::WDT_STOP() const {
    sendOneInt(address, TETRIXEXPANSION_WDTSTOP, 50);
}

void TetrixExpansion::controllerReset() const {
    sendOneInt(address, TETRIXEXPANSION_RESET, 25);
}

void TetrixExpansion::setID(int newID) {
    if (int oldID = readID()) {// No other I2C devices can be connected to sensor ports when executing this command.

        sendTwoInts(oldID, TETRIXEXPANSION_SETID, newID);

        pinMode(6, OUTPUT);                //===== RED LED is on pin 6
        digitalWrite(6, HIGH);                // Flash PRIZM Red LED when finished
        delay(100);
        digitalWrite(6, LOW);
        delay(100);
        digitalWrite(6, HIGH);
        delay(100);
        digitalWrite(6, LOW);
        address = newID;
    }
}

void TetrixExpansion::controllerEnable() const {
    sendOneInt(address, TETRIXEXPANSION_ENABLE, 25);
}

int TetrixExpansion::readID() {
    int ID;                                    // All other I2C devices must also be disconnected from sensor ports when using this function

    for (int i = 1; i < 120 && !ID; i++) {            // Spin up I2C addresses from 1 - 120

        Wire.beginTransmission(i);

        if ((Wire.endTransmission() == 0) &&
            ((i < 5) || (i > 6)))    // Capture response from expansion controller (ignore 5 and 6 - they are used by PRIZM)
        {
            ID = i;
            address = ID;
            delay(10);
        }
    }

    return ID;
}

int TetrixExpansion::readFirmware() const {

    sendOneInt(address, TETRIXEXPANSION_READFW);
    Wire.requestFrom(address, 1);
    int DCversion = Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return DCversion;
}

int TetrixExpansion::readBatteryVoltage() const {
    sendOneInt(address, DCEXPANSION_READVOLTAGE);
    Wire.requestFrom(address, 2);
    byte byte1 = Wire.read();
    int Bvoltage = byte1 * 256 + Wire.read();
    delay(PRIZMUTILS_DEFAULT_I2C_DELAY);
    return Bvoltage;
}
