#ifndef PARAMETERS_H
#define PARAMETERS_H


#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>

#include <Arduino_LSM9DS1.h>
#include <SimpleKalmanFilter.h>

#include <function_declarations_and_globals.h>


// Configuration

#define SERIAL_OUT_TIMING 0
#define SERIAL_OUT_BUTTONS 0

#define SERIAL_OUT_ACC 1




// Buttons
#define BUTT_A 2
#define BUTT_B 3
#define BUTT_C 4

#define DEBOUNCE_DELAY 100

// IMU

// For temperature measurements, the units of the standard 
// deviation would be degrees Celsius or Fahrenheit.
#define ACC_KALMAN_MEASUREMENT_UNCERTAINTY 1.0

//  For example, if you're estimating the position and velocity 
// of an object in meters and meters per second, respectively, 
// the units of the covariance matrix would be meters squared 
// and meters squared per second squared.
#define ACC_KALMAN_ESTIMATION_UNCERTAINTY 1.0

// For example, if you're estimating the position and velocity
// of an object in meters and meters per second, respectively, 
// and the time units used in the Kalman filter equations are seconds,
//  the units of the process noise covariance matrix would be meters 
// squared per second squared and meters squared per second to the fourth power
#define ACC_KALMAN_PROCESS_NOISE_UNCERTAINTY 0.01

#endif
