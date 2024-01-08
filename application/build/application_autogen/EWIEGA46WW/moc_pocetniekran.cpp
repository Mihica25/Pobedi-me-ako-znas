/****************************************************************************
** Meta object code from reading C++ file 'pocetniekran.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pocetniekran.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pocetniekran.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PocetniEkran_t
{
    QByteArrayData data[13];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len)                                                                                  \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(                                                           \
        len, qptrdiff(offsetof(qt_meta_stringdata_PocetniEkran_t, stringdata0) + ofs - idx * sizeof(QByteArrayData)))
static const qt_meta_stringdata_PocetniEkran_t qt_meta_stringdata_PocetniEkran = {
    {
        QT_MOC_LITERAL(0, 0, 12),    // "PocetniEkran"
        QT_MOC_LITERAL(1, 13, 26),   // "on_startGameButton_clicked"
        QT_MOC_LITERAL(2, 40, 0),    // ""
        QT_MOC_LITERAL(3, 41, 34),   // "on_najboljiRezultatiButton_cl..."
        QT_MOC_LITERAL(4, 76, 12),   // "on_reckoEnds"
        QT_MOC_LITERAL(5, 89, 14),   // "on_mojbrojEnds"
        QT_MOC_LITERAL(6, 104, 12),  // "on_koZnaEnds"
        QT_MOC_LITERAL(7, 117, 16),  // "on_podrundaEnded"
        QT_MOC_LITERAL(8, 134, 16),  // "on_pogodiStaEnds"
        QT_MOC_LITERAL(9, 151, 15),  // "on_memorijaEnds"
        QT_MOC_LITERAL(10, 167, 11), // "onReadyRead"
        QT_MOC_LITERAL(11, 179, 22), // "onReadyReadBestResults"
        QT_MOC_LITERAL(12, 202, 7)   // "on_info"

    },
    "PocetniEkran\0on_startGameButton_clicked\0"
    "\0on_najboljiRezultatiButton_clicked\0"
    "on_reckoEnds\0on_mojbrojEnds\0on_koZnaEnds\0"
    "on_podrundaEnded\0on_pogodiStaEnds\0"
    "on_memorijaEnds\0onReadyRead\0"
    "onReadyReadBestResults\0on_info"};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PocetniEkran[] = {

    // content:
    8,      // revision
    0,      // classname
    0, 0,   // classinfo
    11, 14, // methods
    0, 0,   // properties
    0, 0,   // enums/sets
    0, 0,   // constructors
    0,      // flags
    0,      // signalCount

    // slots: name, argc, parameters, tag, flags
    1, 0, 69, 2, 0x0a /* Public */, 3, 0, 70, 2, 0x0a /* Public */, 4, 0, 71, 2, 0x0a /* Public */, 5, 0, 72, 2,
    0x0a /* Public */, 6, 0, 73, 2, 0x0a /* Public */, 7, 0, 74, 2, 0x0a /* Public */, 8, 0, 75, 2, 0x0a /* Public */,
    9, 0, 76, 2, 0x0a /* Public */, 10, 0, 77, 2, 0x0a /* Public */, 11, 0, 78, 2, 0x0a /* Public */, 12, 0, 79, 2,
    0x0a /* Public */,

    // slots: parameters
    QMetaType::Void, QMetaType::Void, QMetaType::Void, QMetaType::Void, QMetaType::Void, QMetaType::Void,
    QMetaType::Void, QMetaType::Void, QMetaType::Void, QMetaType::Void, QMetaType::Void,

    0 // eod
};

void PocetniEkran::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        auto *_t = static_cast<PocetniEkran *>(_o);
        Q_UNUSED(_t)
        switch (_id)
        {
        case 0:
            _t->on_startGameButton_clicked();
            break;
        case 1:
            _t->on_najboljiRezultatiButton_clicked();
            break;
        case 2:
            _t->on_reckoEnds();
            break;
        case 3:
            _t->on_mojbrojEnds();
            break;
        case 4:
            _t->on_koZnaEnds();
            break;
        case 5:
            _t->on_podrundaEnded();
            break;
        case 6:
            _t->on_pogodiStaEnds();
            break;
        case 7:
            _t->on_memorijaEnds();
            break;
        case 8:
            _t->onReadyRead();
            break;
        case 9:
            _t->onReadyReadBestResults();
            break;
        case 10:
            _t->on_info();
            break;
        default:;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PocetniEkran::staticMetaObject = {
    {&QMainWindow::staticMetaObject, qt_meta_stringdata_PocetniEkran.data, qt_meta_data_PocetniEkran,
     qt_static_metacall, nullptr, nullptr}};

const QMetaObject *PocetniEkran::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PocetniEkran::qt_metacast(const char *_clname)
{
    if (!_clname)
        return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PocetniEkran.stringdata0))
        return static_cast<void *>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PocetniEkran::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod)
    {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    else if (_c == QMetaObject::RegisterMethodArgumentMetaType)
    {
        if (_id < 11)
            *reinterpret_cast<int *>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
