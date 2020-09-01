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

#include "Transmitter.h"
#include "packetRecord_m.h"

#include <string.h>
#include <omnetpp.h>
#include <iostream>

using namespace omnetpp;

class Transmitter : public cSimpleModule
{

public:

private:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    int* numberOverheadBits = new int;
    int* NumberUserBits = new int;

};

Define_Module(Transmitter_cc);

void Transmitter_cc::initialize()
{
    //Initializes transmitter at start of simulation
    //Sets variables to parameters
    *numberOverheadBits = par("numberOverheadBits");
    *NumberUserBits = par("NumberUserBits");

    EV << "Initialising transmitter!\n";

    //std::cout<<"Transmitter initialising, numberOverheadBits = "<<*numberOverheadBits;
    //std::cout<<"\nTransmitter initialising, NumberUserBits = "<<*NumberUserBits;
}

void Transmitter_cc::handleMessage(cMessage *msg)
{
    //Occurs when the transmitter receives a message
    //Deletes received message, generates packet record and sends to out gate
    //std::cout<<"Transmitter handling message, numberOverheadBits = "<<*numberOverheadBits;
    //std::cout<<"\nTransmitter handling message, NumberUserBits = "<<*NumberUserBits;

    EV << "Transmitter received message!\n";

    delete msg;

    EV << "Transmitter deleted message!\n";

    packetRecord *myPacket = new packetRecord("myPacket");
    myPacket->setOvhdBits(*numberOverheadBits);
    myPacket->setUserBits(*NumberUserBits);

    EV << "Transmitter created packet record!\n";

    //set error flag to true if you want to
    //myPacket->setSequenceNumber(1);

    send(myPacket, "out");
    //std::cout<<"\nTransmitter sending message";
    EV << "Transmitter packet record sent!\n";
}
