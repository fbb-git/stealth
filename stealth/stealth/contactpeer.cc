#include "stealth.ih"

bool Stealth::contactPeer()
{
    if (not d_options.ipc())
        return false;

    if (d_options.suppress())
        d_ipc.lockRunFile();

    return d_ipc.signalPeer(signum());
}



