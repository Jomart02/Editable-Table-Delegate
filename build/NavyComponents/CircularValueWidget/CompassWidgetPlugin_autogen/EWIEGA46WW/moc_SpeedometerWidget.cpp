/****************************************************************************
** Meta object code from reading C++ file 'SpeedometerWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../NavyComponents/CircularValueWidget/SpeedometerWidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SpeedometerWidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS = QtMocHelpers::stringData(
    "SpeedometerWidget",
    "background",
    "textNameColor",
    "textValueColor",
    "textUintsColor",
    "marksColor"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[18];
    char stringdata1[11];
    char stringdata2[14];
    char stringdata3[15];
    char stringdata4[15];
    char stringdata5[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS_t qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "SpeedometerWidget"
        QT_MOC_LITERAL(18, 10),  // "background"
        QT_MOC_LITERAL(29, 13),  // "textNameColor"
        QT_MOC_LITERAL(43, 14),  // "textValueColor"
        QT_MOC_LITERAL(58, 14),  // "textUintsColor"
        QT_MOC_LITERAL(73, 10)   // "marksColor"
    },
    "SpeedometerWidget",
    "background",
    "textNameColor",
    "textValueColor",
    "textUintsColor",
    "marksColor"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSpeedometerWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QColor, 0x00015103, uint(-1), 0,
       2, QMetaType::QColor, 0x00015103, uint(-1), 0,
       3, QMetaType::QColor, 0x00015103, uint(-1), 0,
       4, QMetaType::QColor, 0x00015003, uint(-1), 0,
       5, QMetaType::QColor, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SpeedometerWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<CircularValueWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSpeedometerWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS_t,
        // property 'background'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'textNameColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'textValueColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'textUintsColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'marksColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SpeedometerWidget, std::true_type>
    >,
    nullptr
} };

void SpeedometerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SpeedometerWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->getBackground(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->getTextNameColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->getTextValueColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->getUintsColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->getMarksColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SpeedometerWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBackground(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setTextNameColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setTextValueColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setUintsColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setMarksColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *SpeedometerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpeedometerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSpeedometerWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return CircularValueWidget::qt_metacast(_clname);
}

int SpeedometerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CircularValueWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
