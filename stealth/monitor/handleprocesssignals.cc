#include "monitor.ih"

// activated by 
void Monitor::handleProcessSignals(int signum)
{
    switch (signum)
    {
        case SIGTERM:                       // TERMINATE
            if (s_mode != TERMINATED)
            {
                s_quit = true;
                s_mode = TERMINATE;
            }
        break;

        case SIGHUP:                        // RERUN
            if (s_mode != KEEP_ALIVE)       // wakeup if mode is KEEP_ALIVE
                return;
        break;

        case SIGUSR1:                       // SUPPRESS
            if (s_mode == KEEP_ALIVE)
                s_mode = SUPPRESS;          // changed to SUPPRESSED in
                                            // processMode() 
        break;

        case SIGUSR2:                       // RESUME
            if (s_mode == SUPPRESS || s_mode == SUPPRESSED)
                s_mode = KEEP_ALIVE;
        break;

        case SIGCHLD:                       // RELOAD: changes KEEP_ALIVE
            if (s_mode == KEEP_ALIVE)       // temporarily into RELOAD
                s_mode = RELOAD;            // for processMode() to handle.
        break;
    }

    wakeup();
    signal(signum, handleProcessSignals);
}
