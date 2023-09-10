//
// Generated file, do not edit! Created by opp_msgtool 6.0 from nodes/mec/MECPlatform/MECServices/packets/HttpMessages.msg.
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
#include "HttpMessages_m.h"

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

Register_Enum(HttpMsgType, (HttpMsgType::REQUEST, HttpMsgType::RESPONSE, HttpMsgType::UNKNOWN));

Register_Enum(HttpRequestState, (HttpRequestState::CORRECT, HttpRequestState::BAD_REQ_LINE, HttpRequestState::BAD_HEADER, HttpRequestState::BAD_HTTP, HttpRequestState::BAD_REQUEST, HttpRequestState::DIFF_HOST, HttpRequestState::UNDEFINED, HttpRequestState::BAD_REQ_METHOD, HttpRequestState::BAD_RES_LINE, HttpRequestState::BAD_REQ_URI));

Register_Enum(HttpResponseStatus, (HttpResponseStatus::OK, HttpResponseStatus::CREATED, HttpResponseStatus::NO_CONTENT, HttpResponseStatus::BAD_REQ, HttpResponseStatus::UNAUTH, HttpResponseStatus::FORBIDDEN, HttpResponseStatus::NOT_FOUND, HttpResponseStatus::NOT_ACC, HttpResponseStatus::TOO_REQS, HttpResponseStatus::BAD_METHOD, HttpResponseStatus::HTTP_NOT_SUPPORTED, HttpResponseStatus::SERV_UNAV));

Register_Class(HttpBaseMessage)

HttpBaseMessage::HttpBaseMessage() : ::inet::FieldsChunk()
{
}

HttpBaseMessage::HttpBaseMessage(const HttpBaseMessage& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

HttpBaseMessage::~HttpBaseMessage()
{
}

HttpBaseMessage& HttpBaseMessage::operator=(const HttpBaseMessage& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void HttpBaseMessage::copy(const HttpBaseMessage& other)
{
    this->sockId = other.sockId;
    this->state = other.state;
    this->isReceivingMsg_ = other.isReceivingMsg_;
    this->type = other.type;
    this->body = other.body;
    this->httpProtocol = other.httpProtocol;
    this->contentLength = other.contentLength;
    this->remainingDataToRecv = other.remainingDataToRecv;
    this->contentType = other.contentType;
    this->connection = other.connection;
    this->arrivalTime = other.arrivalTime;
}

void HttpBaseMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->sockId);
    doParsimPacking(b,this->state);
    doParsimPacking(b,this->isReceivingMsg_);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->body);
    doParsimPacking(b,this->httpProtocol);
    doParsimPacking(b,this->contentLength);
    doParsimPacking(b,this->remainingDataToRecv);
    doParsimPacking(b,this->contentType);
    doParsimPacking(b,this->connection);
    doParsimPacking(b,this->arrivalTime);
}

void HttpBaseMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sockId);
    doParsimUnpacking(b,this->state);
    doParsimUnpacking(b,this->isReceivingMsg_);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->body);
    doParsimUnpacking(b,this->httpProtocol);
    doParsimUnpacking(b,this->contentLength);
    doParsimUnpacking(b,this->remainingDataToRecv);
    doParsimUnpacking(b,this->contentType);
    doParsimUnpacking(b,this->connection);
    doParsimUnpacking(b,this->arrivalTime);
}

int HttpBaseMessage::getSockId() const
{
    return this->sockId;
}

void HttpBaseMessage::setSockId(int sockId)
{
    handleChange();
    this->sockId = sockId;
}

HttpRequestState HttpBaseMessage::getState() const
{
    return this->state;
}

void HttpBaseMessage::setState(HttpRequestState state)
{
    handleChange();
    this->state = state;
}

bool HttpBaseMessage::isReceivingMsg() const
{
    return this->isReceivingMsg_;
}

void HttpBaseMessage::setIsReceivingMsg(bool isReceivingMsg)
{
    handleChange();
    this->isReceivingMsg_ = isReceivingMsg;
}

HttpMsgType HttpBaseMessage::getType() const
{
    return this->type;
}

void HttpBaseMessage::setType(HttpMsgType type)
{
    handleChange();
    this->type = type;
}

const char * HttpBaseMessage::getBody() const
{
    return this->body.c_str();
}

void HttpBaseMessage::setBody(const char * body)
{
    handleChange();
    this->body = body;
}

