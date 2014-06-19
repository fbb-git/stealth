#include "ipc.ih"

void IPC::sendSignal(int signum, pid_t pid)
{
    char const *signame = s_signame.find(signum)->second;

    if (kill(pid, signum) != 0)          
    {                         
        unlink(d_options.runFile().c_str());
      
        fmsg << "Can't send signal " << signame << " to process `" << 
                                                                pid << "',\n"  
                 "removed stale run-file `" << d_options.runFile() << '.' << 
                                                                endl;
    }

    m2 << "sent signal " << signame << endl;
}

