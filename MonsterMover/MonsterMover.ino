#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 6
#define PIN2 7

//Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(40, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  strip2.begin();
  strip2.show();
}

boolean goForward = true;

// Desgined for 25 pixels.. Armmy man lunging at monster
void lungeAttackAnimation()
{
  for(uint16_t i = 0; i<strip.numPixels(); i++)
  {
    for(uint16_t j = 0; j<strip.numPixels(); j++)
      strip.setPixelColor(j, 0x000000);

    uint16_t stripNumber = 0;
    if(goForward)
      stripNumber = i;
    else
      stripNumber = strip.numPixels() - i - 1;

    //strip.setPixelColor(stripNumber, wheel(map(stripNumber, 0, 25, 0, 255)) );
    if(stripNumber < 5)
    {
      strip.setPixelColor(stripNumber, 0xFF0000);
    }
    else
    {
      strip.setPixelColor(stripNumber, 0xAAAAFF);
    }

    if(stripNumber < 5)
    {
      delay(50);
    }
    else if(stripNumber < 10)
    {
      delay(100 - ((stripNumber-5)*10));
    }
    else
    {
      delay(100);
    }
      

    Serial.println(strip.numPixels() - i);

    strip.show();
  }

  goForward = !goForward;
}

void strobeEveryOther()
{
  boolean everyOther = true;

  for(uint16_t i = 0; i<strip.numPixels(); i++)
  {
    for(uint16_t j = 0; j<strip.numPixels(); j++)
    {
      strip.setPixelColor(j, 0x000000);
      strip2.setPixelColor(j, 0x000000);
    }

    uint16_t stripNumber = 0;
    stripNumber = strip.numPixels() - i - 1;

    if(goForward)
      stripNumber = i;
    else
      stripNumber = strip.numPixels() - i - 1;

    if(everyOther)
    {
      strip.setPixelColor(stripNumber, 0xFFFFFF);
      strip2.setPixelColor(stripNumber, 0x5555FF);
    }
    else
    {
      strip.setPixelColor(stripNumber, 0x000000);
      strip2.setPixelColor(stripNumber, 0x000000);
    }
    everyOther = !everyOther;

    delay(30);
      

    strip.show();
    strip2.show();
  }

  goForward = !goForward;
}

void lungeAttackAnimation2Strip()
{
  boolean everyOther = false;
  for(uint16_t i = 0; i < strip2.numPixels(); i++)
  {
      strip2.setPixelColor(i, 0x000000);
  }

  for(uint16_t i = 0; i<strip.numPixels(); i++)
  {
    if(everyOther)
      strip2.setPixelColor(12, 0xFFFFFF);
    else 
      strip2.setPixelColor(12, 0x000000);
    everyOther = !everyOther;

    for(uint16_t j = 0; j<strip.numPixels(); j++)
      strip.setPixelColor(j, 0x000000);

    uint16_t stripNumber = 0;
    if(goForward)
      stripNumber = i;
    else
      stripNumber = strip.numPixels() - i - 1;

    //strip.setPixelColor(stripNumber, wheel(map(stripNumber, 0, 25, 0, 255)) );
    if(stripNumber < 5)
    {
      strip.setPixelColor(stripNumber, 0xFF0000);
    }
    else
    {
      strip.setPixelColor(stripNumber, 0xAAAAFF);
    }

    if(stripNumber < 5)
    {
      delay(50);
    }
    else if(stripNumber < 10)
    {
      delay(100 - ((stripNumber-5)*10));
    }
    else
    {
      delay(100);
    }
      

    Serial.println(strip.numPixels() - i);

    strip.show();
    strip2.show();
  }

  goForward = !goForward;
}

void ContinuousForward()
{
  for(uint16_t i = 0; i<strip.numPixels(); i++)
  {
    for(uint16_t j = 0; j<strip.numPixels(); j++)
      strip.setPixelColor(j, 0x000000);

    uint16_t stripNumber = 0;
    stripNumber = strip.numPixels() - i - 1;

    for(int i = 0; i<2; i++)
    {
      if(stripNumber < 5)
        strip.setPixelColor(stripNumber + i, 0xFFFFFF);
      else
        strip.setPixelColor(stripNumber + i, 0xFFFFFF);
    }



    delay(100);
      

    Serial.println(strip.numPixels() - i);

    strip.show();
  }
}

void BackAndForthStrip2Only()
{
  for(uint16_t i = 0; i<strip2.numPixels(); i++)
  {
    for(uint16_t j = 0; j<strip2.numPixels(); j++)
    {
      strip2.setPixelColor(j, 0x000000);
    }

    uint16_t stripNumber = 0;
    stripNumber = strip2.numPixels() - i - 1;

    if(goForward)
      stripNumber = i;
    else
      stripNumber = strip2.numPixels() - i - 1;

    strip2.setPixelColor(stripNumber, 0xFFFFFF);

    delay(100);
      

    Serial.println(strip2.numPixels() - i);

    strip2.show();
  }

  goForward = !goForward;
}

void BackAndForth()
{
  for(uint16_t i = 0; i<strip.numPixels(); i++)
  {
    for(uint16_t j = 0; j<strip.numPixels(); j++)
    {
      strip.setPixelColor(j, 0x000000);
      strip2.setPixelColor(j, 0x000000);
    }

    uint16_t stripNumber = 0;
    stripNumber = strip.numPixels() - i - 1;

    if(goForward)
      stripNumber = i;
    else
      stripNumber = strip.numPixels() - i - 1;

    strip.setPixelColor(stripNumber, 0xFFFFFF);
    strip2.setPixelColor(stripNumber, 0xFFFFFF);

    delay(100);
      

    Serial.println(strip.numPixels() - i);

    strip.show();
    strip2.show();
  }

  goForward = !goForward;
}

void loop() {
  
  //strobeEveryOther();
 // lungeAttackAnimation2Strip();
  //lungeAttackAnimation();
  //ContinuousForward();
  //BackAndForth();
  BackAndForthStrip2Only();
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}