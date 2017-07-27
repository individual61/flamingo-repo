#include <parameters.h>
#include <programs-common.h>

CRGB color = 0x601040;  // Flamingo Pink for dotstars
// uint32_t color = 0x106040;  // Flamingo Pink for dotstars

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void setPixelByStrandIndex(uint16_t index, CRGB color)
{
  if ((index >= 0) && (index < NUMPERSTRAND))
    {
      // index goes from 0 to NUMPERSTRAND - 1
      uint8_t realindex = 0;

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
