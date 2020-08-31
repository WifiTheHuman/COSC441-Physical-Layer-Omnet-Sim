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

package _441assignment1;

//
// TODO auto-generated module
//
simple Transmitter_cc
{
    parameters:
        int numberOverheadBits;
    	int NumberUserBits;
    gates:
        input in;
        output out;
}

simple Receiver_cc
{
    parameters:
        bool errorFlag;
    	double PLProb_Q;
    gates:
        input in;
        output out;
}

simple Channel_cc
{
    parameters:
        double nodeDistance;
        double pathLossExponent;
        double txPowerDBm;
        double bitRate;
        double noisePowerDBm;
        double transProbGoodGood;
        double transProbBadBad;
        double channelGainGoodDB;
        double channelGainBadDB;
    gates:
        input in;
        output out;
}

network physicalLayer
{
    @display("bgb=308,87");
    submodules:
        Tx: Transmitter_cc;
        Rx: Receiver_cc {
            @display("p=249,30");
        }
        Chan: Channel_cc {
            @display("p=143,30");
        }
    connections:
        Tx.out --> {  delay = 100ms; } --> Chan.in;
        Chan.out --> {  delay = 100ms; } --> Rx.in;
}
