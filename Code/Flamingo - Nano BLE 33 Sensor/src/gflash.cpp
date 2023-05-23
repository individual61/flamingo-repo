#include <parameters.h>
#include <function_declarations_and_globals.h>

//  A bounce is on the scale of 100 ms FWHM

float max_g = 0.0;

uint8_t brightness = 0.0;
// float color_scale = 300.0;
uint16_t hue_angle = 0;

//double elapsed_time_s = 0.0;
void GFLASH_main_program(void)
{
    if (first_program_run)
    {
        max_g = 0.0;
        gflash_factor = 0.0;
        //elapsed_time_s = 0.0;
        strip.clear();
    }

    // hue_angle = hue_angle + color_scale * gflash_factor;

    brightness = GFLASH_MAX_BRIGHTNESS * gflash_factor;
    // hue_angle = hue_angle + 25;
    uint32_t color = strip.ColorHSV(55000, 255, brightness);

    //Serial.print(gflash_factor);
    //Serial.print("\t");
    //Serial.print(acc_g_z);
    //Serial.print("\t");
    //Serial.println(brightness);

    for (int i = 0; i < NUMPERSTRAND; i++)
    {
        // uint32_t color = strip.ColorHSV(hue_angle, 255 -gflash_factor * 30.0, brightness);
        COMMON_SetPixelByStrandIndex(i, color);
    }

    //elapsed_time_s = elapsed_time_s + time_interval_us / 1000000.0;
    // Serial.print(elapsed_time_s);
    // Serial.print("\t");
    // Serial.print(gflash_factor);
    // Serial.print("\t");
    // Serial.print(color_scale * gflash_factor);
    // Serial.print("\t");
    // Serial.println(hue_angle);

    strip.show();
}