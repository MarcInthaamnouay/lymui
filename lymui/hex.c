//
//  hex.c
//  lymui
//
//  Created by Marc on 06/02/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "hex.h"
#include "helper.h"

// Get Hex From RGB
char * getHexFromRGB(struct Rgb *c) {
    char *r = ushortToHex(c->r);
    char *g = ushortToHex(c->g);
    char *b = ushortToHex(c->b);
    
    // create a char array of hex value
    char *hex = malloc(sizeof(char) * 5);
    snprintf(hex, sizeof(hex), "%s%s%s", r, g, b);
    return hex;
}

// Get RGB Value From Hex
uint8_t * getRawRGBArrayValueFromHex(char *hex) {
    if (hex == NULL)
        return NULL;
    
    const char * copy = hex;
    // Make a copy of the pointer
    uint8_t *rgbArr = malloc(sizeof (char) * 3);
    uint8_t idx = 0;
    // As we use the ushort we set 16 as our flag
    
    while (idx < strlen(copy)) {
        int x = getUintCharValue(copy[idx]);
        int y = getUintCharValue(copy[idx + 1]);
        
        rgbArr[(idx / 2)] = y + (x * 16);
        
        idx = idx + 2;
    }
    
    // Don't forget to free it after it's usage
    return rgbArr;
}

// Get Uint Char Value
// Though it could have been better than using a switch...
uint8_t getUintCharValue(char c) {
    uint8_t n = 0;
    switch (c) {
        case '1': n = 1; break;
        case '2': n = 2; break;
        case '3': n = 3; break;
        case '4': n = 4; break;
        case '5': n = 5; break;
        case '6': n = 6; break;
        case '7': n = 7; break;
        case '8': n = 8; break;
        case '9': n = 9; break;
        case 'A': n = 10; break;
        case 'B': n = 11; break;
        case 'C': n = 12; break;
        case 'D': n = 13; break;
        case 'E': n = 14; break;
        case 'F': n = 15; break;
    }
    
    return n;
}
