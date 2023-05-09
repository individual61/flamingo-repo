#include <parameters.h>
#include <function_declarations_and_globals.h>

//////// DAMPED HARMONIC OSCILLATOR FUNCTIONS ///////////////

// acc_ext is generally negative when Flamingo is upright.
//
// m x'' = - k x     -     c v + F_ext
//
//   x'' = - (k/m) x - (c/m) v + F_ext/m
//
//              but v' = x''
//
//    v' = - (k/m) x - (c/m) v + F_ext/m
//
//             also F_ext = m acc_ext
//
//    v' = - (k/m) x - (c/m) v + acc_ext
//
//           Integrate this to get v(t). Then
//
//    x' = v(t)
//
//           Integrate this to get x(t).
//

// DHO_eval_v_func
// Returns the value of the RHS of v' so we can get v
//
//  v' = - (k/m) x - (c/m) v + acc_ext
//

double DHO_xx, DHO_vv;
uint32_t DHO_color = 0x601040;

double DHO_f(double x, double v, double t, double a_ext)
{
    // function for the acceleration of the damped harmonic oscillator
    double f_spring = -DHO_SPRINGCONSTANT * x;
    double f_damping = -DHO_DAMPING * v;
    return (f_spring + f_damping + DHO_MASS * a_ext) / DHO_MASS;
}

// t is not used
void DHO_rk4(double &x, double &v, double t, double acc_ext, double dt)
{
    // implementation of the Runge-Kutta 4th order method
    double k1 = dt * v;
    double l1 = dt * DHO_f(x, v, t, acc_ext);
    double k2 = dt * (v + 0.5 * l1);
    double l2 = dt * DHO_f(x + 0.5 * k1, v + 0.5 * l1, t + 0.5 * dt, acc_ext);
    double k3 = dt * (v + 0.5 * l2);
    double l3 = dt * DHO_f(x + 0.5 * k2, v + 0.5 * l2, t + 0.5 * dt, acc_ext);
    double k4 = dt * (v + l3);
    double l4 = dt * DHO_f(x + k3, v + l3, t + dt, acc_ext);

    DHO_xx += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
    DHO_vv += (l1 + 2.0 * l2 + 2.0 * l3 + l4) / 6.0;
}

double DHO_update_position(void)
{
    double acc_ext = -DHO_G_ACC_MAGNITUDE * (acc_g_z - 1.0);
    double time_interval_s = (double)(time_interval_us / 1000000.0);

    if (first_program_run)
    {
        DHO_xx = 0.3;
        DHO_vv = 0.0;

        //        Serial.print(acc_g_z, 8);
        //        Serial.print("\t");
        //        Serial.println("first program run");
    }

    DHO_rk4(DHO_xx, DHO_vv, 0.0, acc_ext, time_interval_s);
    return DHO_xx;
}

uint16_t DHO_get_strand_index_from_x(float x)
{
    // Fixed round() scope
    //uint16_t strand_index = (uint16_t)round(NUMPERSTRAND / 2.0) + (x / ((float)(DHO_STRAND_LENGTH_M / 2.0))) * (NUMPERSTRAND / 2.0);
    uint16_t strand_index = (uint16_t)round(NUMPERSTRAND / 2.0 + (x / ((float)(DHO_STRAND_LENGTH_M / 2.0))) * (NUMPERSTRAND / 2.0));
    return strand_index;
}

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void DHO_setPixelByStrandIndex(uint16_t index)
{
    strip.clear();

    if ((index >= 0) && (index < NUMPERSTRAND))
    {
        // index goes from 0 to NUMPERSTRAND - 1
        uint8_t realindex = 0;

#if NUM_STRANDS == 1
        realindex = index;
        strip.setPixelColor(realindex, DHO_color);

#endif

#if NUM_STRANDS == 3
        // NUMPERSTRAND - 1
        // 0
        realindex = NUMPERSTRAND - index - 1;
        strip.setPixelColor(realindex, DHO_color);
        // Serial.print(realindex);
        // Serial.print("\t");

        // NUMPERSTRAND
        // 2*NUMPERSTRAND - 1
        realindex = NUMPERSTRAND + index;
        strip.setPixelColor(realindex, DHO_color);
        // Serial.print(realindex);
        // Serial.print("\t");

        // 3*NUMPERSTRAND - 1
        // 2*NUMPERSTRAND
        realindex = 3 * NUMPERSTRAND - index - 1;
        strip.setPixelColor(realindex, DHO_color);
        // Serial.println(realindex);
#endif
    }
    strip.show();
}

