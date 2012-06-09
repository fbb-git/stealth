#include "monitor.ih"

// activated by 
void Monitor::handleProcessSignals(int signum)
{
    switch (signum)
    {
        case SIGTERM:                       // TERMINATE
cerr << "Stealth receives signal SIGTERM in mode " << s_modeID[s_mode] << endl;
            if (s_mode != TERMINATED)
            {
                s_quit = true;
                s_mode = TERMINATE;
            }
        break;

        case SIGHUP:                        // RERUN
cerr << "Stealth receives signal SIGHUP in mode " << s_modeID[s_mode] << endl;
            if (s_mode != KEEP_ALIVE)       // wakeup if mode is KEEP_ALIVE
                return;
        break;

        case SIGUSR1:                       // SUPPRESS
cerr << "Stealth receives signal SIGUSR1 in mode " << s_modeID[s_mode] << endl;
            if (s_mode == KEEP_ALIVE)
                s_mode = SUPPRESS;          // changed to SUPPRESSED in
                                            // processMode() 
        break;

        case SIGUSR2:                       // RESUME
cerr << "Stealth receives signal SIGUSR2 in mode " << s_modeID[s_mode] << endl;
            if (s_mode == SUPPRESS || s_mode == SUPPRESSED)
                s_mode = KEEP_ALIVE;
        break;

        case SIGPIPE:                       // RELOAD: changes KEEP_ALIVE
cerr << "Stealth receives signal SIGPIPE in mode " << s_modeID[s_mode] << endl;
            if (s_mode == KEEP_ALIVE)       // temporarily into RELOAD
                s_mode = RELOAD;            // for processMode() to handle.
        break;

        default:
cerr << "Stealth ignores signal " << signum << " in mode " << s_modeID[s_mode]
<< endl; 
        return;
    }

    wakeup();
    signal(signum, handleProcessSignals);
}

