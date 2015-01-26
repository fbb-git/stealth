#include "stealth.ih"

std::string Stealth::resumeRequest()
{
    string ret = d_run.mode(SUSPEND) ?
                    acceptMode(RESUME)
                :    
                    deniedMode("--resume");

    return ret;
}
