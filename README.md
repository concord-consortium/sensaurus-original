# sensaur-arduino

Arduino code for the Sensaur project. These sketches/libraries are used for the hub board and sensaur/actuator devices that plug into the hub board.

The hub board has two forms: one that attaches to a Raspberry Pi and one that attaches to an ESP32 microcontroller.
See the [sensaur repo](https://github.com/manylabs/sensaur) for python code that runs on the Rasbperry Pi.

The device boards connect to the hub using audio cables that carry power and serial data. The communication between the hub and the devices 
uses a single serial line for both transmitting and receiving (i.e. half-duplex serial).
