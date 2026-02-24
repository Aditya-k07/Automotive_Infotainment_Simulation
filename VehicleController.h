#pragma once
#include <QObject>
#include <QTimer>
#include <QtQml/qqml.h>

class VehicleController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(double speed     READ speed     NOTIFY speedChanged)
    Q_PROPERTY(double rpm       READ rpm       NOTIFY rpmChanged)
    Q_PROPERTY(double fuel      READ fuel      NOTIFY fuelChanged)
    Q_PROPERTY(double engineTemp READ engineTemp NOTIFY engineTempChanged)

    Q_PROPERTY(bool warningEngine   READ warningEngine   NOTIFY warningEngineChanged)
    Q_PROPERTY(bool warningBattery  READ warningBattery  NOTIFY warningBatteryChanged)
    Q_PROPERTY(bool warningOil      READ warningOil      NOTIFY warningOilChanged)
    Q_PROPERTY(bool warningDoor     READ warningDoor     NOTIFY warningDoorChanged)
    Q_PROPERTY(bool warningSeatbelt READ warningSeatbelt NOTIFY warningSeatbeltChanged)

    Q_PROPERTY(bool isDriving READ isDriving NOTIFY isDrivingChanged)
    Q_PROPERTY(int  gear      READ gear      NOTIFY gearChanged)

public:
    explicit VehicleController(QObject *parent = nullptr);

    double speed()      const { return m_speed; }
    double rpm()        const { return m_rpm; }
    double fuel()       const { return m_fuel; }
    double engineTemp() const { return m_engineTemp; }

    bool warningEngine()   const { return m_warningEngine; }
    bool warningBattery()  const { return m_warningBattery; }
    bool warningOil()      const { return m_warningOil; }
    bool warningDoor()     const { return m_warningDoor; }
    bool warningSeatbelt() const { return m_warningSeatbelt; }

    bool isDriving() const { return m_isDriving; }
    int  gear()      const { return m_gear; }

public slots:
    void toggleDriving();
    void setTargetSpeed(double kmh);
    void toggleDoor();
    void toggleSeatbelt();

signals:
    void speedChanged();
    void rpmChanged();
    void fuelChanged();
    void engineTempChanged();
    void warningEngineChanged();
    void warningBatteryChanged();
    void warningOilChanged();
    void warningDoorChanged();
    void warningSeatbeltChanged();
    void isDrivingChanged();
    void gearChanged();

private slots:
    void onTick();

private:
    void updateGear();

    QTimer  m_timer;
    double  m_speed       = 0.0;
    double  m_rpm         = 800.0;
    double  m_fuel        = 78.0;
    double  m_engineTemp  = 20.0;
    double  m_targetSpeed = 0.0;
    int     m_gear        = 1;
    bool    m_isDriving   = false;

    bool m_warningEngine   = false;
    bool m_warningBattery  = false;
    bool m_warningOil      = false;
    bool m_warningDoor     = false;
    bool m_warningSeatbelt = false;

    int m_tickCount = 0;
};
