#include <buttons.h>
#include <parameters.h>

uint8_t button1state;
uint8_t button2state;
uint8_t button1prevstate;
uint8_t button2prevstate;

unsigned long timeNowButton1 = 0;
unsigned long timeNowButton2 = 0;
unsigned long lastTimePressedButton1 = 0;
unsigned long lastTimePressedButton2 = 0;

uint8_t brightnessIndex = 0;

#if BOARD_TYPE == 2
// Make sure there are BRIGHTNESS_COUNT elements in the array.
uint8_t brightness[BRIGHTNESS_COUNT] = {10, 15, 20, 40, 60,
                                        100, 140, 180, 220, 240};
#endif

// Must match BRIGHTNESS_COUNT_PROG_X element count in parameters.h
// uint8_t[][BRIGHTNESS_MAX_QUANTITY] brightness = ALL_BRIGHTNESS_ARRAY;

int brightness[NUM_PROGRAMS][BRIGHTNESS_MAX_QUANTITY] = ALL_BRIGHTNESS_ARRAY

uint8_t programIndex = 1; // start at 1

bool firstRun = 1;

// Change Program
void isr_handler_A()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
    last_interrupt_time = interrupt_time;

    firstRun = 1;
    pos0 = vel0 = pos1 = vel1 = 0.0;

    if (programIndex == NUM_PROGRAMS + 1)
    {
      programIndex = 1;
      Serial.println("Resetting program to 1");
    }

    Serial.println("Button A");
  }
}

// TBD
void isr_handler_B()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
    last_interrupt_time = interrupt_time;

    Serial.println("Button B");
  }
}

// Brightness
void isr_handler_C()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
    last_interrupt_time = interrupt_time;
    Serial.println("Button C");

    if (brightnessIndex++ >= NUM_PROGRAMS - 1)
    {
      Serial.println("Resetting brightness to 0");
      brightnessIndex = 0;
    }
    FastLED.setBrightness(brightness[brightnessIndex][programIndex]);
    FastLED.show();
    Serial.print("Button C pressed, brightness is: ");
    Serial.println(brightness[brightnessIndex][programIndex]);
  }
}

/*
void setFullBrightnessOn10(void)
{
  if (brightnessIndex == BRIGHTNESS_COUNT - 1)
    {
      FastLED.setBrightness(255);
    }
}
*/