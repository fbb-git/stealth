#include "stealth.ih"

// requests are received through the LocalServerSocket unix domain socket.

void Stealth::processRequests()
{
    do
    {
        nextTask();

        m1 << "MODE REQUEST: " << d_task.modeName() << endl;
    
        d_stealthLog.refresh();

                                            // process the current request
        (this->*(s_task.find(d_task.mode())->second))();

        mailLogs();
    }
    while (not d_task.mode(TERMINATE));
}
