#include "ipc.ih"

void IPC::timedWait()
{
    if (not d_options.repeat())
        d_wait11.waitSignal();
    else
    {
        size_t waitSeconds = d_options.repeatInterval() + 
                                d_options.randomAddition();

        m2 << "waiting for " << waitSeconds << " seconds or for a signal" << 
                                                                        endl;
        
        d_wait11.waitFor(waitSeconds);
    }
}