const char * HttpBaseMessage::getHttpProtocol() const
{
    return this->httpProtocol.c_str();
}

void HttpBaseMessage::setHttpProtocol(const char * httpProtocol)
{
    handleChange();
    this->httpProtocol = httpProtocol;
}

int HttpBaseMessage::getContentLength() const
{
    return this->contentLength;
}

void HttpBaseMessage::setContentLength(int contentLength)
{
    handleChange();
    this->contentLength = contentLength;
}

int HttpBaseMessage::getRemainingDataToRecv() const
{
    return this->remainingDataToRecv;
}

void HttpBaseMessage::setRemainingDataToRecv(int remainingDataToRecv)
{
    handleChange();
    this->remainingDataToRecv = remainingDataToRecv;
}

const char * HttpBaseMessage::getContentType() const
{
    return this->contentType.c_str();
}

void HttpBaseMessage::setContentType(const char * contentType)
{
    handleChange();
    this->contentType = contentType;
}

const char * HttpBaseMessage::getConnection() const
{
    return this->connection.c_str();
}

void HttpBaseMessage::setConnection(const char * connection)
{
    handleChange();
    this->connection = connection;
}

omnetpp::simtime_t HttpBaseMessage::getArrivalTime() const
{
    return this->arrivalTime;
}

void HttpBaseMessage::setArrivalTime(omnetpp::simtime_t arrivalTime)
{
    handleChange();
    this->arrivalTime = arrivalTime;
}

class HttpBaseMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sockId,
        FIELD_state,
        FIELD_isReceivingMsg,
        FIELD_type,
        FIELD_body,
        FIELD_httpProtocol,
        FIELD_contentLength,
        FIELD_remainingDataToRecv,
        FIELD_contentType,
        FIELD_connection,
        FIELD_arrivalTime,
    };
  public:
    HttpBaseMessageDescriptor();
    virtual ~HttpBaseMessageDescriptor();

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

Register_ClassDescriptor(HttpBaseMessageDescriptor)

HttpBaseMessageDescriptor::HttpBaseMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(HttpBaseMessage)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

HttpBaseMessageDescriptor::~HttpBaseMessageDescriptor()
{
    delete[] propertyNames;
}

bool HttpBaseMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HttpBaseMessage *>(obj)!=nullptr;
}

const char **HttpBaseMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *HttpBaseMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int HttpBaseMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 11+base->getFieldCount() : 11;
}

unsigned int HttpBaseMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sockId
        0,    // FIELD_state
        FD_ISEDITABLE,    // FIELD_isReceivingMsg
        0,    // FIELD_type
        FD_ISEDITABLE,    // FIELD_body
        FD_ISEDITABLE,    // FIELD_httpProtocol
        FD_ISEDITABLE,    // FIELD_contentLength
        FD_ISEDITABLE,    // FIELD_remainingDataToRecv
        FD_ISEDITABLE,    // FIELD_contentType
        FD_ISEDITABLE,    // FIELD_connection
        FD_ISEDITABLE,    // FIELD_arrivalTime
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *HttpBaseMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sockId",
        "state",
        "isReceivingMsg",
        "type",
        "body",
        "httpProtocol",
        "contentLength",
        "remainingDataToRecv",
        "contentType",
        "connection",
        "arrivalTime",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int HttpBaseMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sockId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "state") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "isReceivingMsg") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "type") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "body") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "httpProtocol") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "contentLength") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "remainingDataToRecv") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "contentType") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "connection") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "arrivalTime") == 0) return baseIndex + 10;
    return base ? base->findField(fieldName) : -1;
}

const char *HttpBaseMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_sockId
        "HttpRequestState",    // FIELD_state
        "bool",    // FIELD_isReceivingMsg
        "HttpMsgType",    // FIELD_type
        "string",    // FIELD_body
        "string",    // FIELD_httpProtocol
        "int",    // FIELD_contentLength
        "int",    // FIELD_remainingDataToRecv
        "string",    // FIELD_contentType
        "string",    // FIELD_connection
        "omnetpp::simtime_t",    // FIELD_arrivalTime
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **HttpBaseMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_state: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_type: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *HttpBaseMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_state:
            if (!strcmp(propertyName, "enum")) return "HttpRequestState";
            return nullptr;
        case FIELD_type:
            if (!strcmp(propertyName, "enum")) return "HttpMsgType";
            return nullptr;
        default: return nullptr;
    }
}

int HttpBaseMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void HttpBaseMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'HttpBaseMessage'", field);
    }
}

