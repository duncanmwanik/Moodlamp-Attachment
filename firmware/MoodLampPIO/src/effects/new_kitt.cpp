#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

int speedsReturn[] = {150, 120, 60, 30, 10};
int speedsDelay[] = {50, 30, 20, 10, 5};

void CenterToOutside(byte red, byte green, byte blue, int EyeSize)
{
  for (int i = ((NUM_LEDS - EyeSize) / 2); i >= 0; i--)
  {
    if (x)
      break;
    setAll(0, 0, 0);

    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++)
    {
      if (x)
        break;
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);

    setPixel(NUM_LEDS - i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++)
    {
      if (x)
        break;
      setPixel(NUM_LEDS - i - j, red, green, blue);
    }
    setPixel(NUM_LEDS - i - EyeSize - 1, red / 10, green / 10, blue / 10);

    show();

    vTaskDelay(speedsDelay[speed]);
  }
  vTaskDelay(speedsReturn[speed]);
}

void OutsideToCenter(byte red, byte green, byte blue, int EyeSize)
{
  for (int i = 0; i <= ((NUM_LEDS - EyeSize) / 2); i++)
  {
    if (x)
      break;
    setAll(0, 0, 0);

    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++)
    {
      if (x)
        break;
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);

    setPixel(NUM_LEDS - i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++)
    {
      if (x)
        break;
      setPixel(NUM_LEDS - i - j, red, green, blue);
    }
    setPixel(NUM_LEDS - i - EyeSize - 1, red / 10, green / 10, blue / 10);

    show();

    vTaskDelay(speedsDelay[speed]);
  }
  vTaskDelay(speedsReturn[speed]);
}

void LeftToRight(byte red, byte green, byte blue, int EyeSize)
{
  for (int i = 0; i < NUM_LEDS - EyeSize - 2; i++)
  {
    if (x)
      break;
    setAll(0, 0, 0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++)
    {
      if (x)
        break;
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    show();

    vTaskDelay(speedsDelay[speed]);
  }
  vTaskDelay(speedsReturn[speed]);
}

void RightToLeft(byte red, byte green, byte blue, int EyeSize)
{
  for (int i = NUM_LEDS - EyeSize - 2; i > 0; i--)
  {
    if (x)
      break;
    setAll(0, 0, 0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for (int j = 1; j <= EyeSize; j++)
    {
      if (x)
        break;
      setPixel(i + j, red, green, blue);
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    show();

    vTaskDelay(speedsDelay[speed]);
  }
  vTaskDelay(speedsReturn[speed]);
}

void NewKITT()
{
  int EyeSize = 8;
  while (1)
  {
    if (x)
      break;
    RightToLeft(r, g, b, EyeSize);
    LeftToRight(r, g, b, EyeSize);
    OutsideToCenter(r, g, b, EyeSize);
    CenterToOutside(r, g, b, EyeSize);
    LeftToRight(r, g, b, EyeSize);
    RightToLeft(r, g, b, EyeSize);
    OutsideToCenter(r, g, b, EyeSize);
    CenterToOutside(r, g, b, EyeSize);
  }
}