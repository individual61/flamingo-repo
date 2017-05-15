
#ifndef EFFECTS_H
#define EFFECTS_H

#include <Adafruit_DotStar.h>
#include <Arduino.h>

byte* Wheel(byte WheelPos);

void setPixelByStrandIndex(int index, uint32_t color);

void setPixelByStrandIndex(int n, uint8_t r, uint8_t g, uint8_t b);

void getPixelColorAsArray(uint16_t index, uint8_t* pixel);

void fadeWholeStrip(float fade_coef);

void DHO_Rainbow(void);

void Rainbow(void);

void DHO_SinglePixel(void);

void DHO_Blob(void);

void DHO_SineStripes(void);

void setPixelHeatColorgreen(int Pixel, byte temperature);

void Fire(void);

void Sparkle(uint8_t red, uint8_t green, uint8_t blue, uint8_t SpeedDelay);

void SparkleFizz(uint8_t red, uint8_t green, uint8_t blue, uint8_t SpeedDelay);

void Acctest(void);

void DHO_Comet(void);

void DHO_Fade(void);

#endif
