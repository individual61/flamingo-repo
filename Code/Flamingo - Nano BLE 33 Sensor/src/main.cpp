#include <Arduino.h>

#include <parameters.h>
#include <function_declarations_and_globals.h>

/*   TODO

Lowest brightness is perfectly adequate for  festival in general, might even consider a lower brightness?
Fix bouncing ball at bottom


*/

/*

About 700 Hz with just 3-button polling and serial out.

syncradnnum program, flowing or fast flowing rainbow, setting 3? max brightness.

 Attom Tech smaller 3000mAh     255 brightness  1723mAh 2h 31
                                150 brightness  1683mAh 3h 30
 Kolumb 2500mAh                 255 brightness  1274mAh 1h 48

For atomtek 3000 mAh battery				
brightness	brightness%	time	hours	hours Kolumb
10	0.04	290.27	4.84	3.41
20	0.08	284.55	4.74	3.35
30	0.12	278.82	4.65	3.28
40	0.16	273.10	4.55	3.21
50	0.20	267.37	4.46	3.15
60	0.24	261.65	4.36	3.08
70	0.27	255.92	4.27	3.01
80	0.31	250.20	4.17	2.94
90	0.35	244.47	4.07	2.88
100	0.39	238.75	3.98	2.81
110	0.43	233.02	3.88	2.74
120	0.47	227.29	3.79	2.67
130	0.51	221.57	3.69	2.61
140	0.55	215.84	3.60	2.54
150	0.59	210.12	3.50	2.47
160	0.63	204.39	3.41	2.40
170	0.67	198.67	3.31	2.34
180	0.71	192.94	3.22	2.27
190	0.75	187.22	3.12	2.20
200	0.78	181.49	3.02	2.14
210	0.82	175.76	2.93	2.07
220	0.86	170.04	2.83	2.00
230	0.90	164.31	2.74	1.93
240	0.94	158.59	2.64	1.87
250	0.98	152.86	2.55	1.80
255	1.00	150.00	2.50	1.76

HOW TO CONNECT EVERYTHING

********* Buttons *********
BAT -> Resistor -> (Button Pin) -> (Normally Open Button) -> GND

********* Dotstars/APA102C *********
Electrolytic cap across VCC and GND

(Adafruit 144/m, on Flamingo Original stick):
VCC -> BAT
Green/data -> 11 (Hardware SPI MOSI)
Yellow/clock -> 13 (Hardware SPI CLOCK)
GND to GND

APA102C 144/m (chinese):
VCC -> BAT
Green/data -> 11 (Hardware SPI MOSI)
Red/clock -> 13 (Hardware SPI CLOCK)
GND to GND
*/

/////// GENERAL ////
//
//
//

// for time()

// uint32_t start_time = 0;

// #define numberofprograms 2

// uint8_t volatile programIndex = 0;

// bool firstRun = 1;

// Globals

bool first_program_run = 1;
uint8_t programIndex = 0;
uint8_t settingIndex = 0;
uint8_t brightnessIndex = 0;

float brightnessArray[GLOBAL_BRIGHTNESS_LEVELS_NUMBER] = GLOBAL_BRIGHTNESS_LEVELS;

// This version uses hardware SPI
// With just DHO single pixel:
// 81.97 Hz, 12.2 ms for 72 LEDs, 1 strand
// 6.8 ms for LED data, 5.44 ms for DHO single pixel loop
//
Adafruit_DotStar strip(NUMPIXELS, DOTSTAR_BGR);

void setup()
{

    //////////////////// Serial ////////////////////

    Serial.begin(115200);

    delay(100);
    Serial.println(F("Started serial to PC."));

    //////////////////// Buttons ////////////////////

    buttons_initialize();

    //////////////////// IMU ////////////////////

    if (!imu_initialize())
    {
        Serial.println(F("IMU failed to initialize."));
        while (1)
            ;
    }

    imu_active = 1;
    mag_active = 0;
    gflash_active = 1;

    //////////////////// LEDs ////////////////////

    strip.begin(); // Initialize pins for output
    strip.clear();
    strip.setBrightness(brightnessArray[0]);
    strip.show(); // Turn all LEDs off ASAP

    //////////////////// Timing ////////////////////

    timing_update_variables();
}

uint8_t counter = 0;

