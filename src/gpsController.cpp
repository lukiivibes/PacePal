#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include <gpsController.hpp>
using namespace speedometer;

static const int RXPin = A0;   // wire to GPS TX
static const int TXPin = A1;   // wire to GPS RX
static const uint32_t GPSBaud = 9600;

SoftwareSerial GPSSerial(RXPin, TXPin);
TinyGPSPlus GPSMod;

void GPS::begin() {
  Serial.begin(115200);
  GPSSerial.begin(GPSBaud);
  Serial.println(F("Booting..."));
}

float GPS::getLong(){
    if (GPSSerial.available() > 0) {
        GPSMod.encode(GPSSerial.read());
    }

    if (GPSMod.location.isValid()){
        return GPSMod.location.lng();
    }
    return -1;
}

float GPS::getLat(){
    if (GPSSerial.available() > 0) {
        GPSMod.encode(GPSSerial.read());
    }

    if (GPSMod.location.isValid()){
        return GPSMod.location.lat();
    }
    return -1;
}

float GPS::getSpeed(){
    deltaTime = 333/1000;

    FLong = getLong();
    FLat = getLat();

    float latavg = ((FLat + ILat) / 2);
    ChangeLat = (FLat - ILat) * cos(latavg) * R;
    ChangeLong = (FLong - ILong) * R;

    float Displacement = sqrt(pow(ChangeLat, 2) + pow(ChangeLong, 2));

    ILong = getLong();
    ILat = getLat();

    return Displacement/deltaTime;
}