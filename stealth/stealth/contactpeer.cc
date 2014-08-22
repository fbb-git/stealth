#include "stealth.ih"

bool Stealth::contactPeer()
{
    if (not d_options.ipc())
        return false;

    Signal &signal = Signal::instance();
    signal.add(SIGUSR1, *this);
    
    if (d_ipc.signalDaemon())
    {
        d_ipc.wait(false);         // false: don't log through m2

        if (d_ipc.requestText() != "OK")
            cout << d_ipc.requestText() << endl;
        
        return true;
    }

    return false;
}



