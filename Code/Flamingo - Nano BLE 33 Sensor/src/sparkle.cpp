#include <parameters.h>
#include <function_declarations_and_globals.h>

//////// SPARKLE ///////////////

uint32_t sparkle_color;
uint16_t sparkle_sat;

void SPARKLE_main_program(void)
{
    switch (settingIndex)
    {

    case 0:
    {
        sparkle_color = strip.ColorHSV(0, 0, SPARKLE_MAX_BRIGHTNESS);
        break;
    };

    case 1:
    {
        sparkle_color = strip.ColorHSV(PINK_HUE, 255, SPARKLE_MAX_BRIGHTNESS);
        break;
    };
    
    case 2:
    {
        sparkle_sat = 255 - 255 * gflash_factor;
        sparkle_color = strip.ColorHSV(PINK_HUE, sparkle_sat, SPARKLE_MAX_BRIGHTNESS);
        break;
    };
    
    default:
    {
        settingIndex = 0;
        Serial.print(F("Setting index set to:\t"));
        Serial.println(settingIndex);
    };
    };

    if ((time_interval_us / 1000.0) > SPARKLE_DURATION_MS)
    {
        strip.clear();
        for (int num_sparkles = 0; num_sparkles < SPARKLE_QUANTITY; num_sparkles++)
        {
            uint8_t the_index = random(0, NUMPERSTRAND);

            COMMON_SetPixelByStrandIndex(the_index, sparkle_color);
        }
        strip.show();
    }
}
