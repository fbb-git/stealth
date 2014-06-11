#include "ipc.ih"

void IPC::wait()
{
    try
    {
        d_selector.wait();              // bobcat's selector throws an
                                        // Errno on negative returns
    }
    catch(...)
    {}

    ::sleep(1);                         // to allow d_keepAlive to change its
                                        // value
}
