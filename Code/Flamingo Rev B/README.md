Derived from the original version of Flamingo as presented at LiB 2015, then updated in 2017.

Runs on original, through-hole Flamingo hardware.

Hardware:

- Adafruit Pro Trinket 5 V
- Battery Backpack
- ADXL345/GY-291
- Adafruit APA102C pins.
- Qty 2 buttons

Setup guide, because I always forget. 

***Connections

I connect an Adafruit FTDI Fried, or CP2104 (discontinued) to the FTDI header of the Pro Trinket. I forget why I preferred this but I think it's better than uploading via USB. I USB might require unplugging and re-plugging but I'm not sure. 

I use a sparse APA102C strip for testing, at least initially. Not sure if my USB port can handle the current draw. I also have my power supply to power the light strip directly.

The grounds in this setup are linked at the light strip itself, which means that as long as the APA102C ground connects to USB ground on the Pro Trinket, they are linked. I'm pretty sure this is the case. 

WHen the light strip is powered this way, the Arduino is always powered on. 

Starting the serial monitor resets the Arduino.

***