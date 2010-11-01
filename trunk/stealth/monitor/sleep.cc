#include "monitor.ih"

void Monitor::sleep()
{
    s_selector.setAlarm(INT_MAX);
}
