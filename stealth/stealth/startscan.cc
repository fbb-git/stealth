#include "stealth.ih"

void Stealth::startScan()
{
    endScanner();
    d_scanThread = thread(startThread<&Stealth::integrityScan>, this);
    d_ipc.notify();
}
