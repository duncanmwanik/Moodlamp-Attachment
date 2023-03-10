#include <Arduino.h>
#include <FastLED.h>
#include "def.h"

uint8_t rainbowHue2(uint8_t pixel, uint8_t num_pixels)
{
  uint8_t hue = 96 - pixel * (145 / num_pixels);
  return hue;
}

void Vu2(bool is_centered)
{
  uint8_t i = 0;
  uint8_t peakLeft = 0;
  uint8_t *peak; // Pointer variable declaration
  static uint8_t dotCountLeft;

  while (1)
  {
    if (x)
      break;
    uint16_t height = readMic();

    peak = &peakLeft;

    // Draw vu meter part
    fill_solid(led, NUM_LEDS, CRGB::Black);
    if (is_centered)
    {
      // Fill with colour gradient
      fill_gradient(led, NUM_LEDS_HALF, CHSV(96, 255, 255), NUM_LEDS - 1, CHSV(224, 255, 255), SHORTEST_HUES);
      fill_gradient(led, NUM_LEDS_HALF - 1, CHSV(96, 255, 255), 0, CHSV(224, 255, 255), LONGEST_HUES);

      // Black out ends
      for (i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;
        uint8_t numBlack = (NUM_LEDS - constrain(height, 0, NUM_LEDS - 1)) / 2;
        if (i <= numBlack - 1 || i >= NUM_LEDS - numBlack)
          led[i] = CRGB::Black;
      }

      // Draw peak dot
      if (height / 2 > *peak)
        *peak = height / 2; // Keep 'peak' dot at top

      if (*peak > 0 && *peak <= NUM_LEDS_HALF - 1)
      {
        led[NUM_LEDS_HALF + *peak] = CHSV(rainbowHue2(*peak, NUM_LEDS_HALF), 255, 255);
        led[NUM_LEDS_HALF - 1 - *peak] = CHSV(rainbowHue2(*peak, NUM_LEDS_HALF), 255, 255);
      }
    }

    else
    {
      // Fill with color gradient
      fill_gradient(led, 0, CHSV(96, 255, 255), NUM_LEDS - 1, CHSV(224, 255, 255), SHORTEST_HUES);

      // Black out end
      for (i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;
        if (i >= height)
          led[i] = CRGB::Black;
      }

      // Draw peak dot
      if (height > *peak)
        *peak = height; // Keep 'peak' dot at top

      if (*peak > 0 && *peak <= NUM_LEDS - 1)
        led[*peak] = CHSV(rainbowHue2(*peak, NUM_LEDS), 255, 255); // Set peak colour correctly
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
