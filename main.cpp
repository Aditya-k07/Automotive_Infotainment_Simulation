#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "VehicleController.h"
#include "MediaController.h"
#include "NavigationController.h"
#include "BluetoothController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Automotive Infotainment Simulator");
    app.setOrganizationName("QtDev");

    VehicleController   vehicleCtrl;
    MediaController     mediaCtrl;
    NavigationController navCtrl;
    BluetoothController  btCtrl;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("vehicleCtrl", &vehicleCtrl);
    engine.rootContext()->setContextProperty("mediaCtrl",   &mediaCtrl);
    engine.rootContext()->setContextProperty("navCtrl",     &navCtrl);
    engine.rootContext()->setContextProperty("btCtrl",      &btCtrl);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("Automotive_Infotainment_Simulation", "Main");

    return app.exec();
}
