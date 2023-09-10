//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Dstt.h"
#include "inet/common/Protocol.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/common/packet/Packet_m.h"
#include "inet/linklayer/ethernet/basic/EthernetEncapsulation.h"
#include "inet/common/INETUtils.h"
#include "inet/common/socket/SocketTag_m.h"
#include "inet/common/stlutils.h"
#include "inet/linklayer/common/FcsMode_m.h"
#include "inet/linklayer/common/Ieee802Ctrl.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/linklayer/common/MacAddressTag_m.h"
#include "inet/linklayer/ethernet/common/EthernetCommand_m.h"
#include "inet/linklayer/ethernet/common/EthernetControlFrame_m.h"
#include "inet/linklayer/ethernet/common/EthernetMacHeader_m.h"
#include "inet/networklayer/contract/IInterfaceTable.h"
#include "inet/linklayer/common/MacAddress.h"
#include "inet/networklayer/contract/IL3AddressType.h"
#include "inet/linklayer/ethernet/basic/EthernetEncapsulation.h"
#include "inet/networklayer/ipv4/Ipv4.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/networklayer/common/L3Tools.h"
#include "inet/networklayer/ipv4/Ipv4Header_m.h"
#include "inet/linklayer/ieee8021q/Ieee8021qTagHeader_m.h"
#include "inet/linklayer/common/PcpTag_m.h"
#include "inet/linklayer/common/UserPriorityTag_m.h"
#include "inet/linklayer/common/VlanTag_m.h"
#include "inet/common/ProtocolUtils.h"
#include "stack/rlc/packet/LteRlcSdu_m.h"
#include "stack/pdcp_rrc/packet/LtePdcpPdu_m.h"
#include "inet/transportlayer/udp/UdpHeader_m.h"


Define_Module(Dstt);
using namespace inet;
void Dstt::initialize()
{

    globalData = check_and_cast<GlobalData*>(getSimulation()->getModuleByPath("globalData"));

}

void Dstt::handleMessage(cMessage *msg)
{

    if (strcmp(msg->getArrivalGate()->getFullName(), "upperLayerIn") == 0)
        {
            EV << "Direction is UL" << endl;
            send(msg,"lowerLayerOut2");

        }
        else if(strcmp(msg->getArrivalGate()->getFullName(),"lowerLayerIn")==0)
        {
            EV <<"Direction is DL"<<endl;
            handlePacketFromUpper(msg);
        }

}
void Dstt::handlePacketFromUpper(cMessage *msg){
    auto nrpacket = check_and_cast<inet::Packet *>(msg);
    try{
        //Set transmission protocol
        const Protocol *qtagProtocol = nullptr;
        qtagProtocol = &Protocol::ieee8021qCTag;//ieee8022llc

        //Pop Residual 5G information
          auto ipHeader = nrpacket->peekAtFront<Ipv4Header>();
          //auto& ipDestAddress = ipHeader->getDestAddress();
          const Ipv4Address& ipDestAddress = ipHeader->getDestAddress();
          auto interfaceMapping = this->globalData->getUeEthInterfaceMapping();
          auto interfaceDetails = interfaceMapping[ipDestAddress.str()];
          int typeOrLength = 2048;
          auto interfaceReqId = std::stoi(interfaceDetails.interfaceId);

       //MacAddrReq
         auto& macAddrTag = nrpacket->addTagIfAbsent<MacAddressReq>();
         MacAddress mac(interfaceDetails.macAddress);
         inet::MacAddress destAddr(mac);
         macAddrTag->setDestAddress(destAddr);
         nrpacket->addTagIfAbsent<InterfaceReq>()->setInterfaceId(interfaceReqId);

         //Protocol tag
       const auto &protocolTag = nrpacket->addTagIfAbsent<PacketProtocolTag>();
       protocolTag->setProtocol(qtagProtocol);

       auto pcp = -1;
       try{
           pcp = convertFiveqiToPcp(nrpacket);
       }
       catch (...){
           pcp=-1;
       }
       auto header = makeShared<Ieee8021qTagEpdHeader>();

       if (pcp!=-1){
           header->setPcp(pcp);
           header->setVid(1);
           header->setTypeOrLength(typeOrLength);
           nrpacket->addTagIfAbsent<PcpInd>()->setPcp(4);
           nrpacket->addTagIfAbsent<UserPriorityInd>()->setUserPriority(pcp);
           nrpacket->insertAtFront(header);
       }

    }
    catch(...){
        EV<<"Please check the simulation and enter the correct interface details in the xml config file";
    }

        send(nrpacket,"lowerLayerOut");
}
int Dstt::convertFiveqiToPcp(Packet *datagram){
    EV<<"Packets name is"<<datagram->getName()<<endl;
    std::string packetName = datagram->getName();

    size_t found = -1;
    auto mappingTable = globalData->getQosMappingTable();
    for (auto& item: mappingTable){
        found = packetName.find(item.first);
        if (found != std::string::npos){
            return std::stoi(item.second.pcp);
          }
    }
    EV<<"Packet not configured!";
    return -1;

}

