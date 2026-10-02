#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_L3GD20_U.h>
#include "gyroController.hpp"

using namespace speedometer;
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(54321);
sensor_t gyroSens;


bool GYRO::begin(){
    gyro.begin();
    return gyro.begin();
}

void GYRO::initGyro(){
    if (!gyro.begin()){
        Serial.print("NO GYRO DETECTED");
        return;
    }

    Serial.print("Gyro Initialized");
}


float GYRO::gyroTimer(){
    uint32_t currentTime = millis();
    double dt = (currentTime - lastTime) / 1000.0; // convert to seconds
    lastTime = currentTime;

    return dt;
}

float GYRO::getHeading(){
    sensors_event_t event;
    gyro.getSensor(&gyroSens);
    gyro.getEvent(&event);
    radHeading += event.gyro.heading *  gyroTimer();
    float Heading = radHeading * (180 / PI);

    return Heading;
}

float GYRO::getPitch(){
    sensors_event_t event;
    gyro.getSensor(&gyroSens);
    gyro.getEvent(&event);
    radPitch += event.gyro.pitch * gyroTimer();
    float Pitch = radPitch * (180/PI);
    return Pitch;
}

float GYRO::getRoll(){
    sensors_event_t event;
    gyro.getSensor(&gyroSens);
    gyro.getEvent(&event);
    radRoll += event.gyro.roll * gyroTimer();
    float Roll = radRoll * (180/PI);
    return Roll;
}