#include "stealth.ih"

void Stealth::resumeRequest()
{
    if (d_run.mode(SUSPEND))
        d_run.setMode(RESUME);
    else
        m2 << "ignored --resume in mode " << d_run.modeName() << endl;
}
