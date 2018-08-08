//
//  yuv.h
//  lymui
//
//  Created by Marc on 12/03/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#ifndef yuv_h
#define yuv_h

#include <stdio.h>
#include "rgb.h"

/**
 * @disuccsion Yuv structure
 */
typedef struct Yuv {
    float y;
    float u;
    float v;
} Yuv;

/**
 * @discussion GetYuvFromRgb return a pointer yuv struct from an RGB pointer
 * @param rgb a pointer struct rgb
 * @return an Yuv pointer struct
 */
Yuv * getYuvFromRgb(Rgb *rgb);

/**
 * @disucssion GetRgbFromYuv return a Rgb pointer struct from a Yuv
 * @param yuv a pointer Yuv struct
 * @return rgb a pointer Rgb struct
 */
Rgb * getRgbFromYuv(Yuv *yuv);

#endif /* yuv_h */
