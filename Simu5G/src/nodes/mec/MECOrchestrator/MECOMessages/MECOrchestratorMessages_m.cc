//
// Generated file, do not edit! Created by opp_msgtool 6.0 from nodes/mec/MECOrchestrator/MECOMessages/MECOrchestratorMessages.msg.
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
#include "MECOrchestratorMessages_m.h"

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

Register_Class(MECOrchestratorMessage)

MECOrchestratorMessage::MECOrchestratorMessage(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MECOrchestratorMessage::MECOrchestratorMessage(const MECOrchestratorMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MECOrchestratorMessage::~MECOrchestratorMessage()
{
}

MECOrchestratorMessage& MECOrchestratorMessage::operator=(const MECOrchestratorMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MECOrchestratorMessage::copy(const MECOrchestratorMessage& other)
{
    this->contextId = other.contextId;
    this->requestId = other.requestId;
    this->type = other.type;
    this->success = other.success;
}

void MECOrchestratorMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->contextId);
    doParsimPacking(b,this->requestId);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->success);
}

void MECOrchestratorMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->contextId);
    doParsimUnpacking(b,this->requestId);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->success);
}

int MECOrchestratorMessage::getContextId() const
{
    return this->contextId;
}

void MECOrchestratorMessage::setContextId(int contextId)
{
    this->contextId = contextId;
}

int MECOrchestratorMessage::getRequestId() const
{
    return this->requestId;
}

void MECOrchestratorMessage::setRequestId(int requestId)
{
    this->requestId = requestId;
}

const char * MECOrchestratorMessage::getType() const
{
    return this->type.c_str();
}

void MECOrchestratorMessage::setType(const char * type)
{
    this->type = type;
}

bool MECOrchestratorMessage::getSuccess() const
{
    return this->success;
}

void MECOrchestratorMessage::setSuccess(bool success)
{
    this->success = success;
}

class MECOrchestratorMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_contextId,
        FIELD_requestId,
        FIELD_type,
        FIELD_success,
    };
  public:
    MECOrchestratorMessageDescriptor();
    virtual ~MECOrchestratorMessageDescriptor();

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

Register_ClassDescriptor(MECOrchestratorMessageDescriptor)

MECOrchestratorMessageDescriptor::MECOrchestratorMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MECOrchestratorMessage)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MECOrchestratorMessageDescriptor::~MECOrchestratorMessageDescriptor()
{
    delete[] propertyNames;
}

bool MECOrchestratorMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MECOrchestratorMessage *>(obj)!=nullptr;
}

const char **MECOrchestratorMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MECOrchestratorMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MECOrchestratorMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int MECOrchestratorMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_contextId
        FD_ISEDITABLE,    // FIELD_requestId
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_success
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *MECOrchestratorMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "contextId",
        "requestId",
        "type",
        "success",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int MECOrchestratorMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "contextId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "requestId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "success") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *MECOrchestratorMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_contextId
        "int",    // FIELD_requestId
        "string",    // FIELD_type
        "bool",    // FIELD_success
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **MECOrchestratorMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *MECOrchestratorMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MECOrchestratorMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MECOrchestratorMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MECOrchestratorMessage'", field);
    }
}

const char *MECOrchestratorMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MECOrchestratorMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: return long2string(pp->getContextId());
        case FIELD_requestId: return long2string(pp->getRequestId());
        case FIELD_type: return oppstring2string(pp->getType());
        case FIELD_success: return bool2string(pp->getSuccess());
        default: return "";
    }
}

void MECOrchestratorMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: pp->setContextId(string2long(value)); break;
        case FIELD_requestId: pp->setRequestId(string2long(value)); break;
        case FIELD_type: pp->setType((value)); break;
        case FIELD_success: pp->setSuccess(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MECOrchestratorMessage'", field);
    }
}

omnetpp::cValue MECOrchestratorMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: return pp->getContextId();
        case FIELD_requestId: return pp->getRequestId();
        case FIELD_type: return pp->getType();
        case FIELD_success: return pp->getSuccess();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MECOrchestratorMessage' as cValue -- field index out of range?", field);
    }
}

void MECOrchestratorMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: pp->setContextId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_requestId: pp->setRequestId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_type: pp->setType(value.stringValue()); break;
        case FIELD_success: pp->setSuccess(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MECOrchestratorMessage'", field);
    }
}

const char *MECOrchestratorMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MECOrchestratorMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MECOrchestratorMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MECOrchestratorMessage *pp = omnetpp::fromAnyPtr<MECOrchestratorMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MECOrchestratorMessage'", field);
    }
}

Register_Class(CreateAppMessage)

