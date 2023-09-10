//
// Generated file, do not edit! Created by opp_msgtool 6.0 from stack/rlc/am/packet/LteRlcAmPdu.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "LteRlcAmPdu_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

LteRlcAmPdu_Base::LteRlcAmPdu_Base() : ::LteRlcPdu()
{
}

LteRlcAmPdu_Base::LteRlcAmPdu_Base(const LteRlcAmPdu_Base& other) : ::LteRlcPdu(other)
{
    copy(other);
}

LteRlcAmPdu_Base::~LteRlcAmPdu_Base()
{
}

LteRlcAmPdu_Base& LteRlcAmPdu_Base::operator=(const LteRlcAmPdu_Base& other)
{
    if (this == &other) return *this;
    ::LteRlcPdu::operator=(other);
    copy(other);
    return *this;
}

void LteRlcAmPdu_Base::copy(const LteRlcAmPdu_Base& other)
{
    this->amType = other.amType;
    this->txNumber = other.txNumber;
    this->firstSn = other.firstSn;
    this->lastSn = other.lastSn;
}

void LteRlcAmPdu_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::LteRlcPdu::parsimPack(b);
    doParsimPacking(b,this->amType);
    doParsimPacking(b,this->txNumber);
    doParsimPacking(b,this->firstSn);
    doParsimPacking(b,this->lastSn);
    // field bitmap is abstract or custom -- please do packing in customized class
}

void LteRlcAmPdu_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::LteRlcPdu::parsimUnpack(b);
    doParsimUnpacking(b,this->amType);
    doParsimUnpacking(b,this->txNumber);
    doParsimUnpacking(b,this->firstSn);
    doParsimUnpacking(b,this->lastSn);
    // field bitmap is abstract or custom -- please do unpacking in customized class
}

unsigned short LteRlcAmPdu_Base::getAmType() const
{
    return this->amType;
}

void LteRlcAmPdu_Base::setAmType(unsigned short amType)
{
    handleChange();
    this->amType = amType;
}

unsigned short LteRlcAmPdu_Base::getTxNumber() const
{
    return this->txNumber;
}

void LteRlcAmPdu_Base::setTxNumber(unsigned short txNumber)
{
    handleChange();
    this->txNumber = txNumber;
}

int LteRlcAmPdu_Base::getFirstSn() const
{
    return this->firstSn;
}

void LteRlcAmPdu_Base::setFirstSn(int firstSn)
{
    handleChange();
    this->firstSn = firstSn;
}

int LteRlcAmPdu_Base::getLastSn() const
{
    return this->lastSn;
}

void LteRlcAmPdu_Base::setLastSn(int lastSn)
{
    handleChange();
    this->lastSn = lastSn;
}

class LteRlcAmPduDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_amType,
        FIELD_txNumber,
        FIELD_firstSn,
        FIELD_lastSn,
        FIELD_bitmap,
    };
  public:
    LteRlcAmPduDescriptor();
    virtual ~LteRlcAmPduDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(LteRlcAmPduDescriptor)

LteRlcAmPduDescriptor::LteRlcAmPduDescriptor() : omnetpp::cClassDescriptor("LteRlcAmPdu", "LteRlcPdu")
{
    propertyNames = nullptr;
}

LteRlcAmPduDescriptor::~LteRlcAmPduDescriptor()
{
    delete[] propertyNames;
}

bool LteRlcAmPduDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteRlcAmPdu_Base *>(obj)!=nullptr;
}

const char **LteRlcAmPduDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LteRlcAmPduDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "customize")) return "true";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LteRlcAmPduDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int LteRlcAmPduDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_amType
        FD_ISEDITABLE,    // FIELD_txNumber
        FD_ISEDITABLE,    // FIELD_firstSn
        FD_ISEDITABLE,    // FIELD_lastSn
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_bitmap
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *LteRlcAmPduDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "amType",
        "txNumber",
        "firstSn",
        "lastSn",
        "bitmap",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int LteRlcAmPduDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "amType") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "txNumber") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "firstSn") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "lastSn") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "bitmap") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *LteRlcAmPduDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",    // FIELD_amType
        "unsigned short",    // FIELD_txNumber
        "int",    // FIELD_firstSn
        "int",    // FIELD_lastSn
        "bool",    // FIELD_bitmap
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **LteRlcAmPduDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_amType: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *LteRlcAmPduDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_amType:
            if (!strcmp(propertyName, "enum")) return "LteAmType";
            if (!strcmp(propertyName, "enum")) return "LteAmType";
            return nullptr;
        default: return nullptr;
    }
}

int LteRlcAmPduDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        case FIELD_bitmap: return pp->getBitmapArraySize();
        default: return 0;
    }
}

void LteRlcAmPduDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        case FIELD_bitmap: pp->setBitmapArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LteRlcAmPdu_Base'", field);
    }
}

const char *LteRlcAmPduDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteRlcAmPduDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        case FIELD_amType: return enum2string(pp->getAmType(), "LteAmType");
        case FIELD_txNumber: return ulong2string(pp->getTxNumber());
        case FIELD_firstSn: return long2string(pp->getFirstSn());
        case FIELD_lastSn: return long2string(pp->getLastSn());
        case FIELD_bitmap: return bool2string(pp->getBitmap(i));
        default: return "";
    }
}

void LteRlcAmPduDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        case FIELD_amType: pp->setAmType((LteAmType)string2enum(value, "LteAmType")); break;
        case FIELD_txNumber: pp->setTxNumber(string2ulong(value)); break;
        case FIELD_firstSn: pp->setFirstSn(string2long(value)); break;
        case FIELD_lastSn: pp->setLastSn(string2long(value)); break;
        case FIELD_bitmap: pp->setBitmap(i,string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteRlcAmPdu_Base'", field);
    }
}

omnetpp::cValue LteRlcAmPduDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        case FIELD_amType: return (omnetpp::intval_t)(pp->getAmType());
        case FIELD_txNumber: return (omnetpp::intval_t)(pp->getTxNumber());
        case FIELD_firstSn: return pp->getFirstSn();
        case FIELD_lastSn: return pp->getLastSn();
        case FIELD_bitmap: return pp->getBitmap(i);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LteRlcAmPdu_Base' as cValue -- field index out of range?", field);
    }
}

void LteRlcAmPduDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        case FIELD_amType: pp->setAmType((LteAmType)value.intValue()); break;
        case FIELD_txNumber: pp->setTxNumber(omnetpp::checked_int_cast<unsigned short>(value.intValue())); break;
        case FIELD_firstSn: pp->setFirstSn(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_lastSn: pp->setLastSn(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bitmap: pp->setBitmap(i,value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteRlcAmPdu_Base'", field);
    }
}

const char *LteRlcAmPduDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr LteRlcAmPduDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LteRlcAmPduDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LteRlcAmPdu_Base *pp = omnetpp::fromAnyPtr<LteRlcAmPdu_Base>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteRlcAmPdu_Base'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

