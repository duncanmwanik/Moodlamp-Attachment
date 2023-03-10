#include <esp_now.h>
#include <esp_wifi.h>
#include <WiFi.h>
#include "def.h"

// ESPNOW MAC Address
uint8_t customMACAddress[] = {0xAA, 0xBB, 0xCC, 0xDD, 0x66, 0x99};

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message
{
  char a[255];
} struct_message;

// Create a struct_message called receivedData
struct_message receivedData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  memcpy(&receivedData, incomingData, sizeof(receivedData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  String command = String(receivedData.a);
  Serial.print("Command: ");
  Serial.println(command);
}

void setCustomMAC()
{
  esp_wifi_set_mac(WIFI_IF_STA, &customMACAddress[0]);
  Serial.print("[NEW] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
}

void activateSlave()
{
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  // Set the boards custome MAC Address
  setCustomMAC();

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK)
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}