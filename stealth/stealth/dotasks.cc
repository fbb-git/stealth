#include "stealth.ih"

void Stealth::doTasks()
{
    if (not d_options.ipc())
    {
        m1 << "timestamps use " << 
            (d_options.timestamp() == TIMESTAMPS ? 
                "local time" 
            : 
                "UTC"
            ) << endl;
    }

    if (d_options.dryrun())
        *d_report << "--dry-run: SH/SSH connections not established" << endl;
    else
        d_integrityScanner->startCommandShells(); 

    jobsHandler();
}









