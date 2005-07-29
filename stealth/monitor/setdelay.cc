#include "monitor.ih"

void Monitor::setDelay()
{
    switch (s_mode)
    {
        case KEEP_ALIVE:
            Util::setAlarm();
        break;

        case TERMINATE:
            Util::wakeup();
        break;

        case SUPPRESS:
        case SUPPRESSED:
            Util::sleep();
        break;

        default:
        break;
    }
}
