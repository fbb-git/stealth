#include "stealth.ih"

void Stealth::startScan()
{
    d_ipc.notify();
    d_scanThread = thread(startThread<&Stealth::integrityScan>, this);
}
