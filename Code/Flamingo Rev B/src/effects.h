
#ifndef EFFECTS_H
#define EFFECTS_H

#include <Adafruit_DotStar.h>
#include <Arduino.h>
#include <FastLED.h>

byte* Wheel(byte WheelPos);

void setPixelByStrandIndex(uint16_t index, CRGB color);

void setPixelByStrandIndex(uint16_t n, uint8_t r, uint8_t g, uint8_t b);

void getPixelColorAsArray(uint16_t index, uint8_t* pixel);

void fadeWholeStrip(uint8_t fade_coef);

void fadePixelByStrandIndex(uint16_t index, uint8_t fade);

void DHO_Rainbow(void);

void Rainbow(void);

void DHO_SinglePixel(void);

void DHO_Blob(void);

void DHO_SineStripes(void);

void setPixelHeatColorgreen(uint16_t Pixel, byte temperature);

void Fire(void);

void Sparkle(uint8_t red, uint8_t green, uint8_t blue, uint8_t SpeedDelay);

void SparkleFizz(uint8_t red, uint8_t green, uint8_t blue, uint8_t SpeedDelay);

void Acctest(void);

void DHO_Comet(void);

void DHO_Fade(void);

#endif
