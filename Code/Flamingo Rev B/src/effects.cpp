#include <effects.h>
#include <parameters.h>

CRGB color = 0x106040;  // Flamingo Pink for dotstars
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

// 1
//////////// DHO SINGLE PIXEL
////////////////////////////////////////////////////////////////////////////////////////

void DHO_SinglePixel()
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tDHO_SinglePixel"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }

  float BallPosition = getBallPosition();

  FastLED.clear();

  setPixelByStrandIndex(ballToStrandPosition(BallPosition), color);
  /*  Serial.print("\tBallPosiition:\t");
    Serial.print(BallPosition);
    Serial.print("\tPixel Index:\t");
    Serial.println(temp);
    */
  FastLED.show();
}

// 2
//////////// DHO Blob
////////////////////////////////////////////////////////////////////////////////////////

// For DHO_Blob
const uint8_t gaussianTable[19] PROGMEM = {2,   5,   12,  27,  53,  94,  145,
                                           199, 240, 255, 240, 199, 145, 94,
                                           53,  27,  12,  5,   2};

void DHO_Blob(void)
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tDHO_Blob"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }
  float BallPosition = getBallPosition();

  FastLED.clear();
  int centerindex = (uint16_t((float)NUMPERSTRAND / 2.0) +
                     BallPosition * ((float)NUMPERSTRAND / 2.0));
  float attnFactor;

  for (int k = -9; k <= 9; k++)
    {
      attnFactor =
          (uint8_t)((uint8_t)pgm_read_byte_near(gaussianTable + k + 9));
      /*    Serial.print("attnFactor: ");
          Serial.println(attnFactor);
                Serial.print("k: ");
          Serial.println(k);*/

      setPixelByStrandIndex(centerindex + k, scale8(16, attnFactor),
                            scale8(96, attnFactor), scale8(64, attnFactor));
    }
  FastLED.show();
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
  FastLED.delay(20);
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
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tDHO_Rainbow"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }
  float BallPosition = getBallPosition();

  int centerindex = (uint16_t((float)NUMPERSTRAND / 2.0) +
                     BallPosition * ((float)NUMPERSTRAND / 2.0));

  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      c = Wheel(((i * 256 / NUMPERSTRAND) + 2 * centerindex) & 255);
      setPixelByStrandIndex(i, CRGB(*c, *(c + 1), *(c + 2)));
    }
  FastLED.show();
}

// 5
//////////// SINE STRIPES
////////////////////////////////////////////////////////////////////////////////////////

// FOR DHO_SineStripes

const uint8_t sinTable[97] PROGMEM = {
    0,   17,  64,  128, 191, 238, 255, 238, 191, 128, 64,  17,  0,   17,
    64,  128, 191, 238, 255, 238, 191, 128, 64,  17,  0,   17,  64,  128,
    191, 238, 255, 238, 191, 128, 64,  17,  0,   17,  64,  128, 191, 238,
    255, 238, 191, 128, 64,  17,  0,   17,  64,  128, 191, 238, 255, 238,
    191, 128, 64,  17,  0,   17,  64,  128, 191, 238, 255, 238, 191, 128,
    64,  17,  0,   17,  64,  128, 191, 238, 255, 238, 191, 128, 64,  17,
    0,   17,  64,  128, 191, 238, 255, 238, 191, 128, 64,  17,  0};

void DHO_SineStripes(void)
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tDHO_SineStripes"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }
  float BallPosition = getBallPosition();

  FastLED.clear();
  int centerindex = NUMPERSTRAND -
                    (NUMPERSTRAND / 2.0f + ballToStrandPosition(BallPosition)) -
                    1;
  float attnFactor;

  for (int k = -NUMPERSTRAND; k <= NUMPERSTRAND; k++)
    {
      attnFactor =
          (float)(((float)pgm_read_byte_near(sinTable + k + NUMPERSTRAND)));
      /*    Serial.print("attnFactor: ");
          Serial.println(attnFactor);
                Serial.print("k: ");
          Serial.println(k);*/

      setPixelByStrandIndex(centerindex + k, scale8(16, attnFactor),
                            scale8(96, attnFactor), scale8(64, attnFactor));
    }
  FastLED.show();
}

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

// 7
//////////// SPARKLE
////////////////////////////////////////////////////////////////////////////////////////

void Sparkle(uint8_t red, uint8_t green, uint8_t blue, uint8_t duration)
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tSparkle"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }
    // FastLED random8(N, M) is from N to M-1
  uint8_t Pixel = random8(0, NUMPERSTRAND);  // (...]
  setPixelByStrandIndex(Pixel, CRGB(red, green, blue));
  FastLED.show();
  FastLED.delay(duration);
  setPixelByStrandIndex(Pixel, CRGB(0, 0, 0));
  FastLED.show();
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

float acc_max = 0.0;
uint16_t sparkleInterval;
uint16_t acc_max_timeold;
uint16_t acc_max_timenew;
uint16_t sparkle_timeold;
uint16_t sparkle_timenew;
uint16_t sparkleInterval_max;

