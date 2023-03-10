#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void MiniBoss()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (x)
      break;
    led[i] = 0x000000;
  }
  show();

  while (1)
  {
    if (x)
      break;
    for (int i = 56; i < NUM_LEDS; i++)
    {
      if (x)
        break;
      led[i].r = r;
      led[i].g = g;
      led[i].b = b;
    }
    show();
  }
}