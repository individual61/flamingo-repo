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
//Make sure there are BRIGHTNESS_COUNT elements in the array.
uint8_t brightness[BRIGHTNESS_COUNT] = {10, 15, 20, 40, 60, 100, 140, 180, 220, 240};

uint8_t programIndex = 1; // start at 1


void button1PressAction(void)
{

  if (brightnessIndex++ >= BRIGHTNESS_COUNT - 1)
  {
    brightnessIndex = 0;
  }
  strip.setBrightness(brightness[brightnessIndex]);
  Serial.print("Button 1 pressed, brightness is: ");
  Serial.println(brightness[brightnessIndex]);
}

void button2PressAction(void)
{
  pos0 = vel0 = pos1 = vel1 = 0.0;
  strip.setBrightness(brightness[0]);
  brightnessIndex = 0;
  strip.show();
  if (programIndex++ >= NUM_PROGRAMS)
  {
    programIndex = 1;
  }
  Serial.print("Button 2 pressed, program is: ");
  Serial.println(programIndex);
}


void checkButton1(void)
{
  bool buttonState = digitalRead(BUTTON1);
  if (buttonState == 0) //pressed
  {
    timeNowButton1 = millis();
    if (timeNowButton1 - lastTimePressedButton1   > DEBOUNCEDELAY)
    {
      button1PressAction();
      lastTimePressedButton1 = timeNowButton1;
    }
  }
}

void checkButton2(void)
{
  bool buttonState = digitalRead(BUTTON2);
  if (buttonState == 0) //pressed
  {
    timeNowButton2 = millis();
    if (timeNowButton2 - lastTimePressedButton2   > DEBOUNCEDELAY)
    {
      button2PressAction();
      lastTimePressedButton2 = timeNowButton2;
    }
  }
}
