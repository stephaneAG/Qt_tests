/****************************************************************************
** Meta object code from reading C++ file 'radio.h'
**
** Created: Fri Jan 17 14:29:00 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "radio.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Radio[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      16,    6,    6,    6, 0x0a,
      27,    6,    6,    6, 0x0a,
      38,    6,    6,    6, 0x0a,
      53,   51,    6,    6, 0x0a,
      72,   70,    6,    6, 0x0a,
      93,   91,    6,    6, 0x0a,
     117,  111,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Radio[] = {
    "Radio\0\0freqUp()\0freqDown()\0searchUp()\0"
    "searchDown()\0f\0freqChanged(int)\0s\0"
    "signalChanged(int)\0v\0updateVolume(int)\0"
    "error\0error(QRadioTuner::Error)\0"
};

void Radio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Radio *_t = static_cast<Radio *>(_o);
        switch (_id) {
        case 0: _t->freqUp(); break;
        case 1: _t->freqDown(); break;
        case 2: _t->searchUp(); break;
        case 3: _t->searchDown(); break;
        case 4: _t->freqChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->signalChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->error((*reinterpret_cast< QRadioTuner::Error(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Radio::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Radio::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Radio,
      qt_meta_data_Radio, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Radio::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Radio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Radio::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Radio))
        return static_cast<void*>(const_cast< Radio*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Radio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
