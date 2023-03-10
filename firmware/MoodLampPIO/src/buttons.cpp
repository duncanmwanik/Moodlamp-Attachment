#include "def.h"

String buttonColors[9] = {"0xff0000", "0x00ff00", "0x0000ff", "0xffffff", "0xffff00", "0x00ffff", "0xffa500",
                          "0xff00ff", "0x4b0082"};
String buttonSegments[9] = {
    "g2|n",
    "g2|n",
    "g3|n",
    "g4|n",
    "g5|n",
    "g6|n",
    "g7|n",
    "g8|n",
    "g9|n"};

String presetSegments[9] = {
    "0xff0000|0x00ff00|",
    "0xff0000|0x00ff00|0x0000ff|",
    "0xff0000|0x00ff00|0x0000ff|0xffffff|",
    "0xff0000|0x00ff00|0x0000ff|0xffffff|0xffff00|",
    "0xff0000|0x00ff00|0x0000ff|0xffffff|0xffff00|0x00ffff|",
    "0xff0000|0x00ff00|0x0000ff|0xffffff|0xffff00|0x00ffff|0xffa500|",
    "0xff0000|0x00ff00|0x0000ff|0xffffff|0xffff00|0x00ffff|0xffa500|0xff00ff|",
    "0xff0000|0x00ff00|0x0000ff|0xffffff|0xffff00|0x00ffff|0xffa500|0xff00ff|0x4b0082|"};

String buttonPatterns[9] = {"p0", "p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8"};
String buttonVu[9] = {"v200", "v201", "v202", "v203", "v204", "v205", "v206", "v207", "v208"};

// Changing Key assignments
void changeButtonAssignment(String command)
{
    Serial.println("Saving IR remote key functions ...");
    int i = command.substring(2, 3).toInt();
    if (command.startsWith("bc")) // changing color assignment
    {
        String bc = "bc" + String(i);
        preferences.putString(bc.c_str(), command.substring(3));
    }
    if (command.startsWith("bs")) // changing segment assignment
    {
        String bs = "bs" + String(i);
        preferences.putString(bs.c_str(), command.substring(3));
    }
    if (command.startsWith("bp")) // changing pattern assignment
    {
        String bp = "bp" + String(i);
        preferences.putString(bp.c_str(), command.substring(3));
    }
    if (command.startsWith("bv")) // changing vu assignment
    {
        String bv = "bv" + String(i);
        preferences.putString(bv.c_str(), command.substring(3));
    }
    Serial.println("... done!");
}