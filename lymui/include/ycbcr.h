//
//  ycbcr.h
//  lymui
//
//  Created by Marc on 12/02/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#ifndef ycbcr_h
#define ycbcr_h

#include <stdio.h>
#include <stdint.h>
#include "rgb.h"

#define YConst 1.164

// Struct Ycbcr
typedef struct Ycbcr {
    uint8_t y;
    uint8_t cb;
    uint8_t cr;
    char *error;
} Ycbcr;

// Struct YcbcrBridge use for calculating indermediary value
typedef struct YcbcrBridge {
    double l;
    double y;
    double m;
} YBridge;

// Enum use to define what to calculate
typedef enum YcbcrKind {
    y,
    cb,
    cr,
} YcbcrKind;

/**
 * @brief Create a Ycbcr struct pointer from an Rgb struct
 * @param rgb a RGB structure
 * @return a Ycbcr struct pointer
 */
Ycbcr *getYcbcrFromRgb(Rgb *rgb);

/**
 * @brief Create a uint_8t array which describe the colors
 * @param yc Ycbcr struct
 * @return a uint8_t array
 */
Rgb *getRgbFromYcbcr(Ycbcr *yc);

#endif /* ycbcr_h */
