//
// Generated file, do not edit! Created by opp_msgtool 6.0 from common/LteControlInfo.msg.
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
#include "LteControlInfo_m.h"

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

Register_Class(LteControlInfo)

LteControlInfo::LteControlInfo() : ::inet::TagBase()
{
}

LteControlInfo::LteControlInfo(const LteControlInfo& other) : ::inet::TagBase(other)
{
    copy(other);
}

LteControlInfo::~LteControlInfo()
{
}

LteControlInfo& LteControlInfo::operator=(const LteControlInfo& other)
{
    if (this == &other) return *this;
    ::inet::TagBase::operator=(other);
    copy(other);
    return *this;
}

void LteControlInfo::copy(const LteControlInfo& other)
{
    this->sourceId = other.sourceId;
    this->destId = other.destId;
    this->direction = other.direction;
    this->d2dTxPeerId = other.d2dTxPeerId;
    this->d2dRxPeerId = other.d2dRxPeerId;
    this->application = other.application;
    this->traffic = other.traffic;
    this->cid = other.cid;
    this->qfi = other.qfi;
    this->radioBearerId = other.radioBearerId;
    this->bytesize = other.bytesize;
    this->numberOfPacketsInQueue = other.numberOfPacketsInQueue;
    this->bytesizeOfOnePacket = other.bytesizeOfOnePacket;
    this->rlcType = other.rlcType;
    this->lcid = other.lcid;
    this->multicastGroupId = other.multicastGroupId;
    this->containsSeveralCids = other.containsSeveralCids;
}

void LteControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TagBase::parsimPack(b);
    doParsimPacking(b,this->sourceId);
    doParsimPacking(b,this->destId);
    doParsimPacking(b,this->direction);
    doParsimPacking(b,this->d2dTxPeerId);
    doParsimPacking(b,this->d2dRxPeerId);
    doParsimPacking(b,this->application);
    doParsimPacking(b,this->traffic);
    doParsimPacking(b,this->cid);
    doParsimPacking(b,this->qfi);
    doParsimPacking(b,this->radioBearerId);
    doParsimPacking(b,this->bytesize);
    doParsimPacking(b,this->numberOfPacketsInQueue);
    doParsimPacking(b,this->bytesizeOfOnePacket);
    doParsimPacking(b,this->rlcType);
    doParsimPacking(b,this->lcid);
    doParsimPacking(b,this->multicastGroupId);
    doParsimPacking(b,this->containsSeveralCids);
}

void LteControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TagBase::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceId);
    doParsimUnpacking(b,this->destId);
    doParsimUnpacking(b,this->direction);
    doParsimUnpacking(b,this->d2dTxPeerId);
    doParsimUnpacking(b,this->d2dRxPeerId);
    doParsimUnpacking(b,this->application);
    doParsimUnpacking(b,this->traffic);
    doParsimUnpacking(b,this->cid);
    doParsimUnpacking(b,this->qfi);
    doParsimUnpacking(b,this->radioBearerId);
    doParsimUnpacking(b,this->bytesize);
    doParsimUnpacking(b,this->numberOfPacketsInQueue);
    doParsimUnpacking(b,this->bytesizeOfOnePacket);
    doParsimUnpacking(b,this->rlcType);
    doParsimUnpacking(b,this->lcid);
    doParsimUnpacking(b,this->multicastGroupId);
    doParsimUnpacking(b,this->containsSeveralCids);
}

uint16_t LteControlInfo::getSourceId() const
{
    return this->sourceId;
}

void LteControlInfo::setSourceId(uint16_t sourceId)
{
    this->sourceId = sourceId;
}

uint16_t LteControlInfo::getDestId() const
{
    return this->destId;
}

void LteControlInfo::setDestId(uint16_t destId)
{
    this->destId = destId;
}

unsigned short LteControlInfo::getDirection() const
{
    return this->direction;
}

void LteControlInfo::setDirection(unsigned short direction)
{
    this->direction = direction;
}

uint16_t LteControlInfo::getD2dTxPeerId() const
{
    return this->d2dTxPeerId;
}

void LteControlInfo::setD2dTxPeerId(uint16_t d2dTxPeerId)
{
    this->d2dTxPeerId = d2dTxPeerId;
}

uint16_t LteControlInfo::getD2dRxPeerId() const
{
    return this->d2dRxPeerId;
}

void LteControlInfo::setD2dRxPeerId(uint16_t d2dRxPeerId)
{
    this->d2dRxPeerId = d2dRxPeerId;
}

unsigned short LteControlInfo::getApplication() const
{
    return this->application;
}

void LteControlInfo::setApplication(unsigned short application)
{
    this->application = application;
}

unsigned short LteControlInfo::getTraffic() const
{
    return this->traffic;
}

void LteControlInfo::setTraffic(unsigned short traffic)
{
    this->traffic = traffic;
}

unsigned int LteControlInfo::getCid() const
{
    return this->cid;
}

void LteControlInfo::setCid(unsigned int cid)
{
    this->cid = cid;
}

unsigned short LteControlInfo::getQfi() const
{
    return this->qfi;
}

void LteControlInfo::setQfi(unsigned short qfi)
{
    this->qfi = qfi;
}

unsigned short LteControlInfo::getRadioBearerId() const
{
    return this->radioBearerId;
}

void LteControlInfo::setRadioBearerId(unsigned short radioBearerId)
{
    this->radioBearerId = radioBearerId;
}

unsigned int LteControlInfo::getBytesize() const
{
    return this->bytesize;
}

void LteControlInfo::setBytesize(unsigned int bytesize)
{
    this->bytesize = bytesize;
}

