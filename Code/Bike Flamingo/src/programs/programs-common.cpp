#include <parameters.h>
#include <programs-common.h>

/* It returns a value between 0 and 255 that loops over and over.
The speed that it loops is inverse to the argument given.*/
// Period in tenths of a second, 0 to 255
uint8_t time(uint8_t period)
{
  uint32_t period_millis = period * 100;
  uint32_t elapsed_time = millis() - start_time;
  uint32_t phase_t = elapsed_time % period_millis;
  float phase_int = phase_t / ((float)period_millis);

 /* Serial.print("period_millis is ");
  Serial.print(period_millis);
  Serial.print(", elapsed_time is ");
  Serial.print(elapsed_time);
  Serial.print(", phase_t = ");
  Serial.print(phase_t);
  Serial.print("phase_int is ");
  Serial.print(phase_int);
  Serial.print(", and return value is ");
  Serial.println((uint8_t)(phase_int * 255));*/

  return ((uint8_t)(phase_int * 255));
}

CRGB color = 0x601040; // Flamingo Pink for dotstars
// uint32_t color = 0x106040;  // Flamingo Pink for dotstars

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void setPixelByStrandIndex(uint16_t index, CRGB color)
{
  if ((index >= 0) && (index < NUMPERSTRAND))
  {
    // index goes from 0 to NUMPERSTRAND - 1
    uint8_t realindex = 0;

#if NUM_STRANDS == 1

    realindex = index;
    leds[realindex] = color;
#endif

#if NUM_STRANDS == 3
    // NUMPERSTRAND - 1
    // 0
    realindex = NUMPERSTRAND - index - 1;
    leds[realindex] = color;

    // NUMPERSTRAND
    // 2*NUMPERSTRAND - 1
    realindex = NUMPERSTRAND + index;
    leds[realindex] = color;

    // 3*NUMPERSTRAND - 1
    // 2*NUMPERSTRAND
    realindex = 3 * NUMPERSTRAND - index - 1;
    leds[realindex] = color;
#endif
  }
  else
  {
    Serial.print(F("Tried to set index "));
    Serial.print(index);
    Serial.print(F("In strand of length "));
    Serial.print(NUMPERSTRAND);
    Serial.print(F(" and total number "));
    Serial.print(NUMPIXELS);
    Serial.print(F(" with "));
    Serial.print(NUM_STRANDS);
    Serial.println(F(" strands."));
  }
}

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void setPixelByStrandIndex(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
{
  setPixelByStrandIndex(index, CRGB(r, g, b));
}

// Fade whole strip. fadecoef goes from 0 to 255.
void fadeWholeStrip(uint8_t fade_coef)
{
  for (uint16_t i = 0; i < NUMPIXELS; i++)
  {
    leds[i].r = scale8(leds[i].r, fade_coef);
    leds[i].g = scale8(leds[i].g, fade_coef);
    leds[i].b = scale8(leds[i].b, fade_coef);
  }
}

void fadePixelByStrandIndex(uint16_t index, uint8_t fade)
{
  if ((index >= 0) && (index < NUMPERSTRAND))
  {
    // index goes from 0 to NUMPERSTRAND - 1
    uint8_t realindex = 0;

    // NUMPERSTRAND - 1 to 0
    realindex = NUMPERSTRAND - index - 1;
    leds[realindex].fadeToBlackBy(fade);

    // NUMPERSTRAND to 2*NUMPERSTRAND - 1
    realindex = NUMPERSTRAND + index;
    leds[realindex].fadeToBlackBy(fade);

    // 3*NUMPERSTRAND - 1 to 2*NUMPERSTRAND
    realindex = 3 * NUMPERSTRAND - index - 1;
    leds[realindex].fadeToBlackBy(fade);
  }
}

////////////////////// PROGRAMS
////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void Test()
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tTestRGB"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }

  leds[0] = CRGB(255, 0, 0);
  leds[1] = CRGB(0, 255, 0);
  leds[2] = CRGB(0, 255, 0);
  leds[3] = CRGB(0, 0, 255);
  leds[4] = CRGB(0, 0, 255);
  leds[5] = CRGB(0, 0, 255);
  FastLED.show();
  FastLED.delay(1000);
}*/
