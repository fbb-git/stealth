#include "ipc.ih"

void IPC::sendRequest(char const *request, pid_t pid)
{
    if (kill(pid, SIGUSR1) != 0)          
    {                         
        unlink(d_options.runFile().c_str());
      
        fmsg << "Can't send signal SIGUSR1 to process `" << pid << "',\n"  
                 "removed stale run-file `" << d_options.runFile() << '.' << 
                                                                endl;
    }

    m2 << "stealth command line process sent request " << request << 
                                " to stealth daemon " << pid << endl;
}

