#include "stealth.ih"

void Stealth::reloadRequest()
{
    if (d_run.mode(INTEGRITY_SCAN | WAIT | SUSPEND))
        d_run.setMode(RELOAD);
    else
        m2 << "ignored --reload in mode " << d_run.modeName() << endl;
}
