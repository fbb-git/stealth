#include "stealth.ih"

void Stealth::reloadSignal()
{
    if (not d_run.mode(INTEGRITY_SCAN | WAITING))
    {
        imsg << "--reload ignored in mode " << d_run.modeName() << endl;
        return;
    }

    d_run.setMode(RELOAD);

}
