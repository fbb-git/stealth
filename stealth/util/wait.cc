#include "util.h2"

void Util::wait()
{
    s_selector.wait();
    sleep(1);                           // to allow s_keepAlive to change its
                                        // value
}
