#include <parameters.h>
#include <programs-common.h>

// This program is on hold. Ball bounces too slowly, velocity of second
// iteration is
bouncingball balls[NUM_BOUNCYBALLS];

float eval_v_func_BB(float v, float x, float acc_ext, float damping, float mass)
{
  // acc_ext is generally negative when Flamingo is upright.
  // m x'' = - c v + F_ext
  // with F_ext = m acc_ext
  return -damping * v / mass + acc_ext;
}

// Integrates acceleration to get velocity for DHO
float get_next_v_BB(float timestep_f, float oldv, float oldx, float acc_ext,
                    float damping, float mass)
{
  float k1, k2, k3, k4;
  k1 = eval_v_func_BB(oldv, oldx, acc_ext, damping, mass);
  k2 = eval_v_func_BB(oldv + 0.5 * k1, oldx, acc_ext, damping, mass);
  k3 = eval_v_func_BB(oldv + 0.5 * k2, oldx, acc_ext, damping, mass);
  k4 = eval_v_func_BB(oldv + k3, oldx, acc_ext, damping, mass);
  return (float)(oldv + timestep_f * ((k1 / 6.0) + (k2 / 3.0) + (k3 / 3.0) +
                                      (k4 / 6.0)));
}

// integrates velocity to get position
float get_next_x_BB(float timestep_f, float oldv, float oldx)
{
  return (float)(oldx + timestep_f * oldv);
}

// for BB, 0.0 is the bottom
int ballToStrandPosition_BB(float ballPos_BB)
{
  // return ballPos_BB * (NUMPERSTRAND);

  return ballPos_BB;
};

// Bouncing Ball, real physical units. Returns object position as a
// float. Resting location is at 0.0
void updateBallPosition_BB(bouncingball* theBall, float damping)
{
  //  Serial.print(theBall->timenow);
  //  Serial.print("\t");
  //  Serial.println(timestep_f_BB);

  // acc_ext is generally negative because getNormalizedAccelY() returns
  // negative when Flamingo is upright.
  // G_ACC_MAGNITUDE_BB is positive.
  float acc_ext = G_ACC_MAGNITUDE_BB * getNormalizedAccelY(); // Added type def

  theBall->timenow = millis();
  float timestep_i_BB = theBall->timenow - theBall->timeold;
  float timestep_f_BB = 0.001 * ((float)timestep_i_BB);
  float vel1 = get_next_v_BB(timestep_f_BB, theBall->velocity, theBall->position,
                       acc_ext, damping, theBall->mass);
  float pos1 = get_next_x_BB(timestep_f_BB, theBall->velocity, theBall->position);
  theBall->velocity = vel1;
  theBall->position = pos1;
  theBall->timeold = theBall->timenow;
}

void Bouncing_Balls(bool BB_fade)
{
  if (firstRun)
    {
      FastLED.clear();
      firstRun = 0;
      Serial.println(F("Starting Program:\tBouncing Balls"));
      Serial.print(F("Free SRAM:  "));
      Serial.println(freeRam());

      balls[0].position = 24.0;
      balls[0].mass = 1.0;
      balls[0].velocity = 0.0;
      balls[0].timenow = 1;
      balls[0].timeold = 1;
      balls[0].colour = CHSV(220, 255, 255);
      /*
            balls[1].position = 12.0;
            balls[1].mass = 1.0;
            balls[1].velocity = 0.0;
            balls[1].timenow = 1;
            balls[1].timeold = 1;
            balls[1].colour = CHSV(190, 255, 255);
      */
      /*      balls[1].position = 40;
            balls[1].mass = 1.0;
            balls[1].velocity = 0.0;
            balls[1].timenow = 1;
            balls[1].timeold = 1;
            balls[1].colour = CHSV(220, 255, 255);
      */
      // Run over balls and update their positions
      for (int i = 0; i < NUM_BOUNCYBALLS; i++)
        {
          updateBallPosition_BB(&(balls[i]), BB_DAMPING);
          balls[i].velocity = 0.0;
        }
    }

  if (BB_fade == 0)
    {
      FastLED.clear();
    }

  // Run over balls and update their positions
  for (int i = 0; i < NUM_BOUNCYBALLS; i++)
    {
      updateBallPosition_BB(&(balls[i]), BB_DAMPING);
      // make the balls bounce
      if (balls[i].position < 0.0)
        {
          //      balls[i].position = 0.0;  // hopefully it won't look too weird
          //      if the
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

  if (BB_fade == 1)
    {
      fadeWholeStrip((uint8_t)FADE_COEF);
    }
  FastLED.show();
}
