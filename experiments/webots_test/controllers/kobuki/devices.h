#pragma once

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/utils/AnsiCodes.hpp>
#include <webots/Lidar.hpp>
#include <webots/Gyro.hpp>
#include <webots/TouchSensor.hpp>

#include <iostream>

using namespace std;
using namespace webots;

typedef struct GyroMeasurement_t {
    double x;
    double y;
    double z;
    friend ostream& operator << (ostream& out, const GyroMeasurement_t& gm) {
        out << "x: " << gm.x << ", y: " << gm.y << ", z: " << gm.z;
        return out;
    }
} GyroMeasurement_t;

typedef struct BumpMeasurement_t {
    bool left;
    bool right;
    bool front;
    friend ostream& operator << (ostream& out, const BumpMeasurement_t& bm) {
        out << "l: " << bm.left << ", r: " << bm.right << ", f: " << bm.front;
        return out;
    }
} BumpMeasurement_t;

typedef struct LidarMeasurement_t {
    const float * left;
    const float * right;
    const float * front;
} LidarMeasurement_t;


class Devices : public Robot {
public:
    Devices(int ts = 32);

    int timeStep;
    Gyro * gyro;
    Lidar * lidars[3];
    TouchSensor * bumpSensors[3];
    Motor * motors[2];

    void init(int ts);
    void readGyro(GyroMeasurement_t& gm);
    void readBump(BumpMeasurement_t& bm);
    void readLidarImage(LidarMeasurement_t& lm);
    int getLidarHorizontalResolution();
    float getBatteryLevel();
    void chargeBattery();
    void setMotor(double leftSpeed, double rightSpeed);

private:
    chrono::time_point<chrono::steady_clock> start;
    float timeElapsedAfterLastCharge();
};
