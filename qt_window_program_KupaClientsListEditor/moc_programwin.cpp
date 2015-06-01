/****************************************************************************
** Meta object code from reading C++ file 'programwin.h'
**
** Created: Sat Dec 7 20:01:45 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "programwin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'programwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Programwin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      59,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
     109,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     164,   11,   11,   11, 0x08,
     182,  176,   11,   11, 0x08,
     211,  176,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Programwin[] = {
    "Programwin\0\0openSlot()\0saveSlot()\0"
    "quitSlot()\0savekclSlot()\0resetkclSlot()\0"
    "backupkclSlot()\0newclientkclSlot()\0"
    "sshpairingkclSlot()\0kupanodesettingsSlot()\0"
    "aboutSlot()\0dummySlot()\0index\0"
    "cellClickedSlot(QModelIndex)\0"
    "cellActivatedSlot(QModelIndex)\0"
};

void Programwin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Programwin *_t = static_cast<Programwin *>(_o);
        switch (_id) {
        case 0: _t->openSlot(); break;
        case 1: _t->saveSlot(); break;
        case 2: _t->quitSlot(); break;
        case 3: _t->savekclSlot(); break;
        case 4: _t->resetkclSlot(); break;
        case 5: _t->backupkclSlot(); break;
        case 6: _t->newclientkclSlot(); break;
        case 7: _t->sshpairingkclSlot(); break;
        case 8: _t->kupanodesettingsSlot(); break;
        case 9: _t->aboutSlot(); break;
        case 10: _t->dummySlot(); break;
        case 11: _t->cellClickedSlot((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->cellActivatedSlot((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Programwin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Programwin::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Programwin,
      qt_meta_data_Programwin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Programwin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Programwin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Programwin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Programwin))
        return static_cast<void*>(const_cast< Programwin*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Programwin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
