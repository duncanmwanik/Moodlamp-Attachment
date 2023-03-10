#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

byte *WheelC(byte WheelPos)
{
  static byte c[3];

  if (WheelPos < 85)
  {
    c[0] = WheelPos * 3;
    c[1] = 255 - WheelPos * 3;
    c[2] = 0;
  }
  else if (WheelPos < 170)
  {
    WheelPos -= 85;
    c[0] = 255 - WheelPos * 3;
    c[1] = 0;
    c[2] = WheelPos * 3;
  }
  else
  {
    WheelPos -= 170;
    c[0] = 0;
    c[1] = WheelPos * 3;
    c[2] = 255 - WheelPos * 3;
  }

  return c;
}

void RainbowCycle()
{
  int speeds[] = {60, 40, 20, 10, 2};
  byte *c;
  uint16_t i, j;

  while (1)
  {
    if (x)
      break;
    for (j = 0; j < 256 * 5; j++)
    {
      if (x)
        break;
      for (i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;
        c = WheelC(((i * 256 / NUM_LEDS) + j) & 255);
        setPixel(i, *c, *(c + 1), *(c + 2));
      }
      show();

      vTaskDelay(speeds[speed]);
    }

    vTaskDelay(10);
  }
}