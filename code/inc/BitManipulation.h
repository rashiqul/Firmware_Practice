/*
 * File:        BitManipulation.h
 * Author:      Mohammad Rashiqul Alam
 */

#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

#ifdef __cplusplus
extern "C" {
#endif

// ==========================
//        INCLUDES
// ==========================
#include <stdio.h>
#include <stdint.h>

// ==========================
//        FUNCTIONS
// ==========================
uint32_t setBit(uint32_t regValue, uint8_t pos);
uint32_t clearBit(uint32_t regValue, uint8_t pos);
uint32_t toggleBit(uint32_t regValue, uint8_t pos);
uint32_t readBit(uint32_t regValue, uint8_t pos);
uint32_t writeBitField(uint32_t regValue, uint8_t pos, uint8_t width, uint8_t fieldValue);

#ifdef __cplusplus
}
#endif


#endif /* BIT_MANIPULATION_H */