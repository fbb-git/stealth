#include "stealth.ih"

string Stealth::reloadRequest()
{
    string ret =  d_run.mode(INTEGRITY_SCAN | WAIT | SUSPEND) ?
                        acceptMode(RELOAD)
                    :
                        deniedMode("--reload");
    return ret;
}




