/****************************************************************************
** Meta object code from reading C++ file 'reckoui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "reckoui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reckoui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReckoUI_t
{
    QByteArrayData data[10];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len)                                                                                  \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(                                                           \
        len, qptrdiff(offsetof(qt_meta_stringdata_ReckoUI_t, stringdata0) + ofs - idx * sizeof(QByteArrayData)))
static const qt_meta_stringdata_ReckoUI_t qt_meta_stringdata_ReckoUI = {{
                                                                            QT_MOC_LITERAL(0, 0, 7),   // "ReckoUI"
                                                                            QT_MOC_LITERAL(1, 8, 7),   // "timesUp"
                                                                            QT_MOC_LITERAL(2, 16, 0),  // ""
                                                                            QT_MOC_LITERAL(3, 17, 8),  // "gameEnds"
                                                                            QT_MOC_LITERAL(4, 26, 9),  // "mGameEnds"
                                                                            QT_MOC_LITERAL(5, 36, 10), // "on_timesUp"
                                                                            QT_MOC_LITERAL(6, 47, 10), // "updateTime"
                                                                            QT_MOC_LITERAL(7, 58, 11), // "on_gameEnds"
                                                                            QT_MOC_LITERAL(8, 70, 11), // "onReadyRead"
                                                                            QT_MOC_LITERAL(9, 82, 11)  // "on_mTimesUp"

                                                                        },
                                                                        "ReckoUI\0timesUp\0\0gameEnds\0mGameEnds\0"
                                                                        "on_timesUp\0updateTime\0on_gameEnds\0"
                                                                        "onReadyRead\0on_mTimesUp"};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReckoUI[] = {

    // content:
    8,     // revision
    0,     // classname
    0, 0,  // classinfo
    8, 14, // methods
    0, 0,  // properties
    0, 0,  // enums/sets
    0, 0,  // constructors
    0,     // flags
    3,     // signalCount

    // signals: name, argc, parameters, tag, flags
    1, 0, 54, 2, 0x06 /* Public */, 3, 0, 55, 2, 0x06 /* Public */, 4, 0, 56, 2, 0x06 /* Public */,

    // slots: name, argc, parameters, tag, flags
    5, 0, 57, 2, 0x0a /* Public */, 6, 0, 58, 2, 0x0a /* Public */, 7, 0, 59, 2, 0x0a /* Public */, 8, 0, 60, 2,
    0x0a /* Public */, 9, 0, 61, 2, 0x0a /* Public */,

    // signals: parameters
    QMetaType::Void, QMetaType::Void, QMetaType::Void,

    // slots: parameters
    QMetaType::Void, QMetaType::Void, QMetaType::Void, QMetaType::Void, QMetaType::Void,

    0 // eod
};

void ReckoUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        auto *_t = static_cast<ReckoUI *>(_o);
        Q_UNUSED(_t)
        switch (_id)
        {
        case 0:
            _t->timesUp();
            break;
        case 1:
            _t->gameEnds();
            break;
        case 2:
            _t->mGameEnds();
            break;
        case 3:
            _t->on_timesUp();
            break;
        case 4:
            _t->updateTime();
            break;
        case 5:
            _t->on_gameEnds();
            break;
        case 6:
            _t->onReadyRead();
            break;
        case 7:
            _t->on_mTimesUp();
            break;
        default:;
        }
    }
    else if (_c == QMetaObject::IndexOfMethod)
    {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReckoUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReckoUI::timesUp))
            {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ReckoUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReckoUI::gameEnds))
            {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ReckoUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReckoUI::mGameEnds))
            {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ReckoUI::staticMetaObject = {
    {&QMainWindow::staticMetaObject, qt_meta_stringdata_ReckoUI.data, qt_meta_data_ReckoUI, qt_static_metacall, nullptr,
     nullptr}};

const QMetaObject *ReckoUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReckoUI::qt_metacast(const char *_clname)
{
    if (!_clname)
        return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReckoUI.stringdata0))
        return static_cast<void *>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ReckoUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    else if (_c == QMetaObject::RegisterMethodArgumentMetaType)
    {
        if (_id < 8)
            *reinterpret_cast<int *>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ReckoUI::timesUp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ReckoUI::gameEnds()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ReckoUI::mGameEnds()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE