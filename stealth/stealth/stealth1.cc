#include "stealth.ih"

Stealth::Stealth()
:
    d_logUnit(d_options),
    d_ipc(0),                               // Semaphores
    d_job(1)
{
    d_task.setMode(d_options.mode());
    d_pending.setMode(UNKNOWN);
}




