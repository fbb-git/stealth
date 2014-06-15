#include "stealth.ih"

void Stealth::reload()
{
    logMsg("reloads its policy file");

    mailLogs();
    
    d_stealthLog.close();

    d_policyFile->reload();
    
    d_stealthLog.open((*d_policyFile)["REPORT"]);

    d_integrityScanner.reset( 
                new IntegrityScanner(d_run, *d_policyFile, d_stealthLog) 
    );

    d_integrityScanner->startCommandShells();

    d_run.setMode(INTEGRITY_SCAN);
}


