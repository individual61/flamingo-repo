#include <parameters.h>
#include <function_declarations_and_globals.h>

// Returns a color in form 0x00RRGGBB using index from 0-65535
uint32_t FIRE_ColorFromPalette(uint8_t the_pal, uint16_t index)
{
    uint32_t color_to_return = 0x000000;

    if (the_pal == 1)
    {
        // An unsigned 16-bit value, 0 to 65535, representing one full
        //         loop of the color wheel, which allows 16-bit hues to "roll
        //         over" while still doing the expected thing

        // uint16_t hue = FIRE_RAINBOW_FIRST_HUE + (index * FIRE_RAINBOW_HUE_REPS /* * 65536*/); // / NUMPERSTRAND;
        // uint16_t hue = FIRE_RAINBOW_FIRST_HUE + (index * FIRE_RAINBOW_HUE_REPS  * 255); // / NUMPERSTRAND;
        uint16_t hue = FIRE_RAINBOW_FIRST_HUE + (index * FIRE_RAINBOW_HUE_REPS); // / NUMPERSTRAND;
        //        Serial.print(hue);
        // Serial.print("\t");
        color_to_return = strip.ColorHSV(hue, FIRE_RAINBOW_SATURATION, FIRE_RAINBOW_BRIGHTNESS);
        // color_to_return = strip.gamma32(color_to_return);
    }

    return color_to_return;
}

uint16_t FIRE_HueIndexFromPixelIndex(uint16_t index, uint16_t hue_start, uint16_t num_leds)
{
    uint16_t hue_index = hue_start + (index * FIRE_RAINBOW_HUE_REPS * 65536) / num_leds;
    // Serial.println(hue_index);
    return hue_index;
}

typedef struct spark
{
    uint8_t pixels_to_live = 0;
    uint8_t rate = 0;
    uint16_t position = 0;
} spark;
spark sparks[5];

uint32_t color_spark = 0;

void SetPixelByHeatColor(uint16_t Pixel, byte temperature, uint8_t style)
{ // Scale 'heat' down from 0-255 to 0-191
    // byte t192 = (byte) round((temperature / 255.0) * 191);
    uint8_t t192 = (byte)round((temperature / 255.0) * 191);

    // calculate ramp up from
    byte heatramp = t192 & 0x3F;
    // 0..63

    heatramp <<= 2;
    // scale up to 0..252

    uint32_t color_hot = 0;
    uint32_t color_mid = 0;
    uint32_t color_cold = 0;

    switch (style)
    {
    // Green Fire
    case 0:
    {
        color_hot = strip.Color(255, 255, heatramp);
        color_mid = strip.Color(heatramp, 255, 0);
        color_cold = strip.Color(0, heatramp, 0);
        color_spark = strip.Color(255, 255, 255);
        break;
    }

    // Pink Fire
    case 1:
    {
        color_hot = strip.Color(heatramp, 255, heatramp);
        color_mid = strip.Color(heatramp, 0, heatramp);
        color_cold = strip.Color(heatramp, 0, heatramp);
        color_spark = strip.Color(255, 255, 255);
        break;
    }

    case 2:
    {
        color_hot = strip.ColorHSV(FIRE_HueIndexFromPixelIndex(Pixel, FIRE_RAINBOW_FIRST_HUE, 0.6 * NUMPIXELS), 20, heatramp);
        color_mid = strip.ColorHSV(FIRE_HueIndexFromPixelIndex(Pixel, FIRE_RAINBOW_FIRST_HUE, 0.6 * NUMPIXELS), 200, heatramp);
        color_cold = strip.ColorHSV(FIRE_HueIndexFromPixelIndex(Pixel, FIRE_RAINBOW_FIRST_HUE, 0.6 * NUMPIXELS), 255, heatramp);
        color_spark = strip.ColorHSV(0, 0, 255);
        break;
    }

    default:
    {
        color_hot = strip.Color(255, 255, heatramp);
        color_mid = strip.Color(heatramp, 255, 0);
        color_cold = strip.Color(0, heatramp, 0);
        color_spark = strip.Color(255, 255, 255);
    }
    };

    // figure out which third of the spectrum we're in:
    if (t192 > 0x80)
    { // hottest
        COMMON_SetPixelByStrandIndex(Pixel, color_hot);
        // Serial.print("\thot");
        // Serial.println(t192);
    }
    else if (t192 > 0x40)
    { // middle
        COMMON_SetPixelByStrandIndex(Pixel, color_mid);
        // Serial.print("\tmid");
        // Serial.println(t192);
    }
    else
    { // coolest
        COMMON_SetPixelByStrandIndex(Pixel, color_cold);
        // Serial.print("\tcoo");
        // Serial.println(t192);
    }
}

