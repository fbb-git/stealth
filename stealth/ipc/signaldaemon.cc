#include "ipc.ih"

bool IPC::signalDaemon()
{
    readDaemonPid();               // get the pid of the daemon to signal 

    char const *request = d_options.modeRequest();

    write(request);

    m2 << "Sending signal SIGUSR1 to process " << d_daemonPid << endl;

    sendRequest(request, d_daemonPid);

    return true;
}


