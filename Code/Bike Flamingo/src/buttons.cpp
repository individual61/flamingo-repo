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

#if BOARD_TYPE == 2
// Make sure there are BRIGHTNESS_COUNT elements in the array.
uint8_t brightness[BRIGHTNESS_COUNT] = {10, 15, 20, 40, 60,
                                        100, 140, 180, 220, 240};
#endif

uint8_t brightness[NUM_PROGRAMS][BRIGHTNESS_MAX_QUANTITY] = ALL_BRIGHTNESS_ARRAY;
uint8_t brightnessIndex[NUM_PROGRAMS];

bool firstRun = 1;

// Change Program
void isr_handler_A()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
    last_interrupt_time = interrupt_time;

    firstRun = 1;

#if BOARD_TYPE == 2
    pos0 = vel0 = pos1 = vel1 = 0.0;
#endif

    programIndex++;

    if (programIndex == NUM_PROGRAMS)
    {
      programIndex = 0;
    }

    Serial.print("Button A was pressed, and the new program is ");
    Serial.println(programIndex);

    // Set the brightness to the value last used for this program.
    FastLED.setBrightness(brightness[programIndex][brightnessIndex[programIndex]]);
    FastLED.show();
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

    (brightnessIndex[programIndex])++;

    if (brightnessIndex[programIndex] == BRIGHTNESS_MAX_QUANTITY)
    {
      brightnessIndex[programIndex] = 0;
      Serial.println("Setting brightnessIndex[programIndex] to 0 because brightnessIndex[programIndex])++ == BRIGHTNESS_MAX_QUANTITY");
    }

    // brightnessIndex[programIndex] may still not have looped because we exceeded BRIGHTNESS_MAX_QUANTITY,
    // so we check if the brightness value for this program is 0, which is another reason to set the brightnessIndex back to zero.
    // this is how we account for different programs having different numbers of brightness levels
    if (brightness[programIndex][brightnessIndex[programIndex]] == 0)
    {
      brightnessIndex[programIndex] = 0;
      Serial.println("Setting brightnessIndex[programIndex] to 0 because brightnessIndex[programIndex])++ == 0");
    }

    // At this point brightnessIndex[programIndex] is either 0 (because we looped through all 10 brightness levels, or we hight a brightness level of 0)
    // or it's a regular brightness level
    FastLED.setBrightness(brightness[programIndex][brightnessIndex[programIndex]]);
    FastLED.show();
    Serial.print("Button C pressed, brightness is: ");
    Serial.print(brightness[programIndex][brightnessIndex[programIndex]]);
    Serial.print(" and brightnessIndex[programIndex] is ");
    Serial.print(brightnessIndex[programIndex]);
    Serial.print(" and program is ");
    Serial.println(programIndex);
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