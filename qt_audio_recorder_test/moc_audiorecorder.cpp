/****************************************************************************
** Meta object code from reading C++ file 'audiorecorder.h'
**
** Created: Fri Jan 17 14:45:48 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "audiorecorder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiorecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AudioRecorder[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      35,   14,   14,   14, 0x08,
      49,   14,   14,   14, 0x08,
      64,   14,   14,   14, 0x08,
     103,   99,   14,   14, 0x08,
     126,   14,   14,   14, 0x08,
     153,   14,  148,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AudioRecorder[] = {
    "AudioRecorder\0\0setOutputLocation()\0"
    "togglePause()\0toggleRecord()\0"
    "updateState(QMediaRecorder::State)\0"
    "pos\0updateProgress(qint64)\0"
    "displayErrorMessage()\0QUrl\0"
    "generateAudioFilePath()\0"
};

void AudioRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AudioRecorder *_t = static_cast<AudioRecorder *>(_o);
        switch (_id) {
        case 0: _t->setOutputLocation(); break;
        case 1: _t->togglePause(); break;
        case 2: _t->toggleRecord(); break;
        case 3: _t->updateState((*reinterpret_cast< QMediaRecorder::State(*)>(_a[1]))); break;
        case 4: _t->updateProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->displayErrorMessage(); break;
        case 6: { QUrl _r = _t->generateAudioFilePath();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AudioRecorder::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AudioRecorder::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AudioRecorder,
      qt_meta_data_AudioRecorder, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AudioRecorder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AudioRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AudioRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AudioRecorder))
        return static_cast<void*>(const_cast< AudioRecorder*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AudioRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
