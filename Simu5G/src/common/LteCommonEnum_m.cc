//
// Generated file, do not edit! Created by opp_msgtool 6.0 from common/LteCommonEnum.msg.
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
#include "LteCommonEnum_m.h"

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

Register_Enum(Direction, (Direction::DL, Direction::UL, Direction::D2D, Direction::D2D_MULTI, Direction::UNKNOWN_DIRECTION));

Register_Enum(LteMod, (LteMod::_QPSK, LteMod::_16QAM, LteMod::_64QAM, LteMod::_256QAM));

Register_Enum(FeedbackType, (FeedbackType::ALLBANDS, FeedbackType::PREFERRED, FeedbackType::WIDEBAND));

Register_Enum(FbPeriodicity, (FbPeriodicity::PERIODIC, FbPeriodicity::APERIODIC));

Register_Enum(RbAllocationType, (RbAllocationType::TYPE2_DISTRIBUTED, RbAllocationType::TYPE2_LOCALIZED));

Register_Enum(GateDirection, (GateDirection::IN_GATE, GateDirection::OUT_GATE));

Register_Enum(LteTrafficClass, (LteTrafficClass::CONVERSATIONAL, LteTrafficClass::STREAMING, LteTrafficClass::INTERACTIVE, LteTrafficClass::BACKGROUND, LteTrafficClass::HIGH_PRIORITY_TSN, LteTrafficClass::UNKNOWN_TRAFFIC_TYPE));

Register_Enum(GrantType, (GrantType::FITALL, GrantType::FIXED_, GrantType::URGENT, GrantType::UNKNOWN_GRANT_TYPE));

Register_Enum(LteRlcType, (LteRlcType::TM, LteRlcType::UM, LteRlcType::AM, LteRlcType::UNKNOWN_RLC_TYPE));

Register_Enum(UlTransmissionMapTTI, (UlTransmissionMapTTI::PREV_TTI, UlTransmissionMapTTI::CURR_TTI));

Register_Enum(LteD2DMode, (LteD2DMode::IM, LteD2DMode::DM));

Register_Enum(ApplicationType, (ApplicationType::VOIP, ApplicationType::VOD, ApplicationType::WEB, ApplicationType::CBR, ApplicationType::FTP, ApplicationType::GAMING, ApplicationType::FULLBUFFER, ApplicationType::NETWORK_CONTROL, ApplicationType::UNKNOWN_APP));

Register_Enum(SchedDiscipline, (SchedDiscipline::DRR, SchedDiscipline::PF, SchedDiscipline::MAXCI, SchedDiscipline::MAXCI_MB, SchedDiscipline::MAXCI_OPT_MB, SchedDiscipline::MAXCI_COMP, SchedDiscipline::ALLOCATOR_BESTFIT, SchedDiscipline::DQOS, SchedDiscipline::UNKNOWN_DISCIPLINE));

Register_Enum(PilotComputationModes, (PilotComputationModes::MIN_CQI, PilotComputationModes::MAX_CQI, PilotComputationModes::AVG_CQI, PilotComputationModes::MEDIAN_CQI, PilotComputationModes::ROBUST_CQI));

Register_Enum(TxMode, (TxMode::SINGLE_ANTENNA_PORT0, TxMode::SINGLE_ANTENNA_PORT5, TxMode::TRANSMIT_DIVERSITY, TxMode::OL_SPATIAL_MULTIPLEXING, TxMode::CL_SPATIAL_MULTIPLEXING, TxMode::MULTI_USER, TxMode::UNKNOWN_TX_MODE));

Register_Enum(TxDirectionType, (TxDirectionType::ANISOTROPIC, TxDirectionType::OMNI));

Register_Enum(FeedbackGeneratorType, (FeedbackGeneratorType::IDEAL, FeedbackGeneratorType::REAL, FeedbackGeneratorType::DAS_AWARE, FeedbackGeneratorType::UNKNOW_FB_GEN_TYPE));

Register_Enum(Plane, (Plane::MAIN_PLANE, Plane::MU_MIMO_PLANE));

Register_Enum(DeploymentScenario, (DeploymentScenario::INDOOR_HOTSPOT, DeploymentScenario::URBAN_MICROCELL, DeploymentScenario::URBAN_MACROCELL, DeploymentScenario::RURAL_MACROCELL, DeploymentScenario::SUBURBAN_MACROCELL, DeploymentScenario::UNKNOW_SCENARIO));

Register_Enum(Remote, (Remote::MACRO, Remote::RU1, Remote::RU2, Remote::RU3, Remote::RU4, Remote::RU5, Remote::RU6, Remote::UNKNOWN_RU));

Register_Enum(LtePhyFrameType, (LtePhyFrameType::DATAPKT, LtePhyFrameType::BROADCASTPKT, LtePhyFrameType::FEEDBACKPKT, LtePhyFrameType::HANDOVERPKT, LtePhyFrameType::HARQPKT, LtePhyFrameType::GRANTPKT, LtePhyFrameType::RACPKT, LtePhyFrameType::D2DMODESWITCHPKT, LtePhyFrameType::UNKNOWN_TYPE));

Register_Enum(RanNodeType, (RanNodeType::INTERNET, RanNodeType::ENODEB, RanNodeType::GNODEB, RanNodeType::UE, RanNodeType::UNKNOWN_NODE_TYPE));

Register_Enum(CoreNodeType, (CoreNodeType::ENB, CoreNodeType::PGW, CoreNodeType::SGW, CoreNodeType::GNB, CoreNodeType::UPF, CoreNodeType::UPF_MEC));

Register_Enum(BsrType, (BsrType::SHORT_BSR, BsrType::D2D_SHORT_BSR, BsrType::D2D_MULTI_SHORT_BSR));

Register_Enum(HarqAcknowledgment, (HarqAcknowledgment::HARQNACK, HarqAcknowledgment::HARQACK));

Register_Enum(TxHarqPduStatus, (TxHarqPduStatus::TXHARQ_PDU_BUFFERED, TxHarqPduStatus::TXHARQ_PDU_WAITING, TxHarqPduStatus::TXHARQ_PDU_EMPTY, TxHarqPduStatus::TXHARQ_PDU_SELECTED));

Register_Enum(RxHarqPduStatus, (RxHarqPduStatus::RXHARQ_PDU_EMPTY, RxHarqPduStatus::RXHARQ_PDU_EVALUATING, RxHarqPduStatus::RXHARQ_PDU_CORRECT, RxHarqPduStatus::RXHARQ_PDU_CORRUPTED));

Register_Enum(EnbType, (EnbType::MACRO_ENB, EnbType::MICRO_ENB));

namespace omnetpp {

}  // namespace omnetpp