double DHO_send_interval = 50.0;
double DHO_sent_last = 0.0;

void DHO_main_program(void)
{
    uint16_t the_index = DHO_get_strand_index_from_x(DHO_update_position());

    DHO_setPixelByStrandIndex(the_index);

    // uint32_t timet = millis();
    // if (timet - DHO_sent_last > DHO_send_interval)
    //{
    /*      Serial.print(the_index);
            Serial.print("\t");
            Serial.print("0.0");
            Serial.print("\t");
            Serial.println("48.0"); */

    /*      double time_interval_ms = (double)(time_interval_us / 1000.0);
            Serial.print(the_position, 8);
            Serial.print("\t");
            Serial.print(acc_g_z, 8);
            Serial.print("\t");
            Serial.print(time_interval_ms, 8);
            Serial.print("\t");
            Serial.print(0.5);
            Serial.print("\t");
            Serial.println(-0.5); */

    //    DHO_sent_last = timet;
    //}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/* Previous attempt, probably borked (diverges)
//Put these in first run
        x_old = 0.0;
        v_old = 0.0;
        x_new = 0.0;
        v_new = 0.0;

double x_old, x_new, v_old, v_new;

double DHO_evaluate_v_prime(double v, double x, double acc_ext, double damping, double springconstant, double mass)
{
    return -(springconstant / mass) * x - (damping / mass) * v + acc_ext;
}

// Integrates acceleration to get velocity for DHO
//
double DHO_get_next_v(double oldv, double oldx, double acc_ext, double damping, double springconstant, double mass, double timestep_f)
{
    double k1, k2, k3, k4;
    k1 = DHO_evaluate_v_prime(oldv, oldx, acc_ext, damping, springconstant, mass);
    k2 = DHO_evaluate_v_prime(oldv + 0.5 * k1, oldx, acc_ext, damping, springconstant, mass);
    k3 = DHO_evaluate_v_prime(oldv + 0.5 * k2, oldx, acc_ext, damping, springconstant, mass);
    k4 = DHO_evaluate_v_prime(oldv + k3, oldx, acc_ext, damping, springconstant, mass);
    return (double)(oldv + timestep_f * ((k1 / 6.0) + (k2 / 3.0) + (k3 / 3.0) + (k4 / 6.0)));
}

// integrates velocity to get position
double DHO_get_next_x(double oldv, double oldx, double timestep_f)
{
    return (double)(oldx + timestep_f * oldv);
}
*/

/*
int DHO_ballToStrandPosition(float ballPos_DHO)
{
  return (NUMPERSTRAND / 2) + ballPos_DHO * (NUMPERSTRAND / 2);
};
*/

// DAMPED HARMONIC OSCILLATOR, real physical units. Returns object position as a
// float, centered on 0, so maxrange is half the length of the strip.  Resting
// location is at 0.0

/*
float DHO_getBallPosition_DHO(void)
{
    if (first_iter == 1) // first iteration
    {
        pos0 = 0.0;
        vel0 = 0.0;
        timenow_i = 0;
        timestep_i = timenow_i - timeold_i;
        timeold_i = millis(); // why is this timeold and not timenow? I moved
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

*/
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
/*  }
 // Resting location is at 0.0


 float temp =
     (pos1 / (MASS_REAL * G_ACC_MAGNITUDE / SPRINGCONSTANT_REAL)) + 1.0;

 return temp;
}

*/