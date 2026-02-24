#include "BluetoothController.h"
#include <QRandomGenerator>

static const QStringList kCallers = {
    "Alex Johnson", "Sarah Mitchell", "Mom", "Dave (Work)", "Emma Clarke"
};

BluetoothController::BluetoothController(QObject *parent) : QObject(parent)
{
    m_availableDevices = {
        "iPhone 15 Pro — Alex",
        "Samsung S24 Ultra",
        "Pixel 8 — Sarah",
        "OnePlus 12"
    };

    m_signalTimer.setInterval(3000);
    connect(&m_signalTimer, &QTimer::timeout, this, &BluetoothController::onSignalTick);

    m_incomingCallTimer.setSingleShot(true);
    connect(&m_incomingCallTimer, &QTimer::timeout, this, &BluetoothController::triggerIncomingCall);

    m_callTimer.setInterval(1000);
    connect(&m_callTimer, &QTimer::timeout, this, &BluetoothController::onCallTick);
}

void BluetoothController::connectDevice(const QString &name)
{
    if (m_isConnected) disconnectDevice();
    m_deviceName    = name;
    m_isConnected   = true;
    m_signalStrength = 85;
    m_signalTimer.start();
    m_incomingCallTimer.start(8000); // incoming call after 8s
    emit connectionChanged();
    emit signalStrengthChanged();
}

void BluetoothController::disconnectDevice()
{
    endCall();
    m_isConnected   = false;
    m_deviceName.clear();
    m_signalStrength = 0;
    m_hasIncoming   = false;
    m_signalTimer.stop();
    m_incomingCallTimer.stop();
    emit connectionChanged();
    emit signalStrengthChanged();
    emit callStateChanged();
}

void BluetoothController::answerCall()
{
    m_hasIncoming = false;
    m_isInCall    = true;
    m_callSeconds = 0;
    m_callDuration = "00:00";
    m_callTimer.start();
    emit callStateChanged();
}

void BluetoothController::endCall()
{
    m_isInCall    = false;
    m_hasIncoming = false;
    m_callSeconds = 0;
    m_callDuration = "00:00";
    m_callerName.clear();
    m_callTimer.stop();
    emit callStateChanged();
}

void BluetoothController::rejectCall()
{
    m_hasIncoming = false;
    m_callerName.clear();
    emit callStateChanged();
}

void BluetoothController::onSignalTick()
{
    int delta = QRandomGenerator::global()->bounded(-5, 6);
    m_signalStrength = qBound(60, m_signalStrength + delta, 100);
    emit signalStrengthChanged();
}

void BluetoothController::triggerIncomingCall()
{
    if (!m_isConnected || m_isInCall) return;
    m_callerName  = kCallers[QRandomGenerator::global()->bounded(kCallers.size())];
    m_hasIncoming = true;
    emit callStateChanged();
}

void BluetoothController::onCallTick()
{
    m_callSeconds++;
    int m = m_callSeconds / 60;
    int s = m_callSeconds % 60;
    m_callDuration = QString("%1:%2")
        .arg(m, 2, 10, QChar('0'))
        .arg(s, 2, 10, QChar('0'));
    emit callStateChanged();
}
