//
// Generated file, do not edit! Created by opp_msgtool 6.0 from apps/mec/DeviceApp/DeviceAppMessages/DeviceAppPacket.msg.
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
#include "DeviceAppPacket_m.h"

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

Register_Class(DeviceAppPacket)

DeviceAppPacket::DeviceAppPacket() : ::MECPacket()
{
}

DeviceAppPacket::DeviceAppPacket(const DeviceAppPacket& other) : ::MECPacket(other)
{
    copy(other);
}

DeviceAppPacket::~DeviceAppPacket()
{
}

DeviceAppPacket& DeviceAppPacket::operator=(const DeviceAppPacket& other)
{
    if (this == &other) return *this;
    ::MECPacket::operator=(other);
    copy(other);
    return *this;
}

void DeviceAppPacket::copy(const DeviceAppPacket& other)
{
}

void DeviceAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MECPacket::parsimPack(b);
}

void DeviceAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MECPacket::parsimUnpack(b);
}

class DeviceAppPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    DeviceAppPacketDescriptor();
    virtual ~DeviceAppPacketDescriptor();

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

Register_ClassDescriptor(DeviceAppPacketDescriptor)

DeviceAppPacketDescriptor::DeviceAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DeviceAppPacket)), "MECPacket")
{
    propertyNames = nullptr;
}

DeviceAppPacketDescriptor::~DeviceAppPacketDescriptor()
{
    delete[] propertyNames;
}

bool DeviceAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DeviceAppPacket *>(obj)!=nullptr;
}

const char **DeviceAppPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeviceAppPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeviceAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int DeviceAppPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *DeviceAppPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int DeviceAppPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *DeviceAppPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **DeviceAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *DeviceAppPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeviceAppPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeviceAppPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DeviceAppPacket'", field);
    }
}

const char *DeviceAppPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeviceAppPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void DeviceAppPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppPacket'", field);
    }
}

omnetpp::cValue DeviceAppPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DeviceAppPacket' as cValue -- field index out of range?", field);
    }
}

void DeviceAppPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppPacket'", field);
    }
}

const char *DeviceAppPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr DeviceAppPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeviceAppPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppPacket *pp = omnetpp::fromAnyPtr<DeviceAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppPacket'", field);
    }
}

Register_Class(DeviceAppStartPacket)

DeviceAppStartPacket::DeviceAppStartPacket() : ::DeviceAppPacket()
{
}

DeviceAppStartPacket::DeviceAppStartPacket(const DeviceAppStartPacket& other) : ::DeviceAppPacket(other)
{
    copy(other);
}

DeviceAppStartPacket::~DeviceAppStartPacket()
{
}

DeviceAppStartPacket& DeviceAppStartPacket::operator=(const DeviceAppStartPacket& other)
{
    if (this == &other) return *this;
    ::DeviceAppPacket::operator=(other);
    copy(other);
    return *this;
}

void DeviceAppStartPacket::copy(const DeviceAppStartPacket& other)
{
    this->mecAppDId = other.mecAppDId;
    this->mecAppName = other.mecAppName;
    this->mecAppProvider = other.mecAppProvider;
    this->appPackageSource = other.appPackageSource;
}

void DeviceAppStartPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::DeviceAppPacket::parsimPack(b);
    doParsimPacking(b,this->mecAppDId);
    doParsimPacking(b,this->mecAppName);
    doParsimPacking(b,this->mecAppProvider);
    doParsimPacking(b,this->appPackageSource);
}

void DeviceAppStartPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::DeviceAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->mecAppDId);
    doParsimUnpacking(b,this->mecAppName);
    doParsimUnpacking(b,this->mecAppProvider);
    doParsimUnpacking(b,this->appPackageSource);
}

const char * DeviceAppStartPacket::getMecAppDId() const
{
    return this->mecAppDId.c_str();
}

void DeviceAppStartPacket::setMecAppDId(const char * mecAppDId)
{
    handleChange();
    this->mecAppDId = mecAppDId;
}

const char * DeviceAppStartPacket::getMecAppName() const
{
    return this->mecAppName.c_str();
}

void DeviceAppStartPacket::setMecAppName(const char * mecAppName)
{
    handleChange();
    this->mecAppName = mecAppName;
}