const char *HttpBaseMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HttpBaseMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sockId: return long2string(pp->getSockId());
        case FIELD_state: return enum2string(pp->getState(), "HttpRequestState");
        case FIELD_isReceivingMsg: return bool2string(pp->isReceivingMsg());
        case FIELD_type: return enum2string(pp->getType(), "HttpMsgType");
        case FIELD_body: return oppstring2string(pp->getBody());
        case FIELD_httpProtocol: return oppstring2string(pp->getHttpProtocol());
        case FIELD_contentLength: return long2string(pp->getContentLength());
        case FIELD_remainingDataToRecv: return long2string(pp->getRemainingDataToRecv());
        case FIELD_contentType: return oppstring2string(pp->getContentType());
        case FIELD_connection: return oppstring2string(pp->getConnection());
        case FIELD_arrivalTime: return simtime2string(pp->getArrivalTime());
        default: return "";
    }
}

void HttpBaseMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sockId: pp->setSockId(string2long(value)); break;
        case FIELD_isReceivingMsg: pp->setIsReceivingMsg(string2bool(value)); break;
        case FIELD_body: pp->setBody((value)); break;
        case FIELD_httpProtocol: pp->setHttpProtocol((value)); break;
        case FIELD_contentLength: pp->setContentLength(string2long(value)); break;
        case FIELD_remainingDataToRecv: pp->setRemainingDataToRecv(string2long(value)); break;
        case FIELD_contentType: pp->setContentType((value)); break;
        case FIELD_connection: pp->setConnection((value)); break;
        case FIELD_arrivalTime: pp->setArrivalTime(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpBaseMessage'", field);
    }
}

omnetpp::cValue HttpBaseMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sockId: return pp->getSockId();
        case FIELD_state: return static_cast<int>(pp->getState());
        case FIELD_isReceivingMsg: return pp->isReceivingMsg();
        case FIELD_type: return static_cast<int>(pp->getType());
        case FIELD_body: return pp->getBody();
        case FIELD_httpProtocol: return pp->getHttpProtocol();
        case FIELD_contentLength: return pp->getContentLength();
        case FIELD_remainingDataToRecv: return pp->getRemainingDataToRecv();
        case FIELD_contentType: return pp->getContentType();
        case FIELD_connection: return pp->getConnection();
        case FIELD_arrivalTime: return pp->getArrivalTime().dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'HttpBaseMessage' as cValue -- field index out of range?", field);
    }
}

void HttpBaseMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sockId: pp->setSockId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_isReceivingMsg: pp->setIsReceivingMsg(value.boolValue()); break;
        case FIELD_body: pp->setBody(value.stringValue()); break;
        case FIELD_httpProtocol: pp->setHttpProtocol(value.stringValue()); break;
        case FIELD_contentLength: pp->setContentLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_remainingDataToRecv: pp->setRemainingDataToRecv(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_contentType: pp->setContentType(value.stringValue()); break;
        case FIELD_connection: pp->setConnection(value.stringValue()); break;
        case FIELD_arrivalTime: pp->setArrivalTime(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpBaseMessage'", field);
    }
}

const char *HttpBaseMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr HttpBaseMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void HttpBaseMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpBaseMessage *pp = omnetpp::fromAnyPtr<HttpBaseMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpBaseMessage'", field);
    }
}

Register_Class(HttpRequestMessage_m)

HttpRequestMessage_m::HttpRequestMessage_m() : ::HttpBaseMessage()
{
}

HttpRequestMessage_m::HttpRequestMessage_m(const HttpRequestMessage_m& other) : ::HttpBaseMessage(other)
{
    copy(other);
}

HttpRequestMessage_m::~HttpRequestMessage_m()
{
}

HttpRequestMessage_m& HttpRequestMessage_m::operator=(const HttpRequestMessage_m& other)
{
    if (this == &other) return *this;
    ::HttpBaseMessage::operator=(other);
    copy(other);
    return *this;
}

void HttpRequestMessage_m::copy(const HttpRequestMessage_m& other)
{
    this->method = other.method;
    this->parameters = other.parameters;
    this->uri = other.uri;
    this->host = other.host;
    this->responseTime = other.responseTime;
}

void HttpRequestMessage_m::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::HttpBaseMessage::parsimPack(b);
    doParsimPacking(b,this->method);
    doParsimPacking(b,this->parameters);
    doParsimPacking(b,this->uri);
    doParsimPacking(b,this->host);
    doParsimPacking(b,this->responseTime);
}

