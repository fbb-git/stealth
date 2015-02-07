#include "stealth.ih"

void Stealth::doChores()
{
    policyDepDataMembers();

    if (not d_options.ipc())
    {
        m1 << "timestamps use " << 
            (d_options.timestamp() == TIMESTAMPS ? 
                    "local time" 
                : 
                "UTC"
            ) << endl;
        d_policyFile->pathMsg();
    }

    if (d_options.dryrun())
        d_stealthReport << "--dry-run: SH/SSH connections not established" << 
                                                                        endl;
    else
        d_integrityScanner->startCommandShells(); 

    jobsHandler();
}









