#include "ipc.ih"

void IPC::wait(bool doM2)
{
    d_signaled = false;

    try
    {
        if (doM2)
            m2 << "waiting..." << endl;
        d_selector.wait();              // bobcat's selector throws an
                                        // Exception on negative returns
    }
    catch(...)                          // timeout OR signal received
    {}

    if (doM2)
        m2 << "continuing after wait" << endl;
}