unsigned int LteControlInfo::getNumberOfPacketsInQueue() const
{
    return this->numberOfPacketsInQueue;
}

void LteControlInfo::setNumberOfPacketsInQueue(unsigned int numberOfPacketsInQueue)
{
    this->numberOfPacketsInQueue = numberOfPacketsInQueue;
}

unsigned int LteControlInfo::getBytesizeOfOnePacket() const
{
    return this->bytesizeOfOnePacket;
}

void LteControlInfo::setBytesizeOfOnePacket(unsigned int bytesizeOfOnePacket)
{
    this->bytesizeOfOnePacket = bytesizeOfOnePacket;
}

unsigned short LteControlInfo::getRlcType() const
{
    return this->rlcType;
}

void LteControlInfo::setRlcType(unsigned short rlcType)
{
    this->rlcType = rlcType;
}

uint16_t LteControlInfo::getLcid() const
{
    return this->lcid;
}

void LteControlInfo::setLcid(uint16_t lcid)
{
    this->lcid = lcid;
}

int32_t LteControlInfo::getMulticastGroupId() const
{
    return this->multicastGroupId;
}

void LteControlInfo::setMulticastGroupId(int32_t multicastGroupId)
{
    this->multicastGroupId = multicastGroupId;
}

bool LteControlInfo::getContainsSeveralCids() const
{
    return this->containsSeveralCids;
}

void LteControlInfo::setContainsSeveralCids(bool containsSeveralCids)
{
    this->containsSeveralCids = containsSeveralCids;
}

class LteControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sourceId,
        FIELD_destId,
        FIELD_direction,
        FIELD_d2dTxPeerId,
        FIELD_d2dRxPeerId,
        FIELD_application,
        FIELD_traffic,
        FIELD_cid,
        FIELD_qfi,
        FIELD_radioBearerId,
        FIELD_bytesize,
        FIELD_numberOfPacketsInQueue,
        FIELD_bytesizeOfOnePacket,
        FIELD_rlcType,
        FIELD_lcid,
        FIELD_multicastGroupId,
        FIELD_containsSeveralCids,
    };
  public:
    LteControlInfoDescriptor();
    virtual ~LteControlInfoDescriptor();

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

Register_ClassDescriptor(LteControlInfoDescriptor)

LteControlInfoDescriptor::LteControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LteControlInfo)), "inet::TagBase")
{
    propertyNames = nullptr;
}

LteControlInfoDescriptor::~LteControlInfoDescriptor()
{
    delete[] propertyNames;
}

bool LteControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteControlInfo *>(obj)!=nullptr;
}

const char **LteControlInfoDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LteControlInfoDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LteControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 17+base->getFieldCount() : 17;
}

unsigned int LteControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sourceId
        FD_ISEDITABLE,    // FIELD_destId
        FD_ISEDITABLE,    // FIELD_direction
        FD_ISEDITABLE,    // FIELD_d2dTxPeerId
        FD_ISEDITABLE,    // FIELD_d2dRxPeerId
        FD_ISEDITABLE,    // FIELD_application
        FD_ISEDITABLE,    // FIELD_traffic
        FD_ISEDITABLE,    // FIELD_cid
        FD_ISEDITABLE,    // FIELD_qfi
        FD_ISEDITABLE,    // FIELD_radioBearerId
        FD_ISEDITABLE,    // FIELD_bytesize
        FD_ISEDITABLE,    // FIELD_numberOfPacketsInQueue
        FD_ISEDITABLE,    // FIELD_bytesizeOfOnePacket
        FD_ISEDITABLE,    // FIELD_rlcType
        FD_ISEDITABLE,    // FIELD_lcid
        FD_ISEDITABLE,    // FIELD_multicastGroupId
        FD_ISEDITABLE,    // FIELD_containsSeveralCids
    };
    return (field >= 0 && field < 17) ? fieldTypeFlags[field] : 0;
}

const char *LteControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceId",
        "destId",
        "direction",
        "d2dTxPeerId",
        "d2dRxPeerId",
        "application",
        "traffic",
        "cid",
        "qfi",
        "radioBearerId",
        "bytesize",
        "numberOfPacketsInQueue",
        "bytesizeOfOnePacket",
        "rlcType",
        "lcid",
        "multicastGroupId",
        "containsSeveralCids",
    };
    return (field >= 0 && field < 17) ? fieldNames[field] : nullptr;
}

int LteControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sourceId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "destId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "direction") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "d2dTxPeerId") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "d2dRxPeerId") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "application") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "traffic") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "cid") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "qfi") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "radioBearerId") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "bytesize") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "numberOfPacketsInQueue") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "bytesizeOfOnePacket") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "rlcType") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "lcid") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "multicastGroupId") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "containsSeveralCids") == 0) return baseIndex + 16;
    return base ? base->findField(fieldName) : -1;
}

const char *LteControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",    // FIELD_sourceId
        "uint16",    // FIELD_destId
        "unsigned short",    // FIELD_direction
        "uint16",    // FIELD_d2dTxPeerId
        "uint16",    // FIELD_d2dRxPeerId
        "unsigned short",    // FIELD_application
        "unsigned short",    // FIELD_traffic
        "unsigned int",    // FIELD_cid
        "unsigned short",    // FIELD_qfi
        "unsigned short",    // FIELD_radioBearerId
        "unsigned int",    // FIELD_bytesize
        "unsigned int",    // FIELD_numberOfPacketsInQueue
        "unsigned int",    // FIELD_bytesizeOfOnePacket
        "unsigned short",    // FIELD_rlcType
        "uint16",    // FIELD_lcid
        "int32",    // FIELD_multicastGroupId
        "bool",    // FIELD_containsSeveralCids
    };
    return (field >= 0 && field < 17) ? fieldTypeStrings[field] : nullptr;
}

