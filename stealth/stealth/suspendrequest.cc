#include "stealth.ih"

void Stealth::suspendRequest()
{
    if (d_run.mode(INTEGRITY_SCAN | WAIT | SUSPEND))
        d_run.setMode(SUSPEND);
    else
        m2 << "ignored --suspend in mode " << d_run.modeName() << endl;
}
