#include "stealth.ih"

void Stealth::terminate()
{
    logMsg("was terminated");
    d_run.setMode(LEAVE);
}
