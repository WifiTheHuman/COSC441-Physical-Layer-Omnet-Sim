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

#include "Receiver.h"
#include "packetRecord_m.h"

#include <string.h>
#include <omnetpp.h>
#include <iostream>

using namespace omnetpp;

class Receiver : public cSimpleModule
{

public:
private:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg);
    virtual void finish() override;

    cStdDev errorFlagCollection;
    double Q;
    double goodput;
};

Define_Module(Receiver_cc);

void Receiver_cc::initialize()
{
    //Initialises receiver at start of simulation
//    EV << "Initialising Receiver!\n";
    errorFlagCollection.setName("Packet Loss rate Q");
}

void Receiver_cc::handleMessage(cMessage *msg)
{
    packetRecord *chanMsg = (packetRecord *)msg;
//    EV << "Receiver processing packet record!\n";

    if (chanMsg->getErrorFlag() == true){
//        EV << "Packet record contains error!\n";
        errorFlagCollection.collect(1.0);

    }
    else {
//        EV << "Packet record is error free!\n";
        errorFlagCollection.collect(0.0);

    }


    Q = errorFlagCollection.getMean();
    goodput = ((1-Q) * chanMsg->getUserBits())/(chanMsg->getUserBits() + chanMsg->getOvhdBits());


    //goodputStats.record(goodput);
    EV << "Current mean: " << Q << "\n";
    EV << "Current goodput: " << goodput << "\n";
    delete chanMsg;

}

void Receiver_cc::finish()
{
    recordScalar("Average packet loss rate Q", Q);
    recordScalar("Goodput", goodput);
}
