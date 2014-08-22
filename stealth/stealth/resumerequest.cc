#include "stealth.ih"

void Stealth::resumeRequest()
{
    if (d_run.mode(SUSPEND))
        acceptMode(RESUME);
    else
        deniedMode("--resume");
}
