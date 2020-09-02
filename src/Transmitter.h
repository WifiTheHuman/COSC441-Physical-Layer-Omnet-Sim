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

#ifndef ___441ASSIGNMENT1_TRANSMITTER_CC_H_
#define ___441ASSIGNMENT1_TRANSMITTER_CC_H_

#include <omnetpp.h>
#include "packetRecord_m.h"

#include <string.h>
#include <omnetpp.h>
#include <iostream>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Transmitter_cc : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
  private:
    int numberOverheadBits;
    int NumberUserBits;
};

#endif
