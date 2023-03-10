#include <Arduino.h>
#include <FastLED.h>
#include <LinkedList.h>
#include <pixeltypes.h>
#include "def.h"

// Fastled instance
CRGB led[NUM_LEDS];

// default effect color RGB values
byte r, g, b;

long RGBColors[] = {0xff0000, 0x00ff00, 0x0000ff};

long MainColors[] = {0xff0000, 0x00ff00, 0x0000ff, 0xffffff, 0xff0056, 0xffa500, 0x4b0082, 0xffff00, 0x00ffff, 0xff0011, 0xff00ff, 0xff1d00};

long PartyColors[] = {0xff0000, 0x00ff00, 0xffff00, 0xff0056, 0x00ffff, 0xffa500, 0xff0011,
                      0x4b0082, 0xff1d00, 0x0000ff, 0xff00ff};

long BallColors[] = {0xff0000, 0x00ff00, 0x0000ff, 0xffffff, 0xff0056, 0xffa500, 0x4b0082, 0xffff00, 0x00ffff};

void setupFastLed()
{
  // Fastled initialization and settings
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(led, NUM_LEDS);
  int b = map(brightness, 0, 100, 0, 255);
  FastLED.setBrightness(b); // Set last brightness value
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 4000);
}

// Set one Neopixel leds to a specific color
void setPixel(int Pixel, byte red, byte green, byte blue)
{
  led[Pixel].r = red;
  led[Pixel].g = green;
  led[Pixel].b = blue;
}

// Set all Neopixels leds to a specific color
void setAll(byte red, byte green, byte blue)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (x)
      break;
    setPixel(i, red, green, blue);
  }
  FastLED.show();
}

// Set all Neopixels leds to a specific color using HEX long
void setAllHex(long hex)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (x)
      break;
    led[i] = hex;
  }
  FastLED.show();
}

void show()
{
  FastLED.show();
}

void clear()
{
  FastLED.clear(true);
}

// Change hex to RGB values to get base effect color
void hexToRGB(String comm)
{
  long pcolor = strtol(comm.c_str(), NULL, 16);
  r = pcolor >> 16;
  g = (pcolor & 0x00ff00) >> 8;
  b = (pcolor & 0x0000ff);
}

void makeSegment(int number, String segments)
{
  LinkedList<String> segColorsList;
  String segColors = "";
  int divisions = round(NUM_LEDS / number);
  int begin = 0;
  int end = divisions;

  if (segments == "n")
  {
    String key = "seg" + String(number);
    segColors = preferences.getString(key.c_str(), "n");
    if (segColors == "n")
    {
      segColors = presetSegments[number - 2];
    }
  }
  else
  {
    segColors = segments;
  }

  // ----- get list of segment colors
  int r = 0, t = 0;
  for (int i = 0; i < segColors.length(); i++)
  {
    if (segColors.charAt(i) == '|')
    {
      segColorsList.add(segColors.substring(r, i));
      r = (i + 1);
      t++;
    }
  }

  for (int s = 0; s < number; s++)
  {
    for (int i = begin; i < end; i++)
    {
      led[i] = strtol(segColorsList[s].c_str(), NULL, 16);
    }
    begin = begin + divisions;
    end = end + divisions;
    if (end == 70)
      end = 72;
  }
  FastLED.show();

  String key = "seg" + String(number);
  preferences.putString(key.c_str(), segColors);
}