//
// Generated file, do not edit! Created by opp_msgtool 6.0 from apps/mec/RealTimeVideoStreamingApp/packets/RTVideoStreamingPackets.msg.
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
#include "RTVideoStreamingPackets_m.h"

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

Register_Class(RealTimeVideoStreamingAppPacket)

RealTimeVideoStreamingAppPacket::RealTimeVideoStreamingAppPacket() : ::inet::FieldsChunk()
{
}

RealTimeVideoStreamingAppPacket::RealTimeVideoStreamingAppPacket(const RealTimeVideoStreamingAppPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

RealTimeVideoStreamingAppPacket::~RealTimeVideoStreamingAppPacket()
{
}

RealTimeVideoStreamingAppPacket& RealTimeVideoStreamingAppPacket::operator=(const RealTimeVideoStreamingAppPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void RealTimeVideoStreamingAppPacket::copy(const RealTimeVideoStreamingAppPacket& other)
{
    this->type = other.type;
}

void RealTimeVideoStreamingAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->type);
}

void RealTimeVideoStreamingAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
}

int RealTimeVideoStreamingAppPacket::getType() const
{
    return this->type;
}

void RealTimeVideoStreamingAppPacket::setType(int type)
{
    handleChange();
    this->type = type;
}

class RealTimeVideoStreamingAppPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_type,
    };
  public:
    RealTimeVideoStreamingAppPacketDescriptor();
    virtual ~RealTimeVideoStreamingAppPacketDescriptor();

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

Register_ClassDescriptor(RealTimeVideoStreamingAppPacketDescriptor)

RealTimeVideoStreamingAppPacketDescriptor::RealTimeVideoStreamingAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(RealTimeVideoStreamingAppPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

RealTimeVideoStreamingAppPacketDescriptor::~RealTimeVideoStreamingAppPacketDescriptor()
{
    delete[] propertyNames;
}

bool RealTimeVideoStreamingAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RealTimeVideoStreamingAppPacket *>(obj)!=nullptr;
}

const char **RealTimeVideoStreamingAppPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RealTimeVideoStreamingAppPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RealTimeVideoStreamingAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int RealTimeVideoStreamingAppPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_type
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *RealTimeVideoStreamingAppPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int RealTimeVideoStreamingAppPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *RealTimeVideoStreamingAppPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_type
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **RealTimeVideoStreamingAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RealTimeVideoStreamingAppPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int RealTimeVideoStreamingAppPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RealTimeVideoStreamingAppPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'RealTimeVideoStreamingAppPacket'", field);
    }
}

const char *RealTimeVideoStreamingAppPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RealTimeVideoStreamingAppPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: return long2string(pp->getType());
        default: return "";
    }
}

void RealTimeVideoStreamingAppPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RealTimeVideoStreamingAppPacket'", field);
    }
}

omnetpp::cValue RealTimeVideoStreamingAppPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: return pp->getType();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'RealTimeVideoStreamingAppPacket' as cValue -- field index out of range?", field);
    }
}

void RealTimeVideoStreamingAppPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_type: pp->setType(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RealTimeVideoStreamingAppPacket'", field);
    }
}

const char *RealTimeVideoStreamingAppPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr RealTimeVideoStreamingAppPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RealTimeVideoStreamingAppPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RealTimeVideoStreamingAppPacket'", field);
    }
}

Register_Class(StartRealTimeVideoStreamingAppPacket)

StartRealTimeVideoStreamingAppPacket::StartRealTimeVideoStreamingAppPacket() : ::RealTimeVideoStreamingAppPacket()
{
}

StartRealTimeVideoStreamingAppPacket::StartRealTimeVideoStreamingAppPacket(const StartRealTimeVideoStreamingAppPacket& other) : ::RealTimeVideoStreamingAppPacket(other)
{
    copy(other);
}

StartRealTimeVideoStreamingAppPacket::~StartRealTimeVideoStreamingAppPacket()
{
}

StartRealTimeVideoStreamingAppPacket& StartRealTimeVideoStreamingAppPacket::operator=(const StartRealTimeVideoStreamingAppPacket& other)
{
    if (this == &other) return *this;
    ::RealTimeVideoStreamingAppPacket::operator=(other);
    copy(other);
    return *this;
}

