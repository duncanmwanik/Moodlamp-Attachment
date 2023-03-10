#include <Arduino.h>
#include <FastLED.h>

#include "def.h"

#define FADE_RATE 40

void Twinkle2()
{
  int speeds[] = {40, 20, 10, 4, 1};

  while (1)
  {
    if (x)
      break;
    if (random(25) == 1)
    {
      uint16_t i = random(NUM_LEDS);
      led[i] = CRGB(random(256), random(256), random(256));
    }
    // fadeToBlackBy(led, NUM_LEDS, FADE_RATE);
    for (uint16_t i = 0; i < NUM_LEDS; i++)
    {
      if (x)
        break;
      led[i].nscale8(255 - FADE_RATE);
    }
    show();

    vTaskDelay(speeds[speed]);
  }
}
