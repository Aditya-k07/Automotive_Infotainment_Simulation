/****************************************************************************
** Meta object code from reading C++ file 'NavigationController.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NavigationController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NavigationController.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20NavigationControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto NavigationController::qt_create_metaobjectdata<qt_meta_tag_ZN20NavigationControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "NavigationController",
        "QML.Element",
        "auto",
        "isNavigatingChanged",
        "",
        "navigationUpdated",
        "routeProgressChanged",
        "carPositionChanged",
        "startRoute",
        "stopRoute",
        "onTick",
        "isNavigating",
        "currentStreet",
        "nextManeuver",
        "directionIcon",
        "etaMinutes",
        "distanceToNext",
        "routeProgress",
        "destination",
        "carX",
        "carY"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'isNavigatingChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'navigationUpdated'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'routeProgressChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'carPositionChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startRoute'
        QtMocHelpers::SlotData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopRoute'
        QtMocHelpers::SlotData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onTick'
        QtMocHelpers::SlotData<void()>(10, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'isNavigating'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'currentStreet'
        QtMocHelpers::PropertyData<QString>(12, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'nextManeuver'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'directionIcon'
        QtMocHelpers::PropertyData<QString>(14, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'etaMinutes'
        QtMocHelpers::PropertyData<int>(15, QMetaType::Int, QMC::DefaultPropertyFlags, 1),
        // property 'distanceToNext'
        QtMocHelpers::PropertyData<double>(16, QMetaType::Double, QMC::DefaultPropertyFlags, 1),
        // property 'routeProgress'
        QtMocHelpers::PropertyData<double>(17, QMetaType::Double, QMC::DefaultPropertyFlags, 2),
        // property 'destination'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'carX'
        QtMocHelpers::PropertyData<double>(19, QMetaType::Double, QMC::DefaultPropertyFlags, 3),
        // property 'carY'
        QtMocHelpers::PropertyData<double>(20, QMetaType::Double, QMC::DefaultPropertyFlags, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<NavigationController, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject NavigationController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20NavigationControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20NavigationControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20NavigationControllerE_t>.metaTypes,
    nullptr
} };

void NavigationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NavigationController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->isNavigatingChanged(); break;
        case 1: _t->navigationUpdated(); break;
        case 2: _t->routeProgressChanged(); break;
        case 3: _t->carPositionChanged(); break;
        case 4: _t->startRoute(); break;
        case 5: _t->stopRoute(); break;
        case 6: _t->onTick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NavigationController::*)()>(_a, &NavigationController::isNavigatingChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NavigationController::*)()>(_a, &NavigationController::navigationUpdated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NavigationController::*)()>(_a, &NavigationController::routeProgressChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NavigationController::*)()>(_a, &NavigationController::carPositionChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isNavigating(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->currentStreet(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->nextManeuver(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->directionIcon(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->etaMinutes(); break;
        case 5: *reinterpret_cast<double*>(_v) = _t->distanceToNext(); break;
        case 6: *reinterpret_cast<double*>(_v) = _t->routeProgress(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->destination(); break;
        case 8: *reinterpret_cast<double*>(_v) = _t->carX(); break;
        case 9: *reinterpret_cast<double*>(_v) = _t->carY(); break;
        default: break;
        }
    }
}

const QMetaObject *NavigationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavigationController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20NavigationControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NavigationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void NavigationController::isNavigatingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NavigationController::navigationUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NavigationController::routeProgressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NavigationController::carPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