const char **LteControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_direction: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_application: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_traffic: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_rlcType: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *LteControlInfoDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_direction:
            if (!strcmp(propertyName, "enum")) return "Direction";
            if (!strcmp(propertyName, "enum")) return "Direction";
            return nullptr;
        case FIELD_application:
            if (!strcmp(propertyName, "enum")) return "ApplicationType";
            if (!strcmp(propertyName, "enum")) return "ApplicationType";
            return nullptr;
        case FIELD_traffic:
            if (!strcmp(propertyName, "enum")) return "LteTrafficClass";
            if (!strcmp(propertyName, "enum")) return "LteTrafficClass";
            return nullptr;
        case FIELD_rlcType:
            if (!strcmp(propertyName, "enum")) return "LteRlcType";
            if (!strcmp(propertyName, "enum")) return "LteRlcType";
            return nullptr;
        default: return nullptr;
    }
}

int LteControlInfoDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void LteControlInfoDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LteControlInfo'", field);
    }
}

const char *LteControlInfoDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteControlInfoDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_sourceId: return ulong2string(pp->getSourceId());
        case FIELD_destId: return ulong2string(pp->getDestId());
        case FIELD_direction: return enum2string(pp->getDirection(), "Direction");
        case FIELD_d2dTxPeerId: return ulong2string(pp->getD2dTxPeerId());
        case FIELD_d2dRxPeerId: return ulong2string(pp->getD2dRxPeerId());
        case FIELD_application: return enum2string(pp->getApplication(), "ApplicationType");
        case FIELD_traffic: return enum2string(pp->getTraffic(), "LteTrafficClass");
        case FIELD_cid: return ulong2string(pp->getCid());
        case FIELD_qfi: return ulong2string(pp->getQfi());
        case FIELD_radioBearerId: return ulong2string(pp->getRadioBearerId());
        case FIELD_bytesize: return ulong2string(pp->getBytesize());
        case FIELD_numberOfPacketsInQueue: return ulong2string(pp->getNumberOfPacketsInQueue());
        case FIELD_bytesizeOfOnePacket: return ulong2string(pp->getBytesizeOfOnePacket());
        case FIELD_rlcType: return enum2string(pp->getRlcType(), "LteRlcType");
        case FIELD_lcid: return ulong2string(pp->getLcid());
        case FIELD_multicastGroupId: return long2string(pp->getMulticastGroupId());
        case FIELD_containsSeveralCids: return bool2string(pp->getContainsSeveralCids());
        default: return "";
    }
}

void LteControlInfoDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_sourceId: pp->setSourceId(string2ulong(value)); break;
        case FIELD_destId: pp->setDestId(string2ulong(value)); break;
        case FIELD_direction: pp->setDirection((Direction)string2enum(value, "Direction")); break;
        case FIELD_d2dTxPeerId: pp->setD2dTxPeerId(string2ulong(value)); break;
        case FIELD_d2dRxPeerId: pp->setD2dRxPeerId(string2ulong(value)); break;
        case FIELD_application: pp->setApplication((ApplicationType)string2enum(value, "ApplicationType")); break;
        case FIELD_traffic: pp->setTraffic((LteTrafficClass)string2enum(value, "LteTrafficClass")); break;
        case FIELD_cid: pp->setCid(string2ulong(value)); break;
        case FIELD_qfi: pp->setQfi(string2ulong(value)); break;
        case FIELD_radioBearerId: pp->setRadioBearerId(string2ulong(value)); break;
        case FIELD_bytesize: pp->setBytesize(string2ulong(value)); break;
        case FIELD_numberOfPacketsInQueue: pp->setNumberOfPacketsInQueue(string2ulong(value)); break;
        case FIELD_bytesizeOfOnePacket: pp->setBytesizeOfOnePacket(string2ulong(value)); break;
        case FIELD_rlcType: pp->setRlcType((LteRlcType)string2enum(value, "LteRlcType")); break;
        case FIELD_lcid: pp->setLcid(string2ulong(value)); break;
        case FIELD_multicastGroupId: pp->setMulticastGroupId(string2long(value)); break;
        case FIELD_containsSeveralCids: pp->setContainsSeveralCids(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteControlInfo'", field);
    }
}

omnetpp::cValue LteControlInfoDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_sourceId: return (omnetpp::intval_t)(pp->getSourceId());
        case FIELD_destId: return (omnetpp::intval_t)(pp->getDestId());
        case FIELD_direction: return (omnetpp::intval_t)(pp->getDirection());
        case FIELD_d2dTxPeerId: return (omnetpp::intval_t)(pp->getD2dTxPeerId());
        case FIELD_d2dRxPeerId: return (omnetpp::intval_t)(pp->getD2dRxPeerId());
        case FIELD_application: return (omnetpp::intval_t)(pp->getApplication());
        case FIELD_traffic: return (omnetpp::intval_t)(pp->getTraffic());
        case FIELD_cid: return (omnetpp::intval_t)(pp->getCid());
        case FIELD_qfi: return (omnetpp::intval_t)(pp->getQfi());
        case FIELD_radioBearerId: return (omnetpp::intval_t)(pp->getRadioBearerId());
        case FIELD_bytesize: return (omnetpp::intval_t)(pp->getBytesize());
        case FIELD_numberOfPacketsInQueue: return (omnetpp::intval_t)(pp->getNumberOfPacketsInQueue());
        case FIELD_bytesizeOfOnePacket: return (omnetpp::intval_t)(pp->getBytesizeOfOnePacket());
        case FIELD_rlcType: return (omnetpp::intval_t)(pp->getRlcType());
        case FIELD_lcid: return (omnetpp::intval_t)(pp->getLcid());
        case FIELD_multicastGroupId: return pp->getMulticastGroupId();
        case FIELD_containsSeveralCids: return pp->getContainsSeveralCids();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LteControlInfo' as cValue -- field index out of range?", field);
    }
}

void LteControlInfoDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_sourceId: pp->setSourceId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_destId: pp->setDestId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_direction: pp->setDirection((Direction)value.intValue()); break;
        case FIELD_d2dTxPeerId: pp->setD2dTxPeerId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_d2dRxPeerId: pp->setD2dRxPeerId(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_application: pp->setApplication((ApplicationType)value.intValue()); break;
        case FIELD_traffic: pp->setTraffic((LteTrafficClass)value.intValue()); break;
        case FIELD_cid: pp->setCid(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_qfi: pp->setQfi(omnetpp::checked_int_cast<unsigned short>(value.intValue())); break;
        case FIELD_radioBearerId: pp->setRadioBearerId(omnetpp::checked_int_cast<unsigned short>(value.intValue())); break;
        case FIELD_bytesize: pp->setBytesize(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_numberOfPacketsInQueue: pp->setNumberOfPacketsInQueue(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_bytesizeOfOnePacket: pp->setBytesizeOfOnePacket(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_rlcType: pp->setRlcType((LteRlcType)value.intValue()); break;
        case FIELD_lcid: pp->setLcid(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_multicastGroupId: pp->setMulticastGroupId(omnetpp::checked_int_cast<int32_t>(value.intValue())); break;
        case FIELD_containsSeveralCids: pp->setContainsSeveralCids(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteControlInfo'", field);
    }
}

const char *LteControlInfoDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LteControlInfoDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LteControlInfoDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LteControlInfo *pp = omnetpp::fromAnyPtr<LteControlInfo>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteControlInfo'", field);
    }
}

Register_Class(FlowControlInfo)

FlowControlInfo::FlowControlInfo() : ::LteControlInfo()
{
}

FlowControlInfo::FlowControlInfo(const FlowControlInfo& other) : ::LteControlInfo(other)
{
    copy(other);
}

FlowControlInfo::~FlowControlInfo()
{
}

FlowControlInfo& FlowControlInfo::operator=(const FlowControlInfo& other)
{
    if (this == &other) return *this;
    ::LteControlInfo::operator=(other);
    copy(other);
    return *this;
}

void FlowControlInfo::copy(const FlowControlInfo& other)
{
    this->srcAddr = other.srcAddr;
    this->dstAddr = other.dstAddr;
    this->typeOfService = other.typeOfService;
    this->sequenceNumber = other.sequenceNumber;
    this->headerSize = other.headerSize;
    this->useNR = other.useNR;
    this->srcPort = other.srcPort;
    this->dstPort = other.dstPort;
}

void FlowControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::LteControlInfo::parsimPack(b);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->dstAddr);
    doParsimPacking(b,this->typeOfService);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->headerSize);
    doParsimPacking(b,this->useNR);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->dstPort);
}

void FlowControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::LteControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->dstAddr);
    doParsimUnpacking(b,this->typeOfService);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->headerSize);
    doParsimUnpacking(b,this->useNR);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->dstPort);
}

uint32_t FlowControlInfo::getSrcAddr() const
{
    return this->srcAddr;
}

void FlowControlInfo::setSrcAddr(uint32_t srcAddr)
{
    this->srcAddr = srcAddr;
}

uint32_t FlowControlInfo::getDstAddr() const
{
    return this->dstAddr;
}

void FlowControlInfo::setDstAddr(uint32_t dstAddr)
{
    this->dstAddr = dstAddr;
}

uint16_t FlowControlInfo::getTypeOfService() const
{
    return this->typeOfService;
}

void FlowControlInfo::setTypeOfService(uint16_t typeOfService)
{
    this->typeOfService = typeOfService;
}

unsigned int FlowControlInfo::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void FlowControlInfo::setSequenceNumber(unsigned int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

int FlowControlInfo::getHeaderSize() const
{
    return this->headerSize;
}

void FlowControlInfo::setHeaderSize(int headerSize)
{
    this->headerSize = headerSize;
}

bool FlowControlInfo::getUseNR() const
{
    return this->useNR;
}

void FlowControlInfo::setUseNR(bool useNR)
{
    this->useNR = useNR;
}

uint16_t FlowControlInfo::getSrcPort() const
{
    return this->srcPort;
}

void FlowControlInfo::setSrcPort(uint16_t srcPort)
{
    this->srcPort = srcPort;
}

uint16_t FlowControlInfo::getDstPort() const
{
    return this->dstPort;
}

void FlowControlInfo::setDstPort(uint16_t dstPort)
{
    this->dstPort = dstPort;
}

class FlowControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddr,
        FIELD_dstAddr,
        FIELD_typeOfService,
        FIELD_sequenceNumber,
        FIELD_headerSize,
        FIELD_useNR,
        FIELD_srcPort,
        FIELD_dstPort,
    };
  public:
    FlowControlInfoDescriptor();
    virtual ~FlowControlInfoDescriptor();

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

Register_ClassDescriptor(FlowControlInfoDescriptor)

