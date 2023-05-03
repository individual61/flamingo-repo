
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

///////////////////// TIMING /////////////////////


extern uint32_t time_interval_us;


void update_timing_variables(void);

#endif
