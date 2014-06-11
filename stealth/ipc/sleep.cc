#include "ipc.ih"

void IPC::sleep()
{
    d_selector.setAlarm(numeric_limits<int>::max());
}
