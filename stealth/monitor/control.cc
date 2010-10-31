#include "monitor.ih"

// Called by main() once all preliminary actions have been completed. This
// function controls the processing of the configuration file.

void Monitor::control()
{
    while (true)
    {
        imsg << "CONTROL: s_mode == " << s_mode << endl;
    
        d_reporter->standby();      // locks the runfile, opens the report
                                    // file
        processMode();
        mailReport();

        if (!d_reporter->relax())   // close the report file, unlock the run
            throw Errno(1);         // file. If the reporter has set
                                    // d_continue to false, then terminate.
                                    // This happens when a (remote) 
                                    // command returns a non-zero exit value.
        if (s_mode == TERMINATED || s_mode == ONCE)
            break;

        if (s_mode == SUPPRESSED)
        {
            imsg << "Supressed. Now signal the suppressor" << endl;

            ::sleep(1);             // This delay is necessary to allow the
                                    // suppressor to start waiting once it has
                                    // signalled this process. See
                                    // signalStealth(). 

                                    // let the process that issued
                                    // `--suppress' know we're done.
            sendSignal(SIGUSR1, "SIGUSR1", suppressorPid());
            imsg << "Wait for --resume..." << endl;
        }

        do
        {
            setDelay();
            wait();
        }
        while (s_mode == SUPPRESSED);
    }        
}
