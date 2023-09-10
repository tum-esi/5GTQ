//
// Generated file, do not edit! Created by opp_msgtool 6.0 from stack/phy/packet/AirFrame.msg.
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
#include "AirFrame_m.h"

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

class ModulationTypeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    ModulationTypeDescriptor();
    virtual ~ModulationTypeDescriptor();

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

Register_ClassDescriptor(ModulationTypeDescriptor)

ModulationTypeDescriptor::ModulationTypeDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ModulationType)), "")
{
    propertyNames = nullptr;
}

ModulationTypeDescriptor::~ModulationTypeDescriptor()
{
    delete[] propertyNames;
}

bool ModulationTypeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ModulationType *>(obj)!=nullptr;
}

const char **ModulationTypeDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ModulationTypeDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "existingClass")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ModulationTypeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int ModulationTypeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *ModulationTypeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int ModulationTypeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *ModulationTypeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **ModulationTypeDescriptor::getFieldPropertyNames(int field) const
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

const char *ModulationTypeDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int ModulationTypeDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ModulationTypeDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ModulationType'", field);
    }
}

const char *ModulationTypeDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ModulationTypeDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void ModulationTypeDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ModulationType'", field);
    }
}

omnetpp::cValue ModulationTypeDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ModulationType' as cValue -- field index out of range?", field);
    }
}

void ModulationTypeDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ModulationType'", field);
    }
}

const char *ModulationTypeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr ModulationTypeDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ModulationTypeDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ModulationType *pp = omnetpp::fromAnyPtr<ModulationType>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ModulationType'", field);
    }
}

Register_Class(AirFrame)

AirFrame::AirFrame(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

AirFrame::AirFrame(const AirFrame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

AirFrame::~AirFrame()
{
}

AirFrame& AirFrame::operator=(const AirFrame& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void AirFrame::copy(const AirFrame& other)
{
    this->pSend = other.pSend;
    this->channelNumber = other.channelNumber;
    this->duration = other.duration;
    this->bitrate = other.bitrate;
    this->snr = other.snr;
    this->lossRate = other.lossRate;
    this->powRec = other.powRec;
    this->senderPos = other.senderPos;
    this->carrierFrequency = other.carrierFrequency;
    this->bandwidth = other.bandwidth;
    this->modulationType = other.modulationType;
}

void AirFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->pSend);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->duration);
    doParsimPacking(b,this->bitrate);
    doParsimPacking(b,this->snr);
    doParsimPacking(b,this->lossRate);
    doParsimPacking(b,this->powRec);
    doParsimPacking(b,this->senderPos);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->bandwidth);
    doParsimPacking(b,this->modulationType);
}

void AirFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->pSend);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->duration);
    doParsimUnpacking(b,this->bitrate);
    doParsimUnpacking(b,this->snr);
    doParsimUnpacking(b,this->lossRate);
    doParsimUnpacking(b,this->powRec);
    doParsimUnpacking(b,this->senderPos);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->bandwidth);
    doParsimUnpacking(b,this->modulationType);
}

double AirFrame::getPSend() const
{
    return this->pSend;
}

void AirFrame::setPSend(double pSend)
{
    this->pSend = pSend;
}

int AirFrame::getChannelNumber() const
{
    return this->channelNumber;
}

void AirFrame::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

omnetpp::simtime_t AirFrame::getDuration() const
{
    return this->duration;
}

void AirFrame::setDuration(omnetpp::simtime_t duration)
{
    this->duration = duration;
}

double AirFrame::getBitrate() const
{
    return this->bitrate;
}

void AirFrame::setBitrate(double bitrate)
{
    this->bitrate = bitrate;
}

double AirFrame::getSnr() const
{
    return this->snr;
}

void AirFrame::setSnr(double snr)
{
    this->snr = snr;
}

double AirFrame::getLossRate() const
{
    return this->lossRate;
}

void AirFrame::setLossRate(double lossRate)
{
    this->lossRate = lossRate;
}

double AirFrame::getPowRec() const
{
    return this->powRec;
}

void AirFrame::setPowRec(double powRec)
{
    this->powRec = powRec;
}

const inet::Coord& AirFrame::getSenderPos() const
{
    return this->senderPos;
}

void AirFrame::setSenderPos(const inet::Coord& senderPos)
{
    this->senderPos = senderPos;
}

double AirFrame::getCarrierFrequency() const
{
    return this->carrierFrequency;
}

void AirFrame::setCarrierFrequency(double carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

double AirFrame::getBandwidth() const
{
    return this->bandwidth;
}

void AirFrame::setBandwidth(double bandwidth)
{
    this->bandwidth = bandwidth;
}

const ModulationType& AirFrame::getModulationType() const
{
    return this->modulationType;
}

void AirFrame::setModulationType(const ModulationType& modulationType)
{
    this->modulationType = modulationType;
}

class AirFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_pSend,
        FIELD_channelNumber,
        FIELD_duration,
        FIELD_bitrate,
        FIELD_snr,
        FIELD_lossRate,
        FIELD_powRec,
        FIELD_senderPos,
        FIELD_carrierFrequency,
        FIELD_bandwidth,
        FIELD_modulationType,
    };
  public:
    AirFrameDescriptor();
    virtual ~AirFrameDescriptor();

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

Register_ClassDescriptor(AirFrameDescriptor)

AirFrameDescriptor::AirFrameDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(AirFrame)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

AirFrameDescriptor::~AirFrameDescriptor()
{
    delete[] propertyNames;
}

bool AirFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AirFrame *>(obj)!=nullptr;
}

