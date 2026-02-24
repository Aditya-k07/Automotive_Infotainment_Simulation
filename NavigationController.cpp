#include "NavigationController.h"
#include <QtMath>

NavigationController::NavigationController(QObject *parent) : QObject(parent)
{
    // Build a simple mock route with 6 waypoints (normalised 0-1 coords)
    m_waypoints = {
        { 0.10, 0.75, "Oak Avenue",      "Continue straight",            "straight"  },
        { 0.25, 0.75, "Oak Ave & 5th",   "Turn right onto Elm Street",   "turn-right"},
        { 0.25, 0.45, "Elm Street",      "Turn left onto Main Blvd",     "turn-left" },
        { 0.55, 0.45, "Main Blvd",       "Keep left on Riverside Dr",    "keep-left" },
        { 0.70, 0.30, "Riverside Drive", "Turn right onto Central Ave",  "turn-right"},
        { 0.88, 0.30, "Central Avenue",  "Arriving at Downtown Plaza",   "destination"},
    };

    m_carX = m_waypoints[0].x;
    m_carY = m_waypoints[0].y;

    m_timer.setInterval(80); // ~12 Hz for smooth animation
    connect(&m_timer, &QTimer::timeout, this, &NavigationController::onTick);
}

void NavigationController::startRoute()
{
    m_waypointIndex = 0;
    m_stepProgress  = 0.0;
    m_routeProgress = 0.0;
    m_etaMinutes    = 12;
    m_carX          = m_waypoints[0].x;
    m_carY          = m_waypoints[0].y;
    m_currentStreet = m_waypoints[0].street;
    m_nextManeuver  = m_waypoints[0].maneuver;
    m_directionIcon = m_waypoints[0].direction;
    m_isNavigating  = true;
    m_timer.start();
    emit isNavigatingChanged();
    emit navigationUpdated();
    emit carPositionChanged();
}

void NavigationController::stopRoute()
{
    m_isNavigating = false;
    m_timer.stop();
    emit isNavigatingChanged();
}

void NavigationController::onTick()
{
    if (m_waypointIndex >= m_waypoints.size() - 1) {
        stopRoute();
        return;
    }

    const Waypoint &from = m_waypoints[m_waypointIndex];
    const Waypoint &to   = m_waypoints[m_waypointIndex + 1];

    m_stepProgress += 0.004; // speed of car along segment
    if (m_stepProgress >= 1.0) {
        m_stepProgress = 0.0;
        m_waypointIndex++;
        if (m_waypointIndex < m_waypoints.size()) {
            m_currentStreet = m_waypoints[m_waypointIndex].street;
            m_nextManeuver  = m_waypointIndex + 1 < m_waypoints.size()
                              ? m_waypoints[m_waypointIndex].maneuver : "Arrived!";
            m_directionIcon = m_waypoints[m_waypointIndex].direction;
            emit navigationUpdated();
        }
        return;
    }

    // Lerp car position
    m_carX = from.x + (to.x - from.x) * m_stepProgress;
    m_carY = from.y + (to.y - from.y) * m_stepProgress;
    emit carPositionChanged();

    // Overall route progress (0→1)
    m_routeProgress = (m_waypointIndex + m_stepProgress) / (m_waypoints.size() - 1);
    m_distanceToNext = (1.0 - m_stepProgress) * 0.5; // mock km
    m_etaMinutes = qMax(0, static_cast<int>(12 * (1.0 - m_routeProgress)));
    emit routeProgressChanged();
    emit navigationUpdated();
}
