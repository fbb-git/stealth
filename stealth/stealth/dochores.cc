#include "stealth.ih"

// called by processPolicy and childProcess

void Stealth::doChores()
{
    policyDepDataMembers();

    setupSignals();

    d_integrityScanner->startCommandShells(); 

    processRequests();
}









