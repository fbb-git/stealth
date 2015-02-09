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
        char const *policyFilePath = d_options.policyFilePath().c_str();

        if (access(policyFilePath, R_OK) != 0)
            d_fatal << "cannot re-read policy file `" << policyFilePath <<
                                                                '\'' << leave;
        d_options.reloadPolicy();
        
        LogUnit::init(d_fatal, d_options.syslogStruct(), 
                        d_options.logName(), d_options.timestamp(),
                        d_options.stdout());

        openStealthReport();
    
        d_integrityScanner = make_shared<IntegrityScanner>(
                                   d_task, *d_policyFile, 
                                   d_fatal, d_stealthReport
                            );

        d_integrityScanner->startCommandShells();
    }

    autoScan("reload");
}




