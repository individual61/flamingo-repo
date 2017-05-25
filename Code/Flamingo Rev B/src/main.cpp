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
#include <buttons.h>
#include <harmonic_oscillator.h>
#include <parameters.h>
#include <programs-common.h>
#include <utils.h>

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

/////// GENERAL ////
//
//
//

uint32_t timer = 0;
uint8_t counter = 0;

////////////////////   FastLED / APA102C   //////////////////
//

CRGB leds[NUMPIXELS];

////////////////////// ADXL345 /////////////////////////
// class default I2C address is 0x53
// specific I2C addresses may be passed as a parameter here
// ALT low = 0x53 (default for SparkFun 6DOF board)
// ALT high = 0x1D
ADXL345 accel;

uint16_t accArray[ACC_AVG_NUM];
uint16_t acc_avg_timeold;
uint16_t acc_avg_timenew;
float acc_avg;

void setup()
{
  // Initialize serial communication
  Serial.begin(115200);

  Serial.println(F("FLAMINGO REV B"));
  Serial.println(F("by Paul Blackburn"));
  Serial.println(F("paulwb@gmail.com"));
  Serial.println(F(
      "If you find this please let me know—it means it has been stolen. Thank "
      "you!"));
  Serial.println(F(""));
  Serial.println(F(""));

  Serial.print(F("Free SRAM:  "));
  Serial.println(freeRam());
  Serial.println(F(""));

  //////////////////////// BUTTONS /////////////////
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  //////////////////////// ADXL345 //////////////////////
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

  // Initialize accel
  Serial.print(F("Initializing ADXL345... "));
  accel.initialize();
  Serial.println(F("Done."));

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
  Serial.println(F(""));

  // Initialize lights
  Serial.print(F("Initializing lights... "));
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUMPIXELS)
      .setCorrection(CORRECTION);

  FastLED.setBrightness(brightness[0]);
  FastLED.clear();
  FastLED.show();
  Serial.println(F("Done."));

  Serial.println(F(""));
  Serial.println(F("Starting loop."));
  Serial.println(F(""));

  Serial.print(F("Free SRAM:  "));
  Serial.println(freeRam());

  timer = millis();
}

//////////////////////// LOOP ///////////////////////////////////////////////

void loop()
{
  counter++;  // do not reset, let it roll over!

  // Buttons
  checkButton1();
  checkButton2();

  /////////////// DHO GROUP    ///////////////////////////////

  //// Damped harmonic oscillator (single pixel).
  if (programIndex == 1)
    {
      setFullBrightnessOn10();

      DHO_SinglePixel();
    }

  if (programIndex == 2)
    {
      DHO_Fade();
    }

  //// Damped harmonic oscillator (blob).
  if (programIndex == 3)
    {
      DHO_Blob();
    }

  //// Damped harmonic oscillator (rainbow).
  if (programIndex == 4)
    {
      DHO_Rainbow();
    }

  //////////// BOUNCING BALL GROUP ///////////////////////////////

  if (programIndex == 5)
    {
      setFullBrightnessOn10();
      // no fade
      Bouncing_Balls(0);
    }

  if (programIndex == 6)
    {
      setFullBrightnessOn10();
      // fade
      Bouncing_Balls(1);
    }

  /////////////////// FIRE GROUP  ///////////////////////////////

  //// Green fire
  if (programIndex == 7)
    {
      // Added yellow sparks.
      GreenFireOriginal();
    }

  if (programIndex == 8)
    {
      // pink fire
      CRGBPalette16 firepal, sparkpal;
      firepal =
          CRGBPalette16(CRGB(0, 0, 0),
                        CRGB(scale8(96, 100), scale8(16, 100), scale8(40, 100)),
                        scale8(CRGB(96, 16, 40), 255), CRGB(255, 255, 255));
      CRGB sparkcolor = CHSV(230, 71, 200);
      Fire2012WithPalette(firepal, sparkcolor, 1);
    }

  if (programIndex == 9)
    {
      // rainbow fire
      CRGBPalette16 firepal, sparkpal;
      firepal = RainbowColors_p;
      CRGB sparkcolor = CRGB(255, 255, 255);
      Fire2012WithPalette(firepal, sparkcolor, 0);
    }

  if (programIndex == 10)
    {
      Fire2012RainbowRotate();
    }

  ///////////////////   SPARKLE GROUP ///////////////////

  //// Sparkle White
  if (programIndex == 11)
    {
      setFullBrightnessOn10();

      Sparkle(CRGB(255, 255, 255), 10);
    }

  //// Sparkle Pink
  if (programIndex == 12)
    {
      setFullBrightnessOn10();

      Sparkle(color, 10);
    }

  //// Sparkle Pink Fizz
  if (programIndex == 13)
    {
      setFullBrightnessOn10();

      SparkleFizz(color, 10);
    }

  ///////////////////  RAINBOW NON-ACC ///////////////////

  //// Rainbow(rainbow).
  if (programIndex == 14)
    {
      Rainbow_FastLED();
    }
}
