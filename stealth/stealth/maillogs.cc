#include "stealth.ih"

// Called from performTask()

void Stealth::mailLogs()
{
    if (not d_stealthLog.hasMail())
    {
        m4 << "No new logs available" << endl;
        return;
    }

    processMail();
}