const char **AirFrameDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AirFrameDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AirFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 11+base->getFieldCount() : 11;
}

unsigned int AirFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_pSend
        FD_ISEDITABLE,    // FIELD_channelNumber
        FD_ISEDITABLE,    // FIELD_duration
        FD_ISEDITABLE,    // FIELD_bitrate
        FD_ISEDITABLE,    // FIELD_snr
        FD_ISEDITABLE,    // FIELD_lossRate
        FD_ISEDITABLE,    // FIELD_powRec
        FD_ISCOMPOUND,    // FIELD_senderPos
        FD_ISEDITABLE,    // FIELD_carrierFrequency
        FD_ISEDITABLE,    // FIELD_bandwidth
        FD_ISCOMPOUND,    // FIELD_modulationType
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *AirFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "pSend",
        "channelNumber",
        "duration",
        "bitrate",
        "snr",
        "lossRate",
        "powRec",
        "senderPos",
        "carrierFrequency",
        "bandwidth",
        "modulationType",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int AirFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "pSend") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "channelNumber") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "duration") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "bitrate") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "snr") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "lossRate") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "powRec") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "senderPos") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "carrierFrequency") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "bandwidth") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "modulationType") == 0) return baseIndex + 10;
    return base ? base->findField(fieldName) : -1;
}

const char *AirFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_pSend
        "int",    // FIELD_channelNumber
        "omnetpp::simtime_t",    // FIELD_duration
        "double",    // FIELD_bitrate
        "double",    // FIELD_snr
        "double",    // FIELD_lossRate
        "double",    // FIELD_powRec
        "inet::Coord",    // FIELD_senderPos
        "double",    // FIELD_carrierFrequency
        "double",    // FIELD_bandwidth
        "ModulationType",    // FIELD_modulationType
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **AirFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *AirFrameDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int AirFrameDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AirFrameDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AirFrame'", field);
    }
}

const char *AirFrameDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AirFrameDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        case FIELD_pSend: return double2string(pp->getPSend());
        case FIELD_channelNumber: return long2string(pp->getChannelNumber());
        case FIELD_duration: return simtime2string(pp->getDuration());
        case FIELD_bitrate: return double2string(pp->getBitrate());
        case FIELD_snr: return double2string(pp->getSnr());
        case FIELD_lossRate: return double2string(pp->getLossRate());
        case FIELD_powRec: return double2string(pp->getPowRec());
        case FIELD_senderPos: return pp->getSenderPos().str();
        case FIELD_carrierFrequency: return double2string(pp->getCarrierFrequency());
        case FIELD_bandwidth: return double2string(pp->getBandwidth());
        case FIELD_modulationType: return "";
        default: return "";
    }
}

void AirFrameDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        case FIELD_pSend: pp->setPSend(string2double(value)); break;
        case FIELD_channelNumber: pp->setChannelNumber(string2long(value)); break;
        case FIELD_duration: pp->setDuration(string2simtime(value)); break;
        case FIELD_bitrate: pp->setBitrate(string2double(value)); break;
        case FIELD_snr: pp->setSnr(string2double(value)); break;
        case FIELD_lossRate: pp->setLossRate(string2double(value)); break;
        case FIELD_powRec: pp->setPowRec(string2double(value)); break;
        case FIELD_carrierFrequency: pp->setCarrierFrequency(string2double(value)); break;
        case FIELD_bandwidth: pp->setBandwidth(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AirFrame'", field);
    }
}

omnetpp::cValue AirFrameDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        case FIELD_pSend: return pp->getPSend();
        case FIELD_channelNumber: return pp->getChannelNumber();
        case FIELD_duration: return pp->getDuration().dbl();
        case FIELD_bitrate: return pp->getBitrate();
        case FIELD_snr: return pp->getSnr();
        case FIELD_lossRate: return pp->getLossRate();
        case FIELD_powRec: return pp->getPowRec();
        case FIELD_senderPos: return omnetpp::toAnyPtr(&pp->getSenderPos()); break;
        case FIELD_carrierFrequency: return pp->getCarrierFrequency();
        case FIELD_bandwidth: return pp->getBandwidth();
        case FIELD_modulationType: return omnetpp::toAnyPtr(&pp->getModulationType()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AirFrame' as cValue -- field index out of range?", field);
    }
}

void AirFrameDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        case FIELD_pSend: pp->setPSend(value.doubleValue()); break;
        case FIELD_channelNumber: pp->setChannelNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_duration: pp->setDuration(value.doubleValue()); break;
        case FIELD_bitrate: pp->setBitrate(value.doubleValue()); break;
        case FIELD_snr: pp->setSnr(value.doubleValue()); break;
        case FIELD_lossRate: pp->setLossRate(value.doubleValue()); break;
        case FIELD_powRec: pp->setPowRec(value.doubleValue()); break;
        case FIELD_carrierFrequency: pp->setCarrierFrequency(value.doubleValue()); break;
        case FIELD_bandwidth: pp->setBandwidth(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AirFrame'", field);
    }
}

const char *AirFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_senderPos: return omnetpp::opp_typename(typeid(inet::Coord));
        case FIELD_modulationType: return omnetpp::opp_typename(typeid(ModulationType));
        default: return nullptr;
    };
}

omnetpp::any_ptr AirFrameDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        case FIELD_senderPos: return omnetpp::toAnyPtr(&pp->getSenderPos()); break;
        case FIELD_modulationType: return omnetpp::toAnyPtr(&pp->getModulationType()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AirFrameDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AirFrame *pp = omnetpp::fromAnyPtr<AirFrame>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AirFrame'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

