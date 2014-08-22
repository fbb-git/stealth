#include "ipc.ih"

bool IPC::signalDaemon()
{
    size_t pid = daemonPid();    // get the pid of the daemon to signal 

    char const *request = d_options.modeRequest();

    write(request);

    m2 << "Sending signal SIGUSR1 to process " << pid << endl;

    sendRequest(request, pid);

    return true;
}


