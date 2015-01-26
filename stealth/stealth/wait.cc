#include "stealth.ih"

void Stealth::wait()
{
    if (not d_options.repeat())
        d_chore.wait();
    else
    {
        size_t nSeconds = d_options.repeatInterval() + 
                            d_options.randomAddition();

        m2 << "waiting for " << nSeconds << " seconds or for a command" << 
                                                                        endl;
        if (d_chore.wait_for(chrono::seconds(nSeconds)) == cv_status::timeout)
            d_run.setMode(INTEGRITY_SCAN);
    }
}
