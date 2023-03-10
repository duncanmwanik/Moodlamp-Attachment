#include <Arduino.h>
#include "IRrecv.h"
#include "def.h"

// store selected color, pattern or vu when direction keys are pressed
int colorIndex = 0;
int segmentIndex = 0;
int patternIndex = 0;
int vuIndex = 200;

String ColorCodes[] = {"0xff0000", "0x00ff00", "0x0000ff", "0xffffff", "0xff0056", "0xffa500", "0x4b0082", "0xffff00", "0x00ffff",
                       "0xff0011", "0xff00ff", "0xff1d00"};
String SegmentCodes[] = {
    "g2|n",
    "g3|n",
    "g4|n",
    "g5|n",
    "g6|n",
    "g7|n",
    "g8|n",
    "g9|n"};

// Keyes remote IR codes: see at the bottom >>
long IRCodes[17] = {0XFFA25D, 0XFF629D, 0XFFE21D, 0XFF22DD, 0XFF02FD, 0XFFC23D, 0XFFE01F, 0XFFA857, 0XFF906F, 0XFF9867,
                    0XFFB04F, 0XFF6897, 0XFF18E7, 0XFF4AB5, 0XFF10EF, 0XFF5AA5, 0XFF38C7};

// IR instance. Don't connect to SPI pins of the board
IRrecv irrecv(4);

void setupIR()
{
    Serial.println("------------------------------------------------------------");
    Serial.println("Setting up IR remote ...");
    // Start the IR receiver
    irrecv.enableIRIn();
}

// Function to receive IR codes, check if they are valid and make required changes
void receiveIRCode()
{
    decode_results results;

    if (irrecv.decode(&results))
    {
        Serial.println(results.value, HEX);
        // check if the code is in the list of valid codes
        for (int c = 0; c < 17; c++)
        {
            if (IRCodes[c] == results.value)
            {
                switchIR(results.value); // make change
                break;
            }
        }
        irrecv.resume(); // Receive the next value
    }
}

// Change colors or patterns on LEFT and RIGHT key presses
void changeCommandIR(int direction)
{
    String command = "";

    // ************* RIGHT key
    if (direction == 1)
    {
        if (mode == MODE_COLORS)
        {
            if (colorIndex < NO_COLORS)
            {
                colorIndex++;
                command = ColorCodes[colorIndex];
            }
        }
        if (mode == MODE_SEGMENTS)
        {
            if (segmentIndex < NO_SEGMENTS)
            {
                segmentIndex++;
                command = SegmentCodes[segmentIndex];
            }
        }
        if (mode == MODE_PATTERNS)
        {
            if (patternIndex < NO_PATTERNS)
            {
                patternIndex++;
                command = "p" + String(patternIndex);
            }
        }
        if (mode == MODE_MUSIC)
        {
            if (vuIndex < NO_MUSIC)
            {
                vuIndex++;
                command = "v" + String(vuIndex);
            }
        }
    }
    // ************* LEFT key
    else
    {
        if (mode == MODE_COLORS)
        {
            if (colorIndex > 0)
            {
                colorIndex--;
                command = ColorCodes[colorIndex];
            }
        }
        if (mode == MODE_SEGMENTS)
        {
            if (segmentIndex > 0)
            {
                segmentIndex--;
                command = SegmentCodes[segmentIndex];
            }
        }
        if (mode == MODE_PATTERNS)
        {
            if (patternIndex > 0)
            {
                patternIndex--;
                command = "p" + String(patternIndex);
            }
        }
        if (mode == MODE_MUSIC)
        {
            if (vuIndex > 200)
            {
                vuIndex--;
                command = "v" + String(vuIndex);
            }
        }
    }
    makeChange(command);
}