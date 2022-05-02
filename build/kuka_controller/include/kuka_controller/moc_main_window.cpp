/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/kuka_controller/include/kuka_controller/main_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[41];
    char stringdata0[718];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "rosShutdown"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(4, 49, 22), // "OnBtnClickedOpenDevice"
QT_MOC_LITERAL(5, 72, 23), // "OnBtnClickedCloseDevice"
QT_MOC_LITERAL(6, 96, 21), // "OnBtnClickedSaveImage"
QT_MOC_LITERAL(7, 118, 21), // "OnBtnClickedOpenRobot"
QT_MOC_LITERAL(8, 140, 22), // "OnBtnClickedCloseRobot"
QT_MOC_LITERAL(9, 163, 24), // "OnBtnClickedSendPosition"
QT_MOC_LITERAL(10, 188, 15), // "display_myImage"
QT_MOC_LITERAL(11, 204, 14), // "const cv::Mat*"
QT_MOC_LITERAL(12, 219, 8), // "imagePtr"
QT_MOC_LITERAL(13, 228, 21), // "OnServerNewConnection"
QT_MOC_LITERAL(14, 250, 21), // "OnServerDisConnection"
QT_MOC_LITERAL(15, 272, 21), // "OnSliderXvalueChanged"
QT_MOC_LITERAL(16, 294, 5), // "value"
QT_MOC_LITERAL(17, 300, 21), // "OnSliderYvalueChanged"
QT_MOC_LITERAL(18, 322, 21), // "OnSliderZvalueChanged"
QT_MOC_LITERAL(19, 344, 21), // "OnSliderAvalueChanged"
QT_MOC_LITERAL(20, 366, 21), // "OnSliderBvalueChanged"
QT_MOC_LITERAL(21, 388, 21), // "OnSliderCvalueChanged"
QT_MOC_LITERAL(22, 410, 22), // "OnLineXeditingFinished"
QT_MOC_LITERAL(23, 433, 22), // "OnLineYeditingFinished"
QT_MOC_LITERAL(24, 456, 22), // "OnLineZeditingFinished"
QT_MOC_LITERAL(25, 479, 22), // "OnLineAeditingFinished"
QT_MOC_LITERAL(26, 502, 22), // "OnLineBeditingFinished"
QT_MOC_LITERAL(27, 525, 22), // "OnLineCeditingFinished"
QT_MOC_LITERAL(28, 548, 28), // "OnBtnClickedSearchSerialPort"
QT_MOC_LITERAL(29, 577, 26), // "OnBtnClickedOpenSerialPort"
QT_MOC_LITERAL(30, 604, 30), // "OnBtnClickedStartGetSerialPort"
QT_MOC_LITERAL(31, 635, 29), // "OnBtnClickedStopGetSerialPort"
QT_MOC_LITERAL(32, 665, 15), // "OnUpdateDataFps"
QT_MOC_LITERAL(33, 681, 14), // "OnUIShowUpdate"
QT_MOC_LITERAL(34, 696, 9), // "ctrlRobot"
QT_MOC_LITERAL(35, 706, 1), // "x"
QT_MOC_LITERAL(36, 708, 1), // "y"
QT_MOC_LITERAL(37, 710, 1), // "z"
QT_MOC_LITERAL(38, 712, 1), // "a"
QT_MOC_LITERAL(39, 714, 1), // "b"
QT_MOC_LITERAL(40, 716, 1) // "c"

    },
    "MainWindow\0rosShutdown\0\0"
    "on_actionAbout_triggered\0"
    "OnBtnClickedOpenDevice\0OnBtnClickedCloseDevice\0"
    "OnBtnClickedSaveImage\0OnBtnClickedOpenRobot\0"
    "OnBtnClickedCloseRobot\0OnBtnClickedSendPosition\0"
    "display_myImage\0const cv::Mat*\0imagePtr\0"
    "OnServerNewConnection\0OnServerDisConnection\0"
    "OnSliderXvalueChanged\0value\0"
    "OnSliderYvalueChanged\0OnSliderZvalueChanged\0"
    "OnSliderAvalueChanged\0OnSliderBvalueChanged\0"
    "OnSliderCvalueChanged\0OnLineXeditingFinished\0"
    "OnLineYeditingFinished\0OnLineZeditingFinished\0"
    "OnLineAeditingFinished\0OnLineBeditingFinished\0"
    "OnLineCeditingFinished\0"
    "OnBtnClickedSearchSerialPort\0"
    "OnBtnClickedOpenSerialPort\0"
    "OnBtnClickedStartGetSerialPort\0"
    "OnBtnClickedStopGetSerialPort\0"
    "OnUpdateDataFps\0OnUIShowUpdate\0ctrlRobot\0"
    "x\0y\0z\0a\0b\0c"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  164,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  165,    2, 0x08 /* Private */,
       4,    0,  166,    2, 0x08 /* Private */,
       5,    0,  167,    2, 0x08 /* Private */,
       6,    0,  168,    2, 0x08 /* Private */,
       7,    0,  169,    2, 0x08 /* Private */,
       8,    0,  170,    2, 0x08 /* Private */,
       9,    0,  171,    2, 0x08 /* Private */,
      10,    1,  172,    2, 0x08 /* Private */,
      13,    0,  175,    2, 0x08 /* Private */,
      14,    0,  176,    2, 0x08 /* Private */,
      15,    1,  177,    2, 0x08 /* Private */,
      17,    1,  180,    2, 0x08 /* Private */,
      18,    1,  183,    2, 0x08 /* Private */,
      19,    1,  186,    2, 0x08 /* Private */,
      20,    1,  189,    2, 0x08 /* Private */,
      21,    1,  192,    2, 0x08 /* Private */,
      22,    0,  195,    2, 0x08 /* Private */,
      23,    0,  196,    2, 0x08 /* Private */,
      24,    0,  197,    2, 0x08 /* Private */,
      25,    0,  198,    2, 0x08 /* Private */,
      26,    0,  199,    2, 0x08 /* Private */,
      27,    0,  200,    2, 0x08 /* Private */,
      28,    0,  201,    2, 0x08 /* Private */,
      29,    0,  202,    2, 0x08 /* Private */,
      30,    0,  203,    2, 0x08 /* Private */,
      31,    0,  204,    2, 0x08 /* Private */,
      32,    0,  205,    2, 0x08 /* Private */,
      33,    0,  206,    2, 0x08 /* Private */,
      34,    6,  207,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   35,   36,   37,   38,   39,   40,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rosShutdown(); break;
        case 1: _t->on_actionAbout_triggered(); break;
        case 2: _t->OnBtnClickedOpenDevice(); break;
        case 3: _t->OnBtnClickedCloseDevice(); break;
        case 4: _t->OnBtnClickedSaveImage(); break;
        case 5: _t->OnBtnClickedOpenRobot(); break;
        case 6: _t->OnBtnClickedCloseRobot(); break;
        case 7: _t->OnBtnClickedSendPosition(); break;
        case 8: _t->display_myImage((*reinterpret_cast< const cv::Mat*(*)>(_a[1]))); break;
        case 9: _t->OnServerNewConnection(); break;
        case 10: _t->OnServerDisConnection(); break;
        case 11: _t->OnSliderXvalueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->OnSliderYvalueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->OnSliderZvalueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->OnSliderAvalueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->OnSliderBvalueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->OnSliderCvalueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->OnLineXeditingFinished(); break;
        case 18: _t->OnLineYeditingFinished(); break;
        case 19: _t->OnLineZeditingFinished(); break;
        case 20: _t->OnLineAeditingFinished(); break;
        case 21: _t->OnLineBeditingFinished(); break;
        case 22: _t->OnLineCeditingFinished(); break;
        case 23: _t->OnBtnClickedSearchSerialPort(); break;
        case 24: _t->OnBtnClickedOpenSerialPort(); break;
        case 25: _t->OnBtnClickedStartGetSerialPort(); break;
        case 26: _t->OnBtnClickedStopGetSerialPort(); break;
        case 27: _t->OnUpdateDataFps(); break;
        case 28: _t->OnUIShowUpdate(); break;
        case 29: _t->ctrlRobot((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::rosShutdown)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
