#include "stealth.ih"

void Stealth::acceptMode(Mode mode)
{
    d_run.setMode(mode);
    d_ipc.sendRequestor("OK");
}
