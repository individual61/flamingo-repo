#include <parameters.h>
#include <function_declarations_and_globals.h>
 /*

 
 // Magnetometer values drift and come with intrinsic offset, cant be bothered to fix


void mag_update_mag_values(void);

float max_mag = 10.0;

void COMPASS_main_program(void)
{
    if (first_program_run)
    {
        max_mag = 0;
        strip.clear();
    }

    Serial.print(mag_g_x);
    Serial.print("\t");
    Serial.print(mag_g_y);
    Serial.print("\t");
    Serial.println(mag_g_z);
    strip.clear();

    if (abs(mag_g_y) > max_mag)
    {
        max_mag = abs(mag_g_y);
    }

    float factor = mag_g_y / max_mag;
    uint16_t index = ((NUMPERSTRAND - 1) / 2.0) + factor * ((NUMPERSTRAND - 1) / 2.0);

    // Serial.print(mag_g_y);
    //  Serial.print("\t");
    //  Serial.print(factor);
    //  Serial.print("\t");
    //  Serial.println(index);

    for (int i = 0; i <= index; i++)
    {
        COMMON_SetPixelByStrandIndex(index, COMPASS_COLOR);
    }

    COMMON_SetPixelByStrandIndex(index, COMPASS_COLOR);

    strip.show();
}

*/
