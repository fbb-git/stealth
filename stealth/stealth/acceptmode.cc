#include "stealth.ih"

void Stealth::acceptMode(Mode mode)
{
    d_ipc.sendRequestor("OK");
    d_run.setMode(mode);
}
