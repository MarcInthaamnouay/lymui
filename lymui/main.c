//
//  main.c
//  lymui
//
//  Created by Marc on 05/02/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cunit.h>
#include "rgb.h"
#include "hex.h"
#include "ycbcr.h"
#include "test_header.h"

int main(int argc, const char * argv[]) {
    // Create suite case
    ctsuite_t *suite = ctsuite("Lymui test");
    ctcase_t  *xyy   = wrapXyyCreationTest();
    ctcase_t  *hwb   = wrapHwbCreationTest();
    ctcase_t  *tsl   = wrapTslCreationTest();
    
    // Launch suite
    ctscaseadd(suite, xyy);
    ctscaseadd(suite, hwb);
    ctscaseadd(suite, tsl);
    ctsrun(suite);
    
    uint8_t failNb = suite->failed;
    
    wrapRgbTest();
    wrapHexTest();
    wrapHueTest();
    wrapCymkTest();
    wrapYcbcrTest();
    wrapHslTest();
    wrapHsvTest();
    wrapYuvTest();
    wrapGrayScaleTest();
    wrapHclTest();
    
    wrapXyzTest();
    wrapArgbTest();
    wrapSrgbTest();
    wrapLabTest();
    wrapHLabTest();
    wrapLuvTest();
    wrapLchTest();
    wrapLchLabTest();
    
    // free the suite
    ctsfree(suite);
    
    if (failNb > 0)
        return -1;
    
    return 0;
}

