#include "monitor.ih"

void Monitor::handleKeepAliveOption()
{
    string value;
    if (s_keepAlive = Arg::instance().option(&value, "keep-alive"))
    {
        s_repeatInterval = INT_MAX;
        Lock::setRunFilename(value);
    }
}