const char * DeviceAppStartPacket::getMecAppProvider() const
{
    return this->mecAppProvider.c_str();
}

void DeviceAppStartPacket::setMecAppProvider(const char * mecAppProvider)
{
    handleChange();
    this->mecAppProvider = mecAppProvider;
}

const char * DeviceAppStartPacket::getAppPackageSource() const
{
    return this->appPackageSource.c_str();
}

void DeviceAppStartPacket::setAppPackageSource(const char * appPackageSource)
{
    handleChange();
    this->appPackageSource = appPackageSource;
}

class DeviceAppStartPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_mecAppDId,
        FIELD_mecAppName,
        FIELD_mecAppProvider,
        FIELD_appPackageSource,
    };
  public:
    DeviceAppStartPacketDescriptor();
    virtual ~DeviceAppStartPacketDescriptor();

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

Register_ClassDescriptor(DeviceAppStartPacketDescriptor)

DeviceAppStartPacketDescriptor::DeviceAppStartPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DeviceAppStartPacket)), "DeviceAppPacket")
{
    propertyNames = nullptr;
}

DeviceAppStartPacketDescriptor::~DeviceAppStartPacketDescriptor()
{
    delete[] propertyNames;
}

bool DeviceAppStartPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DeviceAppStartPacket *>(obj)!=nullptr;
}

const char **DeviceAppStartPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeviceAppStartPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeviceAppStartPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int DeviceAppStartPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_mecAppDId
        FD_ISEDITABLE,    // FIELD_mecAppName
        FD_ISEDITABLE,    // FIELD_mecAppProvider
        FD_ISEDITABLE,    // FIELD_appPackageSource
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *DeviceAppStartPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "mecAppDId",
        "mecAppName",
        "mecAppProvider",
        "appPackageSource",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int DeviceAppStartPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "mecAppDId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "mecAppName") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "mecAppProvider") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "appPackageSource") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *DeviceAppStartPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_mecAppDId
        "string",    // FIELD_mecAppName
        "string",    // FIELD_mecAppProvider
        "string",    // FIELD_appPackageSource
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **DeviceAppStartPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *DeviceAppStartPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeviceAppStartPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeviceAppStartPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DeviceAppStartPacket'", field);
    }
}

const char *DeviceAppStartPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeviceAppStartPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        case FIELD_mecAppDId: return oppstring2string(pp->getMecAppDId());
        case FIELD_mecAppName: return oppstring2string(pp->getMecAppName());
        case FIELD_mecAppProvider: return oppstring2string(pp->getMecAppProvider());
        case FIELD_appPackageSource: return oppstring2string(pp->getAppPackageSource());
        default: return "";
    }
}

void DeviceAppStartPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        case FIELD_mecAppDId: pp->setMecAppDId((value)); break;
        case FIELD_mecAppName: pp->setMecAppName((value)); break;
        case FIELD_mecAppProvider: pp->setMecAppProvider((value)); break;
        case FIELD_appPackageSource: pp->setAppPackageSource((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStartPacket'", field);
    }
}

omnetpp::cValue DeviceAppStartPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        case FIELD_mecAppDId: return pp->getMecAppDId();
        case FIELD_mecAppName: return pp->getMecAppName();
        case FIELD_mecAppProvider: return pp->getMecAppProvider();
        case FIELD_appPackageSource: return pp->getAppPackageSource();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DeviceAppStartPacket' as cValue -- field index out of range?", field);
    }
}

void DeviceAppStartPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        case FIELD_mecAppDId: pp->setMecAppDId(value.stringValue()); break;
        case FIELD_mecAppName: pp->setMecAppName(value.stringValue()); break;
        case FIELD_mecAppProvider: pp->setMecAppProvider(value.stringValue()); break;
        case FIELD_appPackageSource: pp->setAppPackageSource(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStartPacket'", field);
    }
}

const char *DeviceAppStartPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DeviceAppStartPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeviceAppStartPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStartPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStartPacket'", field);
    }
}

Register_Class(DeviceAppStopPacket)

DeviceAppStopPacket::DeviceAppStopPacket() : ::DeviceAppPacket()
{
}

