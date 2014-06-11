#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon();

    Signal &signal = Signal::instance();

    signal.add(SIGHUP,  *this);
    signal.add(SIGTERM, *this);
    signal.add(SIGUSR1, *this);
    signal.add(SIGUSR2, *this);
    signal.add(SIGPIPE, *this);
    
    integrityScan();

    throw 0;
}
