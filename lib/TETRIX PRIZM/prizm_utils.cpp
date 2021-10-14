//
// Created by User on 26.09.2021.
//

#include "prizm_utils.h"

void send8(uint8_t address, uint8_t data, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data);
    Wire.endTransmission();
    delay(delay_ms);
}

void send2x8(uint8_t address, uint8_t data1, uint8_t data2, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.endTransmission();
    delay(delay_ms);
}

void send3x8(uint8_t address, uint8_t data1, uint8_t data2, uint8_t data3, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(data3);
    Wire.endTransmission();
    delay(delay_ms);
}

void send4x8(uint8_t address, uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(data3);
    Wire.write(data4);
    Wire.endTransmission();
    delay(delay_ms);
}

void
send7x8(uint8_t address, uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t data5, uint8_t data6,
        uint8_t data7, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(data3);
    Wire.write(data4);
    Wire.write(data5);
    Wire.write(data6);
    Wire.write(data7);
    Wire.endTransmission();
    delay(delay_ms);
}

void send8and16(uint8_t address, uint8_t idata, int16_t sldata, uint32_t delay_ms) {
    uint8_t lobyte;
    uint8_t hibyte;

    lobyte = lowByte(sldata);
    hibyte = highByte(sldata);

    Wire.beginTransmission(address);
    Wire.write(idata);
    Wire.write(hibyte);
    Wire.write(lobyte);
    Wire.endTransmission();
    delay(delay_ms);
}

void send8and16and32(uint8_t address, uint8_t idata, int16_t sldata, int32_t ldata, uint32_t delay_ms) {

    uint8_t lobyte;
    uint8_t hibyte;

    lobyte = lowByte(sldata);
    hibyte = highByte(sldata);

    uint8_t four = (ldata);
    uint8_t three = (ldata >> 8);
    uint8_t two = (ldata >> 16);
    uint8_t one = (ldata >> 24);

    Wire.beginTransmission(address);
    Wire.write(idata);
    Wire.write(hibyte);
    Wire.write(lobyte);
    Wire.write(one);
    Wire.write(two);
    Wire.write(three);
    Wire.write(four);
    Wire.endTransmission();
    delay(delay_ms);

}

void send8and2x16(uint8_t address, uint8_t idata, int16_t sldata1, int16_t sldata2, uint32_t delay_ms) {
    uint8_t lobyte1;
    uint8_t hibyte1;

    uint8_t lobyte2;
    uint8_t hibyte2;

    lobyte1 = lowByte(sldata1);
    hibyte1 = highByte(sldata1);

    lobyte2 = lowByte(sldata2);
    hibyte2 = highByte(sldata2);

    Wire.beginTransmission(address);
    Wire.write(idata);
    Wire.write(hibyte1);
    Wire.write(lobyte1);
    Wire.write(hibyte2);
    Wire.write(lobyte2);
    Wire.endTransmission();
    delay(delay_ms);
}

void
send8and2x16and32(uint8_t address, uint8_t idata, int16_t sldata1, int32_t ldata1, int16_t sldata2,
                    int32_t ldata2, uint32_t delay_ms) {
    uint8_t lobyte1;
    uint8_t hibyte1;

    uint8_t lobyte2;
    uint8_t hibyte2;

    lobyte1 = lowByte(sldata1);
    hibyte1 = highByte(sldata1);

    lobyte2 = lowByte(sldata2);
    hibyte2 = highByte(sldata2);

    uint8_t four1 = (ldata1);
    uint8_t three1 = (ldata1 >> 8);
    uint8_t two1 = (ldata1 >> 16);
    uint8_t one1 = (ldata1 >> 24);

    uint8_t four2 = (ldata2);
    uint8_t three2 = (ldata2 >> 8);
    uint8_t two2 = (ldata1 >> 16);
    uint8_t one2 = (ldata1 >> 24);

    Wire.beginTransmission(address);
    Wire.write(idata);
    Wire.write(hibyte1);
    Wire.write(lobyte1);
    Wire.write(one1);
    Wire.write(two1);
    Wire.write(three1);
    Wire.write(four1);
    Wire.write(hibyte2);
    Wire.write(lobyte2);
    Wire.write(one2);
    Wire.write(two2);
    Wire.write(three2);
    Wire.write(four2);
    Wire.endTransmission();
    delay(delay_ms);
}
