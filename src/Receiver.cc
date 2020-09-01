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
    virtual void handleMessage(cMessage *msg) override;
    bool* errorFlag = new bool;
    double* PLProb_Q = new double;
};

Define_Module(Receiver_cc);

void Receiver_cc::initialize()
{
    *errorFlag = par("errorFlag");
    *PLProb_Q = par("PLProb_Q");
    //std::cout<<"Receiver initialising, errorFlag = "<<*errorFlag;
    //std::cout<<"\nReceiver initialising, PLProb_Q = "<<*PLProb_Q;
}

void Receiver_cc::handleMessage(cMessage *msg)
{
    //std::cout<<"Receiver handling message, errorFlag = "<<*errorFlag;
    //std::cout<<"\nReceiver handling message, PLProb_Q = "<<*PLProb_Q;
}
