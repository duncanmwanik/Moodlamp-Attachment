
#include "def.h"

void increaseSensitivity()
{
    if (sensitivity < 5)
    {
        sensitivity++;
        preferences.putInt("sensitivity", sensitivity);
        Serial.print("Changed sensitivity to : ");
        Serial.println(sensitivity);
    }
}

void decreaseSensitivity()
{

    if (sensitivity > 1)
    {
        sensitivity--;
        preferences.putInt("sensitivity", sensitivity);
        Serial.print("Changed sensitivity to : ");
        Serial.println(sensitivity);
    }
}

void changeSensitivity(String command)
{

    sensitivity = command.substring(1).toInt();
    preferences.putInt("sensitivity", sensitivity);
    Serial.print("Changed sensitivity to : ");
    Serial.println(sensitivity);
}