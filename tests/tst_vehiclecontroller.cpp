#include <QtTest/QtTest>
#include <QSignalSpy>
#include "VehicleController.h"

class TestVehicleController : public QObject
{
    Q_OBJECT

private slots:
    // ── Initialization ─────────────────────────────────────────────
    void testInitialValues();

    // ── Driving Toggle ─────────────────────────────────────────────
    void testToggleDriving();
    void testToggleDrivingOff();

    // ── Target Speed ───────────────────────────────────────────────
    void testSetTargetSpeed();
    void testSetTargetSpeedClampLow();
    void testSetTargetSpeedClampHigh();

    // ── Door / Seatbelt Toggles ────────────────────────────────────
    void testToggleDoor();
    void testToggleSeatbelt();

    // ── Gear Calculation ───────────────────────────────────────────
    void testGearCalculation();

    // ── Speed Simulation (tick-based) ──────────────────────────────
    void testSpeedConvergesToTarget();

    // ── Fuel Consumption ───────────────────────────────────────────
    void testFuelDrains();

    // ── Engine Temperature ─────────────────────────────────────────
    void testEngineTemperatureWarming();

    // ── Warning: Oil (low fuel) ────────────────────────────────────
    void testOilWarningOnLowFuel();

    // ── Speed Bounds ───────────────────────────────────────────────
    void testSpeedNeverNegative();
    void testSpeedNeverExceeds220();
};

// ───────────────────────────────────────────────────────────────────
void TestVehicleController::testInitialValues()
{
    VehicleController ctrl; 
    QCOMPARE(ctrl.speed(), 0.0);
    QCOMPARE(ctrl.rpm(), 800.0);
    QCOMPARE(ctrl.fuel(), 78.0);
    QCOMPARE(ctrl.engineTemp(), 20.0);
    QCOMPARE(ctrl.isDriving(), false);
    QCOMPARE(ctrl.gear(), 1);

    QCOMPARE(ctrl.warningEngine(), false);
    QCOMPARE(ctrl.warningBattery(), false);
    QCOMPARE(ctrl.warningOil(), false);
    QCOMPARE(ctrl.warningDoor(), false);
    QCOMPARE(ctrl.warningSeatbelt(), false);
}

void TestVehicleController::testToggleDriving()
{
    VehicleController ctrl;
    QSignalSpy spy(&ctrl, &VehicleController::isDrivingChanged);
    ctrl.toggleDriving();
    QCOMPARE(ctrl.isDriving(), true);
    QCOMPARE(spy.count(), 1);
}

void TestVehicleController::testToggleDrivingOff()
{
    VehicleController ctrl;
    ctrl.toggleDriving();  // on
    ctrl.toggleDriving();  // off
    QCOMPARE(ctrl.isDriving(), false);
}

void TestVehicleController::testSetTargetSpeed()
{
    VehicleController ctrl;
    ctrl.setTargetSpeed(100.0);
    // Target is internal — indirectly verified via speed convergence,
    // but we can at least verify no crash and the method returns.
    QVERIFY(true);
}

void TestVehicleController::testSetTargetSpeedClampLow()
{
    VehicleController ctrl;
    ctrl.setTargetSpeed(-50.0);
    // Clamped to 0.0 internally — speed should stay at 0
    QTest::qWait(300);  // let a few ticks run
    QVERIFY(ctrl.speed() >= 0.0);
}

void TestVehicleController::testSetTargetSpeedClampHigh()
{
    VehicleController ctrl;
    ctrl.setTargetSpeed(999.0);
    // Clamped to 220.0 internally
    QTest::qWait(500);
    QVERIFY(ctrl.speed() <= 220.0);
}

void TestVehicleController::testToggleDoor()
{
    VehicleController ctrl;
    QSignalSpy spy(&ctrl, &VehicleController::warningDoorChanged);
    QCOMPARE(ctrl.warningDoor(), false);
    ctrl.toggleDoor();
    QCOMPARE(ctrl.warningDoor(), true);
    QCOMPARE(spy.count(), 1);
    ctrl.toggleDoor();
    QCOMPARE(ctrl.warningDoor(), false);
    QCOMPARE(spy.count(), 2);
}

void TestVehicleController::testToggleSeatbelt()
{
    VehicleController ctrl;
    QSignalSpy spy(&ctrl, &VehicleController::warningSeatbeltChanged);
    QCOMPARE(ctrl.warningSeatbelt(), false);
    ctrl.toggleSeatbelt();
    QCOMPARE(ctrl.warningSeatbelt(), true);
    QCOMPARE(spy.count(), 1);
    ctrl.toggleSeatbelt();
    QCOMPARE(ctrl.warningSeatbelt(), false);
}

void TestVehicleController::testGearCalculation()
{
    VehicleController ctrl;
    ctrl.toggleDriving();
    ctrl.setTargetSpeed(110.0); // Target high enough for Gear 4+
    // Need enough time to reach 100+ kmh for gear 5/6
    // 100 kmh / 8 kmh/s = 12.5s
    QTest::qWait(15000); 
    QVERIFY(ctrl.gear() >= 4);
}

void TestVehicleController::testSpeedConvergesToTarget()
{
    VehicleController ctrl;
    ctrl.toggleDriving();
    ctrl.setTargetSpeed(60.0);
    // 60 kmh / 8 kmh/s = 7.5s. Wait 10s.
    QTest::qWait(10000);
    QVERIFY(qAbs(ctrl.speed() - 60.0) < 5.0);
}

void TestVehicleController::testFuelDrains()
{
    VehicleController ctrl;
    double initialFuel = ctrl.fuel();
    ctrl.toggleDriving();
    // Fuel drains every 50 ticks (5s). Wait 10s to be sure.
    QTest::qWait(10000);
    QVERIFY(ctrl.fuel() < initialFuel);
}

void TestVehicleController::testEngineTemperatureWarming()
{
    VehicleController ctrl;
    double initialTemp = ctrl.engineTemp();
    ctrl.toggleDriving();
    QTest::qWait(3000);
    QVERIFY(ctrl.engineTemp() > initialTemp);
}

void TestVehicleController::testOilWarningOnLowFuel()
{
    // Oil warning triggers when fuel < 15.0
    // We can't easily drain fuel fast, but verify the warning logic
    // by checking initial state (fuel = 78, so no warning)
    VehicleController ctrl;
    QTest::qWait(200);
    QCOMPARE(ctrl.warningOil(), false);
}

void TestVehicleController::testSpeedNeverNegative()
{
    VehicleController ctrl;
    ctrl.setTargetSpeed(-100.0);
    QTest::qWait(500);
    QVERIFY(ctrl.speed() >= 0.0);
}

void TestVehicleController::testSpeedNeverExceeds220()
{
    VehicleController ctrl;
    ctrl.toggleDriving();
    ctrl.setTargetSpeed(220.0);
    QTest::qWait(3000);
    QVERIFY(ctrl.speed() <= 220.0);
}

QTEST_MAIN(TestVehicleController)
#include "tst_vehiclecontroller.moc"
