#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

int wrap(int step)
{
    if (step < 0)
        return NUM_LEDS + step;
    if (step > NUM_LEDS - 1)
        return step - NUM_LEDS;
    return step;
}

void Palette()
{
    // Palette variables
    int color;
    int center = 0;
    int step = -1;
    int maxSteps = 8;
    float fadeRate = 0.80;
    int speeds[] = {100, 75, 50, 25, 10};

    while (1)
    {
        if (x)
            break;
        if (step == -1)
        {
            center = random(NUM_LEDS);
            color = random(256);
            step = 0;
        }

        if (step == 0)
        {
            led[center] = CHSV(color, 255, 255); // strip.setPixelColor(center, Wheel(color, 1));
            step++;
        }
        else
        {
            if (step < maxSteps)
            {
                led[wrap(center + step)] = CHSV(color, 255, pow(fadeRate, step) * 255); //   strip.setPixelColor(wrap(center + step), Wheel(color, pow(fadeRate, step)));
                led[wrap(center - step)] = CHSV(color, 255, pow(fadeRate, step) * 255); //   strip.setPixelColor(wrap(center - step), Wheel(color, pow(fadeRate, step)));
                if (step > 3)
                {
                    led[wrap(center + step - 3)] = CHSV(color, 255, pow(fadeRate, step - 2) * 255); //   strip.setPixelColor(wrap(center + step - 3), Wheel(color, pow(fadeRate, step - 2)));
                    led[wrap(center - step + 3)] = CHSV(color, 255, pow(fadeRate, step - 2) * 255); //   strip.setPixelColor(wrap(center - step + 3), Wheel(color, pow(fadeRate, step - 2)));
                }
                step++;
            }
            else
            {
                step = -1;
            }
        }

        show();

        vTaskDelay(speeds[speed]);
    }
}