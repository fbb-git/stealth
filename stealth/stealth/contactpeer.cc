#include "stealth.ih"

bool Stealth::contactPeer()
{
    if (d_options.suppress())
        d_ipc.lockRunFile();

    return d_ipc.signalPeer(signum());
}



