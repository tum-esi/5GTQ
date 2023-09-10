//
// Generated file, do not edit! Created by opp_msgtool 6.0 from nodes/mec/UALCMP/UALCMPMessages/UALCMPMessages.msg.
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
#include "UALCMPMessages_m.h"

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

Register_Class(UALCMPMessage)

UALCMPMessage::UALCMPMessage(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

UALCMPMessage::UALCMPMessage(const UALCMPMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

UALCMPMessage::~UALCMPMessage()
{
}

UALCMPMessage& UALCMPMessage::operator=(const UALCMPMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void UALCMPMessage::copy(const UALCMPMessage& other)
{
    this->type = other.type;
    this->connectionId = other.connectionId;
    this->requestId = other.requestId;
}

void UALCMPMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->connectionId);
    doParsimPacking(b,this->requestId);
}

void UALCMPMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->connectionId);
    doParsimUnpacking(b,this->requestId);
}

const char * UALCMPMessage::getType() const
{
    return this->type.c_str();
}

void UALCMPMessage::setType(const char * type)
{
    this->type = type;
}

int UALCMPMessage::getConnectionId() const
{
    return this->connectionId;
}

void UALCMPMessage::setConnectionId(int connectionId)
{
    this->connectionId = connectionId;
}

int UALCMPMessage::getRequestId() const
{
    return this->requestId;
}

void UALCMPMessage::setRequestId(int requestId)
{
    this->requestId = requestId;
}

class UALCMPMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_type,
        FIELD_connectionId,
        FIELD_requestId,
    };
  public:
    UALCMPMessageDescriptor();
    virtual ~UALCMPMessageDescriptor();

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

Register_ClassDescriptor(UALCMPMessageDescriptor)

UALCMPMessageDescriptor::UALCMPMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(UALCMPMessage)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

UALCMPMessageDescriptor::~UALCMPMessageDescriptor()
{
    delete[] propertyNames;
}

bool UALCMPMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UALCMPMessage *>(obj)!=nullptr;
}

const char **UALCMPMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UALCMPMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UALCMPMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int UALCMPMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_connectionId
        FD_ISEDITABLE,    // FIELD_requestId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *UALCMPMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "connectionId",
        "requestId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int UALCMPMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "connectionId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "requestId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *UALCMPMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_type
        "int",    // FIELD_connectionId
        "int",    // FIELD_requestId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **UALCMPMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *UALCMPMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int UALCMPMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UALCMPMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UALCMPMessage'", field);
    }
}

const char *UALCMPMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UALCMPMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        case FIELD_type: return oppstring2string(pp->getType());
        case FIELD_connectionId: return long2string(pp->getConnectionId());
        case FIELD_requestId: return long2string(pp->getRequestId());
        default: return "";
    }
}

void UALCMPMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->setType((value)); break;
        case FIELD_connectionId: pp->setConnectionId(string2long(value)); break;
        case FIELD_requestId: pp->setRequestId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UALCMPMessage'", field);
    }
}

omnetpp::cValue UALCMPMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        case FIELD_type: return pp->getType();
        case FIELD_connectionId: return pp->getConnectionId();
        case FIELD_requestId: return pp->getRequestId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UALCMPMessage' as cValue -- field index out of range?", field);
    }
}

void UALCMPMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(value.stringValue()); break;
        case FIELD_connectionId: pp->setConnectionId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_requestId: pp->setRequestId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UALCMPMessage'", field);
    }
}

const char *UALCMPMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr UALCMPMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UALCMPMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UALCMPMessage *pp = omnetpp::fromAnyPtr<UALCMPMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UALCMPMessage'", field);
    }
}

Register_Class(CreateContextApp)

CreateContextApp::CreateContextApp(const char *name, short kind) : ::UALCMPMessage(name, kind)
{
}

CreateContextApp::CreateContextApp(const CreateContextApp& other) : ::UALCMPMessage(other)
{
    copy(other);
}

CreateContextApp::~CreateContextApp()
{
}

CreateContextApp& CreateContextApp::operator=(const CreateContextApp& other)
{
    if (this == &other) return *this;
    ::UALCMPMessage::operator=(other);
    copy(other);
    return *this;
}

void CreateContextApp::copy(const CreateContextApp& other)
{
    this->onboarded = other.onboarded;
    this->appPackagePath = other.appPackagePath;
    this->appDId = other.appDId;
    this->ueIpAddress = other.ueIpAddress;
    this->devAppId = other.devAppId;
}

