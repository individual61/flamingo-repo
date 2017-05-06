#include <effects.h>
#include <parameters.h>


// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void setPixelByIndex(int index, uint32_t color)
{
  if ((index > 0) && (index < NUMPERSTRAND))
  {
    int realindex = 0;
    realindex = NUMPERSTRAND - index - 1;
    strip.setPixelColor(realindex, color);
    realindex = NUMPERSTRAND + index ;
    strip.setPixelColor(realindex, color);
    realindex = 3 * NUMPERSTRAND - index - 1;
    strip.setPixelColor(realindex, color);
  }
}



//////////// RAINBOW
byte *c;
uint16_t jrainbow = 0;
byte * Wheel(byte WheelPos)
{
  static byte c[3];
  if (WheelPos < 85)
  { c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  }
  else if (WheelPos < 170)
  {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  } else {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }
  for (int i = 0; i < 3; i++)
  {
    c[i] = (int) c[i] * 0.4;
  }
  return c;
}

void setPixelHeatColorgreen(int Pixel, byte temperature)
{ // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);
  // calculate ramp up from
  byte heatramp = t192 & 0x3F;
  // 0..63
  heatramp <<= 2;
  // scale up to 0..252
  // figure out which third of the spectrum we're in:

  if ( t192 > 0x80)
  { // hottest
    setPixelByIndex(Pixel, strip.Color(255, 255, heatramp));
  }
  else if ( t192 > 0x40 )
  { // middle
    setPixelByIndex(Pixel, strip.Color(255, heatramp, 0));
  }
  else
  { // coolest
    setPixelByIndex(Pixel, strip.Color(heatramp, 0, 0));
  }
}

///////// Program
void DHO_SinglePixel(void)
{

float BallPosition = getBallPosition();

for (int i = 0; i < NUMPERSTRAND; i++)
{
  setPixelByIndex(i, 0);
}
setPixelByIndex(48 - (24 + ballToStrandPosition(BallPosition)) - 1, color);
strip.show();
}

//////////// Program
void Rainbow(void)
{
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

//////////// Program
void DHO_Rainbow(void)
{
float BallPosition = getBallPosition();

int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;

for (int i = 0; i < NUMPERSTRAND; i++)
{
  c = Wheel(((i * 256 / NUMPERSTRAND) + 2 * centerindex) & 255);
  setPixelByIndex(i, strip.Color(*c, *(c + 1), *(c + 2)));
}
strip.show();
}

void DHO_Blob(void)
{
float BallPosition = getBallPosition();

for (int i = 0; i < NUMPERSTRAND; i++)
{
  setPixelByIndex(i, 0);
}
int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;
float attnFactor;
float gaussianTable[15] = {0.05, 0.11, 0.21, 0.37, 0.57, 0.78, 0.94, 1.00, 0.94, 0.78, 0.57, 0.37, 0.21, 0.11, 0.05};
for (int k = -7; k <= 7; k++)
{
  attnFactor = gaussianTable[k + 7];
  /*    Serial.print("attnFactor: ");
      Serial.println(attnFactor);
            Serial.print("k: ");
      Serial.println(k);*/
  setPixelByIndex(centerindex + k, strip.Color((int)(16 * attnFactor), (int)(96 * attnFactor), (int)(64 * attnFactor)));

}
strip.show();
}


/////////////////// Program
void DHO_SineStripes(void)
{
  float BallPosition = getBallPosition();

for (int i = 0; i < NUMPERSTRAND; i++)
{
  setPixelByIndex(i, 0);
}
int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;
float attnFactor;
float sinTable[97] = {0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                      0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                      0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                      0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07, 0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                      0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                      0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                      0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07, 0.00
                     };
for (int k = -48; k <= 48; k++)
{
  attnFactor = sinTable[k + 48];
  /*    Serial.print("attnFactor: ");
      Serial.println(attnFactor);
            Serial.print("k: ");
      Serial.println(k);*/
  setPixelByIndex(centerindex + k, strip.Color((int)(16 * attnFactor), (int)(96 * attnFactor), (int)(64 * attnFactor)));

}
strip.show();
}

void Fire(void)
{
//Fire(55, 120, 15);
int Cooling = 55;
int Sparking = 120;
int SpeedDelay = 15;

static byte heat[NUMPERSTRAND];
int cooldown;
// Step 1.  Cool down every cell a little
for ( int i = 0; i < NUMPERSTRAND; i++)
{
  cooldown = random(0, ((Cooling * 10) / NUMPERSTRAND) + 2);
  if (cooldown > heat[i]) {
    heat[i] = 0;
  }
  else
  {
    heat[i] = heat[i] - cooldown;
  }
}
// Step 2.  Heat from each cell drifts 'up' and diffuses a little
for ( int k = NUMPERSTRAND - 1; k >= 2; k--)
{
  heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
}
// Step 3.  Randomly ignite new 'sparks' near the bottom
if ( random(255) < Sparking )
{
  int y = random(7);
  heat[y] = heat[y] + random(160, 255);
  //heat[y] = random(160,255);
}
// Step 4.  Convert heat to LED colors
for ( int j = 0; j < NUMPERSTRAND; j++)
{
  setPixelHeatColorgreen(j, heat[j] );
}
strip.show();
strip.show();
delay(SpeedDelay);
}
