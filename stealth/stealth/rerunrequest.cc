#include "stealth.ih"

string Stealth::rerunRequest()
{
    string ret = d_task.mode(INTEGRITY_SCAN) ?
            acceptMode(RERUN)
        :
            deniedMode("--rerun");

    return ret;
}
