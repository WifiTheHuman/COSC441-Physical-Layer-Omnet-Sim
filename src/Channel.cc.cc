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

#include "Channel.cc.h"
#include <string.h>
#include <omnetpp.h>
#include <iostream>

class Channel : public cSimpleModule
{

public:

private:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    double nodeDistance;
    double pathLossExponent;
    double txPowerDBm;
    double bitRate;
    double noisePowerDBm;
    double transProbGoodGood;
    double transProbBadBad;
    double channelGainGoodDB;
    double channelGainBadDB
};

Define_Module(Channel_cc);

void Channel_cc::initialize()
{
    // TODO - Generated method body
}

void Channel_cc::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}