FlowControlInfoDescriptor::FlowControlInfoDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(FlowControlInfo)), "LteControlInfo")
{
    propertyNames = nullptr;
}

FlowControlInfoDescriptor::~FlowControlInfoDescriptor()
{
    delete[] propertyNames;
}

bool FlowControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<FlowControlInfo *>(obj)!=nullptr;
}

const char **FlowControlInfoDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *FlowControlInfoDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int FlowControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 8+base->getFieldCount() : 8;
}

unsigned int FlowControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_srcAddr
        FD_ISEDITABLE,    // FIELD_dstAddr
        FD_ISEDITABLE,    // FIELD_typeOfService
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_headerSize
        FD_ISEDITABLE,    // FIELD_useNR
        FD_ISEDITABLE,    // FIELD_srcPort
        FD_ISEDITABLE,    // FIELD_dstPort
    };
    return (field >= 0 && field < 8) ? fieldTypeFlags[field] : 0;
}

const char *FlowControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddr",
        "dstAddr",
        "typeOfService",
        "sequenceNumber",
        "headerSize",
        "useNR",
        "srcPort",
        "dstPort",
    };
    return (field >= 0 && field < 8) ? fieldNames[field] : nullptr;
}

int FlowControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddr") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "dstAddr") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "typeOfService") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "headerSize") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "useNR") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "srcPort") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "dstPort") == 0) return baseIndex + 7;
    return base ? base->findField(fieldName) : -1;
}

const char *FlowControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",    // FIELD_srcAddr
        "uint32",    // FIELD_dstAddr
        "uint16",    // FIELD_typeOfService
        "unsigned int",    // FIELD_sequenceNumber
        "int",    // FIELD_headerSize
        "bool",    // FIELD_useNR
        "uint16",    // FIELD_srcPort
        "uint16",    // FIELD_dstPort
    };
    return (field >= 0 && field < 8) ? fieldTypeStrings[field] : nullptr;
}

const char **FlowControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *FlowControlInfoDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int FlowControlInfoDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void FlowControlInfoDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'FlowControlInfo'", field);
    }
}

const char *FlowControlInfoDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string FlowControlInfoDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: return ulong2string(pp->getSrcAddr());
        case FIELD_dstAddr: return ulong2string(pp->getDstAddr());
        case FIELD_typeOfService: return ulong2string(pp->getTypeOfService());
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_headerSize: return long2string(pp->getHeaderSize());
        case FIELD_useNR: return bool2string(pp->getUseNR());
        case FIELD_srcPort: return ulong2string(pp->getSrcPort());
        case FIELD_dstPort: return ulong2string(pp->getDstPort());
        default: return "";
    }
}

void FlowControlInfoDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: pp->setSrcAddr(string2ulong(value)); break;
        case FIELD_dstAddr: pp->setDstAddr(string2ulong(value)); break;
        case FIELD_typeOfService: pp->setTypeOfService(string2ulong(value)); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); break;
        case FIELD_headerSize: pp->setHeaderSize(string2long(value)); break;
        case FIELD_useNR: pp->setUseNR(string2bool(value)); break;
        case FIELD_srcPort: pp->setSrcPort(string2ulong(value)); break;
        case FIELD_dstPort: pp->setDstPort(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'FlowControlInfo'", field);
    }
}

omnetpp::cValue FlowControlInfoDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: return (omnetpp::intval_t)(pp->getSrcAddr());
        case FIELD_dstAddr: return (omnetpp::intval_t)(pp->getDstAddr());
        case FIELD_typeOfService: return (omnetpp::intval_t)(pp->getTypeOfService());
        case FIELD_sequenceNumber: return (omnetpp::intval_t)(pp->getSequenceNumber());
        case FIELD_headerSize: return pp->getHeaderSize();
        case FIELD_useNR: return pp->getUseNR();
        case FIELD_srcPort: return (omnetpp::intval_t)(pp->getSrcPort());
        case FIELD_dstPort: return (omnetpp::intval_t)(pp->getDstPort());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'FlowControlInfo' as cValue -- field index out of range?", field);
    }
}

void FlowControlInfoDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: pp->setSrcAddr(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_dstAddr: pp->setDstAddr(omnetpp::checked_int_cast<uint32_t>(value.intValue())); break;
        case FIELD_typeOfService: pp->setTypeOfService(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_headerSize: pp->setHeaderSize(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_useNR: pp->setUseNR(value.boolValue()); break;
        case FIELD_srcPort: pp->setSrcPort(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        case FIELD_dstPort: pp->setDstPort(omnetpp::checked_int_cast<uint16_t>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'FlowControlInfo'", field);
    }
}

const char *FlowControlInfoDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr FlowControlInfoDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void FlowControlInfoDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    FlowControlInfo *pp = omnetpp::fromAnyPtr<FlowControlInfo>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'FlowControlInfo'", field);
    }
}

UserControlInfo_Base::UserControlInfo_Base() : ::LteControlInfo()
{
}

UserControlInfo_Base::UserControlInfo_Base(const UserControlInfo_Base& other) : ::LteControlInfo(other)
{
    copy(other);
}

UserControlInfo_Base::~UserControlInfo_Base()
{
}

UserControlInfo_Base& UserControlInfo_Base::operator=(const UserControlInfo_Base& other)
{
    if (this == &other) return *this;
    ::LteControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UserControlInfo_Base::copy(const UserControlInfo_Base& other)
{
    this->isNr_ = other.isNr_;
    this->carrierFrequency = other.carrierFrequency;
    this->acid = other.acid;
    this->cw = other.cw;
    this->txNumber = other.txNumber;
    this->ndi = other.ndi;
    this->isCorruptible_ = other.isCorruptible_;
    this->isBroadcast_ = other.isBroadcast_;
    this->deciderResult = other.deciderResult;
    this->blerTh = other.blerTh;
    this->blerValue = other.blerValue;
    this->txMode = other.txMode;
    this->frameType = other.frameType;
    this->txPower = other.txPower;
    this->d2dTxPower = other.d2dTxPower;
    this->totalGrantedBlocks = other.totalGrantedBlocks;
    this->grantId = other.grantId;
}

void UserControlInfo_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::LteControlInfo::parsimPack(b);
    doParsimPacking(b,this->isNr_);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->acid);
    doParsimPacking(b,this->cw);
    doParsimPacking(b,this->txNumber);
    doParsimPacking(b,this->ndi);
    doParsimPacking(b,this->isCorruptible_);
    doParsimPacking(b,this->isBroadcast_);
    doParsimPacking(b,this->deciderResult);
    doParsimPacking(b,this->blerTh);
    doParsimPacking(b,this->blerValue);
    doParsimPacking(b,this->txMode);
    doParsimPacking(b,this->frameType);
    doParsimPacking(b,this->txPower);
    doParsimPacking(b,this->d2dTxPower);
    doParsimPacking(b,this->totalGrantedBlocks);
    doParsimPacking(b,this->grantId);
}

