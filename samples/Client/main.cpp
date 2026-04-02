#include <TickNet/Net/UdpSocket.h>
#include <iostream>

int main()
{
    FUdpSocket Socket;
    if (Socket.Open(7777))
    {
        std::cout << "Socket opened successfully\n";
        Socket.Close();
        std::cout << "Socket closed successfully\n";
        return 0;
    }

    std::cout << "Failed to open socket\n";
    return 1;
}