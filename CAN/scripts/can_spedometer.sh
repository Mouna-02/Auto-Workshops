#!/bin/bash

# Define the CAN interface and packet
CAN_INTERFACE="vcan0"
CAN_PACKET="244#0000005100"


while true; do
    cansend $CAN_INTERFACE $CAN_PACKET
    sleep 0.0001  
done
