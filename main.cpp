#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>
#include <QDebug>

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
        []() {
            qCritical() << "QML object creation FAILED!";
            QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    const QUrl url(QStringLiteral("qrc:/qt/qml/Automotive_Infotainment_Simulation/Main.qml"));
    qDebug() << "Loading QML from:" << url;

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        qCritical() << "No root objects! QML load failed.";
        return -1;
    }

    qDebug() << "QML loaded successfully. Root objects:" << engine.rootObjects().size();

    return app.exec();
}
