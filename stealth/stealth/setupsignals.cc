#include "stealth.ih"

void Stealth::setupSignals()
{
    Signal &signal = Signal::instance();

    signal.add(SIGTERM, *this);
    signal.add(SIGINT,  *this);

    signal.add(SIGUSR1, *this);
    signal.add(SIGUSR2, *this);

    signal.add(SIGHUP,  *this);

    signal.add(SIGPIPE, *this);

}
