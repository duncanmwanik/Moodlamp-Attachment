#include <Arduino.h>
#include <FastLED.h>
#include "def.h"

int volLeft[SAMPLES]; // Collection of prior volume samples
int rippleStep = -1;
int peakspersec = 0;
int peakcount = 0;
unsigned int sampleavg;
uint8_t rippleHue = 0;
uint8_t bgcol = 0;

void soundmems()
{ // Rolling average counter - means we don't have to go through an array each time.
    static int samplecount;
    static unsigned long samplesum;
    static unsigned long oldtime;
    unsigned long newtime = millis();
    unsigned int sample = readMic() * 10;

    samplesum = samplesum + sample - volLeft[samplecount]; // Add the new sample and remove the oldest sample in the array
    sampleavg = samplesum / SAMPLES;                       // Get an average
    volLeft[samplecount] = sample;                         // Update oldest sample in the array with new sample
    samplecount = (samplecount + 1) % SAMPLES;             // Update the counter for the array

    if ((sample > (sampleavg + 50)) && (newtime > (oldtime + 1)))
    { // Check for a peak, which is 50 > the average, but wait at least 100ms for another.
        rippleStep = -1;
        peakcount++;
        oldtime = newtime;
    }
}

void ripple_(bool show_background)
{
    const uint8_t MAX_STEPS = 16;
    static int center = 0;

    if (show_background)
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            if (x)
                break;
            led[i] = CHSV(bgcol, 255, sampleavg * 2); // Set the background colour.
        }
    }
    else
    {
        fadeToBlackBy(led, NUM_LEDS, 64);
    }

    switch (rippleStep)
    {
    case -1: // Initialize ripple variables.
        center = random(NUM_LEDS);
        rippleHue = (peakspersec * 10) % 255; // More peaks/s = higher the hue colour.
        rippleStep = 0;
        bgcol = bgcol + 8;
        break;

    case 0:
        led[center] = CHSV(rippleHue, 255, 255); // Display the first pixel of the ripple.
        rippleStep++;
        break;

    case MAX_STEPS: // At the end of the ripples.
        break;

    default:                                                                                            // Middle of the ripples.
        led[(center + rippleStep + NUM_LEDS) % NUM_LEDS] += CHSV(rippleHue, 255, 255 / rippleStep * 2); // Simple wrap from Marc Miller.
        led[(center - rippleStep + NUM_LEDS) % NUM_LEDS] += CHSV(rippleHue, 255, 255 / rippleStep * 2);
        rippleStep++; // Next step.
        break;
    }
}

void Vu4(boolean show_background)
{
    while (1)
    {
        if (x)
            break;
        EVERY_N_MILLISECONDS(100)
        {
            peakspersec = peakcount; // Count the peaks per second. This value will become the foreground rippleHue.
            peakcount = 0;           // Reset the counter every second.
        }

        soundmems();

        EVERY_N_MILLISECONDS(20)
        {
            ripple_(show_background);
        }

        show();
    }
}