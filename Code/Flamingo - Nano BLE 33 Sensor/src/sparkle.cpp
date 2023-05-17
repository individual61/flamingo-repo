#include <parameters.h>
#include <function_declarations_and_globals.h>

//////// SPARKLE ///////////////





void SPARKLE_main_program(void)
{
    if ((time_interval_us / 1000.0) > SPARKLE_DURATION_MS)
    {
        strip.clear();
        for (int num_sparkles = 0; num_sparkles < SPARKLE_QUANTITY; num_sparkles++)
        {
            uint8_t the_index = random(0, NUMPERSTRAND);
            COMMON_SetPixelByStrandIndex(the_index, SPARKLE_COLOR);
        }
        strip.show();
    }
}
