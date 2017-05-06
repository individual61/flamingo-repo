#include <harmonic_oscillator.h>
#include <parameters.h>


float pos0, pos1, vel0, vel1, acc0, acc1, acc_ext;

uint16_t timeold_i = 0;
uint16_t timenow_i = 0;
float timenow_f = 0.0;
float timestep_f = 0.0;
float timestep_i = 0; // check how this is used, name suggests int but decl is float

bool first_iter = 0;
// uint16_t sendTime = 0;  // currently in a commented out section


//////// DAMPED HARMONIC OSCILLATOR FUNCTIONS ///////////////

float eval_v_func(float v, float x, float acc_ext)
{
  return -DAMPING * v - SPRINGCONSTANT * x + acc_ext; // return (-c*v -sin(x) + F*cos(w*t));
}

// Integrates acceleration to get velocity
float get_next_v(float oldv, float oldx, float acc_ext)
{
  float k1, k2, k3, k4;
  k1 = eval_v_func(oldv,          oldx, acc_ext);
  k2 = eval_v_func(oldv + 0.5 * k1, oldx, acc_ext);
  k3 = eval_v_func(oldv + 0.5 * k2, oldx, acc_ext);
  k4 = eval_v_func(oldv + k3,     oldx, acc_ext);
  return (float)(oldv + timestep_f * (  (k1 / 6.0) + (k2 / 3.0) + (k3 / 3.0) + (k4 / 6.0)  ));
}

//integrates velocity to get position
float get_next_x(float oldv, float oldx)
{
  return (float)(oldx + timestep_f * oldv);
}

// DAMPED HARMONIC OSCILLATOR. Returns object position as a fraction of max range,
// centered on 0, so maxrange is half the length of the strip
float getBallPosition(void)
{
  if (first_iter == 1) // first iteration
  {
    pos0 = 0.0;
    vel0 = 0.0;
    timeold_i = 0;
    timenow_i = 0;
    timestep_i = timenow_i - timeold_i;
    timestep_f = 0.01 * ((float)timestep_i);

    acc_ext = getOffsetAccel();
    vel1 = get_next_v(vel0, pos0, acc_ext);
    pos1 = get_next_x(vel0, pos0);

    timeold_i = timenow_i;
    pos0 = pos1;
    vel0 = vel1;

    first_iter = 0;
    timeold_i = millis();
  }
  else
  {
    timenow_i = millis();
    timestep_i = timenow_i - timeold_i;
    timestep_f = 0.01 * ((float)timestep_i);

    acc_ext = getOffsetAccel();
    vel1 = get_next_v(vel0, pos0, acc_ext);
    pos1 = get_next_x(vel0, pos0);
    vel0 = vel1;
    pos0 = pos1;
    timeold_i = timenow_i;

    /*    uint16_t timet = millis();
        if (timet - sendTime > 100)
        {
            #ifndef PLOT
            Serial.print("Timestep:\t");
            Serial.print(timestep_i);
            Serial.print("\tPosition:\t");
            Serial.print(pos1);
            Serial.print("\tVel:\t");
            Serial.print(vel1);
            Serial.print("\tAcc ext:\t");
            Serial.println(acc_ext);
            #else
            Serial.println(pos1);
            //      Serial.print(",");
            //      Serial.println(acc_ext);
            #endif
          sendTime = timet;
        }
    */
  }
  return pos1 / MAXRANGE;
}

int ballToStrandPosition(float ballPos)
{
  return ((int)(ballPos * ((float) NUMPERSTRAND / 2.0)));
}
