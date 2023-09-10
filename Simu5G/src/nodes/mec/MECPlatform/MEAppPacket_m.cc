//
// Generated file, do not edit! Created by opp_msgtool 6.0 from nodes/mec/MECPlatform/MEAppPacket.msg.
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
#include "MEAppPacket_m.h"

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

Register_Class(MEAppPacket)

MEAppPacket::MEAppPacket() : ::inet::FieldsChunk()
{
}

MEAppPacket::MEAppPacket(const MEAppPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

MEAppPacket::~MEAppPacket()
{
}

MEAppPacket& MEAppPacket::operator=(const MEAppPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void MEAppPacket::copy(const MEAppPacket& other)
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

void MEAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
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

void MEAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
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

unsigned int MEAppPacket::getSno() const
{
    return this->sno;
}

void MEAppPacket::setSno(unsigned int sno)
{
    handleChange();
    this->sno = sno;
}

omnetpp::simtime_t MEAppPacket::getTimestamp() const
{
    return this->timestamp;
}

void MEAppPacket::setTimestamp(omnetpp::simtime_t timestamp)
{
    handleChange();
    this->timestamp = timestamp;
}

const char * MEAppPacket::getType() const
{
    return this->type.c_str();
}

void MEAppPacket::setType(const char * type)
{
    handleChange();
    this->type = type;
}

const char * MEAppPacket::getSourceAddress() const
{
    return this->sourceAddress.c_str();
}

void MEAppPacket::setSourceAddress(const char * sourceAddress)
{
    handleChange();
    this->sourceAddress = sourceAddress;
}

int MEAppPacket::getSourcePort() const
{
    return this->sourcePort;
}

void MEAppPacket::setSourcePort(int sourcePort)
{
    handleChange();
    this->sourcePort = sourcePort;
}

const char * MEAppPacket::getDestinationAddress() const
{
    return this->destinationAddress.c_str();
}

void MEAppPacket::setDestinationAddress(const char * destinationAddress)
{
    handleChange();
    this->destinationAddress = destinationAddress;
}

int MEAppPacket::getDestinationPort() const
{
    return this->destinationPort;
}

void MEAppPacket::setDestinationPort(int destinationPort)
{
    handleChange();
    this->destinationPort = destinationPort;
}

const char * MEAppPacket::getDestinationMecAppAddress() const
{
    return this->destinationMecAppAddress.c_str();
}

void MEAppPacket::setDestinationMecAppAddress(const char * destinationMecAppAddress)
{
    handleChange();
    this->destinationMecAppAddress = destinationMecAppAddress;
}

int MEAppPacket::getDestinationMecAppPort() const
{
    return this->destinationMecAppPort;
}

void MEAppPacket::setDestinationMecAppPort(int destinationMecAppPort)
{
    handleChange();
    this->destinationMecAppPort = destinationMecAppPort;
}

const char * MEAppPacket::getMEModuleType() const
{
    return this->MEModuleType.c_str();
}

void MEAppPacket::setMEModuleType(const char * MEModuleType)
{
    handleChange();
    this->MEModuleType = MEModuleType;
}

const char * MEAppPacket::getMEModuleName() const
{
    return this->MEModuleName.c_str();
}

void MEAppPacket::setMEModuleName(const char * MEModuleName)
{
    handleChange();
    this->MEModuleName = MEModuleName;
}

int MEAppPacket::getUeAppID() const
{
    return this->ueAppID;
}

void MEAppPacket::setUeAppID(int ueAppID)
{
    handleChange();
    this->ueAppID = ueAppID;
}

double MEAppPacket::getRequiredDisk() const
{
    return this->requiredDisk;
}

void MEAppPacket::setRequiredDisk(double requiredDisk)
{
    handleChange();
    this->requiredDisk = requiredDisk;
}

double MEAppPacket::getRequiredRam() const
{
    return this->requiredRam;
}

void MEAppPacket::setRequiredRam(double requiredRam)
{
    handleChange();
    this->requiredRam = requiredRam;
}

double MEAppPacket::getRequiredCpu() const
{
    return this->requiredCpu;
}

void MEAppPacket::setRequiredCpu(double requiredCpu)
{
    handleChange();
    this->requiredCpu = requiredCpu;
}

const char * MEAppPacket::getRequiredService() const
{
    return this->requiredService.c_str();
}

void MEAppPacket::setRequiredService(const char * requiredService)
{
    handleChange();
    this->requiredService = requiredService;
}

class MEAppPacketDescriptor : public omnetpp::cClassDescriptor
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
    MEAppPacketDescriptor();
    virtual ~MEAppPacketDescriptor();

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

Register_ClassDescriptor(MEAppPacketDescriptor)

MEAppPacketDescriptor::MEAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MEAppPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

MEAppPacketDescriptor::~MEAppPacketDescriptor()
{
    delete[] propertyNames;
}

bool MEAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MEAppPacket *>(obj)!=nullptr;
}

const char **MEAppPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MEAppPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MEAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 16+base->getFieldCount() : 16;
}

unsigned int MEAppPacketDescriptor::getFieldTypeFlags(int field) const
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

const char *MEAppPacketDescriptor::getFieldName(int field) const
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

int MEAppPacketDescriptor::findField(const char *fieldName) const
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

const char *MEAppPacketDescriptor::getFieldTypeString(int field) const
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
        "double",    // FIELD_requiredDisk
        "double",    // FIELD_requiredRam
        "double",    // FIELD_requiredCpu
        "string",    // FIELD_requiredService
    };
    return (field >= 0 && field < 16) ? fieldTypeStrings[field] : nullptr;
}

const char **MEAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *MEAppPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MEAppPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MEAppPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MEAppPacket'", field);
    }
}

const char *MEAppPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MEAppPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
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
        case FIELD_requiredDisk: return double2string(pp->getRequiredDisk());
        case FIELD_requiredRam: return double2string(pp->getRequiredRam());
        case FIELD_requiredCpu: return double2string(pp->getRequiredCpu());
        case FIELD_requiredService: return oppstring2string(pp->getRequiredService());
        default: return "";
    }
}

void MEAppPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
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
        case FIELD_requiredDisk: pp->setRequiredDisk(string2double(value)); break;
        case FIELD_requiredRam: pp->setRequiredRam(string2double(value)); break;
        case FIELD_requiredCpu: pp->setRequiredCpu(string2double(value)); break;
        case FIELD_requiredService: pp->setRequiredService((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MEAppPacket'", field);
    }
}

omnetpp::cValue MEAppPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
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
        case FIELD_requiredDisk: return pp->getRequiredDisk();
        case FIELD_requiredRam: return pp->getRequiredRam();
        case FIELD_requiredCpu: return pp->getRequiredCpu();
        case FIELD_requiredService: return pp->getRequiredService();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MEAppPacket' as cValue -- field index out of range?", field);
    }
}

void MEAppPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
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
        case FIELD_requiredDisk: pp->setRequiredDisk(value.doubleValue()); break;
        case FIELD_requiredRam: pp->setRequiredRam(value.doubleValue()); break;
        case FIELD_requiredCpu: pp->setRequiredCpu(value.doubleValue()); break;
        case FIELD_requiredService: pp->setRequiredService(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MEAppPacket'", field);
    }
}

const char *MEAppPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MEAppPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MEAppPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MEAppPacket *pp = omnetpp::fromAnyPtr<MEAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MEAppPacket'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

