//
// Generated file, do not edit! Created by opp_msgtool 6.0 from apps/mecRequestResponseApp/packets/MecRequestResponsePacket.msg.
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
#include "MecRequestResponsePacket_m.h"

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

Register_Class(MecRequestResponsePacket)

MecRequestResponsePacket::MecRequestResponsePacket() : ::inet::FieldsChunk()
{
}

MecRequestResponsePacket::MecRequestResponsePacket(const MecRequestResponsePacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MecRequestResponsePacket::~MecRequestResponsePacket()
{
}

MecRequestResponsePacket& MecRequestResponsePacket::operator=(const MecRequestResponsePacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MecRequestResponsePacket::copy(const MecRequestResponsePacket& other)
{
    this->sno = other.sno;
    this->reqTimestamp = other.reqTimestamp;
    this->respTimestamp = other.respTimestamp;
    this->bsId = other.bsId;
    this->appId = other.appId;
    this->srcAddress = other.srcAddress;
    this->srcPort = other.srcPort;
    this->destAddress = other.destAddress;
    this->destPort = other.destPort;
}

void MecRequestResponsePacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->sno);
    doParsimPacking(b,this->reqTimestamp);
    doParsimPacking(b,this->respTimestamp);
    doParsimPacking(b,this->bsId);
    doParsimPacking(b,this->appId);
    doParsimPacking(b,this->srcAddress);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destAddress);
    doParsimPacking(b,this->destPort);
}

void MecRequestResponsePacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sno);
    doParsimUnpacking(b,this->reqTimestamp);
    doParsimUnpacking(b,this->respTimestamp);
    doParsimUnpacking(b,this->bsId);
    doParsimUnpacking(b,this->appId);
    doParsimUnpacking(b,this->srcAddress);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destAddress);
    doParsimUnpacking(b,this->destPort);
}

unsigned int MecRequestResponsePacket::getSno() const
{
    return this->sno;
}

void MecRequestResponsePacket::setSno(unsigned int sno)
{
    handleChange();
    this->sno = sno;
}

double MecRequestResponsePacket::getReqTimestamp() const
{
    return this->reqTimestamp;
}

void MecRequestResponsePacket::setReqTimestamp(double reqTimestamp)
{
    handleChange();
    this->reqTimestamp = reqTimestamp;
}

double MecRequestResponsePacket::getRespTimestamp() const
{
    return this->respTimestamp;
}

void MecRequestResponsePacket::setRespTimestamp(double respTimestamp)
{
    handleChange();
    this->respTimestamp = respTimestamp;
}

int MecRequestResponsePacket::getBsId() const
{
    return this->bsId;
}

void MecRequestResponsePacket::setBsId(int bsId)
{
    handleChange();
    this->bsId = bsId;
}

int MecRequestResponsePacket::getAppId() const
{
    return this->appId;
}

void MecRequestResponsePacket::setAppId(int appId)
{
    handleChange();
    this->appId = appId;
}

const char * MecRequestResponsePacket::getSrcAddress() const
{
    return this->srcAddress.c_str();
}

void MecRequestResponsePacket::setSrcAddress(const char * srcAddress)
{
    handleChange();
    this->srcAddress = srcAddress;
}

int MecRequestResponsePacket::getSrcPort() const
{
    return this->srcPort;
}

void MecRequestResponsePacket::setSrcPort(int srcPort)
{
    handleChange();
    this->srcPort = srcPort;
}

const char * MecRequestResponsePacket::getDestAddress() const
{
    return this->destAddress.c_str();
}

void MecRequestResponsePacket::setDestAddress(const char * destAddress)
{
    handleChange();
    this->destAddress = destAddress;
}

int MecRequestResponsePacket::getDestPort() const
{
    return this->destPort;
}

void MecRequestResponsePacket::setDestPort(int destPort)
{
    handleChange();
    this->destPort = destPort;
}

class MecRequestResponsePacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sno,
        FIELD_reqTimestamp,
        FIELD_respTimestamp,
        FIELD_bsId,
        FIELD_appId,
        FIELD_srcAddress,
        FIELD_srcPort,
        FIELD_destAddress,
        FIELD_destPort,
    };
  public:
    MecRequestResponsePacketDescriptor();
    virtual ~MecRequestResponsePacketDescriptor();

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

Register_ClassDescriptor(MecRequestResponsePacketDescriptor)

MecRequestResponsePacketDescriptor::MecRequestResponsePacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MecRequestResponsePacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

MecRequestResponsePacketDescriptor::~MecRequestResponsePacketDescriptor()
{
    delete[] propertyNames;
}

bool MecRequestResponsePacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MecRequestResponsePacket *>(obj)!=nullptr;
}

const char **MecRequestResponsePacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MecRequestResponsePacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MecRequestResponsePacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 9+base->getFieldCount() : 9;
}

