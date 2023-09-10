//
// Generated file, do not edit! Created by opp_msgtool 6.0 from stack/mac/packet/LteSchedulingGrant.msg.
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
#include "LteSchedulingGrant_m.h"

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

LteSchedulingGrant_Base::LteSchedulingGrant_Base() : ::inet::FieldsChunk()
{
    this->setChunkLength(inet::B(1));

}

LteSchedulingGrant_Base::LteSchedulingGrant_Base(const LteSchedulingGrant_Base& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

LteSchedulingGrant_Base::~LteSchedulingGrant_Base()
{
}

LteSchedulingGrant_Base& LteSchedulingGrant_Base::operator=(const LteSchedulingGrant_Base& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void LteSchedulingGrant_Base::copy(const LteSchedulingGrant_Base& other)
{
    this->periodic = other.periodic;
    this->period = other.period;
    this->expiration = other.expiration;
    this->totalGrantedBlocks = other.totalGrantedBlocks;
    this->codewords = other.codewords;
}

void LteSchedulingGrant_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->periodic);
    doParsimPacking(b,this->period);
    doParsimPacking(b,this->expiration);
    doParsimPacking(b,this->totalGrantedBlocks);
    doParsimPacking(b,this->codewords);
    // field grantedCwBytes is abstract or custom -- please do packing in customized class
}

void LteSchedulingGrant_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->periodic);
    doParsimUnpacking(b,this->period);
    doParsimUnpacking(b,this->expiration);
    doParsimUnpacking(b,this->totalGrantedBlocks);
    doParsimUnpacking(b,this->codewords);
    // field grantedCwBytes is abstract or custom -- please do unpacking in customized class
}

bool LteSchedulingGrant_Base::getPeriodic() const
{
    return this->periodic;
}

void LteSchedulingGrant_Base::setPeriodic(bool periodic)
{
    handleChange();
    this->periodic = periodic;
}

unsigned int LteSchedulingGrant_Base::getPeriod() const
{
    return this->period;
}

void LteSchedulingGrant_Base::setPeriod(unsigned int period)
{
    handleChange();
    this->period = period;
}

unsigned int LteSchedulingGrant_Base::getExpiration() const
{
    return this->expiration;
}

void LteSchedulingGrant_Base::setExpiration(unsigned int expiration)
{
    handleChange();
    this->expiration = expiration;
}

unsigned int LteSchedulingGrant_Base::getTotalGrantedBlocks() const
{
    return this->totalGrantedBlocks;
}

void LteSchedulingGrant_Base::setTotalGrantedBlocks(unsigned int totalGrantedBlocks)
{
    handleChange();
    this->totalGrantedBlocks = totalGrantedBlocks;
}

unsigned int LteSchedulingGrant_Base::getCodewords() const
{
    return this->codewords;
}

void LteSchedulingGrant_Base::setCodewords(unsigned int codewords)
{
    handleChange();
    this->codewords = codewords;
}

class LteSchedulingGrantDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_periodic,
        FIELD_period,
        FIELD_expiration,
        FIELD_totalGrantedBlocks,
        FIELD_codewords,
        FIELD_grantedCwBytes,
    };
  public:
    LteSchedulingGrantDescriptor();
    virtual ~LteSchedulingGrantDescriptor();

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

Register_ClassDescriptor(LteSchedulingGrantDescriptor)

LteSchedulingGrantDescriptor::LteSchedulingGrantDescriptor() : omnetpp::cClassDescriptor("LteSchedulingGrant", "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

LteSchedulingGrantDescriptor::~LteSchedulingGrantDescriptor()
{
    delete[] propertyNames;
}

bool LteSchedulingGrantDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteSchedulingGrant_Base *>(obj)!=nullptr;
}

