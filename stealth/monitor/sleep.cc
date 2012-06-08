#include "monitor.ih"

void Monitor::sleep()
{
    s_selector.setAlarm(numeric_limits<int>::max());
}
