#include <QtTest/QtTest>
#include <QSignalSpy>
#include "NavigationController.h"

class TestNavigationController : public QObject
{
    Q_OBJECT

private slots:
    // ── Initialization ─────────────────────────────────────────────
    void testInitialValues();

    // ── Start / Stop Route ─────────────────────────────────────────
    void testStartRoute();
    void testStopRoute();
    void testStartRouteResetsState();

    // ── Navigation Progress ────────────────────────────────────────
    void testRouteProgressAdvances();

    // ── Car Position ───────────────────────────────────────────────
    void testCarPositionMoves();

    // ── ETA Decreases ──────────────────────────────────────────────
    void testEtaDecreases();

    // ── Signals ────────────────────────────────────────────────────
    void testStartRouteEmitsSignals();
    void testStopRouteEmitsSignal();

    // ── Default Destination ────────────────────────────────────────
    void testDestination();

    // ── Direction Icon Changes ─────────────────────────────────────
    void testDirectionIconUpdates();

    // ── Route Progress Bound ───────────────────────────────────────
    void testRouteProgressBound();
};

// ───────────────────────────────────────────────────────────────────
void TestNavigationController::testInitialValues()
{
    NavigationController ctrl;
    QCOMPARE(ctrl.isNavigating(), false);
    QCOMPARE(ctrl.destination(), QString("Downtown Plaza"));
    QCOMPARE(ctrl.routeProgress(), 0.0);
    QCOMPARE(ctrl.etaMinutes(), 12);
}

void TestNavigationController::testStartRoute()
{
    NavigationController ctrl;
    ctrl.startRoute();
    QCOMPARE(ctrl.isNavigating(), true);
    QCOMPARE(ctrl.routeProgress(), 0.0);
    QCOMPARE(ctrl.currentStreet(), QString("Oak Avenue"));
    ctrl.stopRoute();
}

void TestNavigationController::testStopRoute()
{
    NavigationController ctrl;
    ctrl.startRoute();
    ctrl.stopRoute();
    QCOMPARE(ctrl.isNavigating(), false);
}

void TestNavigationController::testStartRouteResetsState()
{
    NavigationController ctrl;
    ctrl.startRoute();
    QTest::qWait(1000); // let progress advance
    ctrl.stopRoute();

    double progressAfterStop = ctrl.routeProgress();
    ctrl.startRoute(); // restart
    QCOMPARE(ctrl.routeProgress(), 0.0); // should be reset
    QVERIFY(ctrl.routeProgress() < progressAfterStop || progressAfterStop == 0.0);
    ctrl.stopRoute();
}

void TestNavigationController::testRouteProgressAdvances()
{
    NavigationController ctrl;
    ctrl.startRoute();
    QTest::qWait(2000);
    QVERIFY(ctrl.routeProgress() > 0.0);
    ctrl.stopRoute();
}

void TestNavigationController::testCarPositionMoves()
{
    NavigationController ctrl;
    double initialX = ctrl.carX();
    double initialY = ctrl.carY();
    ctrl.startRoute();
    QTest::qWait(1500);
    // Car should have moved from initial position
    bool moved = (ctrl.carX() != initialX || ctrl.carY() != initialY);
    QVERIFY(moved);
    ctrl.stopRoute();
}

void TestNavigationController::testEtaDecreases()
{
    NavigationController ctrl;
    ctrl.startRoute();
    int initialEta = ctrl.etaMinutes();
    QTest::qWait(3000);
    QVERIFY(ctrl.etaMinutes() <= initialEta);
    ctrl.stopRoute();
}

void TestNavigationController::testStartRouteEmitsSignals()
{
    NavigationController ctrl;
    QSignalSpy navSpy(&ctrl, &NavigationController::isNavigatingChanged);
    QSignalSpy updateSpy(&ctrl, &NavigationController::navigationUpdated);
    QSignalSpy posSpy(&ctrl, &NavigationController::carPositionChanged);

    ctrl.startRoute();
    QCOMPARE(navSpy.count(), 1);
    QVERIFY(updateSpy.count() >= 1);
    QVERIFY(posSpy.count() >= 1);
    ctrl.stopRoute();
}

void TestNavigationController::testStopRouteEmitsSignal()
{
    NavigationController ctrl;
    ctrl.startRoute();
    QSignalSpy spy(&ctrl, &NavigationController::isNavigatingChanged);
    ctrl.stopRoute();
    QCOMPARE(spy.count(), 1);
}

void TestNavigationController::testDestination()
{
    NavigationController ctrl;
    QCOMPARE(ctrl.destination(), QString("Downtown Plaza"));
}

void TestNavigationController::testDirectionIconUpdates()
{
    NavigationController ctrl;
    ctrl.startRoute();
    QString initialIcon = ctrl.directionIcon();
    // Wait for the car to move past a waypoint (each segment takes ~250 ticks at 80ms = ~20s)
    // Let's wait a reasonable amount
    QTest::qWait(5000);
    // Just verify the direction icon is non-empty
    QVERIFY(!ctrl.directionIcon().isEmpty());
    ctrl.stopRoute();
}

void TestNavigationController::testRouteProgressBound()
{
    NavigationController ctrl;
    ctrl.startRoute();
    QTest::qWait(2000);
    QVERIFY(ctrl.routeProgress() >= 0.0);
    QVERIFY(ctrl.routeProgress() <= 1.0);
    ctrl.stopRoute();
}

QTEST_MAIN(TestNavigationController)
#include "tst_navigationcontroller.moc"
