/****************************************************************************
** Meta object code from reading C++ file 'memorija.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "memorija.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'memorija.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Memorija_t
{
    QByteArrayData data[6];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len)                                                                                  \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(                                                           \
        len, qptrdiff(offsetof(qt_meta_stringdata_Memorija_t, stringdata0) + ofs - idx * sizeof(QByteArrayData)))
static const qt_meta_stringdata_Memorija_t qt_meta_stringdata_Memorija = {
    {
        QT_MOC_LITERAL(0, 0, 8),   // "Memorija"
        QT_MOC_LITERAL(1, 9, 9),   // "mGameEnds"
        QT_MOC_LITERAL(2, 19, 0),  // ""
        QT_MOC_LITERAL(3, 20, 11), // "onReadyRead"
        QT_MOC_LITERAL(4, 32, 13), // "onCardClicked"
        QT_MOC_LITERAL(5, 46, 6)   // "cardId"

    },
    "Memorija\0mGameEnds\0\0onReadyRead\0"
    "onCardClicked\0cardId"};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Memorija[] = {

    // content:
    8,     // revision
    0,     // classname
    0, 0,  // classinfo
    3, 14, // methods
    0, 0,  // properties
    0, 0,  // enums/sets
    0, 0,  // constructors
    0,     // flags
    1,     // signalCount

    // signals: name, argc, parameters, tag, flags
    1, 0, 29, 2, 0x06 /* Public */,

    // slots: name, argc, parameters, tag, flags
    3, 0, 30, 2, 0x0a /* Public */, 4, 1, 31, 2, 0x08 /* Private */,

    // signals: parameters
    QMetaType::Void,

    // slots: parameters
    QMetaType::Void, QMetaType::Void, QMetaType::Int, 5,

    0 // eod
};

void Memorija::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        auto *_t = static_cast<Memorija *>(_o);
        Q_UNUSED(_t)
        switch (_id)
        {
        case 0:
            _t->mGameEnds();
            break;
        case 1:
            _t->onReadyRead();
            break;
        case 2:
            _t->onCardClicked((*reinterpret_cast<int(*)>(_a[1])));
            break;
        default:;
        }
    }
    else if (_c == QMetaObject::IndexOfMethod)
    {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Memorija::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Memorija::mGameEnds))
            {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Memorija::staticMetaObject = {
    {&QWidget::staticMetaObject, qt_meta_stringdata_Memorija.data, qt_meta_data_Memorija, qt_static_metacall, nullptr,
     nullptr}};

const QMetaObject *Memorija::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Memorija::qt_metacast(const char *_clname)
{
    if (!_clname)
        return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Memorija.stringdata0))
        return static_cast<void *>(this);
    return QWidget::qt_metacast(_clname);
}

int Memorija::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    else if (_c == QMetaObject::RegisterMethodArgumentMetaType)
    {
        if (_id < 3)
            *reinterpret_cast<int *>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Memorija::mGameEnds()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE