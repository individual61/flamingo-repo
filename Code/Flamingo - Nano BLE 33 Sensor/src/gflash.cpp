#include <parameters.h>
#include <function_declarations_and_globals.h>

/// @brief  A bounce is on the scale of 100 ms FWHM

float max_g = 0.0;
float g_scale = 0.5;
float g_thresh = 2.0;
float factor = 0.0;
uint8_t brightness = 0.0;
float color_scale = 300.0;
uint16_t hue_angle = 0;

double elapsed_time_s = 0.0;
void GFLASH_main_program(void)
{
    if (first_program_run)
    {
        max_g = 0.0;
        factor = 0.0;
        elapsed_time_s = 0.0;
        strip.clear();
    }

    if (acc_g_z > g_thresh)
    {
        factor = g_scale * (acc_g_z - g_thresh) * (acc_g_z - g_thresh);
        if (factor > 1.0)
        {
            factor = 1.0;
        }
    }
    else
    {
        factor = 0.0;
    }

    hue_angle = hue_angle + color_scale * factor;

    for (int i = 0; i < NUMPERSTRAND; i++)
    {
        brightness = 30 * factor;
        uint32_t color = strip.ColorHSV(hue_angle, 255 -factor * 30.0, brightness);
        COMMON_SetPixelByStrandIndex(i, color);
    }

    elapsed_time_s = elapsed_time_s + time_interval_us / 1000000.0;
    Serial.print(elapsed_time_s);
    Serial.print("\t");
    Serial.print(factor);
    Serial.print("\t");
    Serial.print(color_scale * factor);
    Serial.print("\t");
    Serial.println(hue_angle);

    strip.show();

        /*
        if (acc_g_z > max_g)
        {
            max_g = acc_g_z;
            //          Serial.print(acc_g_z);
            //  Serial.print("xxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        }

        switch (settingIndex)
        {

        case 0:
        {
            break;
        };

        case 1:
        {
            max_g = 0.0;
            settingIndex = 0;
            break;
        };

        default:
        {
            settingIndex = 0;
        };
        }

        */


}