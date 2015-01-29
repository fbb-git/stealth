#include "stealth.ih"

void Stealth::resume()
{
    d_stealthLog << "STEALTH resumes its tasks at " << d_options.rfc2822() << 
                                                                        endl;
    d_task.setMode(INTEGRITY_SCAN);

    m2 << "resuming tasks: INTEGRITY_SCAN next" << endl;

    d_command.notify();
    d_remote.notify();
}
