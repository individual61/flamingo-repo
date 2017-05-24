#ifndef BOUNCING_BALLS_H
#define BOUNCING_BALLS_H

typedef struct bouncingball
{
  float position = 0.0;
  float mass = 0.0;
  float velocity = 0.0;
  CRGB colour = CRGB(255, 255, 255);
} bouncingball;

float eval_v_func_BB(float v, float x, float acc_ext, float damping,
                     float mass);
float get_next_v_BB(float oldv, float oldx, float acc_ext, float damping,
                    float mass);

void updateBallPosition_BB(bouncingball* theBall, float damping);

// float get_next_x(float oldv, float oldx) // defined in DHO

int ballToStrandPosition_BB(float ballPos_BB);

float getBallPosition_BB(float oldpos, float oldvel, float mass, float damping);

#endif
