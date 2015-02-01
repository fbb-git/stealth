#include "stealth.ih"

string Stealth::rerunRequest()
{
    string ret = d_task.hasMode(INTEGRITY_SCAN) ?
            acceptMode(RERUN)
        :
            deniedMode("--rerun");

    return ret;
}
