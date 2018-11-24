//
//  srgb_test.c
//  lymui
//
//  Created by Marc on 13/03/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <cunit.h>
#include "errors.h"
#include "rgb.h"
#include "xyz.h"
#include "srgb.h"
#include "helper.h"

ctest_return_t testSRgbCreation(ctest_t *test, void *arg) {
    Rgb *rgb = malloc(sizeof(Rgb));
    rgb->r = 50;
    rgb->g = 10;
    rgb->b = 95;
    
    Xyz *xyz = generateXyzFromRgb(rgb, srgb);
    SRgb *srgb = getSRgbFromXyz(xyz);
    
    CTAssertDecimalEqual(test, 0.19, srgb->r, 0.01, "Expect r to be equal to be equal to 0.19 but got %f", srgb->r);
    CTAssertDecimalEqual(test, 0.03, srgb->g, 0.01, "Expect g to be equal to be equal to 0.03 but got %f", srgb->g);
    CTAssertDecimalEqual(test, 0.37, srgb->b, 0.01, "Expect b to be equal to be equal to 0.37 but got %f", srgb->b);

    free(srgb);
}

ctest_return_t testNullSRgbCreation(ctest_t *test, void *arg) {
    SRgb *srgb = getSRgbFromXyz(NULL);
    CTAssertEqual(test, srgb->error, NULL_INPUT_STRUCT, "Expect Error to be equal to %s", NULL_INPUT_STRUCT);

    free(srgb);
}

ctcase_t *wrapSRgbCreationTest() {
    ctcase_t *sRgbCase = ctcase("sRGB test case");
    
    //test regarding the creation of srgb
    ctest_t *srgb  = ctest("Creation of an sRGB from Rgb struct", testSRgbCreation, NULL);
    ctest_t *nSrgb = ctest("Creating of an NULL sRGB from an empty Rgb struct", testNullSRgbCreation, NULL);
    
    ctctestadd(sRgbCase, srgb);
    ctctestadd(sRgbCase, nSrgb);
    
    return sRgbCase;
}
