#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void RunningLights()
{
    int speeds[] = {200, 100, 50, 30, 15};
    int Position = 0;
    while (1)
    {
        if (x)
            break;
        for (int j = 0; j < NUM_LEDS * 2; j++)
        {
            if (x)
                break;
            Position++; // = 0; //Position + Rate;
            for (int i = 0; i < NUM_LEDS; i++)
            {
                if (x)
                    break;
                // sine wave, 3 offset waves make a rainbow!
                // float level = sin(i+Position) * 127 + 128;
                // setPixel(i,level,0,0);
                // float level = sin(i+Position) * 127 + 128;
                setPixel(i, ((sin(i + Position) * 127 + 128) / 255) * r,
                         ((sin(i + Position) * 127 + 128) / 255) * g,
                         ((sin(i + Position) * 127 + 128) / 255) * b);
            }

            show();

            vTaskDelay(speeds[speed]);
        }
    }
}