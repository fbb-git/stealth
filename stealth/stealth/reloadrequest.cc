#include "stealth.ih"

string Stealth::reloadRequest()
{
    string ret =  d_task.mode(INTEGRITY_SCAN | SUSPEND) ?
                        acceptMode(RELOAD)
                    :
                        deniedMode("--reload");
    return ret;
}




