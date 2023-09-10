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

#ifndef __TSNFIVEGCOMM_TSNRELAYUNIT_H_
#define __TSNFIVEGCOMM_TSNRELAYUNIT_H_

#include <omnetpp.h>

using namespace omnetpp;
#include "stack/sdap/QosChecker.h"
#include "inet/linklayer/base/MacRelayUnitBase.h"
#include "common/binder/Binder.h"
#include "common/LteCommon.h"

/**
 * TODO - Generated class
 */
class TsnRelayUnit : public inet::MacRelayUnitBase
{
  protected:
    virtual void handleLowerPacket(inet::Packet *packet) override;
    virtual void handleUpperPacket(inet::Packet *packet) override;
    virtual void handleUpperMessage(inet::cMessage *msg) override;
    int convertFiveqiToPcp(inet::Packet *datagram);
  private:
    QosChecker qosChecker;
    Binder* binder = getBinder();
    GlobalData *globalData;
};

#endif
