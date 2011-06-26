#include "monitor.ih"

void Monitor::handleKeepAliveOption()
{
    string value;
    if ((s_keepAlive = Arg::instance().option(&value, "keep-alive")) != 0)
    {
        s_repeatInterval = INT_MAX;
        Lock::setRunFilename(value);
    }
}


