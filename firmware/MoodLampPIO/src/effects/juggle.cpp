#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

// FOR JUGGLE
uint8_t numdots = 4;  // Number of dots in use.
uint8_t faderate = 2; // How long should the trails be. Very low value = longer trails.
uint8_t hueinc = 16;  // Incremental change in hue between each dot.
uint8_t thishue = 0;  // Starting hue.
uint8_t curhue = 0;
uint8_t thisbright = 255; // How bright should the LED/display be.
uint8_t basebeat = 5;
uint8_t max_bright = 255;
uint8_t thissat = 255; // The saturation, where 255 = brilliant colours.

void doJuggle()
{                     // Several colored dots, weaving in and out of sync with each other
    curhue = thishue; // Reset the hue values.
    // fadeToBlackBy(led, NUM_LEDS, faderate);
    for (uint16_t i = 0; i < NUM_LEDS; i++)
    {
        if (x)
            break;
        led[i].nscale8(255 - faderate);
    }
    for (int i = 0; i < numdots; i++)
    {
        if (x)
            break;
        led[beatsin16(basebeat + i + numdots, 0, NUM_LEDS)] += CHSV(curhue, thissat, thisbright); // beat16 is a FastLED 3.1 function
        curhue += hueinc;
    }
}

void ChangeMe()
{                                                // A time (rather than loop) based demo sequencer. This gives us full control over the length of each sequence.
    uint8_t secondHand = (millis() / 1000) % 30; // IMPORTANT!!! Change '30' to a different value to change duration of the loop.
    static uint8_t lastSecond = 99;              // Static variable, means it's only defined once. This is our 'debounce' variable.
    if (lastSecond != secondHand)
    { // Debounce to make sure we're not repeating an assignment.
        lastSecond = secondHand;
        if (secondHand == 0)
        {
            numdots = 1;
            faderate = 2;
        } // You can change values here, one at a time , or altogether.
        if (secondHand == 10)
        {
            numdots = 4;
            thishue = 128;
            faderate = 8;
        }
        if (secondHand == 20)
        {
            hueinc = 48;
            thishue = random8();
        } // Only gets called once, and not continuously for the next several seconds. Therefore, no rainbows.
    }
}

void Juggle()
{
    while (1)
    {
        if (x)
            break;
        ChangeMe();
        doJuggle();
        show();
    }
}

void Juggle2()
{
    while (1)
    {
        if (x)
            break;
        // eight colored dots, weaving in and out of sync with each other
        // fadeToBlackBy(led, NUM_LEDS, 20);
        for (uint16_t i = 0; i < NUM_LEDS; i++)
        {
            if (x)
                break;
            led[i].nscale8(255 - 20);
        }

        uint8_t dothue = 0;
        for (int i = 0; i < 8; i++)
        {
            if (x)
                break;
            led[beatsin16(i + 7, 0, NUM_LEDS - 1)] |= CHSV(dothue, 200, 255);
            dothue += 32;
        }
        show();
    }
}