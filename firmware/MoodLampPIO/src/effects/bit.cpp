#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void Bit(int type)
{
    int speeds[] = {500, 300, 200, 50, 20};

    while (1)
    {
        if (x)
            break;
        for (int i = 0; i < NUM_LEDS; i++)
        {
            if (x)
                break;

            if (type == 0)
                setPixel(i, r, g, b);
            if (type == 1)
                led[i] = MainColors[random(12)];
            show();
            vTaskDelay(speeds[speed]);
            setPixel(i, 0, 0, 0);
            show();
        }
    }
}