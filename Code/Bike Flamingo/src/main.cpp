#include <Arduino.h>
#include <FastLED.h>
#include <EnableInterrupt.h>

enum states
{
  PROGRAM_1,
  PROGRAM_2
};
states the_state = PROGRAM_1;

#define BUTT_A 9
#define BUTT_B 10
#define BUTT_C 11

#define DEBOUNCE_DELAY 50 // in ms

#define CLOCK 3
#define DATA 2

#define DEBUG 1

uint32_t last_interrupt_time = 0;

uint8_t led_status = 0;
int caca = 0;

bool buttA = 0;
bool buttB = 0;
bool buttC = 0;

void isr_handler_A()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
#ifdef DEBUG
    Serial.println("Button A");
#endif
  }

  last_interrupt_time = interrupt_time;
}

void isr_handler_B()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
#ifdef DEBUG
    Serial.println("Button B");
#endif
  }

  last_interrupt_time = interrupt_time;
}

void isr_handler_C()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
#ifdef DEBUG
    Serial.println("Button C");
#endif
  }

  last_interrupt_time = interrupt_time;
}

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("Started serial to PC.");

  pinMode(BUTT_A, INPUT);
  pinMode(BUTT_B, INPUT);
  pinMode(BUTT_C, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  enableInterrupt(BUTT_A, isr_handler_A, FALLING);
  enableInterrupt(BUTT_B, isr_handler_B, FALLING);
  enableInterrupt(BUTT_C, isr_handler_C, FALLING);
}

void loop()
{
  /* buttA = digitalRead(BUTT_A);
   buttB = digitalRead(BUTT_B);
   buttC = digitalRead(BUTT_C);
   Serial.print(buttA);
   Serial.print("\t");
   Serial.print(buttB);
   Serial.print("\t");
   Serial.println(buttC);*/

  /*   switch (the_state)
     {

     case WAITING_FOR_SHAKE:

       Serial.print("WAITING_FOR_SHAKE ");
     }*/
}