void CreateContextApp::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::UALCMPMessage::parsimPack(b);
    doParsimPacking(b,this->onboarded);
    doParsimPacking(b,this->appPackagePath);
    doParsimPacking(b,this->appDId);
    doParsimPacking(b,this->ueIpAddress);
    doParsimPacking(b,this->devAppId);
}

void CreateContextApp::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::UALCMPMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->onboarded);
    doParsimUnpacking(b,this->appPackagePath);
    doParsimUnpacking(b,this->appDId);
    doParsimUnpacking(b,this->ueIpAddress);
    doParsimUnpacking(b,this->devAppId);
}

bool CreateContextApp::getOnboarded() const
{
    return this->onboarded;
}

void CreateContextApp::setOnboarded(bool onboarded)
{
    this->onboarded = onboarded;
}

const char * CreateContextApp::getAppPackagePath() const
{
    return this->appPackagePath.c_str();
}

void CreateContextApp::setAppPackagePath(const char * appPackagePath)
{
    this->appPackagePath = appPackagePath;
}

const char * CreateContextApp::getAppDId() const
{
    return this->appDId.c_str();
}

void CreateContextApp::setAppDId(const char * appDId)
{
    this->appDId = appDId;
}

const char * CreateContextApp::getUeIpAddress() const
{
    return this->ueIpAddress.c_str();
}

void CreateContextApp::setUeIpAddress(const char * ueIpAddress)
{
    this->ueIpAddress = ueIpAddress;
}

const char * CreateContextApp::getDevAppId() const
{
    return this->devAppId.c_str();
}

void CreateContextApp::setDevAppId(const char * devAppId)
{
    this->devAppId = devAppId;
}

class CreateContextAppDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_onboarded,
        FIELD_appPackagePath,
        FIELD_appDId,
        FIELD_ueIpAddress,
        FIELD_devAppId,
    };
  public:
    CreateContextAppDescriptor();
    virtual ~CreateContextAppDescriptor();

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

Register_ClassDescriptor(CreateContextAppDescriptor)

CreateContextAppDescriptor::CreateContextAppDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(CreateContextApp)), "UALCMPMessage")
{
    propertyNames = nullptr;
}

CreateContextAppDescriptor::~CreateContextAppDescriptor()
{
    delete[] propertyNames;
}

bool CreateContextAppDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CreateContextApp *>(obj)!=nullptr;
}

const char **CreateContextAppDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CreateContextAppDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CreateContextAppDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int CreateContextAppDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_onboarded
        FD_ISEDITABLE,    // FIELD_appPackagePath
        FD_ISEDITABLE,    // FIELD_appDId
        FD_ISEDITABLE,    // FIELD_ueIpAddress
        FD_ISEDITABLE,    // FIELD_devAppId
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *CreateContextAppDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "onboarded",
        "appPackagePath",
        "appDId",
        "ueIpAddress",
        "devAppId",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int CreateContextAppDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "onboarded") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "appPackagePath") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "appDId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "ueIpAddress") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "devAppId") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *CreateContextAppDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_onboarded
        "string",    // FIELD_appPackagePath
        "string",    // FIELD_appDId
        "string",    // FIELD_ueIpAddress
        "string",    // FIELD_devAppId
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **CreateContextAppDescriptor::getFieldPropertyNames(int field) const
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

const char *CreateContextAppDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int CreateContextAppDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CreateContextAppDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CreateContextApp'", field);
    }
}

const char *CreateContextAppDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CreateContextAppDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        case FIELD_onboarded: return bool2string(pp->getOnboarded());
        case FIELD_appPackagePath: return oppstring2string(pp->getAppPackagePath());
        case FIELD_appDId: return oppstring2string(pp->getAppDId());
        case FIELD_ueIpAddress: return oppstring2string(pp->getUeIpAddress());
        case FIELD_devAppId: return oppstring2string(pp->getDevAppId());
        default: return "";
    }
}

void CreateContextAppDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        case FIELD_onboarded: pp->setOnboarded(string2bool(value)); break;
        case FIELD_appPackagePath: pp->setAppPackagePath((value)); break;
        case FIELD_appDId: pp->setAppDId((value)); break;
        case FIELD_ueIpAddress: pp->setUeIpAddress((value)); break;
        case FIELD_devAppId: pp->setDevAppId((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateContextApp'", field);
    }
}

