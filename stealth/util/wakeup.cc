#include "util.h2"

void Util::wakeup()
{
    s_selector.setAlarm(0);
}
