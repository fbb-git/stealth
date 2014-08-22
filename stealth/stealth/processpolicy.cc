#include "stealth.ih"

// Called by main() once all preliminary actions have been completed. 

// Signals are sent by sendSignal. Signals are caught by handleProcessSignals
// contactOtherStealth sends the signals depending on command-line options

void Stealth::processPolicy()
{
    if (d_options.daemon())
        fork();                 // creates the daemon. Its childProcess
    else                        // does the chores.
        doChores();
}
