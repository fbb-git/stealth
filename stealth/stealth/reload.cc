#include "stealth.ih"

void Stealth::reload()
{
    timestamp("reloads its policy file");

    if (d_options.dryrun())
        *d_report << "--dry-run: reload suppressed" << endl;
    else
    {
        PolicyFile *policyFilePtr = new PolicyFile(d_options);
        Report *reportPtr =  new Report(d_options, *policyFilePtr);

        d_logUnit.setupLogs(*reportPtr);
        
        d_integrityScanner.reset(
            new IntegrityScanner(d_pending, d_options, 
                                 *policyFilePtr, *reportPtr)
        );

        d_integrityScanner->startCommandShells();

        d_report.reset(reportPtr);
        d_policyFile.reset(policyFilePtr);

        m2 << "(re)loaded policy file `" << d_options.policyFilePath() << 
                                                                '\'' << endl;
    }

    autoScan("reload");
}




