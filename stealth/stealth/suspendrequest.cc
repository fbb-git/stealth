#include "stealth.ih"

void Stealth::suspendRequest()
{
    if (d_run.mode(INTEGRITY_SCAN | WAIT | SUSPEND))
        acceptMode(SUSPEND);
    else
        deniedMode("--suspend");
}
