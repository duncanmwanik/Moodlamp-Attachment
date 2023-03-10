#include "def.h"

String modes[] = {"Color", "Color Segments", "Pattern", "Music"};

// Changing list used to color or pattern
void changeMode()
{
    if (mode < 3)
        mode++;
    else
        mode = 0;

    preferences.putInt("mode", mode);
    Serial.print("Changed mode to : ");
    Serial.println(modes[mode]);

    changeCommandIR(1);
}