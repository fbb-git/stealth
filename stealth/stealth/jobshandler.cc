#include "stealth.ih"

void Stealth::jobsHandler()
{
    bool prompt =  not d_options.daemon() && d_options.repeat();

    if (prompt)
    {
        thread(startThread, &Stealth::waitForKey, this).detach();
        cout << "? " << flush;
    }

    while (true)
    {
        nextJob();

        m1 << "MODE REQUEST: " << d_task << endl;
    
//        d_stealthReport.refresh();
                                            // process the current request
        (this->*(s_task.find(d_task.mode())->second))();

        d_stealthReport->mail();

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
