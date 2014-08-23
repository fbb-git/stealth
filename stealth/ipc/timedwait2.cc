#include "ipc.ih"

void IPC::timedWait(size_t seconds)
{
    d_selector.setAlarm(seconds);

    wait(false);
}
