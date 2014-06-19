#include "ipc.ih"

void IPC::wait()
{
    try
    {
        m2 << "waiting..." << endl;
        d_selector.wait();              // bobcat's selector throws an
                                        // Exception on negative returns
    }
    catch(...)
    {}

    m2 << "continuing after wait" << endl;
}
