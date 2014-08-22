#include "stealth.ih"

void Stealth::reloadRequest()
{
    if (d_run.mode(INTEGRITY_SCAN | WAIT | SUSPEND))
        acceptMode(RELOAD);
    else
        deniedMode("--reload");
}




