#include "stealth.ih"

void Stealth::expectRequest()
{
    if (d_run.mode(WAIT))
    {
        d_ipc.timedWait();              // wait for the next request
        if (d_run.mode(WAIT))
            d_run.setMode(INTEGRITY_SCAN);
    }
}
