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
        d_options.reloadPolicy();
        
        LogUnit::init(d_options.syslogStruct(), 
                        d_options.logName(), d_options.timestamp(),
                        d_options.stdout());


        d_stealthReport.open((*d_policyFile)["REPORT"]);
    
        d_integrityScanner = make_shared<IntegrityScanner>(
                                   d_task, *d_policyFile, d_stealthReport
                            );

        d_integrityScanner->startCommandShells();
    }

    autoScan("reload");
}




