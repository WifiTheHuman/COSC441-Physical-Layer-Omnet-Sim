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

#include "Channel.h"
#include "packetRecord_m.h"

#include <string.h>
#include <omnetpp.h>
#include <iostream>

class Channel : public cSimpleModule
{

public:

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

private:
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
    *nodeDistance = par("nodeDistance");
    *pathLossExponent = par("pathLossExponent");
    *txPowerDBm = par("txPowerDBm");
    *bitRate = par("bitRate");
    *noisePowerDBm = par("noisePowerDBm");
    *transProbGoodGood = par("transProbGoodGood");
    *transProbBadBad = par("transProbBadBad");
    *channelGainGoodDB = par("channelGainGoodDB");
    *channelGainBadDB = par("channelGainBadDB");

    //std::cout<<"Channel initialising, nodeDistance = "<<*nodeDistance;
    //std::cout<<"Channel initialising, pathLossExponent = "<<*pathLossExponent;
    //std::cout<<"Channel initialising, txPowerDBm = "<<*txPowerDBm;
    //std::cout<<"Channel initialising, bitRate = "<<*bitRate;
    //std::cout<<"Channel initialising, noisePowerDBm = "<<*noisePowerDBm;
    //std::cout<<"Channel initialising, transProbGoodGood = "<<*transProbGoodGood;
    //std::cout<<"Channel initialising, transProbBadBad = "<<*transProbBadBad;
    //std::cout<<"Channel initialising, channelGainGoodDB = "<<*channelGainGoodDB;
    //std::cout<<"Channel initialising, channelGainBadDB = "<<*channelGainBadDB;
}

void Channel_cc::handleMessage(cMessage *msg)
{
    //std::cout<<"Channel handling message, nodeDistance = "<<*nodeDistance;
    //std::cout<<"Channel handling message, pathLossExponent = "<<*pathLossExponent;
    //std::cout<<"Channel handling message, txPowerDBm = "<<*txPowerDBm;
    //std::cout<<"Channel handling message, bitRate = "<<*bitRate;
    //std::cout<<"Channel handling message, noisePowerDBm = "<<*noisePowerDBm;
    //std::cout<<"Channel handling message, transProbGoodGood = "<<*transProbGoodGood;
    //std::cout<<"Channel handling message, transProbBadBad = "<<*transProbBadBad;
    //std::cout<<"Channel handling message, channelGainGoodDB = "<<*channelGainGoodDB;
    //std::cout<<"Channel handling message, channelGainBadDB = "<<*channelGainBadDB;
}
