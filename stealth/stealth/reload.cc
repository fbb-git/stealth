#include "stealth.ih"

void Stealth::reload()
{
    logMsg("reloads its policy file");

    mailLogs();
    
    d_stealthReport.close();

    if (d_options.dryrun())
        d_stealthReport << "--dry-run: reload suppressed" << endl;
    else
    {
//        d_policyFile->reload();
        d_options.reloadPolicy();
        
        d_stealthReport.open((*d_policyFile)["REPORT"]);
    
        d_integrityScanner = make_shared<IntegrityScanner>(
                                   d_task, *d_policyFile, d_stealthReport
                            );

        d_integrityScanner->startCommandShells();
    }

    autoScan("reload");
}