CreateAppMessage::CreateAppMessage() : ::inet::FieldsChunk()
{
}

CreateAppMessage::CreateAppMessage(const CreateAppMessage& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

CreateAppMessage::~CreateAppMessage()
{
}

CreateAppMessage& CreateAppMessage::operator=(const CreateAppMessage& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void CreateAppMessage::copy(const CreateAppMessage& other)
{
    this->sno = other.sno;
    this->timestamp = other.timestamp;
    this->type = other.type;
    this->sourceAddress = other.sourceAddress;
    this->sourcePort = other.sourcePort;
    this->destinationAddress = other.destinationAddress;
    this->destinationPort = other.destinationPort;
    this->destinationMecAppAddress = other.destinationMecAppAddress;
    this->destinationMecAppPort = other.destinationMecAppPort;
    this->MEModuleType = other.MEModuleType;
    this->MEModuleName = other.MEModuleName;
    this->contextId = other.contextId;
    this->ueAppID = other.ueAppID;
    this->requiredDisk = other.requiredDisk;
    this->requiredRam = other.requiredRam;
    this->requiredCpu = other.requiredCpu;
    this->requiredService = other.requiredService;
    this->providedService = other.providedService;
}

void CreateAppMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->sno);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->sourcePort);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->destinationPort);
    doParsimPacking(b,this->destinationMecAppAddress);
    doParsimPacking(b,this->destinationMecAppPort);
    doParsimPacking(b,this->MEModuleType);
    doParsimPacking(b,this->MEModuleName);
    doParsimPacking(b,this->contextId);
    doParsimPacking(b,this->ueAppID);
    doParsimPacking(b,this->requiredDisk);
    doParsimPacking(b,this->requiredRam);
    doParsimPacking(b,this->requiredCpu);
    doParsimPacking(b,this->requiredService);
    doParsimPacking(b,this->providedService);
}

void CreateAppMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sno);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->sourcePort);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->destinationPort);
    doParsimUnpacking(b,this->destinationMecAppAddress);
    doParsimUnpacking(b,this->destinationMecAppPort);
    doParsimUnpacking(b,this->MEModuleType);
    doParsimUnpacking(b,this->MEModuleName);
    doParsimUnpacking(b,this->contextId);
    doParsimUnpacking(b,this->ueAppID);
    doParsimUnpacking(b,this->requiredDisk);
    doParsimUnpacking(b,this->requiredRam);
    doParsimUnpacking(b,this->requiredCpu);
    doParsimUnpacking(b,this->requiredService);
    doParsimUnpacking(b,this->providedService);
}

unsigned int CreateAppMessage::getSno() const
{
    return this->sno;
}

void CreateAppMessage::setSno(unsigned int sno)
{
    handleChange();
    this->sno = sno;
}

omnetpp::simtime_t CreateAppMessage::getTimestamp() const
{
    return this->timestamp;
}

void CreateAppMessage::setTimestamp(omnetpp::simtime_t timestamp)
{
    handleChange();
    this->timestamp = timestamp;
}

const char * CreateAppMessage::getType() const
{
    return this->type.c_str();
}

void CreateAppMessage::setType(const char * type)
{
    handleChange();
    this->type = type;
}

const char * CreateAppMessage::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void CreateAppMessage::setSourceAddress(const char * sourceAddress)
{
    handleChange();
    this->sourceAddress = sourceAddress;
}

int CreateAppMessage::getSourcePort() const
{
    return this->sourcePort;
}

void CreateAppMessage::setSourcePort(int sourcePort)
{
    handleChange();
    this->sourcePort = sourcePort;
}

const char * CreateAppMessage::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void CreateAppMessage::setDestinationAddress(const char * destinationAddress)
{
    handleChange();
    this->destinationAddress = destinationAddress;
}

int CreateAppMessage::getDestinationPort() const
{
    return this->destinationPort;
}

void CreateAppMessage::setDestinationPort(int destinationPort)
{
    handleChange();
    this->destinationPort = destinationPort;
}

const char * CreateAppMessage::getDestinationMecAppAddress() const
{
    return this->destinationMecAppAddress.c_str();
}

void CreateAppMessage::setDestinationMecAppAddress(const char * destinationMecAppAddress)
{
    handleChange();
    this->destinationMecAppAddress = destinationMecAppAddress;
}

int CreateAppMessage::getDestinationMecAppPort() const
{
    return this->destinationMecAppPort;
}

void CreateAppMessage::setDestinationMecAppPort(int destinationMecAppPort)
{
    handleChange();
    this->destinationMecAppPort = destinationMecAppPort;
}

