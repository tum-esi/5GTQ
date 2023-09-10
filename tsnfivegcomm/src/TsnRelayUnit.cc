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

#include "TsnRelayUnit.h"
#include "inet/linklayer/ieee8021q/Ieee8021qTagHeader_m.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/linklayer/common/PcpTag_m.h"
#include "inet/linklayer/common/UserPriorityTag_m.h"
#include "inet/linklayer/common/VlanTag_m.h"
#include "common/binder/GlobalData.h"
Define_Module(TsnRelayUnit);
using namespace inet;
void TsnRelayUnit::handleLowerPacket(Packet *packet)
{
    send(packet,"upperLayerOut");
    // TODO - Generated method body
}
void TsnRelayUnit::handleUpperPacket(Packet *packet){
    //Set transmission protocol
    send(packet,"lowerLayerOut");
}

void TsnRelayUnit::handleUpperMessage(cMessage *msg){
    //Set transmission protocol

    auto packet = check_and_cast<inet::Packet *>(msg);
    auto protocol = packet->getTag<PacketProtocolTag>()->getProtocol();
        const Protocol *qtagProtocol = nullptr;
        qtagProtocol = &Protocol::ieee8021qCTag;//ieee8022llc
        const auto &protocolTag = packet->addTagIfAbsent<PacketProtocolTag>();
        protocolTag->setProtocol(qtagProtocol);

        auto header = makeShared<Ieee8021qTagEpdHeader>();
        auto pcp = convertFiveqiToPcp(packet);
        header->setPcp(4);
                   header->setVid(1);
                   header->setTypeOrLength(2048);
                   packet->addTagIfAbsent<PcpInd>()->setPcp(4);
                   packet->addTagIfAbsent<UserPriorityInd>()->setUserPriority(4);
                   packet->insertAtFront(header);
    send(packet,"lowerLayerOut");

    //send(msg,"lowerLayerOut");
}
int TsnRelayUnit::convertFiveqiToPcp(Packet *datagram){
    globalData = check_and_cast<GlobalData*>(getSimulation()->getModuleByPath("globalData"));
    std::string packetName = datagram->getName();
    size_t found = -1;
    auto mappingTable = globalData->getQosMappingTable();
    for (auto& item: mappingTable){
        found = packetName.find(item.first);
        if (found != std::string::npos){
            return std::stoi(item.second.pcp);
          }
    }
        return -1;
}
