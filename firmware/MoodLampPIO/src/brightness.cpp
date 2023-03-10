#include "def.h"

int value[] = {5, 26, 51, 77, 102, 128, 153, 179, 204, 230, 255};

void increaseBrightness()
{
    if (brightnessIR < 10)
    {
        brightnessIR++;
        // Allows interrupt in patterns to make sure all pixels' brightness are changed
        FastLED.delay(50);
        FastLED.setBrightness(value[brightnessIR]);
        FastLED.show();
        Serial.print("Changed brightness to : ");
        Serial.println(value[brightnessIR]);
    }
}

void decreaseBrightness()
{
    if (brightnessIR > 0)
    {
        brightnessIR--;
        // Allows interrupt in patterns to make sure all pixels' brightness are changed
        FastLED.delay(50);
        FastLED.setBrightness(value[brightnessIR]);
        FastLED.show();
        Serial.print("Changed brightness to : ");
        Serial.println(value[brightnessIR]);
    }
}

void changeBrightness(String command)
{
    brightness = command.substring(1).toInt();
    preferences.putInt("brightness", brightness);
    brightnessIR = (brightness / 10) + 1;
    int b = map(brightness, 0, 100, 0, 255);
    // Allows interrupt in patterns to make sure all pixels' brightness are changed
    FastLED.delay(50);
    FastLED.setBrightness(b);
    FastLED.show();
    Serial.print("Changed brightness to : ");
    Serial.println(b);
    Serial.println(brightnessIR);
}