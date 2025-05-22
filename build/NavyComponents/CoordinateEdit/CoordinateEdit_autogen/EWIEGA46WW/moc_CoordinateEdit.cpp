/****************************************************************************
** Meta object code from reading C++ file 'CoordinateEdit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../NavyComponents/CoordinateEdit/CoordinateEdit.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CoordinateEdit.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS = QtMocHelpers::stringData(
    "AbstractCoordinateEdit",
    "valueChanged",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[23];
    char stringdata1[13];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS_t qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "AbstractCoordinateEdit"
        QT_MOC_LITERAL(23, 12),  // "valueChanged"
        QT_MOC_LITERAL(36, 0)   // ""
    },
    "AbstractCoordinateEdit",
    "valueChanged",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAbstractCoordinateEditENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject AbstractCoordinateEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractSpinBox::staticMetaObject>(),
    qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAbstractCoordinateEditENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AbstractCoordinateEdit, std::true_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void AbstractCoordinateEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AbstractCoordinateEdit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AbstractCoordinateEdit::*)(double );
            if (_t _q_method = &AbstractCoordinateEdit::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *AbstractCoordinateEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractCoordinateEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAbstractCoordinateEditENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CoordinateEdit"))
        return static_cast< CoordinateEdit*>(this);
    return QAbstractSpinBox::qt_metacast(_clname);
}

int AbstractCoordinateEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSpinBox::qt_metacall(_c, _id, _a);
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
    }
    return _id;
}

// SIGNAL 0
void AbstractCoordinateEdit::valueChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSLatitudeEditENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSLatitudeEditENDCLASS = QtMocHelpers::stringData(
    "LatitudeEdit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLatitudeEditENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLatitudeEditENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLatitudeEditENDCLASS_t qt_meta_stringdata_CLASSLatitudeEditENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12)   // "LatitudeEdit"
    },
    "LatitudeEdit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLatitudeEditENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject LatitudeEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractCoordinateEdit::staticMetaObject>(),
    qt_meta_stringdata_CLASSLatitudeEditENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLatitudeEditENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLatitudeEditENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LatitudeEdit, std::true_type>
    >,
    nullptr
} };

void LatitudeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *LatitudeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LatitudeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLatitudeEditENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AbstractCoordinateEdit::qt_metacast(_clname);
}

int LatitudeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCoordinateEdit::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSLongitudeEditENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSLongitudeEditENDCLASS = QtMocHelpers::stringData(
    "LongitudeEdit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLongitudeEditENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLongitudeEditENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLongitudeEditENDCLASS_t qt_meta_stringdata_CLASSLongitudeEditENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13)   // "LongitudeEdit"
    },
    "LongitudeEdit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLongitudeEditENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject LongitudeEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractCoordinateEdit::staticMetaObject>(),
    qt_meta_stringdata_CLASSLongitudeEditENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLongitudeEditENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLongitudeEditENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LongitudeEdit, std::true_type>
    >,
    nullptr
} };

void LongitudeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *LongitudeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LongitudeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLongitudeEditENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AbstractCoordinateEdit::qt_metacast(_clname);
}

int LongitudeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCoordinateEdit::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS = QtMocHelpers::stringData(
    "DeltaLatitudeEdit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS_t qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17)   // "DeltaLatitudeEdit"
    },
    "DeltaLatitudeEdit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDeltaLatitudeEditENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject DeltaLatitudeEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractCoordinateEdit::staticMetaObject>(),
    qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDeltaLatitudeEditENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DeltaLatitudeEdit, std::true_type>
    >,
    nullptr
} };

void DeltaLatitudeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *DeltaLatitudeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeltaLatitudeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDeltaLatitudeEditENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AbstractCoordinateEdit::qt_metacast(_clname);
}

int DeltaLatitudeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCoordinateEdit::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS = QtMocHelpers::stringData(
    "DeltaLongitudeEdit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS_t qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18)   // "DeltaLongitudeEdit"
    },
    "DeltaLongitudeEdit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDeltaLongitudeEditENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject DeltaLongitudeEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractCoordinateEdit::staticMetaObject>(),
    qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDeltaLongitudeEditENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DeltaLongitudeEdit, std::true_type>
    >,
    nullptr
} };

void DeltaLongitudeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *DeltaLongitudeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeltaLongitudeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDeltaLongitudeEditENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AbstractCoordinateEdit::qt_metacast(_clname);
}

int DeltaLongitudeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCoordinateEdit::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSAltitudeEditENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAltitudeEditENDCLASS = QtMocHelpers::stringData(
    "AltitudeEdit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAltitudeEditENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAltitudeEditENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAltitudeEditENDCLASS_t qt_meta_stringdata_CLASSAltitudeEditENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12)   // "AltitudeEdit"
    },
    "AltitudeEdit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAltitudeEditENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject AltitudeEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractCoordinateEdit::staticMetaObject>(),
    qt_meta_stringdata_CLASSAltitudeEditENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAltitudeEditENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAltitudeEditENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AltitudeEdit, std::true_type>
    >,
    nullptr
} };

void AltitudeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *AltitudeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AltitudeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAltitudeEditENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AbstractCoordinateEdit::qt_metacast(_clname);
}

int AltitudeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCoordinateEdit::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSAzimuthEditENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAzimuthEditENDCLASS = QtMocHelpers::stringData(
    "AzimuthEdit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAzimuthEditENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAzimuthEditENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAzimuthEditENDCLASS_t qt_meta_stringdata_CLASSAzimuthEditENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11)   // "AzimuthEdit"
    },
    "AzimuthEdit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAzimuthEditENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject AzimuthEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<AbstractCoordinateEdit::staticMetaObject>(),
    qt_meta_stringdata_CLASSAzimuthEditENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAzimuthEditENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAzimuthEditENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AzimuthEdit, std::true_type>
    >,
    nullptr
} };

void AzimuthEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *AzimuthEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AzimuthEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAzimuthEditENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return AbstractCoordinateEdit::qt_metacast(_clname);
}

int AzimuthEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCoordinateEdit::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
