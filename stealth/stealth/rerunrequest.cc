#include "stealth.ih"

void Stealth::rerunRequest()
{
    if (d_run.mode(WAIT))
        acceptMode(INTEGRITY_SCAN);
    else
        deniedMode("--rerun");
}
