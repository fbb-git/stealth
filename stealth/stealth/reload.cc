#include "stealth.ih"

void Stealth::reload()
{
    logMsg("reloads its policy file");

    mailLogs();
    
    d_log.close();

    d_policyFile->reload();
    
    d_log.open((*d_policyFile)["REPORT"]);

    d_integrityScanner.reset( 
                new IntegrityScanner(d_run, *d_policyFile, d_log) 
    );

    d_integrityScanner->startCommandShells();

    d_run.setMode(INTEGRITY_SCAN);
}


