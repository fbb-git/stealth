#include "stealth.ih"

void Stealth::nextTask()
{
    if (not d_options.repeat())     // if the scan is not automatically
        d_processor.wait();           // restarted, then wait for the next
                                    // command. 
    else
    {
        size_t nSeconds = d_options.nextIntegrityScan();

        m2 << "waiting for " << nSeconds << " seconds or for a command" << 
                                                                        endl;

        while (true)
        {
            auto cvStatus = d_processor.wait_for(chrono::seconds(nSeconds));

            m2 << "wait ends" << endl;

            if (cvStatus != cv_status::timeout)
                break;

            m2 << "timeout" << endl;

            if 
            (
                d_task.mode(SUSPEND)             // At timeout during 
                ||                              // suspend, or 
                d_integrityScanner->active()    // still busy scanning
            )
            {
                m2 << "SUSPEND or scanner busy: wait some more" << endl;
                continue;                       // then wait some more
            }
                                    
            d_task.setMode(INTEGRITY_SCAN);
            m2 << "Next mode: INTEGRITY_SCAN" << endl;
            break;
        }
    }
    m2 << "nextTask returns with mode " << d_task.modeName() << endl;
}
