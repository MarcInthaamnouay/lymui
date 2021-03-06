//
//  hsl.c
//  lymui
//
//  Created by Marc on 21/02/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#include <stdlib.h>
#include <math.h>
#include "errors.h"
#include "helper.h"
#include "hue.h"
#include "rgb.h"
#include "hue.h"
#include "hsl.h"

Hsl *getHslFromRgb(Rgb *rgb) {
    Hsl *hsl = malloc(sizeof(Hsl));
    if (hsl == NULL) {
        return NULL;
    }
    
    if (rgb == NULL) {
        hsl->error = NULL_INPUT_PARAM;
        return hsl;
    }
    
    Hue hue = getHueFromRgb(rgb);
    double _r = (double) rgb->r;
    double _g = (double) rgb->g;
    double _b = (double) rgb->b;
    
    double min = getMinMax(_r, _g, _b, 1) / 255;
    double max = getMinMax(_r, _g, _b, 0) / 255;
    
    double _l = (min + max) / 2;
    double sat = getSaturation(min, max, _l);
    
    hsl->h = hue;
    hsl->s = sat * 100.0;
    hsl->l = _l * 100.0;
    hsl->error = NULL;
    
    return hsl;
}

/**
 * @brief Get the shade of grey from an HSL
 * @param hsl representing the Luminance
 * @param rgb Rgb
 * @return Rgb an rgb describing the shade of grey
 */
static Rgb *getShadeOfGray(Hsl *hsl, Rgb *rgb) {
    uint8_t v = hsl->l / 100 * 255;
    rgb->r = v;
    rgb->g = v;
    rgb->b = v;
    rgb->error = NULL;
    
    free(hsl);
    return rgb;
}

/**
 * @brief Update Constraint
 * @param v double
 * @return double
 */
static double updateConstraint(double v) {
    if (v < 0.0)
        v = v + 1.0f;
    else if (v > 1.0)
        v = v - 1.0f;
    
    return v;
}

/**
 * @brief Get an array of temp _rgb value
 * @param hue a double describing the hue
 * @return RgbInter
 */
static RgbInter getTempRgbValue(Hue hue) {
    RgbInter inter;
    double _hue  = hue / 360.0;
    // red
    inter.ri = updateConstraint(hue + 0.333);
    // green
    inter.gi = updateConstraint(_hue);
    // blue
    inter.bi = updateConstraint(_hue - 0.333);
    
    return inter;
}

/**
 * @discussion Calculate the based on each _temp c pass
 * @param c a double temp color
 * @param temp_m a temporary luminance based on the value of the luminace
 * @param temp_l a temporary luminance based on the temp_m and the current luminance
 */
static uint8_t calculateEachColorValue(double c, double temp_m, double temp_l) {
    double fv = 0.0;
    
    if (6.0 * c < 1.0) {
        fv = temp_l + (temp_m - temp_l) * 6.0 * c;
    } else if (2.0 * c < 1.0) {
        fv = temp_m;
    } else if (3.0 * c < 2.0) {
        fv = temp_l + (temp_m - temp_l) * (0.666 - c) * 6.0;
    } else {
        fv = temp_l;
    }
    
    return doubleToUint(round(fv * 255.0));
}

Rgb *getRgbFromHsl(Hsl *hsl) {
    Rgb *rgb = initRgb();
    if (rgb == NULL) {
        return NULL;
    }
    
    if (hsl == NULL) {
        rgb->error = NULL_INPUT_PARAM;
        return rgb;
    }
    
    if (!hsl->h && !hsl->s) {
        // return a gray shade rgb
        return getShadeOfGray(hsl, rgb);
    }
    
    double _l = hsl->l / 100.0;
    double _s = hsl->s / 100.0;
    
    // choose the luminace formula
    double temp_lum = 0.0;
    if (round(_l)) {
        temp_lum = (_l + _s) - (_l * _s);
    } else {
        temp_lum = _l * (1.0 + _s);
    }
    
    // get other temp value
    double temp_lum_s = 2.0f * _l - temp_lum;
    RgbInter inter = getTempRgbValue(hsl->h);
    
    rgb->r = calculateEachColorValue(inter.ri, temp_lum, temp_lum_s);
    rgb->g = calculateEachColorValue(inter.gi, temp_lum, temp_lum_s);
    rgb->b = calculateEachColorValue(inter.bi, temp_lum, temp_lum_s);
    rgb->error = NULL;
    
    free(hsl);
    
    return rgb;
}
