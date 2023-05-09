
#ifndef PROGRAMSCOMMON_H
#define PROGRAMSCOMMON_H

#include <Arduino.h>

///////////////////// BUTTONS /////////////////////

extern uint32_t last_interrupt_time;

void buttons_initialize(void);
void isr_A(void);
void isr_B(void);
void isr_C(void);

void buttons_check_for_changes(void);

///////////////////// LEDS /////////////////////

extern Adafruit_DotStar strip;
extern uint32_t DHO_color;

///////////////////// PROGRAMS /////////////////////

// Defined in main.cpp

extern bool first_program_run;
extern uint8_t programIndex;

///////////////////// DHO /////////////////////

double DHO_update_position(void);
uint16_t DHO_get_strand_index_from_x(float x);
void DHO_setPixelByStrandIndex(uint16_t index);
void DHO_main_program(void);

///////////////////// BB /////////////////////

double BB_update_position(void);
uint16_t BB_get_strand_index_from_x(float x);
void BB_setPixelByStrandIndex(uint16_t index);
void BB_main_program(void);

///////////////////// TIMING /////////////////////

extern uint32_t time_interval_us;

void timing_update_variables(void);

///////////////////// IMU /////////////////////

extern bool imu_active;
extern float acc_g_x, acc_g_y, acc_g_z;
extern float acc_g_filt_x, acc_g_filt_y, acc_g_filt_z;

extern SimpleKalmanFilter acc_kalman_filter_x;
extern SimpleKalmanFilter acc_kalman_filter_y;
extern SimpleKalmanFilter acc_kalman_filter_z;

bool imu_initialize(void);
void imu_update_accel_values(void);
void imu_update_accel_values_filtered(void);
float imu_get_update_rate(void);

#endif
