#include "stealth.ih"

void Stealth::reload()
{
    logMsg("reloads its policy file");

    mailLogs();
    
    d_stealthLog.close();

    if (d_options.dryrun())
        d_stealthLog << "--dry-run: reload suppressed" << endl;
    else
    {
        d_policyFile->reload();
        
        d_stealthLog.open((*d_policyFile)["REPORT"]);
    
        d_integrityScanner = make_shared<IntegrityScanner>(
                                   d_task, *d_policyFile, d_stealthLog
                            );

        d_integrityScanner->startCommandShells();
    }

    d_task.setMode(INTEGRITY_SCAN);

    d_command.notify();
    d_remote.notify();
}

