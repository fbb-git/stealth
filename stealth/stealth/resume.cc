#include "stealth.ih"

void Stealth::resume()
{
    d_stealthLog << "STEALTH resumes its tasks at " << DateTime() << endl;
    d_run.setMode(INTEGRITY_SCAN);
    m2 << "resuming tasks: INTEGRITY_SCAN next" << endl;
}