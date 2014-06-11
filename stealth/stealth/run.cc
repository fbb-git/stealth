#include "stealth.ih"

// Called by main() once all preliminary actions have been completed. 
// This function processes the configuration file.

// Signals are sent by sendSignal. Signals are caught by handleProcessSignals
// contactOtherStealth sends the signals depending on command-line options

void Stealth::run()
{
    startup();


    if (not d_options.keepAlive())
        integrityScan();
    else
    {
        cerr << "FORKING\n";
        fork();
    }

}


