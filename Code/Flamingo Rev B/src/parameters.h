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

// Accelerometer defs
// NEEDS TO BE SET FOR EACH INDIVIDUAL BOARD!
// +/-1gRawReading come from holding acc upright and upsidedown
// acc_real = (accel.readAccelY() - A_OFFSET)/A_GAIN
// acc_real is factor of g, i.e. 1.0 is 9.81 m/sˆ2
#define A_OFFSET -25.5f// 0.5*( +1gRawReading + -1gRawReading)
#define A_GAIN  72.5f// 0.5*( +1gRawReading - -1gRawReading)


// Average acceleration calculation
#define ACC_AVG_NUM 15
#define ACC_AVG_INTERVAL 200

// Buttons
#define BUTTON1 3
#define BUTTON2 4
#define DEBOUNCEDELAY 300

#define NUM_PROGRAMS 2
#define BRIGHTNESS_COUNT 10

// BRIGHTNESS
#define STANDARD_BRIGHTNESS 30

// LED counts
#define NUMPIXELS 144 // Number of LEDs in strip
#define NUMPERSTRAND 48 // Assuming 3 strands for Flamingo

// Harmonic oscillator parameters
#define GFACTOR 0.2f //-0.0654 // 9.81/150
#define SPRINGCONSTANT 2
#define DAMPING 0.4f
#define MAXRANGE 15.0f

// Green Fire parameters
#define GFIRE_COOLING 55
#define GFIRE_SPARKING 120
#define GFIRE_SPEEDDELAY 15

// Sparkle Fizz
#define MAX_G_SPARKLEFIZZ 1.0f // acceleration in m/sˆ2 for max sparkle
#define MAX_INTERVAL_SPARKLEFIZZ 1300 // longest without a sparkle
#define JITTER_SPARKLEFIZZ 200  //random interval in ms to add to inter-sparkle time
#define ACC_MAX_DECAY_RATE 16000.0f // A0 * exp( - t/AVG_DECAY_RATE), in ms, sets decay rate of acceleration max



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

extern bool firstRun;

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

// Sparkle fizz variables
extern uint16_t sparkleInterval;
extern float acc_max; // Maximum acceleration, decay rate set by AVG_DECAY_RATE
extern uint16_t acc_max_timeold;
extern uint16_t acc_max_timenew;
extern uint16_t sparkle_timeold;
extern uint16_t sparkle_timenew;
extern uint16_t sparkleInterval_max;


#endif
