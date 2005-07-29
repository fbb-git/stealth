#include "monitor.ih"

/*
    Since the Monitor's destruction is also the termination of the program, no
explicit destruction of the newly created objects is necessary. A pointer is
used to prevent the construction of a constant object. As the constructor
itself would create a constant object, the construction *new... 
is used.

*/

Monitor::Monitor(ConfigSorter &sorter, Reporter &reporter, Scanner &scanner)
:
    d_scanner(scanner),
    d_sorter(sorter),
    d_reporter(reporter)
{
    if (Util::keepAlive())
        s_mode = KEEP_ALIVE;

    d_scanner.preamble();

    signal(SIGHUP,  Monitor::handleProcessSignals);
    signal(SIGTERM, Monitor::handleProcessSignals);
    signal(SIGUSR1, Monitor::handleProcessSignals);
    signal(SIGUSR2, Monitor::handleProcessSignals);
}

