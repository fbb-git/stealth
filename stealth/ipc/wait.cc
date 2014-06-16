#include "ipc.ih"

void IPC::wait()
{
    try
    {
        d_selector.wait();              // bobcat's selector throws an
                                        // Exception on negative returns
    }
    catch(...)
    {}

    m2 << "woke up after wait" << endl;
}
