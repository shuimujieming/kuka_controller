/****************************************************************************
** Meta object code from reading C++ file 'MyThreadTCP.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/kuka_controller/include/kuka_controller/MyThreadTCP.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyThreadTCP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyThreadTCP_t {
    QByteArrayData data[12];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyThreadTCP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyThreadTCP_t qt_meta_stringdata_MyThreadTCP = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyThreadTCP"
QT_MOC_LITERAL(1, 12, 4), // "mess"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "sendSerialData"
QT_MOC_LITERAL(4, 33, 7), // "double*"
QT_MOC_LITERAL(5, 41, 2), // "Fx"
QT_MOC_LITERAL(6, 44, 2), // "Fy"
QT_MOC_LITERAL(7, 47, 2), // "Fz"
QT_MOC_LITERAL(8, 50, 2), // "Mx"
QT_MOC_LITERAL(9, 53, 2), // "My"
QT_MOC_LITERAL(10, 56, 2), // "Mz"
QT_MOC_LITERAL(11, 59, 16) // "OnServerReadData"

    },
    "MyThreadTCP\0mess\0\0sendSerialData\0"
    "double*\0Fx\0Fy\0Fz\0Mx\0My\0Mz\0OnServerReadData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyThreadTCP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    6,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    5,    6,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MyThreadTCP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyThreadTCP *_t = static_cast<MyThreadTCP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mess(); break;
        case 1: _t->sendSerialData((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])),(*reinterpret_cast< double*(*)>(_a[5])),(*reinterpret_cast< double*(*)>(_a[6]))); break;
        case 2: _t->OnServerReadData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MyThreadTCP::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreadTCP::mess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyThreadTCP::*_t)(double * , double * , double * , double * , double * , double * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreadTCP::sendSerialData)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MyThreadTCP::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyThreadTCP.data,
      qt_meta_data_MyThreadTCP,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyThreadTCP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyThreadTCP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyThreadTCP.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MyThreadTCP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyThreadTCP::mess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyThreadTCP::sendSerialData(double * _t1, double * _t2, double * _t3, double * _t4, double * _t5, double * _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
