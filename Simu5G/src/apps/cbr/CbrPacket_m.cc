//
// Generated file, do not edit! Created by opp_msgtool 6.0 from apps/cbr/CbrPacket.msg.
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
#include "CbrPacket_m.h"

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

Register_Class(CbrPacket)

CbrPacket::CbrPacket() : ::inet::FieldsChunk()
{
}

CbrPacket::CbrPacket(const CbrPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

CbrPacket::~CbrPacket()
{
}

CbrPacket& CbrPacket::operator=(const CbrPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void CbrPacket::copy(const CbrPacket& other)
{
    this->nframes = other.nframes;
    this->IDframe = other.IDframe;
    this->arrivalTime = other.arrivalTime;
    this->payloadTimestamp = other.payloadTimestamp;
    this->payloadSize = other.payloadSize;
}

void CbrPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->nframes);
    doParsimPacking(b,this->IDframe);
    doParsimPacking(b,this->arrivalTime);
    doParsimPacking(b,this->payloadTimestamp);
    doParsimPacking(b,this->payloadSize);
}

void CbrPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->nframes);
    doParsimUnpacking(b,this->IDframe);
    doParsimUnpacking(b,this->arrivalTime);
    doParsimUnpacking(b,this->payloadTimestamp);
    doParsimUnpacking(b,this->payloadSize);
}

unsigned int CbrPacket::getNframes() const
{
    return this->nframes;
}

void CbrPacket::setNframes(unsigned int nframes)
{
    handleChange();
    this->nframes = nframes;
}

unsigned int CbrPacket::getIDframe() const
{
    return this->IDframe;
}

void CbrPacket::setIDframe(unsigned int IDframe)
{
    handleChange();
    this->IDframe = IDframe;
}

omnetpp::simtime_t CbrPacket::getArrivalTime() const
{
    return this->arrivalTime;
}

void CbrPacket::setArrivalTime(omnetpp::simtime_t arrivalTime)
{
    handleChange();
    this->arrivalTime = arrivalTime;
}

omnetpp::simtime_t CbrPacket::getPayloadTimestamp() const
{
    return this->payloadTimestamp;
}

void CbrPacket::setPayloadTimestamp(omnetpp::simtime_t payloadTimestamp)
{
    handleChange();
    this->payloadTimestamp = payloadTimestamp;
}

unsigned int CbrPacket::getPayloadSize() const
{
    return this->payloadSize;
}

void CbrPacket::setPayloadSize(unsigned int payloadSize)
{
    handleChange();
    this->payloadSize = payloadSize;
}

class CbrPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_nframes,
        FIELD_IDframe,
        FIELD_arrivalTime,
        FIELD_payloadTimestamp,
        FIELD_payloadSize,
    };
  public:
    CbrPacketDescriptor();
    virtual ~CbrPacketDescriptor();

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

Register_ClassDescriptor(CbrPacketDescriptor)

CbrPacketDescriptor::CbrPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(CbrPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

CbrPacketDescriptor::~CbrPacketDescriptor()
{
    delete[] propertyNames;
}

bool CbrPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CbrPacket *>(obj)!=nullptr;
}

const char **CbrPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CbrPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CbrPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int CbrPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_nframes
        FD_ISEDITABLE,    // FIELD_IDframe
        FD_ISEDITABLE,    // FIELD_arrivalTime
        FD_ISEDITABLE,    // FIELD_payloadTimestamp
        FD_ISEDITABLE,    // FIELD_payloadSize
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *CbrPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nframes",
        "IDframe",
        "arrivalTime",
        "payloadTimestamp",
        "payloadSize",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int CbrPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "nframes") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "IDframe") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "arrivalTime") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "payloadTimestamp") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "payloadSize") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *CbrPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_nframes
        "unsigned int",    // FIELD_IDframe
        "omnetpp::simtime_t",    // FIELD_arrivalTime
        "omnetpp::simtime_t",    // FIELD_payloadTimestamp
        "unsigned int",    // FIELD_payloadSize
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **CbrPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *CbrPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int CbrPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CbrPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CbrPacket'", field);
    }
}

const char *CbrPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CbrPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        case FIELD_nframes: return ulong2string(pp->getNframes());
        case FIELD_IDframe: return ulong2string(pp->getIDframe());
        case FIELD_arrivalTime: return simtime2string(pp->getArrivalTime());
        case FIELD_payloadTimestamp: return simtime2string(pp->getPayloadTimestamp());
        case FIELD_payloadSize: return ulong2string(pp->getPayloadSize());
        default: return "";
    }
}

void CbrPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        case FIELD_nframes: pp->setNframes(string2ulong(value)); break;
        case FIELD_IDframe: pp->setIDframe(string2ulong(value)); break;
        case FIELD_arrivalTime: pp->setArrivalTime(string2simtime(value)); break;
        case FIELD_payloadTimestamp: pp->setPayloadTimestamp(string2simtime(value)); break;
        case FIELD_payloadSize: pp->setPayloadSize(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CbrPacket'", field);
    }
}

omnetpp::cValue CbrPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        case FIELD_nframes: return (omnetpp::intval_t)(pp->getNframes());
        case FIELD_IDframe: return (omnetpp::intval_t)(pp->getIDframe());
        case FIELD_arrivalTime: return pp->getArrivalTime().dbl();
        case FIELD_payloadTimestamp: return pp->getPayloadTimestamp().dbl();
        case FIELD_payloadSize: return (omnetpp::intval_t)(pp->getPayloadSize());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CbrPacket' as cValue -- field index out of range?", field);
    }
}

void CbrPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        case FIELD_nframes: pp->setNframes(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_IDframe: pp->setIDframe(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_arrivalTime: pp->setArrivalTime(value.doubleValue()); break;
        case FIELD_payloadTimestamp: pp->setPayloadTimestamp(value.doubleValue()); break;
        case FIELD_payloadSize: pp->setPayloadSize(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CbrPacket'", field);
    }
}

const char *CbrPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr CbrPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CbrPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CbrPacket *pp = omnetpp::fromAnyPtr<CbrPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CbrPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

