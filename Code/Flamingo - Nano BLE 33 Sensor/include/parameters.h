#ifndef PARAMETERS_H
#define PARAMETERS_H


#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>

#include <Arduino_LSM9DS1.h>
#include <SimpleKalmanFilter.h>
#include <Adafruit_DotStar.h>

#include <function_declarations_and_globals.h>


// Configuration

#define SERIAL_OUT_TIMING 0
#define SERIAL_OUT_BUTTONS 0

#define SERIAL_OUT_ACC 1
#define SERIAL_OUT_ACC_PLOT 0


///////////////////////  LEDs  ///////////////////////  

#define NUMPIXELS 144    // Number of LEDs in strip
#define NUMPERSTRAND 48  // Assuming 3 strands for Flamingo
#define NUM_STRANDS 3

#define DATAPIN    11
#define CLOCKPIN   13



///////////////////////  Buttons  ///////////////////////  

#define BUTT_A 2
#define BUTT_B 3
#define BUTT_C 4

#define DEBOUNCE_DELAY 100

#define NUM_PROGRAMS 4

///////////////////////  DHO  ///////////////////////  

#define DHO_G_ACC_MAGNITUDE 9.81f
#define DHO_SPRINGCONSTANT 160.0f
#define DHO_DAMPING 1.7f
#define DHO_MASS 1.0f

#define DHO_STRAND_LENGTH_M 0.3f

// For roughly 120 bpm
//#define DHO_SPRINGCONSTANT 160.0f
//#define DHO_DAMPING 0.7f, maybe 1.7
//#define DHO_MASS 1.0f


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





#endif
