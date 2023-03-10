#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void Twinkle(int mode)
{
  setAll(0, 0, 0);
  int count = 10;
  int speeds[] = {200, 150, 100, 50, 25};

  while (1)
  {
    if (x)
      break;
    for (int i = 0; i < count; i++)
    {
      if (x)
        break;
      if (mode == 0)
        setPixel(random(NUM_LEDS), r, g, b);

      if (mode == 1)
        setPixel(random(NUM_LEDS), random(255), random(255), random(255));
      show();

      vTaskDelay(speeds[speed]);
    }
    vTaskDelay(speeds[speed]);
  }
}