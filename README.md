# Automotive security Workshop

This repository contains various material that will be used in the different automotive workshops.
These were adapted from the 2024 edition of [Barbhack](https://www.barbhack.fr), the french southernmost hacking event. 

The purpose of this series of workshops is to teach some basics on automotive security :

- Workshop 1 : an overview of the CAN bus from a security point of view.
- Workshop 2 : *Loading*

## Workshop 1 : CAN bus hands-on

To discover the CAN bus, this repo holds a fork of "Instrument Cluster Simulator for SocketCAN" aka **ICSim** : https://github.com/zombieCraig/ICSim

It extends the basic ICSim with some specific features :
* Some controls are not related to a CAN frame, to simulate sensors/actuators on ECU
* A very basic diag tool is simulated to help understanding UDS protocol
* A few OBD-II and UDS commands are supported

![Main UI](https://raw.githubusercontent.com/phil-eqtech/CH-Workshop/master/media/interface.png)
![Controls](https://raw.githubusercontent.com/phil-eqtech/CH-Workshop/master/media/controls.png)


## Workshop 2 : *Loading*

