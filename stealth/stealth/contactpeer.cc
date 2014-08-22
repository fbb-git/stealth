#include "stealth.ih"

bool Stealth::contactPeer()
{
    if (not d_options.ipc())
        return false;

    Signal &signal = Signal::instance();
    signal.add(SIGUSR1, *this);
    
    if (d_ipc.signalDaemon())
    {
        d_ipc.timedWait(s_contactPeerWaitSeconds);

        if (d_ipc.timeout())
            cout << "No reply from daemon (pid " << d_ipc.daemonPid() << 
                                                        ')' << endl;
        else if (d_ipc.requestText() != "OK")
            cout << d_ipc.requestText() << endl;
        
        return true;
    }

    return false;
}



