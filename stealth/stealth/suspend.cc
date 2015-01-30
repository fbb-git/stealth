#include "stealth.ih"

void Stealth::suspend()
{
    endScanner();

    logMsg("is suspended");

    mailLogs();
    d_stealthLog.refresh();

    m2 << "received SUSPEND request" << endl;

    d_result.notify();
    d_ipc.notify();
}
