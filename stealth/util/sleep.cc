#include "util.ih"

void Util::sleep()
{
    s_selector.setAlarm(INT_MAX);
}
