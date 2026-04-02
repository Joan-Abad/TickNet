#pragma once
#include "TickNet/Platform/PlatformTypes.h"
#include "TickNet/Platform/SocketHandle.h"

class FIpAddress;

class FUdpSocket
{
public:
    bool Open(uint16 Port);
    void Close();
    bool IsOpen() const;
    int32 SendTo(const uint8* Data, int32 DataSize, const FIpAddress& Address);
    int32 ReceiveFrom(uint8* Buffer, int32 BufferSize, FIpAddress& OutAddress);

private:
    FSocketHandle Handle;
};
