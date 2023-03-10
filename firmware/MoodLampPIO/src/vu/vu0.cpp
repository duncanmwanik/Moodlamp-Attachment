#include <Arduino.h>
#include <FastLED.h>
#include "def.h"

void Vu0(bool is_centered)
{
    int peakLeft = 0;
    int *peak; // Pointer variable declaration
    static int dotCountLeft;

    while (1)
    {
        if (x)
            break;
        int height = readMic();

        // if (height > 72)
        // {
        //   Serial.println(height);
        // }

        peak = &peakLeft;

        if (height > *peak)
            *peak = height; // Keep 'peak' dot at top

        if (is_centered)
        {
            // Color pixels based on rainbow gradient
            for (int i = 0; i < NUM_LEDS_HALF; i++)
            {
                if (x)
                    break;

                if (i >= height)
                {
                    led[NUM_LEDS_HALF - i - 1] = CRGB::Black;
                    led[NUM_LEDS_HALF + i] = CRGB::Black;
                }
                else
                {
                    led[NUM_LEDS_HALF - i - 1].r = r;
                    led[NUM_LEDS_HALF - i - 1].g = g;
                    led[NUM_LEDS_HALF - i - 1].b = b;
                    led[NUM_LEDS_HALF + i].r = r;
                    led[NUM_LEDS_HALF + i].g = g;
                    led[NUM_LEDS_HALF + i].b = b;
                }
            }

            // Draw peak dot
            if (*peak > 0 && *peak <= NUM_LEDS_HALF - 1)
            {
                led[NUM_LEDS_HALF - *peak - 1].r = r;
                led[NUM_LEDS_HALF - *peak - 1].g = g;
                led[NUM_LEDS_HALF - *peak - 1].b = b;
                led[NUM_LEDS_HALF + *peak].r = r;
                led[NUM_LEDS_HALF + *peak].g = g;
                led[NUM_LEDS_HALF + *peak].b = b;
            }
        }

        else
        {
            // Color pixels based on rainbow gradient
            for (int i = 0; i < NUM_LEDS; i++)
            {
                if (x)
                    break;

                if (i >= height)
                {
                    led[i] = CRGB::Black;
                }
                else
                {
                    led[i].r = r;
                    led[i].g = g;
                    led[i].b = b;
                }
            }
            // Draw peak dot
            if (*peak > 0 && *peak <= NUM_LEDS - 1)
            {
                led[*peak].r = r;
                led[*peak].g = g;
                led[*peak].b = b;
            }
        }

        // dropping peak dot
        if (showPeak)
        {
            if (++dotCountLeft >= peak_fall_rate)
            { // fall rate
                if (peakLeft > 0)
                    peakLeft--;
                dotCountLeft = 0;
            }
        }

        show();
    }
}
