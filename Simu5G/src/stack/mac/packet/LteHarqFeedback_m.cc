//
// Generated file, do not edit! Created by opp_msgtool 6.0 from stack/mac/packet/LteHarqFeedback.msg.
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
#include "LteHarqFeedback_m.h"

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

Register_Class(LteHarqFeedback)

LteHarqFeedback::LteHarqFeedback() : ::inet::FieldsChunk()
{
    this->setChunkLength(inet::B(1));

}

LteHarqFeedback::LteHarqFeedback(const LteHarqFeedback& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

LteHarqFeedback::~LteHarqFeedback()
{
}

LteHarqFeedback& LteHarqFeedback::operator=(const LteHarqFeedback& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void LteHarqFeedback::copy(const LteHarqFeedback& other)
{
    this->acid = other.acid;
    this->cw = other.cw;
    this->result = other.result;
    this->fbMacPduId = other.fbMacPduId;
    this->d2dFeedback = other.d2dFeedback;
}

void LteHarqFeedback::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->acid);
    doParsimPacking(b,this->cw);
    doParsimPacking(b,this->result);
    doParsimPacking(b,this->fbMacPduId);
    doParsimPacking(b,this->d2dFeedback);
}

void LteHarqFeedback::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->acid);
    doParsimUnpacking(b,this->cw);
    doParsimUnpacking(b,this->result);
    doParsimUnpacking(b,this->fbMacPduId);
    doParsimUnpacking(b,this->d2dFeedback);
}

unsigned char LteHarqFeedback::getAcid() const
{
    return this->acid;
}

void LteHarqFeedback::setAcid(unsigned char acid)
{
    handleChange();
    this->acid = acid;
}

unsigned char LteHarqFeedback::getCw() const
{
    return this->cw;
}

void LteHarqFeedback::setCw(unsigned char cw)
{
    handleChange();
    this->cw = cw;
}

bool LteHarqFeedback::getResult() const
{
    return this->result;
}

void LteHarqFeedback::setResult(bool result)
{
    handleChange();
    this->result = result;
}

long LteHarqFeedback::getFbMacPduId() const
{
    return this->fbMacPduId;
}

void LteHarqFeedback::setFbMacPduId(long fbMacPduId)
{
    handleChange();
    this->fbMacPduId = fbMacPduId;
}

bool LteHarqFeedback::getD2dFeedback() const
{
    return this->d2dFeedback;
}

void LteHarqFeedback::setD2dFeedback(bool d2dFeedback)
{
    handleChange();
    this->d2dFeedback = d2dFeedback;
}

class LteHarqFeedbackDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_acid,
        FIELD_cw,
        FIELD_result,
        FIELD_fbMacPduId,
        FIELD_d2dFeedback,
    };
  public:
    LteHarqFeedbackDescriptor();
    virtual ~LteHarqFeedbackDescriptor();

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

Register_ClassDescriptor(LteHarqFeedbackDescriptor)

LteHarqFeedbackDescriptor::LteHarqFeedbackDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LteHarqFeedback)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

LteHarqFeedbackDescriptor::~LteHarqFeedbackDescriptor()
{
    delete[] propertyNames;
}

bool LteHarqFeedbackDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteHarqFeedback *>(obj)!=nullptr;
}

const char **LteHarqFeedbackDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LteHarqFeedbackDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LteHarqFeedbackDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int LteHarqFeedbackDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_acid
        FD_ISEDITABLE,    // FIELD_cw
        FD_ISEDITABLE,    // FIELD_result
        FD_ISEDITABLE,    // FIELD_fbMacPduId
        FD_ISEDITABLE,    // FIELD_d2dFeedback
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *LteHarqFeedbackDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "acid",
        "cw",
        "result",
        "fbMacPduId",
        "d2dFeedback",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int LteHarqFeedbackDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "acid") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "cw") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "result") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "fbMacPduId") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "d2dFeedback") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *LteHarqFeedbackDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",    // FIELD_acid
        "unsigned char",    // FIELD_cw
        "bool",    // FIELD_result
        "long",    // FIELD_fbMacPduId
        "bool",    // FIELD_d2dFeedback
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **LteHarqFeedbackDescriptor::getFieldPropertyNames(int field) const
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

