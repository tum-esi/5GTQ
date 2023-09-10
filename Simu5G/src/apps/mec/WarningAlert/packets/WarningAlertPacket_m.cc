//
// Generated file, do not edit! Created by opp_msgtool 6.0 from apps/mec/WarningAlert/packets/WarningAlertPacket.msg.
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
#include "WarningAlertPacket_m.h"

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

Register_Class(WarningAppPacket)

WarningAppPacket::WarningAppPacket() : ::MECPacket()
{
}

WarningAppPacket::WarningAppPacket(const WarningAppPacket& other) : ::MECPacket(other)
{
    copy(other);
}

WarningAppPacket::~WarningAppPacket()
{
}

WarningAppPacket& WarningAppPacket::operator=(const WarningAppPacket& other)
{
    if (this == &other) return *this;
    ::MECPacket::operator=(other);
    copy(other);
    return *this;
}

void WarningAppPacket::copy(const WarningAppPacket& other)
{
}

void WarningAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::MECPacket::parsimPack(b);
}

void WarningAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::MECPacket::parsimUnpack(b);
}

class WarningAppPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    WarningAppPacketDescriptor();
    virtual ~WarningAppPacketDescriptor();

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

Register_ClassDescriptor(WarningAppPacketDescriptor)

WarningAppPacketDescriptor::WarningAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(WarningAppPacket)), "MECPacket")
{
    propertyNames = nullptr;
}

WarningAppPacketDescriptor::~WarningAppPacketDescriptor()
{
    delete[] propertyNames;
}

bool WarningAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WarningAppPacket *>(obj)!=nullptr;
}

const char **WarningAppPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *WarningAppPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int WarningAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int WarningAppPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *WarningAppPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int WarningAppPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *WarningAppPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **WarningAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *WarningAppPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int WarningAppPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void WarningAppPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'WarningAppPacket'", field);
    }
}

const char *WarningAppPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WarningAppPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void WarningAppPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningAppPacket'", field);
    }
}

omnetpp::cValue WarningAppPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'WarningAppPacket' as cValue -- field index out of range?", field);
    }
}

void WarningAppPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningAppPacket'", field);
    }
}

const char *WarningAppPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr WarningAppPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void WarningAppPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningAppPacket *pp = omnetpp::fromAnyPtr<WarningAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningAppPacket'", field);
    }
}

Register_Class(WarningAlertPacket)

WarningAlertPacket::WarningAlertPacket() : ::WarningAppPacket()
{
}

WarningAlertPacket::WarningAlertPacket(const WarningAlertPacket& other) : ::WarningAppPacket(other)
{
    copy(other);
}

WarningAlertPacket::~WarningAlertPacket()
{
}

WarningAlertPacket& WarningAlertPacket::operator=(const WarningAlertPacket& other)
{
    if (this == &other) return *this;
    ::WarningAppPacket::operator=(other);
    copy(other);
    return *this;
}

void WarningAlertPacket::copy(const WarningAlertPacket& other)
{
    this->ueOmnetID = other.ueOmnetID;
    this->positionX = other.positionX;
    this->positionY = other.positionY;
    this->positionZ = other.positionZ;
    this->danger = other.danger;
}

void WarningAlertPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::WarningAppPacket::parsimPack(b);
    doParsimPacking(b,this->ueOmnetID);
    doParsimPacking(b,this->positionX);
    doParsimPacking(b,this->positionY);
    doParsimPacking(b,this->positionZ);
    doParsimPacking(b,this->danger);
}

void WarningAlertPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::WarningAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->ueOmnetID);
    doParsimUnpacking(b,this->positionX);
    doParsimUnpacking(b,this->positionY);
    doParsimUnpacking(b,this->positionZ);
    doParsimUnpacking(b,this->danger);
}

int WarningAlertPacket::getUeOmnetID() const
{
    return this->ueOmnetID;
}

