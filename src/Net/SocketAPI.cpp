#include "TickNet/Net/SocketAPI.h"

#include <WinSock2.h>
#include <WS2tcpip.h>

bool FSocketApi::bInitialized = false;

bool FSocketApi::Startup()
{
    if (bInitialized)
    {
        return true;
    }

    //WinSock is the Windows API that lets your program use sockets to communicate over the network.
    WSADATA WsaData = {};
    //Initializes the WinSocket system. Aka. Turn on networking for this program
    //Version 2.2 of WinSock (I want WinSock version 2.2)
    const int Result = WSAStartup(MAKEWORD(2, 2), &WsaData);
    if (Result != 0)
    {
        return false;
    }

    bInitialized = true;
    return true;
}

void FSocketApi::Shutdown()
{
    if (!bInitialized)
    {
        return;
    }

    //Shuts down the WinSock system.
    WSACleanup();
    
    bInitialized = false;
}
