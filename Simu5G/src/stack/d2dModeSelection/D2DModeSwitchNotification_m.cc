//
// Generated file, do not edit! Created by opp_msgtool 6.0 from stack/d2dModeSelection/D2DModeSwitchNotification.msg.
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
#include "D2DModeSwitchNotification_m.h"

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

Register_Class(D2DModeSwitchNotification)

D2DModeSwitchNotification::D2DModeSwitchNotification() : ::inet::FieldsChunk()
{
    this->setChunkLength(inet::B(1));

}

D2DModeSwitchNotification::D2DModeSwitchNotification(const D2DModeSwitchNotification& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

D2DModeSwitchNotification::~D2DModeSwitchNotification()
{
}

D2DModeSwitchNotification& D2DModeSwitchNotification::operator=(const D2DModeSwitchNotification& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void D2DModeSwitchNotification::copy(const D2DModeSwitchNotification& other)
{
    this->peerId = other.peerId;
    this->txSide = other.txSide;
    this->oldMode = other.oldMode;
    this->newMode = other.newMode;
    this->oldConnection = other.oldConnection;
    this->interruptHarq = other.interruptHarq;
    this->clearRlcBuffer = other.clearRlcBuffer;
}

void D2DModeSwitchNotification::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->peerId);
    doParsimPacking(b,this->txSide);
    doParsimPacking(b,this->oldMode);
    doParsimPacking(b,this->newMode);
    doParsimPacking(b,this->oldConnection);
    doParsimPacking(b,this->interruptHarq);
    doParsimPacking(b,this->clearRlcBuffer);
}

void D2DModeSwitchNotification::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->peerId);
    doParsimUnpacking(b,this->txSide);
    doParsimUnpacking(b,this->oldMode);
    doParsimUnpacking(b,this->newMode);
    doParsimUnpacking(b,this->oldConnection);
    doParsimUnpacking(b,this->interruptHarq);
    doParsimUnpacking(b,this->clearRlcBuffer);
}

unsigned int D2DModeSwitchNotification::getPeerId() const
{
    return this->peerId;
}

void D2DModeSwitchNotification::setPeerId(unsigned int peerId)
{
    handleChange();
    this->peerId = peerId;
}

bool D2DModeSwitchNotification::getTxSide() const
{
    return this->txSide;
}

void D2DModeSwitchNotification::setTxSide(bool txSide)
{
    handleChange();
    this->txSide = txSide;
}

LteD2DMode D2DModeSwitchNotification::getOldMode() const
{
    return this->oldMode;
}

void D2DModeSwitchNotification::setOldMode(LteD2DMode oldMode)
{
    handleChange();
    this->oldMode = oldMode;
}

LteD2DMode D2DModeSwitchNotification::getNewMode() const
{
    return this->newMode;
}

void D2DModeSwitchNotification::setNewMode(LteD2DMode newMode)
{
    handleChange();
    this->newMode = newMode;
}

bool D2DModeSwitchNotification::getOldConnection() const
{
    return this->oldConnection;
}

void D2DModeSwitchNotification::setOldConnection(bool oldConnection)
{
    handleChange();
    this->oldConnection = oldConnection;
}

bool D2DModeSwitchNotification::getInterruptHarq() const
{
    return this->interruptHarq;
}

void D2DModeSwitchNotification::setInterruptHarq(bool interruptHarq)
{
    handleChange();
    this->interruptHarq = interruptHarq;
}

bool D2DModeSwitchNotification::getClearRlcBuffer() const
{
    return this->clearRlcBuffer;
}

void D2DModeSwitchNotification::setClearRlcBuffer(bool clearRlcBuffer)
{
    handleChange();
    this->clearRlcBuffer = clearRlcBuffer;
}

class D2DModeSwitchNotificationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_peerId,
        FIELD_txSide,
        FIELD_oldMode,
        FIELD_newMode,
        FIELD_oldConnection,
        FIELD_interruptHarq,
        FIELD_clearRlcBuffer,
    };
  public:
    D2DModeSwitchNotificationDescriptor();
    virtual ~D2DModeSwitchNotificationDescriptor();

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

Register_ClassDescriptor(D2DModeSwitchNotificationDescriptor)

D2DModeSwitchNotificationDescriptor::D2DModeSwitchNotificationDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(D2DModeSwitchNotification)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

D2DModeSwitchNotificationDescriptor::~D2DModeSwitchNotificationDescriptor()
{
    delete[] propertyNames;
}

