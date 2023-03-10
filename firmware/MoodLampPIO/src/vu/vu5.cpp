#include <Arduino.h>
#include <FastLED.h>

#include "def.h"

static uint8_t scroll_color = 0;

void Vu5()
{
  const uint8_t DRAW_MAX = 30;
  const uint8_t SEGMENTS = 3;

  static int origin = 0;
  static int last_intensity = 0;
  static int intensity_max = 0;
  static int origin_at_flip = 0;
  static CHSV draw[DRAW_MAX];
  static bool growing = false;
  static bool fall_from_left = true;

  while (1)
  {
    if (x)
      break;
    int intensity = readMic();

    // detect peak change and save origin at curve vertex
    if (growing && intensity < last_intensity)
    {
      growing = false;
      intensity_max = last_intensity;
      fall_from_left = !fall_from_left;
      origin_at_flip = origin;
    }
    else if (intensity > last_intensity)
    {
      growing = true;
      origin_at_flip = origin;
    }
    last_intensity = intensity;

    // adjust origin if falling
    if (!growing)
    {
      if (fall_from_left)
      {
        origin = origin_at_flip + ((intensity_max - intensity) / 2);
      }
      else
      {
        origin = origin_at_flip - ((intensity_max - intensity) / 2);
      }
      // correct for origin out of bounds
      if (origin < 0)
      {
        origin = DRAW_MAX - abs(origin);
      }
      else if (origin > DRAW_MAX - 1)
      {
        origin = origin - DRAW_MAX - 1;
      }
    }

    // Assign draw values
    // draw amplitue as 1/2 intensity both directions from origin
    int min_lit = origin - (intensity / 2);
    int max_lit = origin + (intensity / 2);
    if (min_lit < 0)
    {
      min_lit = min_lit + DRAW_MAX;
    }
    if (max_lit >= DRAW_MAX)
    {
      max_lit = max_lit - DRAW_MAX;
    }
    for (int i = 0; i < DRAW_MAX; i++)
    {
      if (x)
        break;
      // if i is within origin +/- 1/2 intensity
      if (
          (min_lit < max_lit && min_lit < i && i < max_lit)      // range is within bounds and i is within range
          || (min_lit > max_lit && (i > min_lit || i < max_lit)) // range wraps out of bounds and i is within that wrap
      )
      {
        draw[i] = CHSV(scroll_color, 255, 255);
      }
      else
      {
        draw[i] = CHSV(scroll_color, 0, 0);
      }
    }

    // Write Segmented
    int seg_len = NUM_LEDS / SEGMENTS;

    for (int s = 0; s < SEGMENTS; s++)
    {
      if (x)
        break;
      for (int i = 0; i < seg_len; i++)
      {
        if (x)
          break;
        led[i + (s * seg_len)] = draw[map(i, 0, seg_len, 0, DRAW_MAX)];
      }
    }

    show();

    EVERY_N_MILLISECONDS(20)
    {
      scroll_color++;
      scroll_color = scroll_color % 255;
    }
  }
}
