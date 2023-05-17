#include <parameters.h>
#include <function_declarations_and_globals.h>

/*

uint16_t addmod(uint16_t a, uint16_t b, uint16_t mod)
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
uint16_t mulmod(uint16_t a, uint16_t b, uint16_t mod)
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

uint16_t mod = pow(2, 16);

uint16_t prng(max)
{
    mulres = mulmod(1103515245, prng_state);

    prng_state = addmod(mulmod(1103515245, prng_state, mod), 12345, mod);

    return prng_state / mod * max;
}

uint16_t adjusts[NUMPERSTRAND];

void beforeRender(uint16_t delta)
{
    t1 = time(.1)
        uint16_t sparkliness = 0.01 for (var i = 0; i < pixelCount; ++i)
    {
        adjusts[i] += prng(sparkliness) - sparkliness / 2;
    }
}

void render(uint16_t index)
{
    h = t1 + index / pixelCount + adjusts[index];
    s = 1 v = 1;
    hsv(h, s, v);
}
 */