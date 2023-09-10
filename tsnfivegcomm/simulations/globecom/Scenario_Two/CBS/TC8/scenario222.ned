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
import inet.networks.base.TsnNetworkBase;
import inet.node.ethernet.EthernetHost;
import inet.node.ethernet.EthernetSwitch;
import inet.node.inet.StandardHost;
import inet.node.tsn.TsnClock;
import inet.node.tsn.TsnDevice;
import inet.node.tsn.TsnSwitch;
import inet.node.wireless.AccessPoint;
import simu5g.world.radio.LteChannelControl;
import inet.networklayer.ipv4.RoutingTableRecorder;
import simu5g.common.binder.Binder;
import simu5g.common.carrierAggregation.CarrierAggregation;
import simu5g.nodes.Upf;
import simu5g.nodes.NR.gNodeB;
import inet.visualizer.common.DataLinkVisualizer;
import simu5g.nodes.NR.NRUe;
import tsnfivegcomm.DsttUe;
import tsnfivegcomm.Nwtt;
import inet.node.ethernet.Eth100M;
import inet.visualizer.common.IntegratedVisualizer;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import simu5g.common.binder.GlobalData;

package tsnfivegcomm.simulations.globecom.Scenario_Two.CBS.TC8;

network Scenario222 extends TsnNetworkBase

{
    int numUe = default(1);
    bool useQosModel = default(true);
    bool packetDropEnabled = default(true);
    string qosModelPriority = default("priority");
    double lambdaPriority = default(1);
    double lambdaRemainDelayBudget = default(0);
    double lambdaCqi = default(0);
    double lambdaRtx = default(0);
    double lambdaByteSize = default(0);
    //string tsnFiveGtrafficMappingXml = "";
    //xml tsnFiveGtrafficMappingXml = default(xml("<Traffic/>"));

    //xml trafficMappingXml = xmldoc("TrafficPcpQfiMapping");
    bool tsnEnabled = default(false);
    //xml config = xmldoc("../simulations/inputConfig/DsttIpMacConfig.xml");
    globalData.config = xmldoc("../simulations/inputConfig/DsttIpMacConfigScenario1.xml");
    globalData.qosMappingConfig = xmldoc("../simulations/inputConfig/TrafficPcpQfiMapping.xml");
    @display("bgb=2800.29,1807.87");
    submodules:
        globalData: GlobalData {
            @display("p=141.258,1492.2639");
        }
        tsnSwitch: TsnSwitch {
            @display("p=1121.208,424.974");
        }
        tsnDevice1: TsnDevice {
            @display("p=795.69604,391.82");
        }
        tsnDevice2: TsnDevice {
            @display("p=1075.998,738.43");
        }
        channelControl: LteChannelControl {
            @display("p=62.012,789.396;is=s");
        }
        routingTableRecorder: RoutingTableRecorder {
            @display("p=334.55402,892.14404");
        }
        binder: Binder {
            @display("p=189.388,881.576;is=s");
        }
        carrierAggregation: CarrierAggregation {
            @display("p=63.688,894.984;is=s");
        }
        upf: Upf {
            @display("p=1808.4,391.82");
        }
        gnb: gNodeB {
            @display("p=2230.36,316.47;is=vl");
        }
        linkVisualizer: DataLinkVisualizer {
            @display("p=63.688,1015.656");
        }
        //  ue: NRUe {
        //    @display("p=1295.7999,499.224");
        //}
        nwtt: Nwtt {
            @display("p=1452.748,391.82");
        }
        // agv: NRUe {
        //    @display("p=1164.856,414.656");
        //}
        ipvisualizer: IntegratedVisualizer {
            @display("p=141.856,1216.688");
        }
        configuratortwo: Ipv4NetworkConfigurator {
            @display("p=452.1,1166.4181");
        }
       // upf1: Upf {
         //   @display("p=1072.104,431.024");
        transportVehicle: NRUe {
            @display("p=2441.34,599.786");
        }
        //  dstt: Dstt {
        //    @display("p=1437.656,521.048");
        //}
        //  standardHost: StandardHost {
        //    @display("p=1391.28,862.048");
        //}
        //   dsttwap: dsttwap {
        //     @display("p=1164.856,575.608");
        //}
        //dsttUe: DsttUe {
       //    @display("p=2185.1501,786.65405");
        //}
       // ueTT: UeTT {
         //   @display("p=1189.408,632.896");
    connections:
        tsnSwitch.ethg++ <--> Eth100M <--> tsnDevice1.ethg++;
        tsnSwitch.ethg++ <--> Eth100M <--> tsnDevice2.ethg++;
        // nwtt.ethg++ <--> Eth100M <--> upf.pppg++;
        upf.pppg++ <--> Eth100M <--> gnb.ppp;
        //      ueTT.egate++ <--> Eth100M <--> standardHost.ethg++;


        tsnSwitch.ethg++ <--> Eth100M <--> nwtt.ethg++;

        nwtt.pppg++ <--> Eth100M <--> upf.filterGate;

}

