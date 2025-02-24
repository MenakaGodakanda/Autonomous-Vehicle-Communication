#include <iostream>
#include <cstring>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main() {
    int socket_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (socket_fd < 0) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    struct ifreq ifr;
    strcpy(ifr.ifr_name, "vcan0");  // Set the virtual CAN interface
    ioctl(socket_fd, SIOCGIFINDEX, &ifr);  // Get the index of the interface

    struct sockaddr_can addr = {};
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cerr << "Error binding socket\n";
        return 1;
    }

    struct can_frame frame = {};
    frame.can_id = 0x123;
    frame.can_dlc = 8;
    std::memcpy(frame.data, "HELLOCAN", 8);

    if (write(socket_fd, &frame, sizeof(frame)) != sizeof(frame)) {
        std::cerr << "Error sending CAN frame\n";
    } else {
        std::cout << "CAN message sent\n";
    }

    close(socket_fd);
    return 0;
}

