/****************************************************************************
** Meta object code from reading C++ file 'koznaui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../application/koznaui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'koznaui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KoZnaui_t {
    QByteArrayData data[17];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KoZnaui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KoZnaui_t qt_meta_stringdata_KoZnaui = {
    {
QT_MOC_LITERAL(0, 0, 7), // "KoZnaui"
QT_MOC_LITERAL(1, 8, 7), // "timesUp"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "gameEnds"
QT_MOC_LITERAL(4, 26, 10), // "on_timesUp"
QT_MOC_LITERAL(5, 37, 11), // "on_gameEnds"
QT_MOC_LITERAL(6, 49, 10), // "updateTime"
QT_MOC_LITERAL(7, 60, 11), // "onReadyRead"
QT_MOC_LITERAL(8, 72, 17), // "on_pushButtonAns1"
QT_MOC_LITERAL(9, 90, 17), // "on_pushButtonAns2"
QT_MOC_LITERAL(10, 108, 17), // "on_pushButtonAns3"
QT_MOC_LITERAL(11, 126, 17), // "on_pushButtonAns4"
QT_MOC_LITERAL(12, 144, 28), // "on_pushButtonAns1Multiplayer"
QT_MOC_LITERAL(13, 173, 28), // "on_pushButtonAns2Multiplayer"
QT_MOC_LITERAL(14, 202, 28), // "on_pushButtonAns3Multiplayer"
QT_MOC_LITERAL(15, 231, 28), // "on_pushButtonAns4Multiplayer"
QT_MOC_LITERAL(16, 260, 8) // "on_DALJE"

    },
    "KoZnaui\0timesUp\0\0gameEnds\0on_timesUp\0"
    "on_gameEnds\0updateTime\0onReadyRead\0"
    "on_pushButtonAns1\0on_pushButtonAns2\0"
    "on_pushButtonAns3\0on_pushButtonAns4\0"
    "on_pushButtonAns1Multiplayer\0"
    "on_pushButtonAns2Multiplayer\0"
    "on_pushButtonAns3Multiplayer\0"
    "on_pushButtonAns4Multiplayer\0on_DALJE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KoZnaui[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

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

       0        // eod
};

void KoZnaui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KoZnaui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timesUp(); break;
        case 1: _t->gameEnds(); break;
        case 2: _t->on_timesUp(); break;
        case 3: _t->on_gameEnds(); break;
        case 4: _t->updateTime(); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->on_pushButtonAns1(); break;
        case 7: _t->on_pushButtonAns2(); break;
        case 8: _t->on_pushButtonAns3(); break;
        case 9: _t->on_pushButtonAns4(); break;
        case 10: _t->on_pushButtonAns1Multiplayer(); break;
        case 11: _t->on_pushButtonAns2Multiplayer(); break;
        case 12: _t->on_pushButtonAns3Multiplayer(); break;
        case 13: _t->on_pushButtonAns4Multiplayer(); break;
        case 14: _t->on_DALJE(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KoZnaui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KoZnaui::timesUp)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KoZnaui::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KoZnaui::gameEnds)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject KoZnaui::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_KoZnaui.data,
    qt_meta_data_KoZnaui,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KoZnaui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KoZnaui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KoZnaui.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int KoZnaui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void KoZnaui::timesUp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void KoZnaui::gameEnds()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
