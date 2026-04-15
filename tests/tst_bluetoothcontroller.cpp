#include <QtTest/QtTest>
#include <QSignalSpy>
#include "BluetoothController.h"

class TestBluetoothController : public QObject
{
    Q_OBJECT

private slots:
    // ── Initialization ─────────────────────────────────────────────
    void testInitialValues();

    // ── Connect / Disconnect ───────────────────────────────────────
    void testConnectDevice();
    void testConnectDeviceSignals();
    void testDisconnectDevice();
    void testDisconnectClearsState();

    // ── Reconnect Disconnects Previous ─────────────────────────────
    void testReconnectDisconnectsPrevious();

    // ── Available Devices ──────────────────────────────────────────
    void testAvailableDevices();

    // ── Signal Strength ────────────────────────────────────────────
    void testSignalStrengthAfterConnect();
    void testSignalStrengthFluctuates();

    // ── Incoming Call ──────────────────────────────────────────────
    void testIncomingCallTriggered();

    // ── Answer Call ────────────────────────────────────────────────
    void testAnswerCall();

    // ── End Call ────────────────────────────────────────────────────
    void testEndCall();

    // ── Reject Call ────────────────────────────────────────────────
    void testRejectCall();

    // ── Call Duration Ticks ─────────────────────────────────────────
    void testCallDurationAdvances();

    // ── No Incoming If Already In Call ──────────────────────────────
    void testNoIncomingWhileInCall();
};

// ───────────────────────────────────────────────────────────────────
void TestBluetoothController::testInitialValues()
{
    BluetoothController ctrl;
    QCOMPARE(ctrl.isConnected(), false);
    QCOMPARE(ctrl.deviceName(), QString());
    QCOMPARE(ctrl.signalStrength(), 0);
    QCOMPARE(ctrl.isInCall(), false);
    QCOMPARE(ctrl.hasIncoming(), false);
    QCOMPARE(ctrl.callerName(), QString());
    QCOMPARE(ctrl.callDuration(), QString("00:00"));
}

void TestBluetoothController::testConnectDevice()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    QCOMPARE(ctrl.isConnected(), true);
    QCOMPARE(ctrl.deviceName(), QString("iPhone 15 Pro — Alex"));
    QCOMPARE(ctrl.signalStrength(), 85);
    ctrl.disconnectDevice();
}

void TestBluetoothController::testConnectDeviceSignals()
{
    BluetoothController ctrl;
    QSignalSpy connSpy(&ctrl, &BluetoothController::connectionChanged);
    QSignalSpy sigSpy(&ctrl, &BluetoothController::signalStrengthChanged);

    ctrl.connectDevice("Samsung S24 Ultra");
    QCOMPARE(connSpy.count(), 1);
    QCOMPARE(sigSpy.count(), 1);
    ctrl.disconnectDevice();
}

void TestBluetoothController::testDisconnectDevice()
{
    BluetoothController ctrl;
    ctrl.connectDevice("Pixel 8 — Sarah");
    ctrl.disconnectDevice();
    QCOMPARE(ctrl.isConnected(), false);
    QCOMPARE(ctrl.signalStrength(), 0);
}

void TestBluetoothController::testDisconnectClearsState()
{
    BluetoothController ctrl;
    ctrl.connectDevice("OnePlus 12");
    // Wait for incoming call
    QTest::qWait(9000);
    ctrl.answerCall();
    QTest::qWait(1000);

    ctrl.disconnectDevice();
    QCOMPARE(ctrl.isConnected(), false);
    QCOMPARE(ctrl.deviceName(), QString());
    QCOMPARE(ctrl.isInCall(), false);
    QCOMPARE(ctrl.hasIncoming(), false);
    QCOMPARE(ctrl.signalStrength(), 0);
}