bool D2DModeSwitchNotificationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<D2DModeSwitchNotification *>(obj)!=nullptr;
}

const char **D2DModeSwitchNotificationDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *D2DModeSwitchNotificationDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int D2DModeSwitchNotificationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int D2DModeSwitchNotificationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_peerId
        FD_ISEDITABLE,    // FIELD_txSide
        0,    // FIELD_oldMode
        0,    // FIELD_newMode
        FD_ISEDITABLE,    // FIELD_oldConnection
        FD_ISEDITABLE,    // FIELD_interruptHarq
        FD_ISEDITABLE,    // FIELD_clearRlcBuffer
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *D2DModeSwitchNotificationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "peerId",
        "txSide",
        "oldMode",
        "newMode",
        "oldConnection",
        "interruptHarq",
        "clearRlcBuffer",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int D2DModeSwitchNotificationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "peerId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "txSide") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "oldMode") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "newMode") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "oldConnection") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "interruptHarq") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "clearRlcBuffer") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *D2DModeSwitchNotificationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_peerId
        "bool",    // FIELD_txSide
        "LteD2DMode",    // FIELD_oldMode
        "LteD2DMode",    // FIELD_newMode
        "bool",    // FIELD_oldConnection
        "bool",    // FIELD_interruptHarq
        "bool",    // FIELD_clearRlcBuffer
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **D2DModeSwitchNotificationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_oldMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_newMode: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *D2DModeSwitchNotificationDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_oldMode:
            if (!strcmp(propertyName, "enum")) return "LteD2DMode";
            return nullptr;
        case FIELD_newMode:
            if (!strcmp(propertyName, "enum")) return "LteD2DMode";
            return nullptr;
        default: return nullptr;
    }
}

int D2DModeSwitchNotificationDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void D2DModeSwitchNotificationDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'D2DModeSwitchNotification'", field);
    }
}

const char *D2DModeSwitchNotificationDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string D2DModeSwitchNotificationDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        case FIELD_peerId: return ulong2string(pp->getPeerId());
        case FIELD_txSide: return bool2string(pp->getTxSide());
        case FIELD_oldMode: return enum2string(pp->getOldMode(), "LteD2DMode");
        case FIELD_newMode: return enum2string(pp->getNewMode(), "LteD2DMode");
        case FIELD_oldConnection: return bool2string(pp->getOldConnection());
        case FIELD_interruptHarq: return bool2string(pp->getInterruptHarq());
        case FIELD_clearRlcBuffer: return bool2string(pp->getClearRlcBuffer());
        default: return "";
    }
}

void D2DModeSwitchNotificationDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        case FIELD_peerId: pp->setPeerId(string2ulong(value)); break;
        case FIELD_txSide: pp->setTxSide(string2bool(value)); break;
        case FIELD_oldConnection: pp->setOldConnection(string2bool(value)); break;
        case FIELD_interruptHarq: pp->setInterruptHarq(string2bool(value)); break;
        case FIELD_clearRlcBuffer: pp->setClearRlcBuffer(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'D2DModeSwitchNotification'", field);
    }
}

omnetpp::cValue D2DModeSwitchNotificationDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        case FIELD_peerId: return (omnetpp::intval_t)(pp->getPeerId());
        case FIELD_txSide: return pp->getTxSide();
        case FIELD_oldMode: return static_cast<int>(pp->getOldMode());
        case FIELD_newMode: return static_cast<int>(pp->getNewMode());
        case FIELD_oldConnection: return pp->getOldConnection();
        case FIELD_interruptHarq: return pp->getInterruptHarq();
        case FIELD_clearRlcBuffer: return pp->getClearRlcBuffer();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'D2DModeSwitchNotification' as cValue -- field index out of range?", field);
    }
}

void D2DModeSwitchNotificationDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        case FIELD_peerId: pp->setPeerId(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_txSide: pp->setTxSide(value.boolValue()); break;
        case FIELD_oldConnection: pp->setOldConnection(value.boolValue()); break;
        case FIELD_interruptHarq: pp->setInterruptHarq(value.boolValue()); break;
        case FIELD_clearRlcBuffer: pp->setClearRlcBuffer(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'D2DModeSwitchNotification'", field);
    }
}

const char *D2DModeSwitchNotificationDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr D2DModeSwitchNotificationDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void D2DModeSwitchNotificationDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    D2DModeSwitchNotification *pp = omnetpp::fromAnyPtr<D2DModeSwitchNotification>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'D2DModeSwitchNotification'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

