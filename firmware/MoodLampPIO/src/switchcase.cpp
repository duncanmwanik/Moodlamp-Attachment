#include <Arduino.h>
#include "effects.h"

#include "def.h"

// --------------------------------------------------------------------------------------------------------------
// Switch to selected pattern----------- --------- ------------ ------------- ---------- ---------- -------------

void switchEffect(int e)
{
    Serial.print("Changing to Effect: ");
    Serial.println(e);

    switch (e)
    {
    // ---------------------------- Patterns
    case 0:
        Bit(0);
        break;
    case 1:
        Bit(1);
        break;
    case 2:
        BouncingBalls(3);
        break;
    case 3:
        BouncingBalls(6);
        break;
    case 4:
        BouncingColoredBalls(3);
        break;
    case 5:
        BouncingColoredBalls(6);
        break;
    case 6:
        BPM();
        break;
    case 7:
        Confetti();
        break;
    case 8:
        ColorWipe(0);
        break;
    case 9:
        ColorWipe(1);
        break;
    case 10:
        ColorWipe(2);
        break;
    case 11:
        CylonBounce(8);
        break;
    case 12:
        Fire();
        break;
    case 13:
        HalloweenEyes(0);
        break;
    case 14:
        HalloweenEyes(1);
        break;
    case 15:
        Juggle();
        break;
    case 16:
        Juggle2();
        break;
    case 17:
        MeteorRain();
        break;
    case 18:
        MeteorShower();
        break;
    case 19:
        MiniBoss();
        break;
    case 20:
        NewKITT();
        break;
    case 21:
        Palette();
        break;
    case 22:
        PartyOfColors();
        break;
    case 23: // v
        Zoom();
        break;
    case 24:
        Pacifica();
        break;
    case 25:
        Pride();
    case 26:
        RainbowCycle();
        break;
    case 27:
        RainbowRun();
        break;
    case 28:
        RGBLoop();
        break;
    case 29:
        Ripple(false);
        break;
    case 30:
        Ripple(true);
        break;
    case 31:
        RunningLights();
        break;
    case 32:
        Sinelon();
        break;
    case 33:
        SinelonRandom();
        break;
    case 34:
        Sinelon2();
        break;
    case 35:
        SnowSparkle();
        break;
    case 36: // v
        Zoom();
        break;
    case 37:
        Sparkle(0);
        break;
    case 38:
        Sparkle(1);
        break;
    case 39:
        Sparkle(2);
        break;
    case 40:
        Strobe();
        break;
    case 41:
        TheaterChase();
        break;
    case 42:
        TheaterChaseRainbow();
        break;
    case 43:
        Twinkle(0);
        break;
    case 44:
        Twinkle(1);
        break;
    case 45:
        Twinkle2();
        break;
    case 46:
        Zoom();
        break;
    // ---------------------------- VU
    case 200:
        Vu1(true);
        break;
    case 201:
        Vu1(false);
        break;
    default:
        Bit(0);
        break;
    }
}