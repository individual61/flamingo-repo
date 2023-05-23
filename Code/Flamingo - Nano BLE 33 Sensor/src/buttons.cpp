#include <parameters.h>
#include <function_declarations_and_globals.h>

uint32_t last_interrupt_time;
volatile bool button_A_state;
volatile bool button_B_state;
volatile bool button_C_state;

void buttons_initialize(void)
{
  last_interrupt_time = 0;
  button_A_state = 0;
  button_B_state = 0;
  button_C_state = 0;

  pinMode(BUTT_A, INPUT);
  pinMode(BUTT_B, INPUT);
  pinMode(BUTT_C, INPUT);

  attachInterrupt(digitalPinToInterrupt(BUTT_A), isr_A, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTT_B), isr_B, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTT_C), isr_C, FALLING);
}

void isr_A(void)
{
  button_A_state = 1;
}

void isr_B(void)
{
  button_B_state = 1;
}

void isr_C(void)
{
  button_C_state = 1;
}

// Program change
void button_A_action(void)
{
#if SERIAL_OUT_BUTTONS == 1
  Serial.println(F("A button pressed."));
#endif

  first_program_run = 1;
  programIndex++;

  if (programIndex == NUM_PROGRAMS)
  {
    programIndex = 0;
  }
}

// Program setting
void button_B_action(void)
{
#if SERIAL_OUT_BUTTONS == 1
  Serial.println(F("B button pressed."));
#endif

  settingIndex++;

  if (settingIndex == NUM_PROGRAMS)
  {
    settingIndex = 0;
  }

  Serial.print(F("Setting index set to:\t"));
  Serial.println(settingIndex);
}

// Brightness
void button_C_action(void)
{
#if SERIAL_OUT_BUTTONS == 1
  Serial.println(F("C button pressed."));
#endif

  brightnessIndex++;
  if (brightnessIndex == GLOBAL_BRIGHTNESS_LEVELS_NUMBER)
  {
    brightnessIndex = 0;
  }
  strip.setBrightness(brightnessArray[brightnessIndex]);
  Serial.print("Global brightness set to\t");
  Serial.println(brightnessArray[brightnessIndex]);
}

void buttons_check_for_changes(void)
{
  if (button_A_state == 1)
  {
    button_A_state = 0;
    uint32_t interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
    {
      last_interrupt_time = interrupt_time;
      button_A_action();
    }
  }

  if (button_B_state == 1)
  {
    button_B_state = 0;
    uint32_t interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
    {
      last_interrupt_time = interrupt_time;
      button_B_action();
    }
  }

  if (button_C_state == 1)
  {
    button_C_state = 0;
    uint32_t interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
    {
      last_interrupt_time = interrupt_time;
      button_C_action();
    }
  }
}