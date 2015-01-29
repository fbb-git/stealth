#include "stealth.ih"

void Stealth::nextMode()
{
    if (not d_options.repeat())     // if the scan is not automatically
        d_command.wait();           // restarted, then wait for the next
                                    // command. 
    else
    {
        size_t nSeconds = d_options.nextIntegrityScan();

        m2 << "waiting for " << nSeconds << " seconds or for a command" << 
                                                                        endl;

        while (true)
        {
            auto cvStatus = d_command.wait_for(chrono::seconds(nSeconds));
            if (cvStatus == cv_status::timeout)
            {
                if 
                (
                    d_task.mode(SUSPEND)             // At timeout during 
                    ||                              // suspend, or 
                    d_integrityScanner->active()    // still busy scanning
                )
                    continue;                       // then wait some more
                                        
                d_task.setMode(INTEGRITY_SCAN);
                break;
            }
        }
    }
}
