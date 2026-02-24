/****************************************************************************
** Meta object code from reading C++ file 'MediaController.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../MediaController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MediaController.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15MediaControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto MediaController::qt_create_metaobjectdata<qt_meta_tag_ZN15MediaControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MediaController",
        "QML.Element",
        "auto",
        "trackChanged",
        "",
        "isPlayingChanged",
        "volumeChanged",
        "trackProgressChanged",
        "playPause",
        "nextTrack",
        "prevTrack",
        "setVolume",
        "v",
        "seekTo",
        "progress",
        "onTick",
        "trackTitle",
        "artistName",
        "albumName",
        "trackIndex",
        "totalTracks",
        "isPlaying",
        "volume",
        "trackProgress",
        "trackDuration",
        "elapsedSec"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'trackChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isPlayingChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'volumeChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trackProgressChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'playPause'
        QtMocHelpers::SlotData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'nextTrack'
        QtMocHelpers::SlotData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'prevTrack'
        QtMocHelpers::SlotData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setVolume'
        QtMocHelpers::SlotData<void(int)>(11, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 12 },
        }}),
        // Slot 'seekTo'
        QtMocHelpers::SlotData<void(double)>(13, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 14 },
        }}),
        // Slot 'onTick'
        QtMocHelpers::SlotData<void()>(15, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'trackTitle'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'artistName'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'albumName'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'trackIndex'
        QtMocHelpers::PropertyData<int>(19, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'totalTracks'
        QtMocHelpers::PropertyData<int>(20, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'isPlaying'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
        // property 'volume'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags, 2),
        // property 'trackProgress'
        QtMocHelpers::PropertyData<double>(23, QMetaType::Double, QMC::DefaultPropertyFlags, 3),
        // property 'trackDuration'
        QtMocHelpers::PropertyData<int>(24, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'elapsedSec'
        QtMocHelpers::PropertyData<int>(25, QMetaType::Int, QMC::DefaultPropertyFlags, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<MediaController, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject MediaController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MediaControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MediaControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15MediaControllerE_t>.metaTypes,
    nullptr
} };

void MediaController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MediaController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->trackChanged(); break;
        case 1: _t->isPlayingChanged(); break;
        case 2: _t->volumeChanged(); break;
        case 3: _t->trackProgressChanged(); break;
        case 4: _t->playPause(); break;
        case 5: _t->nextTrack(); break;
        case 6: _t->prevTrack(); break;
        case 7: _t->setVolume((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->seekTo((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 9: _t->onTick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MediaController::*)()>(_a, &MediaController::trackChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MediaController::*)()>(_a, &MediaController::isPlayingChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MediaController::*)()>(_a, &MediaController::volumeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MediaController::*)()>(_a, &MediaController::trackProgressChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->trackTitle(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->artistName(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->albumName(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->trackIndex(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->totalTracks(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isPlaying(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->volume(); break;
        case 7: *reinterpret_cast<double*>(_v) = _t->trackProgress(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->trackDuration(); break;
        case 9: *reinterpret_cast<int*>(_v) = _t->elapsedSec(); break;
        default: break;
        }
    }
}

const QMetaObject *MediaController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15MediaControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
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
void MediaController::trackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MediaController::isPlayingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MediaController::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MediaController::trackProgressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
