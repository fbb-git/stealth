#include "stealth.ih"

void Stealth::rerunRequest()
{
    if (d_run.mode(WAIT))
        d_run.setMode(INTEGRITY_SCAN);
    else
        m2 << "ignored --rerun in mode " << d_run.modeName() << endl;
}