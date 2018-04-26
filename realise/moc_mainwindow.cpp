/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../matrix_calculator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "on_plus_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "on_minus_clicked"
QT_MOC_LITERAL(4, 45, 15), // "on_mult_clicked"
QT_MOC_LITERAL(5, 61, 18), // "on_transpA_clicked"
QT_MOC_LITERAL(6, 80, 18), // "on_transpB_clicked"
QT_MOC_LITERAL(7, 99, 15), // "on_powA_clicked"
QT_MOC_LITERAL(8, 115, 15), // "on_powB_clicked"
QT_MOC_LITERAL(9, 131, 15), // "on_detA_clicked"
QT_MOC_LITERAL(10, 147, 15), // "on_detB_clicked"
QT_MOC_LITERAL(11, 163, 19), // "on_reverseA_clicked"
QT_MOC_LITERAL(12, 183, 19), // "on_reverseB_clicked"
QT_MOC_LITERAL(13, 203, 29), // "matr1_characteristics_changed"
QT_MOC_LITERAL(14, 233, 29), // "matr2_characteristics_changed"
QT_MOC_LITERAL(15, 263, 15), // "on_save_clicked"
QT_MOC_LITERAL(16, 279, 15) // "on_open_clicked"

    },
    "MainWindow\0on_plus_clicked\0\0"
    "on_minus_clicked\0on_mult_clicked\0"
    "on_transpA_clicked\0on_transpB_clicked\0"
    "on_powA_clicked\0on_powB_clicked\0"
    "on_detA_clicked\0on_detB_clicked\0"
    "on_reverseA_clicked\0on_reverseB_clicked\0"
    "matr1_characteristics_changed\0"
    "matr2_characteristics_changed\0"
    "on_save_clicked\0on_open_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_plus_clicked(); break;
        case 1: _t->on_minus_clicked(); break;
        case 2: _t->on_mult_clicked(); break;
        case 3: _t->on_transpA_clicked(); break;
        case 4: _t->on_transpB_clicked(); break;
        case 5: _t->on_powA_clicked(); break;
        case 6: _t->on_powB_clicked(); break;
        case 7: _t->on_detA_clicked(); break;
        case 8: _t->on_detB_clicked(); break;
        case 9: _t->on_reverseA_clicked(); break;
        case 10: _t->on_reverseB_clicked(); break;
        case 11: _t->matr1_characteristics_changed(); break;
        case 12: _t->matr2_characteristics_changed(); break;
        case 13: _t->on_save_clicked(); break;
        case 14: _t->on_open_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
