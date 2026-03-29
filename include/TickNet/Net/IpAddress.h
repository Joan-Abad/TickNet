#pragma once

#include <TickNet/Platform/PlatformTypes.h>

class FIpAddress
{
public:
    FIpAddress() = default;
    FIpAddress(uint32 InAddress, uint16 InPort);

    uint32 GetAddress() const;
    uint16 GetPort() const;

private:
    uint32 Address = 0;
    uint16 Port = 0;
};