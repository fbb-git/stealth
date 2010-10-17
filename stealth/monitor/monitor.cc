#include "monitor.ih"

Monitor::Monitor(char const *conffile)
:
    d_sorter(conffile),
    d_reporter(d_sorter["REPORT"]),
    d_scanner(d_sorter, d_reporter)
{
    processControlOptions();            // handle process control options
    maybeBackground();                  // maybe run Stealth in the background

    if (keepAlive())
        s_mode = KEEP_ALIVE;

    d_scanner.preamble();

    signal(SIGHUP,  Monitor::handleProcessSignals);
    signal(SIGTERM, Monitor::handleProcessSignals);
    signal(SIGUSR1, Monitor::handleProcessSignals);
    signal(SIGUSR2, Monitor::handleProcessSignals);
}




