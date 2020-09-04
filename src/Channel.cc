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
#include <time.h>
#include <cmath>
#include <math.h>

class Channel : public cSimpleModule
{

public:

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg);

private:
    //Paremeters from .ned file
    double nodeDistance;
    double pathLossExponent;
    double txPowerDBm;
    double bitRate;
    double noisePowerDBm;
    double transProbGoodGood;
    double transProbBadBad;
    double channelGainGoodDB;
    double channelGainBadDB;

    double tempRand;
    double BER;
    double PLd;
    double receivedPower;
    double SNR;

    int packetSize;

    bool chanGood = true;
    bool nextChanGood = true;
};

Define_Module(Channel_cc);

void Channel_cc::initialize()
{
    //Runs at start of simulation
    //Gets values from .ned parameters
    nodeDistance = par("nodeDistance");
    pathLossExponent = par("pathLossExponent");
    txPowerDBm = par("txPowerDBm");
    bitRate = par("bitRate");
    noisePowerDBm = par("noisePowerDBm");
    transProbGoodGood = par("transProbGoodGood");
    transProbBadBad = par("transProbBadBad");
    channelGainGoodDB = par("channelGainGoodDB");
    channelGainBadDB = par("channelGainBadDB");

    EV<<"Channel initialising, nodeDistance = "<<nodeDistance<<"\n";
    EV<<"Channel initialising, pathLossExponent = "<<pathLossExponent<<"\n";
    EV<<"Channel initialising, txPowerDBm = "<<txPowerDBm<<"\n";
    EV<<"Channel initialising, bitRate = "<<bitRate<<"\n";
    EV<<"Channel initialising, noisePowerDBm = "<<noisePowerDBm<<"\n";
    EV<<"Channel initialising, transProbGoodGood = "<<transProbGoodGood<<"\n";
    EV<<"Channel initialising, transProbBadBad = "<<transProbBadBad<<"\n";
    EV<<"Channel initialising, channelGainGoodDB = "<<channelGainGoodDB<<"\n";
    EV<<"Channel initialising, channelGainBadDB = "<<channelGainBadDB<<"\n";
}

void Channel_cc::handleMessage(cMessage *msg)
{
    //Handles incoming messages ot the channel
    packetRecord *chanMsg = (packetRecord *)msg;

    packetSize = chanMsg->getUserBits() + chanMsg->getOvhdBits();

    EV<<"Channel handling message!\n\n";
    srand(time(0));

//////////////////////////////////////////////
    //This section determines state of channel:
    EV<<"\nNew bit incoming!\n\n";
    tempRand = rand()/(double)RAND_MAX;
    if (chanGood == true) {
        if(tempRand < transProbGoodGood){
            nextChanGood = false;
            EV<<"transProbGoodGood = "<<transProbGoodGood<<"\n";
        }
    }
    else {
        if(tempRand < transProbBadBad){
            nextChanGood = true;
            EV<<"transProbBadBad = "<<transProbBadBad<<"\n";
        }
    }
    EV<<"temprand = "<<tempRand<<"\n";
    EV<<"Channel is currently good: "<<chanGood<<"\n"<<"Channel next state is good: "<<nextChanGood<<"\n\n";

    //////////////////////////////////////////////
    //This section determines path loss from node distance and path loss exponent
    if (nodeDistance <= 1.0) {
        PLd = 1.0;
    }
    else {
        PLd = pow(nodeDistance, pathLossExponent);
    }
    EV<<"path loss = "<<PLd<<"\n\n";
    EV<<"PLd = "<<PLd<<"\n";
    //////////////////////////////////////////////
    //This section determines received power in dBm

    if(chanGood == true) {
        receivedPower = txPowerDBm + channelGainGoodDB - 10 * log10(PLd);
    }
    else {
        receivedPower = txPowerDBm + channelGainBadDB - 10 * log10(PLd);
    }
    EV<<"receivedPower = "<<receivedPower<<"\n";
    ///////////////////////////////////////////////

    //////////////////////////////////////////////
    //This section calculates the SNR
    SNR = receivedPower - noisePowerDBm - (10 * log10(bitRate));
    EV<<"SNR = "<<SNR<<"\n";
    //////////////////////////////////////////////
    //This section calculates the bit error rate
    BER = erfc(sqrt(2 * (pow(10, SNR/10))));
    EV<<"BER = "<<BER<<"\n";
    ///////////////////////////////////////////
    //This section determines if the channel introduces errors
    tempRand = rand()/(double)RAND_MAX;

    EV<<"temprand = "<<tempRand<<"\n";
    if (tempRand < BER){
        EV<<"Channel introduced error!\n";
        chanMsg->setErrorFlag(true);
    }
    else {
        EV<<"Channel transmits without error!\n";
    }
    ////////////////////////////////////////////



    send(chanMsg, "out");
    //Update channel state to next channel state
    chanGood = nextChanGood;
}
