#include "stealth.ih"

void Stealth::signalHandler(size_t signal)
{
    switch (signal)
    {
        case SIGTERM:                       // TERMINATE
            if (mode() != TERMINATED)
            {
                d_quit = true;
                setMode(TERMINATE);
            }
        break;

        case SIGHUP:                        // RERUN
            if (mode() != KEEP_ALIVE)       // wakeup if mode is KEEP_ALIVE
                return;
        break;

        case SIGUSR1:                       // SUPPRESS
            if (mode() == KEEP_ALIVE)
                setMode(SUPPRESS);          // changed to SUPPRESSED in
                                            // processMode() 
        break;

        case SIGUSR2:                       // RESUME
            if (mode(SUPPRESS) || mode(SUPPRESSED))
                setMode(KEEP_ALIVE);
        break;

        case SIGPIPE:                       // RELOAD: changes KEEP_ALIVE
            if (mode(KEEP_ALIVE))           // temporarily into RELOAD
                setMode(RELOAD);            // for processMode() to handle.
        break;

        default:
        return;
    }

    d_ipc.wakeup();
    
}