omnetpp::cValue CreateContextAppDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        case FIELD_onboarded: return pp->getOnboarded();
        case FIELD_appPackagePath: return pp->getAppPackagePath();
        case FIELD_appDId: return pp->getAppDId();
        case FIELD_ueIpAddress: return pp->getUeIpAddress();
        case FIELD_devAppId: return pp->getDevAppId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CreateContextApp' as cValue -- field index out of range?", field);
    }
}

void CreateContextAppDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        case FIELD_onboarded: pp->setOnboarded(value.boolValue()); break;
        case FIELD_appPackagePath: pp->setAppPackagePath(value.stringValue()); break;
        case FIELD_appDId: pp->setAppDId(value.stringValue()); break;
        case FIELD_ueIpAddress: pp->setUeIpAddress(value.stringValue()); break;
        case FIELD_devAppId: pp->setDevAppId(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateContextApp'", field);
    }
}

const char *CreateContextAppDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr CreateContextAppDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CreateContextAppDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateContextApp *pp = omnetpp::fromAnyPtr<CreateContextApp>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateContextApp'", field);
    }
}

Register_Class(CreateContextAppAck)

CreateContextAppAck::CreateContextAppAck(const char *name, short kind) : ::UALCMPMessage(name, kind)
{
}

CreateContextAppAck::CreateContextAppAck(const CreateContextAppAck& other) : ::UALCMPMessage(other)
{
    copy(other);
}

CreateContextAppAck::~CreateContextAppAck()
{
}

CreateContextAppAck& CreateContextAppAck::operator=(const CreateContextAppAck& other)
{
    if (this == &other) return *this;
    ::UALCMPMessage::operator=(other);
    copy(other);
    return *this;
}

void CreateContextAppAck::copy(const CreateContextAppAck& other)
{
    this->success = other.success;
    this->appInstanceUri = other.appInstanceUri;
    this->appInstanceId = other.appInstanceId;
    this->contextId = other.contextId;
}

void CreateContextAppAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::UALCMPMessage::parsimPack(b);
    doParsimPacking(b,this->success);
    doParsimPacking(b,this->appInstanceUri);
    doParsimPacking(b,this->appInstanceId);
    doParsimPacking(b,this->contextId);
}

void CreateContextAppAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::UALCMPMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->success);
    doParsimUnpacking(b,this->appInstanceUri);
    doParsimUnpacking(b,this->appInstanceId);
    doParsimUnpacking(b,this->contextId);
}

bool CreateContextAppAck::getSuccess() const
{
    return this->success;
}

void CreateContextAppAck::setSuccess(bool success)
{
    this->success = success;
}

const char * CreateContextAppAck::getAppInstanceUri() const
{
    return this->appInstanceUri.c_str();
}

void CreateContextAppAck::setAppInstanceUri(const char * appInstanceUri)
{
    this->appInstanceUri = appInstanceUri;
}

const char * CreateContextAppAck::getAppInstanceId() const
{
    return this->appInstanceId.c_str();
}

void CreateContextAppAck::setAppInstanceId(const char * appInstanceId)
{
    this->appInstanceId = appInstanceId;
}

int CreateContextAppAck::getContextId() const
{
    return this->contextId;
}

void CreateContextAppAck::setContextId(int contextId)
{
    this->contextId = contextId;
}

class CreateContextAppAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_success,
        FIELD_appInstanceUri,
        FIELD_appInstanceId,
        FIELD_contextId,
    };
  public:
    CreateContextAppAckDescriptor();
    virtual ~CreateContextAppAckDescriptor();

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

Register_ClassDescriptor(CreateContextAppAckDescriptor)

CreateContextAppAckDescriptor::CreateContextAppAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(CreateContextAppAck)), "UALCMPMessage")
{
    propertyNames = nullptr;
}

CreateContextAppAckDescriptor::~CreateContextAppAckDescriptor()
{
    delete[] propertyNames;
}

bool CreateContextAppAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CreateContextAppAck *>(obj)!=nullptr;
}

const char **CreateContextAppAckDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CreateContextAppAckDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CreateContextAppAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int CreateContextAppAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_success
        FD_ISEDITABLE,    // FIELD_appInstanceUri
        FD_ISEDITABLE,    // FIELD_appInstanceId
        FD_ISEDITABLE,    // FIELD_contextId
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *CreateContextAppAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "success",
        "appInstanceUri",
        "appInstanceId",
        "contextId",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int CreateContextAppAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "success") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "appInstanceUri") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "appInstanceId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "contextId") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *CreateContextAppAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_success
        "string",    // FIELD_appInstanceUri
        "string",    // FIELD_appInstanceId
        "int",    // FIELD_contextId
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **CreateContextAppAckDescriptor::getFieldPropertyNames(int field) const
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

