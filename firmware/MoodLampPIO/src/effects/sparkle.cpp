#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void Sparkle(int c)
{
  int speedsDelay[] = {200, 100, 60, 25, 10};

  while (1)
  {
    if (x)
      break;
    int Pixel = random(NUM_LEDS);
    if (c == 0)
      setPixel(Pixel, r, g, b);
    if (c == 1)
      led[Pixel] = MainColors[random(12)];
    if (c == 2)
      setPixel(Pixel, random(255), random(255), random(255));
    show();

    vTaskDelay(speedsDelay[speed]);
    setPixel(Pixel, 0, 0, 0);
  }
}