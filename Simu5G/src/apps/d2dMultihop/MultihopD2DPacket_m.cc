//
// Generated file, do not edit! Created by opp_msgtool 6.0 from apps/d2dMultihop/MultihopD2DPacket.msg.
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
#include "MultihopD2DPacket_m.h"

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

Register_Class(MultihopD2DPacket)

MultihopD2DPacket::MultihopD2DPacket() : ::inet::FieldsChunk()
{
    this->setChunkLength(D2D_MULTIHOP_HEADER_LENGTH);

}

MultihopD2DPacket::MultihopD2DPacket(const MultihopD2DPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MultihopD2DPacket::~MultihopD2DPacket()
{
}

MultihopD2DPacket& MultihopD2DPacket::operator=(const MultihopD2DPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MultihopD2DPacket::copy(const MultihopD2DPacket& other)
{
    this->srcId = other.srcId;
    this->msgid = other.msgid;
    this->srcCoord = other.srcCoord;
    this->maxRadius = other.maxRadius;
    this->ttl = other.ttl;
    this->hops = other.hops;
    this->lastHopSenderId = other.lastHopSenderId;
    this->payloadTimestamp = other.payloadTimestamp;
    this->payloadSize = other.payloadSize;
}

void MultihopD2DPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->srcId);
    doParsimPacking(b,this->msgid);
    doParsimPacking(b,this->srcCoord);
    doParsimPacking(b,this->maxRadius);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->hops);
    doParsimPacking(b,this->lastHopSenderId);
    doParsimPacking(b,this->payloadTimestamp);
    doParsimPacking(b,this->payloadSize);
}

void MultihopD2DPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->srcId);
    doParsimUnpacking(b,this->msgid);
    doParsimUnpacking(b,this->srcCoord);
    doParsimUnpacking(b,this->maxRadius);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->hops);
    doParsimUnpacking(b,this->lastHopSenderId);
    doParsimUnpacking(b,this->payloadTimestamp);
    doParsimUnpacking(b,this->payloadSize);
}

unsigned int MultihopD2DPacket::getSrcId() const
{
    return this->srcId;
}

void MultihopD2DPacket::setSrcId(unsigned int srcId)
{
    handleChange();
    this->srcId = srcId;
}

uint32_t MultihopD2DPacket::getMsgid() const
{
    return this->msgid;
}

void MultihopD2DPacket::setMsgid(uint32_t msgid)
{
    handleChange();
    this->msgid = msgid;
}

const inet::Coord& MultihopD2DPacket::getSrcCoord() const
{
    return this->srcCoord;
}

void MultihopD2DPacket::setSrcCoord(const inet::Coord& srcCoord)
{
    handleChange();
    this->srcCoord = srcCoord;
}

double MultihopD2DPacket::getMaxRadius() const
{
    return this->maxRadius;
}

void MultihopD2DPacket::setMaxRadius(double maxRadius)
{
    handleChange();
    this->maxRadius = maxRadius;
}

int MultihopD2DPacket::getTtl() const
{
    return this->ttl;
}

void MultihopD2DPacket::setTtl(int ttl)
{
    handleChange();
    this->ttl = ttl;
}

unsigned int MultihopD2DPacket::getHops() const
{
    return this->hops;
}

void MultihopD2DPacket::setHops(unsigned int hops)
{
    handleChange();
    this->hops = hops;
}

unsigned int MultihopD2DPacket::getLastHopSenderId() const
{
    return this->lastHopSenderId;
}

void MultihopD2DPacket::setLastHopSenderId(unsigned int lastHopSenderId)
{
    handleChange();
    this->lastHopSenderId = lastHopSenderId;
}

omnetpp::simtime_t MultihopD2DPacket::getPayloadTimestamp() const
{
    return this->payloadTimestamp;
}

void MultihopD2DPacket::setPayloadTimestamp(omnetpp::simtime_t payloadTimestamp)
{
    handleChange();
    this->payloadTimestamp = payloadTimestamp;
}

unsigned int MultihopD2DPacket::getPayloadSize() const
{
    return this->payloadSize;
}

void MultihopD2DPacket::setPayloadSize(unsigned int payloadSize)
{
    handleChange();
    this->payloadSize = payloadSize;
}

class MultihopD2DPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcId,
        FIELD_msgid,
        FIELD_srcCoord,
        FIELD_maxRadius,
        FIELD_ttl,
        FIELD_hops,
        FIELD_lastHopSenderId,
        FIELD_payloadTimestamp,
        FIELD_payloadSize,
    };
  public:
    MultihopD2DPacketDescriptor();
    virtual ~MultihopD2DPacketDescriptor();

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

Register_ClassDescriptor(MultihopD2DPacketDescriptor)

MultihopD2DPacketDescriptor::MultihopD2DPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MultihopD2DPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

MultihopD2DPacketDescriptor::~MultihopD2DPacketDescriptor()
{
    delete[] propertyNames;
}

bool MultihopD2DPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MultihopD2DPacket *>(obj)!=nullptr;
}

