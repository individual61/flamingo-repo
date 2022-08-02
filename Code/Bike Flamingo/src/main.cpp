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

#define CLOCK_PIN 3
#define DATA_PIN 2

#define NUMPIXELS 27 // Number of LEDs in strip

#define COLOR_ORDER BGR // my strip is BGR
#define CORRECTION TypicalLEDStrip
//#define CORRECTION UncorrectedColor

#define DEBUG 1

uint32_t last_interrupt_time = 0;

uint8_t led_status = 1;
int caca = 0;

bool buttA = 0;
bool buttB = 0;
bool buttC = 0;

CRGB leds[NUMPIXELS];

bool firstrun = 1;

// Change Program
void isr_handler_A()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
    last_interrupt_time = interrupt_time;
#ifdef DEBUG
    Serial.println("Button A");
#endif
  }
}

// TBD
void isr_handler_B()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
    last_interrupt_time = interrupt_time;

#ifdef DEBUG
    Serial.println("Button B");
#endif
  }
}

// Brightness
void isr_handler_C()
{
  uint32_t interrupt_time = millis();

  if (interrupt_time - last_interrupt_time > DEBOUNCE_DELAY)
  {
    last_interrupt_time = interrupt_time;

#ifdef DEBUG
    Serial.println("Button C");
#endif
  }
}

void Fire2012RainbowRotate(void)
{
  static uint8_t hue = 0;
  static uint8_t every = 0;
  if (firstRun)
  {
    FastLED.clear();
    firstRun = 0;
    Serial.println(F("Starting Program:\tFire With Rainbow Rotate"));
    Serial.print(F("Free SRAM:  "));
    Serial.println(freeRam());

    // gPal = HeatColors_p;
    // gPal = CRGBPalette16(CRGB::Black, CRGB::Blue, CRGB::Aqua, CRGB::White);
  }

  // Set up pallette
  if (every++ == 15)
  {
    every = 0;
    hue++;
  }
  CRGB darkcolor = CHSV(hue, 255, 192);  // pure hue, three-quarters brightness
  CRGB lightcolor = CHSV(hue, 128, 255); // half 'whitened', full brightness
  CRGBPalette16 gPal;
  gPal = CRGBPalette16(CRGB::Black, darkcolor, lightcolor, CRGB::White);
  //

  // Add entropy to random number generator; we use a lot of it.
  random16_add_entropy(random());
  // Array of temperature readings at each simulation cell
  static byte heat[NUMPERSTRAND];

  // Step 1.  Cool down every cell a little
  for (int i = 0; i < NUMPERSTRAND; i++)
  {
    heat[i] =
        qsub8(heat[i],
              random8(0, ((FIRE_PALLETTE_COOLING * 10) / NUMPERSTRAND) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for (int k = NUMPERSTRAND - 1; k >= 2; k--)
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if (random8() < FIRE_PALLETTE_SPARKING)
  {
    int y = random8(7);
    heat[y] = qadd8(heat[y], random8(160, 255));
  }

  // Step 4.  Map from heat cells to LED colors
  for (int j = 0; j < NUMPERSTRAND; j++)
  {
    // Scale the heat value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat[j], 100); // was 240
    CRGB acolor = ColorFromPalette(gPal, colorindex);
    setPixelByStrandIndex(j, acolor);
    //      Serial.print(color.r);
    //      Serial.print("\t");
    //      Serial.print(color.g);
    //      Serial.print("\t");
    //      Serial.println(color.b);
  }

  // Add sparks here

  // No more than N sparks at a time, N could be around 5
  // Random interval before birth
  // Sparks ascend at constant different and random rate
  // Sparks can die before reaching the top. They are born with "pixels to live"
  // Sparks die when reaching the top
  // Spark properties are time to live, where the spark is, speed

  for (int i = 0; i < 5; i++)
  {
    if (sparks[i].position >= NUMPERSTRAND - 1)
    {
      sparks[i].pixels_to_live =
          0; // We're at the end, so it's time to die
    }
    // for sparks that are alive
    if (sparks[i].pixels_to_live > 0)
    {
      // This spark is alive, so if it is time to move up
      // Move up
      sparks[i].position += sparks[i].rate;
      // Decrease life
      sparks[i].pixels_to_live -= sparks[i].rate;

      if (sparks[i].position < NUMPERSTRAND)
      {
        setPixelByStrandIndex(sparks[i].position, CRGB(255, 255, 255));
      }
    }
    else // this spark is not alive. There is a chance a new one could be
         // born!
    {
      if (random8() < 2)
      {
        // Make a new spark
        sparks[i].position =
            random8(0, NUMPERSTRAND / 2); // It could appear anywhere
                                          // near the base of the strand
        sparks[i].pixels_to_live =
            random8(4, (NUMPERSTRAND / 2) -
                           sparks[i].position); // It could last as
                                                // distance it has yet
                                                // to cover
        sparks[i].rate = random8(2, 3);
      }
    }
  }

  FastLED.show();           // display this frame
  FastLED.delay(1000 / 60); // 60 fps
}

void setup()
{
  Serial.begin(115200);
  // while (!Serial)
  //   ;
  Serial.println("Started serial to PC.");

  pinMode(BUTT_A, INPUT);
  pinMode(BUTT_B, INPUT);
  pinMode(BUTT_C, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);

  enableInterrupt(BUTT_A, isr_handler_A, FALLING);
  enableInterrupt(BUTT_B, isr_handler_B, FALLING);
  enableInterrupt(BUTT_C, isr_handler_C, FALLING);

  Serial.print(F("Initializing lights... "));
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUMPIXELS)
      .setCorrection(CORRECTION);

  FastLED.setBrightness(255);
  FastLED.clear();
  FastLED.show();
  Serial.println(F("Done."));
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

  switch (the_state)
  {

  case PROGRAM_1:
  {
    if (firstrun)
    {
      Serial.print("PROGRAM_1");
      firstrun = 0;
    }
    // FastLED random8(N, M) is from N to M-1
    uint8_t Pixel = random8(0, NUMPIXELS); // (...]
    // leds[Pixel] = thecolor;
    // CRGB color = 0x601040;  // Flamingo Pink for dotstars
    leds[Pixel] = 0xFFFFFF;
    FastLED.show();
    FastLED.delay(1);
    leds[Pixel] = CRGB(0, 0, 0);
    FastLED.show();
  }

  case PROGRAM_2:
  {
    if (firstrun)
    {
      Serial.print("PROGRAM_2");
      firstrun = 0;
    }
  }
  }
}
