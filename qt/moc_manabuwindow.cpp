/****************************************************************************
** Meta object code from reading C++ file 'manabuwindow.h'
**
** Created: Wed Sep 15 16:49:41 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/qt/manabuwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manabuwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManabuWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      30,   13,   13,   13, 0x0a,
      37,   13,   13,   13, 0x0a,
      48,   13,   13,   13, 0x0a,
      65,   59,   13,   13, 0x0a,
      87,   13,   13,   13, 0x0a,
     112,   13,   13,   13, 0x0a,
     128,   13,   13,   13, 0x0a,
     138,   13,   13,   13, 0x0a,
     149,   13,   13,   13, 0x0a,
     160,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ManabuWindow[] = {
    "ManabuWindow\0\0SubmitClicked()\0Quit()\0"
    "OpenDeck()\0SaveDeck()\0index\0"
    "PileIndexChanged(int)\0DeckClicked(QModelIndex)\0"
    "ToggleDisplay()\0NewDeck()\0EditDeck()\0"
    "EditCard()\0AddCard()\0"
};

const QMetaObject ManabuWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ManabuWindow,
      qt_meta_data_ManabuWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManabuWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManabuWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManabuWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManabuWindow))
        return static_cast<void*>(const_cast< ManabuWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ManabuWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SubmitClicked(); break;
        case 1: Quit(); break;
        case 2: OpenDeck(); break;
        case 3: SaveDeck(); break;
        case 4: PileIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: DeckClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: ToggleDisplay(); break;
        case 7: NewDeck(); break;
        case 8: EditDeck(); break;
        case 9: EditCard(); break;
        case 10: AddCard(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
