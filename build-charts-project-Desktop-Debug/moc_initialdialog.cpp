/****************************************************************************
** Meta object code from reading C++ file 'initialdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../charts-project/View/initialdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'initialdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_initialDialog_t {
    QByteArrayData data[6];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_initialDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_initialDialog_t qt_meta_stringdata_initialDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "initialDialog"
QT_MOC_LITERAL(1, 14, 8), // "openFile"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "showView"
QT_MOC_LITERAL(4, 33, 8), // "closeAll"
QT_MOC_LITERAL(5, 42, 11) // "closeWidget"

    },
    "initialDialog\0openFile\0\0showView\0"
    "closeAll\0closeWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_initialDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void initialDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<initialDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openFile(); break;
        case 1: _t->showView(); break;
        case 2: _t->closeAll(); break;
        case 3: _t->closeWidget(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (initialDialog::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&initialDialog::openFile)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (initialDialog::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&initialDialog::showView)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (initialDialog::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&initialDialog::closeAll)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject initialDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_initialDialog.data,
    qt_meta_data_initialDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *initialDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *initialDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_initialDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int initialDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void initialDialog::openFile()const
{
    QMetaObject::activate(const_cast< initialDialog *>(this), &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void initialDialog::showView()const
{
    QMetaObject::activate(const_cast< initialDialog *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void initialDialog::closeAll()const
{
    QMetaObject::activate(const_cast< initialDialog *>(this), &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
