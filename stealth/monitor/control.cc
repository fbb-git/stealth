#include "monitor.ih"

void Monitor::control()
{
    while (true)
    {
        dout("CONTROL: s_mode == " << s_mode);
    
        d_reporter.standby();       // locks the runfile
        processMode();
        mailReport();
        d_reporter.relax();

        if (s_mode == TERMINATED || s_mode == ONCE)
            break;

        do
        {
            setDelay();
            Util::wait();
        }
        while (s_mode == SUPPRESSED);
    }        
}