const char **MultihopD2DPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MultihopD2DPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MultihopD2DPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 9+base->getFieldCount() : 9;
}

unsigned int MultihopD2DPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcId
        FD_ISEDITABLE,    // FIELD_msgid
        FD_ISCOMPOUND,    // FIELD_srcCoord
        FD_ISEDITABLE,    // FIELD_maxRadius
        FD_ISEDITABLE,    // FIELD_ttl
        FD_ISEDITABLE,    // FIELD_hops
        FD_ISEDITABLE,    // FIELD_lastHopSenderId
        FD_ISEDITABLE,    // FIELD_payloadTimestamp
        FD_ISEDITABLE,    // FIELD_payloadSize
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *MultihopD2DPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcId",
        "msgid",
        "srcCoord",
        "maxRadius",
        "ttl",
        "hops",
        "lastHopSenderId",
        "payloadTimestamp",
        "payloadSize",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int MultihopD2DPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "msgid") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "srcCoord") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "maxRadius") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "ttl") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "hops") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "lastHopSenderId") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "payloadTimestamp") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "payloadSize") == 0) return baseIndex + 8;
    return base ? base->findField(fieldName) : -1;
}

const char *MultihopD2DPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",    // FIELD_srcId
        "uint32_t",    // FIELD_msgid
        "inet::Coord",    // FIELD_srcCoord
        "double",    // FIELD_maxRadius
        "int",    // FIELD_ttl
        "unsigned int",    // FIELD_hops
        "unsigned int",    // FIELD_lastHopSenderId
        "omnetpp::simtime_t",    // FIELD_payloadTimestamp
        "unsigned int",    // FIELD_payloadSize
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **MultihopD2DPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *MultihopD2DPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MultihopD2DPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MultihopD2DPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MultihopD2DPacket'", field);
    }
}

const char *MultihopD2DPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MultihopD2DPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcId: return ulong2string(pp->getSrcId());
        case FIELD_msgid: return ulong2string(pp->getMsgid());
        case FIELD_srcCoord: return pp->getSrcCoord().str();
        case FIELD_maxRadius: return double2string(pp->getMaxRadius());
        case FIELD_ttl: return long2string(pp->getTtl());
        case FIELD_hops: return ulong2string(pp->getHops());
        case FIELD_lastHopSenderId: return ulong2string(pp->getLastHopSenderId());
        case FIELD_payloadTimestamp: return simtime2string(pp->getPayloadTimestamp());
        case FIELD_payloadSize: return ulong2string(pp->getPayloadSize());
        default: return "";
    }
}

void MultihopD2DPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcId: pp->setSrcId(string2ulong(value)); break;
        case FIELD_msgid: pp->setMsgid(string2ulong(value)); break;
        case FIELD_maxRadius: pp->setMaxRadius(string2double(value)); break;
        case FIELD_ttl: pp->setTtl(string2long(value)); break;
        case FIELD_hops: pp->setHops(string2ulong(value)); break;
        case FIELD_lastHopSenderId: pp->setLastHopSenderId(string2ulong(value)); break;
        case FIELD_payloadTimestamp: pp->setPayloadTimestamp(string2simtime(value)); break;
        case FIELD_payloadSize: pp->setPayloadSize(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MultihopD2DPacket'", field);
    }
}

omnetpp::cValue MultihopD2DPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcId: return (omnetpp::intval_t)(pp->getSrcId());
        case FIELD_msgid: return (omnetpp::intval_t)(pp->getMsgid());
        case FIELD_srcCoord: return omnetpp::toAnyPtr(&pp->getSrcCoord()); break;
        case FIELD_maxRadius: return pp->getMaxRadius();
        case FIELD_ttl: return pp->getTtl();
        case FIELD_hops: return (omnetpp::intval_t)(pp->getHops());
        case FIELD_lastHopSenderId: return (omnetpp::intval_t)(pp->getLastHopSenderId());
        case FIELD_payloadTimestamp: return pp->getPayloadTimestamp().dbl();
        case FIELD_payloadSize: return (omnetpp::intval_t)(pp->getPayloadSize());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MultihopD2DPacket' as cValue -- field index out of range?", field);
    }
}

void MultihopD2DPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcId: pp->setSrcId(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_msgid: pp->setMsgid(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_maxRadius: pp->setMaxRadius(value.doubleValue()); break;
        case FIELD_ttl: pp->setTtl(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_hops: pp->setHops(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_lastHopSenderId: pp->setLastHopSenderId(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_payloadTimestamp: pp->setPayloadTimestamp(value.doubleValue()); break;
        case FIELD_payloadSize: pp->setPayloadSize(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MultihopD2DPacket'", field);
    }
}

const char *MultihopD2DPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_srcCoord: return omnetpp::opp_typename(typeid(inet::Coord));
        default: return nullptr;
    };
}

omnetpp::any_ptr MultihopD2DPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        case FIELD_srcCoord: return omnetpp::toAnyPtr(&pp->getSrcCoord()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MultihopD2DPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MultihopD2DPacket *pp = omnetpp::fromAnyPtr<MultihopD2DPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MultihopD2DPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

