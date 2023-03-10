#ifndef DEF_H
#define DEF_H

#include <Arduino.h>
#include <Preferences.h>
#include <FastLED.h>
#include <BLEDevice.h>

// Lamp Information
#define LAMP_ID 1999
#define LAMP_VERSION 0
#define LAMP_SOFTWARE_VERSION 1.0

#define NUM_LEDS 72
#define DATA_PIN 15

#define GRAVITY -9.81 // Downward (negative) acceleration of gravity in m/s^2
#define h0 1          // Starting height, in meters, of the ball (strip length)

// MIC pins
#define I2S_SCK 33
#define I2S_WS 26
#define I2S_SD 25


// Music VU stuff
#define TOP (NUM_LEDS + 2) // Allow dot to go slightly off scale [(NUM_LEDS + 2)]
#define NUM_LEDS_HALF (NUM_LEDS / 2)
#define SAMPLES 60

// Mode numbers
#define MODE_COLORS 0
#define MODE_SEGMENTS 1
#define MODE_PATTERNS 2
#define MODE_MUSIC 3

// Number of each effect's options
#define NO_COLORS 11
#define NO_SEGMENTS 7
#define NO_PATTERNS 46
#define NO_MUSIC 208

// ESPNOW stuff

// ---------- Variables
// extern CRGB led[];
extern CRGB led[NUM_LEDS];
extern Preferences preferences;
extern String currentCommand;
extern int brightness;
extern int brightnessIR;
extern int speed;
extern int sensitivity;
extern int mode;
extern bool showPeak;
extern int peak_fall_rate;

// ---------- BLE
void setupBLE();
extern bool deviceConnected;
extern bool oldDeviceConnected;
extern BLECharacteristic *c;
void changeBtName(String name);
void sendData(int type);

// ---------- Initialization
void loadVariables();

// ---------- FastLed Setup
void setupFastLed();

// ---------- IR
void setupIR();
void receiveIRCode();
void changeCommandIR(int direction);
extern long IRCodes[17];
extern int colorIndex;
extern int segmentIndex;
extern int patternIndex;
extern int vuIndex;
// ---------- Switchcases
void switchEffect(int code);
void switchIR(int value);

// ---------- Tasks
extern TaskHandle_t EffectTask;
void effectTask(void *);
void createEffectTask();
extern volatile int code;
extern volatile bool x;

// ---------- Command change methods
void makeChange(String command);
void checkChange();
void changeCommand(int index);

// ---------- Brightness
void changeBrightness(String command);
void increaseBrightness();
void decreaseBrightness();
extern int value[];

// ---------- Speed
void changeSpeed(String command);
void decreaseSpeed();
void increaseSpeed();

// ---------- Sensitivity
void changeSensitivity(String command);
void decreaseSensitivity();
void increaseSensitivity();

// ---------- Mode
void changeMode();

// ---------- Remote buttons
void changeButtonAssignment(String command);
extern String buttonColors[9];
extern String buttonPatterns[9];
extern String buttonSegments[9];
extern String buttonVu[9];
extern String presetSegments[9];

// ---------- Color/Effects/methods
extern byte r, g, b;
extern long RGBColors[];
extern long MainColors[];
extern long PartyColors[];
extern long BallColors[];
extern String ColorCodes[];

void setPixel(int Pixel, byte red, byte green, byte blue);
void setAll(byte red, byte green, byte blue);
void setAllHex(long hex);
void show();
void clear();

void hexToRGB(String comm);
void makeSegment(int segments, String segColors);

// ---------- Mic / methods
void setupMic();
uint16_t readMic();

#endif
