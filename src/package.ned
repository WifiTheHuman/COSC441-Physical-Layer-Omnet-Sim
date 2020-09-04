package attempt69;

@license(LGPL);
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
//
// TODO auto-generated module
//

network physicalLayer
{
    @display("bgb=308,87");
    submodules:

        Tx: Transmitter_cc {
            @display("p=129.67499,11.829999");
        }
        Rx: Receiver_cc {
            @display("p=129.67499,66.884995");
        }
        Chan: Channel_cc {
            @display("p=237.055,29.574999");
        }
    connections:
//        Tx.out --> {  delay = 100ms; } --> Chan.in;
//        Chan.out --> {  delay = 100ms; } --> Rx.in;
		Tx.out --> Chan.in;
        Chan.out --> Rx.in;
        Chan.requestOut --> Tx.in;

}
