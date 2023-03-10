#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void SnowSparkle()
{
  while (1)
  {
    if (x)
      break;
    setAll(r, g, b);
    int Pixel = random(NUM_LEDS);
    setPixel(Pixel, 0xff, 0xff, 0xff);
    setPixel(Pixel + 1, 0xff, 0xff, 0xff);
    setPixel(Pixel + 2, 0xff, 0xff, 0xff);
    show();
    vTaskDelay(8);
    setPixel(Pixel, r, g, b);
    show();

    vTaskDelay(50);
  }
}