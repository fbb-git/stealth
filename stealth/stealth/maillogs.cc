#include "stealth.ih"

// Called from performTask()

void Stealth::mailLogs()
{
    if (not d_stealthlog.hasMail())
    {
        m4 << "No new logs available" << endl;
        return;
    }

    d_stealthlog.rewind();

    processMail();
}

