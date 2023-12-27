/****************************************************************************
** Meta object code from reading C++ file 'mojbroj.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../application/mojbroj.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mojbroj.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mojbroj_t {
    QByteArrayData data[12];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mojbroj_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mojbroj_t qt_meta_stringdata_Mojbroj = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Mojbroj"
QT_MOC_LITERAL(1, 8, 7), // "timesUp"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "gameEnd"
QT_MOC_LITERAL(4, 25, 16), // "buttonPressedNum"
QT_MOC_LITERAL(5, 42, 15), // "buttonPressedOp"
QT_MOC_LITERAL(6, 58, 19), // "buttonPressedSubmit"
QT_MOC_LITERAL(7, 78, 22), // "buttonPressedNextRound"
QT_MOC_LITERAL(8, 101, 3), // "del"
QT_MOC_LITERAL(9, 105, 10), // "on_timesUp"
QT_MOC_LITERAL(10, 116, 10), // "on_gameEnd"
QT_MOC_LITERAL(11, 127, 10) // "updateTime"

    },
    "Mojbroj\0timesUp\0\0gameEnd\0buttonPressedNum\0"
    "buttonPressedOp\0buttonPressedSubmit\0"
    "buttonPressedNextRound\0del\0on_timesUp\0"
    "on_gameEnd\0updateTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mojbroj[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

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

       0        // eod
};

void Mojbroj::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mojbroj *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timesUp(); break;
        case 1: _t->gameEnd(); break;
        case 2: _t->buttonPressedNum(); break;
        case 3: _t->buttonPressedOp(); break;
        case 4: _t->buttonPressedSubmit(); break;
        case 5: _t->buttonPressedNextRound(); break;
        case 6: _t->del(); break;
        case 7: _t->on_timesUp(); break;
        case 8: _t->on_gameEnd(); break;
        case 9: _t->updateTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mojbroj::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mojbroj::timesUp)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Mojbroj::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mojbroj::gameEnd)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Mojbroj::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Mojbroj.data,
    qt_meta_data_Mojbroj,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mojbroj::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mojbroj::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mojbroj.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Mojbroj::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Mojbroj::timesUp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Mojbroj::gameEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
