#include "stealth.ih"

bool Stealth::contactPeer()
{
    return d_options.ipc() ? d_ipc.signalDaemon() : false;
}



