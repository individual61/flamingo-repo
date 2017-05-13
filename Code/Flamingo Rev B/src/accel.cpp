#include <accel.h>
#include <parameters.h>

float acc_offset_normalized;
// float  g0y, g0yphysical, ;

/*
//will delete
// Returns physical acc in m/sˆ2
// Right side up:   9.81
// Upside Down:     -9.81
float getPhysicalAccelY(void)
{
  int16_t acc;
  acc = accel.getAccelerationY();
  return 9.81 * (((float)acc) - A_OFFSET) / A_GAIN;
}
*/

/*
//willdelete
// Returns the accelerometer difference from initial acc in m/s^2
// Right side up: 0.0
// Upside Down:   - 2*9.81
float getPhysicalOffsetAccelY(void)
{
  // g0y was set via initAccelOffset()
  float acc = (getPhysicalAccelY() - g0yphysical);
  return acc;
}
*/

// this one stays
// Returns normalized acc in units of g
// Right side up: 1.0
// Upside Down:   -1.0
float getNormalizedAccelY(void)
{
  int16_t acc;
  acc = accel.getAccelerationY();
  //  Serial.print("getNormalizedAccelY():\t");
  //  Serial.print(-(((float)((acc)-A_OFFSET)) / A_GAIN));
  return -(((float)((acc)-A_OFFSET)) / A_GAIN);
}

// this one stays
// Returns the accelerometer difference from initial acc in m/s^2
// Right side up: 0.0
// Upside Down:
float getNormalizedOffsetAccelY(void)
{
  // g0y was set via initAccelOffset()
  float acc = (getNormalizedAccelY() - acc_offset_normalized);
  return acc;
}

// Measures 1 second of physical accelerometer values and averages to create
// offset.
void initAccelOffset(void)
{
  unsigned long accel_init_start_time;
  uint16_t accel_init_average_count = 0;
  accel_init_start_time = millis();
  acc_offset_normalized = 0;
  while (millis() - accel_init_start_time < 1000)
    {
      acc_offset_normalized = acc_offset_normalized + getNormalizedAccelY();
      accel_init_average_count++;
    }
  acc_offset_normalized =
      acc_offset_normalized / ((float)accel_init_average_count);

  Serial.print(F("Number of measurements: "));
  Serial.print(accel_init_average_count);
  Serial.print(F(".\tAvg acc_offset_normalized:"));
  Serial.println(acc_offset_normalized);
}
