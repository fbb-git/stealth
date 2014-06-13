#include "stealth.ih"

void Stealth::setDelay()
{
    switch (d_run.mode())
    {
        case KEEP_ALIVE:
            d_ipc.setAlarm();
        break;

        case TERMINATE:
            d_ipc.wakeup();
        break;

        case SUSPEND:
        case SUSPENDED:
            d_ipc.sleep();
        break;

        default:
        break;
    }
}
