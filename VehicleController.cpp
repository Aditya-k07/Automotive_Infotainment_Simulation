#include "VehicleController.h"
#include <QtMath>
#include <QRandomGenerator>

VehicleController::VehicleController(QObject *parent) : QObject(parent)
{
    m_timer.setInterval(100); // 10 Hz
    connect(&m_timer, &QTimer::timeout, this, &VehicleController::onTick);
    m_timer.start(); // always ticking so idle RPM/temp warm-up works
}

void VehicleController::toggleDriving()
{
    m_isDriving = !m_isDriving;
    if (m_isDriving) {
        m_targetSpeed = 120.0;
    } else {
        m_targetSpeed = 0.0;
    }
    emit isDrivingChanged();
}

void VehicleController::setTargetSpeed(double kmh)
{
    m_targetSpeed = qBound(0.0, kmh, 220.0);
}

void VehicleController::toggleDoor()
{
    m_warningDoor = !m_warningDoor;
    emit warningDoorChanged();
}

void VehicleController::toggleSeatbelt()
{
    m_warningSeatbelt = !m_warningSeatbelt;
    emit warningSeatbeltChanged();
}

void VehicleController::onTick()
{
    m_tickCount++;

    // --- Speed ---
    double speedDiff = m_targetSpeed - m_speed;
    double accel = m_isDriving ? 0.8 : 1.5; // decel faster
    if (qAbs(speedDiff) < accel) {
        m_speed = m_targetSpeed;
    } else {
        m_speed += (speedDiff > 0 ? accel : -accel);
    }
    m_speed = qBound(0.0, m_speed, 220.0);
    emit speedChanged();

    // --- RPM ---  correlate with speed + gear
    updateGear();
    double rpmTarget = 800.0;
    if (m_isDriving || m_speed > 0) {
        // rpm = base + speed * factor / gear
        rpmTarget = 800.0 + (m_speed * 30.0) / qMax(m_gear, 1);
        rpmTarget = qBound(700.0, rpmTarget, 8000.0);
    }
    double rpmDiff = rpmTarget - m_rpm;
    m_rpm += rpmDiff * 0.15;
    emit rpmChanged();

    // --- Engine Temp --- warm up, stabilise at 90°C while driving
    double tempTarget = m_isDriving ? 90.0 : (m_speed > 0 ? 85.0 : 20.0);
    m_engineTemp += (tempTarget - m_engineTemp) * 0.002;
    emit engineTempChanged();

    // --- Fuel --- drain slowly while driving
    if (m_isDriving && m_tickCount % 50 == 0) { // every 5s
        m_fuel = qMax(0.0, m_fuel - 0.1);
        emit fuelChanged();
    }

    // --- Warnings ---
    bool warnEng = (m_engineTemp > 110.0);
    if (warnEng != m_warningEngine) { m_warningEngine = warnEng; emit warningEngineChanged(); }

    bool warnBat = (m_tickCount % 1200 == 0); // blink every 2min
    if (warnBat && !m_warningBattery) {
        m_warningBattery = true; emit warningBatteryChanged();
        QTimer::singleShot(3000, this, [this]{ m_warningBattery = false; emit warningBatteryChanged(); });
    }

    bool warnOil = (m_fuel < 15.0);
    if (warnOil != m_warningOil) { m_warningOil = warnOil; emit warningOilChanged(); }
}

void VehicleController::updateGear()
{
    int newGear;
    if      (m_speed < 20)  newGear = 1;
    else if (m_speed < 40)  newGear = 2;
    else if (m_speed < 70)  newGear = 3;
    else if (m_speed < 100) newGear = 4;
    else if (m_speed < 140) newGear = 5;
    else                    newGear = 6;

    if (newGear != m_gear) {
        m_gear = newGear;
        emit gearChanged();
    }
}
