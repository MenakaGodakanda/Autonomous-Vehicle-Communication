#!/bin/bash
echo "Setting up virtual CAN interface..."
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0
echo "Setup complete!"

