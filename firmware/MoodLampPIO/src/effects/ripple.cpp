#include <Arduino.h>
#include <FastLED.h>

#include "def.h"

int wrapr(int rippleStep)
{
  if (rippleStep < 0)
    return NUM_LEDS + rippleStep;
  if (rippleStep > NUM_LEDS - 1)
    return rippleStep - NUM_LEDS;
  return rippleStep;
}

void Ripple(boolean show_background)
{

  const float RIPPLE_FADE_RATE = 0.80;
  const uint8_t MAX_STEPS = 16;
  static uint8_t rippleColor = 0;
  static uint8_t rippleCenter = 0;
  static int rippleStep = -1;
  uint8_t myhue = 0;

  while (1)
  {
    if (x)
      break;
    // -- fill background --
    EVERY_N_MILLISECONDS(10)
    {
      myhue++;
    }
    if (show_background)
    {
      // fill_solid(led, NUM_LEDS, CHSV(myhue, 255, 175));
      for (int i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;
        led[i] = CHSV(myhue, 255, 175);
      }
    }
    else
    {
      // fill_solid(led, NUM_LEDS, CRGB::Black);
      for (int i = 0; i < NUM_LEDS; i++)
      {
        if (x)
          break;
        led[i] = CRGB::Black;
      }
    }

    EVERY_N_MILLISECONDS(50)
    {
      // -- do ripple --
      if (rippleStep == -1)
      {
        rippleCenter = random(NUM_LEDS);
        rippleColor = myhue + 128;
        rippleStep = 0;
      }

      if (rippleStep == 0)
      {
        led[rippleCenter] = CHSV(rippleColor, 255, 255);
        rippleStep++;
      }
      else
      {
        if (rippleStep < MAX_STEPS)
        {
          led[wrapr(rippleCenter + rippleStep)] = CHSV(rippleColor, 255, pow(RIPPLE_FADE_RATE, rippleStep) * 255);
          led[wrapr(rippleCenter - rippleStep)] = CHSV(rippleColor, 255, pow(RIPPLE_FADE_RATE, rippleStep) * 255);
          if (rippleStep > 3)
          {
            led[wrapr(rippleCenter + rippleStep - 3)] = CHSV(rippleColor, 255, pow(RIPPLE_FADE_RATE, rippleStep - 2) * 255);
            led[wrapr(rippleCenter - rippleStep + 3)] = CHSV(rippleColor, 255, pow(RIPPLE_FADE_RATE, rippleStep - 2) * 255);
          }
          rippleStep++;
        }
        else
        {
          rippleStep = -1;
        }
      }
    }
    show();
  }
}
