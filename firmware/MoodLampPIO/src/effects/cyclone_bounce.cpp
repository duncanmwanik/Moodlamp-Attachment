#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void CylonBounce(int EyeSize)
{
  int speedsReturn[] = {150, 100, 50, 20, 5};
  int speedsDelay[] = {50, 30, 10, 5, 1};

  while (1)
  {
    if (x)
      break;
    for (int i = 0; i < NUM_LEDS - EyeSize - 2; i++)
    {
      if (x)
        break;
      setAll(0, 0, 0);
      setPixel(i, r / 10, g / 10, b / 10);
      for (int j = 1; j <= EyeSize; j++)
      {
        if (x)
          break;
        setPixel(i + j, r, g, b);
      }
      setPixel(i + EyeSize + 1, r / 10, g / 10, b / 10);
      show();

      vTaskDelay(speedsDelay[speed]);
    }

    vTaskDelay(speedsReturn[speed]);

    for (int i = NUM_LEDS - EyeSize - 2; i > 0; i--)
    {
      if (x)
        break;
      setAll(0, 0, 0);
      setPixel(i, r / 10, g / 10, b / 10);
      for (int j = 1; j <= EyeSize; j++)
      {
        if (x)
          break;
        setPixel(i + j, r, g, b);
      }
      setPixel(i + EyeSize + 1, r / 10, g / 10, b / 10);
      show();

      vTaskDelay(speedsDelay[speed]);
    }

    vTaskDelay(speedsReturn[speed]);
  }
}