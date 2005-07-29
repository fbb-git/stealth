#include "monitor.ih"

void Monitor::processMode()
{
    while (true)
    {
        switch (s_mode)
        {
            case TERMINATE:
                d_reporter <<
                    "STEALTH was terminated after " << d_scanner.nScans() << 
                    " scans at " << Util::date << endl;
                s_mode = TERMINATED;
            return;
    
            case SUPPRESS:
                d_reporter <<
                    "STEALTH was suppressed after " << d_scanner.nScans() << 
                    " scans at " << Util::date << endl;
                s_mode = SUPPRESSED;
            return;

            case TERMINATED:
            case SUPPRESSED:
            return;

            default:
                d_scanner.run(&s_quit);

                if (s_mode == TERMINATE || s_mode == SUPPRESS)
                    continue;
            return;
        }
    }
}
