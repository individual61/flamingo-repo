#include <Arduino.h>

#include <parameters.h>
#include <function_declarations_and_globals.h>

/*

About 700 Hz with just 3-button polling and serial out.


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
    // while (!Serial)
    //     ;
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
    if (imu_active)
    {
        Serial.println(F("IMU active."));
    }

    //////////////////// LEDs ////////////////////

    strip.begin(); // Initialize pins for output
    strip.clear();
    strip.setBrightness(START_BRIGHTNESS);
    strip.show(); // Turn all LEDs off ASAP

    //////////////////// Timing ////////////////////

    timing_update_variables();
}

void loop()
{
    //////////////////// Buttons ////////////////////

    // This calls button_X_action() in buttons.cpp
    buttons_check_for_changes();

    //////////////////// IMU ////////////////////

    if (imu_active)
    {
        imu_update_accel_values();
    }

    //////////////////// Timing ////////////////////

    // This updates time_interval_us with the loop interval
    timing_update_variables();

    //////////////////// Programs ////////////////////

    switch (programIndex)
    {

    case 0:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 0"));
            // DHO_main_program();
            FIRE_main_program();
            first_program_run = 0;
            break;
        }

        // DHO_main_program();
        FIRE_main_program();

        break;
    };

    case 1:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 1"));
            BB_main_program();

            first_program_run = 0;
            break;
        }

        BB_main_program();

        break;
    };

    case 2:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 2"));
            SPARKLE_main_program();
            first_program_run = 0;
            break;
        }

        SPARKLE_main_program();

        break;
    };

    case 3:
    {

        if (first_program_run)
        {
            Serial.println(F("In Case 3"));
            // FIRE_main_program();
            DHO_main_program();
            first_program_run = 0;
            break;
        }

        // FIRE_main_program();
        DHO_main_program();

        break;
    };

    default:
    {
        Serial.print(F("We fell into default case, programIndex is "));
        Serial.println(programIndex);
    };
    };
};

/*
//TEMPLATE
case 3:
{
if (firstRun)
{
  Serial.println(F("PROGRAM_3 "));
  firstRun = 0;
  break;
}

break;
};
*/