#include <Arduino.h>
#include <FastLED.h>

#include "def.h"

void RainbowRun()
{
  static uint8_t leftHue = 0;
  uint8_t rate = 5;
  int speeds[] = {60, 40, 20, 10, 2};

  while (1)
  {
    if (x)
      break;
    CHSV hsv;
    hsv.hue = leftHue;
    hsv.val = 255;
    hsv.sat = 240;
    for (int i = 0; i < NUM_LEDS; i++)
    {
      if (x)
        break;
      led[i] = hsv;
      hsv.hue += 7;
    }

    EVERY_N_MILLISECONDS(20)
    {
      if (x)
        break;
      leftHue = (leftHue + rate) % 255;
    }

    show();
    vTaskDelay(speeds[speed]);
  }
}
