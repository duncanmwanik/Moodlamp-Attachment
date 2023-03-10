#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void Confetti()
{
    while (1)
    {
        if (x)
            break;
        // random colored speckles that blink in and fade smoothly
        // fadeToBlackBy(led, NUM_LEDS, 10);
        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
            if (x)
                break;
            led[i].nscale8(255 - 10);
        }
        int pos = random16(NUM_LEDS);
        led[pos] += CHSV(random8(64), 200, 255);
        show();

        vTaskDelay(100);
    }
}