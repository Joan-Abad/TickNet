#include <TickNet/Net/UdpSocket.h>
#include <TickNet/Net/SocketApi.h>

#include <WinSock2.h>
#include <WS2tcpip.h>

bool FUdpSocket::Open(uint16 Port)
{
    if (IsOpen())
    {
        return false;
    }

    if (!FSocketApi::Startup())
    {
        return false;
    }

    //Creates a socket (endpoint) for communication. AF_INET = IPv4, SOCK_DGRAM = UDP, IPPROTO_UDP = UDP protocol
    const SOCKET NativeSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (NativeSocket == INVALID_SOCKET)
    {
        return false;
    }

    u_long NonBlocking = 1;
    /*Configures socket behavior
    * FIONBIO: Set non-blocking mode
    * Blocking: recv() → waits until data arrives 
    * Non-Blocking: recv() → waits until data arrives (bad for games)
     */
    if (ioctlsocket(NativeSocket, FIONBIO, &NonBlocking) != 0)
    {
        closesocket(NativeSocket);
        return false;
    }

    sockaddr_in Address = {};
    Address.sin_family = AF_INET;
    Address.sin_addr.s_addr = htonl(INADDR_ANY);
    Address.sin_port = htons(Port);

    //Attaches your socket to a local address and port. This is necessary for the socket to receive data sent to that address and port. Deliver packets sent to this port to me
    //Example: Any packet to port 7777 → goes to your socket
    //All the packets to port 7777 on this machine will be delivered to your socket. You can have multiple sockets bound to the same port, but only one of them will receive each packet (the one that was bound first).
    if (bind(NativeSocket, reinterpret_cast<const sockaddr*>(&Address), sizeof(Address)) != 0)
    {
        closesocket(NativeSocket);
        return false;
    }

    Handle.Value = static_cast<uintptr_t>(NativeSocket);
    return true;
}

void FUdpSocket::Close()
{
    if (!IsOpen())
    {
        return;
    }

    const SOCKET NativeSocket = static_cast<SOCKET>(Handle.Value);
    closesocket(NativeSocket);
    Handle.Reset();
}

bool FUdpSocket::IsOpen() const
{
    return Handle.IsValid();
}