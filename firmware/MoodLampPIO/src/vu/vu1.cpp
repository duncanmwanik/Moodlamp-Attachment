#include <Arduino.h>
#include <FastLED.h>
#include "def.h"

void Vu1(bool is_centered)
{
  const int SPEED = 10;
  static int hueOffset = 30;
  int peakLeft = 0;
  int *peak; // Pointer variable declaration
  static int dotCountLeft;

  while (1)
  {
    if (x)
      break;

    int height = round((readMic() * 72) / 500);

    // if (height > 72)
    // {
    //   Serial.println(height);
    // }

    peak = &peakLeft;

    if (height > *peak)
      *peak = height; // Keep 'peak' dot at top

    EVERY_N_MILLISECONDS(SPEED) { hueOffset++; }

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
          led[NUM_LEDS_HALF - i - 1] = CHSV(hueOffset + (10 * i), 255, 255);
          led[NUM_LEDS_HALF + i] = CHSV(hueOffset + (10 * i), 255, 255);
        }
      }

      // Draw peak dot
      if (*peak > 0 && *peak <= NUM_LEDS_HALF - 1)
      {
        led[NUM_LEDS_HALF - *peak - 1] = CHSV(hueOffset, 255, 255);
        led[NUM_LEDS_HALF + *peak] = CHSV(hueOffset, 255, 255);
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
          led[i] = CHSV(hueOffset + (10 * i), 255, 255);
        }
      }
      // Draw peak dot
      if (*peak > 0 && *peak <= NUM_LEDS - 1)
        led[*peak] = CHSV(hueOffset, 255, 255);
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
