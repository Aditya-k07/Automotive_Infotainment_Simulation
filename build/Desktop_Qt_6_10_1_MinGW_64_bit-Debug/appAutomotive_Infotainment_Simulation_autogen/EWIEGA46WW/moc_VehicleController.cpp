/****************************************************************************
** Meta object code from reading C++ file 'VehicleController.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../VehicleController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VehicleController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN17VehicleControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto VehicleController::qt_create_metaobjectdata<qt_meta_tag_ZN17VehicleControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VehicleController",
        "QML.Element",
        "auto",
        "speedChanged",
        "",
        "rpmChanged",
        "fuelChanged",
        "engineTempChanged",
        "warningEngineChanged",
        "warningBatteryChanged",
        "warningOilChanged",
        "warningDoorChanged",
        "warningSeatbeltChanged",
        "isDrivingChanged",
        "gearChanged",
        "toggleDriving",
        "setTargetSpeed",
        "kmh",
        "toggleDoor",
        "toggleSeatbelt",
        "onTick",
        "speed",
        "rpm",
        "fuel",
        "engineTemp",
        "warningEngine",
        "warningBattery",
        "warningOil",
        "warningDoor",
        "warningSeatbelt",
        "isDriving",
        "gear"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'speedChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rpmChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'fuelChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'engineTempChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'warningEngineChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'warningBatteryChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'warningOilChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'warningDoorChanged'
        QtMocHelpers::SignalData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'warningSeatbeltChanged'
        QtMocHelpers::SignalData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isDrivingChanged'
        QtMocHelpers::SignalData<void()>(13, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'gearChanged'
        QtMocHelpers::SignalData<void()>(14, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleDriving'
        QtMocHelpers::SlotData<void()>(15, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setTargetSpeed'
        QtMocHelpers::SlotData<void(double)>(16, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 17 },
        }}),
        // Slot 'toggleDoor'
        QtMocHelpers::SlotData<void()>(18, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleSeatbelt'
        QtMocHelpers::SlotData<void()>(19, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onTick'
        QtMocHelpers::SlotData<void()>(20, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'speed'
        QtMocHelpers::PropertyData<double>(21, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'rpm'
        QtMocHelpers::PropertyData<double>(22, QMetaType::Double, QMC::DefaultPropertyFlags, 1),
        // property 'fuel'
        QtMocHelpers::PropertyData<double>(23, QMetaType::Double, QMC::DefaultPropertyFlags, 2),
        // property 'engineTemp'
        QtMocHelpers::PropertyData<double>(24, QMetaType::Double, QMC::DefaultPropertyFlags, 3),
        // property 'warningEngine'
        QtMocHelpers::PropertyData<bool>(25, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'warningBattery'
        QtMocHelpers::PropertyData<bool>(26, QMetaType::Bool, QMC::DefaultPropertyFlags, 5),
        // property 'warningOil'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags, 6),
        // property 'warningDoor'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags, 7),
        // property 'warningSeatbelt'
        QtMocHelpers::PropertyData<bool>(29, QMetaType::Bool, QMC::DefaultPropertyFlags, 8),
        // property 'isDriving'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::DefaultPropertyFlags, 9),
        // property 'gear'
        QtMocHelpers::PropertyData<int>(31, QMetaType::Int, QMC::DefaultPropertyFlags, 10),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<VehicleController, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject VehicleController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17VehicleControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17VehicleControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17VehicleControllerE_t>.metaTypes,
    nullptr
} };

void VehicleController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VehicleController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->rpmChanged(); break;
        case 2: _t->fuelChanged(); break;
        case 3: _t->engineTempChanged(); break;
        case 4: _t->warningEngineChanged(); break;
        case 5: _t->warningBatteryChanged(); break;
        case 6: _t->warningOilChanged(); break;
        case 7: _t->warningDoorChanged(); break;
        case 8: _t->warningSeatbeltChanged(); break;
        case 9: _t->isDrivingChanged(); break;
        case 10: _t->gearChanged(); break;
        case 11: _t->toggleDriving(); break;
        case 12: _t->setTargetSpeed((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 13: _t->toggleDoor(); break;
        case 14: _t->toggleSeatbelt(); break;
        case 15: _t->onTick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::speedChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::rpmChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::fuelChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::engineTempChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::warningEngineChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::warningBatteryChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::warningOilChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::warningDoorChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::warningSeatbeltChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::isDrivingChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (VehicleController::*)()>(_a, &VehicleController::gearChanged, 10))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<double*>(_v) = _t->speed(); break;
        case 1: *reinterpret_cast<double*>(_v) = _t->rpm(); break;
        case 2: *reinterpret_cast<double*>(_v) = _t->fuel(); break;
        case 3: *reinterpret_cast<double*>(_v) = _t->engineTemp(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->warningEngine(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->warningBattery(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->warningOil(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->warningDoor(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->warningSeatbelt(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->isDriving(); break;
        case 10: *reinterpret_cast<int*>(_v) = _t->gear(); break;
        default: break;
        }
    }
}

const QMetaObject *VehicleController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VehicleController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17VehicleControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VehicleController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void VehicleController::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VehicleController::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VehicleController::fuelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VehicleController::engineTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VehicleController::warningEngineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VehicleController::warningBatteryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VehicleController::warningOilChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VehicleController::warningDoorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void VehicleController::warningSeatbeltChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VehicleController::isDrivingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void VehicleController::gearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