void UserControlInfo_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::LteControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->isNr_);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->acid);
    doParsimUnpacking(b,this->cw);
    doParsimUnpacking(b,this->txNumber);
    doParsimUnpacking(b,this->ndi);
    doParsimUnpacking(b,this->isCorruptible_);
    doParsimUnpacking(b,this->isBroadcast_);
    doParsimUnpacking(b,this->deciderResult);
    doParsimUnpacking(b,this->blerTh);
    doParsimUnpacking(b,this->blerValue);
    doParsimUnpacking(b,this->txMode);
    doParsimUnpacking(b,this->frameType);
    doParsimUnpacking(b,this->txPower);
    doParsimUnpacking(b,this->d2dTxPower);
    doParsimUnpacking(b,this->totalGrantedBlocks);
    doParsimUnpacking(b,this->grantId);
}

bool UserControlInfo_Base::isNr() const
{
    return this->isNr_;
}

void UserControlInfo_Base::setIsNr(bool isNr)
{
    this->isNr_ = isNr;
}

double UserControlInfo_Base::getCarrierFrequency() const
{
    return this->carrierFrequency;
}

void UserControlInfo_Base::setCarrierFrequency(double carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

unsigned char UserControlInfo_Base::getAcid() const
{
    return this->acid;
}

void UserControlInfo_Base::setAcid(unsigned char acid)
{
    this->acid = acid;
}

unsigned char UserControlInfo_Base::getCw() const
{
    return this->cw;
}

void UserControlInfo_Base::setCw(unsigned char cw)
{
    this->cw = cw;
}

unsigned char UserControlInfo_Base::getTxNumber() const
{
    return this->txNumber;
}

void UserControlInfo_Base::setTxNumber(unsigned char txNumber)
{
    this->txNumber = txNumber;
}

bool UserControlInfo_Base::getNdi() const
{
    return this->ndi;
}

void UserControlInfo_Base::setNdi(bool ndi)
{
    this->ndi = ndi;
}

bool UserControlInfo_Base::isCorruptible() const
{
    return this->isCorruptible_;
}

void UserControlInfo_Base::setIsCorruptible(bool isCorruptible)
{
    this->isCorruptible_ = isCorruptible;
}

bool UserControlInfo_Base::isBroadcast() const
{
    return this->isBroadcast_;
}

void UserControlInfo_Base::setIsBroadcast(bool isBroadcast)
{
    this->isBroadcast_ = isBroadcast;
}

bool UserControlInfo_Base::getDeciderResult() const
{
    return this->deciderResult;
}

void UserControlInfo_Base::setDeciderResult(bool deciderResult)
{
    this->deciderResult = deciderResult;
}

double UserControlInfo_Base::getBlerTh() const
{
    return this->blerTh;
}

void UserControlInfo_Base::setBlerTh(double blerTh)
{
    this->blerTh = blerTh;
}

double UserControlInfo_Base::getBlerValue() const
{
    return this->blerValue;
}

void UserControlInfo_Base::setBlerValue(double blerValue)
{
    this->blerValue = blerValue;
}

unsigned short UserControlInfo_Base::getTxMode() const
{
    return this->txMode;
}

void UserControlInfo_Base::setTxMode(unsigned short txMode)
{
    this->txMode = txMode;
}

unsigned int UserControlInfo_Base::getFrameType() const
{
    return this->frameType;
}

void UserControlInfo_Base::setFrameType(unsigned int frameType)
{
    this->frameType = frameType;
}

double UserControlInfo_Base::getTxPower() const
{
    return this->txPower;
}

void UserControlInfo_Base::setTxPower(double txPower)
{
    this->txPower = txPower;
}

double UserControlInfo_Base::getD2dTxPower() const
{
    return this->d2dTxPower;
}

void UserControlInfo_Base::setD2dTxPower(double d2dTxPower)
{
    this->d2dTxPower = d2dTxPower;
}

unsigned int UserControlInfo_Base::getTotalGrantedBlocks() const
{
    return this->totalGrantedBlocks;
}

void UserControlInfo_Base::setTotalGrantedBlocks(unsigned int totalGrantedBlocks)
{
    this->totalGrantedBlocks = totalGrantedBlocks;
}

unsigned int UserControlInfo_Base::getGrantId() const
{
    return this->grantId;
}

void UserControlInfo_Base::setGrantId(unsigned int grantId)
{
    this->grantId = grantId;
}

class UserControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_isNr,
        FIELD_carrierFrequency,
        FIELD_acid,
        FIELD_cw,
        FIELD_txNumber,
        FIELD_ndi,
        FIELD_isCorruptible,
        FIELD_isBroadcast,
        FIELD_deciderResult,
        FIELD_blerTh,
        FIELD_blerValue,
        FIELD_txMode,
        FIELD_frameType,
        FIELD_txPower,
        FIELD_d2dTxPower,
        FIELD_totalGrantedBlocks,
        FIELD_grantId,
    };
  public:
    UserControlInfoDescriptor();
    virtual ~UserControlInfoDescriptor();

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

