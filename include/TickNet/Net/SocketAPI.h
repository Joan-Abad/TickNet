#pragma once

class FSocketApi
{
public:
    static bool Startup();
    static void Shutdown();

private:
    static bool bInitialized;
};