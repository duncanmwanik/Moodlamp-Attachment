#ifndef EFFECTS_H
#define EFFECTS_H

#include <Arduino.h>

// ------------------ Patterns
void Bit(int type);
void BouncingBalls(int BallCount);
void BouncingColoredBalls(int BallCount);
void BPM();
void ColorWipe(int type);
void Confetti();
void CylonBounce(int EyeSize);
void Fire();
void HalloweenEyes(int type);
void Juggle();
void Juggle2();
void MeteorRain();
void MeteorShower();
void MiniBoss();
void NewKITT();
void Pacifica();
void Palette();
void PartyOfColors();
void Pride();
void RainbowCycle();
void RainbowRun();
void RGBLoop();
void Ripple(boolean show_background);
void RunningLights();
void Sinelon();
void SinelonRandom();
void Sinelon2();
void SnowSparkle();
void Sparkle(int c);
void Strobe();
void TheaterChase();
void TheaterChaseRainbow();
void Twinkle(int mode);
void Twinkle2();
void Zoom();
// ------------------ VU
void Vu0(bool is_centered);
void Vu1(bool is_centered);
void Vu2(bool is_centered);
void Vu3(bool is_centered);
void Vu4(boolean show_background);
void Vu5();

#endif