DeviceAppStopPacket::DeviceAppStopPacket(const DeviceAppStopPacket& other) : ::DeviceAppPacket(other)
{
    copy(other);
}

DeviceAppStopPacket::~DeviceAppStopPacket()
{
}

DeviceAppStopPacket& DeviceAppStopPacket::operator=(const DeviceAppStopPacket& other)
{
    if (this == &other) return *this;
    ::DeviceAppPacket::operator=(other);
    copy(other);
    return *this;
}

void DeviceAppStopPacket::copy(const DeviceAppStopPacket& other)
{
    this->contextId = other.contextId;
}

void DeviceAppStopPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::DeviceAppPacket::parsimPack(b);
    doParsimPacking(b,this->contextId);
}

void DeviceAppStopPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::DeviceAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->contextId);
}

const char * DeviceAppStopPacket::getContextId() const
{
    return this->contextId.c_str();
}

void DeviceAppStopPacket::setContextId(const char * contextId)
{
    handleChange();
    this->contextId = contextId;
}

class DeviceAppStopPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_contextId,
    };
  public:
    DeviceAppStopPacketDescriptor();
    virtual ~DeviceAppStopPacketDescriptor();

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

Register_ClassDescriptor(DeviceAppStopPacketDescriptor)

DeviceAppStopPacketDescriptor::DeviceAppStopPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DeviceAppStopPacket)), "DeviceAppPacket")
{
    propertyNames = nullptr;
}

DeviceAppStopPacketDescriptor::~DeviceAppStopPacketDescriptor()
{
    delete[] propertyNames;
}

bool DeviceAppStopPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DeviceAppStopPacket *>(obj)!=nullptr;
}

const char **DeviceAppStopPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeviceAppStopPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeviceAppStopPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int DeviceAppStopPacketDescriptor::getFieldTypeFlags(int field) const
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

const char *DeviceAppStopPacketDescriptor::getFieldName(int field) const
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

int DeviceAppStopPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "contextId") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *DeviceAppStopPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_contextId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **DeviceAppStopPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *DeviceAppStopPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeviceAppStopPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeviceAppStopPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DeviceAppStopPacket'", field);
    }
}

const char *DeviceAppStopPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeviceAppStopPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: return oppstring2string(pp->getContextId());
        default: return "";
    }
}

void DeviceAppStopPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: pp->setContextId((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStopPacket'", field);
    }
}

omnetpp::cValue DeviceAppStopPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: return pp->getContextId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DeviceAppStopPacket' as cValue -- field index out of range?", field);
    }
}

void DeviceAppStopPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: pp->setContextId(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStopPacket'", field);
    }
}

const char *DeviceAppStopPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DeviceAppStopPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeviceAppStopPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStopPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStopPacket'", field);
    }
}

Register_Class(DeviceAppStartAckPacket)

DeviceAppStartAckPacket::DeviceAppStartAckPacket() : ::DeviceAppPacket()
{
}

DeviceAppStartAckPacket::DeviceAppStartAckPacket(const DeviceAppStartAckPacket& other) : ::DeviceAppPacket(other)
{
    copy(other);
}

DeviceAppStartAckPacket::~DeviceAppStartAckPacket()
{
}

DeviceAppStartAckPacket& DeviceAppStartAckPacket::operator=(const DeviceAppStartAckPacket& other)
{
    if (this == &other) return *this;
    ::DeviceAppPacket::operator=(other);
    copy(other);
    return *this;
}

void DeviceAppStartAckPacket::copy(const DeviceAppStartAckPacket& other)
{
    this->contextId = other.contextId;
    this->result = other.result;
    this->ipAddress = other.ipAddress;
    this->reason = other.reason;
    this->port = other.port;
}

void DeviceAppStartAckPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::DeviceAppPacket::parsimPack(b);
    doParsimPacking(b,this->contextId);
    doParsimPacking(b,this->result);
    doParsimPacking(b,this->ipAddress);
    doParsimPacking(b,this->reason);
    doParsimPacking(b,this->port);
}

void DeviceAppStartAckPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::DeviceAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->contextId);
    doParsimUnpacking(b,this->result);
    doParsimUnpacking(b,this->ipAddress);
    doParsimUnpacking(b,this->reason);
    doParsimUnpacking(b,this->port);
}

