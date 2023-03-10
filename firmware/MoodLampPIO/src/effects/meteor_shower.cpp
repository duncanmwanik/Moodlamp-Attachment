#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void MeteorShower()
{
  int speeds[] = {80, 50, 30, 10, 5};
  uint8_t hue = 32;
  byte idex = 255;
  byte meteorLength = 29;

  while (1)
  {
    if (x)
      break;
    // slide all the pixels down one in the array
    memmove8(&led[1], &led[0], (NUM_LEDS - 1) * 3);

    // increment the meteor display frame
    idex++;
    // make sure we don't drift into space
    if (idex > meteorLength)
    {
      idex = 0;
      // cycle through hues in each successive meteor tail
      hue += 32;
    }

    // this switch controls the actual meteor animation, i.e., what gets placed in the
    // first position and then subsequently gets moved down the strip by the memmove above
    switch (idex)
    {
    case 0:
      led[0] = CRGB(200, 200, 200);
      break;
    case 1:
      led[0] = CHSV((hue - 20), 255, 210);
      break;
    case 2:
      led[0] = CHSV((hue - 22), 255, 180);
      break;
    case 3:
      led[0] = CHSV((hue - 23), 255, 150);
      break;
    case 4:
      led[0] = CHSV((hue - 24), 255, 110);
      break;
    case 5:
      led[0] = CHSV((hue - 25), 255, 90);
      break;
    case 6:
      led[0] = CHSV((hue - 26), 160, 60);
      break;
    case 7:
      led[0] = CHSV((hue - 27), 140, 40);
      break;
    case 8:
      led[0] = CHSV((hue - 28), 120, 20);
      break;
    case 9:
      led[0] = CHSV((hue - 29), 100, 20);
      break;
    default:
      led[0] = CRGB::Black;
    }

    // show the blinky
    show();

    // control the animation speed/frame rate
    vTaskDelay(speeds[speed]);
  }
}