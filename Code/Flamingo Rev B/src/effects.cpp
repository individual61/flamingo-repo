#include <effects.h>
#include <parameters.h>

uint32_t color = 0x106040;  // Flamingo Pink

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void setPixelByIndex(int index, uint32_t color)
{
  if ((index > 0) && (index < NUMPERSTRAND))
    {
      uint8_t realindex = 0;
      realindex = NUMPERSTRAND - index - 1;
      strip.setPixelColor(realindex, color);
      realindex = NUMPERSTRAND + index;
      strip.setPixelColor(realindex, color);
      realindex = 3 * NUMPERSTRAND - index - 1;
      strip.setPixelColor(realindex, color);
    }
}

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void setPixelByIndex(int index, uint8_t r, uint8_t g, uint8_t b)
{
  if ((index > 0) && (index < NUMPERSTRAND))
    {
      uint8_t realindex = 0;
      realindex = NUMPERSTRAND - index - 1;
      strip.setPixelColor(realindex, r, g, b);
      realindex = NUMPERSTRAND + index;
      strip.setPixelColor(realindex, r, g, b);
      realindex = 3 * NUMPERSTRAND - index - 1;
      strip.setPixelColor(realindex, r, g, b);
    }
}

////////////////////// PROGRAMS
////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 1
//////////// DHO SINGLE PIXEL
////////////////////////////////////////////////////////////////////////////////////////
void DHO_SinglePixel(void)
{
  if (firstRun)
    {
      strip.clear();
      firstRun = 0;
    }
  float BallPosition = getBallPosition();

  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      setPixelByIndex(i, 0);
    }
  // These should be changed to fractions of NUMPERSTRAND
  setPixelByIndex(48 - (24 + ballToStrandPosition(BallPosition)) - 1, color);
  strip.show();
}

// 2
//////////// DHO Blob
////////////////////////////////////////////////////////////////////////////////////////

// For DHO_Blob
const uint8_t gaussianTable[15] PROGMEM = {5,  11, 21, 37, 57, 78, 94, 100,
                                           94, 78, 57, 37, 21, 11, 5};

void DHO_Blob(void)
{
  if (firstRun)
    {
      strip.clear();
      firstRun = 0;
    }
  float BallPosition = getBallPosition();

  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      setPixelByIndex(i, 0);
    }
  int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;
  float attnFactor;

  for (int k = -7; k <= 7; k++)
    {
      attnFactor =
          (float)((float)pgm_read_byte_near(gaussianTable + k + 7) / 100.0f);
      /*    Serial.print("attnFactor: ");
          Serial.println(attnFactor);
                Serial.print("k: ");
          Serial.println(k);*/
      setPixelByIndex(centerindex + k, strip.Color((int)(16 * attnFactor),
                                                   (int)(96 * attnFactor),
                                                   (int)(64 * attnFactor)));
    }
  strip.show();
}

// 3
//////////// RAINBOW
////////////////////////////////////////////////////////////////////////////////////////
byte *c;
uint16_t jrainbow = 0;
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

void Rainbow(void)
{
  if (firstRun)
    {
      strip.clear();
      firstRun = 0;
    }
  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      c = Wheel(((i * 256 / NUMPERSTRAND) + jrainbow) & 255);
      setPixelByIndex(i, strip.Color(*c, *(c + 1), *(c + 2)));
    }
  strip.show();
  delay(20);
  jrainbow++;
  if (jrainbow == 256 * 5)
    {
      jrainbow = 0;
    }
}

// 4
//////////// DHO Rainbow
////////////////////////////////////////////////////////////////////////////////////////
void DHO_Rainbow(void)
{
  if (firstRun)
    {
      strip.clear();
      firstRun = 0;
    }
  float BallPosition = getBallPosition();

  int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;

  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      c = Wheel(((i * 256 / NUMPERSTRAND) + 2 * centerindex) & 255);
      setPixelByIndex(i, strip.Color(*c, *(c + 1), *(c + 2)));
    }
  strip.show();
}

// 5
//////////// SINE STRIPES
////////////////////////////////////////////////////////////////////////////////////////

