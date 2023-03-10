#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void RGBLoop()
{
  while (1)
  {
    if (x)
      break;
    for (int j = 0; j < 3; j++)
    {
      if (x)
        break;
      // Fade IN
      for (int k = 0; k < 256; k++)
      {
        if (x)
          break;
        switch (j)
        {
        case 0:
          setAll(k, 0, 0);
          break;
        case 1:
          setAll(0, k, 0);
          break;
        case 2:
          setAll(0, 0, k);
          break;
        }
        show();
      }

      // Fade OUT
      for (int k = 255; k >= 0; k--)
      {
        if (x)
          break;
        switch (j)
        {
        case 0:
          setAll(k, 0, 0);
          break;
        case 1:
          setAll(0, k, 0);
          break;
        case 2:
          setAll(0, 0, k);
          break;
        }
        show();
      }
    }
  }
}