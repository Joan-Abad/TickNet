#include <TickNet/Platform/SocketHandle.h>

bool FSocketHandle::IsValid() const
{
    return Value != 0;
}

void FSocketHandle::Reset()
{
    Value = 0;
}