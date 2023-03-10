#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void ColorWipe(int type)
{
  int cSpeeds[] = {175, 130, 50, 20, 5};
  while (1)
  {
    if (x)
      break;

    if (type == 0)
    {
      for (int r = 0; r < 3; r++)
      {
        if (x)
          break;

        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
          if (x)
            break;

          led[i] = RGBColors[r];
          show();

          vTaskDelay(cSpeeds[speed]);
        }
      }
    }

    if (type == 1)
    {
      for (int m = 0; m < 12; m++)
      {
        if (x)
          break;

        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
          if (x)
            break;

          led[i] = MainColors[m];
          show();
          vTaskDelay(cSpeeds[speed]);
        }
      }
    }

    if (type == 2)
    {
      byte red = random(255);
      byte green = random(255);
      byte blue = random(255);

      for (uint16_t i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;

        led[i].setRGB(red, green, blue);
        show();
        vTaskDelay(cSpeeds[speed]);
      }
    }
  }
}

void ColorWipeCenter(int type)
{
  int cSpeeds[] = {175, 130, 50, 20, 5};
  while (1)
  {
    if (x)
      break;

    if (type == 0)
    {
      for (int r = 0; r < 3; r++)
      {
        if (x)
          break;

        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
          if (x)
            break;

          led[i] = RGBColors[r];
          show();

          vTaskDelay(cSpeeds[speed]);
        }
      }
    }

    if (type == 1)
    {
      for (int m = 0; m < 12; m++)
      {
        if (x)
          break;

        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
          if (x)
            break;

          led[i] = MainColors[m];
          show();
          vTaskDelay(cSpeeds[speed]);
        }
      }
    }

    if (type == 2)
    {
      byte red = random(255);
      byte green = random(255);
      byte blue = random(255);

      for (uint16_t i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;

        led[i].setRGB(red, green, blue);
        show();
        vTaskDelay(cSpeeds[speed]);
      }
    }
  }
}