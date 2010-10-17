#include "monitor.ih"

void Monitor::setDelay()
{
    switch (s_mode)
    {
        case KEEP_ALIVE:
            setAlarm();
        break;

        case TERMINATE:
            wakeup();
        break;

        case SUPPRESS:
        case SUPPRESSED:
            sleep();
        break;

        default:
        break;
    }
}
