/****************************************************************************
** Meta object code from reading C++ file 'musicwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "musicwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MusicWindow_t {
    QByteArrayData data[22];
    char stringdata0[381];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicWindow_t qt_meta_stringdata_MusicWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MusicWindow"
QT_MOC_LITERAL(1, 12, 28), // "on_commandLinkButton_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 17), // "on_volume_toggled"
QT_MOC_LITERAL(4, 60, 7), // "checked"
QT_MOC_LITERAL(5, 68, 19), // "on_addfiles_clicked"
QT_MOC_LITERAL(6, 88, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(7, 120, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 137, 4), // "item"
QT_MOC_LITERAL(9, 142, 10), // "music_data"
QT_MOC_LITERAL(10, 153, 15), // "on_play_toggled"
QT_MOC_LITERAL(11, 169, 15), // "on_prev_clicked"
QT_MOC_LITERAL(12, 185, 15), // "on_next_clicked"
QT_MOC_LITERAL(13, 201, 14), // "on_del_clicked"
QT_MOC_LITERAL(14, 216, 25), // "on_vol_change_sliderMoved"
QT_MOC_LITERAL(15, 242, 8), // "position"
QT_MOC_LITERAL(16, 251, 25), // "on_lrc_change_sliderMoved"
QT_MOC_LITERAL(17, 277, 9), // "onTimeout"
QT_MOC_LITERAL(18, 287, 29), // "on_lrc_change_actionTriggered"
QT_MOC_LITERAL(19, 317, 6), // "action"
QT_MOC_LITERAL(20, 324, 27), // "on_lrc_change_sliderPressed"
QT_MOC_LITERAL(21, 352, 28) // "on_lrc_change_sliderReleased"

    },
    "MusicWindow\0on_commandLinkButton_clicked\0"
    "\0on_volume_toggled\0checked\0"
    "on_addfiles_clicked\0on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0music_data\0"
    "on_play_toggled\0on_prev_clicked\0"
    "on_next_clicked\0on_del_clicked\0"
    "on_vol_change_sliderMoved\0position\0"
    "on_lrc_change_sliderMoved\0onTimeout\0"
    "on_lrc_change_actionTriggered\0action\0"
    "on_lrc_change_sliderPressed\0"
    "on_lrc_change_sliderReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    1,   90,    2, 0x08 /* Private */,
       5,    0,   93,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    1,  104,    2, 0x08 /* Private */,
      16,    1,  107,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    1,  111,    2, 0x08 /* Private */,
      20,    0,  114,    2, 0x08 /* Private */,
      21,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MusicWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicWindow *_t = static_cast<MusicWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_commandLinkButton_clicked(); break;
        case 1: _t->on_volume_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_addfiles_clicked(); break;
        case 3: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->music_data(); break;
        case 5: _t->on_play_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_prev_clicked(); break;
        case 7: _t->on_next_clicked(); break;
        case 8: _t->on_del_clicked(); break;
        case 9: _t->on_vol_change_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_lrc_change_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onTimeout(); break;
        case 12: _t->on_lrc_change_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_lrc_change_sliderPressed(); break;
        case 14: _t->on_lrc_change_sliderReleased(); break;
        default: ;
        }
    }
}

const QMetaObject MusicWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MusicWindow.data,
      qt_meta_data_MusicWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MusicWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MusicWindow.stringdata0))
        return static_cast<void*>(const_cast< MusicWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MusicWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
