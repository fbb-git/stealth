#include "stealth.ih"

string Stealth::reloadRequest()
{
    string ret =  d_task.mode(INTEGRITY_SCAN) ?
                        acceptMode(RELOAD)
                    :
                        deniedMode("--reload");
    return ret;
}




