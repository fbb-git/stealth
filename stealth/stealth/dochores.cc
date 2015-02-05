#include "stealth.ih"

// called by processPolicy and childProcess

void Stealth::doChores()
{
    policyDepDataMembers();

    if (d_options.dryrun())
        d_stealthReport << "--dry-run: SH/SSH connections not established" << 
                                                                        endl;
    else
        d_integrityScanner->startCommandShells(); 

    jobsHandler();
}









