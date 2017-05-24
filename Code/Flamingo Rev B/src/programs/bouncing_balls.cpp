#include <parameters.h>
#include <programs-common.h>

bool first_iter_BB = 0;

bouncingball balls[NUM_BOUNCYBALLS];

float eval_v_func_BB(float v, float x, float acc_ext, float damping, float mass)
{
  // acc_ext is generally negative when Flamingo is upright.
  // m x'' = - c v + F_ext
  // with F_ext = m acc_ext
  return -damping * v + mass * acc_ext;
}

// Integrates acceleration to get velocity for DHO
float get_next_v_BB(float oldv, float oldx, float acc_ext, float damping,
                    float mass)
{
  float k1, k2, k3, k4;
  k1 = eval_v_func_BB(oldv, oldx, acc_ext, damping, mass);
  k2 = eval_v_func_BB(oldv + 0.5 * k1, oldx, acc_ext, damping, mass);
  k3 = eval_v_func_BB(oldv + 0.5 * k2, oldx, acc_ext, damping, mass);
  k4 = eval_v_func_BB(oldv + k3, oldx, acc_ext, damping, mass);
  return (float)(oldv + timestep_f * ((k1 / 6.0) + (k2 / 3.0) + (k3 / 3.0) +
                                      (k4 / 6.0)));
}

// for BB, 0.0 is the bottom
int ballToStrandPosition_BB(float ballPos_BB)
{
  return ballPos_BB * (NUMPERSTRAND);
};

// Bouncing Ball, real physical units. Returns object position as a
// float. Resting location is at 0.0
void updateBallPosition_BB(bouncingball* theBall, float damping)
{
  if (first_iter_BB == 1)  // first iteration
    {
      timenow_i = 0;
      timestep_i = timenow_i - timeold_i;
      timeold_i = millis();  // why is this timeold and not timenow? I moved
                             // this from below btw
      timestep_f = 0.01 * ((float)timestep_i);

      // getNormalizedAccelY() is negative when Flamingo is upright.
      // getNormalizedAccelY() returns normalized acc in units of g
      // Right side up: 1.0
      // Upside Down:   -1.0
      acc_ext =
          G_ACC_MAGNITUDE_BB * getNormalizedAccelY();  // lowered g as a kluge
      vel1 = get_next_v_BB(theBall->velocity, theBall->position, acc_ext,
                           damping, theBall->mass);
      pos1 = get_next_x(theBall->velocity, theBall->position);

      timeold_i = timenow_i;
      theBall->position = pos1;
      theBall->velocity = vel1;

      first_iter_BB = 0;
    }
  else
    {
      timenow_i = millis();
      timestep_i = timenow_i - timeold_i;
      timestep_f = 0.01 * ((float)timestep_i);

      // acc_ext is generally negative because getNormalizedAccelY() returns
      // negative when Flamingo is upright.
      // G_ACC_MAGNITUDE_BB is positive.
      acc_ext = G_ACC_MAGNITUDE_BB * getNormalizedAccelY();
      vel1 = get_next_v_BB(theBall->velocity, theBall->position, acc_ext,
                           damping, theBall->mass);
      pos1 = get_next_x(theBall->velocity, theBall->position);
      theBall->velocity = vel1;
      theBall->position = pos1;
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
                    (pos1 / (MASS_REAL * G_ACC_MAGNITUDE_BB /
         SPRINGCONSTANT_REAL)) + 1.0); Serial.print(F("\tPixel Index:\t"));
                Serial.print(ballToStrandPosition(
                    (pos1 / (MASS_REAL * G_ACC_MAGNITUDE_BB /
         SPRINGCONSTANT_REAL)) + 1.0));
         Serial.print(F("\tgetNormalizedAccelY:\t"));
                Serial.print(getNormalizedAccelY());
                Serial.print(F("\tgetNormalizedOffsetAccelY:\t"));
                Serial.println(getNormalizedOffsetAccelY());

                sendTime = timet;
              }
      */
    }
}

void Bouncing_Balls()
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tDHO_SinglePixel"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());

      balls[0].position = 0.0;
      balls[0].mass = 2;
      balls[0].velocity = 0.0;
      balls[0].colour = CRGB(255, 0, 0);

      balls[1].position = 1.0;
      balls[1].mass = 2;
      balls[1].velocity = 0.0;
      balls[1].colour = CRGB(0, 0, 255);

      balls[2].position = 1.0;
      balls[2].mass = 2;
      balls[2].velocity = 0.0;
      balls[2].colour = CRGB(0, 255, 0);
    }

  FastLED.clear();

  // Run over balls and update their positions
  for (int i = 0; i < NUM_BOUNCYBALLS; i++)
    {
      updateBallPosition_BB(&(balls[i]), BB_DAMPING);

      // make the balls bounce
      if (balls[i].position < 0.0)
        {
          balls[i].position = 0.0;  // hopefully it won't look too weird if the
                                    // ball gets placed way below 0.0 and this
                                    // returns it there.
          balls[i].velocity =
              0.8 *
              fabs(balls[i].velocity);  // none of that sign change stuff. Don't
                                        // want to risk that position is
                                        // negative two iterations in a row.
        }

      setPixelByStrandIndex(ballToStrandPosition_BB(balls[i].position),
                            balls[i].colour);

    }  // all ball positions and strands have been updated

  FastLED.show();
}
