#pragma once

#include <cstdint>

struct FSocketHandle
{
    uintptr_t Value = 0;

    bool IsValid() const;
    void Reset();
};