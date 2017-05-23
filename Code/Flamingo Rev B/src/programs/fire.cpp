#include <parameters.h>
#include <programs-common.h>

// 6
//////////// GREEN FIRE
////////////////////////////////////////////////////////////////////////////////////////

// Used with GreenFireOriginal
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
// Mark Kriegsman, July 2012. I converted this to Dotstar originally.

void GreenFireOriginal(void)
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

///////////////////////

// Fire 2016 with pallette, from the FastLED examples.

// Fire2012 with programmable Color Palette
//
// This code is the same fire simulation as the original "Fire2012",
// but each heat cell's temperature is translated to color through a FastLED
// programmable color palette, instead of through the "HeatColor(...)" function.
//
// Four different static color palettes are provided here, plus one dynamic one.
//
// The three static ones are:
//   1. the FastLED built-in HeatColors_p -- this is the default, and it looks
//      pretty much exactly like the original Fire2012.
//
//  To use any of the other palettes below, just "uncomment" the corresponding
//  code.
//
//   2. a gradient from black to red to yellow to white, which is
//      visually similar to the HeatColors_p, and helps to illustrate
//      what the 'heat colors' palette is actually doing,
//   3. a similar gradient, but in blue colors rather than red ones,
//      i.e. from black to blue to aqua to white, which results in
//      an "icy blue" fire effect,
//   4. a simplified three-step gradient, from black to red to white, just to
//   show
//      that these gradients need not have four components; two or
//      three are possible, too, even if they don't look quite as nice for fire.
//
// The dynamic palette shows how you can change the basic 'hue' of the
// color palette every time through the loop, producing "rainbow fire".

// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 55, suggested range 20-100

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.

// setup
// This first palette is the basic 'black body radiation' colors,
// which run from black to red to bright yellow to white.

// These are other ways to set up the color palette for the 'fire'.
// First, a gradient from black to red to yellow to white -- similar to
// HeatColors_p
//   gPal = CRGBPalette16( CRGB::Black, CRGB::Red, CRGB::Yellow, CRGB::White);

// Second, this palette is like the heat colors, but blue/aqua instead of
// red/yellow
//   gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White);

// Third, here's a simpler, three-step gradient, from black to red to white
//   gPal = CRGBPalette16( CRGB::Black, CRGB::Red, CRGB::White);

// Fourth, the most sophisticated: this one sets up a new palette every
// time through the loop, based on a hue that changes every time.
// The palette is a gradient from black, to a dark color based on the hue,
// to a light color based on the hue, to white.
//
//   static uint8_t hue = 0;
//   hue++;
//   CRGB darkcolor  = CHSV(hue,255,192); // pure hue, three-quarters brightness
//   CRGB lightcolor = CHSV(hue,128,255); // half 'whitened', full brightness
//   gPal = CRGBPalette16( CRGB::Black, darkcolor, lightcolor, CRGB::White);

CRGBPalette16 gPal;
typedef struct spark
{
  uint8_t pixels_to_live = 0;
  uint8_t rate = 0;
  uint16_t position = 0;
} spark;
spark sparks[5];
void Fire2012WithPalette()
{
  static uint8_t hue = 0;
  static uint8_t every = 0;
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tFire With Palette"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());

      // gPal = HeatColors_p;
      // gPal = CRGBPalette16(CRGB::Black, CRGB::Blue, CRGB::Aqua, CRGB::White);
    }

  // Set up pallette
  if (every++ == 5)
    {
      every = 0;
      hue++;
    }
  CRGB darkcolor = CHSV(hue, 255, 192);   // pure hue, three-quarters brightness
  CRGB lightcolor = CHSV(hue, 128, 255);  // half 'whitened', full brightness
  gPal = CRGBPalette16(CRGB::Black, darkcolor, lightcolor, CRGB::White);
  //

  // Add entropy to random number generator; we use a lot of it.
  random16_add_entropy(random());
  // Array of temperature readings at each simulation cell
  static byte heat[NUMPERSTRAND];

  // Step 1.  Cool down every cell a little
  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      heat[i] =
          qsub8(heat[i],
                random8(0, ((FIRE_PALLETTE_COOLING * 10) / NUMPERSTRAND) + 2));
    }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for (int k = NUMPERSTRAND - 1; k >= 2; k--)
    {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if (random8() < FIRE_PALLETTE_SPARKING)
    {
      int y = random8(7);
      heat[y] = qadd8(heat[y], random8(160, 255));
    }

  // Step 4.  Map from heat cells to LED colors
  for (int j = 0; j < NUMPERSTRAND; j++)
    {
      // Scale the heat value from 0-255 down to 0-240
      // for best results with color palettes.
      byte colorindex = scale8(heat[j], 100);  // was 240
      CRGB color = ColorFromPalette(gPal, colorindex);
      leds[j] = color;
      //      Serial.print(color.r);
      //      Serial.print("\t");
      //      Serial.print(color.g);
      //      Serial.print("\t");
      //      Serial.println(color.b);
    }

  // Add sparks here

  // No more than N sparks at a time, N could be around 5
  // Random interval before birth
  // Sparks ascend at constant different and random rate
  // Sparks can die before reaching the top. They are born with "pixels to live"
  // Sparks die when reaching the top
  // Spark properties are time to live, where the spark is, speed

  for (int i = 0; i < 5; i++)
    {
      if (sparks[i].position >= NUMPERSTRAND - 1)
        {
          sparks[i].pixels_to_live =
              0;  // We're at the end, so it's time to die
        }
      // for sparks that are alive
      if (sparks[i].pixels_to_live > 0)
        {
          // This spark is alive, so if it is time to move up
          // Move up
          sparks[i].position += sparks[i].rate;
          // Decrease life
          sparks[i].pixels_to_live -= sparks[i].rate;

          if (sparks[i].position < NUMPERSTRAND)
            {
              leds[sparks[i].position] = CRGB(255, 255, 255);
            }
        }
      else  // this spark is not alive. There is a chance a new one could be
            // born!
        {
          if (random8() < 2)
            {
              // Make a new spark
              sparks[i].position =
                  random8(0, NUMPERSTRAND / 2);  // It could appear anywhere
                                                 // near the base of the strand
              sparks[i].pixels_to_live =
                  random8(4, (NUMPERSTRAND / 2) -
                                 sparks[i].position);  // It could last as
                                                       // distance it has yet
                                                       // to cover
              sparks[i].rate = random8(2, 3);
            }
        }
    }

  FastLED.show();            // display this frame
  FastLED.delay(1000 / 60);  // 60 fps
}
