//
// Created by User on 26.09.2021.
//

#include "prizm_utils.h"

void sendOneInt(uint8_t address, int16_t data, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendTwoInts(uint8_t address, int16_t data1, int16_t data2, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendThreeInts(uint8_t address, int16_t data1, int16_t data2, int16_t data3, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(data3);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendFourInts(uint8_t address, int16_t data1, int16_t data2, int16_t data3, int16_t data4, uint32_t delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(data3);
    Wire.write(data4);
    Wire.endTransmission();
    delay(delay_ms);
}

void
sendSevenInts(uint8_t address, int16_t data1, int16_t data2, int16_t data3, int16_t data4, int16_t data5, int16_t data6,
              int16_t data7, uint32_t delay_ms) {
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

void sendIntAndShortLong(uint8_t address, int16_t idata, int32_t sldata, uint32_t delay_ms) {
    int16_t lobyte;
    int16_t hibyte;

    lobyte = lowByte(sldata);
    hibyte = highByte(sldata);

    Wire.beginTransmission(address);
    Wire.write(idata);
    Wire.write(hibyte);
    Wire.write(lobyte);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendIntAndShortLongAndLong(uint8_t address, int16_t idata, int32_t sldata, int32_t ldata, uint32_t delay_ms) {

    int16_t lobyte;
    int16_t hibyte;

    lobyte = lowByte(sldata);
    hibyte = highByte(sldata);

    byte four = (ldata);
    byte three = (ldata >> 8);
    byte two = (ldata >> 16);
    byte one = (ldata >> 24);

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

void sendIntAndTwoShortLongs(uint8_t address, int16_t idata, int32_t sldata1, int32_t sldata2, uint32_t delay_ms) {
    int16_t lobyte1;
    int16_t hibyte1;

    int16_t lobyte2;
    int16_t hibyte2;

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
sendIntAndTwoShortLongsAndTwoLongs(uint8_t address, int16_t idata, int32_t sldata1, int32_t ldata1, int32_t sldata2,
                                   int32_t ldata2, uint32_t delay_ms) {
    int16_t lobyte1;
    int16_t hibyte1;

    int16_t lobyte2;
    int16_t hibyte2;

    lobyte1 = lowByte(sldata1);
    hibyte1 = highByte(sldata1);

    lobyte2 = lowByte(sldata2);
    hibyte2 = highByte(sldata2);

    byte four1 = (ldata1);
    byte three1 = (ldata1 >> 8);
    byte two1 = (ldata1 >> 16);
    byte one1 = (ldata1 >> 24);

    byte four2 = (ldata2);
    byte three2 = (ldata2 >> 8);
    byte two2 = (ldata1 >> 16);
    byte one2 = (ldata1 >> 24);

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
