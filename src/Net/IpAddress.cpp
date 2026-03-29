#include <TickNet/Net/IpAddress.h>

FIpAddress::FIpAddress(uint32 InAddress, uint16 InPort)
    : Address(InAddress)
    , Port(InPort)
{
    
}

uint32 FIpAddress::GetAddress() const
{
    return Address;
}

uint16 FIpAddress::GetPort() const
{
    return Port;
}