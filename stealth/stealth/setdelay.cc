#include "stealth.ih"

void Stealth::setDelay()
{
    switch (mode())
    {
        case KEEP_ALIVE:
            d_ipc.setAlarm();
        break;

        case TERMINATE:
            d_ipc.wakeup();
        break;

        case SUPPRESS:
        case SUPPRESSED:
            d_ipc.sleep();
        break;

        default:
        break;
    }
}
