#include "ipc.ih"

void IPC::sleep(size_t seconds)
{
    d_selector.setAlarm(seconds);
    wait();
}

