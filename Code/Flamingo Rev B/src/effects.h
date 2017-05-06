#ifndef EFFECTS_H
#define EFFECTS_H

#include <Adafruit_DotStar.h>


byte * Wheel(byte WheelPos);

void setPixelByIndex(int index, uint32_t color);

void setPixelHeatColorgreen(int Pixel, byte temperature);

void DHO_Rainbow(void);

void Rainbow(void);

void DHO_SinglePixel(void);

void DHO_Blob(void);

void DHO_SineStripes(void);

void Fire(void);





#endif
