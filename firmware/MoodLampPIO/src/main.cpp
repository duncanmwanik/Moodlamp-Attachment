#include "def.h"

void setup()
{
  Serial.begin(115200);

  loadVariables();

  setupFastLed();

  setupIR();

  setupBLE();

  setupMic();

  createEffectTask();

  makeChange(preferences.getString("command", "0xff0000"));
}

void loop()
{
  checkChange();
}
