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

#ifndef ___441ASSIGNMENT1_CHANNEL_CC_H_
#define ___441ASSIGNMENT1_CHANNEL_CC_H_

#include <omnetpp.h>
#include "packetRecord_m.h"
#include<time.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Channel_cc : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    void determineChanState();
    void calcPathLoss();
    void calcReceivedPower();
    void calcSNRandBER();
    void calcBER();

  private:
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

#endif
