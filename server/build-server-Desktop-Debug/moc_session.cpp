/****************************************************************************
** Meta object code from reading C++ file 'session.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../server/session.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'session.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Session_t {
    QByteArrayData data[14];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Session_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Session_t qt_meta_stringdata_Session = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Session"
QT_MOC_LITERAL(1, 8, 21), // "player1ReadyReadRecko"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "player2ReadyReadRecko"
QT_MOC_LITERAL(4, 53, 23), // "player1ReadyReadMojBroj"
QT_MOC_LITERAL(5, 77, 23), // "player2ReadyReadMojBroj"
QT_MOC_LITERAL(6, 101, 21), // "player1ReadyReadKoZna"
QT_MOC_LITERAL(7, 123, 21), // "player2ReadyReadKoZna"
QT_MOC_LITERAL(8, 145, 24), // "player1ReadyReadPodrunda"
QT_MOC_LITERAL(9, 170, 24), // "player2ReadyReadPodrunda"
QT_MOC_LITERAL(10, 195, 25), // "player1ReadyReadPogodiSta"
QT_MOC_LITERAL(11, 221, 25), // "player2ReadyReadPogodiSta"
QT_MOC_LITERAL(12, 247, 24), // "player1ReadyReadMemorija"
QT_MOC_LITERAL(13, 272, 24) // "player2ReadyReadMemorija"

    },
    "Session\0player1ReadyReadRecko\0\0"
    "player2ReadyReadRecko\0player1ReadyReadMojBroj\0"
    "player2ReadyReadMojBroj\0player1ReadyReadKoZna\0"
    "player2ReadyReadKoZna\0player1ReadyReadPodrunda\0"
    "player2ReadyReadPodrunda\0"
    "player1ReadyReadPogodiSta\0"
    "player2ReadyReadPogodiSta\0"
    "player1ReadyReadMemorija\0"
    "player2ReadyReadMemorija"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Session[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

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

       0        // eod
};

void Session::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Session *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->player1ReadyReadRecko(); break;
        case 1: _t->player2ReadyReadRecko(); break;
        case 2: _t->player1ReadyReadMojBroj(); break;
        case 3: _t->player2ReadyReadMojBroj(); break;
        case 4: _t->player1ReadyReadKoZna(); break;
        case 5: _t->player2ReadyReadKoZna(); break;
        case 6: _t->player1ReadyReadPodrunda(); break;
        case 7: _t->player2ReadyReadPodrunda(); break;
        case 8: _t->player1ReadyReadPogodiSta(); break;
        case 9: _t->player2ReadyReadPogodiSta(); break;
        case 10: _t->player1ReadyReadMemorija(); break;
        case 11: _t->player2ReadyReadMemorija(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Session::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Session.data,
    qt_meta_data_Session,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Session::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Session::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Session.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Session::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE