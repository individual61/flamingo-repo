#include <Arduino.h>

#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <ADXL345.h>
#include <MPU6050.h>
#include <math.h>


#define PLOT 1

/*
  ADXL345 - Arduino
  CS ->3V3
  SDO -> GND
  SDA ->A4
  SCL -> A5
  VCC ->3V3
  GND -> GND
  10k between VCC and SCL
  10k between VCC and SDA

  Dotstars:
  Green/data - 11
  Yellow/clock - 13
  Gnd to Gnd
  Cap across VCC and gnd
*/
#define BUTTON1 3
#define BUTTON2 4

#define NUMPIXELS 144 // Number of LEDs in strip
#define NUMPERSTRAND 48

#define GFACTOR 0.2//-0.0654 // 9.81/150

/////////////////////////// BUTTONS ////////////////////

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

//////////////////// DOTSTARS //////////////////

// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int      head  = 0, tail = -10; // Index of first 'on' and 'off' pixels
uint32_t color = 0x106040;      // 'On' color (starts red)


////////////////////// ADXL345 /////////////////////////
// class default I2C address is 0x53
// specific I2C addresses may be passed as a parameter here
// ALT low = 0x53 (default for SparkFun 6DOF board)
// ALT high = 0x1D
ADXL345 accel;

int16_t ay;
float g0y, gy;
float pos0, pos1, vel0, vel1, acc0, acc1, acc_ext;
uint16_t timeold_i, timenow_i;
float timenow_f, timestep_f, timestep_i;
bool first_iter = 0;
uint16_t sendTime = 0;

bool kittReverse = 0;

#define SPRINGCONSTANT 2
#define DAMPING 0.4
#define MAXRANGE 15.0


// Returns the accelerometer difference from 1 g in m/s^2
float getOffsetAccel(void)
{
  float acc = GFACTOR * (g0y - accel.getAccelerationY());
  return acc;
}

// Measures 1 second of accelerometer values and averages to create offset.
void initAccelOffset(void)
{
  unsigned long accel_init_start_time;
  uint16_t accel_init_average_count = 0;
  accel_init_start_time = millis();
  g0y = 0;
  gy = 0;
  while (millis() - accel_init_start_time < 1000)
  {
    g0y = g0y + accel.getAccelerationY();
    accel_init_average_count++;
  }
  g0y = g0y / ((float)accel_init_average_count);

#ifndef PLOT
  Serial.print("Number of measurements: ");
  Serial.print(accel_init_average_count);
  Serial.print(".\tAvg gy:");
  Serial.println(g0y);
#endif
}



//////// DAMPED HARMONIC OSCILLATOR FUNCTIONS ///////////////

float eval_v_func(float v, float x, float acc_ext)
{
  return -DAMPING * v - SPRINGCONSTANT * x + acc_ext; // return (-c*v -sin(x) + F*cos(w*t));
}

float get_next_v(float oldv, float oldx, float acc_ext)
{
  float k1, k2, k3, k4;
  k1 = eval_v_func(oldv,          oldx, acc_ext);
  k2 = eval_v_func(oldv + 0.5 * k1, oldx, acc_ext);
  k3 = eval_v_func(oldv + 0.5 * k2, oldx, acc_ext);
  k4 = eval_v_func(oldv + k3,     oldx, acc_ext);
  return oldv + timestep_f * (  (k1 / 6.0) + (k2 / 3.0) + (k3 / 3.0) + (k4 / 6.0)  );
}

float get_next_x(float oldv, float oldx)
{
  return (oldx + timestep_f * oldv);
}

// DAMPED HARMONIC OSCILLATOR. Returns object position as a fraction of max range,
// centered on 0, so maxrange is half the length of the strip
float getBallPosition(void)
{
  if (first_iter == 1) // first iteration
  {
    pos0 = 0.0;
    vel0 = 0.0;
    timeold_i = 0;
    timenow_i = 0;
    timestep_i = timenow_i - timeold_i;
    timestep_f = 0.01 * ((float)timestep_i);

    acc_ext = getOffsetAccel();
    vel1 = get_next_v(vel0, pos0, acc_ext);
    pos1 = get_next_x(vel0, pos0);

    timeold_i = timenow_i;
    pos0 = pos1;
    vel0 = vel1;

    first_iter = 0;
    timeold_i = millis();
  }
  else
  {
    timenow_i = millis();
    timestep_i = timenow_i - timeold_i;
    timestep_f = 0.01 * ((float)timestep_i);

    acc_ext = getOffsetAccel();
    vel1 = get_next_v(vel0, pos0, acc_ext);
    pos1 = get_next_x(vel0, pos0);
    vel0 = vel1;
    pos0 = pos1;
    timeold_i = timenow_i;

    /*    uint16_t timet = millis();
        if (timet - sendTime > 100)
        {

            #ifndef PLOT
            Serial.print("Timestep:\t");
            Serial.print(timestep_i);
            Serial.print("\tPosition:\t");
            Serial.print(pos1);
            Serial.print("\tVel:\t");
            Serial.print(vel1);
            Serial.print("\tAcc ext:\t");
            Serial.println(acc_ext);
            #else
            Serial.println(pos1);
            //      Serial.print(",");
            //      Serial.println(acc_ext);
            #endif
          sendTime = timet;
        }
    */
  }
  return pos1 / MAXRANGE;
}

