/****************************************************************************
** Meta object code from reading C++ file 'punch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../S/Server/punch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'punch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Punch_t {
    QByteArrayData data[8];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Punch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Punch_t qt_meta_stringdata_Punch = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Punch"
QT_MOC_LITERAL(1, 6, 11), // "punchPasswd"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "punchslot"
QT_MOC_LITERAL(4, 29, 7), // "selslot"
QT_MOC_LITERAL(5, 37, 11), // "timerUpdate"
QT_MOC_LITERAL(6, 49, 10), // "timeinsert"
QT_MOC_LITERAL(7, 60, 10) // "insertUser"

    },
    "Punch\0punchPasswd\0\0punchslot\0selslot\0"
    "timerUpdate\0timeinsert\0insertUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Punch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Punch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Punch *_t = static_cast<Punch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->punchPasswd(); break;
        case 1: _t->punchslot(); break;
        case 2: _t->selslot(); break;
        case 3: _t->timerUpdate(); break;
        case 4: _t->timeinsert(); break;
        case 5: _t->insertUser(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Punch::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Punch.data,
      qt_meta_data_Punch,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Punch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Punch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Punch.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Punch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
