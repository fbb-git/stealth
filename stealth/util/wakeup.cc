#include "util.ih"

void Util::wakeup()
{
    s_selector.setAlarm(0);
}
