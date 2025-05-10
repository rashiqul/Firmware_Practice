/*
 * File:        BitManipulation.c
 * Author:      Mohammad Rashiqul Alam
 */

// ==========================
//        INCLUDES
// ==========================
#include "BitManipulation.h"

// ==========================
//        FUNCTIONS
// ==========================
uint32_t setBit(uint32_t regValue, uint8_t pos)
{
    regValue |= (1 << pos);
    return regValue;
}

uint32_t clearBit(uint32_t regValue, uint8_t pos)
{
    regValue &= ~(1 << pos);
    return regValue;
}

uint32_t toggleBit(uint32_t regValue, uint8_t pos)
{
    regValue ^= (1 << pos);
    return regValue;
}

uint32_t readBit(uint32_t regValue, uint8_t pos)
{
    return ((regValue >> pos) & 1);
}

