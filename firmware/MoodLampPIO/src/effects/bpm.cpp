#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void BPM()
{
    while (1)
    {
        if (x)
            break;
        // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
        int bpm[] = {15, 30, 60, 120, 180};

        CRGBPalette16 palette = PartyColors_p;
        uint8_t beat = beatsin8(bpm[speed], 64, 255);
        for (int i = 0; i < NUM_LEDS; i++)
        {
            if (x)
                break;

            led[i] = ColorFromPalette(palette, (i * 2), beat + (i * 10));
        }
        show();
    }
}