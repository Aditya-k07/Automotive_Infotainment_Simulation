/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<BluetoothController.h>)
#  include <BluetoothController.h>
#endif
#if __has_include(<MediaController.h>)
#  include <MediaController.h>
#endif
#if __has_include(<NavigationController.h>)
#  include <NavigationController.h>
#endif
#if __has_include(<VehicleController.h>)
#  include <VehicleController.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Automotive_Infotainment_Simulation()
{
    qmlRegisterModule("Automotive_Infotainment_Simulation", 254, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<BluetoothController>("Automotive_Infotainment_Simulation", 254);
    qmlRegisterTypesAndRevisions<MediaController>("Automotive_Infotainment_Simulation", 254);
    qmlRegisterTypesAndRevisions<NavigationController>("Automotive_Infotainment_Simulation", 254);
    qmlRegisterTypesAndRevisions<VehicleController>("Automotive_Infotainment_Simulation", 254);
    QT_WARNING_POP
    qmlRegisterModule("Automotive_Infotainment_Simulation", 254, 254);
}

static const QQmlModuleRegistration automotiveInfotainmentSimulationRegistration("Automotive_Infotainment_Simulation", qml_register_types_Automotive_Infotainment_Simulation);
