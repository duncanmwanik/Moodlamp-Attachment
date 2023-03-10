// #include "FastLED.h"
// #include "def.h"

// // Initialize changeable global variables.
// uint8_t max_bright = 128; // Overall brightness definition. It can be changed on the fly.

// // Initialize global variables for sequences
// int thisdelay = 50; // A delay value for the sequence(s)
// int thishue = 95;
// int thissat = 255;
// int thisdir = 0;
// bool huerot = 0; // Does the hue rotate? 1 = yes
// uint8_t bgclr = 0;
// uint8_t bgbri = 0;

// void ChangeMe()
// {                                                // A time (rather than loop) based demo sequencer. This gives us full control over the length of each sequence.
//     uint8_t secondHand = (millis() / 1000) % 25; // Change '25' to a different value to change length of the loop.
//     static uint8_t lastSecond = 99;              // Static variable, means it's only defined once. This is our 'debounce' variable.
//     if (lastSecond != secondHand)
//     { // Debounce to make sure we're not repeating an assignment.
//         lastSecond = secondHand;
//         switch (secondHand)
//         {
//         case 0:
//             thisdelay = 50;
//             thishue = 95;
//             bgclr = 140;
//             bgbri = 20;
//             huerot = 0;
//             break;
//         case 5:
//             thisdir = 1;
//             bgbri = 0;
//             huerot = 1;
//             break;
//         case 10:
//             thisdelay = 30;
//             thishue = 0;
//             bgclr = 50;
//             bgbri = 20;
//             huerot = 0;
//             break;
//         case 15:
//             thisdelay = 80;
//             bgbri = 10;
//             thishue = random8();
//             break;
//         case 20:
//             thishue = random8();
//             huerot = 1;
//             break;
//         case 25:
//             break;
//         }
//     }
// }

// void matrix()
// { // One line matrix

//     if (huerot)
//         thishue = thishue + 5;

//     if (random16(90) > 80)
//     {
//         if (thisdir == 0)
//             led[0] = CHSV(thishue, thissat, 255);
//         else
//             led[NUM_LEDS - 1] = CHSV(thishue, thissat, 255);
//     }
//     else
//     {
//         if (thisdir == 0)
//             led[0] = CHSV(bgclr, thissat, bgbri);
//         else
//             led[NUM_LEDS - 1] = CHSV(bgclr, thissat, bgbri);
//     }

//     if (thisdir == 0)
//     {
//         for (int i = NUM_LEDS - 1; i > 0; i--)
//         {
//             if (x)
//                 break;
//             led[i] = led[i - 1];
//         }
//     }
//     else
//     {
//         for (int i = 0; i < NUM_LEDS - 1; i++)
//         {
//             if (x)
//                 break;
//             led[i] = led[i + 1];
//         }
//     }
// }

// void Matrix()
// {
//     ChangeMe();

//     EVERY_N_MILLISECONDS(thisdelay)
//     {             // FastLED based non-blocking delay to update/display the sequence.
//         matrix(); // Routine is still delay based, but at least it's now a non-blocking day.
//     }
//     FastLED.show();
// }