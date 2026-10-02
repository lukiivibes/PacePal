#include <Wire.h>
#include <math.h>
#include <Adafruit_Sensor.h>
#include "accelController.hpp"
#include <Adafruit_LSM303.h>
#include <gyroController.hpp>
using namespace speedometer;
Adafruit_LSM303_Accel_Unified imu = Adafruit_LSM303_Accel_Unified(12345);
sensor_t accelSens;


speedometer::GYRO Gyroscope;


bool IMU::begin(){
    imu.begin();
    return imu.begin();
}

void IMU::initAccel(){
    accelSens.type = SENSOR_TYPE_LINEAR_ACCELERATION;
    if (!imu.begin()){
        Serial.print("NO IMU DETECTED");
        return;
    }

    Serial.print("Accel Initialize");
}

float IMU::getX(){
    sensors_event_t event;
    imu.getSensor(&accelSens);
    imu.getEvent(&event);
    return event.acceleration.x;
}

float IMU::getY(){
    sensors_event_t event;
    imu.getSensor(&accelSens);
    imu.getEvent(&event);
    return event.acceleration.y;
}

float IMU::getZ(){
    sensors_event_t event;
    imu.getSensor(&accelSens);
    imu.getEvent(&event);
    return event.acceleration.z;
}

float IMU::getgX(){
    GX = IMU::getX() - (g * sin(Gyroscope.getPitch()));
    
    return GX;
}

float IMU::getgY(){
    GY = IMU::getY() - (g * (-sin(Gyroscope.getRoll()) * cos(Gyroscope.getPitch())));

    return GY;
}

float IMU::getgZ(){
    GZ = IMU::getZ() - (g * (cos(Gyroscope.getRoll()) * cos(Gyroscope.getPitch())));

    return GZ;
}
    