void StartRealTimeVideoStreamingAppPacket::copy(const StartRealTimeVideoStreamingAppPacket& other)
{
    this->fps = other.fps;
    this->codec = other.codec;
    this->sessionId = other.sessionId;
}

void StartRealTimeVideoStreamingAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::RealTimeVideoStreamingAppPacket::parsimPack(b);
    doParsimPacking(b,this->fps);
    doParsimPacking(b,this->codec);
    doParsimPacking(b,this->sessionId);
}

void StartRealTimeVideoStreamingAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::RealTimeVideoStreamingAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->fps);
    doParsimUnpacking(b,this->codec);
    doParsimUnpacking(b,this->sessionId);
}

int StartRealTimeVideoStreamingAppPacket::getFps() const
{
    return this->fps;
}

void StartRealTimeVideoStreamingAppPacket::setFps(int fps)
{
    handleChange();
    this->fps = fps;
}

const char * StartRealTimeVideoStreamingAppPacket::getCodec() const
{
    return this->codec.c_str();
}

void StartRealTimeVideoStreamingAppPacket::setCodec(const char * codec)
{
    handleChange();
    this->codec = codec;
}

int StartRealTimeVideoStreamingAppPacket::getSessionId() const
{
    return this->sessionId;
}

void StartRealTimeVideoStreamingAppPacket::setSessionId(int sessionId)
{
    handleChange();
    this->sessionId = sessionId;
}

class StartRealTimeVideoStreamingAppPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_fps,
        FIELD_codec,
        FIELD_sessionId,
    };
  public:
    StartRealTimeVideoStreamingAppPacketDescriptor();
    virtual ~StartRealTimeVideoStreamingAppPacketDescriptor();

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

Register_ClassDescriptor(StartRealTimeVideoStreamingAppPacketDescriptor)

StartRealTimeVideoStreamingAppPacketDescriptor::StartRealTimeVideoStreamingAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(StartRealTimeVideoStreamingAppPacket)), "RealTimeVideoStreamingAppPacket")
{
    propertyNames = nullptr;
}

StartRealTimeVideoStreamingAppPacketDescriptor::~StartRealTimeVideoStreamingAppPacketDescriptor()
{
    delete[] propertyNames;
}

bool StartRealTimeVideoStreamingAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<StartRealTimeVideoStreamingAppPacket *>(obj)!=nullptr;
}

const char **StartRealTimeVideoStreamingAppPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *StartRealTimeVideoStreamingAppPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int StartRealTimeVideoStreamingAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int StartRealTimeVideoStreamingAppPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_fps
        FD_ISEDITABLE,    // FIELD_codec
        FD_ISEDITABLE,    // FIELD_sessionId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *StartRealTimeVideoStreamingAppPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fps",
        "codec",
        "sessionId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int StartRealTimeVideoStreamingAppPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "fps") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "codec") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "sessionId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *StartRealTimeVideoStreamingAppPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_fps
        "string",    // FIELD_codec
        "int",    // FIELD_sessionId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **StartRealTimeVideoStreamingAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *StartRealTimeVideoStreamingAppPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int StartRealTimeVideoStreamingAppPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void StartRealTimeVideoStreamingAppPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'StartRealTimeVideoStreamingAppPacket'", field);
    }
}

const char *StartRealTimeVideoStreamingAppPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string StartRealTimeVideoStreamingAppPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_fps: return long2string(pp->getFps());
        case FIELD_codec: return oppstring2string(pp->getCodec());
        case FIELD_sessionId: return long2string(pp->getSessionId());
        default: return "";
    }
}

void StartRealTimeVideoStreamingAppPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_fps: pp->setFps(string2long(value)); break;
        case FIELD_codec: pp->setCodec((value)); break;
        case FIELD_sessionId: pp->setSessionId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StartRealTimeVideoStreamingAppPacket'", field);
    }
}