void WarningAlertPacket::setUeOmnetID(int ueOmnetID)
{
    handleChange();
    this->ueOmnetID = ueOmnetID;
}

double WarningAlertPacket::getPositionX() const
{
    return this->positionX;
}

void WarningAlertPacket::setPositionX(double positionX)
{
    handleChange();
    this->positionX = positionX;
}

double WarningAlertPacket::getPositionY() const
{
    return this->positionY;
}

void WarningAlertPacket::setPositionY(double positionY)
{
    handleChange();
    this->positionY = positionY;
}

double WarningAlertPacket::getPositionZ() const
{
    return this->positionZ;
}

void WarningAlertPacket::setPositionZ(double positionZ)
{
    handleChange();
    this->positionZ = positionZ;
}

bool WarningAlertPacket::getDanger() const
{
    return this->danger;
}

void WarningAlertPacket::setDanger(bool danger)
{
    handleChange();
    this->danger = danger;
}

class WarningAlertPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueOmnetID,
        FIELD_positionX,
        FIELD_positionY,
        FIELD_positionZ,
        FIELD_danger,
    };
  public:
    WarningAlertPacketDescriptor();
    virtual ~WarningAlertPacketDescriptor();

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

Register_ClassDescriptor(WarningAlertPacketDescriptor)

WarningAlertPacketDescriptor::WarningAlertPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(WarningAlertPacket)), "WarningAppPacket")
{
    propertyNames = nullptr;
}

WarningAlertPacketDescriptor::~WarningAlertPacketDescriptor()
{
    delete[] propertyNames;
}

bool WarningAlertPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WarningAlertPacket *>(obj)!=nullptr;
}

const char **WarningAlertPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *WarningAlertPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int WarningAlertPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int WarningAlertPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueOmnetID
        FD_ISEDITABLE,    // FIELD_positionX
        FD_ISEDITABLE,    // FIELD_positionY
        FD_ISEDITABLE,    // FIELD_positionZ
        FD_ISEDITABLE,    // FIELD_danger
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *WarningAlertPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueOmnetID",
        "positionX",
        "positionY",
        "positionZ",
        "danger",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int WarningAlertPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueOmnetID") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "positionX") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "positionY") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "positionZ") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "danger") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *WarningAlertPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueOmnetID
        "double",    // FIELD_positionX
        "double",    // FIELD_positionY
        "double",    // FIELD_positionZ
        "bool",    // FIELD_danger
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **WarningAlertPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *WarningAlertPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int WarningAlertPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void WarningAlertPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'WarningAlertPacket'", field);
    }
}

const char *WarningAlertPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WarningAlertPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ueOmnetID: return long2string(pp->getUeOmnetID());
        case FIELD_positionX: return double2string(pp->getPositionX());
        case FIELD_positionY: return double2string(pp->getPositionY());
        case FIELD_positionZ: return double2string(pp->getPositionZ());
        case FIELD_danger: return bool2string(pp->getDanger());
        default: return "";
    }
}

void WarningAlertPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ueOmnetID: pp->setUeOmnetID(string2long(value)); break;
        case FIELD_positionX: pp->setPositionX(string2double(value)); break;
        case FIELD_positionY: pp->setPositionY(string2double(value)); break;
        case FIELD_positionZ: pp->setPositionZ(string2double(value)); break;
        case FIELD_danger: pp->setDanger(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningAlertPacket'", field);
    }
}

omnetpp::cValue WarningAlertPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ueOmnetID: return pp->getUeOmnetID();
        case FIELD_positionX: return pp->getPositionX();
        case FIELD_positionY: return pp->getPositionY();
        case FIELD_positionZ: return pp->getPositionZ();
        case FIELD_danger: return pp->getDanger();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'WarningAlertPacket' as cValue -- field index out of range?", field);
    }
}

void WarningAlertPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ueOmnetID: pp->setUeOmnetID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_positionX: pp->setPositionX(value.doubleValue()); break;
        case FIELD_positionY: pp->setPositionY(value.doubleValue()); break;
        case FIELD_positionZ: pp->setPositionZ(value.doubleValue()); break;
        case FIELD_danger: pp->setDanger(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningAlertPacket'", field);
    }
}

