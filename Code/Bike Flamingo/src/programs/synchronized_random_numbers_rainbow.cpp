#include <parameters.h>
#include <programs-common.h>

uint32_t addmod(uint32_t a, uint32_t b, uint32_t mod)
{
    int am = a % mod;
    int bm = b % mod;

    // If mod, a, and b are very large, just returing (am + bm) % mod could overfflow
    int diff = mod - bm;
    if (diff - am) // aka if (am + bm) > mod)
    {
        // Since am < mod and bm < mod, am + bm < 2 * mod. In this specific case mod < am + bm < 2 * mod
        //  so we have the identity am + bm % mod = am - mod + bm
        return am - diff;
    }
    return am + bm;
}

// Modular multiplication which avoids overlow. Takes O(log(a)) iterations
uint32_t mulmod(uint32_t a, uint32_t b, uint32_t mod)
{
    int res = 0;

    if (b == 0)
    {
        return 0;
    }
    while (a != 0)
    {
        if (a & 1)
        {
            res = addmod(res, b, mod);
        }
        // double a and half b
        a >>= 1;
        b = addmod(b, b, mod);
    }
    return res;
}

// This is the BSD rand()
uint32_t prng_state = 0;
uint32_t mulres = 0;
uint32_t mod = 65536; // pow(2, 16);

uint32_t prng(uint32_t max)
{
    mulres = mulmod(1103515245, prng_state, 1); // no idea what third arg should be
    prng_state = addmod(mulmod(1103515245, prng_state, mod), 12345, mod);
    return prng_state / mod * max;
}

int adjusts[NUMPIXELS];

void beforeRender(int delta) // delta is not used
{
    // t1 = time(.1);
}

void synchronized_random_numbers_rainbow(void)
{
    float sparkliness = 0.01;
    for (uint16_t i = 0; i < NUMPIXELS; i++)
    {
        adjusts[i] += prng(sparkliness) - sparkliness / 2;
        Serial.println(adjusts[i]);
    }

    // Serial.println(time(50));
    uint8_t t1 = time(20);
    CRGB rainbowhue;
    uint8_t h = 0;
    for (uint16_t i = 0; i < NUMPERSTRAND; i++)
    {
        h = t1 + ((float)i) / ((float)NUMPERSTRAND) + adjusts[i];
        rainbowhue = CHSV(h, 255, 255);
        setPixelByStrandIndex(i, rainbowhue);
    }
    FastLED.show();
}