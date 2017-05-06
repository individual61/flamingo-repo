#ifndef HARMONIC_OSCILLATOR_H
#define HARMONIC_OSCILLATOR_H

#include <Arduino.h>

float eval_v_func(float v, float x, float acc_ext);

float get_next_v(float oldv, float oldx, float acc_ext);

float get_next_x(float oldv, float oldx);

float getBallPosition(void);

int ballToStrandPosition(float ballPos);

void setPixelByIndex(int index, uint32_t color);









#endif