void SparkleFizz(uint8_t red, uint8_t green, uint8_t blue, uint8_t duration)
{
  if (firstRun)
    {
      FastLED.clear();
      acc_max = 0;
      firstRun = 0;
      sparkleInterval = 0;
      sparkle_timeold = 0;
      sparkle_timenew = 0;
      Serial.println(F("Starting Program:\tSparkleFizz"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }

  // Calculate decaying max of acceleration
  // acc_timenew is time of current sample, acc_timeold is last time we hit a
  // max.
  // This way the exponential decay is undisturbed if there is no new max.
  acc_max_timenew = millis();

  float arg = ((float)(acc_max_timenew - acc_max_timeold));
  float acc_decayed =
      acc_max * (1.0 - constrain((arg / ACC_MAX_DECAY_RATE), 0.0, 1.0));
  //  float acc_decayed = acc_max * exp(-arg/ACC_MAX_DECAY_RATE);

  float acc_now = fabs(getNormalizedOffsetAccelY());

  // This avoids the problem of being stuck on max sparkle rate for a time that
  // depends on how big the acceleration was. This way there is a max sparkle
  // rate momentarily and everything is lower than that. Worried about exp being
  // too fast a decay? Choose a slow decay and keep shaking, bitch.
  if (acc_now >= MAX_G_SPARKLEFIZZ)
    {
      acc_now = MAX_G_SPARKLEFIZZ;
      // Force sparkle for a hard jerk
      sparkleInterval = 0;
    }

  //  If the acceleration magnitude now is higher than the decayed acceleration
  if (acc_now >= acc_decayed)
    {
      // Current acc is new max and decay time is reset
      acc_max = acc_now;
      acc_max_timeold = acc_max_timenew;
    }

  // We now have a decaying maximum value for acceleration.
  // This needs to be converted into an inter-sparkle interval
  // Sparkle interval should be 0 at some max acceleration value
  // (MAX_G_SPARKLEFIZZ)
  // Sparkle interval should max out at some value.

  sparkle_timenew = millis();

  if (sparkle_timenew - sparkle_timeold > sparkleInterval)
    {
      // If it's time for a sparkle, reset sparkle timer
      sparkle_timeold = sparkle_timenew;

      /*
            Serial.print(1);
            Serial.print(F("\t"));
      */

      // Make the sparkle
      int Pixel = random8(0, NUMPERSTRAND);  // (...]
      setPixelByStrandIndex(Pixel, CRGB(red, green, blue));
      FastLED.show();
      FastLED.delay(duration);
      setPixelByStrandIndex(Pixel, CRGB(0, 0, 0));
      FastLED.show();

      // Now choose a new random sparkle interval based on acc_decayed
      // The interval between sparkles is a random number
      // That goes between 0 if acc_max is >= MAX_G_SPARKLEFIZZ
      // and MAX_INTERVAL_SPARKLEFIZZ if acc_max is 0.0
      sparkleInterval_max = (uint16_t)(
          MAX_INTERVAL_SPARKLEFIZZ *
          (1.0 - constrain(acc_decayed / MAX_G_SPARKLEFIZZ, 0.0, 1.0)));
      sparkleInterval = random16(sparkleInterval_max);
      // sparkleinterval now contains the amount of time to wait for another
      // sparkle
    }
  else
    {
      //      Serial.print(0);
      //      Serial.print(F("\t"));
    }
  /*
    // Debugging output
    Serial.print(acc_now);
    Serial.print(F("\t"));
    Serial.print(acc_max);
    Serial.print(F("\t"));
    Serial.println(acc_decayed);

    */
  /*  Serial.print(F("\t"));
   Serial.print(sparkleInterval);
    Serial.print(F("\t"));
    Serial.println(sparkleInterval_max);*/
  //  Serial.print((uint16_t)(MAX_INTERVAL_SPARKLEFIZZ*(1.0 -
  //  constrain(acc_decayed / MAX_G_SPARKLEFIZZ, 0.0, 1.0))));
  //  Serial.print(F("\t"));
}

/*
void Acctest(void)
{
  Serial.print(F("\tgetNormalizedOffsetAccelY: "));
  Serial.println(getNormalizedOffsetAccelY());
  delay(50);
}
*/

int8_t pos_history[NUM_HISTORY];
void DHO_Comet()
{
  if (firstRun)
    {
      FastLED.clear();

      firstRun = 0;
      for (int i = 0; i < NUM_HISTORY; i++)
        {
          pos_history[i] = 0;
        }
      Serial.println(F("Starting Program:\tDHO_Comet"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }  // if firstRun

  // Shift all values in pos_history array.
  for (int i = 0; i < NUM_HISTORY - 1; i++)
    {
      pos_history[i + 1] = pos_history[i];
    }

  // New current position
  pos_history[0] = ballToStrandPosition(getBallPosition());
  //  Serial.print("Position: ");
  //  Serial.print(pos_history[0]);
  //  Serial.print("\t");
  //  Serial.print("pos_history: ");

  // Clear strip of all previous values
  // FastLED.clear();

  // Brightness of last value in pos_history array should be zero.
  // Draw from tail to head.
  uint8_t fade = 0;

  for (int i = NUM_HISTORY - 1; i > -1; i--)
    {
      // fade is 1.0 when i is 0 and 0.0 when i is NUM_HISTORY -1.
      // Here function is linear but could be something else.
      fade = (uint8_t)(255.0 * (1.0 - ((float)i) / ((float)(NUM_HISTORY - 1))));

      fadePixelByStrandIndex(pos_history[i], fade);
      /*  if (counter == 0)
          {
            Serial.print(pos_history[i]);
            Serial.print("/");
            Serial.print(fade);
            Serial.print("/");
            Serial.print((uint8_t)(fade * 60.0f));
            Serial.print("\t");
          }
          */
    }
  /*  if (counter == 0)
      {
        Serial.println("");
      }
      */
  FastLED.show();
}

void DHO_Fade()
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tDHO_Fade"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());
    }

  // about 1 to 2 ms
  float BallPosition = getBallPosition();

  // about 7 ms
  fadeWholeStrip((uint8_t)FADE_COEF);

  // < 0 ms
  setPixelByStrandIndex(ballToStrandPosition(BallPosition), color);

  /*  Serial.print("\tBallPosiition:\t");
    Serial.print(BallPosition);
    Serial.print("\tPixel Index:\t");
    Serial.println(temp);
    */

  // about 1 ms
  FastLED.show();
}
