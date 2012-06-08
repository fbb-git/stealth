#include "monitor.ih"

void Monitor::handleKeepAliveOption()
{
    string value;
    if ((s_keepAlive = d_arg.option(&value, "keep-alive")) != 0)
    {
        s_repeatInterval = numeric_limits<int>::max();
        Lock::setRunFilename(value);
    }
}


