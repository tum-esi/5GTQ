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

package tsnfivegcomm;
import inet.applications.contract.IApp;
import inet.common.packet.recorder.PcapRecorder;
import inet.linklayer.ethernet.basic.EthernetMac;
import inet.mobility.contract.IMobility;
import inet.linklayer.contract.IEthernetInterface;
import inet.linklayer.contract.ILoopbackInterface;
import inet.linklayer.ethernet.contract.IEthernetLayer;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv4.Ipv4RoutingTable;
import inet.networklayer.contract.IRoutingTable;
import inet.networklayer.contract.INetworkLayer;
import inet.common.packet.recorder.PcapRecorder;
import inet.transportlayer.contract.ITcp;
import inet.transportlayer.contract.IUdp;
import inet.transportlayer.contract.ISctp;
import inet.common.MessageDispatcher;
import simu5g.stack.ICellularNic;
import simu5g.corenetwork.statsCollector.UeStatsCollector;
import inet.linklayer.contract.IMacForwardingTable;
import inet.linklayer.contract.IMacRelayUnit;
import inet.protocolelement.contract.IProtocolLayer;
import inet.linklayer.contract.IMacForwardingTable;
import tsnfivegcomm.Dstt;
import inet.node.contract.IEthernetNetworkNode;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;

module DsttUe like IEthernetNetworkNode
{
    parameters:
        @networkNode();
        @display("i=device/pocketpc;bgb=858.888,659.568");
        @figure[applicationLayer](type=rectangle; pos=250,6; size=600,130; lineColor=#808080; cornerRadius=5; fillColor=#ffff00; fillOpacity=0.1);
        @figure[applicationLayer.title](type=text; pos=845,11; anchor=ne; text="application layer");
        @figure[transportLayer](type=rectangle; pos=250,156; size=600,130; fillColor=#ff0000; lineColor=#808080; cornerRadius=5; fillOpacity=0.1);
        @figure[transportLayer.title](type=text; pos=845,161; anchor=ne; text="transport layer");
        @figure[networkLayer](type=rectangle; pos=250,306; size=600,130; fillColor=#00ff00; lineColor=#808080; cornerRadius=5; fillOpacity=0.1);
        @figure[networkLayer.title](type=text; pos=845,311; anchor=ne; text="network layer");
        @figure[linkLayer](type=rectangle; pos=250,456; size=600,130; fillColor=#0000ff; lineColor=#808080; cornerRadius=5; fillOpacity=0.1);
        @figure[linkLayer.title](type=text; pos=845,461; anchor=ne; text="link layer");
        @labels(node,ethernet-node,wireless-node);
        @figure[submodules];

        // Mobility
        mobility.typename = default("StationaryMobility");

        //Apps
        int numApps = default(0);

        //Transport layer
        bool hasUdp = default(firstAvailableOrEmpty("Udp") != "");
        bool hasTcp = default(firstAvailableOrEmpty("Tcp", "TcpLwip", "TcpNsc") != "");
        bool hasSctp = default(false);

        //Node specs
        string nodeType = "UE";  // DO NOT CHANGE
        int masterId @mutable;
        int macNodeId @mutable = default(0); // TODO: this is not a real parameter
        int macCellId @mutable = default(0);
        int nrMasterId @mutable = default(0);
        int nrMacNodeId @mutable = default(0); // TODO: this is not a real parameter
        int nrMacCellId @mutable = default(0);

        //D2D capability
        string nicType = default("NRNicUe");

        //Network layer specs
        bool hasIpv4 = default(true);
        bool hasIpv6 = default(false);

        *.routingTableModule = default("^.ipv4.routingTable");

        //Loopback interfaces
        int numLoInterfaces = default(1);

        //Num of pcaprecorders
        int numPcapRecorders = default(0);

        bool hasRNISupport = default(false);

        //Ext EthernetInterface
        int numEthInterfaces = default(0);
        string extHostAddress = default("");
        //Ethernet
        ethernet.registerProtocol = default(true);
        *.forwarding = default(true);
        ethernet.typename = default("EthernetLayer");
        int numEInterfaces = default(1);

        //switch
        string fcsMode @enum("declared","computed") = default("declared");
        string spanningTreeProtocol = default("Stp");
        *.fcsMode = this.fcsMode;
        **.macTableModule = default(absPath(".macTable"));
        **.interfaceTableModule = default(absPath(".interfaceTable"));
        *.clockModule = default(exists(clock) ? absPath(".clock") : "");
        ethernet.*.promiscuous = default(true);
        ethernet.registerProtocol = default(true);

    gates:
        input nrRadioIn @directIn;
        inout custom_egate[1] @labels(EtherFrame-conn) @allowUnconnected;
        inout ethg[numEthInterfaces] @labels(EtherFrame-conn) @allowUnconnected;


    submodules:
        configuratorDstt: Ipv4NetworkConfigurator {
            @display("p=449.128,1441.556");
        }
        interfaceTable: InterfaceTable {
            @display("p=99.45,208.18199;is=s");
        }
        mobility: <default("")> like IMobility if typename != "" {
            @display("p=67.626,120.666;is=s");
        }

        //link layer
        lo[numLoInterfaces]: <default("LoopbackInterface")> like ILoopbackInterface {
            parameters:
                @display("p=503.736,589.50397,row,150");
        }
        custom_ethgate[1]: <default("EthernetInterface")> like IEthernetInterface {
            mac.promiscuous = true;
            @display("p=646,573,row;q=txQueue");
        }
        cellularNic: <nicType> like ICellularNic {
            nodeType = parent.nodeType;
            @display("p=355.152,589.50397");
        }

        //network layer
        ipv4: <default("Ipv4NetworkLayer")> like INetworkLayer if hasIpv4 {
            parameters:
                @display("p=405.75598,289.068;q=queue");
        }
        nl: MessageDispatcher {
            parameters:
                @display("p=547.638,358.02;b=600,5,,,,1");
        }
        //Pcap recorders
        pcapRecorder[numPcapRecorders]: PcapRecorder {
            @display("p=99.45,354.042,r,10");
        }
        // Uestatscollector for MEC
        ueCollector: UeStatsCollector if hasRNISupport {
            @display("p=126.84,588.296;is=s");
        }

        //AP
        macTable: <default("MacForwardingTable")> like IMacForwardingTable {
            @display("p=67.626,290.39398;is=s");
        }

        li: MessageDispatcher {
            @display("p=737,526;b=1200,5");
        }
        dstt: Dstt {
            @display("p=405.75598,405.75598;is=m");
        }
        ethernet: <default("EthernetEncapsulation")> like IEthernetLayer {
            @display("p=758.472,460.12198");
        }

    connections allowunconnected:

        ipv4.ifIn <-- nl.out++ if hasIpv4;
        ipv4.ifOut --> nl.in++ if hasIpv4;


        //Nic to radio medium
        cellularNic.nrRadioIn <-- nrRadioIn;


        custom_ethgate[0].phys <--> { @display("m=s"); } <--> custom_egate[0];
        custom_ethgate[0].upperLayerIn <-- li.out++;
        custom_ethgate[0].upperLayerOut --> li.in++;


        ethernet.lowerLayerOut --> li.in++;
        ethernet.lowerLayerIn <-- li.out++;

        dstt.lowerLayerOut --> ethernet.upperLayerIn;
        //ethernet.lowerLayerOut --> li.in++;

        cellularNic.upperLayerOut --> dstt.lowerLayerIn;
        dstt.lowerLayerOut2 --> cellularNic.upperLayerIn;
        ethernet.upperLayerOut --> dstt.upperLayerIn;
        dstt.upperLayerOut --> nl.in++;
        nl.out++ --> dstt.ipUpperLayerIn;
}


