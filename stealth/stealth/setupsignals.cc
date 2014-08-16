#include "stealth.ih"

void Stealth::setupSignals()
{
    Signal &signal = Signal::instance();

    signal.add(SIGTERM, *this);         // ends the running Stealth program.
    signal.add(SIGINT,  *this);

    signal.add(SIGUSR1, *this);
}