const char **LteSchedulingGrantDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LteSchedulingGrantDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "customize")) return "true";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LteSchedulingGrantDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int LteSchedulingGrantDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_periodic
        FD_ISEDITABLE,    // FIELD_period
        FD_ISEDITABLE,    // FIELD_expiration
        FD_ISEDITABLE,    // FIELD_totalGrantedBlocks
        FD_ISEDITABLE,    // FIELD_codewords
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_grantedCwBytes
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *LteSchedulingGrantDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "periodic",
        "period",
        "expiration",
        "totalGrantedBlocks",
        "codewords",
        "grantedCwBytes",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int LteSchedulingGrantDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "periodic") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "period") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "expiration") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "totalGrantedBlocks") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "codewords") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "grantedCwBytes") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *LteSchedulingGrantDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_periodic
        "unsigned int",    // FIELD_period
        "unsigned int",    // FIELD_expiration
        "unsigned int",    // FIELD_totalGrantedBlocks
        "unsigned int",    // FIELD_codewords
        "unsigned int",    // FIELD_grantedCwBytes
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **LteSchedulingGrantDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LteSchedulingGrantDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LteSchedulingGrantDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        case FIELD_grantedCwBytes: return pp->getGrantedCwBytesArraySize();
        default: return 0;
    }
}

void LteSchedulingGrantDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        case FIELD_grantedCwBytes: pp->setGrantedCwBytesArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LteSchedulingGrant_Base'", field);
    }
}

const char *LteSchedulingGrantDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteSchedulingGrantDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        case FIELD_periodic: return bool2string(pp->getPeriodic());
        case FIELD_period: return ulong2string(pp->getPeriod());
        case FIELD_expiration: return ulong2string(pp->getExpiration());
        case FIELD_totalGrantedBlocks: return ulong2string(pp->getTotalGrantedBlocks());
        case FIELD_codewords: return ulong2string(pp->getCodewords());
        case FIELD_grantedCwBytes: return ulong2string(pp->getGrantedCwBytes(i));
        default: return "";
    }
}

void LteSchedulingGrantDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        case FIELD_periodic: pp->setPeriodic(string2bool(value)); break;
        case FIELD_period: pp->setPeriod(string2ulong(value)); break;
        case FIELD_expiration: pp->setExpiration(string2ulong(value)); break;
        case FIELD_totalGrantedBlocks: pp->setTotalGrantedBlocks(string2ulong(value)); break;
        case FIELD_codewords: pp->setCodewords(string2ulong(value)); break;
        case FIELD_grantedCwBytes: pp->setGrantedCwBytes(i,string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteSchedulingGrant_Base'", field);
    }
}

omnetpp::cValue LteSchedulingGrantDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        case FIELD_periodic: return pp->getPeriodic();
        case FIELD_period: return (omnetpp::intval_t)(pp->getPeriod());
        case FIELD_expiration: return (omnetpp::intval_t)(pp->getExpiration());
        case FIELD_totalGrantedBlocks: return (omnetpp::intval_t)(pp->getTotalGrantedBlocks());
        case FIELD_codewords: return (omnetpp::intval_t)(pp->getCodewords());
        case FIELD_grantedCwBytes: return (omnetpp::intval_t)(pp->getGrantedCwBytes(i));
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LteSchedulingGrant_Base' as cValue -- field index out of range?", field);
    }
}

void LteSchedulingGrantDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        case FIELD_periodic: pp->setPeriodic(value.boolValue()); break;
        case FIELD_period: pp->setPeriod(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_expiration: pp->setExpiration(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_totalGrantedBlocks: pp->setTotalGrantedBlocks(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_codewords: pp->setCodewords(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_grantedCwBytes: pp->setGrantedCwBytes(i,omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteSchedulingGrant_Base'", field);
    }
}

const char *LteSchedulingGrantDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LteSchedulingGrantDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LteSchedulingGrantDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LteSchedulingGrant_Base *pp = omnetpp::fromAnyPtr<LteSchedulingGrant_Base>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteSchedulingGrant_Base'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

