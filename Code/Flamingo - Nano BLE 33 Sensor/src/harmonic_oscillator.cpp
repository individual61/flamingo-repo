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
    // uint16_t strand_index = (uint16_t)round(NUMPERSTRAND / 2.0) + (x / ((float)(DHO_STRAND_LENGTH_M / 2.0))) * (NUMPERSTRAND / 2.0);
    uint16_t strand_index = (uint16_t)round(NUMPERSTRAND / 2.0 + (x / ((float)(DHO_STRAND_LENGTH_M / 2.0))) * (NUMPERSTRAND / 2.0));
    return strand_index;
}

double DHO_send_interval = 50.0;
double DHO_sent_last = 0.0;
/*
       counter++;
       if (counter == 0)
       {
           Serial.println(time_interval_us);
       }

*/

// uint32_t time1 = 0;
// uint32_t time2 = 0;
// uint32_t time3 = 0;

// 13.3 ms to update all leds on flamingo
void DHO_main_program(void)
{
    uint16_t the_index = DHO_get_strand_index_from_x(DHO_update_position());

    // time1 = micros();
    strip.clear();

    //Serial.print(DHO_COLOR, HEX);
    //Serial.print("\t");
    //uint32_t color_hue = strip.ColorHSV(80000, 255, 255);
    //Serial.println((uint32_t) color_hue, HEX);

    COMMON_SetPixelByStrandIndex(the_index, strip.ColorHSV(PINK_HUE, 255, DHO_MAX_BRIGHTNESS));



    // time2 = micros();
    strip.show();
    // time3 = micros();
    // Serial.print(time2 - time1);
    // Serial.print("\t");
    // Serial.println(time3 - time2);

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
