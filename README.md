# Simple Autonomous Vehicle Communication System
A software-based implementation of an **Autonomous Vehicle Communication System** using the **CAN (Controller Area Network) protocol**. This project demonstrates inter-vehicle communication using **C++ and Python** with a virtual CAN bus (`vcan0`), requiring no physical hardware.

## Overview
<img width="1272" alt="Screenshot 2025-02-24 at 4 02 15 pm" src="https://github.com/user-attachments/assets/695c2d59-8f7a-44dc-9c5d-43fe1843285c" />

### Explanation
- C++ and Python Senders send messages (`HELLOCAN`) over the virtual CAN bus (`vcan0`).
- The virtual CAN bus (SocketCAN + vcan) simulates a real CAN network.
- C++ and Python Receivers listen and decode messages from `vcan0`.

## Features
- Uses **SocketCAN** on Ubuntu Linux for **virtual CAN bus communication**.
- Implements **CAN sender and receiver** in both **C++ and Python**.
- Supports **continuous message reception**.
- Compatible with **open-source tools** (no hardware required).
- Simulates **real-world vehicle-to-vehicle (V2V) communication**.

## Technologies Used
- **C++** (`g++`, SocketCAN)
- **Python** (`python-can` library)
- **Linux Virtual CAN (`vcan0`)** for software-based CAN communication
- **Ubuntu (or any Linux-based OS)**

## Setup & Installation

### 1. Clone the Repository
```
git clone https://github.com/MenakaGodakanda/Autonomous-Vehicle-Communication.git
cd Autonomous-Vehicle-Communication
```

### 2. Set Up a Virtual Environment
```
python3 -m venv avc
source avc/bin/activate
```

### 3. Install Dependencies
Make sure you have the required tools installed:
```bash
sudo apt update
sudo apt install can-utils python3 python3-pip
pip install python-can
```

### 4. Enable Virtual CAN Interface
Run the following command to create a virtual CAN interface (vcan0):
```
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0
```

- To automate this setup, you can use the provided setup_can.sh script.

### 5. Compile and Run the C++ CAN Sender
```
g++ src/cpp_can_sender.cpp -o cpp_can_sender
./cpp_can_sender
```

### 6. Run the Python CAN Sender
```
python3 src/python_can_sender.py
```

### 7. Run the Python CAN Receiver (Continuous Listening)
```
python3 src/python_can_receiver.py
```

## Testing with candump

To monitor CAN messages, open a terminal and run:
```
candump vcan0
```
You should see output like:

## Example Output

### Python CAN Receiver Output

### `candump` Output

## File Structure
```
Autonomous-Vehicle-Communication/
│── src/
│   ├── cpp_can_sender.cpp
│   ├── cpp_can_receiver.cpp
│   ├── python_can_sender.py
│   ├── python_can_receiver.py
│── setup.sh
│── README.md
```

## License

This project is licensed under the MIT License.
