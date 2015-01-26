#include "stealth.ih"

Stealth::Mode Stealth::nextTask()
{
    if (d_run.mode() == WAIT)
        wait();

    return d_run.mode();
}