omnetpp::cValue StartRealTimeVideoStreamingAppPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_fps: return pp->getFps();
        case FIELD_codec: return pp->getCodec();
        case FIELD_sessionId: return pp->getSessionId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'StartRealTimeVideoStreamingAppPacket' as cValue -- field index out of range?", field);
    }
}

void StartRealTimeVideoStreamingAppPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_fps: pp->setFps(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_codec: pp->setCodec(value.stringValue()); break;
        case FIELD_sessionId: pp->setSessionId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StartRealTimeVideoStreamingAppPacket'", field);
    }
}

const char *StartRealTimeVideoStreamingAppPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr StartRealTimeVideoStreamingAppPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void StartRealTimeVideoStreamingAppPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    StartRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StartRealTimeVideoStreamingAppPacket'", field);
    }
}

Register_Class(StartSessionRealTimeVideoStreamingAppPacket)

StartSessionRealTimeVideoStreamingAppPacket::StartSessionRealTimeVideoStreamingAppPacket() : ::RealTimeVideoStreamingAppPacket()
{
}

StartSessionRealTimeVideoStreamingAppPacket::StartSessionRealTimeVideoStreamingAppPacket(const StartSessionRealTimeVideoStreamingAppPacket& other) : ::RealTimeVideoStreamingAppPacket(other)
{
    copy(other);
}

StartSessionRealTimeVideoStreamingAppPacket::~StartSessionRealTimeVideoStreamingAppPacket()
{
}

StartSessionRealTimeVideoStreamingAppPacket& StartSessionRealTimeVideoStreamingAppPacket::operator=(const StartSessionRealTimeVideoStreamingAppPacket& other)
{
    if (this == &other) return *this;
    ::RealTimeVideoStreamingAppPacket::operator=(other);
    copy(other);
    return *this;
}

void StartSessionRealTimeVideoStreamingAppPacket::copy(const StartSessionRealTimeVideoStreamingAppPacket& other)
{
    this->fps = other.fps;
    this->codec = other.codec;
    this->sessionId = other.sessionId;
}

void StartSessionRealTimeVideoStreamingAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::RealTimeVideoStreamingAppPacket::parsimPack(b);
    doParsimPacking(b,this->fps);
    doParsimPacking(b,this->codec);
    doParsimPacking(b,this->sessionId);
}

void StartSessionRealTimeVideoStreamingAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::RealTimeVideoStreamingAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->fps);
    doParsimUnpacking(b,this->codec);
    doParsimUnpacking(b,this->sessionId);
}

int StartSessionRealTimeVideoStreamingAppPacket::getFps() const
{
    return this->fps;
}

void StartSessionRealTimeVideoStreamingAppPacket::setFps(int fps)
{
    handleChange();
    this->fps = fps;
}

const char * StartSessionRealTimeVideoStreamingAppPacket::getCodec() const
{
    return this->codec.c_str();
}

void StartSessionRealTimeVideoStreamingAppPacket::setCodec(const char * codec)
{
    handleChange();
    this->codec = codec;
}

int StartSessionRealTimeVideoStreamingAppPacket::getSessionId() const
{
    return this->sessionId;
}

void StartSessionRealTimeVideoStreamingAppPacket::setSessionId(int sessionId)
{
    handleChange();
    this->sessionId = sessionId;
}

class StartSessionRealTimeVideoStreamingAppPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_fps,
        FIELD_codec,
        FIELD_sessionId,
    };
  public:
    StartSessionRealTimeVideoStreamingAppPacketDescriptor();
    virtual ~StartSessionRealTimeVideoStreamingAppPacketDescriptor();

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

Register_ClassDescriptor(StartSessionRealTimeVideoStreamingAppPacketDescriptor)

StartSessionRealTimeVideoStreamingAppPacketDescriptor::StartSessionRealTimeVideoStreamingAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(StartSessionRealTimeVideoStreamingAppPacket)), "RealTimeVideoStreamingAppPacket")
{
    propertyNames = nullptr;
}

StartSessionRealTimeVideoStreamingAppPacketDescriptor::~StartSessionRealTimeVideoStreamingAppPacketDescriptor()
{
    delete[] propertyNames;
}

bool StartSessionRealTimeVideoStreamingAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<StartSessionRealTimeVideoStreamingAppPacket *>(obj)!=nullptr;
}

