#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void PartyOfColors()
{
  int speeds[] = {1500, 1000, 500, 250, 100};

  while (1)
  {
    if (x)
      break;
    for (int c = 0; c < 11; c++)
    {
      if (x)
        break;
      // fill_solid(led, NUM_LEDS, PartyColors[c]);
      for (int i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;
        led[i] = PartyColors[c];
      }
      show();

      vTaskDelay(speeds[speed]);
      // fill_solid(led, NUM_LEDS, 0x000000);
      for (int i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;
        led[i] = 0x000000;
      }
      show();
    }
  }
}