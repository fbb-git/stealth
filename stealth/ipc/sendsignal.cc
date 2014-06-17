#include "ipc.ih"

void IPC::sendSignal(int signum, pid_t pid)
{
    char const *signame = s_signame.find(signum)->second;

    if (kill(pid, signum))          
    {                               
//        Lock::unlinkRunFile();

        fmsg << "Can't send signal " << signame << " to process `" << 
                                                                pid << "',\n"  
//                 "removed stale run-file `" << Lock::runFilename << '.' << 
                 "removed stale run-file `" << 
                                Options::instance().runFile() << '.' << endl;
    }

    m2 << signame << " sent" << endl;
}

