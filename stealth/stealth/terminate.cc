#include "stealth.ih"

void Stealth::terminate()
{
    logMsg("terminates");
    d_run.setMode(LEAVE);
}
