

#include <iostream>

#include "TickNet/Net/IpAddress.h"
#include "TickNet/Net/UdpSocket.h"

int main()
{
    FUdpSocket Socket;
    if (!Socket.Open(7777))
    {
        std::cout << "Failed to open server socket\n";
        return 1;
    }

    std::cout << "Server listening on port 7777\n";

    uint8 Buffer[256];
    FIpAddress FromAddress;

    while (true)
    {
        const int32 BytesReceived = Socket.ReceiveFrom(Buffer, sizeof(Buffer), FromAddress);
        if (BytesReceived > 0)
        {
            std::cout << "Received " << BytesReceived << " bytes\n";
        }
    }
}
