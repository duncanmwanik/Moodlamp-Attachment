#include <Arduino.h>
#include <FastLED.h>
#include <pixeltypes.h>

#include "def.h"

void BouncingBalls(int BallCount)
{
  float Gravity = -9.81;
  int StartHeight = 1;

  float Height[BallCount];
  float ImpactVelocityStart = sqrt(-2 * Gravity * StartHeight);
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int Position[BallCount];
  long ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];

  for (int i = 0; i < BallCount; i++)
  {
    if (x)
      break;

    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0;
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i) / pow(BallCount, 2);
  }

  while (1)
  {
    if (x)
      break;
    for (int i = 0; i < BallCount; i++)
    {
      if (x)
        break;

      TimeSinceLastBounce[i] = millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow(TimeSinceLastBounce[i] / 1000, 2.0) + ImpactVelocity[i] * TimeSinceLastBounce[i] / 1000;

      if (Height[i] < 0)
      {
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();

        if (ImpactVelocity[i] < 0.01)
        {
          ImpactVelocity[i] = ImpactVelocityStart;
        }
      }
      Position[i] = round(Height[i] * (NUM_LEDS - 1) / StartHeight);
    }

    for (int i = 0; i < BallCount; i++)
    {
      if (x)
        break;

      setPixel(Position[i], r, g, b);
    }

    show();

    setAll(0, 0, 0);
  }
}