uint16_t hue_index = 0;
void FIRE_main_program(void)
{

    if (first_program_run)
    {
        strip.clear();
    }

    /*
        uint32_t color;
        uint8_t c_red;
        uint8_t c_green;
        uint8_t c_blue;

        for (int i = 0; i < NUMPERSTRAND; i++)
        {
            color = FIRE_ColorFromPalette(1, hue_index);
            c_red = ((color >> 16) & 0xFF);  // Extract the RR byte
            c_green = ((color >> 8) & 0xFF); // Extract the GG byte
            c_blue = ((color)&0xFF);         // Extract the BB byte

            strip.setPixelColor(i, c_red, c_green, c_blue);
        }

        Serial.print(hue_index);
        Serial.print("\t");
        Serial.print(color, HEX);
        Serial.print("\t");
        Serial.print(c_red);
        Serial.print("\t");
        Serial.print(c_green);
        Serial.print("\t");
        Serial.print(c_blue);
        Serial.println("\t");
        strip.show();
    */

    static byte heat[NUMPERSTRAND];
    int cooldown;
    // Step 1.  Cool down every cell a little
    for (int i = 0; i < NUMPERSTRAND; i++)
    {
        cooldown = random(0, (((FIRE_COOLING)*10) / NUMPERSTRAND) + 2);
        if (cooldown > heat[i])
        {
            heat[i] = 0;
        }
        else
        {
            heat[i] = heat[i] - cooldown;
        }
    }
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for (int k = NUMPERSTRAND - 1; k >= 2; k--)
    {
        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }
    // Step 3.  Randomly ignite new 'sparks' near the bottom
    if (random(255) < FIRE_SPARKING)
    {
        int y = random(7);
        heat[y] = heat[y] + random(160, 255);
        // heat[y] = random(160,255);
    }
    // Step 4.  Convert heat to LED colors
    for (int j = 0; j < NUMPERSTRAND; j++)
    {
        SetPixelByHeatColor(j, heat[j], FIRE_STYLE);
    }

    for (int i = 0; i < 5; i++)
    {
        if (sparks[i].position >= NUMPERSTRAND - 1)
        {
            sparks[i].pixels_to_live =
                0; // We're at the end, so it's time to die
        }
        // for sparks that are alive
        if (sparks[i].pixels_to_live > 0)
        {
            // This spark is alive, so if it is time to move up
            // Move up
            sparks[i].position += sparks[i].rate;
            // Decrease life
            sparks[i].pixels_to_live -= sparks[i].rate;

            // show the spark
            if (sparks[i].position < NUMPERSTRAND)
            {
                COMMON_SetPixelByStrandIndex(sparks[i].position, color_spark);
            }
        }
        else // this spark is not alive. There is a chance a new one could be
             // born!
        {
            // if (random8() < 2)
            if (random(255) < 2)
            {
                // Make a new spark
                sparks[i].position =
                    // random8(0, NUMPERSTRAND / 2);  // It could appear anywhere // near the base of the strand
                    random(0, NUMPERSTRAND / 2);
                // sparks[i].pixels_to_live = random8(4, (NUMPERSTRAND / 2) - sparks[i].position);  // It could last as distance it has yet  to cover
                sparks[i].pixels_to_live = random(4, (NUMPERSTRAND / 2) - sparks[i].position);
                // sparks[i].rate = random8(2, 3);
                sparks[i].rate = random(2, 3);
            }
        }
    }

    strip.show();
    delay(FIRE_SPEEDDELAY);
}
