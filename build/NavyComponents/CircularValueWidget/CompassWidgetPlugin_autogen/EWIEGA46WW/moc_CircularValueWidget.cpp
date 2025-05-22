/****************************************************************************
** Meta object code from reading C++ file 'CircularValueWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../NavyComponents/CircularValueWidget/CircularValueWidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CircularValueWidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS = QtMocHelpers::stringData(
    "CircularValueWidget",
    "valueChanged",
    "",
    "value",
    "readOnly",
    "wrapping",
    "maxValue",
    "minValue",
    "nameValue",
    "nameUints",
    "step",
    "decimals"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[20];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[9];
    char stringdata5[9];
    char stringdata6[9];
    char stringdata7[9];
    char stringdata8[10];
    char stringdata9[10];
    char stringdata10[5];
    char stringdata11[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS_t qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "CircularValueWidget"
        QT_MOC_LITERAL(20, 12),  // "valueChanged"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 5),  // "value"
        QT_MOC_LITERAL(40, 8),  // "readOnly"
        QT_MOC_LITERAL(49, 8),  // "wrapping"
        QT_MOC_LITERAL(58, 8),  // "maxValue"
        QT_MOC_LITERAL(67, 8),  // "minValue"
        QT_MOC_LITERAL(76, 9),  // "nameValue"
        QT_MOC_LITERAL(86, 9),  // "nameUints"
        QT_MOC_LITERAL(96, 4),  // "step"
        QT_MOC_LITERAL(101, 8)   // "decimals"
    },
    "CircularValueWidget",
    "valueChanged",
    "",
    "value",
    "readOnly",
    "wrapping",
    "maxValue",
    "minValue",
    "nameValue",
    "nameUints",
    "step",
    "decimals"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCircularValueWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       9,   23, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00015103, uint(-1), 0,
       5, QMetaType::Bool, 0x00015103, uint(-1), 0,
       6, QMetaType::Double, 0x00015003, uint(-1), 0,
       7, QMetaType::Double, 0x00015003, uint(-1), 0,
       3, QMetaType::Double, 0x00115103, uint(-1), 0,
       8, QMetaType::QString, 0x00015103, uint(-1), 0,
       9, QMetaType::QString, 0x00015103, uint(-1), 0,
      10, QMetaType::Double, 0x00015103, uint(-1), 0,
      11, QMetaType::Double, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject CircularValueWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCircularValueWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS_t,
        // property 'readOnly'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'wrapping'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'maxValue'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'minValue'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'value'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'nameValue'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'nameUints'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'step'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'decimals'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CircularValueWidget, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void CircularValueWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CircularValueWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CircularValueWidget::*)(double );
            if (_t _q_method = &CircularValueWidget::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CircularValueWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getReadOnly(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getWrapping(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->getMaximum(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getMinimum(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->getValue(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getNameValue(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->getNameUints(); break;
        case 7: *reinterpret_cast< double*>(_v) = _t->getStep(); break;
        case 8: *reinterpret_cast< double*>(_v) = _t->getDecimals(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CircularValueWidget *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setReadOnly(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setWrapping(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setMaximum(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setMinimum(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setValue(*reinterpret_cast< double*>(_v)); break;
        case 5: _t->setNameValue(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setNameUints(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setStep(*reinterpret_cast< double*>(_v)); break;
        case 8: _t->setDecimals(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *CircularValueWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CircularValueWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCircularValueWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CircularValueWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CircularValueWidget::valueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
