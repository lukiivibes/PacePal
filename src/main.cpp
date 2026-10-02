#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "accelController.hpp"
#include <Adafruit_LSM303.h>
#include "gyroController.hpp"
#include <gpsController.hpp>

#define SDA_PIN PB7
#define SCL_PIN PB6

#define CTRL_REG1_A   0x20
#define OUT_X_L_A     0x28
#define AUTO_INCREMENT 0x80   // MSB of sub-address enables burst reads


speedometer::IMU inertial;
speedometer::GYRO gyroscope;
speedometer::GPS gps;

void setup(void)
{
  Serial.begin(9600);
  Wire.begin(SDA_PIN, SCL_PIN); // Important do not remove connects to IMU
  
  
  gyroscope.begin();
  inertial.begin();
  gps.begin();

   
  inertial.initAccel();
  gyroscope.initGyro();
 
}

int timer = 0;
double speed = 0;

void loop(){
  /*Serial.print("X: "); Serial.print(inertial.getX());
  Serial.print("  Y: "); Serial.print(inertial.getY());
  Serial.print("  Z: "); Serial.print(inertial.getZ());

  gyroscope.gyroTimer();
  Serial.print("  Heading: "); Serial.print(gyroscope.getHeading());
  Serial.print("  Pitch: "); Serial.print(gyroscope.getPitch());
  Serial.print("  Roll: "); Serial.println(gyroscope.getRoll());*/

  Serial.print("  Lat = "); Serial.println(gps.getLat(), 6);
  Serial.print("  Long = "); Serial.print(gps.getLong(), 6);

  /*if(timer % 333 == 0 || timer == 0){
    speed = gps.getSpeed();
    Serial.print("  Speed = "); Serial.println(gps.getSpeed(), 6);
  }

  timer += 1;
  delay(1);
  */
}



/*

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

static const int RXPin = A0;   // wire to GPS TX
static const int TXPin = A1;   // wire to GPS RX
static const uint32_t GPSBaud = 9600;

SoftwareSerial GPSSerial(RXPin, TXPin);
TinyGPSPlus gps;

unsigned long lastPrint = 0;

void setup() {
  Serial.begin(115200);        // <-- this was missing
  GPSSerial.begin(GPSBaud);
  Serial.println(F("Booting..."));
}

void loop() {
  while (GPSSerial.available() > 0) {
    gps.encode(GPSSerial.read());
  }

  // print status once per second WITHOUT blocking the reader
  if (millis() - lastPrint >= 1000) {
    lastPrint = millis();

    Serial.print(F("chars="));
    Serial.print(gps.charsProcessed());
    Serial.print(F("  sentences="));
    Serial.print(gps.sentencesWithFix());
    Serial.print(F("  failed="));
    Serial.print(gps.failedChecksum());
    Serial.print(F("  sats="));
    Serial.print(gps.satellites.isValid() ? gps.satellites.value() : 0);

    if (gps.location.isValid()) {
      Serial.print(F("  Lat="));
      Serial.print(gps.location.lat(), 6);
      Serial.print(F("  Lng="));
      Serial.print(gps.location.lng(), 6);
    } else {
      Serial.print(F("  no fix yet"));
    }
    Serial.println();
  }
}*/
