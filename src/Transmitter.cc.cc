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

#include "Transmitter.cc.h"
#include <string.h>
#include <omnetpp.h>
#include <iostream>

using namespace omnetpp;

class Transmitter : public cSimpleModule
{

public:
//    void setNumberOverheadBits(int ovhBits);
//    void setNumberUserBits(int ovhBits);
//    int getNumberOverheadBits();
//    int getNumberUserBits();
private:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    int* numberOverheadBits = new int;
    int* NumberUserBits = new int;
};

Define_Module(Transmitter_cc);

void Transmitter_cc::initialize()
{

    cout<<"Transmitter initialising, numberOverheadBits = "<<*numberOverheadBits;
    cout<<"\nTransmitter initialising, NumberUserBits = "<<*NumberUserBits;



}

void Transmitter_cc::handleMessage(PacketMessage *msg)
{
    // TODO - Generated method body
    cout<<"Transmitter handling message, numberOverheadBits = "<<*numberOverheadBits;
    cout<<"\nTransmitter handling message, NumberUserBits = "<<*NumberUserBits;

}
