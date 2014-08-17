#include "stealth.ih"

void Stealth::expectRequest()
{
    if (d_run.mode(WAIT))
    {
        while (true)
        {
            d_ipc.timedWait();
            if (d_ipc.timeOut() || d_request)   // wait for the next request
                break;                          // or timeout
        }

        if (d_run.mode(WAIT))
            d_run.setMode(INTEGRITY_SCAN);
    }
}