unsigned int MecRequestResponsePacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sno
        FD_ISEDITABLE,    // FIELD_reqTimestamp
        FD_ISEDITABLE,    // FIELD_respTimestamp
        FD_ISEDITABLE,    // FIELD_bsId
        FD_ISEDITABLE,    // FIELD_appId
        FD_ISEDITABLE,    // FIELD_srcAddress
        FD_ISEDITABLE,    // FIELD_srcPort
        FD_ISEDITABLE,    // FIELD_destAddress
        FD_ISEDITABLE,    // FIELD_destPort
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *MecRequestResponsePacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sno",
        "reqTimestamp",
        "respTimestamp",
        "bsId",
        "appId",
        "srcAddress",
        "srcPort",
        "destAddress",
        "destPort",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int MecRequestResponsePacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sno") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "reqTimestamp") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "respTimestamp") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "bsId") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "appId") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "srcAddress") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "srcPort") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "destAddress") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "destPort") == 0) return baseIndex + 8;
    return base ? base->findField(fieldName) : -1;
}

const char *MecRequestResponsePacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_sno
        "double",    // FIELD_reqTimestamp
        "double",    // FIELD_respTimestamp
        "int",    // FIELD_bsId
        "int",    // FIELD_appId
        "string",    // FIELD_srcAddress
        "int",    // FIELD_srcPort
        "string",    // FIELD_destAddress
        "int",    // FIELD_destPort
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **MecRequestResponsePacketDescriptor::getFieldPropertyNames(int field) const
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

const char *MecRequestResponsePacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MecRequestResponsePacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MecRequestResponsePacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MecRequestResponsePacket'", field);
    }
}

const char *MecRequestResponsePacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MecRequestResponsePacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        case FIELD_sno: return ulong2string(pp->getSno());
        case FIELD_reqTimestamp: return double2string(pp->getReqTimestamp());
        case FIELD_respTimestamp: return double2string(pp->getRespTimestamp());
        case FIELD_bsId: return long2string(pp->getBsId());
        case FIELD_appId: return long2string(pp->getAppId());
        case FIELD_srcAddress: return oppstring2string(pp->getSrcAddress());
        case FIELD_srcPort: return long2string(pp->getSrcPort());
        case FIELD_destAddress: return oppstring2string(pp->getDestAddress());
        case FIELD_destPort: return long2string(pp->getDestPort());
        default: return "";
    }
}

void MecRequestResponsePacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        case FIELD_sno: pp->setSno(string2ulong(value)); break;
        case FIELD_reqTimestamp: pp->setReqTimestamp(string2double(value)); break;
        case FIELD_respTimestamp: pp->setRespTimestamp(string2double(value)); break;
        case FIELD_bsId: pp->setBsId(string2long(value)); break;
        case FIELD_appId: pp->setAppId(string2long(value)); break;
        case FIELD_srcAddress: pp->setSrcAddress((value)); break;
        case FIELD_srcPort: pp->setSrcPort(string2long(value)); break;
        case FIELD_destAddress: pp->setDestAddress((value)); break;
        case FIELD_destPort: pp->setDestPort(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MecRequestResponsePacket'", field);
    }
}

omnetpp::cValue MecRequestResponsePacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        case FIELD_sno: return (omnetpp::intval_t)(pp->getSno());
        case FIELD_reqTimestamp: return pp->getReqTimestamp();
        case FIELD_respTimestamp: return pp->getRespTimestamp();
        case FIELD_bsId: return pp->getBsId();
        case FIELD_appId: return pp->getAppId();
        case FIELD_srcAddress: return pp->getSrcAddress();
        case FIELD_srcPort: return pp->getSrcPort();
        case FIELD_destAddress: return pp->getDestAddress();
        case FIELD_destPort: return pp->getDestPort();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MecRequestResponsePacket' as cValue -- field index out of range?", field);
    }
}

void MecRequestResponsePacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        case FIELD_sno: pp->setSno(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_reqTimestamp: pp->setReqTimestamp(value.doubleValue()); break;
        case FIELD_respTimestamp: pp->setRespTimestamp(value.doubleValue()); break;
        case FIELD_bsId: pp->setBsId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_appId: pp->setAppId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcAddress: pp->setSrcAddress(value.stringValue()); break;
        case FIELD_srcPort: pp->setSrcPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destAddress: pp->setDestAddress(value.stringValue()); break;
        case FIELD_destPort: pp->setDestPort(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MecRequestResponsePacket'", field);
    }
}

const char *MecRequestResponsePacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MecRequestResponsePacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MecRequestResponsePacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MecRequestResponsePacket *pp = omnetpp::fromAnyPtr<MecRequestResponsePacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MecRequestResponsePacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

