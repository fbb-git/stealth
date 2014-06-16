#include "stealth.ih"

void Stealth::reloadSignal()
{
    if (d_run.mode(INTEGRITY_SCAN | WAIT))
        d_run.setMode(RELOAD);
    else
        m2 << "ignored --reload in mode " << d_run.modeName() << endl;
}
