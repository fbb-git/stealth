#include "ipc.ih"

void IPC::timedWait(size_t seconds)
{
    d_selector.setAlarm(seconds);

    wait(false);
//    try
//    {
//        wait(false);
//        d_timeout = true;
//    }
//    catch (...)
//    {
//        d_timeout = false;
//    }
}