void HttpRequestMessage_m::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::HttpBaseMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->method);
    doParsimUnpacking(b,this->parameters);
    doParsimUnpacking(b,this->uri);
    doParsimUnpacking(b,this->host);
    doParsimUnpacking(b,this->responseTime);
}

const char * HttpRequestMessage_m::getMethod() const
{
    return this->method.c_str();
}

void HttpRequestMessage_m::setMethod(const char * method)
{
    handleChange();
    this->method = method;
}

const char * HttpRequestMessage_m::getParameters() const
{
    return this->parameters.c_str();
}

void HttpRequestMessage_m::setParameters(const char * parameters)
{
    handleChange();
    this->parameters = parameters;
}

const char * HttpRequestMessage_m::getUri() const
{
    return this->uri.c_str();
}

void HttpRequestMessage_m::setUri(const char * uri)
{
    handleChange();
    this->uri = uri;
}

const char * HttpRequestMessage_m::getHost() const
{
    return this->host.c_str();
}

void HttpRequestMessage_m::setHost(const char * host)
{
    handleChange();
    this->host = host;
}

double HttpRequestMessage_m::getResponseTime() const
{
    return this->responseTime;
}

void HttpRequestMessage_m::setResponseTime(double responseTime)
{
    handleChange();
    this->responseTime = responseTime;
}

class HttpRequestMessage_mDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_method,
        FIELD_parameters,
        FIELD_uri,
        FIELD_host,
        FIELD_responseTime,
    };
  public:
    HttpRequestMessage_mDescriptor();
    virtual ~HttpRequestMessage_mDescriptor();

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

Register_ClassDescriptor(HttpRequestMessage_mDescriptor)

HttpRequestMessage_mDescriptor::HttpRequestMessage_mDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(HttpRequestMessage_m)), "HttpBaseMessage")
{
    propertyNames = nullptr;
}

HttpRequestMessage_mDescriptor::~HttpRequestMessage_mDescriptor()
{
    delete[] propertyNames;
}

bool HttpRequestMessage_mDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HttpRequestMessage_m *>(obj)!=nullptr;
}

const char **HttpRequestMessage_mDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *HttpRequestMessage_mDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int HttpRequestMessage_mDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int HttpRequestMessage_mDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_method
        FD_ISEDITABLE,    // FIELD_parameters
        FD_ISEDITABLE,    // FIELD_uri
        FD_ISEDITABLE,    // FIELD_host
        FD_ISEDITABLE,    // FIELD_responseTime
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *HttpRequestMessage_mDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "method",
        "parameters",
        "uri",
        "host",
        "responseTime",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int HttpRequestMessage_mDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "method") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "parameters") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "uri") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "host") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "responseTime") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *HttpRequestMessage_mDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_method
        "string",    // FIELD_parameters
        "string",    // FIELD_uri
        "string",    // FIELD_host
        "double",    // FIELD_responseTime
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **HttpRequestMessage_mDescriptor::getFieldPropertyNames(int field) const
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

const char *HttpRequestMessage_mDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int HttpRequestMessage_mDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void HttpRequestMessage_mDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'HttpRequestMessage_m'", field);
    }
}

const char *HttpRequestMessage_mDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HttpRequestMessage_mDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        case FIELD_method: return oppstring2string(pp->getMethod());
        case FIELD_parameters: return oppstring2string(pp->getParameters());
        case FIELD_uri: return oppstring2string(pp->getUri());
        case FIELD_host: return oppstring2string(pp->getHost());
        case FIELD_responseTime: return double2string(pp->getResponseTime());
        default: return "";
    }
}

void HttpRequestMessage_mDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        case FIELD_method: pp->setMethod((value)); break;
        case FIELD_parameters: pp->setParameters((value)); break;
        case FIELD_uri: pp->setUri((value)); break;
        case FIELD_host: pp->setHost((value)); break;
        case FIELD_responseTime: pp->setResponseTime(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpRequestMessage_m'", field);
    }
}

omnetpp::cValue HttpRequestMessage_mDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        case FIELD_method: return pp->getMethod();
        case FIELD_parameters: return pp->getParameters();
        case FIELD_uri: return pp->getUri();
        case FIELD_host: return pp->getHost();
        case FIELD_responseTime: return pp->getResponseTime();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'HttpRequestMessage_m' as cValue -- field index out of range?", field);
    }
}

