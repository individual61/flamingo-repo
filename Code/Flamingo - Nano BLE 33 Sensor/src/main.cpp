#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

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

void setup()
{

    //////////////////// Serial ////////////////////

    Serial.begin(115200);
    // while (!Serial)
    //   ;
    Serial.println(F("Started serial to PC."));

    //////////////////// Buttons ////////////////////

    buttons_initialize();

    //////////////////// IMU ////////////////////

    imu_active = 1;
    if (!imu_initialize())
    {
        Serial.println(F("IMU failed to initialize."));
        while (1)
            ;
    }
}

void loop()
{
    //////////////////// Buttons ////////////////////

    // This calls button_X_action() in buttons.cpp
    buttons_check_for_changes();

    //////////////////// Timing ////////////////////

    // This updates time_interval_us with the loop interval
    timing_update_variables();

    //////////////////// IMU ////////////////////

    if (imu_active)
    {
        imu_update_accel_values();


    }

    //////////////////////////////////////////////

    /*
        switch (programIndex)
        {

        case 0:
        {

            if (firstRun)
            {
                Serial.print(F("In Case 0"));
                firstRun = 0;
                break;
            }
            break;



        }

        case 1:
        {

            if (firstRun)
            {
                Serial.print(F("In Case 1"));
                firstRun = 0;
                break;
            }
            break;


        };

        case 2:
        {

            if (firstRun)
            {
                Serial.print(F("In Case 2"));
                firstRun = 0;
                break;
            }
            break;


        };

        case 3:
        {

            if (firstRun)
            {
                Serial.print(F("In Case 3"));
                firstRun = 0;
                break;
            }
            break;


        };

        default:
        {
            Serial.print(F("We fell into default case, programIndex is "));
            Serial.println(programIndex);
        };
        };
    */
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