#include "ipc.ih"

void IPC::sendSignal(int signum, pid_t pid)
{
    char const *signame = s_signame.find(signum)->second;

    if (kill(pid, signum))          
    {                               
        Lock::unlinkRunFile();

        fmsg << "Can't send signal " << signame << " to process `" << 
                                                                pid << "',\n"  
                 "removed stale run-file `" << Lock::runFilename << '.' << 
                                                                        endl;
    }

    m2 << signame << " sent" << endl;
}