void HttpRequestMessage_mDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        case FIELD_method: pp->setMethod(value.stringValue()); break;
        case FIELD_parameters: pp->setParameters(value.stringValue()); break;
        case FIELD_uri: pp->setUri(value.stringValue()); break;
        case FIELD_host: pp->setHost(value.stringValue()); break;
        case FIELD_responseTime: pp->setResponseTime(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpRequestMessage_m'", field);
    }
}

const char *HttpRequestMessage_mDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr HttpRequestMessage_mDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void HttpRequestMessage_mDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpRequestMessage_m *pp = omnetpp::fromAnyPtr<HttpRequestMessage_m>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpRequestMessage_m'", field);
    }
}

Register_Class(HttpResponseMessage_m)

HttpResponseMessage_m::HttpResponseMessage_m() : ::HttpBaseMessage()
{
}

HttpResponseMessage_m::HttpResponseMessage_m(const HttpResponseMessage_m& other) : ::HttpBaseMessage(other)
{
    copy(other);
}

HttpResponseMessage_m::~HttpResponseMessage_m()
{
}

HttpResponseMessage_m& HttpResponseMessage_m::operator=(const HttpResponseMessage_m& other)
{
    if (this == &other) return *this;
    ::HttpBaseMessage::operator=(other);
    copy(other);
    return *this;
}

void HttpResponseMessage_m::copy(const HttpResponseMessage_m& other)
{
    this->code = other.code;
    this->status = other.status;
}

void HttpResponseMessage_m::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::HttpBaseMessage::parsimPack(b);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->status);
}

void HttpResponseMessage_m::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::HttpBaseMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->status);
}

int HttpResponseMessage_m::getCode() const
{
    return this->code;
}

void HttpResponseMessage_m::setCode(int code)
{
    handleChange();
    this->code = code;
}

const char * HttpResponseMessage_m::getStatus() const
{
    return this->status.c_str();
}

void HttpResponseMessage_m::setStatus(const char * status)
{
    handleChange();
    this->status = status;
}

class HttpResponseMessage_mDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_code,
        FIELD_status,
    };
  public:
    HttpResponseMessage_mDescriptor();
    virtual ~HttpResponseMessage_mDescriptor();

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

Register_ClassDescriptor(HttpResponseMessage_mDescriptor)

HttpResponseMessage_mDescriptor::HttpResponseMessage_mDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(HttpResponseMessage_m)), "HttpBaseMessage")
{
    propertyNames = nullptr;
}

HttpResponseMessage_mDescriptor::~HttpResponseMessage_mDescriptor()
{
    delete[] propertyNames;
}

bool HttpResponseMessage_mDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HttpResponseMessage_m *>(obj)!=nullptr;
}

const char **HttpResponseMessage_mDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *HttpResponseMessage_mDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int HttpResponseMessage_mDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int HttpResponseMessage_mDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_code
        FD_ISEDITABLE,    // FIELD_status
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *HttpResponseMessage_mDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
        "status",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int HttpResponseMessage_mDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "code") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "status") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *HttpResponseMessage_mDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_code
        "string",    // FIELD_status
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **HttpResponseMessage_mDescriptor::getFieldPropertyNames(int field) const
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

const char *HttpResponseMessage_mDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int HttpResponseMessage_mDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void HttpResponseMessage_mDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'HttpResponseMessage_m'", field);
    }
}

const char *HttpResponseMessage_mDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HttpResponseMessage_mDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        case FIELD_code: return long2string(pp->getCode());
        case FIELD_status: return oppstring2string(pp->getStatus());
        default: return "";
    }
}

void HttpResponseMessage_mDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        case FIELD_code: pp->setCode(string2long(value)); break;
        case FIELD_status: pp->setStatus((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpResponseMessage_m'", field);
    }
}

omnetpp::cValue HttpResponseMessage_mDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        case FIELD_code: return pp->getCode();
        case FIELD_status: return pp->getStatus();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'HttpResponseMessage_m' as cValue -- field index out of range?", field);
    }
}

void HttpResponseMessage_mDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        case FIELD_code: pp->setCode(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_status: pp->setStatus(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpResponseMessage_m'", field);
    }
}

const char *HttpResponseMessage_mDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr HttpResponseMessage_mDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void HttpResponseMessage_mDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    HttpResponseMessage_m *pp = omnetpp::fromAnyPtr<HttpResponseMessage_m>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HttpResponseMessage_m'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

