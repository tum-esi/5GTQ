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

import inet.common.MessageDispatcher;
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;
import simu5g.nodes.Upf;
import inet.common.MessageDispatcher;
import inet.linklayer.ppp.PppInterface;
import inet.transportlayer.udp.Udp;
import inet.node.base.NetworkLayerNodeBase;
import inet.node.contract.IEthernetNetworkNode;
import inet.common.MessageDispatcher;
import inet.linklayer.contract.IMacForwardingTable;
import inet.linklayer.ethernet.contract.IEthernetLayer;
import inet.networklayer.common.InterfaceTable;
import inet.node.contract.IEthernetNetworkNode;
import inet.networklayer.common.InterfaceTable;
import tsnfivegcomm.TsnRelayUnit;

module Nwtt extends NetworkLayerNodeBase
{
    parameters:
        @display("bgb=1348.9225,1103.51;i=abstract/switch");
        @figure[applicationLayer](type=rectangle; pos=250,6; size=1000,130; lineColor=#808080; cornerRadius=5; fillColor=#ffff00; fillOpacity=0.1);
        @figure[applicationLayer.title](type=text; pos=1245,11; anchor=ne; text="application layer");
        @figure[transportLayer](type=rectangle; pos=250,156; size=1000,130; fillColor=#ff0000; lineColor=#808080; cornerRadius=5; fillOpacity=0.1);
        @figure[transportLayer.title](type=text; pos=1245,161; anchor=ne; text="transport layer");
        @figure[submodules];

        string nodeType = default("UPF");   // do NOT change!
        forwarding = default(true);
        multicastForwarding = default(false);

        **.macTableModule = default(absPath(".macTable"));
        **.interfaceTableModule = default(absPath(".interfaceTable"));
        bool tsnDlEnabled = default(true);

    gates:
        // this gate is used for the UPF connected to the external data network
        // it must be left unconnected for intermediate UPFs 
        inout filterGate @loose @labels(PppFrame-conn);

    submodules:

        tn: MessageDispatcher {
            parameters:
                @display("p=750,296;b=1000,5,,,,1");
        }
        macTable: <default("MacForwardingTable")> like IMacForwardingTable {
            @display("p=-172.692,-81.918;is=s");
        }

    connections:

        // at dispatcher to transport layer connections
        // transport layer to tn dispatcher connections


        // tn dispatcher to network layer connections
        tn.out++ --> ipv4.transportIn if hasIpv4;
        tn.in++ <-- ipv4.transportOut if hasIpv4;

        tn.out++ --> ipv6.transportIn if hasIpv6;
        tn.in++ <-- ipv6.transportOut if hasIpv6;

        tn.out++ --> generic.transportIn if hasGn;
        tn.in++ <-- generic.transportOut if hasGn;

        tn.out++ --> nl.in++;
        tn.in++ <-- nl.out++;

}


