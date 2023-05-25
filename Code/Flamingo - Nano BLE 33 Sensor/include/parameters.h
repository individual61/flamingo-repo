#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>

#include <SimpleKalmanFilter.h>
#include <Adafruit_DotStar.h>

#include <function_declarations_and_globals.h>

///////////////////////  Board type  ///////////////////////

// #define ARDUINO_NANO_33_BLE
#define ARDUINO_NANO_33_BLE_SENSE_REV2

#ifdef ARDUINO_NANO_33_BLE
#include <Arduino_LSM9DS1.h> // For Arduino Nano BLE 33
#endif

#ifdef ARDUINO_NANO_33_BLE_SENSE_REV2
#include <Arduino_BMI270_BMM150.h> // for Arduino Nano BLE 33 Sense Rev 2
#endif

// Configuration

#define SERIAL_OUT_TIMING 0
#define SERIAL_OUT_BUTTONS 1

#define SERIAL_OUT_ACC 1
#define SERIAL_OUT_ACC_PLOT 0

///////////////////////  LEDs  ///////////////////////

#define NUM_STRANDS 3 // 1 or 3

// Flamingo
#if NUM_STRANDS == 3
#define NUMPIXELS 144   // Number of LEDs in strip
#define NUMPERSTRAND 48 // Assuming 3 strands for Flamingo
#endif

// Test strip
#if NUM_STRANDS == 1
#define NUMPIXELS 72    // Number of LEDs in strip
#define NUMPERSTRAND 72 // This must match NUMPIXELS
#endif

#define START_BRIGHTNESS 10

// SIngle-pixel programs can have a max val of 255.
// Setting brightness scale to max of 600 mA.

// DHO 255
// BB 255
// G Flash 30 is 600 mA, 50 is 800 mA
// Syncrandnum 150
// Fire 80
// Sparkle 255

#define DHO_MAX_BRIGHTNESS 255
#define BB_MAX_BRIGHTNESS 255
#define GFLASH_MAX_BRIGHTNESS 50
#define SYNCRANDNUM_MAX_BRIGHTNESS 40
#define FIRE_MAX_BRIGHTNESS 80
#define SPARKLE_MAX_BRIGHTNESS 255

// DHO @ 255 - 230 mA
// Syncrandnum 70 is 600 mA

// On Flamingo, full strip even color
//  strip.ColorHSV(55000, 255, 255) with global brightness set to 
//  30 -- 600 mA
//  50 -- 800 mA
//  60 -- 860 mA
//  70 -- 930 mA
//  80 -- 980 mA
//  /
// 0xFFFFFF
//  30 -- 730 mA
//  50 -- 940 mA
//
// Sync Rand num setting 0
// 20 - 180
// 30 - 210
// 50 - 250
// 60 - 280
// 70 - 310
// 80 - 330
//
// Green fire
// 
// 20 - 220
// 30 - 310
// 50 - 350
// 60 - 510
// 
// Pink fire
// 20 - 220
// 30 - 250
// 50 - 400
// 60 - 450
// 
// Rainbow fire 1
// 60 - 400
//
// Rainbow fire 2
// 60 - 360
// 
// Rainbow Fire 3
// 60 - 370
//
// Sparkle white qty 3
// 20 - 170
// 30 - 190
// 50 - 220
// 60 - 240
// 70 - 250

#define GLOBAL_BRIGHTNESS_LEVELS \
    {                            \
        40, 100, 150, 210, 255           \
    }
#define GLOBAL_BRIGHTNESS_LEVELS_NUMBER 5

#define DATAPIN 11
#define CLOCKPIN 13

///////////////////////  Buttons  ///////////////////////

#define BUTT_A 2
#define BUTT_B 3
#define BUTT_C 4

#define DEBOUNCE_DELAY 100

#define NUM_PROGRAMS 6
#define NUMSETTINGS 6

///////////////////////  DHO  ///////////////////////

// #define DHO_COLOR 0x601040
#define PINK_HUE 55000
#define DHO_G_ACC_MAGNITUDE 9.81f
#define DHO_SPRINGCONSTANT 160.0f
#define DHO_DAMPING 1.7f
#define DHO_MASS 1.0f

#define DHO_STRAND_LENGTH_M 0.3f

// For roughly 120 bpm
// #define DHO_SPRINGCONSTANT 160.0f
// #define DHO_DAMPING 0.7f, maybe 1.7
// #define DHO_MASS 1.0f

///////////////////////  BB  ///////////////////////

