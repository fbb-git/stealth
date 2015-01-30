#include "stealth.ih"

string Stealth::suspendRequest()
{
    string ret;

    switch (d_task.mode())
    {
        case INTEGRITY_SCAN:
            ret = acceptMode(SUSPEND);
        break;

        case SUSPEND:
            ret = "nop";
        break;

        default:
            ret = deniedMode("--suspend");
        break;
    }

    return ret;
}
