#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

byte *WheelR(byte WheelPos)
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

void TheaterChaseRainbow()
{
  int speeds[] = {180, 120, 60, 30, 20};
  byte *c;

  while (1)
  {
    if (x)
      break;
    // cycle all 256 colors in the wheel
    for (int j = 0; j < 256; j++)
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

          c = WheelR((i + j) % 255);
          setPixel(i + q, *c, *(c + 1), *(c + 2)); // turn every third pixel on
        }
        show();

        vTaskDelay(speeds[speed]);

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