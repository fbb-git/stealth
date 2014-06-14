#include "stealth.ih"

void Stealth::reloadSignal()
{
    if (not d_run.mode(INTEGRITY_SCAN | WAIT))
    {
        imsg << "--reload ignored in mode " << d_run.modeName() << endl;
        return;
    }

    d_run.setMode(RELOAD);
}
