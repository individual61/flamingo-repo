#ifndef HARMONIC_OSCILLATOR_H
#define HARMONIC_OSCILLATOR_H

#include <Arduino.h>

float eval_v_func_DHO(float v, float x, float acc_ext, float damping,
                      float springconstant, float mass);

float get_next_v_DHO(float oldv, float oldx, float acc_ext, float damping,
                     float springconstant, float mass);

float get_next_x_DHO(float oldv, float oldx);

float getBallPosition_DHO(void);

float getBallPositionReal(void);

int ballToStrandPosition_DHO(float ballPos_DHO);

#endif
