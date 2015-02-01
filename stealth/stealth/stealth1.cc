#include "stealth.ih"

Stealth::Stealth()
:
    d_options(Options::instance()),         // determine all options / runmode
    d_ipc(0),
    d_job(1)
{
    d_task.setMode(d_options.mode());
    d_pending.setMode(UNKNOWN);
}




