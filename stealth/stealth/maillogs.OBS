#include "stealth.ih"

void Stealth::mailLogs()
{
    if (not d_stealthReport.hasMail())
    {
        m3 << "No new logs to mail" << endl;
        return;
    }

    processMail();
}

