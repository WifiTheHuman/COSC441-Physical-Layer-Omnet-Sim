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
    double* nodeDistance = new double;
    double* pathLossExponent = new double;
    double* txPowerDBm = new double;
    double* bitRate = new double;
    double* noisePowerDBm = new double;
    double* transProbGoodGood = new double;
    double* transProbBadBad = new double;
    double* channelGainGoodDB = new double;
    double* channelGainBadDB = new double;
};

Define_Module(Channel_cc);

void Channel_cc::initialize()
{
    cout<<"Channel initialising, nodeDistance = "<<*nodeDistance;
    cout<<"Channel initialising, pathLossExponent = "<<*pathLossExponent;
    cout<<"Channel initialising, txPowerDBm = "<<*txPowerDBm;
    cout<<"Channel initialising, bitRate = "<<*bitRate;
    cout<<"Channel initialising, noisePowerDBm = "<<*noisePowerDBm;
    cout<<"Channel initialising, transProbGoodGood = "<<*transProbGoodGood;
    cout<<"Channel initialising, transProbBadBad = "<<*transProbBadBad;
    cout<<"Channel initialising, channelGainGoodDB = "<<*channelGainGoodDB;
    cout<<"Channel initialising, channelGainBadDB = "<<*channelGainBadDB;
}

void Channel_cc::handleMessage(cMessage *msg)
{
    cout<<"Channel initialising, nodeDistance = "<<*nodeDistance;
        cout<<"Channel handling message, pathLossExponent = "<<*pathLossExponent;
        cout<<"Channel handling message, txPowerDBm = "<<*txPowerDBm;
        cout<<"Channel handling message, bitRate = "<<*bitRate;
        cout<<"Channel handling message, noisePowerDBm = "<<*noisePowerDBm;
        cout<<"Channel handling message, transProbGoodGood = "<<*transProbGoodGood;
        cout<<"Channel handling message, transProbBadBad = "<<*transProbBadBad;
        cout<<"Channel handling message, channelGainGoodDB = "<<*channelGainGoodDB;
        cout<<"Channel handling message, channelGainBadDB = "<<*channelGainBadDB;
}
