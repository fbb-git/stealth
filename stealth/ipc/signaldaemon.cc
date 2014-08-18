#include "ipc.ih"

bool IPC::signalDaemon()
{
    size_t pid = getPid();    // get the pid of the process to signal 

    auto const &info = d_options.modeInfo();

    write(info.modeTxt);

    m2 << "Sending signal " << info.signalTxt << " to process " << pid << 
                                                                        endl;

    sendSignal(info, pid);

    return true;
}


