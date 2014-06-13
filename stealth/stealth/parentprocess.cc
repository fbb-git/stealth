#include "stealth.ih"

void Stealth::parentProcess()
{
    d_ipc.writeRunFile(pid());
}

