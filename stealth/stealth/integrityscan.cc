#include "stealth.ih"

void Stealth::integrityScan()
{
    d_integrityScanner->preamble();

    while (true)
    {
        imsg << "CONTROL: mode == " << modeName() << endl;
    
        d_reporter->standby();      // locks the runfile, opens the report
                                    // file
        processMode();
        mailReport();

        if (!d_reporter->relax())   // close the report file, unlock the run
            throw Exception();         // file. If the reporter has set
                                    // d_continue to false, then terminate.
                                    // This happens when a (remote) 
                                    // command returns a non-zero exit value.

        if (mode(TERMINATED) || mode(ONCE))
            break;

        if (mode(RELOAD))
        {
            setMode(KEEP_ALIVE);
            continue;
        }

        if (mode(SUPPRESSED))
        {
            imsg << "Supressed. Now signal back the suppressor" << endl;

            d_ipc.sleep(1);         // This delay is necessary to allow the
                                    // suppressor to start waiting once it has
                                    // signalled this process. See
                                    // signalStealth(). 

                                    // let the process that issued
                                    // `--suppress' know we're done.
            if (d_ipc.signalSuppressor())
                imsg << "Wait for --resume..." << endl;
            else
                imsg << "Suppressor not signalled: can't read `" <<
                        Lock::runFilename() << '\'' << endl;
        }

        do
        {
            setDelay();
            d_ipc.wait();
        }
        while (mode(SUPPRESSED));
    }        
}



