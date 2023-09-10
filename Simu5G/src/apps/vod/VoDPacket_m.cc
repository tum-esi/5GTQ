//
// Generated file, do not edit! Created by opp_msgtool 6.0 from apps/vod/VoDPacket.msg.
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
#include "VoDPacket_m.h"

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

Register_Class(VoDPacket)

VoDPacket::VoDPacket() : ::inet::FieldsChunk()
{
}

VoDPacket::VoDPacket(const VoDPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

VoDPacket::~VoDPacket()
{
}

VoDPacket& VoDPacket::operator=(const VoDPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void VoDPacket::copy(const VoDPacket& other)
{
    this->frameSeqNum = other.frameSeqNum;
    this->frameLength = other.frameLength;
    this->tid = other.tid;
    this->qid = other.qid;
    this->payloadTimestamp = other.payloadTimestamp;
}

void VoDPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->frameSeqNum);
    doParsimPacking(b,this->frameLength);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->qid);
    doParsimPacking(b,this->payloadTimestamp);
}

void VoDPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->frameSeqNum);
    doParsimUnpacking(b,this->frameLength);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->qid);
    doParsimUnpacking(b,this->payloadTimestamp);
}

int VoDPacket::getFrameSeqNum() const
{
    return this->frameSeqNum;
}

void VoDPacket::setFrameSeqNum(int frameSeqNum)
{
    handleChange();
    this->frameSeqNum = frameSeqNum;
}

int VoDPacket::getFrameLength() const
{
    return this->frameLength;
}

void VoDPacket::setFrameLength(int frameLength)
{
    handleChange();
    this->frameLength = frameLength;
}

int VoDPacket::getTid() const
{
    return this->tid;
}

void VoDPacket::setTid(int tid)
{
    handleChange();
    this->tid = tid;
}

int VoDPacket::getQid() const
{
    return this->qid;
}

void VoDPacket::setQid(int qid)
{
    handleChange();
    this->qid = qid;
}

omnetpp::simtime_t VoDPacket::getPayloadTimestamp() const
{
    return this->payloadTimestamp;
}

void VoDPacket::setPayloadTimestamp(omnetpp::simtime_t payloadTimestamp)
{
    handleChange();
    this->payloadTimestamp = payloadTimestamp;
}

class VoDPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_frameSeqNum,
        FIELD_frameLength,
        FIELD_tid,
        FIELD_qid,
        FIELD_payloadTimestamp,
    };
  public:
    VoDPacketDescriptor();
    virtual ~VoDPacketDescriptor();

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

Register_ClassDescriptor(VoDPacketDescriptor)

VoDPacketDescriptor::VoDPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(VoDPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

VoDPacketDescriptor::~VoDPacketDescriptor()
{
    delete[] propertyNames;
}

bool VoDPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<VoDPacket *>(obj)!=nullptr;
}

const char **VoDPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *VoDPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int VoDPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int VoDPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_frameSeqNum
        FD_ISEDITABLE,    // FIELD_frameLength
        FD_ISEDITABLE,    // FIELD_tid
        FD_ISEDITABLE,    // FIELD_qid
        FD_ISEDITABLE,    // FIELD_payloadTimestamp
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *VoDPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "frameSeqNum",
        "frameLength",
        "tid",
        "qid",
        "payloadTimestamp",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int VoDPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "frameSeqNum") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "frameLength") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "tid") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "qid") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "payloadTimestamp") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *VoDPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_frameSeqNum
        "int",    // FIELD_frameLength
        "int",    // FIELD_tid
        "int",    // FIELD_qid
        "omnetpp::simtime_t",    // FIELD_payloadTimestamp
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **VoDPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *VoDPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int VoDPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void VoDPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'VoDPacket'", field);
    }
}

const char *VoDPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string VoDPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        case FIELD_frameSeqNum: return long2string(pp->getFrameSeqNum());
        case FIELD_frameLength: return long2string(pp->getFrameLength());
        case FIELD_tid: return long2string(pp->getTid());
        case FIELD_qid: return long2string(pp->getQid());
        case FIELD_payloadTimestamp: return simtime2string(pp->getPayloadTimestamp());
        default: return "";
    }
}

void VoDPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        case FIELD_frameSeqNum: pp->setFrameSeqNum(string2long(value)); break;
        case FIELD_frameLength: pp->setFrameLength(string2long(value)); break;
        case FIELD_tid: pp->setTid(string2long(value)); break;
        case FIELD_qid: pp->setQid(string2long(value)); break;
        case FIELD_payloadTimestamp: pp->setPayloadTimestamp(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VoDPacket'", field);
    }
}

omnetpp::cValue VoDPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        case FIELD_frameSeqNum: return pp->getFrameSeqNum();
        case FIELD_frameLength: return pp->getFrameLength();
        case FIELD_tid: return pp->getTid();
        case FIELD_qid: return pp->getQid();
        case FIELD_payloadTimestamp: return pp->getPayloadTimestamp().dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'VoDPacket' as cValue -- field index out of range?", field);
    }
}

void VoDPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        case FIELD_frameSeqNum: pp->setFrameSeqNum(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_frameLength: pp->setFrameLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_tid: pp->setTid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_qid: pp->setQid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_payloadTimestamp: pp->setPayloadTimestamp(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VoDPacket'", field);
    }
}

const char *VoDPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr VoDPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void VoDPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    VoDPacket *pp = omnetpp::fromAnyPtr<VoDPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'VoDPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

