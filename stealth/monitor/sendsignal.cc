#include "monitor.ih"

void Monitor::sendSignal(int signum, char const *signame, pid_t pid)
{
    if (kill(pid, signum))          
    {                               
        Lock::unlinkRunFile();

        msg() << "Can't send " << signame << " to process `" << pid << "',\n"  
                 "removed stale run-file `" << Lock::runFilename << '.' << 
                                                                        fatal;
    }

    msg() << signame << " sent" << info;
}

