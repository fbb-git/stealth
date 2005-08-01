#include "util.h2"

void Util::sendSignal(int signum, char const *signame, pid_t pid)
{
    if (kill(pid, signum))          
    {                               
        unlink(s_runFilename.c_str());

        exit(1, "Can't send %s to process `%u',\n"  
                "removing stale run-file `%s'.",    
                signame,
                pid,
                s_runFilename.c_str());
    }

    dout(signame << " sent");
}

