//
//  cymk.h
//  lymui
//
//  Created by Marc on 15/02/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#ifndef cymk_h
#define cymk_h

#include <stdio.h>
#include "rgb.h"

/*!
 * @brief Cymk structure Object
 */
typedef struct Cymk {
    // C value
    float c;
    // Y value
    float y;
    // M value
    float m;
    // K value
    float k;
} Cymk;

/*!
 * @discussion Create a Cymk struct pointer from an Rgb struct
 * @param rgb a RGB structure
 * @return a uint8_t array
 */
Cymk *getCymkFromRgb(Rgb *rgb);

/*!
 * @discussion Creates a uint8_t array from a Cymk struct pointer
 * @param cymk a Cymk structure
 * @return a uint8_t array
 * @TODO return RGB struct instead
 */
Rgb * getRawRGBValueFromCymk(Cymk *cymk);

#endif /* cymk_h */
