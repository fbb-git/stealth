#include "util.h2"

void Util::sleep()
{
    s_selector.setAlarm(INT_MAX);
}