const char **StartSessionRealTimeVideoStreamingAppPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *StartSessionRealTimeVideoStreamingAppPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_fps
        FD_ISEDITABLE,    // FIELD_codec
        FD_ISEDITABLE,    // FIELD_sessionId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fps",
        "codec",
        "sessionId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int StartSessionRealTimeVideoStreamingAppPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "fps") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "codec") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "sessionId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_fps
        "string",    // FIELD_codec
        "int",    // FIELD_sessionId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void StartSessionRealTimeVideoStreamingAppPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'StartSessionRealTimeVideoStreamingAppPacket'", field);
    }
}

const char *StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_fps: return long2string(pp->getFps());
        case FIELD_codec: return oppstring2string(pp->getCodec());
        case FIELD_sessionId: return long2string(pp->getSessionId());
        default: return "";
    }
}

void StartSessionRealTimeVideoStreamingAppPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_fps: pp->setFps(string2long(value)); break;
        case FIELD_codec: pp->setCodec((value)); break;
        case FIELD_sessionId: pp->setSessionId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StartSessionRealTimeVideoStreamingAppPacket'", field);
    }
}

omnetpp::cValue StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_fps: return pp->getFps();
        case FIELD_codec: return pp->getCodec();
        case FIELD_sessionId: return pp->getSessionId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'StartSessionRealTimeVideoStreamingAppPacket' as cValue -- field index out of range?", field);
    }
}

void StartSessionRealTimeVideoStreamingAppPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_fps: pp->setFps(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_codec: pp->setCodec(value.stringValue()); break;
        case FIELD_sessionId: pp->setSessionId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StartSessionRealTimeVideoStreamingAppPacket'", field);
    }
}

const char *StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr StartSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void StartSessionRealTimeVideoStreamingAppPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    StartSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StartSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StartSessionRealTimeVideoStreamingAppPacket'", field);
    }
}

Register_Class(StopSessionRealTimeVideoStreamingAppPacket)

StopSessionRealTimeVideoStreamingAppPacket::StopSessionRealTimeVideoStreamingAppPacket() : ::RealTimeVideoStreamingAppPacket()
{
}

StopSessionRealTimeVideoStreamingAppPacket::StopSessionRealTimeVideoStreamingAppPacket(const StopSessionRealTimeVideoStreamingAppPacket& other) : ::RealTimeVideoStreamingAppPacket(other)
{
    copy(other);
}

StopSessionRealTimeVideoStreamingAppPacket::~StopSessionRealTimeVideoStreamingAppPacket()
{
}

StopSessionRealTimeVideoStreamingAppPacket& StopSessionRealTimeVideoStreamingAppPacket::operator=(const StopSessionRealTimeVideoStreamingAppPacket& other)
{
    if (this == &other) return *this;
    ::RealTimeVideoStreamingAppPacket::operator=(other);
    copy(other);
    return *this;
}

void StopSessionRealTimeVideoStreamingAppPacket::copy(const StopSessionRealTimeVideoStreamingAppPacket& other)
{
    this->sessionId = other.sessionId;
}

void StopSessionRealTimeVideoStreamingAppPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::RealTimeVideoStreamingAppPacket::parsimPack(b);
    doParsimPacking(b,this->sessionId);
}

void StopSessionRealTimeVideoStreamingAppPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::RealTimeVideoStreamingAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sessionId);
}

int StopSessionRealTimeVideoStreamingAppPacket::getSessionId() const
{
    return this->sessionId;
}

void StopSessionRealTimeVideoStreamingAppPacket::setSessionId(int sessionId)
{
    handleChange();
    this->sessionId = sessionId;
}

class StopSessionRealTimeVideoStreamingAppPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sessionId,
    };
  public:
    StopSessionRealTimeVideoStreamingAppPacketDescriptor();
    virtual ~StopSessionRealTimeVideoStreamingAppPacketDescriptor();

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

Register_ClassDescriptor(StopSessionRealTimeVideoStreamingAppPacketDescriptor)

