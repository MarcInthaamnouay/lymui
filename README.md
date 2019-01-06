##  Lymui

Lymui is a small color conversion library. It's my first project in C !.

[![Coverage Status](https://coveralls.io/repos/github/MarcInthaamnouay/lymui/badge.svg)](https://coveralls.io/github/MarcInthaamnouay/lymui)
[![Build Status](https://travis-ci.org/MarcInthaamnouay/lymui.svg?branch=master)](https://travis-ci.org/MarcInthaamnouay/lymui)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/c443f9099d024a81b2c56b42edf0b147)](https://www.codacy.com/app/mintha/lymui?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=MarcInthaamnouay/lymui&amp;utm_campaign=Badge_Grade)

## Status

Version: 1.2.0

## Contribute

Contributions are always welcomed. Open issue if you want to add an other kind of format and submit a PR if you wish to add an other feature such as a format color and many more...

## Tests

Testing this project required some steps:

- Clone the cunit library available at this link [Cunit library](https://github.com/itzseven/cunit.git)
- Go into cunit folder and run ```make lib```
- Copy the **content** of the **bin** folder and paste it into the **lib/cunit** folder
- Then run: ```make lym && make test```

*Note*: If you are on OSX you can open xcode and run the test from there

## Install & Compile the project

The project is shipped with a makefile. Below is the command that you can use in order to generate different type of build

- Output lib: ```make lib```

### Note

If you want to test this project with Xcode you will need to add the **binding** folder to the excluded source file names property of xcode

```bash
EXCLUDED_SOURCE_FILE_NAMES = lymui/binding/* 
EXCLUDED_SOURCE_FILE_NAMES = lymui/binding/normalizer/*
```

## Usage

Converting a kind of color required you to import a color of type T. From this type T color you will be able to convert into an other type of color. 

Note that for any color space you have to pass by an Xyz color then to the wanted color. Below is some example of how to use the lib.

**Note**: When converting a color the struct that has been given to a converter will be freed

## APIs

A full list of the APIs and it's example usage is available at this link
[APIs list](https://marcinthaamnouay.github.io/lymui/docs/)

## Changelogs

* 1.2.0:
* * Remove free on rgb & xyz for user's reusability 
* * Add support for TSL color format
* * Add support for converting shorthand hex -> rgb
* * Add support for HWB color format
* * Add support for grayscale color format

* 1.1.1:
* * Refactor Hex -> Rgb
* * Fix random wrong value when converting Hex to Rgb
* * Add more tests cases on Yuv
* * Update travis config

* 1.1.0: 
* * Refactor error handling
* * Change decimal type to double
* * Fix hex random wrong output issue
* * Fix miscalculation for XYZ type colors
* * Reviewed lab, lch, lchuv color calculation
* * Remove useless use malloc (internal)
* * Update tests
* * Other bug fixes

* 1.0.0: Initial release
