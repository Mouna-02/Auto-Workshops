# Automotive security Workshop

This repository contains various material that will be used in the different automotive workshops. 

The purpose of this series of workshops is to teach some basics on automotive security :

- Workshop 1 : an overview of the CAN bus from a security point of view.
- Workshop 2 : a very simple ransomware encryption algorithm that should be studied and reversed.

## Workshop 1 : CAN bus hands-on

This workshop was adapted from the 2024 edition of [Barbhack](https://www.barbhack.fr), the french southernmost hacking event.

To discover the CAN bus, this repo holds a fork of "Instrument Cluster Simulator for SocketCAN" aka **ICSim** : https://github.com/zombieCraig/ICSim

It extends the basic ICSim with some specific features :
* Some controls are not related to a CAN frame, to simulate sensors/actuators on ECU
* A very basic diag tool is simulated to help understanding UDS protocol
* A few OBD-II and UDS commands are supported

![Main UI](https://raw.githubusercontent.com/phil-eqtech/CH-Workshop/master/media/interface.png)
![Controls](https://raw.githubusercontent.com/phil-eqtech/CH-Workshop/master/media/controls.png)


## Workshop 2 : Cryptography 101

The content in this repository provides support for the lab from the Cryptography 101 workjshop.
The lab was dedicated to ransomware, so an encrypted file was provided along with the encryption script.
The script was overly simplified from a HackTheBox challenge (in order to fit the alloted timeslot).

The goal is to:
* Understand the logic used to encrypt the original "highly_important.txt" file.
* Reverse the logic to obtain a decrypted readable file from the provided "highly_important.enc" file.





