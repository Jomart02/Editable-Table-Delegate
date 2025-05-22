/****************************************************************************
** Meta object code from reading C++ file 'TableDelegate.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/TableDelegate/TableDelegate.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TableDelegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTableDelegateENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTableDelegateENDCLASS = QtMocHelpers::stringData(
    "TableDelegate",
    "buttonClicked",
    "",
    "QModelIndex",
    "index",
    "deleteButtonCicked",
    "ColumnType",
    "DoubleSpinBox",
    "SpinBox",
    "LineEdit",
    "ComboBox",
    "Checkbox",
    "LatEdit",
    "LongEdit",
    "TimeEdit",
    "DateEdit",
    "DateTimeEdit",
    "AltitEdit",
    "RadioButton",
    "Button",
    "DeleteButton",
    "DragButton"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTableDelegateENDCLASS_t {
    uint offsetsAndSizes[44];
    char stringdata0[14];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[19];
    char stringdata6[11];
    char stringdata7[14];
    char stringdata8[8];
    char stringdata9[9];
    char stringdata10[9];
    char stringdata11[9];
    char stringdata12[8];
    char stringdata13[9];
    char stringdata14[9];
    char stringdata15[9];
    char stringdata16[13];
    char stringdata17[10];
    char stringdata18[12];
    char stringdata19[7];
    char stringdata20[13];
    char stringdata21[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTableDelegateENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTableDelegateENDCLASS_t qt_meta_stringdata_CLASSTableDelegateENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "TableDelegate"
        QT_MOC_LITERAL(14, 13),  // "buttonClicked"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 11),  // "QModelIndex"
        QT_MOC_LITERAL(41, 5),  // "index"
        QT_MOC_LITERAL(47, 18),  // "deleteButtonCicked"
        QT_MOC_LITERAL(66, 10),  // "ColumnType"
        QT_MOC_LITERAL(77, 13),  // "DoubleSpinBox"
        QT_MOC_LITERAL(91, 7),  // "SpinBox"
        QT_MOC_LITERAL(99, 8),  // "LineEdit"
        QT_MOC_LITERAL(108, 8),  // "ComboBox"
        QT_MOC_LITERAL(117, 8),  // "Checkbox"
        QT_MOC_LITERAL(126, 7),  // "LatEdit"
        QT_MOC_LITERAL(134, 8),  // "LongEdit"
        QT_MOC_LITERAL(143, 8),  // "TimeEdit"
        QT_MOC_LITERAL(152, 8),  // "DateEdit"
        QT_MOC_LITERAL(161, 12),  // "DateTimeEdit"
        QT_MOC_LITERAL(174, 9),  // "AltitEdit"
        QT_MOC_LITERAL(184, 11),  // "RadioButton"
        QT_MOC_LITERAL(196, 6),  // "Button"
        QT_MOC_LITERAL(203, 12),  // "DeleteButton"
        QT_MOC_LITERAL(216, 10)   // "DragButton"
    },
    "TableDelegate",
    "buttonClicked",
    "",
    "QModelIndex",
    "index",
    "deleteButtonCicked",
    "ColumnType",
    "DoubleSpinBox",
    "SpinBox",
    "LineEdit",
    "ComboBox",
    "Checkbox",
    "LatEdit",
    "LongEdit",
    "TimeEdit",
    "DateEdit",
    "DateTimeEdit",
    "AltitEdit",
    "RadioButton",
    "Button",
    "DeleteButton",
    "DragButton"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTableDelegateENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       1,   32, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x106,    1 /* Public | MethodIsConst  */,
       5,    1,   29,    2, 0x106,    3 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // enums: name, alias, flags, count, data
       6,    6, 0x2,   15,   37,

 // enum data: key, value
       7, uint(TableDelegate::ColumnType::DoubleSpinBox),
       8, uint(TableDelegate::ColumnType::SpinBox),
       9, uint(TableDelegate::ColumnType::LineEdit),
      10, uint(TableDelegate::ColumnType::ComboBox),
      11, uint(TableDelegate::ColumnType::Checkbox),
      12, uint(TableDelegate::ColumnType::LatEdit),
      13, uint(TableDelegate::ColumnType::LongEdit),
      14, uint(TableDelegate::ColumnType::TimeEdit),
      15, uint(TableDelegate::ColumnType::DateEdit),
      16, uint(TableDelegate::ColumnType::DateTimeEdit),
      17, uint(TableDelegate::ColumnType::AltitEdit),
      18, uint(TableDelegate::ColumnType::RadioButton),
      19, uint(TableDelegate::ColumnType::Button),
      20, uint(TableDelegate::ColumnType::DeleteButton),
      21, uint(TableDelegate::ColumnType::DragButton),

       0        // eod
};

Q_CONSTINIT const QMetaObject TableDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_CLASSTableDelegateENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTableDelegateENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTableDelegateENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TableDelegate, std::true_type>,
        // method 'buttonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'deleteButtonCicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>
    >,
    nullptr
} };

void TableDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TableDelegate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->buttonClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->deleteButtonCicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TableDelegate::*)(const QModelIndex & ) const;
            if (_t _q_method = &TableDelegate::buttonClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TableDelegate::*)(const QModelIndex & ) const;
            if (_t _q_method = &TableDelegate::deleteButtonCicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *TableDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTableDelegateENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int TableDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TableDelegate::buttonClicked(const QModelIndex & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< TableDelegate *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TableDelegate::deleteButtonCicked(const QModelIndex & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< TableDelegate *>(this), &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS = QtMocHelpers::stringData(
    "TableWidgetsDelegate"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS_t qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20)   // "TableWidgetsDelegate"
    },
    "TableWidgetsDelegate"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTableWidgetsDelegateENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject TableWidgetsDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<TableDelegate::staticMetaObject>(),
    qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTableWidgetsDelegateENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TableWidgetsDelegate, std::true_type>
    >,
    nullptr
} };

void TableWidgetsDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *TableWidgetsDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableWidgetsDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTableWidgetsDelegateENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return TableDelegate::qt_metacast(_clname);
}

int TableWidgetsDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TableDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
