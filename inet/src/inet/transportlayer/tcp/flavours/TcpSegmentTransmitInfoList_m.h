//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/transportlayer/tcp/flavours/TcpSegmentTransmitInfoList.msg.
//

#ifndef __INET__TCP_TCPSEGMENTTRANSMITINFOLIST_M_H
#define __INET__TCP_TCPSEGMENTTRANSMITINFOLIST_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {
namespace tcp {


}  // namespace tcp
}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

// cplusplus {{
#include "inet/transportlayer/tcp/flavours/TcpSegmentTransmitInfoList.h"
// }}


namespace inet {
namespace tcp {


}  // namespace tcp
}  // namespace inet


namespace omnetpp {

inline any_ptr toAnyPtr(const inet::tcp::TcpSegmentTransmitInfoList *p) {if (auto obj = as_cObject(p)) return any_ptr(obj); else return any_ptr(p);}
template<> inline inet::tcp::TcpSegmentTransmitInfoList *fromAnyPtr(any_ptr ptr) { return ptr.get<inet::tcp::TcpSegmentTransmitInfoList>(); }

}  // namespace omnetpp

#endif // ifndef __INET__TCP_TCPSEGMENTTRANSMITINFOLIST_M_H
