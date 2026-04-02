#pragma once
#include "TickNet/Platform/PlatformTypes.h"
#include "TickNet/Platform/SocketHandle.h"

class FUdpSocket
{
public:
    bool Open(uint16 Port);
    void Close();
    bool IsOpen() const;

private:
    FSocketHandle Handle;
};
