#include "stealth.ih"

void Stealth::suspend()
{
    logMsg("was suspended");

    while (true)
    {
        d_ipc.wait();
        if (d_run.mode(RESUME | TERMINATE))
            break;
        m2 << "ignoring wake up signal in SUSPEND mode" << endl;
    }
    m2 << "received SUSPEND signal" << endl;
}
