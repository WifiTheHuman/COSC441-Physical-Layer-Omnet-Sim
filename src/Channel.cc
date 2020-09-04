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
    double BERGood;
    double BERBad;
    double BER;
    double PLd;
    double receivedPowerGood;
    double receivedPowerBad;
    double SNRGood;
    double SNRBad;

    int packetSize;

    bool chanGood = true;
    bool nextChanGood = true;

    cMessage *requestMsg = new cMessage();
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

//    EV<<"Channel initialising, nodeDistance = "<<nodeDistance<<"\n";
//    EV<<"Channel initialising, pathLossExponent = "<<pathLossExponent<<"\n";
//    EV<<"Channel initialising, txPowerDBm = "<<txPowerDBm<<"\n";
//    EV<<"Channel initialising, bitRate = "<<bitRate<<"\n";
//    EV<<"Channel initialising, noisePowerDBm = "<<noisePowerDBm<<"\n";
//    EV<<"Channel initialising, transProbGoodGood = "<<transProbGoodGood<<"\n";
//    EV<<"Channel initialising, transProbBadBad = "<<transProbBadBad<<"\n";
//    EV<<"Channel initialising, channelGainGoodDB = "<<channelGainGoodDB<<"\n";
//    EV<<"Channel initialising, channelGainBadDB = "<<channelGainBadDB<<"\n";


    send(requestMsg, "requestOut");

}

void Channel_cc::determineChanState() {
    /////////////////////////////////////
    //Determines next channel state from current state
    tempRand = rand()/(double)RAND_MAX;
    if (chanGood == true) {
        if(tempRand < transProbGoodGood){
            nextChanGood = true;
//            EV<<"transProbGoodGood = "<<transProbGoodGood<<"\n";
        }
        else {
            nextChanGood = false;
        }
    }
    else {
        if(tempRand < transProbBadBad){
            nextChanGood = false;
//            EV<<"transProbBadBad = "<<transProbBadBad<<"\n";
        }
        else {
            nextChanGood = true;
        }
    }
//    EV<<"temprand = "<<tempRand<<"\n";
//    EV<<"Channel is currently good: "<<chanGood<<"\n"<<"Channel next state is good: "<<nextChanGood<<"\n\n";
}

void Channel_cc::calcPathLoss() {
    //////////////////////////////////////////////
    //This section determines path loss from node distance and path loss exponent
    if (nodeDistance <= 1.0) {
        PLd = 1.0;
        }
        else {
            PLd = pow(nodeDistance, pathLossExponent);
        }
        EV<<"path loss = "<<PLd<<"\n\n";
}
//
//void Channel_cc::calcReceivedPower() {
//    //////////////////////////////////////////////
//    //This section determines received power in dBm
//
//    if(chanGood == true) {
//        receivedPower = txPowerDBm + channelGainGoodDB - 10 * log10(PLd);
//    }
//    else {
//        receivedPower = txPowerDBm + channelGainBadDB - 10 * log10(PLd);
//    }
//    EV<<"receivedPower = "<<receivedPower<<"\n";
//    ///////////////////////////////////////////////
//}
//
//void Channel_cc::calcSNRandBER() {
//    //////////////////////////////////////////////
//    //This section calculates the SNR
//    SNR = receivedPower - noisePowerDBm - (10 * log10(bitRate));
//    EV<<"SNR = "<<SNR<<"\n";
//    //This section calculates the bit error rate
//    BER = erfc(sqrt(2 * (pow(10, SNR/10))));
//    EV<<"BER = "<<BER<<"\n";
//    //////////////////////////////////////////////
//}

void Channel_cc::calcBER() {
    //////////////////////////////////////////////
        //This section determines received power in dBm
        calcPathLoss();
        receivedPowerGood = txPowerDBm + channelGainGoodDB - 10 * log10(PLd);
        receivedPowerBad = txPowerDBm + channelGainBadDB - 10 * log10(PLd);

        EV<<"receivedPower = "<<receivedPowerGood<<"\n";
        //////////////////////////////////////////
        //This section calculates the SNR
        SNRGood = receivedPowerGood - noisePowerDBm - (10 * log10(bitRate));
        SNRBad = receivedPowerBad - noisePowerDBm - (10 * log10(bitRate));
        EV<<"SNR = "<<SNRGood<<"\n";
        //This section calculates the bit error rate
        BERGood = erfc(sqrt(2 * (pow(10, SNRGood/10))));
        BERBad = erfc(sqrt(2 * (pow(10, SNRBad/10))));
        EV<<"BERGood = "<<BERGood<<"\n";
        EV<<"BERBad = "<<BERBad<<"\n";
        //////////////////////////////////////////////
}

void Channel_cc::handleMessage(cMessage *msg)
{
    //Handles incoming messages ot the channel
    packetRecord *chanMsg = (packetRecord *)msg;

    packetSize = chanMsg->getUserBits() + chanMsg->getOvhdBits();

//    EV<<"Channel handling message!\n\n";
    srand(time(0));
    calcPathLoss();//maybe move to init
    calcBER();
    for (int i = 0; i < packetSize; i++) {
//        EV<<"\nNew bit incoming!\n\n";
        determineChanState();

        if (chanGood) {
            BER = BERGood;
        }
        else {
            BER = BERBad;
        }
        //This section determines if the channel introduces errors
        tempRand = rand()/(double)RAND_MAX;

//        EV<<"temprand = "<<tempRand<<"\n";

        if (tempRand < BER){
//            EV<<"Bit contains error!\n";
            chanMsg->setErrorFlag(true);
        }
        else {
//            EV<<"Bit transmits without error!\n";
        }
        ////////////////////////////////////////////
        //Update channel state to next channel state
        chanGood = nextChanGood;
    }
    //////////////////////////////////////////////
    //This section determines state of channel:
//    EV<<"Error flag state: "<<chanMsg->getErrorFlag()<<"\n";

    send(chanMsg, "out");

    cMessage *requestMsg = new cMessage();
    send(requestMsg, "requestOut");
}
