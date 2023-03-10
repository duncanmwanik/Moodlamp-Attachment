#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "def.h"

BLEServer *pServer = NULL;
BLECharacteristic *c = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb54800-36e1-4688-b7f5-ea07361b26a8"

class MyServerCallbacks : public BLEServerCallbacks
{
  void onConnect(BLEServer *pServer)
  {
    deviceConnected = true;
    Serial.println(">>>> Connected!");
    BLEDevice::startAdvertising();
  };

  void onDisconnect(BLEServer *pServer)
  {
    deviceConnected = false;
    Serial.println(">>>> Disconnected!");
    pServer->startAdvertising();
  }
};

void setupBLE()
{
  Serial.println("------------------------------------------------------------");
  Serial.println("Setting up BLE ...");

  // Create the BLE Device
  String name = preferences.getString("btname", "Mood Lamp One");
  BLEDevice::init(name.c_str());

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
  pServer->disconnect(0);

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  c = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE |
          BLECharacteristic::PROPERTY_NOTIFY |
          BLECharacteristic::PROPERTY_INDICATE);

  c->addDescriptor(new BLE2902());
  // Start the service
  pService->start();
  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0); // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting for client to connect ...");
}

void changeBtName(String name)
{
  preferences.putString("btname", name);
  ESP.restart();
}

void sendData(int type)
{
  String data = "ds-";
  if (type == 0)
  {
    data = data + brightness + "-" + speed + "-" + sensitivity;
  }
  if (type == 1)
  {
    data = data + LAMP_ID + "-" + LAMP_VERSION + "-" + LAMP_SOFTWARE_VERSION;
  }
  c->setValue(data.c_str());
  c->notify();

  Serial.print("Sending requested data: ");
  Serial.println(data);
}
