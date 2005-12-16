#include "util.ih"

void Util::wait()
{
    try
    {
        s_selector.wait();              // bobcat's selector throws an
                                        // Errno on negative returns
    }
    catch(...)
    {}

    ::sleep(1);                         // to allow s_keepAlive to change its
                                        // value
}
