/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../charts-project/Controller/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[23];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 3), // "add"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 16), // "changeSplitState"
QT_MOC_LITERAL(4, 33, 5), // "state"
QT_MOC_LITERAL(5, 39, 3), // "set"
QT_MOC_LITERAL(6, 43, 6), // "remove"
QT_MOC_LITERAL(7, 50, 7), // "newPlan"
QT_MOC_LITERAL(8, 58, 4), // "save"
QT_MOC_LITERAL(9, 63, 6), // "saveAs"
QT_MOC_LITERAL(10, 70, 13), // "showExercises"
QT_MOC_LITERAL(11, 84, 9), // "showChart"
QT_MOC_LITERAL(12, 94, 13), // "screenChanged"
QT_MOC_LITERAL(13, 108, 4), // "open"
QT_MOC_LITERAL(14, 113, 9), // "closePlan"
QT_MOC_LITERAL(15, 123, 20), // "firstResponseHandler"
QT_MOC_LITERAL(16, 144, 9), // "firstOpen"
QT_MOC_LITERAL(17, 154, 11), // "updateChart"
QT_MOC_LITERAL(18, 166, 12), // "chartWidget&"
QT_MOC_LITERAL(19, 179, 6), // "widget"
QT_MOC_LITERAL(20, 186, 11), // "std::string"
QT_MOC_LITERAL(21, 198, 5), // "chart"
QT_MOC_LITERAL(22, 204, 4) // "data"

    },
    "Controller\0add\0\0changeSplitState\0state\0"
    "set\0remove\0newPlan\0save\0saveAs\0"
    "showExercises\0showChart\0screenChanged\0"
    "open\0closePlan\0firstResponseHandler\0"
    "firstOpen\0updateChart\0chartWidget&\0"
    "widget\0std::string\0chart\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

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
       1,    0,   89,    2, 0x0a /* Public */,
       3,    1,   90,    2, 0x0a /* Public */,
       5,    0,   93,    2, 0x0a /* Public */,
       6,    0,   94,    2, 0x0a /* Public */,
       7,    0,   95,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x0a /* Public */,
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    3,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
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
    QMetaType::Void, 0x80000000 | 18, 0x80000000 | 20, 0x80000000 | 20,   19,   21,   22,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add(); break;
        case 1: _t->changeSplitState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->set(); break;
        case 3: _t->remove(); break;
        case 4: _t->newPlan(); break;
        case 5: _t->save(); break;
        case 6: _t->saveAs(); break;
        case 7: _t->showExercises(); break;
        case 8: _t->showChart(); break;
        case 9: _t->screenChanged(); break;
        case 10: _t->open(); break;
        case 11: _t->closePlan(); break;
        case 12: _t->firstResponseHandler(); break;
        case 13: _t->firstOpen(); break;
        case 14: _t->updateChart((*reinterpret_cast< chartWidget(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
