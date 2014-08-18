#include "ipc.ih"

void IPC::sendSignal(ModeInfo const &info, pid_t pid)
{
    if (kill(pid, info.signum) != 0)          
    {                         
        unlink(d_options.runFile().c_str());
      
        fmsg << "Can't send signal " << info.signalTxt << " to process `" << 
                                                                pid << "',\n"  
                 "removed stale run-file `" << d_options.runFile() << '.' << 
                                                                endl;
    }

    m2 << "sent signal " << info.signalTxt << endl;
}

