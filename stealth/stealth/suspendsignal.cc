#include "stealth.ih"

void Stealth::suspendSignal()
{
    if (not d_run.mode(INTEGRITY_SCAN | WAITING))
    {
        imsg << "--suspend ignored in mode " << d_run.modeName() << endl;
        return;
    }

    d_run.setMode(SUSPEND);

    
}
