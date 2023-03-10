#include <Arduino.h>
#include <FastLED.h>
#include "def.h"

void Vu3(bool is_centered)
{
  uint8_t peakLeft = 0;
  uint8_t *peak; // Pointer variable declaration
  static uint8_t dotCountLeft;

  while (1)
  {
    if (x)
      break;
    uint16_t height = readMic();

    peak = &peakLeft;

    if (height > *peak)
      *peak = height; // Keep 'peak' dot at top

    if (is_centered)
    {
      // Color pixels based on old school green / red
      for (uint8_t i = 0; i < NUM_LEDS_HALF; i++)
      {
        if (x)
          break;
        if (i >= height)
        {
          // Pixels greater than peak, no light
          led[NUM_LEDS_HALF - i - 1] = CRGB::Black;
          led[NUM_LEDS_HALF + i] = CRGB::Black;
        }
        else
        {
          if (i > NUM_LEDS_HALF - (NUM_LEDS_HALF / 3))
          {
            led[NUM_LEDS_HALF - i - 1] = CRGB::Red;
            led[NUM_LEDS_HALF + i] = CRGB::Red;
          }
          else
          {
            led[NUM_LEDS_HALF - i - 1] = CRGB::Green;
            led[NUM_LEDS_HALF + i] = CRGB::Green;
          }
        }
      }

      // Draw peak dot
      if (*peak > 0 && *peak <= NUM_LEDS_HALF - 1)
      {
        if (*peak > NUM_LEDS_HALF - (NUM_LEDS_HALF / 3))
        {
          led[NUM_LEDS_HALF - *peak - 1] = CRGB::Red;
          led[NUM_LEDS_HALF + *peak] = CRGB::Red;
        }
        else
        {
          led[NUM_LEDS_HALF - *peak - 1] = CRGB::Green;
          led[NUM_LEDS_HALF + *peak] = CRGB::Green;
        }
      }
    }
    else
    {
      // Color pixels based on old school green/red vu
      for (uint8_t i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;
        if (i >= height)
          led[i] = CRGB::Black;
        else if (i > NUM_LEDS - (NUM_LEDS / 3))
          led[i] = CRGB::Red;
        else
          led[i] = CRGB::Green;
      }

      // Draw peak dot
      if (*peak > 0 && *peak <= (NUM_LEDS - 1))
      {
        if (*peak > (NUM_LEDS - (NUM_LEDS / 3)))
          led[*peak] = CRGB::Red;
        else
          led[*peak] = CRGB::Green;
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
