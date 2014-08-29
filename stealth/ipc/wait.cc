#include "ipc.ih"

void IPC::wait(bool doM2)
{
    d_wait11.waitSignal(doM2);

    if (doM2)
        m2 << "continuing after wait" << endl;
}
