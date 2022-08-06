#include <parameters.h>
#include <programs-common.h>


//////////// SPARKLE
////////////////////////////////////////////////////////////////////////////////////////

void Sparkle(CRGB thecolor, uint8_t duration)
{

  if (firstRun)
  {
    Serial.println("PROGRAM_0 first run: Sparkle");
    firstRun = 0;
  }
  // FastLED random8(N, M) is from N to M-1
  uint16_t Pixel = random16(0, NUMPIXELS); // (...]
  // leds[Pixel] = thecolor;
  // CRGB color = 0x601040;  // Flamingo Pink for dotstars
  leds[Pixel] = 0xFFFFFF;
  FastLED.show();
  FastLED.delay(1);
  leds[Pixel] = CRGB(0, 0, 0);
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

void SparkleFizz(CRGB thecolor, uint8_t duration)
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
    uint16_t Pixel = random8(0, NUMPIXELS); // (...]
    leds[Pixel] = thecolor;
    FastLED.show();
    FastLED.delay(duration);
    leds[Pixel] = CRGB(0, 0, 0);
    FastLED.show();

    // Now choose a new random sparkle interval based on acc_decayed
    // The interval between sparkles is a random number
    // That goes between 0 if acc_max is >= MAX_G_SPARKLEFIZZ
    // and MAX_INTERVAL_SPARKLEFIZZ if acc_max is 0.0
    sparkleInterval_max = (uint16_t)(MAX_INTERVAL_SPARKLEFIZZ *
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