Register_ClassDescriptor(UserControlInfoDescriptor)

UserControlInfoDescriptor::UserControlInfoDescriptor() : omnetpp::cClassDescriptor("UserControlInfo", "LteControlInfo")
{
    propertyNames = nullptr;
}

UserControlInfoDescriptor::~UserControlInfoDescriptor()
{
    delete[] propertyNames;
}

bool UserControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UserControlInfo_Base *>(obj)!=nullptr;
}

const char **UserControlInfoDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UserControlInfoDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "customize")) return "true";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UserControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 17+base->getFieldCount() : 17;
}

unsigned int UserControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_isNr
        FD_ISEDITABLE,    // FIELD_carrierFrequency
        FD_ISEDITABLE,    // FIELD_acid
        FD_ISEDITABLE,    // FIELD_cw
        FD_ISEDITABLE,    // FIELD_txNumber
        FD_ISEDITABLE,    // FIELD_ndi
        FD_ISEDITABLE,    // FIELD_isCorruptible
        FD_ISEDITABLE,    // FIELD_isBroadcast
        FD_ISEDITABLE,    // FIELD_deciderResult
        FD_ISEDITABLE,    // FIELD_blerTh
        FD_ISEDITABLE,    // FIELD_blerValue
        FD_ISEDITABLE,    // FIELD_txMode
        FD_ISEDITABLE,    // FIELD_frameType
        FD_ISEDITABLE,    // FIELD_txPower
        FD_ISEDITABLE,    // FIELD_d2dTxPower
        FD_ISEDITABLE,    // FIELD_totalGrantedBlocks
        FD_ISEDITABLE,    // FIELD_grantId
    };
    return (field >= 0 && field < 17) ? fieldTypeFlags[field] : 0;
}

const char *UserControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isNr",
        "carrierFrequency",
        "acid",
        "cw",
        "txNumber",
        "ndi",
        "isCorruptible",
        "isBroadcast",
        "deciderResult",
        "blerTh",
        "blerValue",
        "txMode",
        "frameType",
        "txPower",
        "d2dTxPower",
        "totalGrantedBlocks",
        "grantId",
    };
    return (field >= 0 && field < 17) ? fieldNames[field] : nullptr;
}

int UserControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "isNr") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "carrierFrequency") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "acid") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "cw") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "txNumber") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "ndi") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "isCorruptible") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "isBroadcast") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "deciderResult") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "blerTh") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "blerValue") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "txMode") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "frameType") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "txPower") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "d2dTxPower") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "totalGrantedBlocks") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "grantId") == 0) return baseIndex + 16;
    return base ? base->findField(fieldName) : -1;
}

const char *UserControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",    // FIELD_isNr
        "double",    // FIELD_carrierFrequency
        "unsigned char",    // FIELD_acid
        "unsigned char",    // FIELD_cw
        "unsigned char",    // FIELD_txNumber
        "bool",    // FIELD_ndi
        "bool",    // FIELD_isCorruptible
        "bool",    // FIELD_isBroadcast
        "bool",    // FIELD_deciderResult
        "double",    // FIELD_blerTh
        "double",    // FIELD_blerValue
        "unsigned short",    // FIELD_txMode
        "unsigned int",    // FIELD_frameType
        "double",    // FIELD_txPower
        "double",    // FIELD_d2dTxPower
        "unsigned int",    // FIELD_totalGrantedBlocks
        "unsigned int",    // FIELD_grantId
    };
    return (field >= 0 && field < 17) ? fieldTypeStrings[field] : nullptr;
}

const char **UserControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_txMode: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_frameType: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *UserControlInfoDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_txMode:
            if (!strcmp(propertyName, "enum")) return "TxMode";
            if (!strcmp(propertyName, "enum")) return "TxMode";
            return nullptr;
        case FIELD_frameType:
            if (!strcmp(propertyName, "enum")) return "LtePhyFrameType";
            if (!strcmp(propertyName, "enum")) return "LtePhyFrameType";
            return nullptr;
        default: return nullptr;
    }
}

int UserControlInfoDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UserControlInfoDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UserControlInfo_Base'", field);
    }
}

