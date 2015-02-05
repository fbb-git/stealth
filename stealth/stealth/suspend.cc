#include "stealth.ih"

void Stealth::suspend()
{
    logMsg("is suspended");

    mailLogs();
    d_stealthReport.refresh();

    m2 << "received SUSPEND request" << endl;
}
