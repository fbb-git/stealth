#include "monitor.ih"

Monitor::Monitor()
{
    processControlOptions();            // handle process control options
    maybeBackground();                  // maybe run Stealth in the background

    if (keepAlive())
        s_mode = KEEP_ALIVE;

    d_scanner->preamble();

    signal(SIGHUP,  Monitor::handleProcessSignals);
    signal(SIGTERM, Monitor::handleProcessSignals);
    signal(SIGUSR1, Monitor::handleProcessSignals);
    signal(SIGUSR2, Monitor::handleProcessSignals);
}




