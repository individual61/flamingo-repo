#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <ADXL345.h>
#include <Arduino.h>
#include <FastLED.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <SPI.h>

#include <Wire.h>
#include <avr/pgmspace.h>
#include <math.h>

#include <accel.h>
#include <bouncing_balls.h>
#include <buttons.h>
#include <harmonic_oscillator.h>
#include <parameters.h>
#include <programs-common.h>
#include <utils.h>

#define DEBUG 1

//////////// BOARD TYPE 1 ////////////////////////
// 1 = Bike Flamingo 2022 Rev 1
// ItsyBitsy 5V, 3 buttons
#define BOARD_TYPE 1
#define NUM_STRANDS 1
#define NUM_PROGRAMS 3
#define BRIGHTNESS_MAX_QUANTITY 10 // max number of brightness levels across all programs
// All brightness arrays have 10 elements. When the value is 0, it cycles back. Therefore all must end with 0
#define ALL_BRIGHTNESS_ARRAY                                                                                                        \
  {                                                                                                                                 \
    {10, 15, 20, 40, 60, 100, 140, 180, 240, 0}, {10, 140, 240, 0, 0, 0, 0, 0, 0, 0}, { 10, 15, 20, 40, 60, 100, 140, 180, 240, 0 } \
  }
// NO "RUN_ON_TOTEM" defined here
extern uint8_t brightnessIndex[NUM_PROGRAMS];

// Buttons
//#define BUTTON1 3
//#define BUTTON2 4
#define BUTT_A 9
#define BUTT_B 10
#define BUTT_C 11

#define DEBOUNCE_DELAY 100

// FastLED stuff
//#define NUMPIXELS 144    // Number of LEDs in strip
#define NUMPIXELS 29    // Number of LEDs in strip
#define NUMPERSTRAND 29 // Assuming 1 strands for bike Flamingo
//#define NUMPERSTRAND 48 // Assuming 3 strands for Flamingo
//#define CLOCK_PIN 13
//#define DATA_PIN 11
#define CLOCK_PIN 3
#define DATA_PIN 2

#define COLOR_ORDER BGR // my strip is BGR
#define CORRECTION TypicalLEDStrip
//#define CORRECTION UncorrectedColor

// Harmonic oscillator parameters
//#define SPRINGCONSTANT 2
//#define DAMPING 0.4f
//#define MAXRANGE 15.0f
//#define MAXRANGE_REAL 1.0f
//#define SPRINGCONSTANT_REAL 1.0f  // 1.0
//#define DAMPING_REAL 0.3f         // 0.3
//#define MASS_REAL 4.0f            // 4.0

// Green Fire parameters
#define GFIRE_COOLING 55
#define GFIRE_SPARKING 120
#define GFIRE_SPEEDDELAY 15

// Fire W PALLETTE parameters
#define FIRE_PALLETTE_COOLING 70
#define FIRE_PALLETTE_SPARKING 120

// Sparkle Fizz
#define MAX_G_SPARKLEFIZZ 1.0f        // acceleration in m/sˆ2 for max sparkle
#define MAX_INTERVAL_SPARKLEFIZZ 1300 // longest without a sparkle
#define JITTER_SPARKLEFIZZ \
  200 // random interval in ms to add to inter-sparkle time
#define ACC_MAX_DECAY_RATE \
  20000.0f // A0 * exp( - t/AVG_DECAY_RATE), in ms, sets decay rate of
           // acceleration max

// DHO_Comet
//#define NUM_HISTORY 100

// DHO_Fade
//#define FADE_COEF 240

// Bouncy Balls
//#define NUM_BOUNCYBALLS 1
//#define BB_DAMPING 0.2f
//#define G_ACC_MAGNITUDE_BB 1412.64  // 9.81

// General variables
extern uint8_t counter;
extern uint32_t timer;
extern uint8_t counter_every_10_8;
extern uint32_t last_interrupt_time;

// ADXL345/GY-291 variables
extern ADXL345 accel;

extern int16_t ay;
extern float g0y, gy, acc_offset_normalized;

// Button variables
extern uint8_t button1state;
extern uint8_t button2state;
extern uint8_t button1prevstate;
extern uint8_t button2prevstate;

extern unsigned long timeNowButton1;
extern unsigned long timeNowButton2;
extern unsigned long lastTimePressedButton1;
extern unsigned long lastTimePressedButton2;

extern volatile bool firstRun;

extern volatile uint8_t programIndex; // start at 0

// FastLED/Dotstar/APA102C variables
// extern uint32_t color;
extern CRGB color;
extern CRGB leds[NUMPIXELS];

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

// Fire with Pallette variables
// Fire W PALLETTE parameters
#define FIRE_PALLETTE_COOLING 70
#define FIRE_PALLETTE_SPARKING 120

// Rainbow variables
extern byte *c;
extern uint16_t jrainbow;

