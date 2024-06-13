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

#ifndef __TSNFIVEGCOMM_DSTT_H_
#define __TSNFIVEGCOMM_DSTT_H_

#include <omnetpp.h>
#include "inet/networklayer/common/NetworkInterface.h"
#include "inet/linklayer/common/FcsMode_m.h"
#include "common/binder/Binder.h"
#include "common/LteCommon.h"
#include "stack/sdap/QosChecker.h"
#include "common/binder/GlobalData.h"

using namespace omnetpp;


class Dstt : public cSimpleModule
{
  protected:

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void handlePacketFromUpper(cMessage *msg);
    int convertFiveqiToPcp(inet::Packet *datagram);
    GlobalData *globalData;
  public:
    Binder* binder_;
    Direction dir;
    //TSN handling
    QosChecker qosChecker;
};

#endif
