#include "ipc.ih"

void IPC::timedWait()
{
    if (d_options.repeat())
    {
        size_t waitSeconds = d_options.repeatInterval() + 
                             d_options.randomAddition();

        m2 << "waiting for " << waitSeconds << " seconds or for a signal" << 
                                                                        endl;
        d_selector.setAlarm(waitSeconds);
    }

    wait();

//    try
//    {
//        wait();
//        d_timeout = true;
//    }
//    catch (...)
//    {
//        d_timeout = false;
//    }
}
