#include "util.ih"

void Util::sendSignal(int signum, char const *signame, pid_t pid)
{
    if (kill(pid, signum))          
    {                               
        unlink(s_runFilename.c_str());

        exit("Can't send %s to process `%u',\n"  
                "removing stale run-file `%s'.",    
                signame,
                pid,
                s_runFilename.c_str());
    }

    debug() << signame << " sent\n";
}

