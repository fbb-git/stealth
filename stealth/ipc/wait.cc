#include "ipc.ih"

void IPC::wait(bool doM2)
{
    try
    {
        if (doM2)
            m2 << "waiting..." << endl;
        d_selector.wait();              // bobcat's selector throws an
                                        // Exception on negative returns
    }
    catch(...)
    {}

    if (doM2)
        m2 << "continuing after wait" << endl;
}