const char * DeviceAppStartAckPacket::getContextId() const
{
    return this->contextId.c_str();
}

void DeviceAppStartAckPacket::setContextId(const char * contextId)
{
    handleChange();
    this->contextId = contextId;
}

bool DeviceAppStartAckPacket::getResult() const
{
    return this->result;
}

void DeviceAppStartAckPacket::setResult(bool result)
{
    handleChange();
    this->result = result;
}

const char * DeviceAppStartAckPacket::getIpAddress() const
{
    return this->ipAddress.c_str();
}

void DeviceAppStartAckPacket::setIpAddress(const char * ipAddress)
{
    handleChange();
    this->ipAddress = ipAddress;
}

const char * DeviceAppStartAckPacket::getReason() const
{
    return this->reason.c_str();
}

void DeviceAppStartAckPacket::setReason(const char * reason)
{
    handleChange();
    this->reason = reason;
}

int DeviceAppStartAckPacket::getPort() const
{
    return this->port;
}

void DeviceAppStartAckPacket::setPort(int port)
{
    handleChange();
    this->port = port;
}

class DeviceAppStartAckPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_contextId,
        FIELD_result,
        FIELD_ipAddress,
        FIELD_reason,
        FIELD_port,
    };
  public:
    DeviceAppStartAckPacketDescriptor();
    virtual ~DeviceAppStartAckPacketDescriptor();

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

Register_ClassDescriptor(DeviceAppStartAckPacketDescriptor)

DeviceAppStartAckPacketDescriptor::DeviceAppStartAckPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DeviceAppStartAckPacket)), "DeviceAppPacket")
{
    propertyNames = nullptr;
}

DeviceAppStartAckPacketDescriptor::~DeviceAppStartAckPacketDescriptor()
{
    delete[] propertyNames;
}

bool DeviceAppStartAckPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DeviceAppStartAckPacket *>(obj)!=nullptr;
}

const char **DeviceAppStartAckPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeviceAppStartAckPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeviceAppStartAckPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int DeviceAppStartAckPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_contextId
        FD_ISEDITABLE,    // FIELD_result
        FD_ISEDITABLE,    // FIELD_ipAddress
        FD_ISEDITABLE,    // FIELD_reason
        FD_ISEDITABLE,    // FIELD_port
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *DeviceAppStartAckPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "contextId",
        "result",
        "ipAddress",
        "reason",
        "port",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int DeviceAppStartAckPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "contextId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "result") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ipAddress") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "reason") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "port") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *DeviceAppStartAckPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_contextId
        "bool",    // FIELD_result
        "string",    // FIELD_ipAddress
        "string",    // FIELD_reason
        "int",    // FIELD_port
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **DeviceAppStartAckPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *DeviceAppStartAckPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeviceAppStartAckPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeviceAppStartAckPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DeviceAppStartAckPacket'", field);
    }
}

const char *DeviceAppStartAckPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeviceAppStartAckPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: return oppstring2string(pp->getContextId());
        case FIELD_result: return bool2string(pp->getResult());
        case FIELD_ipAddress: return oppstring2string(pp->getIpAddress());
        case FIELD_reason: return oppstring2string(pp->getReason());
        case FIELD_port: return long2string(pp->getPort());
        default: return "";
    }
}

void DeviceAppStartAckPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: pp->setContextId((value)); break;
        case FIELD_result: pp->setResult(string2bool(value)); break;
        case FIELD_ipAddress: pp->setIpAddress((value)); break;
        case FIELD_reason: pp->setReason((value)); break;
        case FIELD_port: pp->setPort(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStartAckPacket'", field);
    }
}

omnetpp::cValue DeviceAppStartAckPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: return pp->getContextId();
        case FIELD_result: return pp->getResult();
        case FIELD_ipAddress: return pp->getIpAddress();
        case FIELD_reason: return pp->getReason();
        case FIELD_port: return pp->getPort();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DeviceAppStartAckPacket' as cValue -- field index out of range?", field);
    }
}

void DeviceAppStartAckPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        case FIELD_contextId: pp->setContextId(value.stringValue()); break;
        case FIELD_result: pp->setResult(value.boolValue()); break;
        case FIELD_ipAddress: pp->setIpAddress(value.stringValue()); break;
        case FIELD_reason: pp->setReason(value.stringValue()); break;
        case FIELD_port: pp->setPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStartAckPacket'", field);
    }
}

