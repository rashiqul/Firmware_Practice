/*
 * File:        BitManipulation.h
 * Author:      Mohammad Rashiqul Alam
 */

#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H

// ==========================
//        INCLUDES
// ==========================
#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// ==========================
//        FUNCTIONS
// ==========================
uint32_t setBit(uint32_t regValue, uint8_t pos);
uint32_t clearBit(uint32_t regValue, uint8_t pos);
uint32_t toggleBit(uint32_t regValue, uint8_t pos);
uint32_t readBit(uint32_t regValue, uint8_t pos);

#ifdef __cplusplus
}
#endif


#endif /* BIT_MANIPULATION_H */