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

#define OK (0)
#define FAIL (-1)

int main(int argc, const char * argv[]) {
    // Create suite case
    ctsuite_t *suite = ctsuite("Lymui test");
    ctcase_t  *rgb   = wrapRgbCreationTest();
    ctcase_t  *hex   = wrapHexCreationTest();
    ctcase_t  *ycbcr = wrapYcbcrCreationTest();
    
    // Launch suite
    ctscaseadd(suite, rgb);
    ctscaseadd(suite, hex);
    ctscaseadd(suite, ycbcr);
    ctsrun(suite);
    
    return 0;
}

