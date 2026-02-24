#pragma once
#include <QObject>
#include <QTimer>
#include <QVariantList>
#include <QtQml/qqml.h>

class NavigationController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(bool    isNavigating    READ isNavigating    NOTIFY isNavigatingChanged)
    Q_PROPERTY(QString currentStreet   READ currentStreet   NOTIFY navigationUpdated)
    Q_PROPERTY(QString nextManeuver    READ nextManeuver    NOTIFY navigationUpdated)
    Q_PROPERTY(QString directionIcon   READ directionIcon   NOTIFY navigationUpdated)
    Q_PROPERTY(int     etaMinutes      READ etaMinutes      NOTIFY navigationUpdated)
    Q_PROPERTY(double  distanceToNext  READ distanceToNext  NOTIFY navigationUpdated)
    Q_PROPERTY(double  routeProgress   READ routeProgress   NOTIFY routeProgressChanged)
    Q_PROPERTY(QString destination     READ destination     NOTIFY navigationUpdated)
    Q_PROPERTY(double  carX            READ carX            NOTIFY carPositionChanged)
    Q_PROPERTY(double  carY            READ carY            NOTIFY carPositionChanged)

public:
    explicit NavigationController(QObject *parent = nullptr);

    bool    isNavigating()   const { return m_isNavigating; }
    QString currentStreet()  const { return m_currentStreet; }
    QString nextManeuver()   const { return m_nextManeuver; }
    QString directionIcon()  const { return m_directionIcon; }
    int     etaMinutes()     const { return m_etaMinutes; }
    double  distanceToNext() const { return m_distanceToNext; }
    double  routeProgress()  const { return m_routeProgress; }
    QString destination()    const { return m_destination; }
    double  carX()           const { return m_carX; }
    double  carY()           const { return m_carY; }

public slots:
    void startRoute();
    void stopRoute();

signals:
    void isNavigatingChanged();
    void navigationUpdated();
    void routeProgressChanged();
    void carPositionChanged();

private slots:
    void onTick();

private:
    struct Waypoint {
        double x, y;
        QString street;
        QString maneuver;
        QString direction;
    };

    QList<Waypoint> m_waypoints;
    int     m_waypointIndex  = 0;
    bool    m_isNavigating   = false;
    QString m_currentStreet  = "Oak Avenue";
    QString m_nextManeuver   = "Turn right onto Elm Street";
    QString m_directionIcon  = "turn-right";
    int     m_etaMinutes     = 12;
    double  m_distanceToNext = 0.4;
    double  m_routeProgress  = 0.0;
    QString m_destination    = "Downtown Plaza";
    double  m_carX           = 0.1;
    double  m_carY           = 0.5;

    double  m_stepProgress   = 0.0;
    QTimer  m_timer;
};
