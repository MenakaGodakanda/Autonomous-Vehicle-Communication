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
    strcpy(ifr.ifr_name, "vcan0");
    ioctl(socket_fd, SIOCGIFINDEX, &ifr);

    struct sockaddr_can addr = {};
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    
    if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cerr << "Error binding socket\n";
        return 1;
    }

    struct can_frame frame;
    while (true) {
        int bytes = read(socket_fd, &frame, sizeof(frame));
        if (bytes > 0) {
            std::cout << "Received CAN ID: 0x" << std::hex << frame.can_id << "\n";
            std::cout << "Data: " << std::string((char *)frame.data, frame.can_dlc) << "\n";
        }
    }

    close(socket_fd);
    return 0;
}

