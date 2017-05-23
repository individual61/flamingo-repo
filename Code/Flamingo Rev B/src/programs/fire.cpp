#include <parameters.h>
#include <programs-common.h>

// 6
//////////// GREEN FIRE
////////////////////////////////////////////////////////////////////////////////////////

void setPixelHeatColorgreen(uint16_t Pixel, byte temperature)
{  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);
  // calculate ramp up from
  byte heatramp = t192 & 0x3F;
  // 0..63
  heatramp <<= 2;
  // scale up to 0..252
  // figure out which third of the spectrum we're in:
  if (t192 > 0x80)
    {  // hottest
      setPixelByStrandIndex(Pixel, CRGB(255, 255, heatramp));
    }
  else if (t192 > 0x40)
    {  // middle
      setPixelByStrandIndex(Pixel, CRGB(255, heatramp, 0));
    }
  else
    {  // coolest
      setPixelByStrandIndex(Pixel, CRGB(heatramp, 0, 0));
    }
}

// Fire2012: a basic fire simulation for a one-dimensional string of LEDs
// Mark Kriegsman, July 2012.
void Fire(void)
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tFire"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }
  // Fire(55, 120, 15);

  static byte heat[NUMPERSTRAND];
  int cooldown;
  // Step 1.  Cool down every cell a little
  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      cooldown = random(0, (((GFIRE_COOLING)*10) / NUMPERSTRAND) + 2);
      if (cooldown > heat[i])
        {
          heat[i] = 0;
        }
      else
        {
          heat[i] = heat[i] - cooldown;
        }
    }
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for (int k = NUMPERSTRAND - 1; k >= 2; k--)
    {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if (random(255) < GFIRE_SPARKING)
    {
      int y = random(7);
      heat[y] = heat[y] + random(160, 255);
      // heat[y] = random(160,255);
    }
  // Step 4.  Convert heat to LED colors
  for (int j = 0; j < NUMPERSTRAND; j++)
    {
      setPixelHeatColorgreen(j, heat[j]);
    }
  FastLED.show();
  FastLED.delay(GFIRE_SPEEDDELAY);
}
