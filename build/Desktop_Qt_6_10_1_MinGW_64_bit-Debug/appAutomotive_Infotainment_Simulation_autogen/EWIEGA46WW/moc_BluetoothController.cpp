/****************************************************************************
** Meta object code from reading C++ file 'BluetoothController.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../BluetoothController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BluetoothController.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19BluetoothControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto BluetoothController::qt_create_metaobjectdata<qt_meta_tag_ZN19BluetoothControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BluetoothController",
        "QML.Element",
        "auto",
        "connectionChanged",
        "",
        "signalStrengthChanged",
        "callStateChanged",
        "connectDevice",
        "name",
        "disconnectDevice",
        "answerCall",
        "endCall",
        "rejectCall",
        "onSignalTick",
        "triggerIncomingCall",
        "onCallTick",
        "isConnected",
        "deviceName",
        "signalStrength",
        "isInCall",
        "callerName",
        "callDuration",
        "hasIncoming",
        "availableDevices"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'connectionChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'signalStrengthChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'callStateChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'connectDevice'
        QtMocHelpers::SlotData<void(const QString &)>(7, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Slot 'disconnectDevice'
        QtMocHelpers::SlotData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'answerCall'
        QtMocHelpers::SlotData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'endCall'
        QtMocHelpers::SlotData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'rejectCall'
        QtMocHelpers::SlotData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onSignalTick'
        QtMocHelpers::SlotData<void()>(13, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'triggerIncomingCall'
        QtMocHelpers::SlotData<void()>(14, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCallTick'
        QtMocHelpers::SlotData<void()>(15, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'isConnected'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'deviceName'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'signalStrength'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags, 1),
        // property 'isInCall'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
        // property 'callerName'
        QtMocHelpers::PropertyData<QString>(20, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'callDuration'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'hasIncoming'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
        // property 'availableDevices'
        QtMocHelpers::PropertyData<QStringList>(23, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<BluetoothController, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject BluetoothController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19BluetoothControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19BluetoothControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19BluetoothControllerE_t>.metaTypes,
    nullptr
} };

void BluetoothController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BluetoothController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->connectionChanged(); break;
        case 1: _t->signalStrengthChanged(); break;
        case 2: _t->callStateChanged(); break;
        case 3: _t->connectDevice((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->disconnectDevice(); break;
        case 5: _t->answerCall(); break;
        case 6: _t->endCall(); break;
        case 7: _t->rejectCall(); break;
        case 8: _t->onSignalTick(); break;
        case 9: _t->triggerIncomingCall(); break;
        case 10: _t->onCallTick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BluetoothController::*)()>(_a, &BluetoothController::connectionChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothController::*)()>(_a, &BluetoothController::signalStrengthChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothController::*)()>(_a, &BluetoothController::callStateChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isConnected(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->deviceName(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->signalStrength(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isInCall(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->callerName(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->callDuration(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->hasIncoming(); break;
        case 7: *reinterpret_cast<QStringList*>(_v) = _t->availableDevices(); break;
        default: break;
        }
    }
}

const QMetaObject *BluetoothController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19BluetoothControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BluetoothController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BluetoothController::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BluetoothController::signalStrengthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BluetoothController::callStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