const char *DeviceAppStartAckPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DeviceAppStartAckPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeviceAppStartAckPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStartAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStartAckPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStartAckPacket'", field);
    }
}

Register_Class(DeviceAppStopAckPacket)

DeviceAppStopAckPacket::DeviceAppStopAckPacket() : ::DeviceAppPacket()
{
}

DeviceAppStopAckPacket::DeviceAppStopAckPacket(const DeviceAppStopAckPacket& other) : ::DeviceAppPacket(other)
{
    copy(other);
}

DeviceAppStopAckPacket::~DeviceAppStopAckPacket()
{
}

DeviceAppStopAckPacket& DeviceAppStopAckPacket::operator=(const DeviceAppStopAckPacket& other)
{
    if (this == &other) return *this;
    ::DeviceAppPacket::operator=(other);
    copy(other);
    return *this;
}

void DeviceAppStopAckPacket::copy(const DeviceAppStopAckPacket& other)
{
    this->result = other.result;
    this->reason = other.reason;
}

void DeviceAppStopAckPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::DeviceAppPacket::parsimPack(b);
    doParsimPacking(b,this->result);
    doParsimPacking(b,this->reason);
}

void DeviceAppStopAckPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::DeviceAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->result);
    doParsimUnpacking(b,this->reason);
}

bool DeviceAppStopAckPacket::getResult() const
{
    return this->result;
}

void DeviceAppStopAckPacket::setResult(bool result)
{
    handleChange();
    this->result = result;
}

const char * DeviceAppStopAckPacket::getReason() const
{
    return this->reason.c_str();
}

void DeviceAppStopAckPacket::setReason(const char * reason)
{
    handleChange();
    this->reason = reason;
}

class DeviceAppStopAckPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_result,
        FIELD_reason,
    };
  public:
    DeviceAppStopAckPacketDescriptor();
    virtual ~DeviceAppStopAckPacketDescriptor();

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

Register_ClassDescriptor(DeviceAppStopAckPacketDescriptor)

DeviceAppStopAckPacketDescriptor::DeviceAppStopAckPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DeviceAppStopAckPacket)), "DeviceAppPacket")
{
    propertyNames = nullptr;
}

DeviceAppStopAckPacketDescriptor::~DeviceAppStopAckPacketDescriptor()
{
    delete[] propertyNames;
}

bool DeviceAppStopAckPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DeviceAppStopAckPacket *>(obj)!=nullptr;
}

const char **DeviceAppStopAckPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DeviceAppStopAckPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DeviceAppStopAckPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int DeviceAppStopAckPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_result
        FD_ISEDITABLE,    // FIELD_reason
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *DeviceAppStopAckPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "result",
        "reason",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int DeviceAppStopAckPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "result") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "reason") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *DeviceAppStopAckPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_result
        "string",    // FIELD_reason
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **DeviceAppStopAckPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *DeviceAppStopAckPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int DeviceAppStopAckPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DeviceAppStopAckPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DeviceAppStopAckPacket'", field);
    }
}

const char *DeviceAppStopAckPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DeviceAppStopAckPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        case FIELD_result: return bool2string(pp->getResult());
        case FIELD_reason: return oppstring2string(pp->getReason());
        default: return "";
    }
}

void DeviceAppStopAckPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        case FIELD_result: pp->setResult(string2bool(value)); break;
        case FIELD_reason: pp->setReason((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStopAckPacket'", field);
    }
}

omnetpp::cValue DeviceAppStopAckPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        case FIELD_result: return pp->getResult();
        case FIELD_reason: return pp->getReason();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DeviceAppStopAckPacket' as cValue -- field index out of range?", field);
    }
}

void DeviceAppStopAckPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        case FIELD_result: pp->setResult(value.boolValue()); break;
        case FIELD_reason: pp->setReason(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStopAckPacket'", field);
    }
}

const char *DeviceAppStopAckPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr DeviceAppStopAckPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DeviceAppStopAckPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DeviceAppStopAckPacket *pp = omnetpp::fromAnyPtr<DeviceAppStopAckPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DeviceAppStopAckPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

