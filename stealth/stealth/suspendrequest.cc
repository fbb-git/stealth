#include "stealth.ih"

string Stealth::suspendRequest()
{
    string ret = d_run.mode(INTEGRITY_SCAN | WAIT | SUSPEND) ?
                    acceptMode(SUSPEND)
                :
                    deniedMode("--suspend");

    return ret;
}
