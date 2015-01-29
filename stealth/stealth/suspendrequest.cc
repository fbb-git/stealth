#include "stealth.ih"

string Stealth::suspendRequest()
{
    string ret = d_task.mode(INTEGRITY_SCAN | SUSPEND) ?
                    acceptMode(SUSPEND)
                :
                    deniedMode("--suspend");

    return ret;
}