const char * CreateAppMessage::getMEModuleType() const
{
    return this->MEModuleType.c_str();
}

void CreateAppMessage::setMEModuleType(const char * MEModuleType)
{
    handleChange();
    this->MEModuleType = MEModuleType;
}

const char * CreateAppMessage::getMEModuleName() const
{
    return this->MEModuleName.c_str();
}

void CreateAppMessage::setMEModuleName(const char * MEModuleName)
{
    handleChange();
    this->MEModuleName = MEModuleName;
}

int CreateAppMessage::getContextId() const
{
    return this->contextId;
}

void CreateAppMessage::setContextId(int contextId)
{
    handleChange();
    this->contextId = contextId;
}

int CreateAppMessage::getUeAppID() const
{
    return this->ueAppID;
}

void CreateAppMessage::setUeAppID(int ueAppID)
{
    handleChange();
    this->ueAppID = ueAppID;
}

double CreateAppMessage::getRequiredDisk() const
{
    return this->requiredDisk;
}

void CreateAppMessage::setRequiredDisk(double requiredDisk)
{
    handleChange();
    this->requiredDisk = requiredDisk;
}

double CreateAppMessage::getRequiredRam() const
{
    return this->requiredRam;
}

void CreateAppMessage::setRequiredRam(double requiredRam)
{
    handleChange();
    this->requiredRam = requiredRam;
}

double CreateAppMessage::getRequiredCpu() const
{
    return this->requiredCpu;
}

void CreateAppMessage::setRequiredCpu(double requiredCpu)
{
    handleChange();
    this->requiredCpu = requiredCpu;
}

const char * CreateAppMessage::getRequiredService() const
{
    return this->requiredService.c_str();
}

void CreateAppMessage::setRequiredService(const char * requiredService)
{
    handleChange();
    this->requiredService = requiredService;
}

const char * CreateAppMessage::getProvidedService() const
{
    return this->providedService.c_str();
}

void CreateAppMessage::setProvidedService(const char * providedService)
{
    handleChange();
    this->providedService = providedService;
}

class CreateAppMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sno,
        FIELD_timestamp,
        FIELD_type,
        FIELD_sourceAddress,
        FIELD_sourcePort,
        FIELD_destinationAddress,
        FIELD_destinationPort,
        FIELD_destinationMecAppAddress,
        FIELD_destinationMecAppPort,
        FIELD_MEModuleType,
        FIELD_MEModuleName,
        FIELD_contextId,
        FIELD_ueAppID,
        FIELD_requiredDisk,
        FIELD_requiredRam,
        FIELD_requiredCpu,
        FIELD_requiredService,
        FIELD_providedService,
    };
  public:
    CreateAppMessageDescriptor();
    virtual ~CreateAppMessageDescriptor();

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

Register_ClassDescriptor(CreateAppMessageDescriptor)

CreateAppMessageDescriptor::CreateAppMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(CreateAppMessage)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

CreateAppMessageDescriptor::~CreateAppMessageDescriptor()
{
    delete[] propertyNames;
}

bool CreateAppMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CreateAppMessage *>(obj)!=nullptr;
}

const char **CreateAppMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CreateAppMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CreateAppMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 18+base->getFieldCount() : 18;
}

unsigned int CreateAppMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sno
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_sourceAddress
        FD_ISEDITABLE,    // FIELD_sourcePort
        FD_ISEDITABLE,    // FIELD_destinationAddress
        FD_ISEDITABLE,    // FIELD_destinationPort
        FD_ISEDITABLE,    // FIELD_destinationMecAppAddress
        FD_ISEDITABLE,    // FIELD_destinationMecAppPort
        FD_ISEDITABLE,    // FIELD_MEModuleType
        FD_ISEDITABLE,    // FIELD_MEModuleName
        FD_ISEDITABLE,    // FIELD_contextId
        FD_ISEDITABLE,    // FIELD_ueAppID
        FD_ISEDITABLE,    // FIELD_requiredDisk
        FD_ISEDITABLE,    // FIELD_requiredRam
        FD_ISEDITABLE,    // FIELD_requiredCpu
        FD_ISEDITABLE,    // FIELD_requiredService
        FD_ISEDITABLE,    // FIELD_providedService
    };
    return (field >= 0 && field < 18) ? fieldTypeFlags[field] : 0;
}

const char *CreateAppMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sno",
        "timestamp",
        "type",
        "sourceAddress",
        "sourcePort",
        "destinationAddress",
        "destinationPort",
        "destinationMecAppAddress",
        "destinationMecAppPort",
        "MEModuleType",
        "MEModuleName",
        "contextId",
        "ueAppID",
        "requiredDisk",
        "requiredRam",
        "requiredCpu",
        "requiredService",
        "providedService",
    };
    return (field >= 0 && field < 18) ? fieldNames[field] : nullptr;
}

int CreateAppMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sno") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sourceAddress") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sourcePort") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "destinationAddress") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "destinationPort") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "destinationMecAppAddress") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "destinationMecAppPort") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "MEModuleType") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "MEModuleName") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "contextId") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "ueAppID") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "requiredDisk") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "requiredRam") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "requiredCpu") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "requiredService") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "providedService") == 0) return baseIndex + 17;
    return base ? base->findField(fieldName) : -1;
}

const char *CreateAppMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_sno
        "omnetpp::simtime_t",    // FIELD_timestamp
        "string",    // FIELD_type
        "string",    // FIELD_sourceAddress
        "int",    // FIELD_sourcePort
        "string",    // FIELD_destinationAddress
        "int",    // FIELD_destinationPort
        "string",    // FIELD_destinationMecAppAddress
        "int",    // FIELD_destinationMecAppPort
        "string",    // FIELD_MEModuleType
        "string",    // FIELD_MEModuleName
        "int",    // FIELD_contextId
        "int",    // FIELD_ueAppID
        "double",    // FIELD_requiredDisk
        "double",    // FIELD_requiredRam
        "double",    // FIELD_requiredCpu
        "string",    // FIELD_requiredService
        "string",    // FIELD_providedService
    };
    return (field >= 0 && field < 18) ? fieldTypeStrings[field] : nullptr;
}

const char **CreateAppMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *CreateAppMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int CreateAppMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CreateAppMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CreateAppMessage'", field);
    }
}

const char *CreateAppMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CreateAppMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sno: return ulong2string(pp->getSno());
        case FIELD_timestamp: return simtime2string(pp->getTimestamp());
        case FIELD_type: return oppstring2string(pp->getType());
        case FIELD_sourceAddress: return oppstring2string(pp->getSourceAddress());
        case FIELD_sourcePort: return long2string(pp->getSourcePort());
        case FIELD_destinationAddress: return oppstring2string(pp->getDestinationAddress());
        case FIELD_destinationPort: return long2string(pp->getDestinationPort());
        case FIELD_destinationMecAppAddress: return oppstring2string(pp->getDestinationMecAppAddress());
        case FIELD_destinationMecAppPort: return long2string(pp->getDestinationMecAppPort());
        case FIELD_MEModuleType: return oppstring2string(pp->getMEModuleType());
        case FIELD_MEModuleName: return oppstring2string(pp->getMEModuleName());
        case FIELD_contextId: return long2string(pp->getContextId());
        case FIELD_ueAppID: return long2string(pp->getUeAppID());
        case FIELD_requiredDisk: return double2string(pp->getRequiredDisk());
        case FIELD_requiredRam: return double2string(pp->getRequiredRam());
        case FIELD_requiredCpu: return double2string(pp->getRequiredCpu());
        case FIELD_requiredService: return oppstring2string(pp->getRequiredService());
        case FIELD_providedService: return oppstring2string(pp->getProvidedService());
        default: return "";
    }
}

void CreateAppMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sno: pp->setSno(string2ulong(value)); break;
        case FIELD_timestamp: pp->setTimestamp(string2simtime(value)); break;
        case FIELD_type: pp->setType((value)); break;
        case FIELD_sourceAddress: pp->setSourceAddress((value)); break;
        case FIELD_sourcePort: pp->setSourcePort(string2long(value)); break;
        case FIELD_destinationAddress: pp->setDestinationAddress((value)); break;
        case FIELD_destinationPort: pp->setDestinationPort(string2long(value)); break;
        case FIELD_destinationMecAppAddress: pp->setDestinationMecAppAddress((value)); break;
        case FIELD_destinationMecAppPort: pp->setDestinationMecAppPort(string2long(value)); break;
        case FIELD_MEModuleType: pp->setMEModuleType((value)); break;
        case FIELD_MEModuleName: pp->setMEModuleName((value)); break;
        case FIELD_contextId: pp->setContextId(string2long(value)); break;
        case FIELD_ueAppID: pp->setUeAppID(string2long(value)); break;
        case FIELD_requiredDisk: pp->setRequiredDisk(string2double(value)); break;
        case FIELD_requiredRam: pp->setRequiredRam(string2double(value)); break;
        case FIELD_requiredCpu: pp->setRequiredCpu(string2double(value)); break;
        case FIELD_requiredService: pp->setRequiredService((value)); break;
        case FIELD_providedService: pp->setProvidedService((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateAppMessage'", field);
    }
}

