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
    QByteArrayData data[7];
    char stringdata0[79];
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
QT_MOC_LITERAL(3, 26, 12), // "setTrainings"
QT_MOC_LITERAL(4, 39, 15), // "removeTrainings"
QT_MOC_LITERAL(5, 55, 13), // "showExercises"
QT_MOC_LITERAL(6, 69, 9) // "showChart"

    },
    "chartViewer\0addTrainings\0\0setTrainings\0"
    "removeTrainings\0showExercises\0showChart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chartViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void chartViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chartViewer *_t = static_cast<chartViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addTrainings(); break;
        case 1: _t->setTrainings(); break;
        case 2: _t->removeTrainings(); break;
        case 3: _t->showExercises(); break;
        case 4: _t->showChart(); break;
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
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::setTrainings)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (chartViewer::*_t)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&chartViewer::removeTrainings)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void chartViewer::addTrainings()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void chartViewer::setTrainings()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void chartViewer::removeTrainings()const
{
    QMetaObject::activate(const_cast< chartViewer *>(this), &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