StopSessionRealTimeVideoStreamingAppPacketDescriptor::StopSessionRealTimeVideoStreamingAppPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(StopSessionRealTimeVideoStreamingAppPacket)), "RealTimeVideoStreamingAppPacket")
{
    propertyNames = nullptr;
}

StopSessionRealTimeVideoStreamingAppPacketDescriptor::~StopSessionRealTimeVideoStreamingAppPacketDescriptor()
{
    delete[] propertyNames;
}

bool StopSessionRealTimeVideoStreamingAppPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<StopSessionRealTimeVideoStreamingAppPacket *>(obj)!=nullptr;
}

const char **StopSessionRealTimeVideoStreamingAppPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *StopSessionRealTimeVideoStreamingAppPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sessionId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sessionId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int StopSessionRealTimeVideoStreamingAppPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sessionId") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_sessionId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void StopSessionRealTimeVideoStreamingAppPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'StopSessionRealTimeVideoStreamingAppPacket'", field);
    }
}

const char *StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_sessionId: return long2string(pp->getSessionId());
        default: return "";
    }
}

void StopSessionRealTimeVideoStreamingAppPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_sessionId: pp->setSessionId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StopSessionRealTimeVideoStreamingAppPacket'", field);
    }
}

omnetpp::cValue StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_sessionId: return pp->getSessionId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'StopSessionRealTimeVideoStreamingAppPacket' as cValue -- field index out of range?", field);
    }
}

void StopSessionRealTimeVideoStreamingAppPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        case FIELD_sessionId: pp->setSessionId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StopSessionRealTimeVideoStreamingAppPacket'", field);
    }
}

const char *StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr StopSessionRealTimeVideoStreamingAppPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void StopSessionRealTimeVideoStreamingAppPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    StopSessionRealTimeVideoStreamingAppPacket *pp = omnetpp::fromAnyPtr<StopSessionRealTimeVideoStreamingAppPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'StopSessionRealTimeVideoStreamingAppPacket'", field);
    }
}

Register_Class(RealTimeVideoStreamingAppSegmentHeader)

RealTimeVideoStreamingAppSegmentHeader::RealTimeVideoStreamingAppSegmentHeader() : ::RealTimeVideoStreamingAppPacket()
{
}

RealTimeVideoStreamingAppSegmentHeader::RealTimeVideoStreamingAppSegmentHeader(const RealTimeVideoStreamingAppSegmentHeader& other) : ::RealTimeVideoStreamingAppPacket(other)
{
    copy(other);
}

RealTimeVideoStreamingAppSegmentHeader::~RealTimeVideoStreamingAppSegmentHeader()
{
}

RealTimeVideoStreamingAppSegmentHeader& RealTimeVideoStreamingAppSegmentHeader::operator=(const RealTimeVideoStreamingAppSegmentHeader& other)
{
    if (this == &other) return *this;
    ::RealTimeVideoStreamingAppPacket::operator=(other);
    copy(other);
    return *this;
}

void RealTimeVideoStreamingAppSegmentHeader::copy(const RealTimeVideoStreamingAppSegmentHeader& other)
{
    this->headerLength = other.headerLength;
    this->payloadLength = other.payloadLength;
    this->frameLength = other.frameLength;
    this->frameNumber = other.frameNumber;
    this->sequenceNumber = other.sequenceNumber;
    this->sessionId = other.sessionId;
    this->isLastFragment_ = other.isLastFragment_;
    this->isFragmented_ = other.isFragmented_;
    this->payloadTimestamp = other.payloadTimestamp;
    this->pictureType = other.pictureType;
    this->totalFrags = other.totalFrags;
    this->currentFrags = other.currentFrags;
}

void RealTimeVideoStreamingAppSegmentHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::RealTimeVideoStreamingAppPacket::parsimPack(b);
    doParsimPacking(b,this->headerLength);
    doParsimPacking(b,this->payloadLength);
    doParsimPacking(b,this->frameLength);
    doParsimPacking(b,this->frameNumber);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->sessionId);
    doParsimPacking(b,this->isLastFragment_);
    doParsimPacking(b,this->isFragmented_);
    doParsimPacking(b,this->payloadTimestamp);
    doParsimPacking(b,this->pictureType);
    doParsimPacking(b,this->totalFrags);
    doParsimPacking(b,this->currentFrags);
}

void RealTimeVideoStreamingAppSegmentHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::RealTimeVideoStreamingAppPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->headerLength);
    doParsimUnpacking(b,this->payloadLength);
    doParsimUnpacking(b,this->frameLength);
    doParsimUnpacking(b,this->frameNumber);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->sessionId);
    doParsimUnpacking(b,this->isLastFragment_);
    doParsimUnpacking(b,this->isFragmented_);
    doParsimUnpacking(b,this->payloadTimestamp);
    doParsimUnpacking(b,this->pictureType);
    doParsimUnpacking(b,this->totalFrags);
    doParsimUnpacking(b,this->currentFrags);
}

int RealTimeVideoStreamingAppSegmentHeader::getHeaderLength() const
{
    return this->headerLength;
}

void RealTimeVideoStreamingAppSegmentHeader::setHeaderLength(int headerLength)
{
    handleChange();
    this->headerLength = headerLength;
}

int RealTimeVideoStreamingAppSegmentHeader::getPayloadLength() const
{
    return this->payloadLength;
}

void RealTimeVideoStreamingAppSegmentHeader::setPayloadLength(int payloadLength)
{
    handleChange();
    this->payloadLength = payloadLength;
}

int RealTimeVideoStreamingAppSegmentHeader::getFrameLength() const
{
    return this->frameLength;
}

void RealTimeVideoStreamingAppSegmentHeader::setFrameLength(int frameLength)
{
    handleChange();
    this->frameLength = frameLength;
}

unsigned long RealTimeVideoStreamingAppSegmentHeader::getFrameNumber() const
{
    return this->frameNumber;
}

void RealTimeVideoStreamingAppSegmentHeader::setFrameNumber(unsigned long frameNumber)
{
    handleChange();
    this->frameNumber = frameNumber;
}

unsigned long RealTimeVideoStreamingAppSegmentHeader::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void RealTimeVideoStreamingAppSegmentHeader::setSequenceNumber(unsigned long sequenceNumber)
{
    handleChange();
    this->sequenceNumber = sequenceNumber;
}

int RealTimeVideoStreamingAppSegmentHeader::getSessionId() const
{
    return this->sessionId;
}

void RealTimeVideoStreamingAppSegmentHeader::setSessionId(int sessionId)
{
    handleChange();
    this->sessionId = sessionId;
}

bool RealTimeVideoStreamingAppSegmentHeader::isLastFragment() const
{
    return this->isLastFragment_;
}

void RealTimeVideoStreamingAppSegmentHeader::setIsLastFragment(bool isLastFragment)
{
    handleChange();
    this->isLastFragment_ = isLastFragment;
}

bool RealTimeVideoStreamingAppSegmentHeader::isFragmented() const
{
    return this->isFragmented_;
}

void RealTimeVideoStreamingAppSegmentHeader::setIsFragmented(bool isFragmented)
{
    handleChange();
    this->isFragmented_ = isFragmented;
}

omnetpp::simtime_t RealTimeVideoStreamingAppSegmentHeader::getPayloadTimestamp() const
{
    return this->payloadTimestamp;
}

void RealTimeVideoStreamingAppSegmentHeader::setPayloadTimestamp(omnetpp::simtime_t payloadTimestamp)
{
    handleChange();
    this->payloadTimestamp = payloadTimestamp;
}

uint8_t RealTimeVideoStreamingAppSegmentHeader::getPictureType() const
{
    return this->pictureType;
}

void RealTimeVideoStreamingAppSegmentHeader::setPictureType(uint8_t pictureType)
{
    handleChange();
    this->pictureType = pictureType;
}

int RealTimeVideoStreamingAppSegmentHeader::getTotalFrags() const
{
    return this->totalFrags;
}

void RealTimeVideoStreamingAppSegmentHeader::setTotalFrags(int totalFrags)
{
    handleChange();
    this->totalFrags = totalFrags;
}

int RealTimeVideoStreamingAppSegmentHeader::getCurrentFrags() const
{
    return this->currentFrags;
}

