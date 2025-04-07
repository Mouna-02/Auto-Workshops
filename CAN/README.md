# CAN bus hands-on

To discover the CAN bus, this repo holds a fork of "Instrument Cluster Simulator for SocketCAN" aka **ICSim** : https://github.com/zombieCraig/ICSim

The version used is that of Quarkslab's workshop : https://github.com/phil-eqtech/CH-Workshop which extends the basic ICSim with some specific features :
* Some controls are not related to a CAN frame, to simulate sensors/actuators on ECU
* A very basic diag tool is simulated to help understanding UDS protocol
* A few OBD-II and UDS commands are supported

![Main UI](https://raw.githubusercontent.com/phil-eqtech/CH-Workshop/master/media/interface.png)
![Controls](https://raw.githubusercontent.com/phil-eqtech/CH-Workshop/master/media/controls.png)


## Challenges

- Blink the turn signals on the instrument cluster without manually activating the warning or turn commands.
- The speed is limited to 100Km/h. Can you move the needle on the speedometer above this limit ?
- Can you get the VIN of the car ?
- A sensor triggers the lights by night. Can you override it ?


## Compiling

Before this workshop, you were all asked to have a running Virtual Machine that is linux-based.

You will need:
* SDL2
* SDL2_Image
* can-utils

You can run the following:

```
  sudo apt-get install libsdl2-dev libsdl2-image-dev can-utils  
```

## Default operation
------------------

You will need a virtual CAN interface to run this software.

You can create it using the "setup_vcan.sh" as sudo
```
  sudo ./setup_vcan.sh
```

OR type the following commands :

```
  sudo modprobe can
  sudo modprobe vcan
  sudo ip link add dev vcan0 type vcan
  sudo ip link set up vcan0
```

If you type "ifconfig vcan0" or "ip a" you should see a vcan0 interface.

Once the virtual CAN interface is up and running, type the two following commands in two different terminals :

```
  ./controls vcan0
```
and
```
  ./icsim vcan0
```
Each application can be closed by typing "Ctrl+c" in the terminal window.

Troubleshooting
---------------
* If you have to relaunch the "controls" app, you need to restart "icsim" also, to sync the shared data and transiting can packets.
* If the GUI is blinking/glitching, move it away from any open windows and get the focus by clicking in it.

## lib.o not linking
If lib.o doesn't link it's probably because it's the wrong arch for your platform.  To fix this you will
want to compile can-utils and copy the newly compiled lib.o to the icsim directory.  You can get can-utils
from: https://github.com/linux-can/can-utils

## read: Bad address
When running `./icsim vcan0` you end up getting a `read: Bad Address` message,
this is typically a result of needing to recompile with updated SDL libraries.
Make sure you have the recommended latest SDL2 libraries.  Some users have
reported fixing this problem by creating symlinks to the SDL.h files manually
or you could edit the Makefile and change the CFLAGS to point to wherever your
distro installs the SDL.h header, ie: /usr/include/x86_64-linux-gnu/SDL2

There was also a report that on Arch linux needed sdl2_gfx library.
