#include <parameters.h>
#include <function_declarations_and_globals.h>

//////// BOUNCING BALL FUNCTIONS ///////////////

// acc_ext is generally negative when Flamingo is upright.
//
// m x'' =                       F_ext
//
//   x'' =                       F_ext/m
//
//              but v' = x''
//
//    v' =                       F_ext/m
//
//             also F_ext = m acc_ext
//
//    v' =                       acc_ext
//
//           Integrate this to get v(t). Then
//
//    x' = v(t)
//
//           Integrate this to get x(t).
//

// BB_eval_v_func
// Returns the value of the RHS of v' so we can get v
//
//  v' =                         acc_ext
//

double BB_xx, BB_vv;
uint32_t BB_color = 0x601040;

double BB_f(double x, double v, double t, double a_ext)
{
    // function for the acceleration of the bouncing ball
    double f_damping = -BB_DAMPING * v;
    return (f_damping + BB_MASS * a_ext) / BB_MASS;
}

// t is not used
void BB_rk4(double &x, double &v, double t, double acc_ext, double dt)
{
    // implementation of the Runge-Kutta 4th order method
    double k1 = dt * v;
    double l1 = dt * BB_f(x, v, t, acc_ext);
    double k2 = dt * (v + 0.5 * l1);
    double l2 = dt * BB_f(x + 0.5 * k1, v + 0.5 * l1, t + 0.5 * dt, acc_ext);
    double k3 = dt * (v + 0.5 * l2);
    double l3 = dt * BB_f(x + 0.5 * k2, v + 0.5 * l2, t + 0.5 * dt, acc_ext);
    double k4 = dt * (v + l3);
    double l4 = dt * BB_f(x + k3, v + l3, t + dt, acc_ext);

    BB_xx += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
    BB_vv += (l1 + 2.0 * l2 + 2.0 * l3 + l4) / 6.0;
}

double BB_update_position(void)
{
    double acc_ext = -BB_G_ACC_MAGNITUDE * acc_g_z;
    double time_interval_s = (double)(time_interval_us / 1000000.0);

    if (first_program_run)
    {
        BB_xx = 0.3;
        BB_vv = 0.0;

        //        Serial.print(acc_g_z, 8);
        //        Serial.print("\t");
        //        Serial.println("first program run");
    }

    //    Serial.print(first_program_run);
    //    Serial.print("\t");
    //    Serial.print(BB_xx);
    //    Serial.print("\t");
    //    Serial.print(BB_vv);
    //    Serial.print("\t\t");

    BB_rk4(BB_xx, BB_vv, 0.0, acc_ext, time_interval_s);

    //    Serial.print(BB_xx);
    //    Serial.print("\t");
    //    Serial.println(BB_vv);

    if (BB_xx < 0.0)
    {
        Serial.println("Bounce");
        BB_xx = 0.0;
        BB_vv = BB_BOUNCE_COEF * fabs(BB_vv);
    }

    return BB_xx;
}

uint16_t BB_get_strand_index_from_x(float x)
{
    // uint16_t strand_index = (uint16_t)round(NUMPERSTRAND / 2.0) + (x / ((float)(BB_STRAND_LENGTH_M / 2.0))) * (NUMPERSTRAND / 2.0);

    // Note that this returns a signed LED index
    uint16_t strand_index = (uint16_t)floor((x / ((float)(BB_STRAND_LENGTH_M))) * (NUMPERSTRAND));
    Serial.print(x);
    Serial.print("\t");
    Serial.println(strand_index);
    return strand_index;
}

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void BB_setPixelByStrandIndex(uint16_t index)
{
    strip.clear();

    if ((index >= 0) && (index < NUMPERSTRAND))
    {
        // index goes from 0 to NUMPERSTRAND - 1
        uint8_t realindex = 0;

#if NUM_STRANDS == 1
        realindex = index;
        strip.setPixelColor(realindex, BB_color);

#endif

#if NUM_STRANDS == 3
        // NUMPERSTRAND - 1
        // 0
        realindex = NUMPERSTRAND - index - 1;
        strip.setPixelColor(realindex, BB_color);
        // Serial.print(realindex);
        // Serial.print("\t");

        // NUMPERSTRAND
        // 2*NUMPERSTRAND - 1
        realindex = NUMPERSTRAND + index;
        strip.setPixelColor(realindex, BB_color);
        // Serial.print(realindex);
        // Serial.print("\t");

        // 3*NUMPERSTRAND - 1
        // 2*NUMPERSTRAND
        realindex = 3 * NUMPERSTRAND - index - 1;
        strip.setPixelColor(realindex, BB_color);
        // Serial.println(realindex);
#endif
    }
    strip.show();
}

double BB_send_interval = 50.0;
double BB_sent_last = 0.0;

void BB_main_program(void)
{
    uint16_t the_index = BB_get_strand_index_from_x(BB_update_position());

    BB_setPixelByStrandIndex(the_index);

    // uint32_t timet = millis();
    // if (timet - BB_sent_last > BB_send_interval)
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

    //    BB_sent_last = timet;
    //}
}
