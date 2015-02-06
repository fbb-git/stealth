#include "stealth.ih"

void Stealth::notifyTask()
{
    d_task = d_pending;             // set the next request
    d_pending.setMode(UNKNOWN);     // clear the pending request

    d_job.notify();                 // notify processRequests (i.e., 
}
