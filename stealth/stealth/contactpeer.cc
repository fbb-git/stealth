#include "stealth.ih"

bool Stealth::contactPeer()
{
    if (not d_options.ipc())
        return false;

    if (d_options.suppress())
        d_ipc.lockRunFile();

cerr << "Mode = " << d_run.mode() << ", " << d_run.modeName() << '\n';

    return d_ipc.signalPeer(d_run.signum());
}