const char *LteHarqFeedbackDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LteHarqFeedbackDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void LteHarqFeedbackDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LteHarqFeedback'", field);
    }
}

const char *LteHarqFeedbackDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteHarqFeedbackDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        case FIELD_acid: return ulong2string(pp->getAcid());
        case FIELD_cw: return ulong2string(pp->getCw());
        case FIELD_result: return bool2string(pp->getResult());
        case FIELD_fbMacPduId: return long2string(pp->getFbMacPduId());
        case FIELD_d2dFeedback: return bool2string(pp->getD2dFeedback());
        default: return "";
    }
}

void LteHarqFeedbackDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        case FIELD_acid: pp->setAcid(string2ulong(value)); break;
        case FIELD_cw: pp->setCw(string2ulong(value)); break;
        case FIELD_result: pp->setResult(string2bool(value)); break;
        case FIELD_fbMacPduId: pp->setFbMacPduId(string2long(value)); break;
        case FIELD_d2dFeedback: pp->setD2dFeedback(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteHarqFeedback'", field);
    }
}

omnetpp::cValue LteHarqFeedbackDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        case FIELD_acid: return (omnetpp::intval_t)(pp->getAcid());
        case FIELD_cw: return (omnetpp::intval_t)(pp->getCw());
        case FIELD_result: return pp->getResult();
        case FIELD_fbMacPduId: return (omnetpp::intval_t)(pp->getFbMacPduId());
        case FIELD_d2dFeedback: return pp->getD2dFeedback();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LteHarqFeedback' as cValue -- field index out of range?", field);
    }
}

void LteHarqFeedbackDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        case FIELD_acid: pp->setAcid(omnetpp::checked_int_cast<unsigned char>(value.intValue())); break;
        case FIELD_cw: pp->setCw(omnetpp::checked_int_cast<unsigned char>(value.intValue())); break;
        case FIELD_result: pp->setResult(value.boolValue()); break;
        case FIELD_fbMacPduId: pp->setFbMacPduId(omnetpp::checked_int_cast<long>(value.intValue())); break;
        case FIELD_d2dFeedback: pp->setD2dFeedback(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteHarqFeedback'", field);
    }
}

const char *LteHarqFeedbackDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LteHarqFeedbackDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LteHarqFeedbackDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LteHarqFeedback *pp = omnetpp::fromAnyPtr<LteHarqFeedback>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteHarqFeedback'", field);
    }
}

Register_Class(LteHarqFeedbackMirror)

LteHarqFeedbackMirror::LteHarqFeedbackMirror() : ::LteHarqFeedback()
{
    this->setD2dFeedback(true);

}

LteHarqFeedbackMirror::LteHarqFeedbackMirror(const LteHarqFeedbackMirror& other) : ::LteHarqFeedback(other)
{
    copy(other);
}

LteHarqFeedbackMirror::~LteHarqFeedbackMirror()
{
}

LteHarqFeedbackMirror& LteHarqFeedbackMirror::operator=(const LteHarqFeedbackMirror& other)
{
    if (this == &other) return *this;
    ::LteHarqFeedback::operator=(other);
    copy(other);
    return *this;
}

void LteHarqFeedbackMirror::copy(const LteHarqFeedbackMirror& other)
{
    this->d2dSenderId = other.d2dSenderId;
    this->d2dReceiverId = other.d2dReceiverId;
    this->pduLength = other.pduLength;
}

void LteHarqFeedbackMirror::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::LteHarqFeedback::parsimPack(b);
    doParsimPacking(b,this->d2dSenderId);
    doParsimPacking(b,this->d2dReceiverId);
    doParsimPacking(b,this->pduLength);
}

void LteHarqFeedbackMirror::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::LteHarqFeedback::parsimUnpack(b);
    doParsimUnpacking(b,this->d2dSenderId);
    doParsimUnpacking(b,this->d2dReceiverId);
    doParsimUnpacking(b,this->pduLength);
}

long LteHarqFeedbackMirror::getD2dSenderId() const
{
    return this->d2dSenderId;
}

void LteHarqFeedbackMirror::setD2dSenderId(long d2dSenderId)
{
    handleChange();
    this->d2dSenderId = d2dSenderId;
}

