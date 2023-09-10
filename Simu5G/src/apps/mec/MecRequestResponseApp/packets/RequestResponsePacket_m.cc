//
// Generated file, do not edit! Created by opp_msgtool 6.0 from apps/mec/MecRequestResponseApp/packets/RequestResponsePacket.msg.
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
#include "RequestResponsePacket_m.h"

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

Register_Class(RequestResponseAppPacket)

RequestResponseAppPacket::RequestResponseAppPacket() : ::inet::FieldsChunk()
{
}

RequestResponseAppPacket::RequestResponseAppPacket(const RequestResponseAppPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

RequestResponseAppPacket::~RequestResponseAppPacket()
{
}

RequestResponseAppPacket& RequestResponseAppPacket::operator=(const RequestResponseAppPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void RequestResponseAppPacket::copy(const RequestResponseAppPacket& other)
{
    this->type = other.type;
    this->sno = other.sno;
    this->requestSentTimestamp = other.requestSentTimestamp;
    this->requestArrivedTimestamp = other.requestArrivedTimestamp;
    this->processingTime = other.processingTime;
    this->serviceResponseTime = other.serviceResponseTime;
    this->responseSentTimestamp = other.responseSentTimestamp;
}

void RequestResponseAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->sno);
    doParsimPacking(b,this->requestSentTimestamp);
    doParsimPacking(b,this->requestArrivedTimestamp);
    doParsimPacking(b,this->processingTime);
    doParsimPacking(b,this->serviceResponseTime);
    doParsimPacking(b,this->responseSentTimestamp);
}

void RequestResponseAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->sno);
    doParsimUnpacking(b,this->requestSentTimestamp);
    doParsimUnpacking(b,this->requestArrivedTimestamp);
    doParsimUnpacking(b,this->processingTime);
    doParsimUnpacking(b,this->serviceResponseTime);
    doParsimUnpacking(b,this->responseSentTimestamp);
}

int RequestResponseAppPacket::getType() const
{
    return this->type;
}

void RequestResponseAppPacket::setType(int type)
{
    handleChange();
    this->type = type;
}

unsigned int RequestResponseAppPacket::getSno() const
{
    return this->sno;
}

void RequestResponseAppPacket::setSno(unsigned int sno)
{
    handleChange();
    this->sno = sno;
}

omnetpp::simtime_t RequestResponseAppPacket::getRequestSentTimestamp() const
{
    return this->requestSentTimestamp;
}

void RequestResponseAppPacket::setRequestSentTimestamp(omnetpp::simtime_t requestSentTimestamp)
{
    handleChange();
    this->requestSentTimestamp = requestSentTimestamp;
}

omnetpp::simtime_t RequestResponseAppPacket::getRequestArrivedTimestamp() const
{
    return this->requestArrivedTimestamp;
}

void RequestResponseAppPacket::setRequestArrivedTimestamp(omnetpp::simtime_t requestArrivedTimestamp)
{
    handleChange();
    this->requestArrivedTimestamp = requestArrivedTimestamp;
}

double RequestResponseAppPacket::getProcessingTime() const
{
    return this->processingTime;
}

void RequestResponseAppPacket::setProcessingTime(double processingTime)
{
    handleChange();
    this->processingTime = processingTime;
}

omnetpp::simtime_t RequestResponseAppPacket::getServiceResponseTime() const
{
    return this->serviceResponseTime;
}

void RequestResponseAppPacket::setServiceResponseTime(omnetpp::simtime_t serviceResponseTime)
{
    handleChange();
    this->serviceResponseTime = serviceResponseTime;
}

omnetpp::simtime_t RequestResponseAppPacket::getResponseSentTimestamp() const
{
    return this->responseSentTimestamp;
}

void RequestResponseAppPacket::setResponseSentTimestamp(omnetpp::simtime_t responseSentTimestamp)
{
    handleChange();
    this->responseSentTimestamp = responseSentTimestamp;
}

class RequestResponseAppPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_type,
        FIELD_sno,
        FIELD_requestSentTimestamp,
        FIELD_requestArrivedTimestamp,
        FIELD_processingTime,
        FIELD_serviceResponseTime,
        FIELD_responseSentTimestamp,
    };
  public:
    RequestResponseAppPacketDescriptor();
    virtual ~RequestResponseAppPacketDescriptor();

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

Register_ClassDescriptor(RequestResponseAppPacketDescriptor)