const char *CreateContextAppAckDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int CreateContextAppAckDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CreateContextAppAckDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CreateContextAppAck'", field);
    }
}

const char *CreateContextAppAckDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CreateContextAppAckDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        case FIELD_success: return bool2string(pp->getSuccess());
        case FIELD_appInstanceUri: return oppstring2string(pp->getAppInstanceUri());
        case FIELD_appInstanceId: return oppstring2string(pp->getAppInstanceId());
        case FIELD_contextId: return long2string(pp->getContextId());
        default: return "";
    }
}

void CreateContextAppAckDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        case FIELD_success: pp->setSuccess(string2bool(value)); break;
        case FIELD_appInstanceUri: pp->setAppInstanceUri((value)); break;
        case FIELD_appInstanceId: pp->setAppInstanceId((value)); break;
        case FIELD_contextId: pp->setContextId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateContextAppAck'", field);
    }
}

omnetpp::cValue CreateContextAppAckDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        case FIELD_success: return pp->getSuccess();
        case FIELD_appInstanceUri: return pp->getAppInstanceUri();
        case FIELD_appInstanceId: return pp->getAppInstanceId();
        case FIELD_contextId: return pp->getContextId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CreateContextAppAck' as cValue -- field index out of range?", field);
    }
}

void CreateContextAppAckDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        case FIELD_success: pp->setSuccess(value.boolValue()); break;
        case FIELD_appInstanceUri: pp->setAppInstanceUri(value.stringValue()); break;
        case FIELD_appInstanceId: pp->setAppInstanceId(value.stringValue()); break;
        case FIELD_contextId: pp->setContextId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateContextAppAck'", field);
    }
}

const char *CreateContextAppAckDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr CreateContextAppAckDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CreateContextAppAckDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CreateContextAppAck *pp = omnetpp::fromAnyPtr<CreateContextAppAck>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CreateContextAppAck'", field);
    }
}

Register_Class(DeleteContextAppMessage)

DeleteContextAppMessage::DeleteContextAppMessage(const char *name, short kind) : ::UALCMPMessage(name, kind)
{
}

DeleteContextAppMessage::DeleteContextAppMessage(const DeleteContextAppMessage& other) : ::UALCMPMessage(other)
{
    copy(other);
}

DeleteContextAppMessage::~DeleteContextAppMessage()
{
}

DeleteContextAppMessage& DeleteContextAppMessage::operator=(const DeleteContextAppMessage& other)
{
    if (this == &other) return *this;
    ::UALCMPMessage::operator=(other);
    copy(other);
    return *this;
}

void DeleteContextAppMessage::copy(const DeleteContextAppMessage& other)
{
    this->contextId = other.contextId;
}

void DeleteContextAppMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::UALCMPMessage::parsimPack(b);
    doParsimPacking(b,this->contextId);
}

void DeleteContextAppMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::UALCMPMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->contextId);
}

int DeleteContextAppMessage::getContextId() const
{
    return this->contextId;
}

void DeleteContextAppMessage::setContextId(int contextId)
{
    this->contextId = contextId;
}

class DeleteContextAppMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_contextId,
    };
  public:
    DeleteContextAppMessageDescriptor();
    virtual ~DeleteContextAppMessageDescriptor();

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

Register_ClassDescriptor(DeleteContextAppMessageDescriptor)

DeleteContextAppMessageDescriptor::DeleteContextAppMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DeleteContextAppMessage)), "UALCMPMessage")
{
    propertyNames = nullptr;
}

DeleteContextAppMessageDescriptor::~DeleteContextAppMessageDescriptor()
{
    delete[] propertyNames;
}

bool DeleteContextAppMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DeleteContextAppMessage *>(obj)!=nullptr;
}

const char **DeleteContextAppMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeleteContextAppMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeleteContextAppMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int DeleteContextAppMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_contextId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *DeleteContextAppMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "contextId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int DeleteContextAppMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "contextId") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *DeleteContextAppMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_contextId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **DeleteContextAppMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *DeleteContextAppMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeleteContextAppMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeleteContextAppMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DeleteContextAppMessage'", field);
    }
}

const char *DeleteContextAppMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeleteContextAppMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: return long2string(pp->getContextId());
        default: return "";
    }
}

void DeleteContextAppMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: pp->setContextId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteContextAppMessage'", field);
    }
}

omnetpp::cValue DeleteContextAppMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: return pp->getContextId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DeleteContextAppMessage' as cValue -- field index out of range?", field);
    }
}

void DeleteContextAppMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: pp->setContextId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteContextAppMessage'", field);
    }
}

const char *DeleteContextAppMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DeleteContextAppMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeleteContextAppMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteContextAppMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteContextAppMessage'", field);
    }
}

Register_Class(DeleteContextAppAckMessage)

DeleteContextAppAckMessage::DeleteContextAppAckMessage(const char *name, short kind) : ::UALCMPMessage(name, kind)
{
}

DeleteContextAppAckMessage::DeleteContextAppAckMessage(const DeleteContextAppAckMessage& other) : ::UALCMPMessage(other)
{
    copy(other);
}

DeleteContextAppAckMessage::~DeleteContextAppAckMessage()
{
}

DeleteContextAppAckMessage& DeleteContextAppAckMessage::operator=(const DeleteContextAppAckMessage& other)
{
    if (this == &other) return *this;
    ::UALCMPMessage::operator=(other);
    copy(other);
    return *this;
}

void DeleteContextAppAckMessage::copy(const DeleteContextAppAckMessage& other)
{
    this->success = other.success;
    this->contextId = other.contextId;
}

void DeleteContextAppAckMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::UALCMPMessage::parsimPack(b);
    doParsimPacking(b,this->success);
    doParsimPacking(b,this->contextId);
}

void DeleteContextAppAckMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::UALCMPMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->success);
    doParsimUnpacking(b,this->contextId);
}

bool DeleteContextAppAckMessage::getSuccess() const
{
    return this->success;
}

void DeleteContextAppAckMessage::setSuccess(bool success)
{
    this->success = success;
}

int DeleteContextAppAckMessage::getContextId() const
{
    return this->contextId;
}

void DeleteContextAppAckMessage::setContextId(int contextId)
{
    this->contextId = contextId;
}

class DeleteContextAppAckMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_success,
        FIELD_contextId,
    };
  public:
    DeleteContextAppAckMessageDescriptor();
    virtual ~DeleteContextAppAckMessageDescriptor();

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

Register_ClassDescriptor(DeleteContextAppAckMessageDescriptor)

DeleteContextAppAckMessageDescriptor::DeleteContextAppAckMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DeleteContextAppAckMessage)), "UALCMPMessage")
{
    propertyNames = nullptr;
}

DeleteContextAppAckMessageDescriptor::~DeleteContextAppAckMessageDescriptor()
{
    delete[] propertyNames;
}

bool DeleteContextAppAckMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DeleteContextAppAckMessage *>(obj)!=nullptr;
}

const char **DeleteContextAppAckMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeleteContextAppAckMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeleteContextAppAckMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int DeleteContextAppAckMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_success
        FD_ISEDITABLE,    // FIELD_contextId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *DeleteContextAppAckMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "success",
        "contextId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int DeleteContextAppAckMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "success") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "contextId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *DeleteContextAppAckMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_success
        "int",    // FIELD_contextId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **DeleteContextAppAckMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *DeleteContextAppAckMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeleteContextAppAckMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeleteContextAppAckMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DeleteContextAppAckMessage'", field);
    }
}

const char *DeleteContextAppAckMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeleteContextAppAckMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        case FIELD_success: return bool2string(pp->getSuccess());
        case FIELD_contextId: return long2string(pp->getContextId());
        default: return "";
    }
}

void DeleteContextAppAckMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        case FIELD_success: pp->setSuccess(string2bool(value)); break;
        case FIELD_contextId: pp->setContextId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteContextAppAckMessage'", field);
    }
}

omnetpp::cValue DeleteContextAppAckMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        case FIELD_success: return pp->getSuccess();
        case FIELD_contextId: return pp->getContextId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DeleteContextAppAckMessage' as cValue -- field index out of range?", field);
    }
}

void DeleteContextAppAckMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        case FIELD_success: pp->setSuccess(value.boolValue()); break;
        case FIELD_contextId: pp->setContextId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteContextAppAckMessage'", field);
    }
}

const char *DeleteContextAppAckMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DeleteContextAppAckMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeleteContextAppAckMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DeleteContextAppAckMessage *pp = omnetpp::fromAnyPtr<DeleteContextAppAckMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeleteContextAppAckMessage'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

