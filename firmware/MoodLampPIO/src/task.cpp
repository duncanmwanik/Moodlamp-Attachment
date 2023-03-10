#include <FastLED.h>
#include <Preferences.h>

#include "def.h"

// This runs patterns and vus in the second core
// To switch effects, we break the running effect and change codes
TaskHandle_t EffectTask = NULL;

volatile int code = 666; // for choosing a pattern or vu
volatile bool x = false; // this breaks pattern or vu loops

void effectTask(void *)
{
    for (;;)
    {
        x = false;
        clear();
        if (code != 666)
        {
            switchEffect(code);
        }
        if (code == 666)
        {
            Serial.println("Suspending effect task...");
            vTaskSuspend(NULL);
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void createEffectTask()
{
    Serial.println("Creating effect task...");

    xTaskCreatePinnedToCore(
        effectTask,   /* Task function. */
        "EffectTask", /* name of task. */
        10000,        /* Stack size of task */
        NULL,         /* parameter of the task */
        10,           /* priority of the task */
        &EffectTask,  /* Task handle to keep track of created task */
        1);
}