
#include "def.h"

void increaseSpeed()
{
    if (speed < 4)
    {
        speed++;
        preferences.putInt("speed", speed);
        Serial.print("Changed speed to : ");
        Serial.println(speed);
    }
}

void decreaseSpeed()
{
    if (speed > 0)
    {
        speed--;
        preferences.putInt("speed", speed);
        Serial.print("Changed speed to : ");
        Serial.println(speed);
    }
}

void changeSpeed(String command)
{
    speed = command.substring(1).toInt();
    preferences.putInt("speed", speed);

    Serial.print("Changed speed to : ");
    Serial.println(speed);
}
