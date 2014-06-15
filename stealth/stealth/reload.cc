#include "stealth.ih"

void Stealth::reload()
{
    logMsg("reloads its policy file");

    mailLogs();
    
    d_stealthlog.close();

    d_policyFile->reload();
    
    d_stealthlog.open((*d_policyFile)["REPORT"]);

    d_integrityScanner.reset( 
                new IntegrityScanner(d_run, *d_policyFile, d_stealthlog) 
    );

    d_integrityScanner->startCommandShells();

    d_run.setMode(INTEGRITY_SCAN);
}


