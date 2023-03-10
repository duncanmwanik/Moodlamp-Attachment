#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

// function used by "fadeTowardColor"
void nblendU8TowardU8(uint8_t &cur, const uint8_t target, uint8_t amount)
{
  if (cur == target)
    return;

  if (cur < target)
  {
    uint8_t delta = target - cur;
    delta = scale8_video(delta, amount);
    cur += delta;
  }
  else
  {
    uint8_t delta = cur - target;
    delta = scale8_video(delta, amount);
    cur -= delta;
  }
}

// Functions from Kriegsman example
CRGB fadeTowardColor_2(CRGB &cur, const CRGB &target, uint8_t amount)
{
  nblendU8TowardU8(cur.red, target.red, amount);
  nblendU8TowardU8(cur.green, target.green, amount);
  nblendU8TowardU8(cur.blue, target.blue, amount);
  return cur;
}

void MeteorRain()
{
  int speeds[] = {100, 80, 30, 15, 5};
  byte meteorSize = 10;
  byte meteorTrailDecay = 64;
  boolean meteorRandomDecay = true;

  while (1)
  {
    if (x)
      break;
    // set background color
    fill_solid(led, NUM_LEDS, 0x000000);

    for (int i = 0; i < NUM_LEDS + NUM_LEDS; i++)
    {
      if (x)
        break;
      // fade color to background color for all LEDs
      for (int j = 0; j < NUM_LEDS; j++)
      {
        if (x)
          break;
        if ((!meteorRandomDecay) || (random(10) > 5))
        {
          led[j] = fadeTowardColor_2(led[j], 0x000000, meteorTrailDecay);
        }
      }

      // draw meteor
      for (int j = 0; j < meteorSize; j++)
      {
        if (x)
          break;
        if ((i - j < NUM_LEDS) && (i - j >= 0))
        {
          led[i - j] = CRGB(r, g, b);
        }
      }

      show();

      vTaskDelay(speeds[speed]);
    }
  }
}