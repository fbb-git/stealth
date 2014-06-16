#include "stealth.ih"

void Stealth::suspendSignal()
{
    if (d_run.mode(INTEGRITY_SCAN | WAIT))
        d_run.setMode(SUSPEND);
    else
        m2 << "ignored --suspend in mode " << d_run.modeName() << endl;
}
