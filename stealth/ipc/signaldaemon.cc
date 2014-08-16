#include "ipc.ih"

bool IPC::signalDaemon(char const *request)
{
    size_t pid = getPid();    // get the pid of the process to signal 

    write(request);

    m2 << "Sending signal SIGUSR1 to process " << pid << endl;

    sendSignal(SIGUSR1, pid);

    return true;
}


