#pragma once
#include <QObject>
#include <QTimer>
#include <QStringList>
#include <QtQml/qqml.h>

class BluetoothController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(bool    isConnected    READ isConnected    NOTIFY connectionChanged)
    Q_PROPERTY(QString deviceName     READ deviceName     NOTIFY connectionChanged)
    Q_PROPERTY(int     signalStrength READ signalStrength NOTIFY signalStrengthChanged)
    Q_PROPERTY(bool    isInCall       READ isInCall       NOTIFY callStateChanged)
    Q_PROPERTY(QString callerName     READ callerName     NOTIFY callStateChanged)
    Q_PROPERTY(QString callDuration   READ callDuration   NOTIFY callStateChanged)
    Q_PROPERTY(bool    hasIncoming    READ hasIncoming    NOTIFY callStateChanged)
    Q_PROPERTY(QStringList availableDevices READ availableDevices CONSTANT)

public:
    explicit BluetoothController(QObject *parent = nullptr);

    bool       isConnected()      const { return m_isConnected; }
    QString    deviceName()       const { return m_deviceName; }
    int        signalStrength()   const { return m_signalStrength; }
    bool       isInCall()         const { return m_isInCall; }
    QString    callerName()       const { return m_callerName; }
    QString    callDuration()     const { return m_callDuration; }
    bool       hasIncoming()      const { return m_hasIncoming; }
    QStringList availableDevices() const { return m_availableDevices; }

public slots:
    void connectDevice(const QString &name);
    void disconnectDevice();
    void answerCall();
    void endCall();
    void rejectCall();

signals:
    void connectionChanged();
    void signalStrengthChanged();
    void callStateChanged();

private slots:
    void onSignalTick();
    void triggerIncomingCall();
    void onCallTick();

private:
    bool        m_isConnected    = false;
    QString     m_deviceName;
    int         m_signalStrength = 0;
    bool        m_isInCall       = false;
    bool        m_hasIncoming    = false;
    QString     m_callerName;
    QString     m_callDuration   = "00:00";
    int         m_callSeconds    = 0;

    QStringList m_availableDevices;
    QTimer      m_signalTimer;
    QTimer      m_incomingCallTimer;
    QTimer      m_callTimer;
};
