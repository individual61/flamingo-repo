#include <harmonic_oscillator.h>
#include <parameters.h>
#include <programs-common.h>

float pos0, pos1, vel0, vel1, acc0, acc1, acc_ext;

uint16_t timeold_i = 0;
uint16_t timenow_i = 0;
float timenow_f = 0.0;
float timestep_f = 0.0;
float timestep_i =
    0;  // check how this is used, name suggests int but decl is float

bool first_iter = 0;
uint16_t sendTime = 0;  // currently in a commented out section

//////// DAMPED HARMONIC OSCILLATOR FUNCTIONS ///////////////

float eval_v_func_DHO(float v, float x, float acc_ext, float damping,
                      float springconstant, float mass)
{
  // acc_ext is generally negative when Flamingo is upright.
  // m x'' = - k x - c v + F_ext
  // with F_ext = m acc_ext
  return -damping * v - springconstant * x + mass * acc_ext;
}

// Integrates acceleration to get velocity for DHO
float get_next_v_DHO(float oldv, float oldx, float acc_ext, float damping,
                     float springconstant, float mass)
{
  float k1, k2, k3, k4;
  k1 = eval_v_func_DHO(oldv, oldx, acc_ext, damping, springconstant, mass);
  k2 = eval_v_func_DHO(oldv + 0.5 * k1, oldx, acc_ext, damping, springconstant,
                       mass);
  k3 = eval_v_func_DHO(oldv + 0.5 * k2, oldx, acc_ext, damping, springconstant,
                       mass);
  k4 = eval_v_func_DHO(oldv + k3, oldx, acc_ext, damping, springconstant, mass);
  return (float)(oldv + timestep_f * ((k1 / 6.0) + (k2 / 3.0) + (k3 / 3.0) +
                                      (k4 / 6.0)));
}

// integrates velocity to get position
float get_next_x_DHO(float oldv, float oldx)
{
  return (float)(oldx + timestep_f * oldv);
}

int ballToStrandPosition_DHO(float ballPos_DHO)
{
  return (NUMPERSTRAND / 2) + ballPos_DHO * (NUMPERSTRAND / 2);
};