////////////////////////////////////////////////////////////

/*

//////////// BOARD TYPE 2 ////////////////////////
// 2= Flamingo Totem Original ADXL345
#define BOARD_TYPE 2
#define NUM_PROGRAMS 14
#define RUN_ON_TOTEM  // accelerometer has different offsets on the Totem

// Accelerometer defs
// NEEDS TO BE SET FOR EACH INDIVIDUAL BOARD!
// +/-1gRawReading come from holding acc upright and upsidedown
// acc_real = (accel.readAccelY() - A_OFFSET)/A_GAIN
// acc_real is factor of g, i.e. 1.0 is 9.81 m/sˆ2

// For Totem:
#ifdef RUN_ON_TOTEM
#define A_OFFSET 9.0f  // 0.5*( +1gRawReading + -1gRawReading)
#define A_GAIN -77.0f  // 0.5*( +1gRawReading - -1gRawReading)
#else
// for testbed
#define A_OFFSET -25.5f  // 0.5*( +1gRawReading + -1gRawReading)
#define A_GAIN 72.5f     // 0.5*( +1gRawReading - -1gRawReading)
#endif

#define G_ACC_MAGNITUDE 9.81f

// Average acceleration calculation
#define ACC_AVG_NUM 15
#define ACC_AVG_INTERVAL 200

// Buttons
#define BUTTON1 3
#define BUTTON2 4
#define DEBOUNCEDELAY 300

#define BRIGHTNESS_COUNT 10  // Number of brightness levels

// Buttons
#define BUTTON1 3
#define BUTTON2 4
#define DEBOUNCEDELAY 300

#define BRIGHTNESS_COUNT 10  // Number of brightness levels


// FastLED stuff
#define NUMPIXELS 144    // Number of LEDs in strip
#define NUMPERSTRAND 48  // Assuming 3 strands for Flamingo
#define CLOCK_PIN 13
#define DATA_PIN 11
#define COLOR_ORDER BGR  // my strip is BGR
#define CORRECTION TypicalLEDStrip
//#define CORRECTION UncorrectedColor

// Harmonic oscillator parameters
#define SPRINGCONSTANT 2
#define DAMPING 0.4f
#define MAXRANGE 15.0f
#define MAXRANGE_REAL 1.0f
#define SPRINGCONSTANT_REAL 1.0f  // 1.0
#define DAMPING_REAL 0.3f         // 0.3
#define MASS_REAL 4.0f            // 4.0


// Green Fire parameters
#define GFIRE_COOLING 55
#define GFIRE_SPARKING 120
#define GFIRE_SPEEDDELAY 15

// Fire W PALLETTE parameters
#define FIRE_PALLETTE_COOLING 70
#define FIRE_PALLETTE_SPARKING 120

// Sparkle Fizz
#define MAX_G_SPARKLEFIZZ 1.0f         // acceleration in m/sˆ2 for max sparkle
#define MAX_INTERVAL_SPARKLEFIZZ 1300  // longest without a sparkle
#define JITTER_SPARKLEFIZZ \
  200  // random interval in ms to add to inter-sparkle time
#define ACC_MAX_DECAY_RATE \
  20000.0f  // A0 * exp( - t/AVG_DECAY_RATE), in ms, sets decay rate of
            // acceleration max

// DHO_Comet
#define NUM_HISTORY 100

// DHO_Fade
#define FADE_COEF 240

// Bouncy Balls
#define NUM_BOUNCYBALLS 1
#define BB_DAMPING 0.2f
#define G_ACC_MAGNITUDE_BB 1412.64  // 9.81

// General variables
extern uint8_t counter;
extern uint32_t timer;
extern uint8_t counter_every_10_8;

// ADXL345/GY-291 variables
extern ADXL345 accel;

extern int16_t ay;
extern float g0y, gy, acc_offset_normalized;

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

extern uint8_t programIndex;  // start at 1

// FastLED/Dotstar/APA102C variables
// extern uint32_t color;
extern CRGB color;
extern CRGB leds[NUMPIXELS];

// Harmonic oscillator variables
extern float pos0, pos1, vel0, vel1, acc0, acc1, acc_ext;
extern float timenow_f, timestep_f, timestep_i;
extern uint16_t timeold_i, timenow_i;
extern bool first_iter;

// Sparkle fizz variables
extern uint16_t sparkleInterval;
extern float acc_max;  // Maximum acceleration, decay rate set by AVG_DECAY_RATE
extern uint16_t acc_max_timeold;
extern uint16_t acc_max_timenew;
extern uint16_t sparkle_timeold;
extern uint16_t sparkle_timenew;
extern uint16_t sparkleInterval_max;

// Fire with Pallette variables

// Rainbow variables
extern byte *c;
extern uint16_t jrainbow;
////////////////////////////////////////////////////////////




*/

#endif
