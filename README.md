##  Lymui

Lymui is a small color conversion library. It's my first project in C !.

## Tests

This project used cunit @itzseven library as it's unit test lib.

[![Coverage Status](https://coveralls.io/repos/github/MarcInthaamnouay/lymui/badge.svg)](https://coveralls.io/github/MarcInthaamnouay/lymui)

[![Build Status](https://travis-ci.org/MarcInthaamnouay/lymui.svg?branch=master)](https://travis-ci.org/MarcInthaamnouay/lymui)

## Status

Version: 1.1.0a

## Contribute

Contributions are always welcomed. Open issue if you want to add an other kind of format and submit a PR if you wish to add an other feature such as a format color and many more...

## Install & Compile the project

The project is shipped with a makefile. Below is the command that you can use in order to generate different type of build

- Output lib: ```make lib```
- Test app: ```make lym && make test```

### Note

If you want to test this project with Xcode you will need to add the **binding** folder to the excluded source file names property of xcode

```bash
EXCLUDED_SOURCE_FILE_NAMES = lymui/binding/* 
EXCLUDED_SOURCE_FILE_NAMES = lymui/binding/normalizer/*
```

## Usage

Converting a kind of color required you to import a color of type T. From this type T color you will be able to convert into an other type of color. 

Note that for any color space you have to pass by an Xyz color then to the wanted color. Below is some example of how to use the lib.

Note that each time you convert a base color T to an other format Y, the **base color T will be free** (this might need improvement...)

## NodeJS

A NodeJS compatibility is currently being in WIP by using N-API. You can check the code on the binding folder lymui/binding.

## Example in C

#### Converting an Rgb to an Hex

```c
#include <stdlib.h>
#include "rgb.h"
#include "hex.h"

uint8_t c[] = {5, 10, 95};
struct Rgb *rgb = makeRgb(c);

// Convert a rgb struct to an Hex
char * hex = getHexFromRGB(rgb);

printf("Value of the hex %s", hex);
```

#### Converting an Rgb to an Hsl

```c
#include <stdlib.h>
#include "rgb.h"
#include "hsl.h"

struct Rgb *rgb = initRGB();
// rgb return NULL if malloc fail
rgb->r = 100;
rgb->g = 150;
rgb->b = 200;

// Convert a rgb struct to an Hex
Hsl *hsl = getHslFromRGB(rgb);

// Every Struct either return NULL if malloc fail.
// If it fail internally it return an error char

if (hsl->error != NULL) {
  printf("AYOO !! an error %s", hsl->error);
}

// do anything you want with the struct pointer then :)
double hue = hsl->h;
```


## Example in NodeJS

#### Converting an Rgb to an Hex

4 APIs are available for converting colors

- convertRegular
- convertSpace
- toRGB
- toXYZ

Example for HEX value

```js
const lib = require('lymuilib')

const rgb = {
  r: 5,
  g: 10,
  b: 98
}

const { data, error } = await lib.convertRegular({
  input: rgb,
  output: 'hex'
})
```

Example for LAB value from RGB

```js
const lib = require('lymuilib')

const rgb = {
  r: 50,
  g: 10,
  b: 95
}

const { data, error } = await lib.convertRegular({
  input: rgb,
  output: 'xyz',
  profile: 'srgb' // optional
})

const xyz = await lib.convertSpace({
  input: data,
  output: 'lab',
  clamp: 1000 // optional
})
```

an object should be output like this

```js
{
  data: {
    l: 13.951,
    a: 37.071,
    b: -41.431
  }
}
```