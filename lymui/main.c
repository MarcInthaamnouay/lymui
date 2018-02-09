//
//  main.c
//  lymui
//
//  Created by Marc on 05/02/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#include <stdio.h>
#include "rgb.h"
#include "hex.h"

int main(int argc, const char * argv[]) {
    uint8_t c[] = {0, 155, 205};
    struct Rgb *color = makeRGB(c);
    
    char *hex = getHexFromRGB(color);
    printf("\ngreen is %i", color->g);
    printf("\nhex is %s\n", hex);
    
    getRawRGBArrayValueFromHex(hex);
    
    return 0;
}
