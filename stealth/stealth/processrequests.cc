#include "stealth.ih"

// requests are received through interrupts (SIGUSR1, SIGTERM, SIGINT). For
// SIGUSR1 requests the type of request is written in line 2 of the run file.
// When a SIGUSR1 signal is received, the request

void Stealth::processRequests()
{
    while (true)
    {
        Mode request = d_run.mode();

        if (request == LEAVE)
            break;

        m1 << "\n"
              "MODE: " << d_run.modeName() << endl;
    
        d_stealthLog.refresh();

        process(request);                    // process the current request

        mailLogs();

        waitForRequest();
    }
}
