//
// Created by User on 26.09.2021.
//

#ifndef PRIZMUTILS_H
#define PRIZMUTILS_H

#include <Arduino.h>
#include <Wire.h>

#define PRIZMUTILS_DEFAULT_I2C_DELAY 10

void send8(uint8_t address, uint8_t  data, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void send2x8(uint8_t address, uint8_t  data1, uint8_t  data2, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void send3x8(uint8_t address, uint8_t  data1, uint8_t  data2, uint8_t  data3, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void send4x8(uint8_t address, uint8_t  data1, uint8_t  data2, uint8_t  data3, uint8_t  data4, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void send7x8(uint8_t address, uint8_t  data1, uint8_t  data2, uint8_t  data3, uint8_t  data4, uint8_t  data5, uint8_t  data6, uint8_t  data7,
             uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void send8and16(uint8_t address, uint8_t  idata, int16_t sldata, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void send8and16and32(uint8_t address, uint8_t  idata, int16_t sldata, int32_t ldata, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void send8and2x16(uint8_t address, uint8_t  idata, int16_t sldata1, int16_t sldata2, uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);
void send8and2x16and32(uint8_t address, uint8_t  idata, int16_t sldata1, int32_t ldata1, int16_t sldata2, int32_t ldata2,
                       uint32_t delay_ms = PRIZMUTILS_DEFAULT_I2C_DELAY);

#endif //PRIZMUTILS_H
