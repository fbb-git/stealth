#include "ipc.ih"

bool IPC::signalPeer(int signum)
{
    size_t pid = getPid();    // get the pid of the process to signal 

    m2 << "Sending signal " << s_signame.find(signum)->second << 
                                            " to process " << pid << endl;

    sendSignal(signum, pid);

    return true;
}


