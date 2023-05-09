#include <parameters.h>
#include <function_declarations_and_globals.h>

//////// SPARKLE ///////////////

uint32_t SPARKLE_color = 0xffffff;

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void SPARKLE_setPixelByStrandIndex(uint16_t index)
{

    if ((index >= 0) && (index < NUMPERSTRAND))
    {
        // index goes from 0 to NUMPERSTRAND - 1
        uint8_t realindex = 0;

#if NUM_STRANDS == 1
        realindex = index;
        strip.setPixelColor(realindex, SPARKLE_color);

#endif

#if NUM_STRANDS == 3
        // NUMPERSTRAND - 1
        // 0
        realindex = NUMPERSTRAND - index - 1;
        strip.setPixelColor(realindex, SPARKLE_color);
        // Serial.print(realindex);
        // Serial.print("\t");

        // NUMPERSTRAND
        // 2*NUMPERSTRAND - 1
        realindex = NUMPERSTRAND + index;
        strip.setPixelColor(realindex, SPARKLE_color);
        // Serial.print(realindex);
        // Serial.print("\t");

        // 3*NUMPERSTRAND - 1
        // 2*NUMPERSTRAND
        realindex = 3 * NUMPERSTRAND - index - 1;
        strip.setPixelColor(realindex, SPARKLE_color);
        // Serial.println(realindex);
#endif
    }
}

void SPARKLE_main_program(void)
{
    if ((time_interval_us / 1000.0) > SPARKLE_DURATION_MS)
    {
        strip.clear();
        for (int num_sparkles = 0; num_sparkles < SPARKLE_QUANTITY; num_sparkles++)
        {
            uint8_t the_index = random(0, NUMPERSTRAND);
            SPARKLE_setPixelByStrandIndex(the_index);
        }
        strip.show();
    }
}
