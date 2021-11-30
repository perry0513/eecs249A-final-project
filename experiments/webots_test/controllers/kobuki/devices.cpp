#include <chrono>
#include "devices.h"

Devices::Devices(int ts) {
    timeStep = ts;
}

void Devices::init(int ts) {
    timeStep = ts;
    gyro = getGyro("gyro");
    gyro->enable(timeStep);
    motors[0] = getMotor("wheel_left_joint");
    motors[1] = getMotor("wheel_right_joint");
    motors[0]->setPosition(std::numeric_limits<double>::infinity());
    motors[1]->setPosition(std::numeric_limits<double>::infinity());
    motors[0]->setVelocity(0.0);
    motors[1]->setVelocity(0.0);

    lidars[0] = getLidar("cliff_sensor_left");
    lidars[1] = getLidar("cliff_sensor_right");
    lidars[2] = getLidar("cliff_sensor_front");

    for (int i = 0; i < 3; ++i)
    lidars[i]->enable(timeStep);

    bumpSensors[0] = getTouchSensor("bump_sensor_left");
    bumpSensors[1] = getTouchSensor("bump_sensor_right");
    bumpSensors[2] = getTouchSensor("bump_sensor_front");

    for (int i = 0; i < 3; ++i)
    bumpSensors[i]->enable(timeStep);

    start = chrono::steady_clock::now();
}


void Devices::readGyro(GyroMeasurement_t& gm) {
    const double * vals = gyro->getValues();
    gm.x = vals[0]; gm.y = vals[1]; gm.z = vals[2];
}


void Devices::readBump(BumpMeasurement_t& bm) {
    bm.left = bool(bumpSensors[0]->getValue());
    bm.right = bool(bumpSensors[1]->getValue());
    bm.front = bool(bumpSensors[2]->getValue());
}


void Devices::readLidarImage(LidarMeasurement_t& lm) {
    lm.left = lidars[0]->getRangeImage();
    lm.right = lidars[1]->getRangeImage();
    lm.front = lidars[2]->getRangeImage();
}

int Devices::getLidarHorizontalResolution() {
    return lidars[0]->getHorizontalResolution();
}

float Devices::getBatteryLevel() {
    return 100 - timeElapsedAfterLastCharge() / 5.0;
}

void Devices::setMotor(double leftSpeed, double rightSpeed) {
    motors[0]->setVelocity(leftSpeed);
    motors[1]->setVelocity(rightSpeed);
}

/* private methods */
float Devices::timeElapsedAfterLastCharge() {
    return chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - start).count();
}

void Devices::chargeBattery() {
    start = chrono::steady_clock::now();
}