omnetpp::cValue CreateAppMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sno: return (omnetpp::intval_t)(pp->getSno());
        case FIELD_timestamp: return pp->getTimestamp().dbl();
        case FIELD_type: return pp->getType();
        case FIELD_sourceAddress: return pp->getSourceAddress();
        case FIELD_sourcePort: return pp->getSourcePort();
        case FIELD_destinationAddress: return pp->getDestinationAddress();
        case FIELD_destinationPort: return pp->getDestinationPort();
        case FIELD_destinationMecAppAddress: return pp->getDestinationMecAppAddress();
        case FIELD_destinationMecAppPort: return pp->getDestinationMecAppPort();
        case FIELD_MEModuleType: return pp->getMEModuleType();
        case FIELD_MEModuleName: return pp->getMEModuleName();
        case FIELD_contextId: return pp->getContextId();
        case FIELD_ueAppID: return pp->getUeAppID();
        case FIELD_requiredDisk: return pp->getRequiredDisk();
        case FIELD_requiredRam: return pp->getRequiredRam();
        case FIELD_requiredCpu: return pp->getRequiredCpu();
        case FIELD_requiredService: return pp->getRequiredService();
        case FIELD_providedService: return pp->getProvidedService();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CreateAppMessage' as cValue -- field index out of range?", field);
    }
}

void CreateAppMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sno: pp->setSno(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_timestamp: pp->setTimestamp(value.doubleValue()); break;
        case FIELD_type: pp->setType(value.stringValue()); break;
        case FIELD_sourceAddress: pp->setSourceAddress(value.stringValue()); break;
        case FIELD_sourcePort: pp->setSourcePort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationAddress: pp->setDestinationAddress(value.stringValue()); break;
        case FIELD_destinationPort: pp->setDestinationPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationMecAppAddress: pp->setDestinationMecAppAddress(value.stringValue()); break;
        case FIELD_destinationMecAppPort: pp->setDestinationMecAppPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_MEModuleType: pp->setMEModuleType(value.stringValue()); break;
        case FIELD_MEModuleName: pp->setMEModuleName(value.stringValue()); break;
        case FIELD_contextId: pp->setContextId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ueAppID: pp->setUeAppID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_requiredDisk: pp->setRequiredDisk(value.doubleValue()); break;
        case FIELD_requiredRam: pp->setRequiredRam(value.doubleValue()); break;
        case FIELD_requiredCpu: pp->setRequiredCpu(value.doubleValue()); break;
        case FIELD_requiredService: pp->setRequiredService(value.stringValue()); break;
        case FIELD_providedService: pp->setProvidedService(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateAppMessage'", field);
    }
}

const char *CreateAppMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr CreateAppMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CreateAppMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateAppMessage *pp = omnetpp::fromAnyPtr<CreateAppMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateAppMessage'", field);
    }
}

Register_Class(DeleteAppMessage)

DeleteAppMessage::DeleteAppMessage() : ::inet::FieldsChunk()
{
}

DeleteAppMessage::DeleteAppMessage(const DeleteAppMessage& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

DeleteAppMessage::~DeleteAppMessage()
{
}

DeleteAppMessage& DeleteAppMessage::operator=(const DeleteAppMessage& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void DeleteAppMessage::copy(const DeleteAppMessage& other)
{
    this->sno = other.sno;
    this->timestamp = other.timestamp;
    this->type = other.type;
    this->sourceAddress = other.sourceAddress;
    this->sourcePort = other.sourcePort;
    this->destinationAddress = other.destinationAddress;
    this->destinationPort = other.destinationPort;
    this->destinationMecAppAddress = other.destinationMecAppAddress;
    this->destinationMecAppPort = other.destinationMecAppPort;
    this->MEModuleType = other.MEModuleType;
    this->MEModuleName = other.MEModuleName;
    this->ueAppID = other.ueAppID;
    this->requiredDisk = other.requiredDisk;
    this->requiredRam = other.requiredRam;
    this->requiredCpu = other.requiredCpu;
    this->requiredService = other.requiredService;
}

void DeleteAppMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->sno);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->sourcePort);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->destinationPort);
    doParsimPacking(b,this->destinationMecAppAddress);
    doParsimPacking(b,this->destinationMecAppPort);
    doParsimPacking(b,this->MEModuleType);
    doParsimPacking(b,this->MEModuleName);
    doParsimPacking(b,this->ueAppID);
    doParsimPacking(b,this->requiredDisk);
    doParsimPacking(b,this->requiredRam);
    doParsimPacking(b,this->requiredCpu);
    doParsimPacking(b,this->requiredService);
}

void DeleteAppMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sno);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->sourcePort);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->destinationPort);
    doParsimUnpacking(b,this->destinationMecAppAddress);
    doParsimUnpacking(b,this->destinationMecAppPort);
    doParsimUnpacking(b,this->MEModuleType);
    doParsimUnpacking(b,this->MEModuleName);
    doParsimUnpacking(b,this->ueAppID);
    doParsimUnpacking(b,this->requiredDisk);
    doParsimUnpacking(b,this->requiredRam);
    doParsimUnpacking(b,this->requiredCpu);
    doParsimUnpacking(b,this->requiredService);
}

unsigned int DeleteAppMessage::getSno() const
{
    return this->sno;
}

void DeleteAppMessage::setSno(unsigned int sno)
{
    handleChange();
    this->sno = sno;
}

omnetpp::simtime_t DeleteAppMessage::getTimestamp() const
{
    return this->timestamp;
}

void DeleteAppMessage::setTimestamp(omnetpp::simtime_t timestamp)
{
    handleChange();
    this->timestamp = timestamp;
}

const char * DeleteAppMessage::getType() const
{
    return this->type.c_str();
}

void DeleteAppMessage::setType(const char * type)
{
    handleChange();
    this->type = type;
}

const char * DeleteAppMessage::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void DeleteAppMessage::setSourceAddress(const char * sourceAddress)
{
    handleChange();
    this->sourceAddress = sourceAddress;
}

int DeleteAppMessage::getSourcePort() const
{
    return this->sourcePort;
}

void DeleteAppMessage::setSourcePort(int sourcePort)
{
    handleChange();
    this->sourcePort = sourcePort;
}

const char * DeleteAppMessage::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void DeleteAppMessage::setDestinationAddress(const char * destinationAddress)
{
    handleChange();
    this->destinationAddress = destinationAddress;
}

int DeleteAppMessage::getDestinationPort() const
{
    return this->destinationPort;
}

void DeleteAppMessage::setDestinationPort(int destinationPort)
{
    handleChange();
    this->destinationPort = destinationPort;
}

const char * DeleteAppMessage::getDestinationMecAppAddress() const
{
    return this->destinationMecAppAddress.c_str();
}

void DeleteAppMessage::setDestinationMecAppAddress(const char * destinationMecAppAddress)
{
    handleChange();
    this->destinationMecAppAddress = destinationMecAppAddress;
}

int DeleteAppMessage::getDestinationMecAppPort() const
{
    return this->destinationMecAppPort;
}

void DeleteAppMessage::setDestinationMecAppPort(int destinationMecAppPort)
{
    handleChange();
    this->destinationMecAppPort = destinationMecAppPort;
}

const char * DeleteAppMessage::getMEModuleType() const
{
    return this->MEModuleType.c_str();
}

void DeleteAppMessage::setMEModuleType(const char * MEModuleType)
{
    handleChange();
    this->MEModuleType = MEModuleType;
}

const char * DeleteAppMessage::getMEModuleName() const
{
    return this->MEModuleName.c_str();
}

void DeleteAppMessage::setMEModuleName(const char * MEModuleName)
{
    handleChange();
    this->MEModuleName = MEModuleName;
}

int DeleteAppMessage::getUeAppID() const
{
    return this->ueAppID;
}

void DeleteAppMessage::setUeAppID(int ueAppID)
{
    handleChange();
    this->ueAppID = ueAppID;
}

unsigned int DeleteAppMessage::getRequiredDisk() const
{
    return this->requiredDisk;
}

void DeleteAppMessage::setRequiredDisk(unsigned int requiredDisk)
{
    handleChange();
    this->requiredDisk = requiredDisk;
}

unsigned int DeleteAppMessage::getRequiredRam() const
{
    return this->requiredRam;
}

void DeleteAppMessage::setRequiredRam(unsigned int requiredRam)
{
    handleChange();
    this->requiredRam = requiredRam;
}

double DeleteAppMessage::getRequiredCpu() const
{
    return this->requiredCpu;
}

void DeleteAppMessage::setRequiredCpu(double requiredCpu)
{
    handleChange();
    this->requiredCpu = requiredCpu;
}

const char * DeleteAppMessage::getRequiredService() const
{
    return this->requiredService.c_str();
}

void DeleteAppMessage::setRequiredService(const char * requiredService)
{
    handleChange();
    this->requiredService = requiredService;
}

class DeleteAppMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sno,
        FIELD_timestamp,
        FIELD_type,
        FIELD_sourceAddress,
        FIELD_sourcePort,
        FIELD_destinationAddress,
        FIELD_destinationPort,
        FIELD_destinationMecAppAddress,
        FIELD_destinationMecAppPort,
        FIELD_MEModuleType,
        FIELD_MEModuleName,
        FIELD_ueAppID,
        FIELD_requiredDisk,
        FIELD_requiredRam,
        FIELD_requiredCpu,
        FIELD_requiredService,
    };
  public:
    DeleteAppMessageDescriptor();
    virtual ~DeleteAppMessageDescriptor();

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

Register_ClassDescriptor(DeleteAppMessageDescriptor)

DeleteAppMessageDescriptor::DeleteAppMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DeleteAppMessage)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

DeleteAppMessageDescriptor::~DeleteAppMessageDescriptor()
{
    delete[] propertyNames;
}

bool DeleteAppMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DeleteAppMessage *>(obj)!=nullptr;
}

const char **DeleteAppMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeleteAppMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeleteAppMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 16+base->getFieldCount() : 16;
}

unsigned int DeleteAppMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sno
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_sourceAddress
        FD_ISEDITABLE,    // FIELD_sourcePort
        FD_ISEDITABLE,    // FIELD_destinationAddress
        FD_ISEDITABLE,    // FIELD_destinationPort
        FD_ISEDITABLE,    // FIELD_destinationMecAppAddress
        FD_ISEDITABLE,    // FIELD_destinationMecAppPort
        FD_ISEDITABLE,    // FIELD_MEModuleType
        FD_ISEDITABLE,    // FIELD_MEModuleName
        FD_ISEDITABLE,    // FIELD_ueAppID
        FD_ISEDITABLE,    // FIELD_requiredDisk
        FD_ISEDITABLE,    // FIELD_requiredRam
        FD_ISEDITABLE,    // FIELD_requiredCpu
        FD_ISEDITABLE,    // FIELD_requiredService
    };
    return (field >= 0 && field < 16) ? fieldTypeFlags[field] : 0;
}

const char *DeleteAppMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sno",
        "timestamp",
        "type",
        "sourceAddress",
        "sourcePort",
        "destinationAddress",
        "destinationPort",
        "destinationMecAppAddress",
        "destinationMecAppPort",
        "MEModuleType",
        "MEModuleName",
        "ueAppID",
        "requiredDisk",
        "requiredRam",
        "requiredCpu",
        "requiredService",
    };
    return (field >= 0 && field < 16) ? fieldNames[field] : nullptr;
}

int DeleteAppMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sno") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sourceAddress") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sourcePort") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "destinationAddress") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "destinationPort") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "destinationMecAppAddress") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "destinationMecAppPort") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "MEModuleType") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "MEModuleName") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "ueAppID") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "requiredDisk") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "requiredRam") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "requiredCpu") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "requiredService") == 0) return baseIndex + 15;
    return base ? base->findField(fieldName) : -1;
}

const char *DeleteAppMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_sno
        "omnetpp::simtime_t",    // FIELD_timestamp
        "string",    // FIELD_type
        "string",    // FIELD_sourceAddress
        "int",    // FIELD_sourcePort
        "string",    // FIELD_destinationAddress
        "int",    // FIELD_destinationPort
        "string",    // FIELD_destinationMecAppAddress
        "int",    // FIELD_destinationMecAppPort
        "string",    // FIELD_MEModuleType
        "string",    // FIELD_MEModuleName
        "int",    // FIELD_ueAppID
        "unsigned int",    // FIELD_requiredDisk
        "unsigned int",    // FIELD_requiredRam
        "double",    // FIELD_requiredCpu
        "string",    // FIELD_requiredService
    };
    return (field >= 0 && field < 16) ? fieldTypeStrings[field] : nullptr;
}

const char **DeleteAppMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *DeleteAppMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeleteAppMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeleteAppMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DeleteAppMessage'", field);
    }
}

const char *DeleteAppMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeleteAppMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sno: return ulong2string(pp->getSno());
        case FIELD_timestamp: return simtime2string(pp->getTimestamp());
        case FIELD_type: return oppstring2string(pp->getType());
        case FIELD_sourceAddress: return oppstring2string(pp->getSourceAddress());
        case FIELD_sourcePort: return long2string(pp->getSourcePort());
        case FIELD_destinationAddress: return oppstring2string(pp->getDestinationAddress());
        case FIELD_destinationPort: return long2string(pp->getDestinationPort());
        case FIELD_destinationMecAppAddress: return oppstring2string(pp->getDestinationMecAppAddress());
        case FIELD_destinationMecAppPort: return long2string(pp->getDestinationMecAppPort());
        case FIELD_MEModuleType: return oppstring2string(pp->getMEModuleType());
        case FIELD_MEModuleName: return oppstring2string(pp->getMEModuleName());
        case FIELD_ueAppID: return long2string(pp->getUeAppID());
        case FIELD_requiredDisk: return ulong2string(pp->getRequiredDisk());
        case FIELD_requiredRam: return ulong2string(pp->getRequiredRam());
        case FIELD_requiredCpu: return double2string(pp->getRequiredCpu());
        case FIELD_requiredService: return oppstring2string(pp->getRequiredService());
        default: return "";
    }
}

void DeleteAppMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sno: pp->setSno(string2ulong(value)); break;
        case FIELD_timestamp: pp->setTimestamp(string2simtime(value)); break;
        case FIELD_type: pp->setType((value)); break;
        case FIELD_sourceAddress: pp->setSourceAddress((value)); break;
        case FIELD_sourcePort: pp->setSourcePort(string2long(value)); break;
        case FIELD_destinationAddress: pp->setDestinationAddress((value)); break;
        case FIELD_destinationPort: pp->setDestinationPort(string2long(value)); break;
        case FIELD_destinationMecAppAddress: pp->setDestinationMecAppAddress((value)); break;
        case FIELD_destinationMecAppPort: pp->setDestinationMecAppPort(string2long(value)); break;
        case FIELD_MEModuleType: pp->setMEModuleType((value)); break;
        case FIELD_MEModuleName: pp->setMEModuleName((value)); break;
        case FIELD_ueAppID: pp->setUeAppID(string2long(value)); break;
        case FIELD_requiredDisk: pp->setRequiredDisk(string2ulong(value)); break;
        case FIELD_requiredRam: pp->setRequiredRam(string2ulong(value)); break;
        case FIELD_requiredCpu: pp->setRequiredCpu(string2double(value)); break;
        case FIELD_requiredService: pp->setRequiredService((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteAppMessage'", field);
    }
}

omnetpp::cValue DeleteAppMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sno: return (omnetpp::intval_t)(pp->getSno());
        case FIELD_timestamp: return pp->getTimestamp().dbl();
        case FIELD_type: return pp->getType();
        case FIELD_sourceAddress: return pp->getSourceAddress();
        case FIELD_sourcePort: return pp->getSourcePort();
        case FIELD_destinationAddress: return pp->getDestinationAddress();
        case FIELD_destinationPort: return pp->getDestinationPort();
        case FIELD_destinationMecAppAddress: return pp->getDestinationMecAppAddress();
        case FIELD_destinationMecAppPort: return pp->getDestinationMecAppPort();
        case FIELD_MEModuleType: return pp->getMEModuleType();
        case FIELD_MEModuleName: return pp->getMEModuleName();
        case FIELD_ueAppID: return pp->getUeAppID();
        case FIELD_requiredDisk: return (omnetpp::intval_t)(pp->getRequiredDisk());
        case FIELD_requiredRam: return (omnetpp::intval_t)(pp->getRequiredRam());
        case FIELD_requiredCpu: return pp->getRequiredCpu();
        case FIELD_requiredService: return pp->getRequiredService();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DeleteAppMessage' as cValue -- field index out of range?", field);
    }
}

void DeleteAppMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sno: pp->setSno(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_timestamp: pp->setTimestamp(value.doubleValue()); break;
        case FIELD_type: pp->setType(value.stringValue()); break;
        case FIELD_sourceAddress: pp->setSourceAddress(value.stringValue()); break;
        case FIELD_sourcePort: pp->setSourcePort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationAddress: pp->setDestinationAddress(value.stringValue()); break;
        case FIELD_destinationPort: pp->setDestinationPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationMecAppAddress: pp->setDestinationMecAppAddress(value.stringValue()); break;
        case FIELD_destinationMecAppPort: pp->setDestinationMecAppPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_MEModuleType: pp->setMEModuleType(value.stringValue()); break;
        case FIELD_MEModuleName: pp->setMEModuleName(value.stringValue()); break;
        case FIELD_ueAppID: pp->setUeAppID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_requiredDisk: pp->setRequiredDisk(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_requiredRam: pp->setRequiredRam(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_requiredCpu: pp->setRequiredCpu(value.doubleValue()); break;
        case FIELD_requiredService: pp->setRequiredService(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteAppMessage'", field);
    }
}

const char *DeleteAppMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DeleteAppMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeleteAppMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteAppMessage *pp = omnetpp::fromAnyPtr<DeleteAppMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteAppMessage'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

