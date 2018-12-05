/*
 *
 *  Created on: Dec.5 2018
 *      Author: odie Peng
 */

#include "ns3/core-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"
#include "ns3/wifi-module.h"
#include "ns3/mobility-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/netanim-module.h"
#include "ns3/olsr-module.h"
#include "ns3/dsr-module.h"
#include "ns3/dsdv-module.h"
#include <vector>
#include "ns3/stats-module.h"
using namespace ns3;
using namespace std;

int main(int argc, char *argv[]) {

	//Install InternetStack and DsrRouting Protocol on nodes
	InternetStackHelper stack;
	DsrHelper Dsr_Normal, Dsr_Malicous;
	DsrMainHelper DsrMain;
	Dsr_Normal.Set("isMalicious",UintegerValue(0));
	Dsr_Malicous.Set("isMalicious", UintegerValue(1)); //You can set '1' or '2' to choose a type
	stack.Install(nodeall);
	stack.Install(maliciousNode);
	DsrMain.Install(Dsr_Normal, nodeall);
	DsrMain.Install(Dsr_Malicous, maliciousNode);

	return 0;
}
