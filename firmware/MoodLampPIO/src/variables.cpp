#include <Preferences.h>

bool showPeak = true;

// Preferences instance
Preferences preferences;

String currentCommand = "--"; // prevents acting on the same command twice
int brightness = 100;         // brightness of the lamp
int brightnessIR = 10;        // brightness value for IR
int speed = 1;                // speed of patterns
int sensitivity = 3;          // music vu sensitivity
int mode = 1;                 // 0:colors, 1:segments, 2:patterns, 2:vu
int peak_fall_rate = 40;      // Rate of peak falling dot [20]