#include "Runtime.h"

void ARuntime::SetContextState(bool state)
{
    isContextInitializated = state;
}

bool ARuntime::GetContextState()
{
    return isContextInitializated;
}

void ARuntime::SetPollWindow(Window* window)
{
    pollWindow = window;
}

Window* ARuntime::GetPollWindow()
{
    return pollWindow;
}
