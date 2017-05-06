#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <Arduino.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <ADXL345.h>
#include <MPU6050.h>
#include <math.h>
#include <avr/pgmspace.h>

#include <accel.h>
#include <buttons.h>
#include <harmonic_oscillator.h>
#include <parameters.h>
#include <effects.h>


// Buttons
#define BUTTON1 3
#define BUTTON2 4
#define DEBOUNCEDELAY 300

#define NUM_PROGRAMS 6
#define BRIGHTNESS_COUNT 10

// LED counts
#define NUMPIXELS 144 // Number of LEDs in strip
#define NUMPERSTRAND 48 // Assuming 3 strands for Flamingo

// Harmonic oscillator parameters
#define GFACTOR 0.2 //-0.0654 // 9.81/150
#define SPRINGCONSTANT 2
#define DAMPING 0.4
#define MAXRANGE 15.0

// ADXL345/GY-291 variables
extern ADXL345 accel;

extern int16_t ay;
extern float g0y, gy;

// Button variables
extern uint8_t button1state;
extern uint8_t button2state;
extern uint8_t button1prevstate;
extern uint8_t button2prevstate;

extern unsigned long timeNowButton1;
extern unsigned long timeNowButton2;
extern unsigned long lastTimePressedButton1;
extern unsigned long lastTimePressedButton2;

extern uint8_t brightnessIndex;
extern uint8_t brightness[BRIGHTNESS_COUNT];

extern uint8_t programIndex; // start at 1

// Dotstar/APA102C variables
extern Adafruit_DotStar strip;
extern uint32_t color;

// Harmonic oscillator variables
extern float pos0, pos1, vel0, vel1, acc0, acc1, acc_ext;
extern float timenow_f, timestep_f, timestep_i;
extern uint16_t timeold_i, timenow_i;
extern bool first_iter;

#endif
