#!/bin/bash

# Define the CAN interface and packet
CAN_INTERFACE="vcan0"
CAN_PACKET="7E0#020902AAAAAAAAAA"
CAN_FC="7E0#3000000000000000"

while true; do
	cansend $CAN_INTERFACE $CAN_PACKET
	cansend $CAN_INTERFACE $CAN_FC
done
