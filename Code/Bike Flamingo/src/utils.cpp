#include <parameters.h>
#include <utils.h>

int freeRam(void)
{
  extern int __heap_start, *__brkval;
  int v;
  return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

void Test(void) { Serial.println(accel.getAccelerationY()); }