const char *WarningAlertPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr WarningAlertPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void WarningAlertPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningAlertPacket *pp = omnetpp::fromAnyPtr<WarningAlertPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningAlertPacket'", field);
    }
}

Register_Class(WarningStartPacket)

WarningStartPacket::WarningStartPacket() : ::WarningAppPacket()
{
}

WarningStartPacket::WarningStartPacket(const WarningStartPacket& other) : ::WarningAppPacket(other)
{
    copy(other);
}

WarningStartPacket::~WarningStartPacket()
{
}

WarningStartPacket& WarningStartPacket::operator=(const WarningStartPacket& other)
{
    if (this == &other) return *this;
    ::WarningAppPacket::operator=(other);
    copy(other);
    return *this;
}

void WarningStartPacket::copy(const WarningStartPacket& other)
{
    this->centerPositionX = other.centerPositionX;
    this->centerPositionY = other.centerPositionY;
    this->centerPositionZ = other.centerPositionZ;
    this->radius = other.radius;
}

void WarningStartPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::WarningAppPacket::parsimPack(b);
    doParsimPacking(b,this->centerPositionX);
    doParsimPacking(b,this->centerPositionY);
    doParsimPacking(b,this->centerPositionZ);
    doParsimPacking(b,this->radius);
}

void WarningStartPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::WarningAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->centerPositionX);
    doParsimUnpacking(b,this->centerPositionY);
    doParsimUnpacking(b,this->centerPositionZ);
    doParsimUnpacking(b,this->radius);
}

double WarningStartPacket::getCenterPositionX() const
{
    return this->centerPositionX;
}

void WarningStartPacket::setCenterPositionX(double centerPositionX)
{
    handleChange();
    this->centerPositionX = centerPositionX;
}

double WarningStartPacket::getCenterPositionY() const
{
    return this->centerPositionY;
}

void WarningStartPacket::setCenterPositionY(double centerPositionY)
{
    handleChange();
    this->centerPositionY = centerPositionY;
}

double WarningStartPacket::getCenterPositionZ() const
{
    return this->centerPositionZ;
}

void WarningStartPacket::setCenterPositionZ(double centerPositionZ)
{
    handleChange();
    this->centerPositionZ = centerPositionZ;
}

double WarningStartPacket::getRadius() const
{
    return this->radius;
}

void WarningStartPacket::setRadius(double radius)
{
    handleChange();
    this->radius = radius;
}

class WarningStartPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_centerPositionX,
        FIELD_centerPositionY,
        FIELD_centerPositionZ,
        FIELD_radius,
    };
  public:
    WarningStartPacketDescriptor();
    virtual ~WarningStartPacketDescriptor();

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

Register_ClassDescriptor(WarningStartPacketDescriptor)

WarningStartPacketDescriptor::WarningStartPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(WarningStartPacket)), "WarningAppPacket")
{
    propertyNames = nullptr;
}

WarningStartPacketDescriptor::~WarningStartPacketDescriptor()
{
    delete[] propertyNames;
}

bool WarningStartPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WarningStartPacket *>(obj)!=nullptr;
}

const char **WarningStartPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *WarningStartPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int WarningStartPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int WarningStartPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_centerPositionX
        FD_ISEDITABLE,    // FIELD_centerPositionY
        FD_ISEDITABLE,    // FIELD_centerPositionZ
        FD_ISEDITABLE,    // FIELD_radius
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *WarningStartPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "centerPositionX",
        "centerPositionY",
        "centerPositionZ",
        "radius",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int WarningStartPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "centerPositionX") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "centerPositionY") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "centerPositionZ") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "radius") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *WarningStartPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_centerPositionX
        "double",    // FIELD_centerPositionY
        "double",    // FIELD_centerPositionZ
        "double",    // FIELD_radius
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **WarningStartPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *WarningStartPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int WarningStartPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void WarningStartPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'WarningStartPacket'", field);
    }
}

