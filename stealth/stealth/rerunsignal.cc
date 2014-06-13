#include "stealth.ih"

void Stealth::rerunSignal()
{
    if (d_run.mode(WAITING))
        d_run.setMode(INTEGRITY_SCAN);
    else
        imsg << "--rerun request ignored in mode " << d_run.modeName() << 
                                                                    endl;
}
