/****************************************************************************
** Meta object code from reading C++ file 'dialogwindow.h'
**
** Created: Fri Dec 6 13:07:16 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x0a,
      29,   13,   13,   13, 0x08,
      44,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogWindow[] = {
    "DialogWindow\0\0idx\0mSlot(int)\0"
    "acceptedSlot()\0rejectedSlot()\0"
};

void DialogWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DialogWindow *_t = static_cast<DialogWindow *>(_o);
        switch (_id) {
        case 0: _t->mSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->acceptedSlot(); break;
        case 2: _t->rejectedSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DialogWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DialogWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogWindow,
      qt_meta_data_DialogWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogWindow))
        return static_cast<void*>(const_cast< DialogWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
