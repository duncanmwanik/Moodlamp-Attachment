#include <FastLED.h>
#include "def.h"

// Make the change from new command
void makeChange(String command)
{
    currentCommand = command;
    Serial.println(".............");

    // we save the effect to be loaded on next start
    if (command.startsWith("p") | command.startsWith("v") | command.startsWith("0x") | command.startsWith("g"))
    {
        preferences.putString("command", command); // last command used
    }
    if (command.startsWith("0x"))
    {
        if (mode != 0)
            clear();
        x = true;
        code = 666;
        mode = 0; // switch to colors mode
        preferences.putString("color", command);

        hexToRGB(command);
        fill_solid(led, NUM_LEDS, strtol(command.c_str(), NULL, 16));
        show();
        delay(10);
        fill_solid(led, NUM_LEDS, strtol(command.c_str(), NULL, 16));
        show();

        Serial.print("Changed to color: ");
        Serial.println(command);
    }
}
if (command.startsWith("p"))
{
    if (code == 666)
    {
        Serial.println("Resuming effect task...");
        vTaskResume(EffectTask);
    }
    code = command.substring(1).toInt();
    patternIndex = code;
    x = true;
    mode = 2; // switch to patterns mode
}
if (command.startsWith("v"))
{
    if (code == 666)
    {
        Serial.println("Resuming effect task...");
        vTaskResume(EffectTask);
    }

    code = command.substring(1).toInt();
    vuIndex = code;
    x = true;
    mode = 3; // switch to music vu mode
}
//------- Change pattern color
if (command.startsWith("c"))
{
    Serial.println("Changed pattern color to:");
    Serial.println(command.substring(1));
    hexToRGB(command.substring(1));
}
//------- Change Brightness
if (command.startsWith("b"))
{
    changeBrightness(command);
}
//------- Change pattern speed
if (command.startsWith("s"))
{
    changeSpeed(command);
}
//------- Change vu sensitivity
if (command.startsWith("z"))
{
    changeSensitivity(command);
}
//------- Change Device BT Name
if (command.startsWith("n"))
{
    changeBtName(command.substring(1));
}
if (command.startsWith("dr"))
{
    sendData(command.substring(2).toInt());
}

preferences.putInt("mode", mode);
c->setValue("");
Serial.println(".............");
}

void checkChange()
{
    // Check for commands sent via BLE if a phone is connected
    if (deviceConnected)
    {
        std::string received_data = c->getValue();
        String newCommand = String(received_data.c_str());

        if ((!(newCommand.equals(currentCommand)) || newCommand.startsWith("dr")) && newCommand.length() > 1)
        {
            makeChange(newCommand);
        }
    }
}

void changeCommand(int index)
{
    String newCommand = "";

    if (mode == 0)
    {
        String c = "bc" + String(index);
        newCommand = preferences.getString(c.c_str(), buttonColors[index]);
    }
    if (mode == 1)
    {
        String s = "bs" + String(index);
        newCommand = preferences.getString(s.c_str(), buttonSegments[index]);
    }
    if (mode == 2)
    {
        String p = "bp" + String(index);
        newCommand = preferences.getString(p.c_str(), buttonPatterns[index]);
    }
    if (mode == 3)
    {
        String v = "bv" + String(index);
        newCommand = preferences.getString(v.c_str(), buttonVu[index]);
    }

    if (!newCommand.equals(currentCommand))
    {
        makeChange(newCommand);
    }
}