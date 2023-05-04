#include <parameters.h>
#include <function_declarations_and_globals.h>


uint32_t time_now_us = 0;       // global
uint32_t time_last_us = 0;
float time_frequency_hz = 0.0;
uint32_t time_interval_us = 0;

void timing_update_variables(void)
{
    time_now_us = micros();
    time_interval_us = time_now_us - time_last_us;

    if (time_interval_us > 0)
    {
        time_frequency_hz = 1000000.0 * (1.0 / time_interval_us);
    }
    else
    {
        time_frequency_hz = 0;
    }
#if SERIAL_OUT_TIMING == 1
    Serial.print("Time now, us: ");
    Serial.print(time_now_us);
    Serial.print("\tFrequency, Hz ");
    Serial.print(time_frequency_hz);
    Serial.print("\tInterval, us: ");
    Serial.println(time_interval_us);
#endif

    time_last_us = time_now_us;
}
