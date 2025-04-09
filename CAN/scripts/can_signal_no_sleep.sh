#!/bin/bash

# Define the CAN interface and packet
CAN_INTERFACE="vcan0"
CAN_PACKET="188#03"


while true; do
    cansend $CAN_INTERFACE $CAN_PACKET 
done
