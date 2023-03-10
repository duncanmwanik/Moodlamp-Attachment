#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void TheaterChase()
{
  int tcSpeeds[] = {180, 120, 60, 30, 20};
  while (1)
  {
    if (x)
      break;
    // do 10 cycles of chasing
    for (int j = 0; j < 10; j++)
    {
      if (x)
        break;
      for (int q = 0; q < 3; q++)
      {
        if (x)
          break;
        for (int i = 0; i < NUM_LEDS; i = i + 3)
        {
          if (x)
            break;
          setPixel(i + q, r, g, b); // turn every third pixel on
        }
        show();

        vTaskDelay(tcSpeeds[speed]);

        for (int i = 0; i < NUM_LEDS; i = i + 3)
        {
          if (x)
            break;
          setPixel(i + q, 0, 0, 0); // turn every third pixel off
        }
      }
    }
  }
}