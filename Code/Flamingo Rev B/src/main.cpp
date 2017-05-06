#include <Arduino.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <ADXL345.h>
#include <MPU6050.h>
#include <math.h>

#include <accel.h>
#include <buttons.h>
#include <harmonic_oscillator.h>
#include <parameters.h>
#include <effects.h>

// To use serial or not
#define PLOT 1

/*
 HOW TO CONNECT EVERYTHING

 ** ADXL345 - Adafruit Pro Trinket 5V w/ battery backpack:
 CS -> BAT
 SDO -> GND
 SDA ->A4
 SCL -> A5
 VCC -> BAT
 GND -> GND

  ** ADXL345 - Arduino Uno:
  CS ->3V3
  SDO -> GND
  SDA ->A4
  SCL -> A5
  VCC ->3V3
  GND -> GND
  10k between VCC and SCL ??
  10k between VCC and SDA ??

  Dotstars (Adafruit):
  Green/data - 11
  Yellow/clock - 13
  Gnd to Gnd
  Electrolytic cap across VCC and gnd

  APA102C (chinese):
  Physical location of data/clock wires are different
*/


//////////////////// DOTSTARS //////////////////
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);



////////////////////// ADXL345 /////////////////////////
// class default I2C address is 0x53
// specific I2C addresses may be passed as a parameter here
// ALT low = 0x53 (default for SparkFun 6DOF board)
// ALT high = 0x1D
ADXL345 accel;

void setup() {

  // Initialize serial communication
  Serial.begin(115200);

  //////////////////////// BUTTONS /////////////////

  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  //////////////////////// ADXL345 //////////////////////
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

  // initialize device

  Serial.println("Initializing ADXL345...");

  accel.initialize();

  // Verify connection

  Serial.print("Testing ADXL345 connections...");
  Serial.println(accel.testConnection() ? "\tADXL345 connection successful" : "\tADXL345 connection failed");
  Serial.println("");

  Serial.print("Setting offset: ");
  accel.setOffsetY(0);

  Serial.print("Setting Range to 2");
  accel.setRange(2);
  Serial.println("");

  // Measure 3 seconds of accelerometer values and averages to create offset.
  initAccelOffset();

  //////////////////// DOTSTARS //////////////////////
  strip.begin(); // Initialize pins for output
  strip.setBrightness(30);
  strip.clear();
  strip.show();

}

//////////////////////// LOOP ///////////////////////////////////////////////

void loop()
{

  checkButton1();
  checkButton2();

  //// Damped harmonic oscillator (single pixel).
  if (programIndex == 1)
  {
    DHO_SinglePixel();
  }

  //// Damped harmonic oscillator (blob).
  if (programIndex == 2)
  {
    DHO_Blob();
  }

  //// Rainbow(rainbow).
  if (programIndex == 3)
  {
    Rainbow();
  }

  //// Damped harmonic oscillator (rainbow).
  if (programIndex == 4)
  {
      DHO_Rainbow();
  }

//// Damped harmonic oscillator (sine stripes).
  if (programIndex == 5)
  {
    DHO_SineStripes();
  }

//// Green fire
  if (programIndex == 6)
  {
    Fire();
  }


}
