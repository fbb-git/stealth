#include "stealth.ih"

void Stealth::reload()
{
    timestamp("reloads its policy file");

    if (d_options.dryrun())
        *d_report << "--dry-run: would have reloaded the policy file" << endl;
    else
    {
        PolicyFile *policyFilePtr = new PolicyFile(d_options);

        Report *reportPtr =  new Report(d_options, *policyFilePtr);

        d_integrityScanner.reset(
            new IntegrityScanner(d_pending, d_options, 
                                 *policyFilePtr, *reportPtr)
        );

        d_integrityScanner->startCommandShells();

        setupFatalReport();

        d_logUnit.setupLogs(d_logReport);
        
        d_report.reset(reportPtr);
        d_policyFile.reset(policyFilePtr);

        m2 << "reloaded policy file `" << d_options.policyFilePath() << 
                                                                '\'' << endl;
    }
    autoScan("reload");
}




