#include "ipc.ih"

void IPC::sendSignal(int signum, pid_t pid)
{
cerr << "SIGNAL nr = " << signum << '\n';

    char const *signame = s_signame.find(signum)->second;

    if (kill(pid, signum))          
    {                               
        Lock::unlinkRunFile();

        fmsg << "Can't send signal " << signame << " to process `" << 
                                                                pid << "',\n"  
                 "removed stale run-file `" << Lock::runFilename << '.' << 
                                                                        endl;
    }

    imsg << signame << " sent" << endl;
}

