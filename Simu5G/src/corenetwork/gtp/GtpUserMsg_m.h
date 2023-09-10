//
// Generated file, do not edit! Created by opp_msgtool 6.0 from corenetwork/gtp/GtpUserMsg.msg.
//

#ifndef __GTPUSERMSG_M_H
#define __GTPUSERMSG_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class GtpUserMsg;
#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/packet/chunk/Chunk_m.h" // import inet.common.packet.chunk.Chunk

/**
 * Class generated from <tt>corenetwork/gtp/GtpUserMsg.msg:15</tt> by opp_msgtool.
 * <pre>
 * class GtpUserMsg extends inet::FieldsChunk
 * {
 *     unsigned int teid;
 *     chunkLength = inet::B(1); // TODO: size 0
 *     unsigned int qfi;
 * 
 * }
 * </pre>
 */
class GtpUserMsg : public ::inet::FieldsChunk
{
  protected:
    unsigned int teid = 0;
    unsigned int qfi = 0;

  private:
    void copy(const GtpUserMsg& other);

  protected:
    bool operator==(const GtpUserMsg&) = delete;

  public:
    GtpUserMsg();
    GtpUserMsg(const GtpUserMsg& other);
    virtual ~GtpUserMsg();
    GtpUserMsg& operator=(const GtpUserMsg& other);
    virtual GtpUserMsg *dup() const override {return new GtpUserMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual unsigned int getTeid() const;
    virtual void setTeid(unsigned int teid);

    virtual unsigned int getQfi() const;
    virtual void setQfi(unsigned int qfi);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const GtpUserMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, GtpUserMsg& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline GtpUserMsg *fromAnyPtr(any_ptr ptr) { return check_and_cast<GtpUserMsg*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __GTPUSERMSG_M_H
