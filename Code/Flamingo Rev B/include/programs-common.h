
#ifndef PROGRAMSCOMMON_H
#define PROGRAMSCOMMON_H

#include <Arduino.h>
#include <FastLED.h>

byte* Wheel(byte WheelPos);

void setPixelByIndex(int index, uint32_t color);

void setPixelByStrandIndex(uint16_t index, CRGB color);

void setPixelByStrandIndex(uint16_t n, uint8_t r, uint8_t g, uint8_t b);

void getPixelColorAsArray(uint16_t index, uint8_t* pixel);

void fadeWholeStrip(uint8_t fade_coef);

void fadePixelByStrandIndex(uint16_t index, uint8_t fade);

void DHO_Rainbow(void);

byte* Wheel(byte WheelPos);
void Rainbow(void);

void Rainbow_FastLED(void);

void DHO_SinglePixel(void);

void DHO_Blob(void);

void DHO_SineStripes(void);

void setPixelHeatColorgreen(uint16_t Pixel, byte temperature);

void GreenFireOriginal(void);

void Fire2012RainbowRotate(void);

void Fire2012WithPalette(CRGBPalette16 firepal, CRGB sparkcolor, bool scaleHeat,
                         bool rotate);

void Sparkle(CRGB thecolor, uint8_t duration);

void SparkleFizz(CRGB thecolor, uint8_t duration);

void Acctest(void);

// void DHO_Comet(void);

void DHO_Fade(void);

void Test(void);

void Bouncing_Balls(bool BB_fade);

#endif
