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


        if (s_mode == SUPPRESSED)
        {
            dout("Supressed. Now signal the suppressor");

            ::sleep(1);             // This delay is necessary to allow the
                                    // suppressor to start waiting once it has
                                    // signalled this process. See
                                    // Util::signalStealth(). 

                                    // let the process that issued
                                    // `--suppress' know we're done.
            Util::sendSignal(SIGUSR1, "SIGUSR1", Util::suppressorPid());
            dout("Wait for --resume...");
        }

        do
        {
            setDelay();
            Util::wait();
        }
        while (s_mode == SUPPRESSED);
    }        
}