long LteHarqFeedbackMirror::getD2dReceiverId() const
{
    return this->d2dReceiverId;
}

void LteHarqFeedbackMirror::setD2dReceiverId(long d2dReceiverId)
{
    handleChange();
    this->d2dReceiverId = d2dReceiverId;
}

long LteHarqFeedbackMirror::getPduLength() const
{
    return this->pduLength;
}

void LteHarqFeedbackMirror::setPduLength(long pduLength)
{
    handleChange();
    this->pduLength = pduLength;
}

class LteHarqFeedbackMirrorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_d2dSenderId,
        FIELD_d2dReceiverId,
        FIELD_pduLength,
    };
  public:
    LteHarqFeedbackMirrorDescriptor();
    virtual ~LteHarqFeedbackMirrorDescriptor();

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

Register_ClassDescriptor(LteHarqFeedbackMirrorDescriptor)

LteHarqFeedbackMirrorDescriptor::LteHarqFeedbackMirrorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LteHarqFeedbackMirror)), "LteHarqFeedback")
{
    propertyNames = nullptr;
}

LteHarqFeedbackMirrorDescriptor::~LteHarqFeedbackMirrorDescriptor()
{
    delete[] propertyNames;
}

bool LteHarqFeedbackMirrorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LteHarqFeedbackMirror *>(obj)!=nullptr;
}

const char **LteHarqFeedbackMirrorDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LteHarqFeedbackMirrorDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LteHarqFeedbackMirrorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int LteHarqFeedbackMirrorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_d2dSenderId
        FD_ISEDITABLE,    // FIELD_d2dReceiverId
        FD_ISEDITABLE,    // FIELD_pduLength
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LteHarqFeedbackMirrorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "d2dSenderId",
        "d2dReceiverId",
        "pduLength",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LteHarqFeedbackMirrorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "d2dSenderId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "d2dReceiverId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "pduLength") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *LteHarqFeedbackMirrorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",    // FIELD_d2dSenderId
        "long",    // FIELD_d2dReceiverId
        "long",    // FIELD_pduLength
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LteHarqFeedbackMirrorDescriptor::getFieldPropertyNames(int field) const
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

const char *LteHarqFeedbackMirrorDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int LteHarqFeedbackMirrorDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void LteHarqFeedbackMirrorDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LteHarqFeedbackMirror'", field);
    }
}

const char *LteHarqFeedbackMirrorDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LteHarqFeedbackMirrorDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        case FIELD_d2dSenderId: return long2string(pp->getD2dSenderId());
        case FIELD_d2dReceiverId: return long2string(pp->getD2dReceiverId());
        case FIELD_pduLength: return long2string(pp->getPduLength());
        default: return "";
    }
}

void LteHarqFeedbackMirrorDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        case FIELD_d2dSenderId: pp->setD2dSenderId(string2long(value)); break;
        case FIELD_d2dReceiverId: pp->setD2dReceiverId(string2long(value)); break;
        case FIELD_pduLength: pp->setPduLength(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteHarqFeedbackMirror'", field);
    }
}

omnetpp::cValue LteHarqFeedbackMirrorDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        case FIELD_d2dSenderId: return (omnetpp::intval_t)(pp->getD2dSenderId());
        case FIELD_d2dReceiverId: return (omnetpp::intval_t)(pp->getD2dReceiverId());
        case FIELD_pduLength: return (omnetpp::intval_t)(pp->getPduLength());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LteHarqFeedbackMirror' as cValue -- field index out of range?", field);
    }
}

void LteHarqFeedbackMirrorDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        case FIELD_d2dSenderId: pp->setD2dSenderId(omnetpp::checked_int_cast<long>(value.intValue())); break;
        case FIELD_d2dReceiverId: pp->setD2dReceiverId(omnetpp::checked_int_cast<long>(value.intValue())); break;
        case FIELD_pduLength: pp->setPduLength(omnetpp::checked_int_cast<long>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteHarqFeedbackMirror'", field);
    }
}

const char *LteHarqFeedbackMirrorDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr LteHarqFeedbackMirrorDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LteHarqFeedbackMirrorDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LteHarqFeedbackMirror *pp = omnetpp::fromAnyPtr<LteHarqFeedbackMirror>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LteHarqFeedbackMirror'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

