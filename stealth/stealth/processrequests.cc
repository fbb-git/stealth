#include "stealth.ih"

// requests are received through the LocalServerSocket unix domain socket.

void Stealth::processRequests()
{
    do
    {
        nextMode();

        m1 << "MODE: " << d_task.modeName() << endl;
    
        d_stealthLog.refresh();

                                            // process the current request
        (this->*(s_task.find(d_task.mode())->second))();

        mailLogs();
    }
    while (not d_task.mode(TERMINATE));
}
