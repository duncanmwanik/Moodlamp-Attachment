#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void Strobe()
{
  int speeds[] = {150, 100, 50, 30, 10};
  int StrobeCount = 8;
  while (1)
  {
    if (x)
      break;
    for (int j = 0; j < StrobeCount; j++)
    {
      if (x)
        break;
      setAll(r, g, b);
      show();
      vTaskDelay(speeds[speed]);
      setAll(0, 0, 0);
      show();
      vTaskDelay(speeds[speed]);
    }
    vTaskDelay(600);
  }
}