#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void Sinelon()
{
    while (1)
    {
        if (x)
            break;
        // FOR SYLON ETC
        uint8_t thisbeat = 23;
        uint8_t thatbeat = 28;
        uint8_t thisfade = 2;  // How quickly does it fade? Lower = slower fade rate.
        uint8_t thissat = 255; // The saturation, where 255 = brilliant colours.
        uint8_t thisbri = 255;

        int myhue = 0;
        // a colored dot sweeping back and forth, with fading trails
        // fadeToBlackBy(led, NUM_LEDS, thisfade);
        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
            if (x)
                break;
            led[i].nscale8(255 - thisfade);
        }
        int pos1 = beatsin16(thisbeat, 0, NUM_LEDS);
        int pos2 = beatsin16(thatbeat, 0, NUM_LEDS);
        led[(pos1 + pos2) / 2] += CHSV(myhue++ / 64, thissat, thisbri);

        show();
    }
}

void SinelonRandom()
{
    const uint8_t THIS_BEAT = 23;
    const uint8_t THAT_BEAT = 28;
    const uint8_t THIS_FADE = 2; // How quickly does it fade? Lower = slower fade rate.
    uint8_t myhue = 0;

    while (1)
    {
        if (x)
            break;
        // fadeToBlackBy(led, NUM_LEDS, THIS_FADE);
        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
            if (x)
                break;
            led[i].nscale8(255 - THIS_FADE);
        }
        int pos1 = beatsin16(THIS_BEAT, 0, NUM_LEDS - 1);
        int pos2 = beatsin16(THAT_BEAT, 0, NUM_LEDS - 1);
        led[(pos1 + pos2) / 2] += CHSV(myhue, 255, 255);
        EVERY_N_MILLISECONDS(10)
        {
            myhue++;
        }
        show();
    }
}

void Sinelon2()
{
    while (1)
    {
        if (x)
            break;
        // a colored dot sweeping back and forth, with fading trails
        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
            if (x)
                break;
            led[i].nscale8(255 - 20);
        }
        int pos = beatsin16(13, 0, NUM_LEDS - 1);
        led[pos] += CHSV(r, g, b);
        show();
    }
}