int ballToStrandPosition(float ballPos)
{
  return ((int)(ballPos * ((float) NUMPERSTRAND / 2.0)));
}

// Takes an index from 0 to NUMPERSTRAND -1 and sets all three strands.
void setPixelByIndex(int index, uint32_t color)
{
  if ((index > 0) && (index < NUMPERSTRAND))
  {
    int realindex = 0;
    realindex = NUMPERSTRAND - index - 1;
    strip.setPixelColor(realindex, color);
    realindex = NUMPERSTRAND + index ;
    strip.setPixelColor(realindex, color);
    realindex = 3 * NUMPERSTRAND - index - 1;
    strip.setPixelColor(realindex, color);
  }
}

//////////// RAINBOW
byte *c;
uint16_t jrainbow = 0;
byte * Wheel(byte WheelPos)
{
  static byte c[3];
  if (WheelPos < 85)
  { c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  }
  else if (WheelPos < 170)
  {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  } else {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }
  for (int i = 0; i < 3; i++)
  {
    c[i] = (int) c[i] * 0.4;
  }
  return c;
}

void setPixelHeatColorgreen(int Pixel, byte temperature)
{ // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);
  // calculate ramp up from
  byte heatramp = t192 & 0x3F;
  // 0..63
  heatramp <<= 2;
  // scale up to 0..252
  // figure out which third of the spectrum we're in:

  if ( t192 > 0x80)
  { // hottest
    setPixelByIndex(Pixel, strip.Color(255, 255, heatramp));
  }
  else if ( t192 > 0x40 )
  { // middle
    setPixelByIndex(Pixel, strip.Color(255, heatramp, 0));
  }
  else
  { // coolest
    setPixelByIndex(Pixel, strip.Color(heatramp, 0, 0));
  }
}

/*
void setPixelHeatColorpink(int Pixel, byte temperature)
{ // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);
  // calculate ramp up from
  byte heatramp = t192 & 0x3F;
  // 0..63
  heatramp <<= 2;
  // scale up to 0..252
  // figure out which third of the spectrum we're in:
  Serial.println(heatramp);
  if ( t192 > 0x80)
  { // hottest
    setPixelByIndex(Pixel, strip.Color(32*heatramp/255.0, 96*heatramp/255.0, 80*heatramp/255.0));
  }
  else if ( t192 > 0x40 )
  { // middle
    setPixelByIndex(Pixel, strip.Color(16*heatramp/255.0, 96*heatramp/255.0, 64*heatramp/255.0));
  }
  else
  { // coolest
    setPixelByIndex(Pixel, strip.Color(64*heatramp/255.0, 96*heatramp/255.0, 64*heatramp/255.0));
  }
}
*/

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






/////////



void setup() {

  // initialize serial communication
  Serial.begin(115200);


  //////////////////////// BUTTONS /////////////////

  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  //////////////////////// ADXL345 //////////////////////
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

  // initialize device
#ifndef PLOT
  Serial.println("Initializing ADXL345...");
#endif
  accel.initialize();

  // verify connection
#ifndef PLOT
  Serial.print("Testing ADXL345 connections...");
  Serial.println(accel.testConnection() ? "\tADXL345 connection successful" : "\tADXL345 connection failed");
  Serial.println("");
#endif

#ifndef PLOT
  Serial.print("Setting offset: ");
#endif // PLOT
  accel.setOffsetY(0);

#ifndef PLOT
  Serial.print("Setting Range to 2");
#endif // PLOT
  accel.setRange(2);
#ifndef PLOT
  Serial.println("");
#endif // PLOT

  initAccelOffset(); // Measures 3 seconds of accelerometer values and averages to create offset.

  //////////////////// DOTSTARS //////////////////////
  strip.begin(); // Initialize pins for output
  strip.setBrightness(30);
  strip.clear();
  strip.show();  // Turn all LEDs off ASAP

  /////// MISC //////

  timeold_i = 0;
  timenow_i = 0;
  timenow_f = 0.0;
  timestep_i = 0;
  timestep_f = 0.0;

}



