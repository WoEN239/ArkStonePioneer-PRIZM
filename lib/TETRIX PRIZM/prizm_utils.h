//
// Created by User on 26.09.2021.
//

#ifndef PRIZMUTILS_H
#define PRIZMUTILS_H

#include <Arduino.h>
#include <Wire.h>

#define PRIZMUTILS_DEFAULT_I2C_DELAY 10

void sendOneInt(uint8_t address, int16_t data, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendTwoInts(uint8_t address, int16_t data1, int16_t data2, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendThreeInts(uint8_t address, int16_t data1, int16_t data2, int16_t data3, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendFourInts(uint8_t address, int16_t data1, int16_t data2, int16_t data3, int16_t data4, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendSevenInts(uint8_t address, int16_t data1, int16_t data2, int16_t data3, int16_t data4, int16_t data5, int16_t data6, int16_t data7,
                   uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendIntAndShortLong(uint8_t address, int16_t idata, int32_t sldata, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendIntAndShortLongAndLong(uint8_t address, int16_t idata, int32_t sldata, int32_t ldata, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendIntAndTwoShortLongs(uint8_t address, int16_t idata, int32_t sldata1, int32_t sldata2, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void sendIntAndTwoShortLongsAndTwoLongs(uint8_t address, int16_t idata, int32_t sldata1, int32_t ldata1, int32_t sldata2, int32_t ldata2,
                                        uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);

#endif //PRIZMUTILS_H
