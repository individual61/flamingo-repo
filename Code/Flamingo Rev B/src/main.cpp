#include <ADXL345.h>
#include <Adafruit_DotStar.h>
#include <Arduino.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/pgmspace.h>
#include <math.h>

#include <accel.h>
#include <buttons.h>
#include <effects.h>
#include <harmonic_oscillator.h>
#include <parameters.h>

// To use serial or not
#define PLOT 1

/*
 HOW TO CONNECT EVERYTHING

  ********* ADXL345 *********
  Adafruit Pro Trinket 5V w/ battery backpack:
  CS -> BAT
  SDO -> GND
  SDA -> A4 (I2C SDA)
  SCL -> A5 (I2C SCL)
  VCC -> BAT
  GND -> GND

  Arduino Uno:
  CS ->3V3
  SDO -> GND
  SDA -> A4 (I2C SDA)
  SCL -> A5 (I2C SCL)
  VCC ->3V3
  GND -> GND
  10k between VCC and SCL ??
  10k between VCC and SDA ??

  ********* Buttons *********
  BAT -> Resistor -> (Button Pin) -> (Normally Open Button) -> GND

  ********* Dotstars/APA102C *********
  Electrolytic cap across VCC and GND

  (Adafruit 144/m, on Flamingo Original stick):
  VCC -> BAT
  Green/data -> 11 (Hardware SPI MOSI)
  Yellow/clock -> 13 (Hardware SPI CLOCK)
  GND to GND

  APA102C 144/m (chinese):
  VCC -> BAT
  Green/data -> 11 (Hardware SPI MOSI)
  Red/clock -> 13 (Hardware SPI CLOCK)
  GND to GND
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

int freeRam()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

uint16_t accArray[ACC_AVG_NUM];
uint16_t acc_avg_timeold;
uint16_t acc_avg_timenew;
float acc_avg;

void setup()
{
  // Initialize serial communication
  Serial.begin(115200);

  Serial.print(F("Free SRAM:  "));
  Serial.println(freeRam());

  //////////////////////// BUTTONS /////////////////
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  //////////////////////// ADXL345 //////////////////////
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

  // Initialize accel
  Serial.print(F("Initializing ADXL345... "));
  accel.initialize();
  Serial.println("Done.");

  // Verify connection
  Serial.print(F("Testing ADXL345 connections..."));
  if (accel.testConnection())
    {
      Serial.println(F("\tADXL345 connection successful."));
    }
  else
    {
      Serial.println(F("\tADXL345 connection failed."));
    }
  Serial.println("");

  // Set Y offset
  Serial.print(F("Setting offset... "));
  accel.setOffsetY(0);
  Serial.println("Done.");

  // Set accel range
  Serial.print(F("Setting Range to 2... "));
  accel.setRange(2);
  Serial.println(F("Done."));

  // Measure 3 seconds of accelerometer values and averages to create offset.
  Serial.print(
      F("Measuring 1 second of accelerometer values for zero value... "));
  initAccelOffset();
  Serial.println(F("Done."));

  // Initialize lights
  Serial.print(F("Initializing lights... "));
  strip.begin();  // Initialize pins for output
  strip.setBrightness(STANDARD_BRIGHTNESS);
  strip.clear();
  strip.show();
  Serial.println(F("Done."));

  Serial.println("");
  Serial.println(F("Starting loop."));
  Serial.println("");

  Serial.print(F("Free SRAM:  "));
  Serial.println(freeRam());
}

//////////////////////// LOOP ///////////////////////////////////////////////

unsigned int counter = 0;

void loop()
{
  /*  counter++;
    if(counter==100)
    {
      counter = 0;
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }
  */

  /*
    // Calculate rolling average of acceleration
    acc_avg_timenew = millis();
    // If the interval between avg acc measurements has passed
    if (acc_avg_timenew - acc_avg_timeold > ACC_AVG_INTERVAL)
      {
        acc_avg_timeold = acc_avg_timenew;
        // Reset acc average
        acc_avg = 0.0;
        // Add up all acc_avg[] array values, and shift the array down one.
        for (int i = 0; i < ACC_AVG_NUM - 1; i++)
          {
            // The array is uints, the average is a float
            acc_avg = accArray[i + 1] + acc_avg;
            accArray[i + 1] = accArray[i];
          }
        accArray[0] = ((int)100 * fabs(getOffsetAccel(GFACTOR)));
        acc_avg = acc_avg + accArray[0];
  // At this point acc_avg is the sum of all 100*acc values.
  // Divide by 100 and the number of measurements


        acc_avg =    ((float)(accArray[0])) / (100.0f*((float)ACC_AVG_NUM));
        Serial.print(F("Avg acc:  "));
        Serial.println(acc_avg);
        Serial.print(F("Now acc:  "));
        Serial.println(accArray[0]);
      }
  */
  // Buttons
  checkButton1();
  checkButton2();

  //// Damped harmonic oscillator (single pixel).
  if (programIndex == 1)
    {
      setFullBrightnessOn10();

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

  //// Sparkle
  if (programIndex == 7)
    {
      setFullBrightnessOn10();

      Sparkle(0xff, 0xff, 0xff, 10);
    }

  //// Sparkle Pink
  if (programIndex == 8)
    {
      setFullBrightnessOn10();

      Sparkle(0x10, 0x60, 0x40, 10);
    }

  //// Sparkle Pink Fizz
  if (programIndex == 9)
    {
      setFullBrightnessOn10();

      SparkleFizz(0x10, 0x60, 0x40, 10);
    }

  if (programIndex == 10)
    {
      DHO_Comet();
    }

  if (programIndex == 11)
    {
      Acctest();
    }
}
