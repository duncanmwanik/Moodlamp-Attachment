#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void HalloweenEyes(int type)
{
  int EyeWidth = 1;
  int EyeSpace = 4;
  boolean Fade = true;
  int Steps = random(5, 50);
  unsigned long EndPause[] = {1500, 1250, 1000, 750, 500};

  while (1)
  {
    if (x)
      break;

    int i;
    int StartPoint = random(0, NUM_LEDS - (2 * EyeWidth) - EyeSpace);
    int Start2ndEye = StartPoint + EyeWidth + EyeSpace;
    long rcolor = MainColors[random(12)];
    int FadeDelay = random(50, 150);

    for (i = 0; i < EyeWidth; i++)
    {
      if (x)
        break;

      if (type == 0)
      {
        setPixel(StartPoint + i, r, g, b);
        setPixel(Start2ndEye + i, r, g, b);
      }
      if (type == 1)
      {
        led[StartPoint + i] = rcolor;
        led[Start2ndEye + i] = rcolor;
      }
    }

    show();

    if (Fade == true)
    {
      long randomR, randomG, randomB;
      randomR = rcolor >> 16;
      randomG = (rcolor & 0x00ff00) >> 8;
      randomB = (rcolor & 0x0000ff);

      for (int j = Steps; j >= 0; j--)
      {
        if (x)
          break;

        if (type == 0)
        {
          float r1 = j * (r / Steps);
          float g1 = j * (g / Steps);
          float b1 = j * (b / Steps);

          for (i = 0; i < EyeWidth; i++)
          {
            if (x)
              break;

            setPixel(StartPoint + i, r1, g1, b1);
            setPixel(Start2ndEye + i, r1, g1, b1);
          }
        }
        if (type == 1)
        {
          float r1 = j * (randomR / Steps);
          float g1 = j * (randomG / Steps);
          float b1 = j * (randomB / Steps);

          for (i = 0; i < EyeWidth; i++)
          {
            if (x)
              break;

            setPixel(StartPoint + i, r1, g1, b1);
            setPixel(Start2ndEye + i, r1, g1, b1);
          }
        }
        show();

        vTaskDelay(FadeDelay);
      }
    }

    setAll(0, 0, 0); // Set all black

    while (1)
    {
      if (x)
        break;
      unsigned long lastExecutedMillis = 0;
      unsigned long currentMillis = millis();
      if (currentMillis - lastExecutedMillis >= EndPause[speed])
      {
        lastExecutedMillis = currentMillis; // save the last executed time
        break;
      }
    }
  }
}