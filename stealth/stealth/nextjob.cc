#include "stealth.ih"

void Stealth::nextJob()
{
    if (not d_options.repeat())     // if the scan is not automatically
        d_job.wait();               // restarted, then wait for the next job
    else
    {
        size_t nSeconds = d_options.nextIntegrityScan();

        m2 << "waiting for " << nSeconds << " seconds or for a command" << 
                                                                        endl;

        while (true)
        {
            auto cvStatus = d_job.wait_for(chrono::seconds(nSeconds));

            m2 << "wait ends" << endl;

            if (cvStatus != cv_status::timeout)
                break;

            m2 << "timeout" << endl;

            if 
            (
                d_task.hasMode(SUSPEND)         // At timeout during 
                ||                              // suspend, or 
                d_integrityScanner->active()    // still busy scanning
            )
            {
                m2 << "SUSPEND or actively scanning: wait some more" << endl;
                continue;                       // then wait some more
            }
                             
            d_task.setMode(INTEGRITY_SCAN);
            m2 << "Next mode: INTEGRITY_SCAN" << endl;
            d_autoJob = true;
            break;
        }
    }
    m2 << "nextTask returns with mode " << d_task << endl;
}
