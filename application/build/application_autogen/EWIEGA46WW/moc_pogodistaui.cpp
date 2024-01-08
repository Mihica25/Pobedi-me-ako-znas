/****************************************************************************
** Meta object code from reading C++ file 'pogodistaui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pogodistaui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pogodistaui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PogodiStaUI_t
{
    QByteArrayData data[8];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len)                                                                                  \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(                                                           \
        len, qptrdiff(offsetof(qt_meta_stringdata_PogodiStaUI_t, stringdata0) + ofs - idx * sizeof(QByteArrayData)))
static const qt_meta_stringdata_PogodiStaUI_t qt_meta_stringdata_PogodiStaUI = {
    {
        QT_MOC_LITERAL(0, 0, 11),  // "PogodiStaUI"
        QT_MOC_LITERAL(1, 12, 8),  // "gameEnds"
        QT_MOC_LITERAL(2, 21, 0),  // ""
        QT_MOC_LITERAL(3, 22, 9),  // "mGameEnds"
        QT_MOC_LITERAL(4, 32, 11), // "updateTimer"
        QT_MOC_LITERAL(5, 44, 13), // "onGuessSubmit"
        QT_MOC_LITERAL(6, 58, 11), // "on_gameEnds"
        QT_MOC_LITERAL(7, 70, 11)  // "onReadyRead"

    },
    "PogodiStaUI\0gameEnds\0\0mGameEnds\0"
    "updateTimer\0onGuessSubmit\0on_gameEnds\0"
    "onReadyRead"};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PogodiStaUI[] = {

    // content:
    8,     // revision
    0,     // classname
    0, 0,  // classinfo
    6, 14, // methods
    0, 0,  // properties
    0, 0,  // enums/sets
    0, 0,  // constructors
    0,     // flags
    2,     // signalCount

    // signals: name, argc, parameters, tag, flags
    1, 0, 44, 2, 0x06 /* Public */, 3, 0, 45, 2, 0x06 /* Public */,

    // slots: name, argc, parameters, tag, flags
    4, 0, 46, 2, 0x08 /* Private */, 5, 0, 47, 2, 0x08 /* Private */, 6, 0, 48, 2, 0x08 /* Private */, 7, 0, 49, 2,
    0x08 /* Private */,

    // signals: parameters
    QMetaType::Void, QMetaType::Void,

    // slots: parameters
    QMetaType::Void, QMetaType::Void, QMetaType::Void, QMetaType::Void,

    0 // eod
};

void PogodiStaUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        auto *_t = static_cast<PogodiStaUI *>(_o);
        Q_UNUSED(_t)
        switch (_id)
        {
        case 0:
            _t->gameEnds();
            break;
        case 1:
            _t->mGameEnds();
            break;
        case 2:
            _t->updateTimer();
            break;
        case 3:
            _t->onGuessSubmit();
            break;
        case 4:
            _t->on_gameEnds();
            break;
        case 5:
            _t->onReadyRead();
            break;
        default:;
        }
    }
    else if (_c == QMetaObject::IndexOfMethod)
    {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PogodiStaUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PogodiStaUI::gameEnds))
            {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PogodiStaUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PogodiStaUI::mGameEnds))
            {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PogodiStaUI::staticMetaObject = {
    {&QWidget::staticMetaObject, qt_meta_stringdata_PogodiStaUI.data, qt_meta_data_PogodiStaUI, qt_static_metacall,
     nullptr, nullptr}};

const QMetaObject *PogodiStaUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PogodiStaUI::qt_metacast(const char *_clname)
{
    if (!_clname)
        return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PogodiStaUI.stringdata0))
        return static_cast<void *>(this);
    return QWidget::qt_metacast(_clname);
}

int PogodiStaUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    else if (_c == QMetaObject::RegisterMethodArgumentMetaType)
    {
        if (_id < 6)
            *reinterpret_cast<int *>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PogodiStaUI::gameEnds()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PogodiStaUI::mGameEnds()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
