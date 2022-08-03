#include <parameters.h>
#include <programs-common.h>

uint16_t jrainbow = 0;
// 3
//////////// RAINBOW
////////////////////////////////////////////////////////////////////////////////////////
/*byte *c;

byte *Wheel(byte WheelPos)
{
  static byte c[3];
  if (WheelPos < 85)
    {
      c[0] = WheelPos * 3;
      c[1] = 255 - WheelPos * 3;
      c[2] = 0;
    }
  else if (WheelPos < 170)
    {
      WheelPos -= 85;
      c[0] = 255 - WheelPos * 3;
      c[1] = 0;
      c[2] = WheelPos * 3;
    }
  else
    {
      WheelPos -= 170;
      c[0] = 0;
      c[1] = WheelPos * 3;
      c[2] = 255 - WheelPos * 3;
    }
  for (int i = 0; i < 3; i++)
    {
      c[i] = (int)c[i] * 0.4;
    }
  return c;
}
*/
/*
void Rainbow(void)
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tRainbow"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }

  //////////////// do same here //////////////

  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      c = Wheel(((i * 256 / NUMPERSTRAND) + jrainbow) & 255);
      setPixelByStrandIndex(i, CRGB(*c, *(c + 1), *(c + 2)));
    }
  FastLED.show();
  FastLED.delay(10);
  jrainbow++;
  if (jrainbow == 256 * 5)
    {
      jrainbow = 0;
    }
}*/

void Rainbow_FastLED(void)
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tRainbow FastLED"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
      jrainbow = 0;
    }

  //////////////// do same here //////////////

  CRGB rainbowhue;
  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      rainbowhue = CHSV(jrainbow - 255 * (i / ((float)NUMPERSTRAND)), 255, 255);
      setPixelByStrandIndex(i, rainbowhue);
    }
  FastLED.show();
  //  FastLED.delay(10);
  jrainbow++;
}