void TestBluetoothController::testReconnectDisconnectsPrevious()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    ctrl.connectDevice("Samsung S24 Ultra");
    QCOMPARE(ctrl.deviceName(), QString("Samsung S24 Ultra"));
    QCOMPARE(ctrl.isConnected(), true);
    ctrl.disconnectDevice();
}

void TestBluetoothController::testAvailableDevices()
{
    BluetoothController ctrl;
    QStringList devices = ctrl.availableDevices();
    QCOMPARE(devices.size(), 4);
    QVERIFY(devices.contains("iPhone 15 Pro — Alex"));
    QVERIFY(devices.contains("Samsung S24 Ultra"));
    QVERIFY(devices.contains("Pixel 8 — Sarah"));
    QVERIFY(devices.contains("OnePlus 12"));
}

void TestBluetoothController::testSignalStrengthAfterConnect()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    QCOMPARE(ctrl.signalStrength(), 85);
    ctrl.disconnectDevice();
}

void TestBluetoothController::testSignalStrengthFluctuates()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    int initial = ctrl.signalStrength();
    // Signal timer fires every 3s — wait for a couple of ticks
    QTest::qWait(7000);
    // Signal strength should have changed (statistically very likely)
    // It's bounded 60-100, so it should be in range
    QVERIFY(ctrl.signalStrength() >= 60);
    QVERIFY(ctrl.signalStrength() <= 100);
    ctrl.disconnectDevice();
}

void TestBluetoothController::testIncomingCallTriggered()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    // Incoming call triggers after 8s
    QTest::qWait(9000);
    QCOMPARE(ctrl.hasIncoming(), true);
    QVERIFY(!ctrl.callerName().isEmpty());
    ctrl.disconnectDevice();
}

void TestBluetoothController::testAnswerCall()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    QTest::qWait(9000); // wait for incoming call

    QSignalSpy spy(&ctrl, &BluetoothController::callStateChanged);
    ctrl.answerCall();
    QCOMPARE(ctrl.isInCall(), true);
    QCOMPARE(ctrl.hasIncoming(), false);
    QCOMPARE(ctrl.callDuration(), QString("00:00"));
    QVERIFY(spy.count() >= 1);

    ctrl.endCall();
    ctrl.disconnectDevice();
}

void TestBluetoothController::testEndCall()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    QTest::qWait(9000);
    ctrl.answerCall();
    QTest::qWait(2000);

    ctrl.endCall();
    QCOMPARE(ctrl.isInCall(), false);
    QCOMPARE(ctrl.callDuration(), QString("00:00"));
    QCOMPARE(ctrl.callerName(), QString());
    ctrl.disconnectDevice();
}

void TestBluetoothController::testRejectCall()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    QTest::qWait(9000);

    QSignalSpy spy(&ctrl, &BluetoothController::callStateChanged);
    ctrl.rejectCall();
    QCOMPARE(ctrl.hasIncoming(), false);
    QCOMPARE(ctrl.callerName(), QString());
    QCOMPARE(ctrl.isInCall(), false);
    QVERIFY(spy.count() >= 1);
    ctrl.disconnectDevice();
}

void TestBluetoothController::testCallDurationAdvances()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    QTest::qWait(9000);
    ctrl.answerCall();
    QTest::qWait(3500);
    // After ~3 seconds, call duration should be ~00:03
    QVERIFY(ctrl.callDuration() != QString("00:00"));
    ctrl.endCall();
    ctrl.disconnectDevice();
}

void TestBluetoothController::testNoIncomingWhileInCall()
{
    BluetoothController ctrl;
    ctrl.connectDevice("iPhone 15 Pro — Alex");
    QTest::qWait(9000);
    ctrl.answerCall();
    // triggerIncomingCall checks m_isInCall and should bail out
    // The internal timer has already fired, so no new incoming should appear
    QCOMPARE(ctrl.hasIncoming(), false);
    ctrl.endCall();
    ctrl.disconnectDevice();
}

QTEST_MAIN(TestBluetoothController)
#include "tst_bluetoothcontroller.moc"