// DAMPED HARMONIC OSCILLATOR, real physical units. Returns object position as a
// float, centered on 0, so maxrange is half the length of the strip.  Resting
// location is at 0.0
float getBallPosition_DHO(void)
{
  if (first_iter == 1)  // first iteration
    {
      pos0 = 0.0;
      vel0 = 0.0;
      timenow_i = 0;
      timestep_i = timenow_i - timeold_i;
      timeold_i = millis();  // why is this timeold and not timenow? I moved
                             // this from below btw
      timestep_f = 0.01 * ((float)timestep_i);

      // getNormalizedAccelY() is negative when Flamingo is upright.
      // getNormalizedAccelY() returns normalized acc in units of g
      // Right side up: 1.0
      // Upside Down:   -1.0
      acc_ext = G_ACC_MAGNITUDE * getNormalizedAccelY();
      vel1 = get_next_v_DHO(vel0, pos0, acc_ext, DAMPING_REAL,
                            SPRINGCONSTANT_REAL, MASS_REAL);
      pos1 = get_next_x_DHO(vel0, pos0);

      timeold_i = timenow_i;
      pos0 = pos1;
      vel0 = vel1;

      first_iter = 0;
    }
  else
    {
      timenow_i = millis();
      timestep_i = timenow_i - timeold_i;
      timestep_f = 0.01 * ((float)timestep_i);

      // acc_ext is generally negative because getNormalizedAccelY() returns
      // negative when Flamingo is upright.
      // G_ACC_MAGNITUDE is positive.
      acc_ext = G_ACC_MAGNITUDE * getNormalizedAccelY();
      vel1 = get_next_v_DHO(vel0, pos0, acc_ext, DAMPING_REAL,
                            SPRINGCONSTANT_REAL, MASS_REAL);
      pos1 = get_next_x_DHO(vel0, pos0);
      vel0 = vel1;
      pos0 = pos1;
      timeold_i = timenow_i;

      /*
            uint16_t timet = millis();
            if (timet - sendTime > 100)
              {
                Serial.print(F("Time:\t"));
                Serial.print(timet);
                Serial.print(F("\tpos1:\t"));
                Serial.print((pos1));
                Serial.print(F("\tBallPosition:\t"));
                Serial.print(
                    (pos1 / (MASS_REAL * G_ACC_MAGNITUDE / SPRINGCONSTANT_REAL))
         + 1.0); Serial.print(F("\tPixel Index:\t"));
                Serial.print(ballToStrandPosition(
                    (pos1 / (MASS_REAL * G_ACC_MAGNITUDE / SPRINGCONSTANT_REAL))
         + 1.0)); Serial.print(F("\tgetNormalizedAccelY:\t"));
                Serial.print(getNormalizedAccelY());
                Serial.print(F("\tgetNormalizedOffsetAccelY:\t"));
                Serial.println(getNormalizedOffsetAccelY());
                sendTime = timet;
              }
      */
    }
  // Resting location is at 0.0
  float temp =
      (pos1 / (MASS_REAL * G_ACC_MAGNITUDE / SPRINGCONSTANT_REAL)) + 1.0;

  return temp;
}

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

  float BallPosition = getBallPosition_DHO();

  FastLED.clear();

  setPixelByStrandIndex(ballToStrandPosition_DHO(BallPosition), color);
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
const uint8_t gaussianTable[19] PROGMEM = {0,   5,   12,  27,  53,  94,  145,
                                           199, 240, 255, 240, 199, 145, 94,
                                           53,  27,  12,  5,   0};

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
  float BallPosition = getBallPosition_DHO();

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

      setPixelByStrandIndex(centerindex + k, scale8(color.r, attnFactor),
                            scale8(color.g, attnFactor),
                            scale8(color.b, attnFactor));
    }
  FastLED.show();
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
  float BallPosition = getBallPosition_DHO();

  int centerindex = (uint16_t((float)NUMPERSTRAND / 2.0) +
                     BallPosition * ((float)NUMPERSTRAND / 2.0));

  CRGB rainbowhue;
  for (int i = 0; i < NUMPERSTRAND; i++)
    {
      rainbowhue =
          CHSV(2 * centerindex + 255 * (i / ((float)NUMPERSTRAND)), 255, 255);
      setPixelByStrandIndex(i, rainbowhue);
    }
  FastLED.show();
}

///////////////////////////////////////////////////////
// DHO FADE
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
  float BallPosition = getBallPosition_DHO();

  // about 7 ms
  fadeWholeStrip((uint8_t)FADE_COEF);

  // < 0 ms
  setPixelByStrandIndex(ballToStrandPosition_DHO(BallPosition), color);

  /*  Serial.print("\tBallPosiition:\t");
    Serial.print(BallPosition);
    Serial.print("\tPixel Index:\t");
    Serial.println(temp);
    */

  // about 1 ms
  FastLED.show();
}

///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
////////////// UNUSED /////////////////
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////

// 5
//////////// DHO SINE STRIPES
////////////////////////////////////////////////////////////////////////////////////////

// FOR DHO_SineStripes
/*
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
  float BallPosition = getBallPosition_DHO();
  FastLED.clear();
  int centerindex =
      NUMPERSTRAND -
      (NUMPERSTRAND / 2.0f + ballToStrandPosition_DHO(BallPosition)) - 1;
  float attnFactor;
  for (int k = -NUMPERSTRAND; k <= NUMPERSTRAND; k++)
    {
      attnFactor =
          (float)(((float)pgm_read_byte_near(sinTable + k + NUMPERSTRAND)));
          Serial.print("attnFactor: ");
          Serial.println(attnFactor);
                Serial.print("k: ");
          Serial.println(k);*
      setPixelByStrandIndex(centerindex + k, scale8(color.r, attnFactor),
                            scale8(color.g, attnFactor),
                            scale8(color.b, attnFactor));
    }
  FastLED.show();
}
*/

/*
//////////////// DHO COMET (not currently working)
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
  pos_history[0] = ballToStrandPosition_DHO(getBallPosition_DHO());
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
        if (counter == 0)
          {
            Serial.print(pos_history[i]);
            Serial.print("/");
            Serial.print(fade);
            Serial.print("/");
            Serial.print((uint8_t)(fade * 60.0f));
            Serial.print("\t");
          }
    }
   if (counter == 0)
      {
        Serial.println("");
      }
  FastLED.show();
}
*/