const char *WarningStartPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WarningStartPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        case FIELD_centerPositionX: return double2string(pp->getCenterPositionX());
        case FIELD_centerPositionY: return double2string(pp->getCenterPositionY());
        case FIELD_centerPositionZ: return double2string(pp->getCenterPositionZ());
        case FIELD_radius: return double2string(pp->getRadius());
        default: return "";
    }
}

void WarningStartPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        case FIELD_centerPositionX: pp->setCenterPositionX(string2double(value)); break;
        case FIELD_centerPositionY: pp->setCenterPositionY(string2double(value)); break;
        case FIELD_centerPositionZ: pp->setCenterPositionZ(string2double(value)); break;
        case FIELD_radius: pp->setRadius(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningStartPacket'", field);
    }
}

omnetpp::cValue WarningStartPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        case FIELD_centerPositionX: return pp->getCenterPositionX();
        case FIELD_centerPositionY: return pp->getCenterPositionY();
        case FIELD_centerPositionZ: return pp->getCenterPositionZ();
        case FIELD_radius: return pp->getRadius();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'WarningStartPacket' as cValue -- field index out of range?", field);
    }
}

void WarningStartPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        case FIELD_centerPositionX: pp->setCenterPositionX(value.doubleValue()); break;
        case FIELD_centerPositionY: pp->setCenterPositionY(value.doubleValue()); break;
        case FIELD_centerPositionZ: pp->setCenterPositionZ(value.doubleValue()); break;
        case FIELD_radius: pp->setRadius(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningStartPacket'", field);
    }
}

const char *WarningStartPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr WarningStartPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void WarningStartPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningStartPacket *pp = omnetpp::fromAnyPtr<WarningStartPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningStartPacket'", field);
    }
}

Register_Class(WarningStopPacket)

WarningStopPacket::WarningStopPacket() : ::WarningAppPacket()
{
}

WarningStopPacket::WarningStopPacket(const WarningStopPacket& other) : ::WarningAppPacket(other)
{
    copy(other);
}

WarningStopPacket::~WarningStopPacket()
{
}

WarningStopPacket& WarningStopPacket::operator=(const WarningStopPacket& other)
{
    if (this == &other) return *this;
    ::WarningAppPacket::operator=(other);
    copy(other);
    return *this;
}

void WarningStopPacket::copy(const WarningStopPacket& other)
{
}

void WarningStopPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::WarningAppPacket::parsimPack(b);
}

void WarningStopPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::WarningAppPacket::parsimUnpack(b);
}

class WarningStopPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    WarningStopPacketDescriptor();
    virtual ~WarningStopPacketDescriptor();

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

Register_ClassDescriptor(WarningStopPacketDescriptor)

WarningStopPacketDescriptor::WarningStopPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(WarningStopPacket)), "WarningAppPacket")
{
    propertyNames = nullptr;
}

WarningStopPacketDescriptor::~WarningStopPacketDescriptor()
{
    delete[] propertyNames;
}

bool WarningStopPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WarningStopPacket *>(obj)!=nullptr;
}

const char **WarningStopPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *WarningStopPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int WarningStopPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int WarningStopPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *WarningStopPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int WarningStopPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *WarningStopPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **WarningStopPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *WarningStopPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int WarningStopPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void WarningStopPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'WarningStopPacket'", field);
    }
}

const char *WarningStopPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WarningStopPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void WarningStopPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningStopPacket'", field);
    }
}

omnetpp::cValue WarningStopPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'WarningStopPacket' as cValue -- field index out of range?", field);
    }
}

void WarningStopPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningStopPacket'", field);
    }
}

const char *WarningStopPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr WarningStopPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void WarningStopPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    WarningStopPacket *pp = omnetpp::fromAnyPtr<WarningStopPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'WarningStopPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

