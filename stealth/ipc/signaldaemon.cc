#include "ipc.ih"

bool IPC::signalDaemon()
{
    size_t pid = daemonPid();    // get the pid of the daemon to signal 

    auto const &info = d_options.modeInfo();    // requestname, signal(name)

    write(info.modeTxt);

    m2 << "Sending signal " << info.signalTxt << " to process " << pid << 
                                                                        endl;

    sendSignal(info, pid);

    return true;
}


