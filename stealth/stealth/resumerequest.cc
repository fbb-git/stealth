#include "stealth.ih"

std::string Stealth::resumeRequest()
{
    string ret = d_task.hasMode(SUSPEND) ?
                    acceptMode(RESUME)
                :    
                    deniedMode("--resume");

    return ret;
}
