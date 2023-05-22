#include <parameters.h>
#include <function_declarations_and_globals.h>

uint32_t time_start = millis();
uint32_t time_now = millis();
uint16_t time_interval = 0;

float time_ramp(float period)
{
    time_now = millis();
    float time_interval = time_now - time_start;
    if (time_interval > period)
    {
        time_start = time_now;
    }
    float ramp = (float)time_interval / ((float)period);
    // Serial.print(time_interval);
    // Serial.print("\t");
    // Serial.println(ramp);
    return ramp;
}

uint16_t addmod(uint16_t a, uint16_t b, uint32_t mod)
{
    uint16_t am = a % mod;

    uint16_t bm = b % mod;

    // If `mod`, `a`, and `b` are very large, just returning `(am + bm) % mod` could overflow
    uint16_t diff = mod - bm;

    if (diff < am)
    { // aka if (am + bm > mod)
        // Since am < mod and bm < mod, am + bm < 2 * mod.  In this specific case mod < am + bm < 2 * mod,
        // so we have the identity am + bm % mod = am - mod + bm
        return am - diff;
    }
    return am + bm;
}

// modular multiplication which avoids overflow.  Takes O(log(a)) iterations.
uint16_t mulmod(uint32_t a, uint32_t b, uint32_t mod)
{
    uint16_t res = 0;

    if (b == 0)
        return 0;

    while (a != 0)
    {
        if (a & 1)
        {
            res = addmod(res, b, mod);
        }
        // double a and half b.
        a >>= 1;

        b = addmod(b, b, mod);
    }
    return res;
}

// This is the BSD rand() from https://rosettacode.org/wiki/Linear_congruential_generator
uint16_t prng_state = 0;

uint16_t mulres = 0;

uint16_t mod = 65536;

float prng(float max)
{
    mulres = mulmod(1103515245, prng_state, 65536);

    prng_state = addmod(mulmod(1103515245, prng_state, 65536 /*mod*/), 12345, 65536 /*mod*/);

    //  Serial.print(mulres);
    //  Serial.print("\t");
    //  Serial.print(prng_state);
    //  Serial.print("\t");
    //  Serial.print(max);
    //  Serial.print("\t");
    //  Serial.println((prng_state / 65536.0) * max, 6);

    return (prng_state / 65536.0) * max; // 65536 = mod
}

float adjusts[NUMPERSTRAND];
float sparkliness = 0;
float scale = 0;
uint16_t period = 0;

void SYNCRANDNUM_main_program(void)
{
    switch (settingIndex)
    {

    case 0:
    {

        sparkliness = SYNCRANDNUM_SPARKLINESS_SETT_0;
        scale = SYNCRANDNUM_SCALE_SETT_0;
        period = SYNCRANDNUM_RAMP_PERIOD_SETT_0;
        // Serial.println("Syncrandnum setting\t0");
        break;
    };

    case 1:
    {
        sparkliness = SYNCRANDNUM_SPARKLINESS_SETT_1;
        scale = SYNCRANDNUM_SCALE_SETT_1;
        period = SYNCRANDNUM_RAMP_PERIOD_SETT_1;
        // Serial.println("Syncrandnum setting\t1");
        break;
    };

    case 2:
    {
        sparkliness = SYNCRANDNUM_SPARKLINESS_SETT_2;
        scale = SYNCRANDNUM_SCALE_SETT_2;
        period = SYNCRANDNUM_RAMP_PERIOD_SETT_2;
        // Serial.println("Syncrandnum setting\t2");
        break;
    };

    default:
    {
        settingIndex = 0;
        Serial.print(F("Setting index set to:\t"));
        Serial.println(settingIndex);
    };
    };

    float ramp = time_ramp(period);

    for (uint16_t i = 0; i < NUMPERSTRAND; ++i)
    {
        adjusts[i] += prng(sparkliness) - sparkliness / 2;
        // Serial.print(adjusts[i]);
        // Serial.print("\t");
        // Serial.print(prng(sparkliness));
        // Serial.print("\t");
        // Serial.println(sparkliness);
    }

    for (uint16_t index = 0; index < NUMPERSTRAND; index++)
    {

        //   Serial.print(sparkliness);
        //   Serial.print("\t");
        //   Serial.print(scale);
        //   Serial.print("\t");
        //   Serial.println(period);

        uint16_t color_h = 65536 * (ramp + scale * index / ((float)NUMPERSTRAND) + adjusts[index]);
        uint16_t color_s = 255 - 255 * gflash_factor;

        // Serial.print(gflash_active);
        // Serial.print("\t");
        // Serial.print(acc_g_z);
        // Serial.print("\t");
        // Serial.print(gflash_factor);
        // Serial.print("\t");
        // Serial.println(color_s);

        // Serial.print(color_h);
        // Serial.print("\t");
        // Serial.print(ramp);
        // Serial.print("\t");
        // Serial.print(index / ((float)NUMPERSTRAND));
        // Serial.print("\t");
        // Serial.println(adjusts[index]);

        uint32_t the_color = strip.ColorHSV(color_h, color_s, 50);
        //the_color = strip.gamma32(color_h);
        COMMON_SetPixelByStrandIndex(index, the_color);
    }
    strip.show();
}
