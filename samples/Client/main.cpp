#include <TickNet/Net/UdpSocket.h>
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

#include "TickNet/Net/IpAddress.h"

int main()
{
    FUdpSocket Socket;
    if (!Socket.Open(0))
    {
        std::cout << "Failed to open client socket\n";
        return 1;
    }

    const char* Message = "Hello";
    uint32 Ip = 0;

    in_addr Addr = {};
    if (inet_pton(AF_INET, "192.168.0.11", &Addr) == 1)
    {
        Ip = ntohl(Addr.s_addr);
    }
    else
    {
        // Handle error (invalid IP)
    }
    FIpAddress ServerAddress(Ip, 7777);

    const int32 BytesSent = Socket.SendTo(
        reinterpret_cast<const uint8*>(Message),
        5,
        ServerAddress);

    if (BytesSent > 0)
    {
        std::cout << "Sent " << BytesSent << " bytes\n";
    }
    else
    {
        std::cout << "Send failed\n";
    }
}