void RealTimeVideoStreamingAppSegmentHeader::setCurrentFrags(int currentFrags)
{
    handleChange();
    this->currentFrags = currentFrags;
}

class RealTimeVideoStreamingAppSegmentHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_headerLength,
        FIELD_payloadLength,
        FIELD_frameLength,
        FIELD_frameNumber,
        FIELD_sequenceNumber,
        FIELD_sessionId,
        FIELD_isLastFragment,
        FIELD_isFragmented,
        FIELD_payloadTimestamp,
        FIELD_pictureType,
        FIELD_totalFrags,
        FIELD_currentFrags,
    };
  public:
    RealTimeVideoStreamingAppSegmentHeaderDescriptor();
    virtual ~RealTimeVideoStreamingAppSegmentHeaderDescriptor();

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

Register_ClassDescriptor(RealTimeVideoStreamingAppSegmentHeaderDescriptor)

RealTimeVideoStreamingAppSegmentHeaderDescriptor::RealTimeVideoStreamingAppSegmentHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(RealTimeVideoStreamingAppSegmentHeader)), "RealTimeVideoStreamingAppPacket")
{
    propertyNames = nullptr;
}

RealTimeVideoStreamingAppSegmentHeaderDescriptor::~RealTimeVideoStreamingAppSegmentHeaderDescriptor()
{
    delete[] propertyNames;
}

bool RealTimeVideoStreamingAppSegmentHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RealTimeVideoStreamingAppSegmentHeader *>(obj)!=nullptr;
}

const char **RealTimeVideoStreamingAppSegmentHeaderDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RealTimeVideoStreamingAppSegmentHeaderDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 12+base->getFieldCount() : 12;
}

unsigned int RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_headerLength
        FD_ISEDITABLE,    // FIELD_payloadLength
        FD_ISEDITABLE,    // FIELD_frameLength
        FD_ISEDITABLE,    // FIELD_frameNumber
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_sessionId
        FD_ISEDITABLE,    // FIELD_isLastFragment
        FD_ISEDITABLE,    // FIELD_isFragmented
        FD_ISEDITABLE,    // FIELD_payloadTimestamp
        FD_ISEDITABLE,    // FIELD_pictureType
        FD_ISEDITABLE,    // FIELD_totalFrags
        FD_ISEDITABLE,    // FIELD_currentFrags
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "headerLength",
        "payloadLength",
        "frameLength",
        "frameNumber",
        "sequenceNumber",
        "sessionId",
        "isLastFragment",
        "isFragmented",
        "payloadTimestamp",
        "pictureType",
        "totalFrags",
        "currentFrags",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int RealTimeVideoStreamingAppSegmentHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "headerLength") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "payloadLength") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "frameLength") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "frameNumber") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "sessionId") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "isLastFragment") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "isFragmented") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "payloadTimestamp") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "pictureType") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "totalFrags") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "currentFrags") == 0) return baseIndex + 11;
    return base ? base->findField(fieldName) : -1;
}

const char *RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_headerLength
        "int",    // FIELD_payloadLength
        "int",    // FIELD_frameLength
        "unsigned long",    // FIELD_frameNumber
        "unsigned long",    // FIELD_sequenceNumber
        "int",    // FIELD_sessionId
        "bool",    // FIELD_isLastFragment
        "bool",    // FIELD_isFragmented
        "omnetpp::simtime_t",    // FIELD_payloadTimestamp
        "uint8_t",    // FIELD_pictureType
        "int",    // FIELD_totalFrags
        "int",    // FIELD_currentFrags
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RealTimeVideoStreamingAppSegmentHeaderDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'RealTimeVideoStreamingAppSegmentHeader'", field);
    }
}

