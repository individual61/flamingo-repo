#include <buttons.h>
#include <parameters.h>


uint8_t button1state;
uint8_t button2state;
uint8_t button1prevstate;
uint8_t button2prevstate;

unsigned long debounceDelay = 300;
unsigned long timeNowButton1 = 0;
unsigned long timeNowButton2 = 0;
unsigned long lastTimePressedButton1 = 0;
unsigned long lastTimePressedButton2 = 0;

int brightnessIndex = 0;
int brightnessCount = 10;
int brightness[10] = {10, 15, 20, 40, 60, 100, 140, 180, 220, 240};

int programIndex = 1; // start at 1
int num_programs = 6;

void button1PressAction(void)
{

  if (brightnessIndex++ >= brightnessCount - 1)
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
  if (programIndex++ >= num_programs)
  {
    programIndex = 1;
  }
  Serial.print("Button 2 pressed, program is: ");
  Serial.println(programIndex);
}


void checkButton1(void)
{
  bool buttonState = digitalRead(BUTTON1);
  if (buttonState == 0)
  {
    timeNowButton1 = millis();
    if (timeNowButton1 - lastTimePressedButton1   > debounceDelay)
    {
      button1PressAction();
      lastTimePressedButton1 = timeNowButton1;
    }
  }
}

void checkButton2(void)
{
  bool buttonState = digitalRead(BUTTON2);
  if (buttonState == 0)
  {
    timeNowButton2 = millis();
    if (timeNowButton2 - lastTimePressedButton2   > debounceDelay)
    {
      button2PressAction();
      lastTimePressedButton2 = timeNowButton2;
    }
  }
}
