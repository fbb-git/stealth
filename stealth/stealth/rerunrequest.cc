#include "stealth.ih"

string Stealth::rerunRequest()
{
    string ret = d_run.mode(WAIT) ?
            acceptMode(INTEGRITY_SCAN)
        :
            deniedMode("--rerun");

    return ret;
}
