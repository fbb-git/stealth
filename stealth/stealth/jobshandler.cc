#include "stealth.ih"

// requests are received through the LocalServerSocket unix domain socket.

void Stealth::jobsHandler()
{
    while (true)
    {
         nextJob();

        m1 << "MODE REQUEST: " << d_task << endl;
    
        d_stealthLog.refresh();

                                            // process the current request
        (this->*(s_task.find(d_task.mode())->second))();

        mailLogs();

        if (d_task.hasMode(TERMINATE))
        {
            d_ipc.notify();
            break;
        }

        if (d_autoJob)
        {
            d_autoJob = false;
            continue;
        }

        d_ipc.notify();
    }
}
