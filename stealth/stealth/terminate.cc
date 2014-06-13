#include "stealth.ih"

void Stealth::terminate()
{
    report("was terminated");
    d_run.setMode(LEAVE);
}
