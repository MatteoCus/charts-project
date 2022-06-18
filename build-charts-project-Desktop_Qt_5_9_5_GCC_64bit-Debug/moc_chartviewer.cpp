/****************************************************************************
** Meta object code from reading C++ file 'chartviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../charts-project/View/chartviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chartviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_chartViewer_t {
    QByteArrayData data[17];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_chartViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_chartViewer_t qt_meta_stringdata_chartViewer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "chartViewer"
QT_MOC_LITERAL(1, 12, 12), // "addTrainings"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "changeSplitState"
QT_MOC_LITERAL(4, 43, 12), // "setTrainings"
QT_MOC_LITERAL(5, 56, 15), // "removeTrainings"
QT_MOC_LITERAL(6, 72, 4), // "save"
QT_MOC_LITERAL(7, 77, 6), // "saveAs"
QT_MOC_LITERAL(8, 84, 13), // "showExercises"
QT_MOC_LITERAL(9, 98, 9), // "showChart"
QT_MOC_LITERAL(10, 108, 13), // "screenChanged"
QT_MOC_LITERAL(11, 122, 7), // "newPlan"
QT_MOC_LITERAL(12, 130, 4), // "open"
QT_MOC_LITERAL(13, 135, 8), // "closeAll"
QT_MOC_LITERAL(14, 144, 11), // "updateChart"
QT_MOC_LITERAL(15, 156, 12), // "chartWidget&"
QT_MOC_LITERAL(16, 169, 11) // "std::string"

    },
    "chartViewer\0addTrainings\0\0changeSplitState\0"
    "setTrainings\0removeTrainings\0save\0"
    "saveAs\0showExercises\0showChart\0"
    "screenChanged\0newPlan\0open\0closeAll\0"
    "updateChart\0chartWidget&\0std::string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chartViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    1,   80,    2, 0x06 /* Public */,
       4,    0,   83,    2, 0x06 /* Public */,
       5,    0,   84,    2, 0x06 /* Public */,
       6,    0,   85,    2, 0x06 /* Public */,
       7,    0,   86,    2, 0x06 /* Public */,
       8,    0,   87,    2, 0x06 /* Public */,
       9,    0,   88,    2, 0x06 /* Public */,
      10,    0,   89,    2, 0x06 /* Public */,
      11,    0,   90,    2, 0x06 /* Public */,
      12,    0,   91,    2, 0x06 /* Public */,
      13,    0,   92,    2, 0x06 /* Public */,
      14,    3,   93,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
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
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 16, 0x80000000 | 16,    2,    2,    2,

       0        // eod
};

void chartViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chartViewer *_t = static_cast<chartViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addTrainings(); break;
        case 1: _t->changeSplitState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setTrainings(); break;
        case 3: _t->removeTrainings(); break;
        case 4: _t->save(); break;
        case 5: _t->saveAs(); break;
        case 6: _t->showExercises(); break;
        case 7: _t->showChart(); break;
        case 8: _t->screenChanged(); break;
        case 9: _t->newPlan(); break;
        case 10: _t->open(); break;
        case 11: _t->closeAll(); break;
        case 12: _t->updateChart((*reinterpret_cast< chartWidget(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::addTrainings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)(bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::changeSplitState)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::setTrainings)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::removeTrainings)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::save)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::saveAs)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::showExercises)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::showChart)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::screenChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::newPlan)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::open)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::closeAll)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)(chartWidget & , const std::string & , const std::string & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::updateChart)) {
                *result = 12;
                return;
            }
        }
    }
}

const QMetaObject chartViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_chartViewer.data,
      qt_meta_data_chartViewer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *chartViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chartViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_chartViewer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int chartViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void chartViewer::addTrainings()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void chartViewer::changeSplitState(bool _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void chartViewer::setTrainings()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void chartViewer::removeTrainings()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void chartViewer::save()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void chartViewer::saveAs()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void chartViewer::showExercises()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void chartViewer::showChart()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void chartViewer::screenChanged()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void chartViewer::newPlan()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void chartViewer::open()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void chartViewer::closeAll()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void chartViewer::updateChart(chartWidget & _t1, const std::string & _t2, const std::string & _t3)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 12, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
