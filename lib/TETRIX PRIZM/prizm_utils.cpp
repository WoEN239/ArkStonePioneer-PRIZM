//
// Created by User on 26.09.2021.
//

#include "prizm_utils.h"

void sendOneInt(int address, int data, int delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendTwoInts(int address, int data1, int data2, int delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendThreeInts(int address, int data1, int data2, int data3, int delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(data3);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendFourInts(int address, int data1, int data2, int data3, int data4, int delay_ms) {
    Wire.beginTransmission(address);
    Wire.write(data1);
    Wire.write(data2);
    Wire.write(data3);
    Wire.write(data4);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendSevenInts(int address, int data1, int data2, int data3, int data4, int data5, int data6, int data7, int delay_ms) {
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

void sendIntAndShortLong(int address, int idata, long sldata, int delay_ms) {
    int lobyte;
    int hibyte;

    lobyte = lowByte(sldata);
    hibyte = highByte(sldata);

    Wire.beginTransmission(address);
    Wire.write(idata);
    Wire.write(hibyte);
    Wire.write(lobyte);
    Wire.endTransmission();
    delay(delay_ms);
}

void sendIntAndShortLongAndLong(int address, int idata, long sldata, long ldata, int delay_ms) {

    int lobyte;
    int hibyte;

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

void sendIntAndTwoShortLongs(int address, int idata, long sldata1, long sldata2, int delay_ms) {
    int lobyte1;
    int hibyte1;

    int lobyte2;
    int hibyte2;

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

void sendIntAndTwoShortLongsAndTwoLongs(int address, int idata, long sldata1, long ldata1, long sldata2, long ldata2, int delay_ms) {
    int lobyte1;
    int hibyte1;

    int lobyte2;
    int hibyte2;

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