void loop()
{
    // Serial.print(first_program_run);
    // Serial.print("\t");
    // Serial.println(imu_active);
    //////////////////// Buttons ////////////////////

    // This calls button_X_action() in buttons.cpp
    buttons_check_for_changes();

    //////////////////// IMU ////////////////////

    if (imu_active)
    {
        imu_update_accel_values();
    }

    if (mag_active)
    {
        mag_update_mag_values();
    }

    //////////////////// Timing ////////////////////

    // This updates time_interval_us with the loop interval
    timing_update_variables();

    //////////////////// Programs ////////////////////
    //////////////////////////////////////////////////

    switch (programIndex)
    {

        ///////////////////////  DHO  ///////////////////////
    case 0:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 0"));

            imu_active = 1;
            mag_active = 0;
            gflash_active = 0;

            settingIndex = 0;
            DHO_main_program();
            first_program_run = 0;

            break;
        }

        DHO_main_program();

        /* counter++;
         if (counter == 0)
         {
             Serial.println(time_frequency_hz);
         }
         */

        break;
    };

        ///////////////////////  BB  ///////////////////////
    case 1:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 1"));

            imu_active = 1;
            mag_active = 0;
            gflash_active = 0;

            settingIndex = 0;
            BB_main_program();
            first_program_run = 0;

            break;
        }

        BB_main_program();

        break;
    };

        ///////////////////////  GFLASH  ///////////////////////
    case 2:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 2"));

            imu_active = 1;
            mag_active = 0;
            gflash_active = 1;

            settingIndex = 0;
            GFLASH_main_program();
            first_program_run = 0;

            break;
        }

        GFLASH_main_program();

        break;
    };

        ///////////////////////  SYNCRANDNUM  ///////////////////////
    case 3:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 3"));

            imu_active = 1;
            mag_active = 0;
            gflash_active = 1;

            settingIndex = 0;
            SYNCRANDNUM_main_program();
            first_program_run = 0;

            break;
        }

        SYNCRANDNUM_main_program();

        break;
    };

        ///////////////////////  FIRE  ///////////////////////
    case 4:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 4"));

            imu_active = 0;
            mag_active = 0;
            gflash_active = 0;

            settingIndex = 0;
            FIRE_main_program();
            first_program_run = 0;

            break;
        }

        FIRE_main_program();

        break;
    };

        ///////////////////////  SPARKLE  ///////////////////////
    case 5:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 5"));

            imu_active = 1;
            mag_active = 0;
            gflash_active = 1;

            settingIndex = 0;
            SPARKLE_main_program();
            first_program_run = 0;

            break;
        }

        SPARKLE_main_program();

        break;
    };

    ///////////////////////  Timing  ///////////////////////
    /*
    case 6:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 6"));

            imu_active = 0;
            mag_active = 0;
            gflash_active = 0;

            settingIndex = 0;

            first_program_run = 0;

            break;
        }

        Serial.print(DHO_COLOR);
        Serial.print("\t");
        uint32_t color_hue = strip.ColorHSV(55000, 255, 255);
        Serial.println(color_hue);

        strip.clear();
        for (int i = 0; i < NUMPERSTRAND / 2.0; i++)
        {
            // uint32_t color = strip.ColorHSV(hue_angle, 255 -gflash_factor * 30.0, brightness);
            // COMMON_SetPixelByStrandIndex(i, strip.ColorHSV(55000, 255, 255));
            COMMON_SetPixelByStrandIndex(i, DHO_COLOR);
        }
        for (int i = NUMPERSTRAND / 2.0; i < NUMPERSTRAND; i++)
        {
            // uint32_t color = strip.ColorHSV(hue_angle, 255 -gflash_factor * 30.0, brightness);
            // COMMON_SetPixelByStrandIndex(i, strip.ColorHSV(55000, 255, 255));
            COMMON_SetPixelByStrandIndex(i, color_hue);
        }
        strip.show();

        // counter++;
        // if (counter == 0)
        //{
        //     Serial.println(time_interval_us);
        // }

        break;
    };
*/
    default:
    {
        Serial.print(F("We fell into default case, programIndex is "));
        Serial.println(programIndex);
    };
    };
};

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void COMMON_SetPixelByStrandIndex(uint16_t index, uint32_t color)
{
    if ((index >= 0) && (index < NUMPERSTRAND))
    {
        // index goes from 0 to NUMPERSTRAND - 1
        uint16_t realindex = 0;

#if NUM_STRANDS == 1
        realindex = index;
        strip.setPixelColor(realindex, color);
        // Serial.println(color_h, HEX);
#endif

#if NUM_STRANDS == 3
        // NUMPERSTRAND - 1
        // 0
        realindex = NUMPERSTRAND - index - 1;
        strip.setPixelColor(realindex, color);
        // Serial.print(realindex);
        // Serial.print("\t");

        // NUMPERSTRAND
        // 2*NUMPERSTRAND - 1
        realindex = NUMPERSTRAND + index;
        strip.setPixelColor(realindex, color);
        // Serial.print(realindex);
        // Serial.print("\t");

        // 3*NUMPERSTRAND - 1
        // 2*NUMPERSTRAND
        realindex = 3 * NUMPERSTRAND - index - 1;
        strip.setPixelColor(realindex, color);
        // Serial.println(realindex);
#endif
    }
}
