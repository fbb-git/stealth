#include "stealth.ih"

// requests are received through the LocalServerSocket unix domain socket.

void Stealth::processRequests()
{
    while (true)
    {
        Mode request = d_run.mode();

        if (request == LEAVE)
            break;

        m1 << "MODE: " << d_run.modeName() << endl;
    
        d_stealthLog.refresh();

        process(request);                   // process the current request
                                            // calls a function from s_task

        mailLogs();

        waitForRequest();
    }
}
