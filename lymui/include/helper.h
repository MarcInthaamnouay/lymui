//
//  helper.h
//  lymui
//
//  Created by Marc on 06/02/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#ifndef helper_h
#define helper_h

#include <stdio.h>

/*!
 * @discussion convert an uint character to hex value
 * @param v a Hex char array
 * @return a char
 */
char * uintToHex(uint8_t v);

/*!
 * @discussion convert a float to a uint
 * @param value float
 * @return a uint8_t value
 */
uint8_t floatToUint(float value);

/**
 * @brief convert a double to an uint8_t
 * @param value doule
 * @return uint8_t
 */
uint8_t doubleToUint(double value);

/**
 * @discussion round a double to 1 digit
 * @param value double
 * @param factor int
 * @return a double
 */
double roundDigit(double value, int factor);

/**
 * @brief round the decimal value
 * @param value double
 * @param decimal int
 */
double roundDecimal(double value, int decimal);

/*
 * @discussion Update Constraint Value
 * @TODO This method need to be redone
 * @param value the float array
 * @return an array of float
 */
double *updateConstraintValue(double *value, uint8_t size);

/**
 * @brief Get the saturation between 2 values
 * @param min double value of the rgb struct
 * @param max double value of the rgb struct
 * @param l   double representing the luminance
 * @return double saturation
 */
double getSaturation(double min, double max, double l);

/**
 * @discussion Get degree from radian value
 * @param r float
 * @return d float
 */
float getDegFromRad(float r);

/**
 * @discussion Get radian from degree value
 * @param d float
 * @return r float
 */
float getRadFromDeg(float d);

/**
 * @brief Clamp the value
 * @param v float
 * @return float
 */
float clampXyz(float v);

/**
 * @brief Get minimum value of RGB
 * @param r double
 * @param g double
 * @param b double
 * @param operation uint
 * @return double
 */
double getMinMax(double r, double g, double b, uint8_t operation);


#endif /* helper_h */