void loop() {
  ///////////// BUTTONS /////////////

  checkButton1();
  checkButton2();


  //////////////////////// ADXL345 //////////////////////

  // Single pixel damped harmonic oscillator.
  if (programIndex == 1)
  {
    float BallPosition = getBallPosition();

    for (int i = 0; i < NUMPERSTRAND; i++)
    {
      setPixelByIndex(i, 0);
    }
    setPixelByIndex(48 - (24 + ballToStrandPosition(BallPosition)) - 1, color);
    strip.show();
  }



  if (programIndex == 2)
  {
    float BallPosition = getBallPosition();

    for (int i = 0; i < NUMPERSTRAND; i++)
    {
      setPixelByIndex(i, 0);
    }
    int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;
    float attnFactor;
    float gaussianTable[15] = {0.05, 0.11, 0.21, 0.37, 0.57, 0.78, 0.94, 1.00, 0.94, 0.78, 0.57, 0.37, 0.21, 0.11, 0.05};
    for (int k = -7; k <= 7; k++)
    {
      attnFactor = gaussianTable[k + 7];
      /*    Serial.print("attnFactor: ");
          Serial.println(attnFactor);
                Serial.print("k: ");
          Serial.println(k);*/
      setPixelByIndex(centerindex + k, strip.Color((int)(16 * attnFactor), (int)(96 * attnFactor), (int)(64 * attnFactor)));

    }
    strip.show();
  }



  if (programIndex == 3)
  {
    for (int i = 0; i < NUMPERSTRAND; i++)
    {
      c = Wheel(((i * 256 / NUMPERSTRAND) + jrainbow) & 255);
      setPixelByIndex(i, strip.Color(*c, *(c + 1), *(c + 2)));
    }
    strip.show();
    delay(20);
    jrainbow++;
    if (jrainbow == 256 * 5)
    {
      jrainbow = 0;
    }
  }

  if (programIndex == 4)
  {
    float BallPosition = getBallPosition();

    /*   for (int i = 0; i < NUMPERSTRAND; i++)
       {
         setPixelByIndex(i, 0);
       }*/
    int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;

    for (int i = 0; i < NUMPERSTRAND; i++)
    {
      c = Wheel(((i * 256 / NUMPERSTRAND) + 2 * centerindex) & 255);
      setPixelByIndex(i, strip.Color(*c, *(c + 1), *(c + 2)));
    }
    strip.show();
  }


  if (programIndex == 5)
  {
    float BallPosition = getBallPosition();

    for (int i = 0; i < NUMPERSTRAND; i++)
    {
      setPixelByIndex(i, 0);
    }
    int centerindex = 48 - (24 + ballToStrandPosition(BallPosition)) - 1;
    float attnFactor;
    float sinTable[97] = {0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                          0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                          0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                          0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07, 0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                          0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                          0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07,
                          0.00, 0.07, 0.25, 0.50, 0.75, 0.93, 1.00, 0.93, 0.75, 0.50, 0.25, 0.07, 0.00
                         };
    for (int k = -48; k <= 48; k++)
    {
      attnFactor = sinTable[k + 48];
      /*    Serial.print("attnFactor: ");
          Serial.println(attnFactor);
                Serial.print("k: ");
          Serial.println(k);*/
      setPixelByIndex(centerindex + k, strip.Color((int)(16 * attnFactor), (int)(96 * attnFactor), (int)(64 * attnFactor)));

    }
    strip.show();
  }


  if (programIndex == 6)
  {
    //Fire(55, 120, 15);
    int Cooling = 55;
    int Sparking = 120;
    int SpeedDelay = 15;

    static byte heat[NUMPERSTRAND];
    int cooldown;
    // Step 1.  Cool down every cell a little
    for ( int i = 0; i < NUMPERSTRAND; i++)
    {
      cooldown = random(0, ((Cooling * 10) / NUMPERSTRAND) + 2);
      if (cooldown > heat[i]) {
        heat[i] = 0;
      }
      else
      {
        heat[i] = heat[i] - cooldown;
      }
    }
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for ( int k = NUMPERSTRAND - 1; k >= 2; k--)
    {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }
    // Step 3.  Randomly ignite new 'sparks' near the bottom
    if ( random(255) < Sparking )
    {
      int y = random(7);
      heat[y] = heat[y] + random(160, 255);
      //heat[y] = random(160,255);
    }
    // Step 4.  Convert heat to LED colors
    for ( int j = 0; j < NUMPERSTRAND; j++)
    {
      setPixelHeatColorgreen(j, heat[j] );
    }
    strip.show();
    strip.show();
    delay(SpeedDelay);
  }

/*
  if (programIndex == 6)
  {
    //Fire(55, 120, 15);
    int Cooling = 55;
    int Sparking = 120;
    int SpeedDelay = 15;

    static byte heat[NUMPERSTRAND];
    int cooldown;
    // Step 1.  Cool down every cell a little
    for ( int i = 0; i < NUMPERSTRAND; i++)
    {
      cooldown = random(0, ((Cooling * 10) / NUMPERSTRAND) + 2);
      if (cooldown > heat[i]) {
        heat[i] = 0;
      }
      else
      {
        heat[i] = heat[i] - cooldown;
      }
    }
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for ( int k = NUMPERSTRAND - 1; k >= 2; k--)
    {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
    }
    // Step 3.  Randomly ignite new 'sparks' near the bottom
    if ( random(255) < Sparking )
    {
      int y = random(7);
      heat[y] = heat[y] + random(160, 255);
      //heat[y] = random(160,255);
    }
    // Step 4.  Convert heat to LED colors
    for ( int j = 0; j < NUMPERSTRAND; j++)
    {
      setPixelHeatColorgreen(j, heat[j] );
    }
    strip.show();
    delay(SpeedDelay);
  }

*/



}
