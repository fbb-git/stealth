#include "stealth.ih"

void Stealth::resumeSignal()
{
    if (not d_run.mode(SUSPEND))
    {
        imsg << "--resume only valid after --suspend" << endl;
        return;
    }

    d_run.setMode(RESUME);
}
