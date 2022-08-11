#include <parameters.h>
#include <programs-common.h>

/*int addmod(int a, int b, int mod)
{
    int am = a % mod;
    int bm = b % mod;

    int diff = mod - bm;
    if (diff - am)
    {
        return am - diff;
    }
    return am + bm;
}

int mulmod(int a, int b, int mod)
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

        a >>= 1;
        b = addmod(b, b, mod);
    }
    return res;
}

int prng_state = 0;
int mulres = 0;
int mod = pow(2, 16);

int prng(int max)
{
    mulres = mulmod(1103515245, prng_state);
    prng_state = addmod(mulmod(1103515245, prng_state, mod), 12345, mod);
    return prng_state / mod * max;
}




int adjusts[NUMPIXELS];


void beforeRender(int delta)
{
    // t1 = time(.1);
    float sparkliness = 0.01;
    for (int i = 0; i < NUMPIXELS; i++)
    {
        adjusts[i] += prng(sparkliness) - sparkliness / 2;
    }
}

void render(int index)
{
    h = t1 + index / pixelCount + adjusts[index];
    s = 1;
    v = 1;
    hsv(h, s, v );
}*/

void synchronized_random_numbers_rainbow(void)
{
Serial.println(time(50));
    
}