// FOR DHO_SineStripes
const uint8_t sinTable[97] PROGMEM = {
    0,  7,   25, 50,  75, 93,  100, 93, 75,  50, 25,  7,  0,  7,   25, 50,  75,
    93, 100, 93, 75,  50, 25,  7,   0,  7,   25, 50,  75, 93, 100, 93, 75,  50,
    25, 7,   0,  7,   25, 50,  75,  93, 100, 93, 75,  50, 25, 7,   0,  7,   25,
    50, 75,  93, 100, 93, 75,  50,  25, 7,   0,  7,   25, 50, 75,  93, 100, 93,
    75, 50,  25, 7,   0,  7,   25,  50, 75,  93, 100, 93, 75, 50,  25, 7,   0,
    7,  25,  50, 75,  93, 100, 93,  75, 50,  25, 7,   0};

void DHO_SineStripes(void)
{
  if (firstRun)
    {
      strip.clear();
      firstRun = 0;
    }
  float BallPosition = getBallPosition();

  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      setPixelByIndex(i, 0);
    }
  int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;
  float attnFactor;

  for (int k = -48; k <= 48; k++)
    {
      attnFactor =
          (float)(((float)pgm_read_byte_near(sinTable + k + 48)) / 100.0f);
      /*    Serial.print("attnFactor: ");
          Serial.println(attnFactor);
                Serial.print("k: ");
          Serial.println(k);*/
      setPixelByIndex(centerindex + k, strip.Color((int)(16 * attnFactor),
                                                   (int)(96 * attnFactor),
                                                   (int)(64 * attnFactor)));
    }
  strip.show();
}

// 6
//////////// GREEN FIRE
////////////////////////////////////////////////////////////////////////////////////////

void setPixelHeatColorgreen(int Pixel, byte temperature)
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
      setPixelByIndex(Pixel, strip.Color(255, 255, heatramp));
    }
  else if (t192 > 0x40)
    {  // middle
      setPixelByIndex(Pixel, strip.Color(255, heatramp, 0));
    }
  else
    {  // coolest
      setPixelByIndex(Pixel, strip.Color(heatramp, 0, 0));
    }
}

void Fire(void)
{
  if (firstRun)
    {
      strip.clear();
      firstRun = 0;
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
  strip.show();
  strip.show();
  delay(GFIRE_SPEEDDELAY);
}

// 7
//////////// SPARKLE
////////////////////////////////////////////////////////////////////////////////////////

void Sparkle(uint8_t red, uint8_t green, uint8_t blue, uint8_t SpeedDelay)
{
  if (firstRun)
    {
      strip.clear();
      firstRun = 0;
    }
  int Pixel = random(1, NUMPERSTRAND + 1);  // (...]
  setPixelByIndex(Pixel, red, green, blue);
  strip.show();
  delay(SpeedDelay);
  setPixelByIndex(Pixel, 0, 0, 0);
  strip.show();
}

// 8
//////////// SPARKLE PINK
////////////////////////////////////////////////////////////////////////////////////////

// ditto

// 9
//////////// SPARKLE PINK FIZZ
////////////////////////////////////////////////////////////////////////////////////////

// The higher the average acceleration, the shorter the interval between flashes
// Define: Max g, longest interval





#define ACC_AVG_NUM 10
#define ACC_AVG_INTERVAL 100

void SparkleFizz(uint8_t red, uint8_t green, uint8_t blue, uint8_t SpeedDelay)
{
  if (firstRun)
    {
      strip.clear();
      firstRun = 0;
    }

  uint16_t sparkleInterval = 0;

  float accel = fabs(acc_avg);
  sparkleInterval =
      constrain((MAX_G_SPARKLEFIZZ - accel) / MAX_G_SPARKLEFIZZ, 0.0, 1.0) *
      MAX_INTERVAL_SPARKLEFIZZ;

  timenow_i = millis();
  if (timenow_i - timeold_i >= constrain(sparkleInterval + random(-JITTER_SPARKLEFIZZ, JITTER_SPARKLEFIZZ), 0, 2*MAX_INTERVAL_SPARKLEFIZZ))
    {
      timeold_i = timenow_i;
      int Pixel = random(1, NUMPERSTRAND + 1);  // (...]
      setPixelByIndex(Pixel, red, green, blue);
      strip.show();
      delay(SpeedDelay);
      setPixelByIndex(Pixel, 0, 0, 0);
      strip.show();
    }

}
