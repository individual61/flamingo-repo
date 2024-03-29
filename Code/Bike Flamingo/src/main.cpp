#include <Arduino.h>
#include <FastLED.h>
#include <ADXL345.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/pgmspace.h>
#include <math.h>
#include <EnableInterrupt.h>

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
uint16_t counter16 = 0;
uint8_t counter_every_10_8 = 0;
uint32_t last_interrupt_time = 0;

// for time()

uint32_t start_time = 0;

////////////////////   FastLED / APA102C   //////////////////
//

CRGB leds[NUMPIXELS];

////////////////////// ADXL345 /////////////////////////
// class default I2C address is 0x53
// specific I2C addresses may be passed as a parameter here
// ALT low = 0x53 (default for SparkFun 6DOF board)
// ALT high = 0x1D
ADXL345 accel;

#if BOARD_TYPE == 3
uint16_t accArray[ACC_AVG_NUM];
uint16_t acc_avg_timeold;
uint16_t acc_avg_timenew;
float acc_avg;
#endif

///////////////

#define numberofprograms 2

uint8_t volatile programIndex = 0;

#define BUTT_A 9
#define BUTT_B 10
#define BUTT_C 11

//#define DEBOUNCE_DELAY 50 // in ms

//#define CLOCK_PIN 3
//#define DATA_PIN 2

//#define NUMPIXELS 27 // Number of LEDs in strip

//#define COLOR_ORDER BGR // my strip is BGR
//#define CORRECTION TypicalLEDStrip
//#define CORRECTION UncorrectedColor

// Fire W PALLETTE parameters
//#define FIRE_PALLETTE_COOLING 70
//#define FIRE_PALLETTE_SPARKING 120

// int caca = 0;

// bool buttA = 0;
// bool buttB = 0;
// bool buttC = 0;

// CRGB leds[NUMPIXELS];

// bool firstRun = 1;

void setup()
{
  // initialize start time for time()
  start_time = millis();

  // Serial
  Serial.begin(115200);
  // while (!Serial)
  //   ;
  Serial.println(F("Started serial to PC."));

  pinMode(BUTT_A, INPUT);
  pinMode(BUTT_B, INPUT);
  pinMode(BUTT_C, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);

  enableInterrupt(BUTT_A, isr_handler_A, FALLING);
  enableInterrupt(BUTT_B, isr_handler_B, FALLING);
  enableInterrupt(BUTT_C, isr_handler_C, FALLING);

  Serial.print(F("Initializing lights... "));
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUMPIXELS)
      .setCorrection(CORRECTION);

  // I guess the first program will always start at 10 brightness.
  FastLED.setBrightness(10);
  FastLED.clear();
  FastLED.show();
  Serial.println(F("Done."));

  // Initialize brightness of all programs to initial brightness
  for (int i = 0; i < NUM_PROGRAMS; i++)
  {
    brightnessIndex[i] = 0;
  }
}

void loop()
{
  /* buttA = digitalRead(BUTT_A);
   buttB = digitalRead(BUTT_B);
   buttC = digitalRead(BUTT_C);
   Serial.print(buttA);
   Serial.print("\t");
   Serial.print(buttB);
   Serial.print("\t");
   Serial.println(buttC);*/

  // Serial.print(F("Entering loop(), programIndex is "));
  // Serial.println(programIndex);

  switch (programIndex)
  {

  case 0:
  {

    // FastLED random8(N, M) is from N to M-1
    uint16_t Pixel = random16(0, NUMPIXELS); // (...]
    // leds[Pixel] = thecolor;
    // CRGB color = 0x601040;  // Flamingo Pink for dotstars
    leds[Pixel] = 0xFFFFFF;
    FastLED.show();
    FastLED.delay(1);
    leds[Pixel] = CRGB(0, 0, 0);
    FastLED.show();
    break;
  }

  case 1:
  {
    if (firstRun)
    {
      Serial.println(F("PROGRAM_1 first run: Fire 2012 Rainbow Rotate"));
      Fire2012RainbowRotate();
      firstRun = 0;
      break;
    }
    Fire2012RainbowRotate();
    break;
  };

  case 2:
  {

    CRGBPalette16 firepal, sparkpal;
    firepal = RainbowColors_p;
    CRGB sparkcolor = CRGB(255, 255, 255);
    bool rotate = 1;

    if (firstRun)
    {
      Serial.println(F("PROGRAM_2 first run: Fire 2012 Rainbow Palette"));
      Fire2012WithPalette(firepal, sparkcolor, 0, rotate);
      firstRun = 0;
      break;
    }

    // rainbow fire
    Fire2012WithPalette(firepal, sparkcolor, 0, rotate);

    break;
  };

  case 3:
  {
    if (firstRun)
    {
      Serial.println(F("PROGRAM_3 "));
      synchronized_random_numbers_rainbow();
      firstRun = 0;
      break;
    }
    synchronized_random_numbers_rainbow();
    break;
  };

  default:
  {
    Serial.print(F("We fell into default case, programIndex is "));
    Serial.println(programIndex);
  };
  };
};

/*

//TEMPLATE
    case 3:
  {
    if (firstRun)
    {
      Serial.println(F("PROGRAM_3 "));
      firstRun = 0;
      break;
    }

    break;
  };
  */