const char *RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        case FIELD_headerLength: return long2string(pp->getHeaderLength());
        case FIELD_payloadLength: return long2string(pp->getPayloadLength());
        case FIELD_frameLength: return long2string(pp->getFrameLength());
        case FIELD_frameNumber: return ulong2string(pp->getFrameNumber());
        case FIELD_sequenceNumber: return ulong2string(pp->getSequenceNumber());
        case FIELD_sessionId: return long2string(pp->getSessionId());
        case FIELD_isLastFragment: return bool2string(pp->isLastFragment());
        case FIELD_isFragmented: return bool2string(pp->isFragmented());
        case FIELD_payloadTimestamp: return simtime2string(pp->getPayloadTimestamp());
        case FIELD_pictureType: return ulong2string(pp->getPictureType());
        case FIELD_totalFrags: return long2string(pp->getTotalFrags());
        case FIELD_currentFrags: return long2string(pp->getCurrentFrags());
        default: return "";
    }
}

void RealTimeVideoStreamingAppSegmentHeaderDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        case FIELD_headerLength: pp->setHeaderLength(string2long(value)); break;
        case FIELD_payloadLength: pp->setPayloadLength(string2long(value)); break;
        case FIELD_frameLength: pp->setFrameLength(string2long(value)); break;
        case FIELD_frameNumber: pp->setFrameNumber(string2ulong(value)); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2ulong(value)); break;
        case FIELD_sessionId: pp->setSessionId(string2long(value)); break;
        case FIELD_isLastFragment: pp->setIsLastFragment(string2bool(value)); break;
        case FIELD_isFragmented: pp->setIsFragmented(string2bool(value)); break;
        case FIELD_payloadTimestamp: pp->setPayloadTimestamp(string2simtime(value)); break;
        case FIELD_pictureType: pp->setPictureType(string2ulong(value)); break;
        case FIELD_totalFrags: pp->setTotalFrags(string2long(value)); break;
        case FIELD_currentFrags: pp->setCurrentFrags(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RealTimeVideoStreamingAppSegmentHeader'", field);
    }
}

omnetpp::cValue RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        case FIELD_headerLength: return pp->getHeaderLength();
        case FIELD_payloadLength: return pp->getPayloadLength();
        case FIELD_frameLength: return pp->getFrameLength();
        case FIELD_frameNumber: return omnetpp::checked_int_cast<omnetpp::intval_t>(pp->getFrameNumber());
        case FIELD_sequenceNumber: return omnetpp::checked_int_cast<omnetpp::intval_t>(pp->getSequenceNumber());
        case FIELD_sessionId: return pp->getSessionId();
        case FIELD_isLastFragment: return pp->isLastFragment();
        case FIELD_isFragmented: return pp->isFragmented();
        case FIELD_payloadTimestamp: return pp->getPayloadTimestamp().dbl();
        case FIELD_pictureType: return (omnetpp::intval_t)(pp->getPictureType());
        case FIELD_totalFrags: return pp->getTotalFrags();
        case FIELD_currentFrags: return pp->getCurrentFrags();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'RealTimeVideoStreamingAppSegmentHeader' as cValue -- field index out of range?", field);
    }
}

void RealTimeVideoStreamingAppSegmentHeaderDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        case FIELD_headerLength: pp->setHeaderLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_payloadLength: pp->setPayloadLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_frameLength: pp->setFrameLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_frameNumber: pp->setFrameNumber(omnetpp::checked_int_cast<unsigned long>(value.intValue())); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<unsigned long>(value.intValue())); break;
        case FIELD_sessionId: pp->setSessionId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_isLastFragment: pp->setIsLastFragment(value.boolValue()); break;
        case FIELD_isFragmented: pp->setIsFragmented(value.boolValue()); break;
        case FIELD_payloadTimestamp: pp->setPayloadTimestamp(value.doubleValue()); break;
        case FIELD_pictureType: pp->setPictureType(omnetpp::checked_int_cast<uint8_t>(value.intValue())); break;
        case FIELD_totalFrags: pp->setTotalFrags(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_currentFrags: pp->setCurrentFrags(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RealTimeVideoStreamingAppSegmentHeader'", field);
    }
}

const char *RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr RealTimeVideoStreamingAppSegmentHeaderDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RealTimeVideoStreamingAppSegmentHeaderDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    RealTimeVideoStreamingAppSegmentHeader *pp = omnetpp::fromAnyPtr<RealTimeVideoStreamingAppSegmentHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RealTimeVideoStreamingAppSegmentHeader'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

