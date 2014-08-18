#include "stealth.ih"

// called by processPolicy and childProcess

void Stealth::doChores()
{
    policyDepDataMembers();

    setupSignals();

    if (d_options.dryrun())
        d_stealthLog << 
            "--dry-run: SH/SSH connections not established" << endl;
    else
        d_integrityScanner->startCommandShells(); 

    processRequests();
}