RequestResponseAppPacketDescriptor::RequestResponseAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(RequestResponseAppPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

RequestResponseAppPacketDescriptor::~RequestResponseAppPacketDescriptor()
{
    delete[] propertyNames;
}

bool RequestResponseAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RequestResponseAppPacket *>(obj)!=nullptr;
}

const char **RequestResponseAppPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RequestResponseAppPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RequestResponseAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int RequestResponseAppPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_sno
        FD_ISEDITABLE,    // FIELD_requestSentTimestamp
        FD_ISEDITABLE,    // FIELD_requestArrivedTimestamp
        FD_ISEDITABLE,    // FIELD_processingTime
        FD_ISEDITABLE,    // FIELD_serviceResponseTime
        FD_ISEDITABLE,    // FIELD_responseSentTimestamp
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *RequestResponseAppPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "sno",
        "requestSentTimestamp",
        "requestArrivedTimestamp",
        "processingTime",
        "serviceResponseTime",
        "responseSentTimestamp",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int RequestResponseAppPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sno") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "requestSentTimestamp") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "requestArrivedTimestamp") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "processingTime") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "serviceResponseTime") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "responseSentTimestamp") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *RequestResponseAppPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_type
        "unsigned int",    // FIELD_sno
        "omnetpp::simtime_t",    // FIELD_requestSentTimestamp
        "omnetpp::simtime_t",    // FIELD_requestArrivedTimestamp
        "double",    // FIELD_processingTime
        "omnetpp::simtime_t",    // FIELD_serviceResponseTime
        "omnetpp::simtime_t",    // FIELD_responseSentTimestamp
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **RequestResponseAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RequestResponseAppPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int RequestResponseAppPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RequestResponseAppPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'RequestResponseAppPacket'", field);
    }
}

const char *RequestResponseAppPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RequestResponseAppPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: return long2string(pp->getType());
        case FIELD_sno: return ulong2string(pp->getSno());
        case FIELD_requestSentTimestamp: return simtime2string(pp->getRequestSentTimestamp());
        case FIELD_requestArrivedTimestamp: return simtime2string(pp->getRequestArrivedTimestamp());
        case FIELD_processingTime: return double2string(pp->getProcessingTime());
        case FIELD_serviceResponseTime: return simtime2string(pp->getServiceResponseTime());
        case FIELD_responseSentTimestamp: return simtime2string(pp->getResponseSentTimestamp());
        default: return "";
    }
}

void RequestResponseAppPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(string2long(value)); break;
        case FIELD_sno: pp->setSno(string2ulong(value)); break;
        case FIELD_requestSentTimestamp: pp->setRequestSentTimestamp(string2simtime(value)); break;
        case FIELD_requestArrivedTimestamp: pp->setRequestArrivedTimestamp(string2simtime(value)); break;
        case FIELD_processingTime: pp->setProcessingTime(string2double(value)); break;
        case FIELD_serviceResponseTime: pp->setServiceResponseTime(string2simtime(value)); break;
        case FIELD_responseSentTimestamp: pp->setResponseSentTimestamp(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RequestResponseAppPacket'", field);
    }
}

omnetpp::cValue RequestResponseAppPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: return pp->getType();
        case FIELD_sno: return (omnetpp::intval_t)(pp->getSno());
        case FIELD_requestSentTimestamp: return pp->getRequestSentTimestamp().dbl();
        case FIELD_requestArrivedTimestamp: return pp->getRequestArrivedTimestamp().dbl();
        case FIELD_processingTime: return pp->getProcessingTime();
        case FIELD_serviceResponseTime: return pp->getServiceResponseTime().dbl();
        case FIELD_responseSentTimestamp: return pp->getResponseSentTimestamp().dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'RequestResponseAppPacket' as cValue -- field index out of range?", field);
    }
}

void RequestResponseAppPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sno: pp->setSno(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_requestSentTimestamp: pp->setRequestSentTimestamp(value.doubleValue()); break;
        case FIELD_requestArrivedTimestamp: pp->setRequestArrivedTimestamp(value.doubleValue()); break;
        case FIELD_processingTime: pp->setProcessingTime(value.doubleValue()); break;
        case FIELD_serviceResponseTime: pp->setServiceResponseTime(value.doubleValue()); break;
        case FIELD_responseSentTimestamp: pp->setResponseSentTimestamp(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RequestResponseAppPacket'", field);
    }
}

const char *RequestResponseAppPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr RequestResponseAppPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RequestResponseAppPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    RequestResponseAppPacket *pp = omnetpp::fromAnyPtr<RequestResponseAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RequestResponseAppPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

