#include "util.h2"

void Util::wait()
{
    s_selector.wait();
    if (!s_selector.nReady())           // to allow s_keepAlive to change its
        sleep(1);                       // value
}