const char *UserControlInfoDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UserControlInfoDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        case FIELD_isNr: return bool2string(pp->isNr());
        case FIELD_carrierFrequency: return double2string(pp->getCarrierFrequency());
        case FIELD_acid: return ulong2string(pp->getAcid());
        case FIELD_cw: return ulong2string(pp->getCw());
        case FIELD_txNumber: return ulong2string(pp->getTxNumber());
        case FIELD_ndi: return bool2string(pp->getNdi());
        case FIELD_isCorruptible: return bool2string(pp->isCorruptible());
        case FIELD_isBroadcast: return bool2string(pp->isBroadcast());
        case FIELD_deciderResult: return bool2string(pp->getDeciderResult());
        case FIELD_blerTh: return double2string(pp->getBlerTh());
        case FIELD_blerValue: return double2string(pp->getBlerValue());
        case FIELD_txMode: return enum2string(pp->getTxMode(), "TxMode");
        case FIELD_frameType: return enum2string(pp->getFrameType(), "LtePhyFrameType");
        case FIELD_txPower: return double2string(pp->getTxPower());
        case FIELD_d2dTxPower: return double2string(pp->getD2dTxPower());
        case FIELD_totalGrantedBlocks: return ulong2string(pp->getTotalGrantedBlocks());
        case FIELD_grantId: return ulong2string(pp->getGrantId());
        default: return "";
    }
}

void UserControlInfoDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        case FIELD_isNr: pp->setIsNr(string2bool(value)); break;
        case FIELD_carrierFrequency: pp->setCarrierFrequency(string2double(value)); break;
        case FIELD_acid: pp->setAcid(string2ulong(value)); break;
        case FIELD_cw: pp->setCw(string2ulong(value)); break;
        case FIELD_txNumber: pp->setTxNumber(string2ulong(value)); break;
        case FIELD_ndi: pp->setNdi(string2bool(value)); break;
        case FIELD_isCorruptible: pp->setIsCorruptible(string2bool(value)); break;
        case FIELD_isBroadcast: pp->setIsBroadcast(string2bool(value)); break;
        case FIELD_deciderResult: pp->setDeciderResult(string2bool(value)); break;
        case FIELD_blerTh: pp->setBlerTh(string2double(value)); break;
        case FIELD_blerValue: pp->setBlerValue(string2double(value)); break;
        case FIELD_txMode: pp->setTxMode((TxMode)string2enum(value, "TxMode")); break;
        case FIELD_frameType: pp->setFrameType((LtePhyFrameType)string2enum(value, "LtePhyFrameType")); break;
        case FIELD_txPower: pp->setTxPower(string2double(value)); break;
        case FIELD_d2dTxPower: pp->setD2dTxPower(string2double(value)); break;
        case FIELD_totalGrantedBlocks: pp->setTotalGrantedBlocks(string2ulong(value)); break;
        case FIELD_grantId: pp->setGrantId(string2ulong(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UserControlInfo_Base'", field);
    }
}

omnetpp::cValue UserControlInfoDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        case FIELD_isNr: return pp->isNr();
        case FIELD_carrierFrequency: return pp->getCarrierFrequency();
        case FIELD_acid: return (omnetpp::intval_t)(pp->getAcid());
        case FIELD_cw: return (omnetpp::intval_t)(pp->getCw());
        case FIELD_txNumber: return (omnetpp::intval_t)(pp->getTxNumber());
        case FIELD_ndi: return pp->getNdi();
        case FIELD_isCorruptible: return pp->isCorruptible();
        case FIELD_isBroadcast: return pp->isBroadcast();
        case FIELD_deciderResult: return pp->getDeciderResult();
        case FIELD_blerTh: return pp->getBlerTh();
        case FIELD_blerValue: return pp->getBlerValue();
        case FIELD_txMode: return (omnetpp::intval_t)(pp->getTxMode());
        case FIELD_frameType: return (omnetpp::intval_t)(pp->getFrameType());
        case FIELD_txPower: return pp->getTxPower();
        case FIELD_d2dTxPower: return pp->getD2dTxPower();
        case FIELD_totalGrantedBlocks: return (omnetpp::intval_t)(pp->getTotalGrantedBlocks());
        case FIELD_grantId: return (omnetpp::intval_t)(pp->getGrantId());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UserControlInfo_Base' as cValue -- field index out of range?", field);
    }
}

void UserControlInfoDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        case FIELD_isNr: pp->setIsNr(value.boolValue()); break;
        case FIELD_carrierFrequency: pp->setCarrierFrequency(value.doubleValue()); break;
        case FIELD_acid: pp->setAcid(omnetpp::checked_int_cast<unsigned char>(value.intValue())); break;
        case FIELD_cw: pp->setCw(omnetpp::checked_int_cast<unsigned char>(value.intValue())); break;
        case FIELD_txNumber: pp->setTxNumber(omnetpp::checked_int_cast<unsigned char>(value.intValue())); break;
        case FIELD_ndi: pp->setNdi(value.boolValue()); break;
        case FIELD_isCorruptible: pp->setIsCorruptible(value.boolValue()); break;
        case FIELD_isBroadcast: pp->setIsBroadcast(value.boolValue()); break;
        case FIELD_deciderResult: pp->setDeciderResult(value.boolValue()); break;
        case FIELD_blerTh: pp->setBlerTh(value.doubleValue()); break;
        case FIELD_blerValue: pp->setBlerValue(value.doubleValue()); break;
        case FIELD_txMode: pp->setTxMode((TxMode)value.intValue()); break;
        case FIELD_frameType: pp->setFrameType((LtePhyFrameType)value.intValue()); break;
        case FIELD_txPower: pp->setTxPower(value.doubleValue()); break;
        case FIELD_d2dTxPower: pp->setD2dTxPower(value.doubleValue()); break;
        case FIELD_totalGrantedBlocks: pp->setTotalGrantedBlocks(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        case FIELD_grantId: pp->setGrantId(omnetpp::checked_int_cast<unsigned int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UserControlInfo_Base'", field);
    }
}

const char *UserControlInfoDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr UserControlInfoDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UserControlInfoDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UserControlInfo_Base *pp = omnetpp::fromAnyPtr<UserControlInfo_Base>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UserControlInfo_Base'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

