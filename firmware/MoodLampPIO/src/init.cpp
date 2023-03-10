
#include "def.h"

void loadVariables()
{
    Serial.println("------------------------------------------------------------");
    Serial.println("Loading important variables ...");

    preferences.begin("esp", false); // opens our namespace to read & write data

    brightness = preferences.getInt("brightness", 100);   // last speed set
    speed = preferences.getInt("speed", 1);               // last speed set
    sensitivity = preferences.getInt("sensitivity", 3);   // last sensitivity set
    hexToRGB(preferences.getString("color", "0xff0000")); // use the last set color as default patttern color
}