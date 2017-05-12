#include <accel.h>
#include <parameters.h>

float g0y, g0yphysical, gy;

// Returns the accelerometer difference from 1 g in m/s^2
float getOffsetAccel(float gfactor)
{
  // g0y was set via initAccelOffset()
  float acc = gfactor * (g0y - accel.getAccelerationY());
  return acc;
}

// Returns physical acc in m/sˆ2
float getPhysicalAccelY(void)
{
  int16_t acc;
  acc = accel.getAccelerationY();
  return 9.81 * (((float)acc) - A_OFFSET) / A_GAIN;
}

// Returns the accelerometer difference from 1 g in m/s^2
float getPhysicalOffsetAccel(void)
{
  // g0y was set via initAccelOffset()
  float acc = (getPhysicalAccelY() - g0yphysical);
  return acc;
}

// Measures 1 second of accelerometer values and averages to create offset.
void initAccelOffset(void)
{
  unsigned long accel_init_start_time;
  uint16_t accel_init_average_count = 0;
  accel_init_start_time = millis();
  g0y = 0;
  gy = 0;
  while (millis() - accel_init_start_time < 1000)
    {
      g0y = g0y + accel.getAccelerationY();
      accel_init_average_count++;
    }
  g0y = g0y / ((float)accel_init_average_count);

  Serial.print(F("Number of measurements: "));
  Serial.print(accel_init_average_count);
  Serial.print(F(".\tAvg g0y:"));
  Serial.println(g0y);
}

// Measures 1 second of physical accelerometer values and averages to create
// offset.
void initAccelOffsetReal(void)
{
  unsigned long accel_init_start_time;
  uint16_t accel_init_average_count = 0;
  accel_init_start_time = millis();
  g0yphysical = 0;
  gy = 0;
  while (millis() - accel_init_start_time < 1000)
    {
      g0yphysical = g0yphysical + getPhysicalAccelY();
      accel_init_average_count++;
    }
  g0yphysical = g0yphysical / ((float)accel_init_average_count);

  Serial.print(F("Number of measurements: "));
  Serial.print(accel_init_average_count);
  Serial.print(F(".\tAvg g0yphysical:"));
  Serial.println(g0yphysical);
}
