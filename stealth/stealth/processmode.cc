#include "stealth.ih"

void Stealth::processMode()
{
    while (true)
    {
        switch (mode())
        {
            default:
                d_integrityScanner->run(&d_quit);

                if (mode(TERMINATE) || mode(SUPPRESS))
                    continue;
            return;

            case RELOAD:
                report("reloads its configuration files");
                reload();
            return;              // next cycle: rerun a scan.
    
            case TERMINATE:
                report("was terminated");
                setMode(TERMINATED);
            return;
    
            case SUPPRESS:
                report("was suppressed");
                setMode(SUPPRESSED);
            return;

            case TERMINATED:
            case SUPPRESSED:
            return;
        }
    }
}
