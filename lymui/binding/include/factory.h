//
//  factory.h
//  lymui
//
//  Created by Marc Intha on 01/11/2018.
//  Copyright © 2018 Marc. All rights reserved.
//

#ifndef factory_h
#define factory_h

#include <stdio.h>
#include <node_api.h>
#include "rgb.h"
#include "cymk.h"
#include "ycbcr.h"
#include "hsl.h"

/**
 * @brief Factory creating Rgb Object on the fly
 * @param env napi_env
 * @param rgb Rgb struct pointer
 */
napi_value RgbJSObjFactory(napi_env env, Rgb * rgb);

/**
 * @brief Factory creating Cymk JS Object
 * @param env napi_env
 * @param cymk Cymk struct pointer
 * @param clamp int
 * @return napi_value
 */
napi_value CymkJSObjFactory(napi_env env, Cymk * cymk, int clamp);

/**
 * @brief Factory creating Ycbcr Object
 * @param env napi_env
 * @param ycb Ycbcr struct pointer
 * @return napi_value
 */
napi_value YcbcrJSObjFactory(napi_env env, Ycbcr *ycb);

/**
 * @brief Factory creating Hsl Object
 * @param env napi_env
 * @param hsl Hsl struct pointer
 * @param clamp int
 * @return napi_value
 */
napi_value HslJSObjFactory(napi_env env, Hsl * hsl, int clamp);

#endif /* factory_h */