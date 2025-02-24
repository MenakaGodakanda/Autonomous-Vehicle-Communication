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

- To automate this setup, you can use the provided `setup.sh` script.

#### Run the setup script:
```
./setup.sh
```
![Screenshot 2025-02-24 152354](https://github.com/user-attachments/assets/67caf45a-5d84-4c65-a61b-b89980908933)

#### Verify the interface:
```
ip link show vcan0
```
![Screenshot 2025-02-24 150651](https://github.com/user-attachments/assets/a1979843-faca-4d08-adea-29b3428ac786)

### 5. Compile and Run the C++ CAN Sender
```
g++ src/cpp_can_sender.cpp -o cpp_can_sender
./cpp_can_sender
```
![Screenshot 2025-02-24 151057](https://github.com/user-attachments/assets/b6a486ad-5ad6-4ad5-b5f3-1795e9dfe573)

### 6. Compile and Run the C++ CAN Receiver
```
g++ src/cpp_can_receiver.cpp -o cpp_can_receiver
./cpp_can_receiver
```
![Screenshot 2025-02-24 151341](https://github.com/user-attachments/assets/86351079-da5d-4297-a426-757143671a92)

### 7. Run the Python CAN Sender
```
python3 src/python_can_sender.py
```
![Screenshot 2025-02-24 151916](https://github.com/user-attachments/assets/16d7fba5-600e-4716-8e34-df2b51e6fbbd)

### 8. Run the Python CAN Receiver (Continuous Listening)
```
python3 src/python_can_receiver.py
```
![Screenshot 2025-02-24 152034](https://github.com/user-attachments/assets/8fce1730-0bd9-4f02-9952-cd178f3c5916)

## Testing with candump

To monitor CAN messages, open a terminal and run:
```
candump vcan0
```
You should see output like:
![Screenshot 2025-02-24 152201](https://github.com/user-attachments/assets/26758784-bbc5-4338-8179-7a32d4cbb88f)

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
