//
// Created by User on 26.09.2021.
//

#ifndef PRIZMUTILS_H
#define PRIZMUTILS_H

#include <Arduino.h>
#include <Wire.h>

#define PRIZMUTILS_DEFAULT_I2C_DELAY 10

void sendOneInt(int address, int data, int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendTwoInts(int address, int data1, int data2, int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendThreeInts(int address, int data1, int data2, int data3, int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendFourInts(int address, int data1, int data2, int data3, int data4, int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendSevenInts(int address, int data1, int data2, int data3, int data4, int data5, int data6, int data7,
                   int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendIntAndShortLong(int address, int idata, long sldata, int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendIntAndShortLongAndLong(int address, int idata, long sldata, long ldata, int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendIntAndTwoShortLongs(int address, int idata, long sldata1, long sldata2, int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendIntAndTwoShortLongsAndTwoLongs(int address, int idata, long sldata1, long ldata1, long sldata2, long ldata2,
                                        int delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);

#endif //PRIZMUTILS_H