//#define BB_COLOR 0x601040

#define BB_G_ACC_MAGNITUDE 9.81f
#define BB_MASS 1.0f
#define BB_BOUNCE_COEF 0.8f
#define BB_DAMPING 0.2f

#define BB_STRAND_LENGTH_M 0.3f

///////////////////////  SPARKLE  ///////////////////////

//#define SPARKLE_COLOR 0xffffff

#define SPARKLE_QUANTITY 3
#define SPARKLE_DURATION_MS 1

///////////////////////  FIRE  ///////////////////////

#define FIRE_RAINBOW_FIRST_HUE 0
#define FIRE_RAINBOW_HUE_REPS 1
#define FIRE_RAINBOW_SATURATION 255
#define FIRE_RAINBOW_BRIGHTNESS 20

// Green Fire parameters
#define FIRE_COOLING 55
#define FIRE_SPARKING 120
#define FIRE_SPEEDDELAY 5

#define FIRE_STYLE 4

///////////////////// SYNC RAND NUM /////////////////////

// If sparkliness > 0.01, it sparkles way too fast and flickers

// 3 SETTLED
// 4 sweep with glitter
#define SYNCRANDNUM_SPARKLINESS_SETT_0 0.01
#define SYNCRANDNUM_RAMP_PERIOD_SETT_0 4000
#define SYNCRANDNUM_SCALE_SETT_0 1.0

// 4 SETTLED
// Nice slightly flowing slightly fading pattern
#define SYNCRANDNUM_SPARKLINESS_SETT_1 0.001
#define SYNCRANDNUM_RAMP_PERIOD_SETT_1 4000
#define SYNCRANDNUM_SCALE_SETT_1 1.0

#define SYNCRANDNUM_SPARKLINESS_SETT_2 0.01
#define SYNCRANDNUM_RAMP_PERIOD_SETT_2 8000
#define SYNCRANDNUM_SCALE_SETT_2 1.0

// 5 sparkles dont move??
// Clear flowing of pattern, with some sparkles
#define SYNCRANDNUM_SPARKLINESS_SETT_3 0.001
#define SYNCRANDNUM_RAMP_PERIOD_SETT_3 8000
#define SYNCRANDNUM_SCALE_SETT_3 1.0

// Unused
// 0 boring no noise
// #define SYNCRANDNUM_SPARKLINESS_SETT_0 0.001
// #define SYNCRANDNUM_RAMP_PERIOD_SETT_0 4000
// #define SYNCRANDNUM_SCALE_SETT_0 0.5

// 1 eh
// Slow fading in of pixels with overall color theme
// #define SYNCRANDNUM_SPARKLINESS_SETT_1 0.01
// #define SYNCRANDNUM_RAMP_PERIOD_SETT_1 4000
// #define SYNCRANDNUM_SCALE_SETT_1 0.5

// 2 too fast
// 1 s sweep with glitter, maybe a bit too many colors close together
// #define SYNCRANDNUM_SPARKLINESS_SETT_2 0.01
// #define SYNCRANDNUM_RAMP_PERIOD_SETT_2 1000
// #define SYNCRANDNUM_SCALE_SETT_2 1.0

///////////////////////  IMU  ///////////////////////

// Using Arduino LSM9DS1 library: [-4, +4] g -/+0.122 mg

// For temperature measurements, the units of the standard
// deviation would be degrees Celsius or Fahrenheit.
#define ACC_KALMAN_MEASUREMENT_UNCERTAINTY 0.0148f

//  For example, if you're estimating the position and velocity
// of an object in meters and meters per second, respectively,
// the units of the covariance matrix would be meters squared
// and meters squared per second squared.
#define ACC_KALMAN_ESTIMATION_UNCERTAINTY 0.2f

// For example, if you're estimating the position and velocity
// of an object in meters and meters per second, respectively,
// and the time units used in the Kalman filter equations are seconds,
//  the units of the process noise covariance matrix would be meters
// squared per second squared and meters squared per second to the fourth power
#define ACC_KALMAN_PROCESS_NOISE_UNCERTAINTY 0.1f

///////////////////////  GFLASH  ///////////////////////

#define GFLASH_COLOR 0x300030

// Scale 0.5, thresh 2.0 reaches 1.0 at 3.4 G
#define GFLASH_MAX 2.5
#define GFLASH_START 1.8

/*
///////////////////////  COMPASS  ///////////////////////

#define COMPASS_COLOR 0x300030
*/

#endif
